#include QMK_KEYBOARD_H

enum combos {
  QW_TAB,
  XC_CTLZ,

  ER_LPRN,
  DF_LCBR,
  CV_LBRC,

  UI_RPRN,
  JK_RCBR,
  MCOMM_RBRC,

  RT_DQUO,
  FG_PLUS,
  VB_UNDS,

  YU_QUOT,
  HJ_EQL,
  NM_MINS,
};

const uint16_t PROGMEM qw_combo[] =     {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM xc_combo[] =     {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM er_combo[] =     {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM df_combo[] =     {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cv_combo[] =     {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM ui_combo[] =     {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM jk_combo[] =     {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] =     {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM rt_combo[] =     {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] =     {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] =     {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM yu_combo[] =     {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] =     {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] =     {KC_N, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [XC_CTLZ] = COMBO(xc_combo, LCTL(KC_Z)),

  [ER_LPRN] = COMBO(er_combo, KC_LPRN),
  [DF_LCBR] = COMBO(df_combo, KC_LCBR),
  [CV_LBRC] = COMBO(cv_combo, KC_LBRC),

  [UI_RPRN] = COMBO(ui_combo, KC_RPRN),
  [JK_RCBR] = COMBO(jk_combo, KC_RCBR),
  [MCOMM_RBRC] = COMBO(mcomm_combo, KC_RBRC),

  [RT_DQUO] = COMBO(rt_combo, KC_DQUO),
  [FG_PLUS] = COMBO(fg_combo, KC_PLUS),
  [VB_UNDS] = COMBO(vb_combo, KC_UNDS),

  [YU_QUOT] = COMBO(yu_combo, KC_QUOT),
  [HJ_EQL] = COMBO(hj_combo, KC_EQL),
  [NM_MINS] = COMBO(nm_combo, KC_MINS),
};

#define KC_LSHA LSFT_T(KC_A)
#define KC_CTLZ LCTL_T(KC_Z)
#define KC_RCLN RSFT_T(KC_SCLN)
#define KC_CTSH RCTL_T(KC_SLSH)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_GUBS GUI_T(KC_BSPC)
#define KC_GUDE GUI_T(KC_DEL)
#define KC_RABS RALT_T(KC_BSPC)
#define KC_RATA RALT_T(KC_TAB)

#define SPC4 LT(4, KC_SPC)
#define ENT4 LT(4, KC_ENT)
#define SPC1 LT(1, KC_SPC)
#define ENT2 LT(2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x5_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSHA, KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,   KC_RCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CTLZ, KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,                       KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_CTSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RATA, SPC4  ,  SPC1,     ENT2, ENT4 , KC_GUBS
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x5_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,                      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RATA, SPC4,  _______,     MO(3), ENT4, KC_GUDE
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x5_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,                      XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RATA,  SPC4,  MO(3),     _______, ENT4, KC_GUDE
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x5_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, RGB_MOD, RGB_RMOD,XXXXXXX, XXXXXXX,                                       XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                                       XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RATA,  SPC4, _______,     _______, ENT4, KC_GUBS
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x5_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_7,    KC_8,    KC_9,  KC_MINS,                                         XXXXXXX, KC_HOME, KC_UP,   KC_END,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_4,    KC_5,    KC_6,  KC_PLUS,                                         XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL,   XXXXXXX,                      KC_MINS, XXXXXXX, KC_PGUP, XXXXXXX, KC_PGDN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_RATA,  SPC4, _______,     _______, ENT4, KC_GUBS
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_ARROW 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ARROW:
            oled_write_ln_P(PSTR("Arrow"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_ARROW:
        case L_ADJUST|L_LOWER|L_RAISE:
        case L_ADJUST|L_LOWER|L_ARROW:
        case L_ADJUST|L_RAISE|L_ARROW:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
