/*
Copyright 2022 GEIST <@geigeigeist>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3A3C
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    "KEEBBEAR"
#define PRODUCT         "COOKIE40"


/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6


// wiring of each half
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { B4, B5, F4, F5, F6, F7 }
#define DIODE_DIRECTION COL2ROW

// #define UNUSED_PINS

//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#define DEBOUNCE 5


/* Serial settings */
// #define USE_SERIAL
/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D2
//#define SPLIT_LAYER_STATE_ENABLE
//#define SPLIT_USB_DETECT
// #define SERIAL_USE_MULTI_TRANSACTION


/* rgb led support */
#define RGB_DI_PIN D3

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define SPLIT_OLED_ENABLE
#    define OLED_FONT_H  "./lib/glcdfont.c"
#    define OLED_TIMEOUT 90000
#endif
