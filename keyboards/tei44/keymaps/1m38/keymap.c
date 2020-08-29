/* Copyright 2020 1m38
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_jp.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _EUCALYN,
    _RAISE,
    _LOWER,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EUCALYN,
    ESC_MH,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ALT_ESC LALT_T(KC_ESC)
#define WINPSCR G(KC_PSCR)        // Win + PrtScr
#define WINSFTS G(S(KC_S))        // Win + Shift + S
#define PANIC LALT(LCTL(KC_DEL))  // Ctrl-Alt-Del

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,    KC_BTN3,    KC_N,    KC_M, JP_COMM,  JP_DOT, KC_MINS, JP_SLSH,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LCTL,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RSFT,\
             //,--------.                 `--------+--------+--------'  `--------+--------+--------'                 ,--------.
                 JP_MHEN,                            ALT_ESC,                      KC_BSPC,                            JP_HENK
             //`--------'                          `--------'                    `--------'                          `--------'
    ),

    [_EUCALYN] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                    KC_Q,    KC_W, JP_COMM,  JP_DOT, JP_SCLN,                         KC_M,    KC_R,    KC_D,    KC_Y,   KC_P,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                         KC_G,    KC_T,    KC_K,    KC_S,    KC_N, _______,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F, _______,    _______,    KC_B,    KC_H,    KC_J,    KC_L, KC_MINS, _______,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
             //,--------.                 `--------+--------+--------'  `--------+--------+--------'                 ,--------.
                 _______,                            _______,                      _______,                            _______
             //`--------'                          `--------'                    `--------'                          `--------'
    ),

    [_RAISE] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                 JP_EXLM,  JP_DQT, JP_HASH,  JP_DLR, JP_PERC,                      JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN,  JP_GRV,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_TILD,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______, JP_PIPE, JP_CIRC,   JP_AT, JP_LBRC, JP_LCBR, _______,    _______, JP_RCBR, JP_RBRC, JP_UNDS,  JP_DOT, JP_BSLS, JP_QUES,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
             //,--------.                 `--------+--------+--------'  `--------+--------+--------'                 ,--------.
                 _______,                            _______,                      _______,                            _______
             //`--------'                          `--------'                    `--------'                          `--------'
    ),

    [_LOWER] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______,  KC_F11,  KC_F12, XXXXXXX,  ESC_MH, XXXXXXX, _______,    _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
             //,--------.                 `--------+--------+--------'  `--------+--------+--------'                 ,--------.
                 _______,                            _______,                       KC_DEL,                            _______
             //`--------'                          `--------'                    `--------'                          `--------'
    ),

    [_ADJUST] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                 _______, _______, G(KC_E), G(KC_R), _______,                       KC_INS, WINSFTS, WINPSCR, JP_ZHTG, JP_KANA,\
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      G(KC_TAB), G(KC_A), _______, G(KC_D), _______, _______,                      KC_CAPS, KC_PSCR, _______, _______, _______,   RESET,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______, KC_LWIN, G(KC_X), _______, G(KC_V), _______, _______,    _______, _______, _______, _______, EUCALYN,  QWERTY,   PANIC,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
             //,--------.                 `--------+--------+--------'  `--------+--------+--------'                 ,--------.
                 _______,                            _______,                      _______,                            _______
             //`--------'                          `--------'                    `--------'                          `--------'
    ),
};
// clang-format on

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY);
            }
            return false;
        case EUCALYN:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _EUCALYN);
            }
            return false;
        case ESC_MH:
            if (record->event.pressed) {
                tap_code(KC_ESC);
                tap_code(JP_MHEN);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
}
#endif