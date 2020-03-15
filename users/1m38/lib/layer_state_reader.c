#include QMK_KEYBOARD_H
#include <stdio.h>

// required to implement on keymap.c
const char *print_layer(int layer_number);

const char *read_layer_state(void) {
  const char *layer_str = "";
  int layer = get_highest_layer(layer_state);
  if (layer == 0)
  {
    layer_str = print_layer(get_highest_layer(default_layer_state));
  }
  else
  {
    layer_str = print_layer(layer);
  }

  static char layer_state_str[24] = "";
  snprintf(layer_state_str, sizeof(layer_state_str), "Layer: %s", layer_str);
  return layer_state_str;
}
