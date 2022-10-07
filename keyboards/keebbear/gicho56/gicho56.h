
#pragma once

#include "quantum.h"
// #include "pointing_device.h"

#define ___ KC_NO

// clang-format off
#define LAYOUT_gicho56( \
       L01, L02, L03, L04, L05,                                   R05, R04, R03, R02, R01,      \
  L10, L11, L12, L13, L14, L15,                                   R15, R14, R13, R12, R11, R10, \
  L20, L21, L22, L23, L24, L25,                                   R25, R24, R23, R22, R21, R20, \
  L30, L31, L32, L33, L34, L35, L36,                         R36, R35, R34, R33, R32, R31, R30, \
                 L43, L44, L45, L46,                         R46, R45, R44, R43                 \
  ) \
  { \
    { ___, L01, L02, L03, L04, L05, ___ }, \
    { L10, L11, L12, L13, L14, L15, ___ }, \
    { L20, L21, L22, L23, L24, L25, ___ }, \
    { L30, L31, L32, L33, L34, L35, L36 }, \
    { ___, ___, ___, L43, L44, L45, L46 }, \
                                           \
    { ___, R01, R02, R03, R04, R05, ___ }, \
    { R10, R11, R12, R13, R14, R15, ___ }, \
    { R20, R21, R22, R23, R24, R25, ___ }, \
    { R30, R31, R32, R33, R34, R35, R36 }, \
    { ___, ___, ___, R43, R44, R45, R46 }  \
}

typedef union {
    uint32_t raw;
    struct {
        uint8_t dpi_config;
    };
} keyboard_config_t;

extern keyboard_config_t keyboard_config;

enum ploopy_keycodes {
    DPI_CONFIG = SAFE_RANGE,
    KEYMAP_SAFE_RANGE,
};

typedef struct {
    uint16_t device_cpi;
} kb_config_data_t;

void trackball_set_cpi(uint16_t cpi);
void matrix_init_sub_kb(void);
void matrix_scan_sub_kb(void);

void keyboard_pre_init_sync(void);
void keyboard_post_init_sync(void);
void housekeeping_task_sync(void);
