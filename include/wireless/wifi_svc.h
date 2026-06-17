/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : wifi_svc.h
  * @brief          : Header file for WiFi service task definition
  ******************************************************************************
**/
/* USER CODE END Header */

extern bool WIFI_CONNECTED; // Global variable to track WiFi connection status
extern bool INTERNET_CONNECTED; // Global variable to track internet connectivity status

void xTask_WIFI_SVC();
void xStart_WIFI_SVC();