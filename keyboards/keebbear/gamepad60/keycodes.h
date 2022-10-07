#pragma once

enum layer_names {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOVE
};

#define SFT_EQ MT(MOD_LSFT, KC_EQL)
#define SFT_QT MT(MOD_RSFT, KC_QUOT)

#define SFT_A MT(MOD_LSFT, KC_A)
#define CTL_Z MT(MOD_LCTL, KC_Z)

#define SFT_SCLN MT(MOD_RSFT, KC_SCLN)
#define CTL_SLSH MT(MOD_RCTL, KC_SLSH)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOVE MO(_MOVE)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define LOW_ENT LT(_LOWER, KC_ENT)

#define RAI_SPC LT(_RAISE, KC_SPC)
#define RAI_ENT LT(_RAISE, KC_ENT)

#define LOW_BSP LT(_LOWER, KC_BSPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)

#define LOW_DEL LT(_LOWER, KC_DEL)

#define RAI_EQ LT(_RAISE, KC_EQL)
#define ADJ_BSLS LT(_ADJUST, KC_BSLS)

#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT)

#define TAB_MOVE LT(_MOVE, KC_TAB)
