/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : config.h
  * @brief          : Centralized configuration header for this project.
  ******************************************************************************
**/
/* USER CODE END Header */
#pragma once
#include <Arduino.h>

// Pinouts
// ===================== ESP / SYSTEM =====================
#define __PIN_ESP_LED        48

// ===================== I2C BUS ==========================
#define __PIN_I2C_SCL        9
#define __PIN_I2C_SDA        8

// ===================== ANALOG SENSORS ===================
#define __PIN_PHS_SENSOR     4
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

// WiFi credentials
constexpr char* wifi[4][2] = {
  {"HUAWEI-2.4G-ReY2", "12345678"},
  {"Techno_MTsLvl7_4G", "sifatmuhammad"},
  {"Techno_MTsLvl8_4G", "sifatmuhammad"},
  {"Techno_MTsLvl9_4G", "sifatmuhammad"}
};

// WiFi connection attempts
constexpr uint8_t NUM_CONN_ATTEMPTS = 20;
constexpr uint8_t NUM_PING_ATTEMPTS = 5;

// WiFi connection config
constexpr uint8_t CONFIG_WIFI_CONN_PRIORITY = 2;
constexpr uint16_t CONFIG_WIFI_CONN_STACK_SIZE = 8192;
constexpr bool CONFIG_WIFI_CONN_USE_CORE_0 = true; // Run on core 0 for better performance

// WiFi service config
constexpr uint8_t CONFIG_WIFI_SVC_PRIORITY = 1;
constexpr uint16_t CONFIG_WIFI_SVC_STACK_SIZE = 4096;
constexpr bool CONFIG_WIFI_SVC_USE_CORE_0 = true; // Run on core 0 for better performance