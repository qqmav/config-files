/* Copyright 2021 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_MUTE, KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_PGUP,          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_PGDN,          KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_VOLU,          KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
    KC_VOLD,          KC_LCTL, KC_LGUI, KC_LALT, KC_LGUI, MO(1),   KC_SPC,      KC_ENT,  MO(2),   KC_RALT, KC_RGUI, KC_MENU, KC_RCTL
  ),
  [1] = LAYOUT(
    _______, _______, RGB_MOD, RGB_HUD, RGB_HUI, _______, _______, KC_LABK,     KC_RABK, KC_7,    KC_8,    KC_9,    _______, _______, _______, KC_DEL,
    _______,          _______, RGB_SAD, RGB_SAI, _______, _______, KC_LPRN,     KC_RPRN, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______,
    _______,          _______, RGB_VAD, RGB_VAI, _______, _______, KC_LBRC,     KC_RBRC, KC_1,    KC_2,    KC_3,    KC_MINS, _______,          _______,
    _______,          _______, _______, _______, _______, _______, KC_LCBR,     KC_RCBR, _______, KC_0,    KC_PDOT, KC_EQL,  _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT(
    _______, _______, KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_DEL,
    _______,          _______, KC_VOLD, KC_MPLY, KC_VOLU, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, KC_MPRV, KC_MSTP, KC_MNXT, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  ),
};

bool is_alt_tabbing = false;
uint16_t alt_tab_timer = 0;
const uint16_t alt_tab_timeout = 1000;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (IS_LAYER_ON(2)) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(S(C(KC_TAB)));
    }
  } else {
    if (!is_alt_tabbing) {
      is_alt_tabbing = true;
      register_code(KC_LALT);
    }
    alt_tab_timer = timer_read();
    if (clockwise) {
        tap_code(KC_TAB);
    } else {
        tap_code16(S(KC_TAB));
    }
  }

  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tabbing) {
    if (timer_elapsed(alt_tab_timer) > alt_tab_timeout) {
      unregister_code(KC_LALT);
      is_alt_tabbing = false;
    }
  }
}
