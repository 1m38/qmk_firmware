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

enum tapdance_keycodes {
    LOWER_MH,    // 1tap: 無変換, hold: MO(_LOWER), 2tap: TG(_LOWER)
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EUCALYN,
    ESC_MH,
    RAISE,
};

#define TD_LOWMH TD(LOWER_MH)
#define ALT_ESC LALT_T(KC_ESC)
#define WINPSCR G(KC_PSCR)        // Win + PrtScr
#define WINSFTS G(S(KC_S))        // Win + Shift + S
#define PANIC LALT(LCTL(KC_DEL))  // Ctrl-Alt-Del

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LWIN,     KC_ESC,    KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,    KC_BTN3,    KC_N,    KC_M, JP_COMM,  JP_DOT, KC_MINS, JP_SLSH,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LCTL,TD_LOWMH,  KC_SPC,     KC_ENT,   RAISE, KC_RSFT,\
             //,--------.                 `--------+--------+--------'  `--------+--------+--------'                 ,--------.
                 JP_MHEN,                            ALT_ESC,                      KC_BSPC,                            JP_HENK
             //`--------'                          `--------'                    `--------'                          `--------'
    ),

    [_EUCALYN] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                    KC_Q,    KC_W, JP_COMM,  JP_DOT, JP_SCLN,                         KC_M,    KC_R,    KC_D,    KC_Y,   KC_P,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U, _______,    _______,    KC_G,    KC_T,    KC_K,    KC_S,    KC_N, _______,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
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
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,    _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_TILD,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
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
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,    _______, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
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
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
      G(KC_TAB), G(KC_A), _______, G(KC_D), _______, _______, _______,    _______, KC_CAPS, KC_PSCR, _______, _______, _______,   RESET,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
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

uint16_t timer_raise_pressed = 0;
bool is_last_pressed_key_raise = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed)
    {
        is_last_pressed_key_raise = (keycode == RAISE);
    }
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
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                timer_raise_pressed = record->event.time;
            } else {
                layer_off(_RAISE);
                if (is_last_pressed_key_raise && timer_elapsed(timer_raise_pressed) < TAPPING_TERM) {
                    // tapped(released) 変換
                    tap_code(KC_HENK);
                }
            }
            return false;
    }
    return true;
}

// Tap Dance

typedef enum {
    UNKNOWN_TAP,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    TRIPLE_OR_MORE_TAP
} tap_state_t;

typedef struct {
    bool        is_press_action;
    tap_state_t state;
} tap;

// Determine the current tap dance state
tap_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        return DOUBLE_TAP;
    } else if (state->count >= 3) {
        return TRIPLE_OR_MORE_TAP;
    }
    return UNKNOWN_TAP;
}

// Tap Dance definition: LOWER_MH
static tap lower_mh_tap_state = {
    .is_press_action = true,
    .state = UNKNOWN_TAP
};

void lower_mh_each(qk_tap_dance_state_t *state, void *user_data) {
    if (state->pressed)
    {
        layer_on(_LOWER);
    }
}

void lower_mh_finished(qk_tap_dance_state_t *state, void *user_data) {
    lower_mh_tap_state.state = cur_dance(state);
    switch (lower_mh_tap_state.state) {
        case SINGLE_TAP:
            // 無変換
            tap_code(KC_MHEN);
            break;
        default:
            break;
    }
}

void lower_mh_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (lower_mh_tap_state.state != DOUBLE_TAP) {
        layer_off(_LOWER);
    }
    lower_mh_tap_state.state = UNKNOWN_TAP;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [LOWER_MH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(
        lower_mh_each, lower_mh_finished, lower_mh_reset, 200),
};

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