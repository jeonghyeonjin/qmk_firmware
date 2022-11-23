#pragma once

#include "config_common.h"

#define DEVICE_VER      0x0001
#define PRODUCT         "frame40"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring of each half
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X64
#    define OLED_FONT_H  "./lib/glcdfont.c"
#    define OLED_TIMEOUT 90000
#endif

/* Pointing device configuration. */

// Enable use of pointing device on slave split.
#define SPLIT_POINTING_ENABLE

// Pointing device is on the right split.
#define POINTING_DEVICE_RIGHT

// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

// Configure for the Cirque model used on the Dilemma.
#define CIRQUE_PINNACLE_DIAMETER_MM 40
// #define CIRQUE_PINNACLE_CURVED_OVERLAY
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE // Circular scroll.
#define CIRQUE_PINNACLE_TAP_ENABLE // tab
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
