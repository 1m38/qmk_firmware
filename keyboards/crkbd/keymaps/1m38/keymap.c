#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number
{
  _QWERTY = 0,
  _EUCALYN,
  _RAISE,
  _LOWER,
  _NUMPAD,
  _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  RGBRST
};

#if SWAP_CAPS
  #define MY_LCTL KC_CAPS
  #define MY_CAPS KC_LCTL
#else
  #define MY_LCTL KC_LCTL
  #define MY_CAPS KC_CAPS
#endif

#define LOW_MH LT(_LOWER, KC_MHEN)  // タップで無変換, ホールドでLOWER
#define RAISE  MO(_RAISE)
#define NUMPAD TG(_NUMPAD)
#define ALT_ESC ALT_T(KC_ESC)       // タップでEsc, ホールドでAlt
#define WINPSCR G(KC_PSCR)          // Win + PrtScr
#define WINSFTS G(S(KC_S))          // Win + Shift + S

#define PANIC LALT(LCTL(KC_DEL))  // Ctrl-Alt-Del


enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, JP_SCLN, JP_COLN,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, JP_COMM,  JP_DOT, KC_MINS, JP_SLSH,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ALT_ESC,  LOW_MH,  KC_SPC,     KC_ENT,   RAISE, KC_RSFT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_EUCALYN] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W, JP_COMM,  JP_DOT, JP_SCLN,                         KC_M,    KC_R,    KC_D,    KC_Y,    KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MY_LCTL,    KC_A,    KC_O,    KC_E,    KC_I,    KC_U,                         KC_G,    KC_T,    KC_K,    KC_S,    KC_N, JP_COLN,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,                         KC_B,    KC_H,    KC_J,    KC_L, KC_MINS, JP_SLSH,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ALT_ESC,  LOW_MH,  KC_SPC,     KC_ENT,   RAISE, KC_RSFT \
                                      //`--------------------------'  `--------------------------'
  ),


  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, JP_EXLM,  JP_DQT, JP_HASH,  JP_DLR, JP_PERC,                      JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN,  JP_GRV, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_TILD,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, JP_PIPE, JP_CIRC,   JP_AT, JP_LBRC, JP_LCBR,                      JP_RCBR, JP_RBRC, JP_UNDS,  JP_DOT, JP_BSLS, JP_QUES,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  NUMPAD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_DEL, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_HENK,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

[_NUMPAD] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX,  NUMPAD,                      XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PDOT, KC_KP_1, KC_KP_2, KC_KP_3, KC_PMNS, KC_PSLS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_PENT, _______, KC_KP_0 \
                                      //`--------------------------'  `--------------------------'
    ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    G(KC_TAB), _______, _______, G(KC_E), G(KC_R), _______,                       KC_INS, WINSFTS, WINPSCR, JP_ZHTG, JP_KANA,   RESET,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, G(KC_A), _______, G(KC_D), _______, _______,                   S(MY_CAPS), KC_PSCR, KC_PGUP, _______, _______,   PANIC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_LWIN, G(KC_X), _______, G(KC_V), _______,                      _______, KC_HOME, KC_PGDN,  KC_END,  QWERTY, EUCALYN,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  LOW_MH, _______,    _______,   RAISE, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

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
    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    // case ADJUST:
    //     if (record->event.pressed) {
    //       layer_on(_ADJUST);
    //     } else {
    //       layer_off(_ADJUST);
    //     }
    //     return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

char layer_state_str[24];

const char *read_layer_state(void) {
  char *base_layer;
  switch (default_layer_state)
  {
    case (1U<<_QWERTY):
      base_layer = "Qwerty";
      break;
    case (1U<<_EUCALYN):
      base_layer = "Eucalyn";
      break;
    default:
      base_layer = "Undef";
      break;
  }

  char *layer_name;
  if      (layer_state & (1U<<_ADJUST))   layer_name = "Adjust";
  else if (layer_state & (1U<<_NUMPAD))   layer_name = "NumPad";
  else if (layer_state & (1U<<_LOWER))    layer_name = "Lower";
  else if (layer_state & (1U<<_RAISE))    layer_name = "Raise";
  else if (layer_state == 0)              layer_name = base_layer;
  else                                    layer_name = "Undef";

  snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %s %ld", layer_name, layer_state);
  return layer_state_str;
}
