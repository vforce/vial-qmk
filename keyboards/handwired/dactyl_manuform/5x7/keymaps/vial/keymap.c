#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _NUMPAD 2

// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LCTL,   KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_G,
        KC_LEFT_SHIFT,      KC_Z,    KC_X,    KC_C,   KC_V,   KC_B, KC_GRAVE,
                                     KC_CAPS, KC_RIGHT_ALT, KC_RWIN, KC_RIGHT_ALT,
                                     KC_PAGE_DOWN, TT(_FN), KC_END, KC_HOME,
        // right hand
                                                KC_BACKSPACE, KC_EQL,KC_MINS,KC_0,KC_9,KC_8,KC_7,
                                                  KC_BSLS,KC_P,KC_O,KC_I,KC_U,KC_Y,KC_RBRC,
                                                  KC_QUOT,KC_SCLN,KC_L,KC_K,KC_J,KC_H,KC_GRAVE,
                                             KC_RIGHT_SHIFT,KC_SLSH,KC_DOT,KC_COMM,KC_M,KC_N,KC_N,
                                            KC_RIGHT, KC_SPACE,    KC_LEFT,  KC_RGHT,
             KC_DOWN, KC_UP,
             KC_LEFT, KC_ENTER
    ),

    [_FN] = LAYOUT_5x7(
        // left hand
        _______,   KC_F1,     KC_F2,      KC_F3,    KC_F4,     KC_F5,    KC_F6,
        _______,   _______,   _______,    KC_UP,    _______,   _______,  _______,
        _______,   _______,   KC_LEFT,    KC_DOWN,  KC_RGHT,   _______,  QK_BOOT,
        _______,   _______,   _______,   _______,   _______,   _______, _______,
                                KC_MSTP,   KC_MPLY,   KC_MPRV,   KC_MNXT,  
                                        _______, _______,
                                        _______, _______,
        // right hand
                KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    _______,
                _______,   _______,   _______,   KC_UP,   _______,   _______,   _______,
                _______,   _______,   KC_RIGHT,   KC_DOWN,   KC_LEFT,   _______,   _______,
                _______,   _______,   _______,   _______,   _______,   _______,   _______,
                                                _______,  _______, KC_BACKSPACE,   _______, 
                _______, _______,
                _______, _______
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } 
    return false;
}