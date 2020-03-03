
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
// #define L_BASE 0
#define L_RAISE 2
#define L_LOWER 4
#define L_NUMPAD 8
#define L_ADJUST 16
#define L_ADJUST_TRI 22

char layer_state_str[24];

const char *read_layer_state(void) {
  char *layer_name;
  if      (layer_state & L_ADJUST)  layer_name = "Adjust";
  else if (layer_state & L_NUMPAD)  layer_name = "NumPad";
  else if (layer_state & L_LOWER)   layer_name = "Lower";
  else if (layer_state & L_RAISE)   layer_name = "Raise";
  else if (layer_state == 0)        layer_name = "Querty";
  else                              layer_name = "Undef";

  snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %s %ld", layer_name, layer_state);
  return layer_state_str;
}
