// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

enum layer_number {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARRPAD,
    _SYMBOL,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
    ARRPAD,
    SYMBOL,
    OS_SWAP,
    MAKE_H,
    SNAP1,
    SNAP2
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

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)
#define APDEN LT(_ARRPAD, KC_ENT)
#define APDSP LT(_ARRPAD, KC_SPC)

// #define SYMBOL MO(_SYMBOL)
#define SYMBOL LT(_SYMBOL, KC_LNG1)

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)

enum combos {
  QA_1,
  WS_2,
  ED_3,
  RF_4,
  TG_5,
  YH_6,
  UJ_7,
  IK_8,
  OL_9,
  PCLN_0,

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

  KL_QUOT,
  OP_QUOT,
};

const uint16_t PROGMEM qa_combo[] =     {KC_Q, KC_LSHA, COMBO_END};
const uint16_t PROGMEM ws_combo[] =     {KC_W, KC_S, COMBO_END};
const uint16_t PROGMEM ed_combo[] =     {KC_E, KC_D, COMBO_END};
const uint16_t PROGMEM rf_combo[] =     {KC_R, KC_F, COMBO_END};
const uint16_t PROGMEM tg_combo[] =     {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM yh_combo[] =     {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM uj_combo[] =     {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM ik_combo[] =     {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM ol_combo[] =     {KC_O, KC_L, COMBO_END};
const uint16_t PROGMEM pcln_combo[] =   {KC_P, KC_RCLN, COMBO_END};

const uint16_t PROGMEM qw_combo[] =     {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM xc_combo[] =     {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM er_combo[] =     {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM df_combo[] =     {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cv_combo[] =     {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM ui_combo[] =     {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM jk_combo[] =     {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mcomm_combo[] =  {KC_M, KC_COMM, COMBO_END};

const uint16_t PROGMEM rt_combo[] =     {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM fg_combo[] =     {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM vb_combo[] =     {KC_V, KC_B, COMBO_END};

const uint16_t PROGMEM yu_combo[] =     {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM hj_combo[] =     {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM nm_combo[] =     {KC_N, KC_M, COMBO_END};

const uint16_t PROGMEM kl_combo[] =     {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM op_combo[] =     {KC_O, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QA_1] = COMBO(qa_combo, KC_1),
  [WS_2] = COMBO(ws_combo, KC_2),
  [ED_3] = COMBO(ed_combo, KC_3),
  [RF_4] = COMBO(rf_combo, KC_4),
  [TG_5] = COMBO(tg_combo, KC_5),
  [YH_6] = COMBO(yh_combo, KC_6),
  [UJ_7] = COMBO(uj_combo, KC_7),
  [IK_8] = COMBO(ik_combo, KC_8),
  [OL_9] = COMBO(ol_combo, KC_9),
  [PCLN_0] = COMBO(pcln_combo, KC_0),

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

  [KL_QUOT] = COMBO(kl_combo, KC_QUOT),
  [OP_QUOT] = COMBO(op_combo, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
    *        .----------------------------------.                    ,----------------------------------.
    *        |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
    * .------+------+------+------+------+------|                    |------+------+------+------+------+------.
    * | LCTRL|   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  | BSPC |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | LSFT |   Z  |   X  |   C  |   V  |   B  |-------.    .-------|   N  |   M  |   ,  |   .  |   /  | RSFT |
    * `-----------------------------------------/       /    \       \-----------------------------------------'
    *                        | LALT  | LOWER|  / Space /      \ Enter \  | RAISE| RGUI |
    *                        `-------------' '-------'         '-------' '-------------'
    */
    [_QWERTY] = LAYOUT(
                  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                KC_Y,  KC_U,  KC_I,    KC_O,    KC_P,
                  KC_LSHA,  KC_S,  KC_D,  KC_F,  KC_G,                KC_H,  KC_J,  KC_K,    KC_L,    KC_RCLN,
                  KC_CTLZ,  KC_X,  KC_C,  KC_V,  KC_B,                KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_CTSH,
                             KC_RATA, APDSP, LOWER,    RAISE,  APDEN, KC_BSPC
    ),

    [_LOWER] = LAYOUT(
                    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                        KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
                    KC_ESC,   OSM(KC_LGUI),  KC_GRV,  _______,  _______,                        KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,
                    SNAP2,    _______,  _______,  _______,  _______,                        KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
                                        _______,  _______,  _______,     _______,  _______,  KC_DEL
        ),

    [_RAISE] = LAYOUT(
                    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                           KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
                    KC_ESC,   OSM(KC_LGUI),  KC_GRV,  _______,  _______,                        KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,
                    SNAP2,    _______,  _______,  _______,  _______,                        KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
                                        _______,  _______,  _______,    _______,  _______,  KC_DEL
    ),
    [_ADJUST] = LAYOUT(
                  KC_TAB,        LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),               LSFT(KC_BSLS),  KC_DEL,  KC_PGDN, KC_PGUP, KC_INS,
                  LSFT(KC_EQL),  LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_LBRC),            LSFT(KC_QUOT),  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                  LSFT(KC_MINS), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_RBRC),            LSFT(KC_GRV),   KC_HOME, KC_END,  XXXXXXX, XXXXXXX,
                                                           _______, _______, KC_CAPS,      XXXXXXX, _______, _______
    ),
    [_ARRPAD] = LAYOUT(
                _______,  KC_7,     KC_8,     KC_9,     KC_MINS,                       _______,  KC_HOME,  _______,  KC_END,   _______,
                _______,  KC_4,     KC_5,     KC_6,     KC_PLUS,                       _______,  KC_LEFT,  KC_UP,    KC_RGHT,  KC_QUOT,
                KC_0,     KC_1,     KC_2,     KC_3,     KC_EQL,     _______,  KC_PGUP,  KC_DOWN,  KC_PGDN,  _______,
                                    _______,  _______,  _______,    _______,  _______,  _______
    ),
    [_SYMBOL] = LAYOUT(
                _______,  _______,  _______,  _______,  _______,                       _______,  _______,  KC_LPRN,  KC_RPRN,  _______,
                _______,  _______,  _______,  _______,  _______,                       _______,  _______,  KC_LCBR,  KC_RCBR,  KC_QUOT,
                _______,  _______,  _______,  _______,  _______,    _______,  _______,  KC_LBRC,  KC_RBRC,  _______,
                                    _______,  _______,  _______,    _______,  _______,  _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE
                }
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }

// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘

      case SNAP1:
          if (record->event.pressed) {
              if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LSFT(SS_LCMD("4")));           //MAC
              } else {
              SEND_STRING(SS_LWIN(SS_TAP(X_PSCR)));         //WIN
              }
          }
          break;
      case SNAP2:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
            } else {
              SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
            }
          }
          break;
    }
    return true;
}
