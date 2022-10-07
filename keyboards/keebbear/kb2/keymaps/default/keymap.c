#include QMK_KEYBOARD_H
#include "keycodes.h"

#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    * QWERTY
    *          ,----------------------------------------------.                      ,----------------------------------------------.
    *         |   `   |   1   |   2   |   3   |   4   |   5   |                     |   6   |   7   |   8   |   9   |   0   |  _ -  |
    *         |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *         |  Tab  |   Q   |   W   |   E   |   R   |   T   |                     |   Y   |   U   |   I   |   O   |   P   |  Bkpc |
    *         |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *         | Shift |   A   |   S   |   D   |   F   |   G   |                     |   H   |   J   |   K   |   L   |  ; :  |  ' "  |
    *         |-------+-------+-------+-------+-------+-------|-------.      .------|-------+-------+-------+-------+-------+-------|
    *         | Shift |   Z   |   X   |   C   |   V   |   B   |  Esc  |     |   B   |   N   |   M   |  , <  |  . >  |  / ?  |   ↑   |
    *         |-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------+-------.
    *         |  CTRL |  GUI  |  Alt  |  Alt  |     Space     | Lower |     | RAISE |     Enter     |RAI\Bsp| RAISE |   ←   |   ↓   |   →   |
    *         `------------------------------------------------------'      '-------------------------------------------------------+------'
    */

    [_QWERTY] = LAYOUT( \
               KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
               TAB_MOVE,KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
               KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, SFT_QT, \
               KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,  KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   \
      _______, KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, KC_SPC,           LOWER,   RAISE,   KC_ENT,           RAI_BSP, RAISE,   KC_LEFT, KC_DOWN, KC_RGHT \
    ),

    /*
    * Lower
    *           ,----------------------------------------------.                      ,----------------------------------------------.
    *          |  Esc  |   6   |   7   |   8   |   9   |   0   |                     |       |       |       |   (   |   )   |  + =  |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |       |   Y   |   U   |   I   |   O   |   P   |                     |       |       |       |   {   |   }   |  Del  |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |       |   H   |   J   |   K   |   L   |  ; :  |                     |       |       |       |   [   |   ]   |       |
    *          |-------+-------+-------+-------+-------+-------|-------.      .------|-------+-------+-------+-------+-------+-------|
    *          |       |   N   |   M   |  , <  |  . >  |  / ?  |       |     |       |       |       |       |   \   |   |   |       |
    *          |-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------+-------.
    *          |       |       |       |       |               |       |     |       |               |       |       |       |       |       |
    *          `------------------------------------------------------'      '-------------------------------------------------------+------'
    */

    [_LOWER] = LAYOUT( \
               KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, _______, _______, KC_LPRN, KC_RPRN, KC_EQL,  \
               _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                      _______, _______, _______, KC_LCBR, KC_RCBR, KC_DEL,  \
               _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,                   _______, _______, _______, KC_LBRC, KC_RBRC, _______, \
               _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, _______, _______, _______, _______, KC_BSLS, KC_PIPE, _______, \
      _______, _______, _______, _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______, _______ \
    ),

   /*
    * Raise
    *           ,----------------------------------------------.                      ,----------------------------------------------.
    *          |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |                     |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |       |   1   |   2   |   3   |   4   |   5   |                     |   6   |   7   |   8   |   9   |   0   |  Del  |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |       |       |       |       |       |       |                     |       |       |       |       |       |       |
    *          |-------+-------+-------+-------+-------+-------|-------.      .------|-------+-------+-------+-------+-------+-------|
    *          |       |       |       |       |       |       |  Caps |     |       |       |       |       |       |       |  Home |
    *          |-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------+-------.
    *          |       |       |       |       |               |       |     |       |               |       |       |Page Up|  End  |Page Dn|
    *          `------------------------------------------------------'      '-------------------------------------------------------+------'
    */

    [_RAISE] = LAYOUT( \
               KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
               _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
               _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
               _______, _______, _______, _______, _______, _______, KC_CAPS, _______, BALL_HUI, BALL_WHT, BALL_DEC, _______, _______, KC_HOME, \
      _______, _______, _______, _______, _______, _______,          _______, _______, _______,          _______, _______, KC_PGUP, KC_END,  KC_PGDN \
    ),

    /*
    * MOVE
    *           ,----------------------------------------------.                      ,----------------------------------------------.
    *          |       |       |       |       |       |       |                     |       |       |       |       |       |       |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |       |       |   ↑   |       |       |       |                     |       |       |   ↑   |       |       |       |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |       |   ←   |   ↓   |   →   |       |       |                     |       |   ←   |   ↓   |   →   |       |       |
    *          |-------+-------+-------+-------+-------+-------|-------.      .------|-------+-------+-------+-------+-------+-------|
    *          |       |       |       |       |       |       |       |     |       |       |       |       |       |       |       |
    *          |-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------+-------.
    *          |       |       |       |       |               |       |     |       |               |       |       |       |       |       |
    *          `------------------------------------------------------'      '-------------------------------------------------------+------'
    */

    [_MOVE] = LAYOUT( \
               _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
               _______, _______, KC_UP,   _______, _______, _______,                   _______, _______, KC_UP,   _______, _______, _______, \
               _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
               _______, _______, _______, _______, _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,          _______, _______, _______,          _______, _______, _______, _______,  _______ \
    ),

   /*
    * Adjust
    *           ,----------------------------------------------.                      ,----------------------------------------------.
    *          |███████|███████|███████|███████|███████|███████|                     |███████|███████|███████|███████|EEP RST| Reset |
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |███████|RGB TOG|RGB RST|███████|███████|███████|                     |███████|███████|███████|███████|███████|███████|
    *          |-------+-------+-------+-------+-------+-------|                     |-------+-------+-------+-------+-------+-------|
    *          |███████| MODE+ | HUE + | SAT + | VAL + | SPD + |                     |███████|███████|███████|███████| VOL + |███████|
    *          |-------+-------+-------+-------+-------+-------|-------.      .------|-------+-------+-------+-------+-------+-------|
    *          |███████| MODE- | HUE - | SAT - | VAL - | SPD - |███████|     |███████|███████|███████|███████|███████| VOL - |███████|
    *          |-------+-------+-------+-------+-------+-------+-------|     |-------+-------+-------+-------+-------+-------+-------+-------.
    *          |███████|███████|███████|███████|               |███████|     |███████|               |       |███████|███████|███████|███████|
    *          `------------------------------------------------------'      '-------------------------------------------------------+------'
    */

    [_ADJUST] =  LAYOUT( \
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, RESET,   \
               XXXXXXX, RGB_TOG, RGBRST,  XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
               XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, \
               XXXXXXX, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______, _______,          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
    )
};

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return true;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


