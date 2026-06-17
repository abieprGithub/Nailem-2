/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body for ESP32-S3 Nailem project
  ******************************************************************************
  * @attention
  *
  * ESP32-S3 Nailem Aquascape project, main program body
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include "globals/rtos.h"
#include "wireless/wifi_conn.h"
#include "wireless/wifi_svc.h"
#include "config.h"
/* USER CODE END Includes */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Defines */

/* USER CODE END Defines */

/* Pinouts -------------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The setup function runs once when you press reset or power the board
  */
void setup() {
  /* USER CODE BEGIN Setup_Init */
  xMutex = xSemaphoreCreateMutex();
  Serial.begin(115200);
  Serial.println("Starting ESP32-S3 ...");
  xStart_WIFI_CONN();
  xStart_WIFI_SVC();
  /* USER CODE END Setup_Init */

  /* USER CODE BEGIN Setup */
  // Additional setup code here
  /* USER CODE END Setup */
}

/**
  * @brief  The loop function runs over and over again forever
  */
void loop() {
  /* USER CODE BEGIN Loop */
  vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
  /* USER CODE END Loop */

  /* USER CODE BEGIN Loop_End */

  /* USER CODE END Loop_End */
}

/* USER CODE BEGIN 1 */
// Extra helper functions here
/* USER CODE END 1 */