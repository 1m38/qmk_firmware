/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "1m38.h"
#include "keymap_jp.h"

enum layers {
    _QWERTY,
    _QWERTY_US,
    _EUCALYN,
    _RAISE,
    _RAISE_US,
    _LOWER,
    _NUMPAD,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    EUCALYN,
    QWER_US,
    SWAP_CA,
};

#define LOW_MH LT(_LOWER, KC_MHEN)     // タップで無変換, ホールドでLOWER
#define RAI_HK LT(_RAISE, KC_HENK)     // タップで変換, ホールドでRAISE
#define LOW_MHU LT(_LOWER, KC_F15)     // タップで無変換(F15), ホールドでLOWER
#define RAI_HKU LT(_RAISE_US, KC_F16)  // タップで変換(F16), ホールドでRAISE
#define NUMPAD TG(_NUMPAD)
#define ALT_ESC ALT_T(KC_ESC)     // タップでEsc, ホールドでAlt
#define WINPSCR G(KC_PSCR)        // Win + PrtScr
#define WINSFTS G(S(KC_S))        // Win + Shift + S
#define PANIC LALT(LCTL(KC_DEL))  // Ctrl-Alt-Del

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, KC_LWIN,    XXXXXXX, XXXXXXX,    KC_N,    KC_M, JP_COMM,  JP_DOT, KC_MINS, JP_SLSH,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   RGB_TOG, ALT_ESC,  LOW_MH,  KC_SPC, KC_BSPC,    KC_RCTL,  KC_ENT,  RAI_HK, KC_RSFT, KC_BTN3 \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_QWERTY_US] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
        _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_EQL,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, _______, _______,    _______, _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_MINS, KC_SLSH,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, LOW_MHU, _______, _______,    _______, _______, RAI_HKU, _______, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_EUCALYN] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
        _______,    KC_Q,    KC_W, JP_COMM,  JP_DOT, JP_SCLN,                                           KC_M,    KC_R,    KC_D,    KC_Y,    KC_P, _______,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                                           KC_G,    KC_T,    KC_K,    KC_S,    KC_N, _______,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F, _______, _______,    _______, _______,    KC_B,    KC_H,    KC_J,    KC_L, KC_MINS, _______,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______,  LOW_MH, _______, _______,    _______, _______,  RAI_HK, _______, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_RAISE] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
        _______, JP_EXLM,  JP_DQT, JP_HASH,  JP_DLR, JP_PERC,                                        JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN,  JP_GRV, _______,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_TILD,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______, JP_PIPE, JP_CIRC,   JP_AT, JP_LBRC, JP_LCBR, _______, _______,    _______, _______, JP_RCBR, JP_RBRC, JP_UNDS,  JP_DOT, JP_BSLS, JP_QUES,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_RAISE_US] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
        _______, KC_EXLM,  KC_DQT, KC_HASH,  KC_DLR, KC_PERC,                                        KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN,  KC_GRV, _______,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_TILD,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______, KC_PIPE, KC_CIRC,   KC_AT, KC_LBRC, KC_LCBR, _______, _______,    _______, _______, KC_RCBR, KC_RBRC, KC_UNDS,  KC_DOT, KC_BSLS, KC_QUES,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_LOWER] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                        XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,  NUMPAD, _______, _______,    _______, _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_NUMPAD] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
        _______, KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_BSPC,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  NUMPAD, _______, _______,    _______, _______, KC_PDOT, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, KC_PSLS,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______, _______, _______,    _______, _______, _______, KC_KP_0, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),

    [_ADJUST] = LAYOUT(
    //,-----------------------------------------------------.                                      ,-----------------------------------------------------.
      G(KC_TAB), _______, _______, G(KC_E), G(KC_R), _______,                                         KC_INS, WINSFTS, WINPSCR, JP_ZHTG, JP_KANA,   RESET,\
    //|--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
        _______, G(KC_A), _______, G(KC_D), _______, _______,                                        KC_CAPS, KC_PSCR, _______, _______, SWAP_CA,   PANIC,\
    //|--------+--------+--------+--------+--------+--------+-----------------.  ------------------+--------+--------+--------+--------+--------+--------|
        _______, KC_LWIN, G(KC_X), _______, G(KC_V), _______, _______, _______,    _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, QWER_US,  QWERTY, EUCALYN,\
    //|--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                   _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______ \
                               //`--------------------------------------------'  `--------------------------------------------'
    ),
};
// clang-format on

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    if ((state & (1UL << _ADJUST)) == 0) {
        state = update_tri_layer_state(state, _LOWER, _RAISE_US, _ADJUST);
    }
    return state;
}

static bool g_swap_caps = false;
bool        process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
        count_type();
    }
#endif
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
        case QWER_US:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL << _QWERTY_US);
            }
            return false;
        case SWAP_CA:
            if (record->event.pressed) {
                g_swap_caps = (!g_swap_caps);
            }
            return false;
        case KC_CAPS:
            if (g_swap_caps) {
                if (record->event.pressed) {
                    register_code(KC_LCTL);
                } else {
                    unregister_code(KC_LCTL);
                }
                return false;
            } else {
                return true;
            }
        case KC_LCTL:
            if (g_swap_caps) {
                if (record->event.pressed) {
                    register_code(KC_CAPS);
                } else {
                    unregister_code(KC_CAPS);
                }
                return false;
            } else {
                return true;
            }
    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        // clang-format off
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        // clang-format on
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

void oled_write_layer_state(void) {
    oled_write_P(PSTR("L: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty"), false);
            break;
        case _QWERTY_US:
            oled_write_P(PSTR("Qwerty(US)"), false);
            break;
        case _EUCALYN:
            oled_write_P(PSTR("Eucalyn"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _RAISE_US:
            oled_write_P(PSTR("Raise(US)"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NumPad"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            break;
    }
    oled_write_ln_P(g_swap_caps ? PSTR(" SwCp") : PSTR(""), false);
}

static void oled_render_master(void) {
    // QMK Logo and version information
    render_qmk_logo();

    oled_write_layer_state();
    oled_render_host_led_state();
    // oled_render_key();
    oled_render_type_count();
    // oled_render_uptime();
#if RGBLIGHT_ENABLE
    oled_render_rgb_value();
#endif
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_master();
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (get_highest_layer(layer_state) == _RAISE) {
            // Left/Right
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
#ifdef RGBLIGHT_ENABLE
        else if (get_highest_layer(layer_state) == _ADJUST) {
            // Hue change
            if (clockwise) {
                rgblight_increase_hue_noeeprom();
            } else {
                rgblight_decrease_hue_noeeprom();
            }
        }
#endif
        else {
            // Up/Down
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        }
    } else if (index == 1) {
        // Mouse wheel
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
}
#endif

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(156, 255, 168);
#endif
}