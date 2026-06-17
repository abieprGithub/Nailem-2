/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : rtos.cpp
  * @brief          : Source file for RTOS-related definitions and declarations
  ******************************************************************************
**/
/* USER CODE END Header */
#include "globals/rtos.h"

SemaphoreHandle_t xMutex = nullptr; // Initialize the mutex handle to nullptr
TaskHandle_t tTaskHandle_WIFI_CONN = nullptr;
TaskHandle_t tTaskHandle_WIFI_SVC = nullptr;