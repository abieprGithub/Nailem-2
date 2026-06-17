/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : wifi_conn.cpp
  * @brief          : Source file for WiFi connection oneshot task.
  ******************************************************************************
**/
/* USER CODE END Header */
#include "freertos/FreeRTOS.h"

#include "wireless/wifi_conn.h"
#include "wireless/wifi_svc.h"
#include "globals/rtos.h"
#include "config.h"

#include <Arduino.h>
#include <WiFi.h>
#include <ESPping.h>

void xTask_WIFI_CONN(void *pv) {
    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // Wait indefinitely for a notification to start the task
        #ifdef CONFIG_SERIAL_DEBUG
            Serial.println("WiFi Connection Task notified.");
        #endif
        if (WiFi.status() != WL_CONNECTED) {
            WiFi.disconnect(true, true); // Disconnect and erase previous credentials
            vTaskDelay(pdMS_TO_TICKS(200)); // Short delay to ensure disconnection

            for (int i = 0; i < NUM_WIFI_NETWORKS; i++) { // Iterate through indexed WiFi credentials
                WiFi.begin(WIFI_CREDENTIALS[i][0], WIFI_CREDENTIALS[i][1]); // Attempt to connect with current credentials
                #ifdef CONFIG_SERIAL_DEBUG
                    Serial.print("Attempting to connect to WiFi SSID: ");
                    Serial.println(WIFI_CREDENTIALS[i][0]);
                #endif

                uint8_t attempts = 0;
                while (WiFi.status() != WL_CONNECTED && attempts < NUM_CONN_ATTEMPTS) { // Attempt to connect with current credentials
                    vTaskDelay(pdMS_TO_TICKS(CONN_TIMEOUT_MS)); // Wait for the specified timeout before checking again
                    attempts++;
                }

                if (WiFi.status() == WL_CONNECTED) { // If connection successful, break out of the loop
                    if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
                        WIFI_CONNECTED = true; // Update global connection status
                        xSemaphoreGive(xMutex);
                    }

                    #ifdef CONFIG_SERIAL_DEBUG
                        Serial.print("Connected to WiFi SSID: ");
                        Serial.println(WIFI_CREDENTIALS[i][0]);
                    #endif

                    IPAddress IP_TO_PING(PING_IP[0], PING_IP[1], PING_IP[2], PING_IP[3]);

                    if (Ping.ping(IP_TO_PING) > 0) { // If ping successful, update global internet connectivity status
                        if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
                            INTERNET_CONNECTED = true; // Update global internet connectivity status
                            xSemaphoreGive(xMutex);
                            #ifdef CONFIG_SERIAL_DEBUG
                                Serial.println("Internet connectivity confirmed via ping.");
                            #endif

                            break; // Exit the loop since we have a successful connection and internet access
                        }
                    } else { // If ping fails, update global internet connectivity status
                        if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
                            INTERNET_CONNECTED = false; // Update global internet connectivity status
                            xSemaphoreGive(xMutex);
                            #ifdef CONFIG_SERIAL_DEBUG
                                Serial.println("Ping failed. No internet connectivity.");
                            #endif
                        }
                    }
                }
                #ifdef CONFIG_SERIAL_DEBUG
                    Serial.print("Failed to connect to WiFi SSID: ");
                    Serial.println(WIFI_CREDENTIALS[i][0]);
                    Serial.printf("\nStatus: %d\n", WiFi.status());
                #endif

                WiFi.disconnect(true, true); // Disconnect and erase previous credentials before trying the next one
                vTaskDelay(pdMS_TO_TICKS(200)); // Short delay to ensure disconnection
            }
            
            if (WiFi.status() != WL_CONNECTED) { // If all attempts failed, update global connection status
                if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
                    WIFI_CONNECTED = false;
                    INTERNET_CONNECTED = false;
                    xSemaphoreGive(xMutex);
                }
                #ifdef CONFIG_SERIAL_DEBUG
                    Serial.println("All WiFi connection attempts failed.");
                #endif

            }

        } // If it's notified but the WiFi is actually fine, it will just loop back and wait for the next notification

        // Now, call back the wifi service to notify that the connection process is complete, whether successful or not
        xTaskNotifyGive(tTaskHandle_WIFI_SVC);
    }
}

void xStart_WIFI_CONN() {
    xTaskCreatePinnedToCore(
        xTask_WIFI_CONN,   // Task function
        "WIFI_CONN",       // Name of the task
        CONFIG_WIFI_CONN_STACK_SIZE,              // Stack size in bytes
        nullptr,           // Parameter to pass to the task
        1,                 // Task priority
        &tTaskHandle_WIFI_CONN,           // Task handle (optional)
        CONFIG_WIFI_CONN_USE_CORE_0 ? 0 : 1                  // Core to run the task on (0 or 1)
    );
}
