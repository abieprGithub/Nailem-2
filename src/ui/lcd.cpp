/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : lcd.cpp
  * @brief          : Source file for LCD display tasks
  ******************************************************************************
**/
/* USER CODE END Header */
#include "ui/lcd.h"
#include "freertos/FreeRTOS.h"
#include "globals/rtos.h"
#include "wireless/ntp.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "config.h"
#include <stdarg.h> // For snprintf

LiquidCrystal_I2C OBJ_LCD(LCD_I2C_ADDRESS, LCD_COLUMNS, LCD_ROWS); // Create an instance of the LiquidCrystal_I2C class

uint8_t LCD_TARGET_PAGE = 0;
bool TM1 = false;

void INTERNAL_TIMER(void *pv) {
  while (1) {
    if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
      TM1 = !TM1; // Toggle the software timer flag
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(LCD_REFRESH_RATE_MS * 3)); // Delay for the specified refresh rate
  }
}

void LCD_PRINT(uint8_t x, uint8_t y, const char *fmt, ...) {
  char BUF[LCD_PRINTF_BUF_SIZE]; // Buffer for formatted string

  va_list args;
  va_start(args, fmt);

  vsnprintf(BUF, sizeof(BUF), fmt, args); // Format the string

  va_end(args);

  OBJ_LCD.setCursor(x, y); // Set cursor position
  OBJ_LCD.print(BUF); // Print the formatted string to the LCD
}

void LCD_DRAW_HEADER() {
  bool SW;
  bool TIME_VALID;

  tm timeinfo;
  tm now;

  LCD_PRINT(0, 0, "><> Nailem");

  if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
    SW = TM1;
    if (getLocalTime(&timeinfo)) {
      TIME_VALID = true;
      now = timeinfo;
    } else {
      TIME_VALID = false;
    }
    xSemaphoreGive(xMutex);
  }

  if (TIME_VALID) {
    if (SW) {
      LCD_PRINT(11, 0, " %02d/%02d/%02d", now.tm_mday, now.tm_mon + 1, now.tm_year - 100);
    } else {
      LCD_PRINT(11, 0, " %02d:%02d:%02d", now.tm_hour, now.tm_min, now.tm_sec);
    }

  } else {
    LCD_PRINT(11, 0, "  NTP ERR");
  }
}

void LCD_P0() {
  LCD_DRAW_HEADER();
}

void LCD_P1() {
  LCD_DRAW_HEADER();
}

void LCD_P2() {
  LCD_DRAW_HEADER();
}


void xTask_LCD(void *pv) {
  OBJ_LCD.init();
  OBJ_LCD.backlight();

  while (1) {
    switch (LCD_TARGET_PAGE) {
      case 0: {
        LCD_P0();
      }

      case 1: {
        LCD_P1();
      }

      case 2: {
        LCD_P2();
      }
    }

    vTaskDelay(pdMS_TO_TICKS(LCD_REFRESH_RATE_MS)); // Delay for the specified refresh rate
  }
}



void xStart_LCD() {
  xTaskCreatePinnedToCore(INTERNAL_TIMER, "LCD TM", 1024, NULL, 1, NULL, CONFIG_LCD_USE_CORE_0 ? 0 : 1);

  xTaskCreatePinnedToCore(
      xTask_LCD,          // Task function
      "LCD Task",         // Name of the task
      CONFIG_LCD_STACK_SIZE, // Stack size in words
      NULL,               // Task input parameter
      CONFIG_LCD_PRIORITY,                  // Priority of the task
      NULL,               // Task handle
      CONFIG_LCD_USE_CORE_0 ? 0 : 1 // Core to run the task on
  );
}