#include QMK_KEYBOARD_H
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(

    /*
    *         ┌───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┐
    * ┌───────┤   1   │   2   │   3   │   4   │   5   │                         │   6   │   7   │   8   │   9   │   0   ├───────┐
    * │  TAB  ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤ BKSPC │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤   Q   │   W   │   E   │   R   │   T   │          QWERTY         │   Y   │   U   │   I   │   O   │   P   ├───────┐
    * │ SHIFT ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤  ' "  │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤   A   │   S   │   D   │   F   │   G   │                         │   H   │   J   │   K   │   L   │  ; :  ├───────┐
    * │ SHIFT ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤ SHIFT │
    * └───────┘┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐└───────┘
    *          │   Z   │   X   │   C   │   V   │   B   │  ESC  │       │   B   │   N   │   M   │  , <  │  . >  │  / ?  │
    *          └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
    *  ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐
    *  │  CTL  │  GUI  │  ALT  │       │  MOV  │  SPC  │LOW/ENT│       │RAI/SPC│  ENT  │ BKSPC │       │  _ -  │  + =  │       │
    *  └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘
    */

    KC_TAB,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_LSFT,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SFT_QT,
    KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,      KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_LCTL,  KC_LGUI, KC_LALT,          MOVE,    KC_SPC,  LOW_ENT,     RAI_SPC, KC_ENT,  KC_BSPC,          KC_MINS, KC_EQL,  KC_TAB
  ),

  [_LOWER] = LAYOUT(

    /*
    *         ┌───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┐
    * ┌───────┤       │       │       │       │       │                         │       │       │       │   (   │   )   ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤  Del  │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤       │       │       │       │       │          LOWER          │       │       │       │   {   │   }   ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤       │       │       │   ↑   │       │                         │       │       │       │   [   │   ]   ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┘┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐└───────┘
    *          │       │       │   ←   │   ↓   │   →   │       │       │       │       │       │       │   \   │   |   │
    *          └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
    *  ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐
    *  │       │       │       │       │       │       │       │       │       │       │       │       │       │       │       │
    *  └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘
    */

    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, KC_LPRN, KC_RPRN, KC_DEL,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, KC_UP,   _______,                       _______, _______, _______, KC_LBRC, KC_RBRC, _______,
             _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,     _______, _______, _______, _______, KC_BSLS, KC_PIPE,
    _______, _______, _______,          _______, _______, _______,     _______, _______, _______,          _______, _______, _______
  ),

  [_RAISE] = LAYOUT(

    /*
    *         ┌───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┐
    * ┌───────┤  F2   │  F3   │  F4   │  F5   │  F6   │                         │  F7   │  F8   │  F9   │  F10  │  F11  ├───────┐
    * │  F1   ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤  F12  │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤   1   │   2   │   3   │   4   │   5   │          RAISE          │   6   │   7   │   8   │   9   │   0   ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤       │       │       │       │       │                         │       │       │       │       │       ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┘┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐└───────┘
    *          │       │       │       │       │       │       │       │       │       │       │       │       │       │
    *          └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
    *  ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐
    *  │       │       │       │       │       │       │       │       │       │       │       │       │       │       │       │
    *  └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘
    */

    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    _______, _______, _______,          _______, _______, _______,     _______, _______, _______,          _______, _______, _______
  ),

  [_MOVE] = LAYOUT(

    /*
    *         ┌───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┐
    * ┌───────┤       │       │       │       │       │                         │       │       │       │       │       ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤       │   ↑   │       │       │       │          MOVE           │       │       │   ↑   │       │       ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┼───────┬───────┬───────┬───────┬───────┐                         ┌───────┬───────┬───────┬───────┬───────┼───────┘
    * ┌───────┤   ←   │   ↓   │   →   │       │       │                         │       │   ←   │   ↓   │   →   │       ├───────┐
    * │       ├───────┴───────┴───────┴───────┴───────┘                         └───────┴───────┴───────┴───────┴───────┤       │
    * └───────┘┌───────┬───────┬───────┬───────┬───────┬───────┐       ┌───────┬───────┬───────┬───────┬───────┬───────┐└───────┘
    *          │       │       │       │       │       │       │       │       │       │       │       │       │   ↑   │
    *          └───────┴───────┴───────┴───────┴───────┴───────┘       └───────┴───────┴───────┴───────┴───────┴───────┘
    *  ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐       ┌───────┬───────┬───────┐
    *  │       │       │       │       │       │       │       │       │       │       │       │       │   ←   │   ↓   │   →   │
    *  └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘       └───────┴───────┴───────┘
    */

    _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
    _______, _______, KC_UP,   _______, _______, _______,                       _______, _______, KC_UP,   _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
             _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_UP,
    _______, _______, _______,          _______, _______, _______,     _______, _______, _______,          KC_LEFT, KC_DOWN, KC_RGHT
  )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
