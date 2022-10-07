#include QMK_KEYBOARD_H
#include "keycodes.h"

#ifdef JOYSTICK_ENABLE
#   include "joystick.h"
#   include "analog.h"
#endif

/* TapDance Aliases */
#define TD_LBRK TD(TD_BRACKETS_LEFT)
#define TD_RBRK TD(TD_BRACKETS_RIGHT)
#define TD_PLEQ TD(TD_PLUS_EQUALS)
#define TD_SCOL TD(TD_SEMICOLON_COLON)
#define TD_SLQU TD(TD_SLASH_QUESTION)
#define TD_SQDQ TD(TD_QUOTE_DOUBLEQUOTE)
#define TD_USMI TD(TD_UNDERSCORE_MINUS)

/* Sentinel value for invalid tap dance exit */
#define TAP_DANCE_NO_MATCH 64

enum tapdance_keycodes {
    TD_BRACKETS_LEFT,
    TD_BRACKETS_RIGHT,
    TD_CONTROL_ESCAPE,
    TD_PLUS_EQUALS,
    TD_QUOTE_DOUBLEQUOTE,
    TD_SEMICOLON_COLON,
    TD_SLASH_QUESTION,
    TD_UNDERSCORE_MINUS,
};

typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_HOLD,
} t_tap_state;

typedef struct {
    t_tap_state left_brackets;
    t_tap_state right_brackets;
} t_tap;

t_tap_state get_tapdance_state(qk_tap_dance_state_t *state);

void td_brackets_left_finished(qk_tap_dance_state_t *state, void *user_data);
void td_brackets_left_reset(qk_tap_dance_state_t *state, void *user_data);
void td_brackets_right_finished(qk_tap_dance_state_t *state, void *user_data);
void td_brackets_right_reset(qk_tap_dance_state_t *state, void *user_data);

/* Tap Dance Definitions */
qk_tap_dance_action_t tap_dance_actions[] = {
    /* Tap once for left parenthesis, twice for left bracket, thrice for left brace */
    [TD_BRACKETS_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_brackets_left_finished, td_brackets_left_reset),
    /* Tap once for right parenthesis, twice for right bracket, thrice for right brace */
    [TD_BRACKETS_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_brackets_right_finished, td_brackets_right_reset),
    /* Tap once for plus, twice for equals */
    [TD_PLUS_EQUALS] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_EQUAL),
    /* Tap once for single quote, twice for double quote */
    [TD_QUOTE_DOUBLEQUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
    /* Tap once for semicolon, twice for colon */
    [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_COLON),
    /* Tap once for slash, twice for question mark */
    [TD_SLASH_QUESTION] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_QUESTION),
    /* Tap once for underscore, twice for minus */
    [TD_UNDERSCORE_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_UNDERSCORE, KC_MINUS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_gicho56(
              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    TD_SCOL, TD_SQDQ,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_SLQU, KC_RSFT,
                                KC_LALT, SP_LWER, RAISE,   ARROW,    ARROW,   LOWER,   ET_RAIS, KC_LGUI
    ),

    [_MAC] = LAYOUT_gicho56(
              _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
     KC_LGUI, _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,   _______, _______, _______, KC_LCTL
    ),

    [_COLEMAK_DH] = LAYOUT_gicho56(
              _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,
     _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
     _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
     _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,  _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH,_______,
                                _______, _______, _______, _______,  _______, _______, _______, _______
    ),

    [_GAMEPAD] = LAYOUT_gicho56(
            _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______,
     KC_I,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                        _______, _______, _______, _______, _______, _______,
     KC_M,  KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,                        _______, _______, _______, _______, _______, _______,
     KC_P, KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    _______,   _______, _______, _______, _______, _______, _______, _______,
                                KC_LALT, KC_SPC,  _______, _______,   _______, _______, _______,_______
    ),

    [_ARROW] = LAYOUT_gicho56(
              _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,
     _______, _______, _______, KC_UP,   _______, _______,                    _______, _______, KC_UP,   _______, _______, _______,
     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,
                                _______, _______, _______, _______,  _______, _______, _______, _______

    ),

    [_LOWER] = LAYOUT_gicho56(
              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       _______, _______, _______, _______, _______,
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     _______, _______, KC_LEFT, KC_UP,   KC_RGHT, _______,                    _______, KC_UNDS, KC_PLUS, TD_LBRK, TD_RBRK, KC_PIPE,
     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_ESC,   _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                                _______, _______, _______, _______,  _______, _______, _______, _______

    ),

    [_RAISE] = LAYOUT_gicho56(
              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
     KC_F11,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
     _______, _______, KC_LEFT, KC_UP,   KC_RGHT, _______,                    _______, KC_MINS, KC_EQL,  TD_LBRK, TD_RBRK, KC_BSLS,
     _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_ESC,   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                                _______, _______, _______, _______,  _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_gicho56(
              _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,
     VRSN,    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,                    _______, _______, _______, _______, _______, EEP_RST,
     KEYLOCK, MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM,                    CG_SWAP, TG_QWER, TG_CODH, TG_GAME, TG_MAC,  _______,
     _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, KC_RGB_T,_______,  _______, MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
                                _______, _______, _______, _______,  _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define BASE_ENCODERS { { KC_VOLD, KC_VOLU }, { KC_WH_D, KC_WH_U } }

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY]          = BASE_ENCODERS,
    [_MAC]             = BASE_ENCODERS,
    [_COLEMAK_DH]      = BASE_ENCODERS,
    [_GAMEPAD]         = { { _______, _______ }, { _______, _______ } },
    [_ARROW]         = { { _______, _______ }, { _______, _______ } },
    [_RAISE]           = { { _______, _______ }, { KC_PGDN, KC_PGUP } },
    [_LOWER]           = { { _______, _______ }, { KC_PGDN, KC_PGUP } },
    [_ADJUST]          = { { RGB_MOD, RGB_RMOD}, { RGB_HUD, RGB_HUI } },
};
// clang-format on
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
#    ifdef SWAP_HANDS_ENABLE
    if (swap_hands) {
        index ^= 1;
    }
#    endif
    if (index == 0) {
        tap_code_delay(clockwise ? KC_VOLD : KC_VOLU, 5);
    } else if (index == 1) {
        tap_code_delay(clockwise ? KC_WH_D : KC_WH_U, 5);
    }
    return false;
}
#endif

