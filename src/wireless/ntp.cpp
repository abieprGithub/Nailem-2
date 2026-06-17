/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : ntp.cpp
  * @brief          : Source file for NTP synchronization task
  ******************************************************************************
**/
/* USER CODE END Header */
#include "wireless/ntp.h"
#include "globals/rtos.h"
#include "config.h"
#include <Arduino.h>
#include <WiFi.h>
#include <time.h>
#include "config.h"
#include "wireless/wifi_svc.h"

bool NTP_VALID = false; // Global variable to track NTP synchronization status

void xTask_WIFI_NTP(void *pv) {

    while (1) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // Wait indefinitely for a notification to start the task
        #ifdef CONFIG_SERIAL_DEBUG
            Serial.println("WiFi NTP Task notified.");
        #endif

        if (WiFi.status() == WL_CONNECTED) {
            configTime(GMT_OFFSET_SEC, DAYLIGHT_OFFSET_SEC, NTP_SERVER);
            struct tm timeinfo;
            if (getLocalTime(&timeinfo)) {
                NTP_VALID = true; // Update global NTP synchronization status

                #ifdef CONFIG_SERIAL_DEBUG
                    Serial.println("NTP synchronization successful");
                    Serial.print("Current time: ");
                    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
                #endif

            } else {
                NTP_VALID = false; // Update global NTP synchronization status

                #ifdef CONFIG_SERIAL_DEBUG
                    Serial.println("Failed to obtain time from NTP server");
                #endif

            }

        } else {
            #ifdef CONFIG_SERIAL_DEBUG
                Serial.println("WiFi not connected, skipping NTP synchronization...");
            #endif
        }
        vTaskDelay(pdMS_TO_TICKS(60000)); // Check connection every 60 seconds
    }
}

void xStart_WIFI_NTP() {
    xTaskCreatePinnedToCore(
        xTask_WIFI_NTP,     // Task function
        "WiFi NTP Task",    // Name of the task (for debugging)
        CONFIG_NTP_STACK_SIZE,              // Stack size in bytes
        nullptr,           // Parameter to pass to the task
        CONFIG_NTP_PRIORITY,           // Task priority
        &tTaskHandle_WIFI_NTP,           // Task handle (optional)
        CONFIG_NTP_USE_CORE_0 ? 0 : 1                  // Core to run the task on (0 or 1)
    );
}







