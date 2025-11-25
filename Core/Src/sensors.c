/**
******************************************************************************
* @file           : sensors.c
* @brief          : Sensors implementation
******************************************************************************
*/

#include "sensors.h"
#include "driver_sht31.h"
#include "shroom_shed.h"
#include "driver_sht31_basic.h"
#include "stdint.h"
#include "usbd_cdc_if.h"


uint8_t res;
uint8_t sn[4];
float temperature;
float humidity;



void init_sensors(void) {
    if (sht31_basic_init(SHT31_ADDRESS_0)) {
        sprintf(usb_buffer, "Failed to initialize SHT31 sensor\r\n");
        CDC_Transmit_FS((uint8_t*)usb_buffer, strlen(usb_buffer));
    }

    sht31_basic_get_serial_number(sn);
    sprintf(usb_buffer, "sht31: serial number is 0x%02X 0x%02X 0x%02X 0x%02X.\n", sn[0], sn[1], sn[2], sn[3]);
    CDC_Transmit_FS((uint8_t*)usb_buffer, strlen(usb_buffer));
}

void read_sensors(void) {
    
    if (sht31_basic_read((float *)&temperature, (float *)&humidity)) {
        sprintf(usb_buffer, "Failed to read from SHT31 sensor\r\n");
        CDC_Transmit_FS((uint8_t*)usb_buffer, strlen(usb_buffer));
    } else {
        sprintf(usb_buffer, "SHT31 Read Result: %d, Temperature: %.2f C, Humidity: %.2f %%\r\n", res, temperature, humidity);
        CDC_Transmit_FS((uint8_t*)usb_buffer, strlen(usb_buffer));
        shroomShed.temperatureCurrent = temperature;
        shroomShed.humidityCurrent = humidity;  
    } 
}
    


