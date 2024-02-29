// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_TX_PIN GP0

#define COMBO_COUNT 26

//#define TAPPING_TERM 170
#define TAPPING_TERM 170

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_DISABLE_KEYCODES // disable keycodes for RGB Light controls, only status LED is supported
#    define PICA40_RGBLIGHT_TIMEOUT 5 // turn RGB off after N minutes
#endif

#ifdef ENCODER_ENABLE
#   define SPLIT_TRANSACTION_IDS_KB ENCODER_SYNC
#endif
