#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
#ifdef RGBLIGHT_ENABLE

void oled_render_rgb_value(void) {
    static char value_str[6];
    oled_write_P(PSTR("H:"), false);
    itoa(rgblight_get_hue(), value_str, 10);
    oled_write(value_str, false);
    oled_write_P(PSTR(" S:"), false);
    itoa(rgblight_get_sat(), value_str, 10);
    oled_write(value_str, false);
    oled_write_P(PSTR(" V:"), false);
    itoa(rgblight_get_val(), value_str, 10);
    oled_write_ln(value_str, false);
}

#endif
#endif
