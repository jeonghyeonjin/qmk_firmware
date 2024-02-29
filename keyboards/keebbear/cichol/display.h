// SPDX-License-Identifier: GPL-2.0-or-later

#include "qp_lvgl.h"
#include "quantum.h"

typedef enum {
    _DEV = 0,
    _DESIGN,
    _GAME,
    _LOWER,
    _RAISE,
    _ARRPAD,
    _ADJUST
} layer_number;

#define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define MODS_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define MODS_ALT ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define MODS_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

/* shared styles */
extern lv_style_t style_screen;
extern lv_style_t style_container;
extern lv_style_t style_button;
extern lv_style_t style_button_active;

bool display_init_kb(void);
bool display_init_user(void);
void display_housekeeping_task(void);
void display_process_caps(bool active);

void display_process_layer_state(uint8_t layer);
