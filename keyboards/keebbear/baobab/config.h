#pragma once

#include "config_common.h"

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
/* #define DEBOUNCE 5 */

#define WS2812_PIO_USE_PIO1
#define RGBLED_NUM 14
#define RGB_MATRIX_LED_COUNT RGBLED_NUM

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN GP17
#define I2C1_SDA_PIN GP16
