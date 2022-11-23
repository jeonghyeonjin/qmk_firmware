#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "frame40.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘

enum cookie_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _ARRPAD,
    _SYMBOL,
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

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

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

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

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘

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

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ q w e r t y                                               │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SHIFT/A │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │ SHIFT/; │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │  CTRL/Z │    X    │    C    │    V    │    B    │   ESC   ││    B    │    N    │    M    │    ,    │    .    │  CTRL// │
   ╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┴─────────╯
                       │ Alt/Tab │ APD/SPC │  LOWER  │  SYMBOL ││   GUI   │  RAISE  │ APD/ENT │  BKSPC  │
                       ╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯  */

   [_QWERTY] = LAYOUT_cookie(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
    KC_LSHA,  KC_S,     KC_D,     KC_F,     KC_G,                          KC_H,     KC_J,     KC_K,     KC_L,    KC_RCLN,
    KC_CTLZ,  KC_X,     KC_C,     KC_V,     KC_B,     KC_ESC,    KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_CTSH,
                        KC_RATA,  APDSP,    LOWER,    SYMBOL,    KC_LGUI,  RAISE,    APDEN,    KC_BSPC
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ l o w e r                                                 │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │    !    │    @    │    #    │    $    │    %    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    ^    │    &    │    *    │    (    │    )    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │█████████│█████████│█████████│█████████│█████████├─╯                ╰─┤    -    │    =    │    {    │    }    │    \    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SCRNSHT │█████████│█████████│█████████│█████████│    ~    ││█████████│    _    │    +    │    [    │    ]    │    |    │
   ╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┴─────────╯
                       │    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │   DEL   │
                       ╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯  */

   [_LOWER] = LAYOUT_cookie(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                       KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
    _______,  _______,  _______,  _______,  _______,                       KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,
    SNAP2,    _______,  _______,  _______,  _______,  KC_GRV,   _______,   KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
                        _______,  _______,  _______,  _______,  _______,   _______,  _______,  KC_DEL
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ r a i s e                                                 │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │    1    │    2    │    3    │    4    │    5    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    6    │    7    │    8    │    9    │    0    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │█████████│█████████│█████████│█████████│█████████├─╯                ╰─┤    -    │    =    │    {    │    }    │    \    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SCRNSHT │█████████│█████████│█████████│█████████│    ~    ││█████████│    _    │    +    │    [    │    ]    │    |    │
   ╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┴─────────╯
                       │    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │   DEL   │
                       ╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯  */

   [_RAISE] = LAYOUT_cookie(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    _______,  _______,  _______,  _______,  _______,                       KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,
    SNAP2,    _______,  _______,  _______,  _______,  KC_GRV,    _______,  KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
                        _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_DEL
 ),

 /*
    ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ a d j u s t                                               │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │         │         │         │         │ OS SWAP │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │   F 9   │   F10   │   F11   │   F12   │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ├─╯                ╰─┤   F 5   │   F 6   │   F 7   │   F 8   │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││         │   F 1   │   F 2   │   F 3   │   F 4   │         │
   ╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┴─────────╯
                       │    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    │
                       ╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯  */

   [_ADJUST] = LAYOUT_cookie(
    _______,  _______,  _______,  _______,  OS_SWAP,                       KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
    _______,  _______,  _______,  _______,  _______,                       KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,
    _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,
                        _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ a r r o w / n u m p a d                                   │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │         │    7    │    8    │    9    │    -    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │  HOME   │         │   END   │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    4    │    5    │    6    │    +    ├─╯                ╰─┤         │    ←    │    ↑    │    →    │    '    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │    0    │    1    │    2    │    3    │    =    │         ││    -    │         │  PGUP   │    ↓    │  PGDN   │         │
   ╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┴─────────╯
                       │    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    │
                       ╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯  */

   [_ARRPAD] = LAYOUT_cookie(
    _______,  KC_7,     KC_8,     KC_9,     KC_MINS,                       _______,  KC_HOME,  _______,  KC_END,   _______,
    _______,  KC_4,     KC_5,     KC_6,     KC_PLUS,                       _______,  KC_LEFT,  KC_UP,    KC_RGHT,  KC_QUOT,
    KC_0,     KC_1,     KC_2,     KC_3,     KC_EQL,   _______,   KC_MINS,  _______,  KC_PGUP,  KC_DOWN,  KC_PGDN,  _______,
                        _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ s y m b o l                                               │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │         │    (    │    )    │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         ├─╯                ╰─┤         │         │    {    │    }    │    '    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││         │         │         │    [    │    ]    │         │
   ╰─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┴─────────╯
                       │    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    │
                       ╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯  */

   [_SYMBOL] = LAYOUT_cookie(
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  KC_LPRN,  KC_RPRN,  _______,
    _______,  _______,  _______,  _______,  _______,                       _______,  _______,  KC_LCBR,  KC_RCBR,  KC_QUOT,
    _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,
                        _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______
 ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

#ifdef OLED_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ d y n a m i c   m a c r o                                 │
// └───────────────────────────────────────────────────────────┘

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0;

#ifdef DYNAMIC_MACRO_ENABLE
    char dmacro_text[4][24] = { "", "RECORDING", "STOP RECORDING",  "PLAY RECORDING"};
    static uint16_t dmacro_timer;
    const char PROGMEM rec_ico[] = {0xD1, 0xE1, 0};
    const char PROGMEM stop_ico[] = {0xD3, 0xE1, 0};
    const char PROGMEM play_ico[] = {0xD2, 0xE1, 0};


    // DYNMACRO RECORD ├─────────────────────────────────────────────────────────────┐
    void dynamic_macro_record_start_user(void) {
          dmacro_num = 1;
        return;
    }

    // DYNMACRO STOP RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_record_end_user(int8_t direction) {
          dmacro_num = 2;
          dmacro_timer = timer_read();
        return;
    }

    // DYNMACRO PLAY RECORDING ├─────────────────────────────────────────────────────┐
    void dynamic_macro_play_user(int8_t direction) {
          dmacro_num = 3;
          dmacro_timer = timer_read();
        return;
    }
#endif //DYNAMIC_MACRO_ENABLE


void matrix_scan_user(void) {
  #ifdef DYNAMIC_MACRO_ENABLE
    // DynMacroTimer
    if(dmacro_num > 0){
        if (timer_elapsed(dmacro_timer) < 3000) {
            strcpy ( o_text, dmacro_text[dmacro_num] );
          }
        else {
            if (dmacro_num == 1) {
                strcpy ( o_text, dmacro_text[1] );
              }
            else {
                strcpy ( o_text, layer_state_str );
                dmacro_num = 0;
              }
          }
      }
   #endif //DYNAMIC_MACRO_ENABLE
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

// layer status ──────────────────────────────────────────┐

void render_prompt(void) {
    // bool blink = (timer_read() % 1000) < 500;
    if (layer_state_is(_ADJUST)) {
        oled_write_ln_P(PSTR(" adjust "), true);
    } else if (layer_state_is(_LOWER)) {
        oled_write_ln_P(PSTR(" lower "), true);
    } else if (layer_state_is(_RAISE)) {
        oled_write_ln_P(PSTR(" raise "), true);
    } else if (layer_state_is(_ARRPAD)) {
        oled_write_ln_P(PSTR(" arr/num "), true);
    } else if (layer_state_is(_SYMBOL)) {
        oled_write_ln_P(PSTR(" symbol "), true);
    } else {
        oled_write_ln_P(PSTR(" default "), true);
    }
};


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   r o t a t i o n                                 │
// └───────────────────────────────────────────────────────────┘

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    } else {
        return OLED_ROTATION_180;
    }
}

// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘

/* timers */
// uint32_t anim_timer = 0;
// uint32_t anim_sleep = 0;

/* status variables */
// int   current_wpm = 0;

bool oled_task_user(void) {
    static const char PROGMEM face_1[] = {0x20, 0x20, 0x20, 0x80, 0x81, 0x82, 0x83, 0x84, 0};
    static const char PROGMEM face_2[] = {0x20, 0x20, 0x20, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0};
    static const char PROGMEM face_3[] = {0x20, 0x20, 0x20, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};
    // static const char PROGMEM os_m_1[] = {0x20, 0x20, 0x20, 0x9C, 0x9D, 0};
    // static const char PROGMEM os_m_2[] = {0x20, 0x20, 0x20, 0xBC, 0xBD, 0};
    // static const char PROGMEM os_w_1[] = {0x20, 0x20, 0x20, 0x9E, 0x9F, 0};
    // static const char PROGMEM os_w_2[] = {0x20, 0x20, 0x20, 0xBE, 0xBF, 0};

    static const char PROGMEM symbol_1[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x95, 0x96, 0x97, 0x98, 0};
    static const char PROGMEM symbol_2[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xB5, 0xB6, 0xB7, 0xB8, 0};
    static const char PROGMEM symbol_3[] = {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xD5, 0xD6, 0xD7, 0xD8, 0};

    static const char PROGMEM logo_1[] = {0x20, 0x20, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0};
    static const char PROGMEM logo_2[] = {0x20, 0x20, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0};
    static const char PROGMEM logo_3[] = {0x20, 0x20, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0};

    // current_wpm   = get_current_wpm();

    // if (current_wpm > 0) {
    //     oled_on();
    //     anim_sleep = timer_read32();
    // } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
    //     oled_off();
    // }

    if (is_keyboard_master()) {

        oled_write_ln("", false);
        oled_write_ln("", false);

        oled_write_ln(face_1, false);
        oled_write_ln(face_2, false);
        oled_write_ln(face_3, false);

        oled_write_ln("", false);
        oled_write_ln("", false);

        oled_write_ln_P(PSTR("-layer"), false);
        oled_write_ln("", false);
        render_prompt();

        oled_write_ln("", false);
        oled_write_ln("", false);

        oled_write_ln_P(PSTR("-mode"), false);
        oled_write_ln("", false);
        // if (keymap_config.swap_lctl_lgui) {
        //     oled_write_ln(os_m_1, false); // ──── MAC
        //     oled_write_ln(os_m_2, false);
        // } else {
        //     oled_write_ln(os_w_1, false); // ──── WIN
        //     oled_write_ln(os_w_2, false);
        // }
        if (keymap_config.swap_lctl_lgui) {
            oled_write_ln_P(PSTR(" mac "), true); // ──── MAC
            oled_write_ln_P(PSTR(" win "), false);
        } else {
            oled_write_ln_P(PSTR(" mac "), false);
            oled_write_ln_P(PSTR(" win "), true); // ──── WIN
        }
    } else {
        oled_write_ln(symbol_1, false);
        oled_write_ln(symbol_2, false);
        oled_write_ln(symbol_3, false);
        oled_write_ln("", false);
        oled_write_ln(logo_1, false);
        oled_write_ln(logo_2, false);
        oled_write_ln(logo_3, false);
    }
    return false;
}
#endif // OLED_ENABLE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_T:
            return TAPPING_TERM - 150;
        case SHT_N:
            return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                }
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }

// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘

        // case LOWER:
        //     if (record->event.pressed) {
        //         layer_on(_LOWER);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //         #ifdef HAPTIC_ENABLE
        //           DRV_pulse(sharp_click);
        //         #endif // HAPTIC_ENABLE
        //     } else {
        //         layer_off(_LOWER);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     }
        //     return false;
        // case RAISE:
        //     if (record->event.pressed) {
        //         layer_on(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //         #ifdef HAPTIC_ENABLE
        //           DRV_pulse(sharp_click);
        //         #endif // HAPTIC_ENABLE
        //     } else {
        //         layer_off(_RAISE);
        //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
        //     }
        //     return false;
        // case ADJUST:
        //     if (record->event.pressed) {
        //         layer_on(_ADJUST);
        //         #ifdef HAPTIC_ENABLE
        //           DRV_pulse(buzz);
        //         #endif // HAPTIC_ENABLE
        //     } else {
        //         layer_off(_ADJUST);
        //     }
        //     return false;
        // case SYMBOL:
        //     if (record->event.pressed) {
        //         layer_on(_SYMBOL);
        //         #ifdef HAPTIC_ENABLE
        //           DRV_pulse(transition_hum);
        //         #endif // HAPTIC_ENABLE
        //     } else {
        //         layer_off(_SYMBOL);
        //     }
        //     return false;

// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘

        case MAKE_H:
          if (record->event.pressed) {
            #ifdef KEYBOARD_cookie_mx_kb2040
              SEND_STRING ("qmk compile -kb keebbear/cookie_mx/kb2040 -km default");
            #else
              SEND_STRING ("qmk compile -kb keebbear/cookie_mx -km default");
            #endif
            tap_code(KC_ENTER);
          }
          break;

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
