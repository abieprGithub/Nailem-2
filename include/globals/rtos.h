/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : rtos.h
  * @brief          : Header file for RTOS-related definitions and declarations
  ******************************************************************************
**/
/* USER CODE END Header */

#pragma once
#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>

extern SemaphoreHandle_t xMutex;
extern TaskHandle_t tTaskHandle_WIFI_CONN;
extern TaskHandle_t tTaskHandle_WIFI_SVC;