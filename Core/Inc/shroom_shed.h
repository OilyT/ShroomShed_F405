/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : shroom_shed.h
  * @brief          : Header for shroom_shed.c file.
  *                   This file contains structs and defines for the shroom shed
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SHROOM_SHED_H
#define __SHROOM_SHED_H

#ifdef __cplusplus
extern "C" {   
#endif


// start user code

#include <stdint.h>
#include <stdbool.h>


struct shroomShed_t {

    float humidityCurrent;
    float temperatureCurrent;
    uint8_t humidityControlvalue;
    uint8_t fanSpeed;

    bool waterState;
};

extern struct shroomShed_t shroomShed;
extern char usb_buffer[200];


#ifdef __cplusplus
}
#endif

#endif /* __SHROOM_SHED_H */