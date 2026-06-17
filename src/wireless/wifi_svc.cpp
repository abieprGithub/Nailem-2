/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : wifi_svc.cpp
  * @brief          : Source file for WiFi monitor task.
  ******************************************************************************
**/
/* USER CODE END Header */
#pragma once
#include "wireless/wifi_svc.h"
#include "freertos/FreeRTOS.h"
#include "globals/rtos.h"
#include <ESPping.h>
#include "config.h"

bool WIFI_CONNECTED = false; // Global variable to track WiFi connection status
bool INTERNET_CONNECTED = false; // Global variable to track internet connectivity status

void xTask_WIFI_SVC(void *pv) {
    #ifdef CONFIG_SERIAL_DEBUG
        Serial.println("WiFi Service Task Started");
    #endif

    while (1) { // Check if WiFi is disconnected and attempt to reconnect if necessary
        if (WiFi.status() != WL_CONNECTED) {
            #ifdef CONFIG_SERIAL_DEBUG
                Serial.println("WiFi Disconnected, attempting to reconnect...");
            #endif

            if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
                WIFI_CONNECTED = false; // Update global connection status
                INTERNET_CONNECTED = false; // Update global internet connectivity status
                xSemaphoreGive(xMutex);
            }
            xTaskNotifyGive(tTaskHandle_WIFI_CONN); // Notify the WiFi connection task to attempt reconnection
            #ifdef CONFIG_SERIAL_DEBUG
                Serial.println("Notifying WiFi Connection Task");
            #endif

            ulTaskNotifyTake(pdTRUE, portMAX_DELAY); // Wait for the WiFi connection
            #ifdef CONFIG_SERIAL_DEBUG
                Serial.println("WiFi Connection Task Completed");
            #endif

        } else {
            #ifdef CONFIG_SERIAL_DEBUG
                Serial.println("WiFi Connected");
            #endif
            if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
                WIFI_CONNECTED = true; // Update global connection status
                INTERNET_CONNECTED = true; // Update global internet connectivity status
                xSemaphoreGive(xMutex);
            }
        }
        vTaskDelay(pdMS_TO_TICKS(10000)); // Check connection every 10 seconds
    }
}

void xStart_WIFI_SVC() {
    xTaskCreatePinnedToCore(
        xTask_WIFI_SVC,          // Task function
        "WiFi Service Task",     // Name of the task
        CONFIG_WIFI_SVC_STACK_SIZE,                    // Stack size in words
        NULL,                    // Task input parameter
        CONFIG_WIFI_SVC_PRIORITY,                       // Priority of the task
        &tTaskHandle_WIFI_SVC,   // Task handle
        CONFIG_WIFI_SVC_USE_CORE_0 ? 0 : 1                        // Core where the task should run
    );
}