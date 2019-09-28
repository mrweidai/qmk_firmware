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
    MACRO_EMOJI_SHRUG,
    MACRO_EMOJI_PASS
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
                                        SEND_STRING("'\\_(``/)_/'");
                                        return false;
                                    }
                                }

        case MACRO_EMOJI_BILL: {
                                   if (record->event.pressed) {
                                       SEND_STRING("[$(100)$]");
                                       return false;
                                   }
                               }
        case MACRO_EMOJI_PASS: {
                                   if (record->event.pressed) {
                                       SEND_STRING("testTEST1234");
                                       return false;
                                   }
                               }
    }
    return MACRO_NONE;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_split_bs_rshift(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RALT, MO(1), MO(2), KC_RCTL),
    [1] = LAYOUT_60_ansi_split_bs_rshift(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL, KC_TRNS, KC_PGUP, KC_UP, KC_PGDN, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC__VOLDOWN, KC__VOLUP, KC__MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_60_ansi_split_bs_rshift(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_EMOJI_SHRUG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_EMOJI_BILL, KC_TRNS, MACRO_EMOJI_PASS, KC_ACL2, KC_ACL1, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT_60_ansi_split_bs_rshift(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};
