#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "display.h"

enum bearblitz38_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    GAME,
    LOWER,
    RAISE,
    ARRPAD,
    ADJUST,
    OS_SWAP,
    SNAP1,
    SNAP2
};

// enum bearblitz38_layers {
//     /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
//     _DEV = 0,
//     _DESIGN,
//     _GAME,
//     _LOWER,
//     _RAISE,
//     _ARRPAD,
//     _ADJUST
// };

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

#define KC_LSHA LSFT_T(KC_A)
#define KC_CTLZ LCTL_T(KC_Z)
#define KC_RCLN RSFT_T(KC_SCLN)
#define KC_CTSH RCTL_T(KC_SLSH)
#define KC_RSHO RSFT_T(KC_O)
#define KC_GUTA GUI_T(KC_TAB)
#define KC_GUBS GUI_T(KC_BSPC)
#define KC_GUDE GUI_T(KC_DEL)
#define KC_RABS RALT_T(KC_BSPC)
#define KC_RATA RALT_T(KC_TAB)

#define LOWER LT(_LOWER, KC_SPC)
#define RAISE LT(_RAISE, KC_ENT)
#define APDEN LT(_ARRPAD, KC_ENT)
#define APDSP LT(_ARRPAD, KC_SPC)
#define ADJUST LT(_ADJUST, KC_LNG1)

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

// clang-format off
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
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │  CTRL/Z │    X    │    C    │    V    │    B    │                    │    N    │    M    │    ,    │    .    │  CTRL// │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││ Alt/Tab │  LOWER  │ APD/SPC │ ADJUST  ││   GUI   │ APD/ENT │  RAISE  │  BKSPC  ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_QWERTY] = LAYOUT_default(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
    KC_LSHA,  KC_S,     KC_D,     KC_F,     KC_G,                          KC_H,     KC_J,     KC_K,     KC_L,    KC_RCLN,
    KC_CTLZ,  KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_CTSH,
              _______,  KC_RATA,  LOWER,    APDSP,    ADJUST,    KC_LGUI,  APDEN,    RAISE,    KC_BSPC,  KC_MUTE
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ c o l e m a k - d h                                       │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │    Q    │    W    │    F    │    P    │    B    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    J    │    L    │    U    │    Y    │    ;    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SHIFT/A │    R    │    S    │    T    │    G    ├─╯                ╰─┤    M    │    N    │    E    │    I    │ SHIFT/O │
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │  CTRL/Z │    X    │    C    │    D    │    V    │                    │    K    │    H    │    ,    │    .    │  CTRL// │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││ Alt/Tab │  LOWER  │ APD/SPC │ ADJUST  ││   GUI   │ APD/ENT │  RAISE  │  BKSPC  ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_COLEMAK] = LAYOUT_default(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
    KC_LSHA,  KC_S,     KC_D,     KC_F,     KC_G,                          KC_H,     KC_J,     KC_K,     KC_L,    KC_RSHO,
    KC_CTLZ,  KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_CTSH,
              _______,  KC_RATA,  LOWER,    APDSP,    ADJUST,    KC_LGUI,  APDEN,    RAISE,    KC_BSPC,  KC_MUTE
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ g a m e                                                   │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │ SHIFT/; │
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │    Z    │    X    │    C    │    V    │    B    │                    │    N    │    M    │    ,    │    .    │  CTRL// │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││ Alt/Tab │  LOWER  │  SHIFT  │   CTRL  ││   GUI   │ APD/ENT │  RAISE  │  BKSPC  ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_GAME] = LAYOUT_default(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                          KC_H,     KC_J,     KC_K,     KC_L,    KC_RCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_CTSH,
              _______,  KC_RATA,  LOWER,    KC_LSFT,  KC_LCTL,   KC_LGUI,  APDEN,    RAISE,    KC_BSPC,  KC_MUTE
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
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SCRNSHT │█████████│█████████│█████████│█████████│                    │    _    │    +    │    [    │    ]    │    |    │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_LOWER] = LAYOUT_default(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                       KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
    _______,  _______,  _______,  _______,  _______,                       KC_MINS,  KC_EQL,   KC_LCBR,  KC_RCBR,  KC_BSLS,
    SNAP2,    _______,  _______,  _______,  KC_GRV,                        KC_UNDS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  KC_PIPE,
              _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_DEL,  KC_MUTE
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
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │ SCRNSHT │█████████│█████████│█████████│█████████│                    │    _    │    +    │    [    │    ]    │    |    │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_RAISE] = LAYOUT_default(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                          KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    _______,  _______,  _______,  _______,  _______,                       _______,  KC_LEFT,  KC_UP,    KC_RGHT,  KC_QUOT,
    SNAP1,    _______,  _______,  _______,  KC_GRV,                        _______,  KC_PGUP,  KC_DOWN,  KC_PGDN,  _______,
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  KC_DEL,  KC_MUTE
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ a r r o w / n u m p a d                                   │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │         │    7    │    8    │    9    │    -    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │  HOME   │    ↑    │   END   │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    4    │    5    │    6    │    +    ├─╯                ╰─┤         │    ←    │    ↓    │    →    │    '    │
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    1    │    2    │    3    │    =    │                    │         │  PGUP   │         │  PGDN   │         │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_ARRPAD] = LAYOUT_default(
    KC_ESC,   KC_7,     KC_8,     KC_9,     KC_MINS,                       _______,  KC_HOME,  _______,  KC_END,   _______,
    _______,  KC_4,     KC_5,     KC_6,     KC_PLUS,                       _______,  KC_LEFT,  KC_UP,    KC_RGHT,  KC_QUOT,
    KC_0,     KC_1,     KC_2,     KC_3,     KC_EQL,                        _______,  KC_PGUP,  KC_DOWN,  KC_PGDN,  _______,
              _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  KC_MUTE
    ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ a d j u s t                                               │
   └───────────────────────────────────────────────────────────┘
   ╭─────────┬─────────┬─────────┬─────────┬─────────╮                    ╭─────────┬─────────┬─────────┬─────────┬─────────╮
   │ RGB TOG │         │ QWERTY  │ COLEMAK │  GAME   │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │   F 9   │   F10   │   F11   │   F12   │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┤
   │RGB MOD ↑│RGB VAL ↑│RGB HUE ↑│RGB SAT ↑│RGB SPD ↑├─╯                ╰─┤   F 5   │   F 6   │   F 7   │   F 8   │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────│                    │─────────┼─────────┼─────────┼─────────┼─────────┤
   │RGB MOD ↓│RGB VAL ↓│RGB HUE ↓│RGB SAT ↓│RGB SPD ↓│                    │   F 1   │   F 2   │   F 3   │   F 4   │         │
   ╰─────────╭────────╮┼─────────┼─────────┼─────────┼─────────╮╭─────────┼─────────┼─────────┼─────────┼╭────────╮─────────╯
             │        ││    ▼    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │    ▼    ││  MUTE  │
             ╰────────╯╰─────────┴─────────┴─────────┴─────────╯╰─────────┴─────────┴─────────┴─────────╯╰────────╯  */
    [_ADJUST] = LAYOUT_default(
    RGB_TOG,  _______,  QWERTY,   COLEMAK,  GAME,                           KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
    RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,                        KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,
    RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,                        KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,
              _______,   _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  KC_MUTE
    ),
};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    switch (index) {
        case 0: // Left-half encoder, mouse scroll.
            tap_code(clockwise ? KC_MS_WH_UP : KC_MS_WH_DOWN);
            break;
        case 1: // Right-half encoder, volume control.
            tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
            break;
    }
    return true;
}
#endif // ENCODER_ENABLE

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
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘
         case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;

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
