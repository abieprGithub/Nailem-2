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

/* USER CODE END Includes */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Defines */
#define LED_PIN 13
/* USER CODE END Defines */

/* Pinouts -------------------------------------------------------------------*/
/* USER CODE BEGIN Pinouts */
// ===================== ESP / SYSTEM =====================
#define __PIN_ESP_LED        48

// ===================== I2C BUS ==========================
#define __PIN_I2C_SCL        9
#define __PIN_I2C_SDA        8

// ===================== ANALOG SENSORS ===================
#define __PIN_PHS_SENSOR      4
#define __PIN_TDS_SENSOR     5
#define __PIN_TRB_SENSOR     6

// ===================== DIGITAL SENSORS ==================
#define __PIN_DS18B20        7
#define __PIN_US_TRIG        15
#define __PIN_US_ECHO        16

// ===================== MOSFET OUTPUTS ===================
#define __PIN_MOSFET_1       38
#define __PIN_MOSFET_2       45
#define __PIN_MOSFET_3       47
#define __PIN_MOSFET_4       21

// ===================== RELAY OUTPUTS ====================
#define __PIN_RELAY_1        42
#define __PIN_RELAY_2        41
#define __PIN_RELAY_3        40
#define __PIN_RELAY_4        39

// ===================== STEPPER DRIVER ===================
#define __PIN_STEPPER_STEP   12
#define __PIN_STEPPER_DIR    13
#define __PIN_STEPPER_EN     14  

// ==================== STEPPER ENDSTOPS ==================

#define __PIN_RIGHT_STP      TBA
#define __PIN_LEFT_STP       TBA

// ===================== EXTRA OUTPUTS ====================
#define __PIN_LED_STRIP      3
#define __PIN_SERVO          1

// ===================== UART (JETSON BACKUP) =============
#define __PIN_UART_TX        TBA
#define __PIN_UART_RX        TBA
/* USER CODE END Pinouts*/

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

  /* USER CODE END Loop */

  /* USER CODE BEGIN Loop_End */

  /* USER CODE END Loop_End */
}

/* USER CODE BEGIN 1 */
// Extra helper functions here
/* USER CODE END 1 */