#pragma once
#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// readability
#define ___ KC_NO

#define LAYOUT_cookie(                                                 \
    L00, L01, L02, L03, L04,                R01, R02, R03, R04, R05,       \
    L10, L11, L12, L13, L14,                R11, R12, R13, R14, R15,  \
    L20, L21, L22, L23, L24, L25,      R20, R21, R22, R23, R24, R25,  \
              L32, L33, L34, L35,      R30, R31, R32, R33             \
    )                                               \
    {                                               \
        { L00,   L01,   L02,   L03,   L04,   ___ }, \
        { L10,   L11,   L12,   L13,   L14,   ___ }, \
        { L20,   L21,   L22,   L23,   L24,   L25 }, \
        { ___,   ___,   L32,   L33,   L34,   L35 }, \
        { R05,   R04,   R03,   R02,   R01,   ___ }, \
        { R15,   R14,   R13,   R12,   R11,   ___ }, \
        { R25,   R24,   R23,   R22,   R21,   R20 }, \
        { ___,   ___,   R33,   R32,   R31,   R30 }, \
    }

// #define LAYOUT LAYOUT_cookie

#ifdef POINTING_DEVICE_ENABLE
#    ifndef NO_FRAME_KEYCODES
enum frame_keycodes {
#        ifdef VIA_ENABLE
    POINTER_DEFAULT_DPI_FORWARD = USER00,
#        else
    POINTER_DEFAULT_DPI_FORWARD = SAFE_RANGE,
#        endif // VIA_ENABLE
    POINTER_DEFAULT_DPI_REVERSE,
    POINTER_SNIPING_DPI_FORWARD,
    POINTER_SNIPING_DPI_REVERSE,
    SNIPING_MODE,
    SNIPING_MODE_TOGGLE,
    DRAGSCROLL_MODE,
    DRAGSCROLL_MODE_TOGGLE,
    FRAME_SAFE_RANGE,
};

#        define DPI_MOD POINTER_DEFAULT_DPI_FORWARD
#        define DPI_RMOD POINTER_DEFAULT_DPI_REVERSE
#        define S_D_MOD POINTER_SNIPING_DPI_FORWARD
#        define S_D_RMOD POINTER_SNIPING_DPI_REVERSE
#        define SNIPING SNIPING_MODE
#        define SNP_TOG SNIPING_MODE_TOGGLE
#        define DRGSCRL DRAGSCROLL_MODE
#        define DRG_TOG DRAGSCROLL_MODE_TOGGLE
#    endif // !NO_FRAME_KEYCODES

/** \brief Return the current DPI value for the pointer's default mode. */
uint16_t frame_get_pointer_default_dpi(void);

/**
 * \brief Update the pointer's default DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to FRAME_DEFAULT_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void frame_cycle_pointer_default_dpi(bool forward);

/**
 * \brief Same as `frame_cycle_pointer_default_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void frame_cycle_pointer_default_dpi_noeeprom(bool forward);

/** \brief Return the current DPI value for the pointer's sniper-mode. */
uint16_t frame_get_pointer_sniping_dpi(void);

/**
 * \brief Update the pointer's sniper-mode DPI to the next or previous step.
 *
 * Increases the DPI value if `forward` is `true`, decreases it otherwise.
 * The increment/decrement steps are equal to FRAME_SNIPING_DPI_CONFIG_STEP.
 *
 * The new value is persisted in EEPROM.
 */
void frame_cycle_pointer_sniping_dpi(bool forward);

/**
 * \brief Same as `frame_cycle_pointer_sniping_dpi`, but do not write to
 * EEPROM.
 *
 * This means that reseting the board will revert the value to the last
 * persisted one.
 */
void frame_cycle_pointer_sniping_dpi_noeeprom(bool forward);

/** \brief Whether sniper-mode is enabled. */
bool frame_get_pointer_sniping_enabled(void);

/**
 * \brief Enable/disable sniper mode.
 *
 * When sniper mode is enabled the dpi is reduced to slow down the pointer for
 * more accurate movements.
 */
void frame_set_pointer_sniping_enabled(bool enable);

/** \brief Whether drag-scroll is enabled. */
bool frame_get_pointer_dragscroll_enabled(void);

/**
 * \brief Enable/disable drag-scroll mode.
 *
 * When drag-scroll mode is enabled, horizontal and vertical pointer movements
 * are translated into horizontal and vertical scroll movements.
 */
void frame_set_pointer_dragscroll_enabled(bool enable);
#endif // POINTING_DEVICE_ENABLE
