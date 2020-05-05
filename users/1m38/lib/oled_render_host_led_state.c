#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE
void oled_render_host_led_state(void) {
    const led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("NL:"), false);
    oled_write_P(led_state.num_lock ? PSTR("on") : PSTR("- "), false);
    oled_write_P(PSTR(" CL:"), false);
    oled_write_P(led_state.caps_lock ? PSTR("on") : PSTR("- "), false);
    oled_write_P(PSTR(" SL:"), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("on") : PSTR("-"), false);
}
#endif