#ifdef JOYSTICK_ENABLE

// Joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(B1, 268, 514, 813),
    [1] = JOYSTICK_AXIS_IN(B0, 865, 519, 260)
};

#endif

bool dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if(active) //ENC0 pressed
		{
			tap_code(KC_MUTE);
		}  else {

      }
      break;
    case 1:
      if(active) //ENC1 pressed
		{
			tap_code(KC_MUTE);
		}  else {

      }
      break;
   }
   return true;
}


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_90;
    }
}

static void render_logo(void) {
    static const char PROGMEM gicho56_logo1[] = {0x85, 0x86, 0x87, 0x88, 0x89, 0};
    static const char PROGMEM gicho56_logo2[] = {0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0};
    static const char PROGMEM gicho56_logo3[] = {0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0};

    oled_set_cursor(3, 1);
    oled_write_P(gicho56_logo1, false);
    oled_write_P(PSTR("\n"), false);
    oled_set_cursor(3, 2);
    oled_write_P(gicho56_logo2, false);
    oled_write_P(PSTR("\n"), false);
    oled_set_cursor(3, 3);
    oled_write_P(gicho56_logo3, false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("  Gicho56"), false);
}

static void render_keebbear(void) {
    static const char PROGMEM keebbear_logo1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0};
    static const char PROGMEM keebbear_logo2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0};
    static const char PROGMEM keebbear_logo3[] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0};

    oled_set_cursor(3, 8);
    oled_write_P(keebbear_logo1, false);
    oled_write_P(PSTR("\n"), false);
    oled_set_cursor(3, 9);
    oled_write_P(keebbear_logo2, false);
    oled_write_P(PSTR("\n"), false);
    oled_set_cursor(3, 10);
    oled_write_P(keebbear_logo3, false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" Designed\n"), false);
    oled_write_P(PSTR(" by\n"), false);
    oled_write_P(PSTR(" KEEBBEAR\n"), false);
}

