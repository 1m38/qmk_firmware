/* Copyright 2019 ENDO Katsuhiro <ka2hiro@kagizaraya.jp>
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

#include "board.h"
#include "keymap_jp.h"
// #include <stdio.h>

extern keymap_config_t keymap_config;

enum layer_number
{
  _QWERTY = 0,
  _QWERTY_US,
  _EUCALYN,
  _RAISE,
  _RAISE_US,
  _LOWER,
  _NUMPAD,
  _ADJUST
};


// Tap Dance declarations
enum td_keycodes {
  TD_ALT_ESC_MH   // ホールドでAlt, タップでEsc, ダブルタップでEsc+無変換
};
#define TD_AEMH TD(TD_ALT_ESC_MH)    // ホールドでAlt, タップでEsc, ダブルタップでEsc+無変換

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  EUCALYN,
  QWER_US,
};

#if SWAP_CAPS
  #define MY_LCTL KC_CAPS
  #define MY_CAPS KC_LCTL
#else
  #define MY_LCTL KC_LCTL
  #define MY_CAPS KC_CAPS
#endif

#define LOW_MH LT(_LOWER, KC_MHEN)  // タップで無変換, ホールドでLOWER
#define RAI_HK LT(_RAISE, KC_HENK)  // タップで変換, ホールドでRAISE
#define LOW_MHU LT(_LOWER, KC_F15)  // タップで無変換(F15), ホールドでLOWER
#define RAI_HKU LT(_RAISE_US, KC_F16)  // タップで変換(F16), ホールドでRAISE
#define NUMPAD TG(_NUMPAD)
#define ALT_ESC ALT_T(KC_ESC)       // タップでEsc, ホールドでAlt
#define WINPSCR G(KC_PSCR)          // Win + PrtScr
#define WINSFTS G(S(KC_S))          // Win + Shift + S
#define PANIC LALT(LCTL(KC_DEL))  // Ctrl-Alt-Del

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, JP_COMM,  JP_DOT, KC_MINS, JP_SLSH,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LWIN, TD_AEMH,  LOW_MH,  KC_SPC,           KC_ENT,  RAI_HK, KC_RSFT, KC_DOWN,   KC_UP,  NUMPAD \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  ),

  [_QWERTY_US] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_EQL,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, KC_COMM,  KC_DOT, KC_MINS, KC_SLSH,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, LOW_MHU, _______,          _______, RAI_HKU, _______, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  ),

  [_EUCALYN] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W, JP_COMM,  JP_DOT, JP_SCLN,             KC_M,    KC_R,    KC_D,    KC_Y,    KC_P, _______,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,             KC_G,    KC_T,    KC_K,    KC_S,    KC_N, _______,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,             KC_B,    KC_H,    KC_J,    KC_L, KC_MINS, _______,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,  LOW_MH, _______,          _______,  RAI_HK, _______, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, JP_EXLM,  JP_DQT, JP_HASH,  JP_DLR, JP_PERC,          JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN,  JP_GRV, _______,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_TILD,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, JP_PIPE, JP_CIRC,   JP_AT, JP_LBRC, JP_LCBR,          JP_RCBR, JP_RBRC, JP_UNDS,  JP_DOT, JP_BSLS, JP_QUES,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  ),

  [_RAISE_US] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, KC_EXLM,  KC_DQT, KC_HASH,  KC_DLR, KC_PERC,          KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN,  KC_GRV, _______,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE, KC_CIRC,   KC_AT, KC_LBRC, KC_LCBR,          KC_RCBR, KC_RBRC, KC_UNDS,  KC_DOT, KC_BSLS, KC_ASTR,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,          XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,  NUMPAD,          XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
    ),

  [_NUMPAD] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  NUMPAD,          KC_PDOT, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, KC_PSLS,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          KC_PENT, _______, KC_KP_0, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
    ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
    G(KC_TAB), _______, _______, G(KC_E), G(KC_R), _______,           KC_INS, WINSFTS, WINPSCR, JP_ZHTG, JP_KANA,   RESET,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, G(KC_A), _______, G(KC_D), _______, _______,       S(MY_CAPS), KC_PSCR, _______, _______, _______,   PANIC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_LWIN, G(KC_X), _______, G(KC_V), _______,          _______, _______, _______, QWER_US,  QWERTY, EUCALYN,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______ \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  )
};
// clang-format on

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  if ((state & (1UL << _ADJUST)) == 0)
  {
    state = update_tri_layer_state(state, _LOWER, _RAISE_US, _ADJUST);
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
    count_type();
  }
#endif
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case EUCALYN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_EUCALYN);
      }
      return false;
    case QWER_US:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY_US);
      }
      return false;
  }
  return true;
}

bool led_update_user(led_t led_state) {
  // Left Yellow: default layer (Qwerty: off, Eucalyn: on)
  board_set_led_by_index(0, LED_YELLOW, (default_layer_state & (1U<<_EUCALYN)));
  // Right Yellow: NUMPAD layer
  board_set_led_by_index(1, LED_YELLOW, (layer_state & (1U<<_NUMPAD)));

  return false;
}

#ifdef OLED_DRIVER_ENABLE

void oled_write_layer_state(void) {
    oled_write_P(PSTR("L: "), false);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case _QWERTY_US:
            oled_write_ln_P(PSTR("Qwerty(US)"), false);
            break;
        case _EUCALYN:
            oled_write_ln_P(PSTR("Eucalyn"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _RAISE_US:
            oled_write_ln_P(PSTR("Raise(US)"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NumPad"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
            break;
    }
}

void oled_task_user(void) {
  // If you want to change the display of OLED, you need to change here
  oled_write_layer_state();
  oled_render_host_led_state();
  oled_render_type_count();
  oled_render_uptime();
}
#endif

// Tap Dance definitions
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_TAP,
  TD_STATE_UNKNOWN
} td_state_t;

static td_state_t td_state;

td_state_t cur_dance(qk_tap_dance_state_t *state)
{
  if (state->count == 1) {
    if (!state->pressed) { return SINGLE_TAP; }
    return SINGLE_HOLD;
  }
  if (state->count == 2) { return DOUBLE_TAP; }
  return TD_STATE_UNKNOWN;
}

void alt_esc_mh_finished (qk_tap_dance_state_t *state, void *user_data)
{
  td_state = cur_dance(state);
  switch (td_state)
  {
    case SINGLE_TAP:
      register_code(KC_ESC);    // Esc
      break;
    case SINGLE_HOLD:
      register_code(KC_LALT);    // Alt
      break;
    case DOUBLE_TAP:
      register_code(KC_ESC); unregister_code(KC_ESC);  // Esc
      if (default_layer_state & (1U<<_QWERTY_US))
      {
        register_code(KC_F15);
      }
      else
      {
        register_code(KC_MHEN);   // 無変換
      }
      break;
    default:
      break;
  }
}

void alt_esc_mh_reset (qk_tap_dance_state_t *state, void *user_data)
{
  switch (td_state)
  {
    case SINGLE_TAP:
      unregister_code(KC_ESC);    // Escをリリース
      break;
    case SINGLE_HOLD:
      unregister_code(KC_LALT);    // Altをリリース
      break;
    case DOUBLE_TAP:
      if (default_layer_state & (1U<<_QWERTY_US))
      {
        unregister_code(KC_F15);
      }
      else
      {
        unregister_code(KC_MHEN);   // 無変換
      }
      break;
    default:
      break;
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  
  [TD_ALT_ESC_MH]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_esc_mh_finished, alt_esc_mh_reset)
};
