/* Copyright 2021 1p038
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LALT,     KC_ESC,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,    XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LCTL,   LOWER,  KC_SPC,     KC_ENT,   RAISE, KC_RSFT,\
    //                                    `--------+--------+--------'  `--------+--------+--------'
                                                     KC_LGUI,                      KC_BSPC
    //                                             `--------'                    `--------'
    ),

    [_RAISE] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
    //                                    `--------+--------+--------'  `--------+--------+--------'
                                                     _______,                      _______
    //                                             `--------'                    `--------'
    ),

    [_LOWER] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                 KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
    //                                    `--------+--------+--------'  `--------+--------+--------'
                                                     _______,                       KC_DEL
    //                                             `--------'                    `--------'
    ),

    [_ADJUST] = LAYOUT(
    //         ,--------------------------------------------.                    ,--------------------------------------------.
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
          RESET, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______,\
    //                                    `--------+--------+--------'  `--------+--------+--------'
                                                     _______,                      _______
    //                                             `--------'                    `--------'
    ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

void oled_write_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }
}

void oled_render_host_led_state(void) {
    const led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("NL:"), false);
    oled_write_P(led_state.num_lock ? PSTR("on") : PSTR("- "), false);
    oled_write_P(PSTR(" CL:"), false);
    oled_write_P(led_state.caps_lock ? PSTR("on") : PSTR("- "), false);
    oled_write_P(PSTR(" SL:"), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("on") : PSTR("-"), false);
}

void oled_task_user(void) {
    // If you want to change the display of OLED, you need to change here
    render_qmk_logo();

    oled_write_layer_state();
    oled_render_host_led_state();
}
#endif

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