#ifdef PIMORONI_TRACKBALL_ENABLE
void run_trackball_cleanup(void) {
    // if (trackball_is_scrolling()) {
    //     trackball_set_rgbw(RGB_CYAN, 0x00);
    // } else if (trackball_get_precision() != 1.0) {
    //     trackball_set_rgbw(RGB_GREEN, 0x00);
    // } else {
    // trackball_set_rgbw(RGB_MAGENTA, 0x00);
    // }
}

void keyboard_post_init_keymap(void) {
    // trackball_set_precision(1.5);
    // trackball_set_rgbw(RGB_MAGENTA, 0x00);
}
// void shutdown_keymap(void) { trackball_set_rgbw(RGB_RED, 0x00); }

static bool mouse_button_one, trackball_button_one;

void trackball_register_button(bool pressed, enum mouse_buttons button) {
    report_mouse_t currentReport = pointing_device_get_report();
    if (pressed) {
        currentReport.buttons |= button;
    } else {
        currentReport.buttons &= ~button;
    }
    pointing_device_set_report(currentReport);
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_1:
            if (IS_LAYER_ON(_LOWER)) {
                if (record->event.pressed) {
                    register_code(KC_2);
                } else {
                    unregister_code(KC_2);
                }
                return false;
            }
            break;
        case KC_2:
            if (IS_LAYER_ON(_LOWER)) {
                if (record->event.pressed) {
                    register_code(KC_1);
                } else {
                    unregister_code(KC_1);
                }
                return false;
            }
            break;
#ifdef PIMORONI_TRACKBALL_ENABLE
        case PM_SCROLL:
            // trackball_set_scrolling(record->event.pressed);
            run_trackball_cleanup();
            break;
        case PM_PRECISION:
            // if (record->event.pressed) {
            //     trackball_set_precision(1.5);
            // } else {
            //     trackball_set_precision(1);
            // }
            // run_trackball_cleanup();
            break;
#    if !defined(MOUSEKEY_ENABLE)
        case KC_MS_BTN1:
            mouse_button_one = record->event.pressed;
            trackball_register_button(mouse_button_one | trackball_button_one, MOUSE_BTN1);
            break;
        case KC_MS_BTN2:
            trackball_register_button(record->event.pressed, MOUSE_BTN2);
            break;
        case KC_MS_BTN3:
            trackball_register_button(record->event.pressed, MOUSE_BTN3);
            break;
#    endif
#endif
    }
    return true;
}




uint8_t white = 0;
uint8_t red = 255;
uint8_t green = 0;
uint8_t blue = 0;

void ball_increase_hue(void){
      if(red!=255&&green!=255&&blue!=255){
        red =255;
      }
      if (red==255&&green<255&&blue==0){
       green += 15;
      } else if(green==255&&blue==0&&red>0){
        red-=15;
      } else if(red==0&&blue<255&&green==255){
        blue+=15;
      } else if(blue==255&&green>0&&red==0){
        green -= 15;
      } else if(green == 0&&blue==255&&red<255){
        red +=15;
      } else if(green ==0&&blue>0&&red==255){
        blue -=15;
      }
      pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void decrease_color(void){
  if (green>0){
    green-=15;
  }
  if (red>0){
    red-=15;
  }
  if (blue>0){
    blue-=15;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void cycle_white(void){
  if (white<255){
    white +=15;
  } else{
    white=0;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch (keycode){
  case  BALL_HUI:
    if(record->event.pressed){
      ball_increase_hue();
    }
    break;

  case BALL_WHT:
    if(record-> event.pressed){
      cycle_white();
    }
    break;

  case BALL_DEC:
   if(record-> event.pressed){
      decrease_color();
    }
    break;

  case BALL_NCL:
     record->event.pressed?register_code(KC_BTN1):unregister_code(KC_BTN1);
     break;
  case BALL_RCL:
      record->event.pressed?register_code(KC_BTN2):unregister_code(KC_BTN2);
      break;
  case BALL_MCL:
      record->event.pressed?register_code(KC_BTN3):unregister_code(KC_BTN3);
      break;
  }
  return true;
}
