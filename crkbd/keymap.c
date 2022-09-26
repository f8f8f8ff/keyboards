/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define KY_TABG LGUI_T(KC_TAB)
#define KY_ESCC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3(
	KY_TABG,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KY_ESCC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LEAD,
                          KC_LALT, MO(_LOWER), KC_SPC,                     KC_ENT, MO(_RAISE), KC_DEL
),
[_LOWER] = LAYOUT_split_3x6_3(
	KC_DEL,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    LCTL_T(KC_BSPC),  KC_4,    KC_5,    KC_6,    KC_MINS, KC_PLUS,         KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_GRV,
    _______,  KC_7,   KC_8,    KC_9,    KC_0,    KC_DOT,                   KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TILD,
                            _______, _______, _______,                     _______, _______, _______
),
[_RAISE] = LAYOUT_split_3x6_3(
	_______,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
	_______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_DEL,
	_______,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F12,  KC_INS,
                            _______, _______, _______,                     _______, _______, _______
),
[_ADJUST] = LAYOUT_split_3x6_3(
    RESET,    _______,  KC_MPLY, KC_VOLU,  KC_MSTP,  _______,              _______, _______, _______, KC_LPRN, KC_RPRN, _______,
    _______,  _______,  KC_MPRV, KC_VOLD,  KC_MNXT,  _______,              _______, _______, _______, KC_LCBR, KC_RCBR, _______,
    _______,  _______,  _______, KC_MUTE,  _______,  _______,              _______, _______, _______, KC_LBRC, KC_RBRC, _______,
                                   _______, _______, _______,              _______, _______, _______
),
};


