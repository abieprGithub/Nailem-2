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
constexpr char* WIFI_CREDENTIALS[5][2] = {
  {"HUAWEI-2.4G-ReY2", "12345678"},
  {"abiepr-p1", "abcdefgh"},
  {"Techno_MTsLvl7_4G", "sifatmuhammad"},
  {"Techno_MTsLvl8_4G", "sifatmuhammad"},
  {"Techno_MTsLvl9_4G", "sifatmuhammad"}
};

constexpr size_t NUM_WIFI_NETWORKS = sizeof(WIFI_CREDENTIALS) / sizeof(WIFI_CREDENTIALS[0]);

// General functions
#define CONFIG_USE_LCD
#define CONFIG_USE_NEXTION
#define CONFIG_SERIAL_DEBUG

// WiFi connection config
constexpr uint8_t CONFIG_WIFI_CONN_PRIORITY = 2;
constexpr uint16_t CONFIG_WIFI_CONN_STACK_SIZE = 8192;
constexpr bool CONFIG_WIFI_CONN_USE_CORE_0 = true; // Run on core 0 for better performance

constexpr uint8_t NUM_CONN_ATTEMPTS = 20;
constexpr uint8_t NUM_PING_ATTEMPTS = 5;
constexpr uint16_t CONN_TIMEOUT_MS = 1000; // Timeout for WiFi connection attempts in milliseconds
constexpr uint8_t PING_IP[4] = {8, 8, 8, 8}; // IP address to ping for internet connectivity check

// WiFi service config
constexpr uint8_t CONFIG_WIFI_SVC_PRIORITY = 1;
constexpr uint16_t CONFIG_WIFI_SVC_STACK_SIZE = 4096;
constexpr bool CONFIG_WIFI_SVC_USE_CORE_0 = true; // Run on core 0 for better performance