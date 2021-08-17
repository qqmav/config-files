#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
};

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_BSLS, KC_GRV,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_RALT, KC_DOWN, KC_LBRC, KC_RBRC
  ),

  [_RAISE] = LAYOUT_ortho_4x12(
 KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
 _______, KC_VOLD, KC_MPLY, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
 _______, KC_MPRV, KC_MSTP, KC_MNXT, _______, _______, _______, _______, _______, _______, _______, _______,
 RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_ortho_4x12(
 KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    _______, KC_DEL,
 _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
 _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_EQL,  _______,
 _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, _______, KC_0,    KC_PDOT, _______, _______
  )

};
