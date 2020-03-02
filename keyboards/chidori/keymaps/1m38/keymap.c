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

#include "board.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

// Tap Dance declarations
enum td_keycodes {
  TD_LOWER_LANG
};
#define TD_LowLG TD(TD_LOWER_LANG)    // ホールドでLower, タップで無変換, ダブルタップで変換

enum layer_number
{
  _QWERTY = 0,
  _RAISE,
  _LOWER,
  _NUMPAD,
  _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes
{
  QWERTY = SAFE_RANGE,
  NUMPAD,
  ADJUST
};

#if SWAP_CAPS
  #define MY_LCTL KC_CAPS
  #define MY_CAPS KC_LCTL
#else
  #define MY_LCTL KC_LCTL
  #define MY_CAPS KC_CAPS
#endif

#define RAISE  MO(_RAISE)
#define ALT_ESC ALT_T(KC_ESC)       // タップでEsc, ホールドでAlt
#define WINPSCR G(KC_PSCR)          // Win + PrtScr
#define WINSFTS G(S(KC_S))          // Win + Shift + S
#define PANIC LALT(LCTL(KC_DEL))  // Ctrl-Alt-Del

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M, JP_COMM,  JP_DOT, KC_MINS, JP_SLSH,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, ALT_ESC,TD_LowLG,  KC_SPC,           KC_ENT,   RAISE, KC_RSFT, KC_DOWN,   KC_UP, TG(_NUMPAD) \
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
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,          XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,          XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
    ),

  [_NUMPAD] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK,          XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, KC_PSLS,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,          KC_PENT, _______, KC_KP_0, KC_PDOT, XXXXXXX, TG(_NUMPAD) \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
    ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
    G(KC_TAB), _______, _______, G(KC_E), G(KC_R), _______,           KC_INS, WINSFTS, WINPSCR, JP_ZHTG, JP_KANA,   RESET,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, G(KC_A), _______, G(KC_D), _______, _______,       S(MY_CAPS), KC_PSCR, KC_PGUP, _______, _______,   PANIC,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      _______, KC_LWIN, G(KC_X), _______, G(KC_V), _______,          _______, KC_HOME, KC_PGDN,  KC_END, _______, _______,\
  //|--------+--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,          _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
  //|-----------------------------------------------------'        `-----------------------------------------------------'
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  const layer_state_t t = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  board_set_led_by_index(1, LED_YELLOW, get_highest_layer(t) == _NUMPAD);
  return t;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

bool led_update_user(led_t led_state) {
    board_set_led_by_index(0, LED_YELLOW, led_state.caps_lock);
    //board_set_led_by_index(1, LED_YELLOW, led_state.scroll_lock);

    return false;
}

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

void lower_lang_finished (qk_tap_dance_state_t *state, void *user_data)
{
  td_state = cur_dance(state);
  switch (td_state)
  {
    case SINGLE_TAP:
      // Lowerレイヤにいるなら抜ける
      if (IS_LAYER_ON(_LOWER)) layer_off(_LOWER);
      register_code(KC_MHEN);   // 無変換
      break;
    case SINGLE_HOLD:
      layer_on(_LOWER);   // Lowerレイヤに入る
      break;
    case DOUBLE_TAP:
      // Lowerレイヤにいるなら抜ける
      if (IS_LAYER_ON(_LOWER)) layer_off(_LOWER);
      register_code(KC_HENK);   // 変換
      break;
    default:
      // Lowerレイヤにいるなら抜ける
      if (IS_LAYER_ON(_LOWER)) layer_off(_LOWER);
      break;
  }
}

void lower_lang_reset (qk_tap_dance_state_t *state, void *user_data)
{
  switch (td_state)
  {
    case SINGLE_TAP:
      unregister_code(KC_MHEN);   // 無変換をリリース
      break;
    case SINGLE_HOLD:
      layer_off(_LOWER);          // lowerから抜ける
      break;
    case DOUBLE_TAP:
      unregister_code(KC_HENK);   // 変換をリリース
      break;
    default:
      break;
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  
  [TD_LOWER_LANG]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lower_lang_finished, lower_lang_reset)
};
