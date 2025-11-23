/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : display_manager.h
  * @brief          : Header for display_manager.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DISPLAY_MANAGER_H
#define __DISPLAY_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "lvgl.h"


void initDisplay(void);
void my_flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map);


#ifdef __cplusplus
}
#endif

#endif /* __DISPLAY_MANAGER_H */
