/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : lcd.h
  * @brief          : Header file for LCD display task definition
  ******************************************************************************
**/
/* USER CODE END Header */
#pragma once

#include <Arduino.h>

void xTask_LCD(void *pv);
void xStart_LCD();

extern uint8_t LCD_TARGET_PAGE;