void render_status(void) {

    static const char PROGMEM colemak_logo1[] = {0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0};
    static const char PROGMEM colemak_logo2[] = {0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0};
    static const char PROGMEM colemak_logo3[] = {0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0};

    static const char PROGMEM game_logo1[] = {0x8F, 0x90, 0x91, 0x92, 0x93, 0};
    static const char PROGMEM game_logo2[] = {0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0};
    static const char PROGMEM game_logo3[] = {0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0};

    static const char PROGMEM qwerty_logo1[] = {0x94, 0x95, 0x96, 0x97, 0x98, 0};
    static const char PROGMEM qwerty_logo2[] = {0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0};
    static const char PROGMEM qwerty_logo3[] = {0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0};

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("   "), false);
            oled_write_P(qwerty_logo1, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(qwerty_logo2, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(qwerty_logo3, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("  QWERTY\n"), false);
            oled_set_cursor(1, 11);
            break;
        case _MAC:
            oled_write_P(PSTR("   "), false);
            oled_write_P(qwerty_logo1, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(qwerty_logo2, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(qwerty_logo3, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR(" QWERTY_M\n"), false);
            oled_set_cursor(1, 11);
            break;
        case _COLEMAK_DH:
            oled_write_P(PSTR("   "), false);
            oled_write_P(colemak_logo1, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(colemak_logo2, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(colemak_logo3, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("COLEMAK_DH\n"), false);
            oled_set_cursor(1, 11);
            break;
        case _GAMEPAD:
            oled_write_P(PSTR("   "), false);
            oled_write_P(game_logo1, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(game_logo2, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("   "), false);
            oled_write_P(game_logo3, false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("\n"), false);
            oled_write_P(PSTR("  GAMEPAD\n"), false);
            oled_set_cursor(1, 11);
            break;
        default:
            oled_set_cursor(1, 11);
    }
}

void render_prompt(void) {
    bool blink = (timer_read() % 1000) < 500;
    if (layer_state_is(_ADJUST)) {
        oled_write_ln_P(blink ? PSTR("  > aj_") : PSTR("  > aj "), false);
    } else if (layer_state_is(_LOWER)) {
        oled_write_ln_P(blink ? PSTR("  > lo_") : PSTR("  > lo "), false);
    } else if (layer_state_is(_RAISE)) {
        oled_write_ln_P(blink ? PSTR("  > hi_") : PSTR("  > hi "), false);
    } else if (layer_state_is(_ARROW)) {
        oled_write_ln_P(blink ? PSTR("  > aw_") : PSTR("  > aw "), false);
    } else {
        oled_write_ln_P(blink ? PSTR("  > _  ") : PSTR("  >    "), false);
    }
};

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* status variables */
int   current_wpm = 0;

bool oled_task_user(void) {

    current_wpm   = get_current_wpm();

    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }

    if (is_keyboard_master()) {

        oled_write_ln("", false);
        oled_write_ln("", false);

        render_status();

        render_prompt();
    } else {
        render_logo();
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("\n"), false);
        render_keebbear();
    }
    return false;
}
#endif

/* Global TapDance State */
static t_tap qk_tap_state = {
    .left_brackets  = 0,
    .right_brackets = 0,
};

t_tap_state get_tapdance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE_TAP;
        } else {
            return DOUBLE_HOLD;
        }
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) {
            return TRIPLE_TAP;
        } else {
            return TRIPLE_HOLD;
        }
    } else
        return TAP_DANCE_NO_MATCH;
}

void td_brackets_left_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_state.left_brackets = get_tapdance_state(state);
    switch (qk_tap_state.left_brackets) {
        case SINGLE_TAP:
            register_code16(KC_LEFT_PAREN);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LEFT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            register_code(KC_LBRACKET);
            break;
        default:
            break;
    }
}

void td_brackets_left_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (qk_tap_state.left_brackets) {
        case SINGLE_TAP:
            unregister_code16(KC_LEFT_PAREN);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LEFT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_LBRACKET);
            break;
        default:
            break;
    }
    qk_tap_state.left_brackets = 0;
}

void td_brackets_right_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_state.right_brackets = get_tapdance_state(state);
    switch (qk_tap_state.right_brackets) {
        case SINGLE_TAP:
            register_code16(KC_RIGHT_PAREN);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RIGHT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            register_code(KC_RBRACKET);
            break;
        default:
            break;
    }
}

void td_brackets_right_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (qk_tap_state.right_brackets) {
        case SINGLE_TAP:
            unregister_code16(KC_RIGHT_PAREN);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RIGHT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            unregister_code(KC_RBRACKET);
            break;
        default:
            break;
    }
    qk_tap_state.right_brackets = 0;
}
