#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Macro Declarations
enum {
    MACRO_EMOJI_BILL = 0,
    MACRO_EMOJI_CHECK,
    MACRO_EMOJI_DAY,
    MACRO_EMOJI_FORBIDDEN,
    MACRO_EMOJI_HEART,
    MACRO_EMOJI_KEYBOARD,
    MACRO_EMOJI_NIGHT,
    MACRO_TEXT_tT1,
    MACRO_EMOJI_ROUND_SHRUG,
    MACRO_EMOJI_SHRUG,
    MACRO_EMOJI_WAIT,
    MACRO_EMOJI_XOSS
    // ..., the rest of your macros
};

// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    // for basic strings
    // _bcd______kl_n___rs____x__
    case MACRO_EMOJI_SHRUG: {
        if (record->event.pressed) {
            //SEND_STRING("¯\\_(ツ)_/¯"); // REPLACE with what you want your macro to be
            SEND_STRING("'\\_(``/)_/'"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_BILL: {
        if (record->event.pressed) {
            SEND_STRING("[$(100)$]"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_CHECK: {
        if (record->event.pressed) {
            SEND_STRING("✓"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_XOSS: {
        if (record->event.pressed) {
            SEND_STRING("✗"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_KEYBOARD: {
        if (record->event.pressed) {
            SEND_STRING("⌨"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_DAY: {
        if (record->event.pressed) {
            SEND_STRING("☀"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_NIGHT: {
        if (record->event.pressed) {
            SEND_STRING("☾"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_ROUND_SHRUG: {
        if (record->event.pressed) {
            SEND_STRING("㋡"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_HEART: {
        if (record->event.pressed) {
            SEND_STRING("♡ "); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_EMOJI_FORBIDDEN: {
        if (record->event.pressed) {
            SEND_STRING("⊘"); // REPLACE with what you want your macro to be
            return false;
        }
    }
    case MACRO_TEXT_tT1: {
        if (record->event.pressed) {
            SEND_STRING("testTEST1234"); // REPLACE with what you want your macro to be
            return false;
        }
    }
  }
  return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    MO(_FN1),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  MO(_FN2),KC_BSLS, _______,  MO(_FN3),KC_RCTL
  ),

  [_FN1] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TAB,  KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, _______, _______, _______, _______, KC_9,    KC_0,    KC_MINS, KC_EQL, KC_DEL, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______,\
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_GRV,  _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN1, _______, KC_GRV, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT, _______, \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  ),

  [_FN3] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, M(MACRO_TEXT_tT1), _______, _______, _______, \
    _______, _______, M(MACRO_EMOJI_SHRUG), M(MACRO_EMOJI_DAY), M(MACRO_EMOJI_FORBIDDEN), _______, _______, M(MACRO_EMOJI_HEART), _______, M(MACRO_EMOJI_KEYBOARD), _______, _______, _______,\
    _______, _______, M(MACRO_EMOJI_XOSS), M(MACRO_EMOJI_CHECK), _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  )
};
