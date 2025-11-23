/**
******************************************************************************
* @file           : display_manager.c
* @brief          : Display manager implementation
******************************************************************************
*/

#include "display_manager.h"
#include "main.h"
#include "st7735.h"
#include "lvgl.h"


/* Declare buffer for 1/10 screen size; BYTES_PER_PIXEL will be 2 for RGB565. */
#define BYTES_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565))
static uint8_t buf1[ST7735_WIDTH * ST7735_HEIGHT / 10 * BYTES_PER_PIXEL];


lv_display_t * display;

void my_flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map);


void initDisplay(void) {
    // Initialize the display hardware
    ST7735_Init();
    ST7735_Backlight_On();

    // initialize LVGL
    lv_init();
    lv_tick_set_cb(HAL_GetTick);

    // Create the display
    display = lv_display_create(ST7735_WIDTH, ST7735_HEIGHT);

    /* Set display buffer for display `display1`. */
    lv_display_set_buffers(display, buf1, NULL, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    lv_display_set_flush_cb(display, my_flush_cb);

 }


void my_flush_cb(lv_display_t * display, const lv_area_t * area, uint8_t * px_map)
{
    /* The most simple case (also the slowest) to send all rendered pixels to the
        * screen one-by-one.  `put_px` is just an example.  It needs to be implemented by you. */
    uint16_t * buf16 = (uint16_t *)px_map; /* Let's say it's a 16 bit (RGB565) display */
    int32_t x, y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            ST7735_DrawPixel(x, y, *buf16);
            buf16++;
        }
    }

    lv_display_flush_ready(display);
}


