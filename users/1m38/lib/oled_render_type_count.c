#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
static unsigned int type_count = 0;
static char         type_count_str[7];

void count_type(void) { type_count++; }

void oled_render_type_count(void) {
    oled_write_P(PSTR("Type count: "), false);
    itoa(type_count, type_count_str, 10);
    oled_write_ln(type_count_str, false);
}
#endif
