
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_stack_of_waffles(
    KC_NO, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,
    KC_NO, KC_Q,  KC_W,  KC_E,  KC_R, KC_G,
    KC_NO, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B, LINKS, KC_NO,
                  KC_NO, UPDIR, ESCLWR,   KC_SPC,   KC_NO,

                    KC_Y, KC_U,  KC_I,    KC_O,   KC_P,    KC_NO,
                    KC_H, KC_Q,  KC_W,  KC_E,  KC_R, KC_NO,
    KC_NO, KC_MPLY, KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_NO,
    KC_NO, KC_BSPC, PSTRSE, PNP, KC_NO
  ),

  [_LOWER] = LAYOUT_stack_of_waffles(
    KC_TRNS, KC_1,    KC_2 ,  KC_3,     KC_4,     KC_5,
    KC_TRNS, KC_Q,  KC_W,  KC_E,  KC_R,  KC_PERC,
    KC_TRNS, KC_TRNS, KC_TAB, KC_CAPS,  KC_TILD,  KC_GRV,  KC_TRNS, KC_TRNS,
                              KC_TRNS,  KC_TRNS,  KC_TRNS, H_S,     KC_TRNS,

                      KC_6,    KC_7,     KC_8,     KC_9,     DEG0,     KC_TRNS,
                      KC_CIRC, KC_Q,  KC_W,  KC_E,  KC_R, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,
    KC_TRNS, STAR,    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT_stack_of_waffles(
    KC_TRNS, RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,
    KC_TRNS, KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD,
    KC_TRNS, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,  KC_1,   KC_TRNS,
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                      KC_1, KC_1, KC_1, KC_1, KC_1, KC_TRNS,
                      KC_1,   KC_1, KC_1,  KC_1,    KC_1, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_F6,     KC_F7,     KC_F8,     KC_F9,       KC_F10,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS
  )
};
