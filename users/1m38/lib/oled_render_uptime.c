#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE

// write given digit, with leading zero if digit < 10
static void oled_write_2digit(const unsigned int *digit) {
    static char buf[5];
    itoa(*digit, buf, 10);
    if (*digit < 10) {
        oled_write_char('0', false);
    }
    oled_write(buf, false);
}

void oled_render_uptime(void) {
    static uint32_t uptime_s;
    uptime_s = timer_read32() / 1000;
    static unsigned int uptime_tmp;
    oled_write_P(PSTR("Uptime "), false);
    // hour
    uptime_tmp = (uptime_s / 3600) % 60;
    oled_write_2digit(&uptime_tmp);
    oled_write_char(':', false);
    // minutes
    uptime_tmp = (uptime_s / 60) % 60;
    oled_write_2digit(&uptime_tmp);
    oled_write_char(':', false);
    // seconds
    uptime_tmp = uptime_s % 60;
    oled_write_2digit(&uptime_tmp);
    oled_write_char('\n', false);
}
#endif