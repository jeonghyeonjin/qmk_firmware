#pragma once

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
/* #define DEBOUNCE 5 */

#define RGBLIGHT_DEFAULT_MODE 9

#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X32
  #define OLED_TIMEOUT 400000
#endif

#define I2C_DRIVER I2CD1
