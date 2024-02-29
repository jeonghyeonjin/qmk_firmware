/* Copyright 2022 DZTECH <moyi4681@Live.cn>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "display.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum cichol_keycodes {
    DEV = SAFE_RANGE,
    DESIGN,
    GAME,
    LOWER,
    RAISE,
    ARRPAD,
    ADJUST
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

#define ADJUST MO(_ADJUST)
#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)
#define APDEN LT(_ARRPAD, KC_ENT)
#define APDSP LT(_ARRPAD, KC_SPC)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘

enum combos {
  QA_1,
  QASFT_1,
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

const uint16_t PROGMEM qa_combo[] =     {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM qasft_combo[] =  {KC_Q, KC_LSHA, COMBO_END};
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

combo_t key_combos[] = {
  [QA_1] = COMBO(qa_combo, KC_1),
  [QASFT_1] = COMBO(qasft_combo, KC_1),
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
  [HJ_EQL] = COMBO(hj_combo, KC_MINS),
  [NM_MINS] = COMBO(nm_combo, KC_EQL),

  [KL_QUOT] = COMBO(kl_combo, KC_QUOT),
  [OP_QUOT] = COMBO(op_combo, KC_QUOT),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ d e v                                                     │
   └───────────────────────────────────────────────────────────┘
*/
    [_DEV] = LAYOUT_default(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        QK_GESC, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
        KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_LSFT, KC_LSHA,  KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_RCLN,
        KC_LSFT, KC_CTLZ,  KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_CTSH,
        KC_LCTL,                               KC_RATA,  APDSP,    LOWER,    RAISE,    APDEN,    KC_GUBS
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ d e s i g n                                               │
   └───────────────────────────────────────────────────────────┘
*/
    [_DESIGN] = LAYOUT_default(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        QK_GESC, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
        KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_LSFT, KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_RCLN,
        KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_CTSH,
        KC_LCTL,                               KC_LALT,  APDSP,    LOWER,    RAISE,    APDEN,    KC_GUBS
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ g a m e                                                   │
   └───────────────────────────────────────────────────────────┘
*/
    [_GAME] = LAYOUT_default(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
        QK_GESC, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,
        KC_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_RCLN,
        KC_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_CTSH,
        KC_LCTL,                               KC_LALT,  KC_SPC,   LOWER,    RAISE,    APDEN,    KC_GUBS
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ l o w e r                                                 │
   └───────────────────────────────────────────────────────────┘
*/
    [_LOWER] = LAYOUT_default(
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
        _______, _______,  _______,  _______,  _______,  _______,                      KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,
        _______, _______,  _______,  _______,  _______,  KC_GRV,                       KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
        _______,                               _______,  _______,  _______,  ADJUST,   _______,  KC_DEL
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ r a i s e                                                 │
   └───────────────────────────────────────────────────────────┘
*/
    [_RAISE] = LAYOUT_default(
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______, KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
        _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
        _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,
        _______,                               _______,  _______,  ADJUST,   _______,  _______,  KC_DEL
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ a r r o w / n u m p a d                                   │
   └───────────────────────────────────────────────────────────┘
*/
    [_ARRPAD] = LAYOUT_default(
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  TO(_DEV), TO(_DESIGN), TO(_GAME),
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,
        _______, _______,  KC_7,     KC_8,     KC_9,     KC_MINS,                      _______,  KC_HOME,  KC_UP,    KC_END,      _______,
        _______, _______,  KC_4,     KC_5,     KC_6,     KC_PLUS,                      _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,     _______,
        _______, KC_0,     KC_1,     KC_2,     KC_3,     KC_EQL,                       _______,  KC_PGUP,  _______,  KC_PGDN,     _______,
        _______,                               _______,  _______,  _______,  _______,  _______,  _______
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ a d j u s t                                               │
   └───────────────────────────────────────────────────────────┘
*/
    [_ADJUST] = LAYOUT_default(
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  TO(_DEV), TO(_DESIGN), TO(_GAME),
        _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,
        _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,     _______,
        _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,     _______,
        _______, _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,     _______,
        _______,                               _______,  _______,  _______,  _______,  _______,  _______
    ),
};


layer_state_t layer_state_set_user(layer_state_t state) {

    if (is_display_enabled()) {
        display_process_layer_state(get_highest_layer(state));
    }

    return state;
}

// void layer_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
//     set_layer_img(*(uint8_t *)initiator2target_buffer);
// }
