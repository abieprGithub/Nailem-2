/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : ntp.h
  * @brief          : Header file for NTP synchronization task definition
  ******************************************************************************
**/
/* USER CODE END Header */
#pragma once
#include <Arduino.h>
#include "time.h"

void xTask_WIFI_NTP();
void xStart_WIFI_NTP();

extern bool NTP_VALID; // Global variable to track NTP synchronization status

constexpr auto NTP_SERVER = "pool.ntp.org"; // NTP server to synchronize with
constexpr auto GMT_OFFSET_SEC = 7L * 3600L; // GMT offset in seconds (adjust for your timezone)
constexpr auto DAYLIGHT_OFFSET_SEC = 0; // Daylight saving time offset in seconds (
