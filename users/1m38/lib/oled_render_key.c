#include <stdio.h>
#include QMK_KEYBOARD_H

#ifdef OLED_DRIVER_ENABLE

typedef struct {
    uint8_t row;
    uint8_t col;
    uint16_t keycode;
} pushed_key_t;
static pushed_key_t pushed_key = {0, 0, 0};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ';', '\'', ' ', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    pushed_key.row = record->event.key.row;
    pushed_key.col = record->event.key.col;
    pushed_key.keycode = keycode;
}


void oled_render_key(void) {
    static char buf[4];
    // row
    itoa(pushed_key.row, buf, 10);
    oled_write(buf, false); oled_write_char('x', false);
    // col
    itoa(pushed_key.col, buf, 10);
    oled_write(buf, false); oled_write_char(' ', false);
    // keycode
    itoa(pushed_key.keycode, buf, 10);
    oled_write(buf, false); oled_write_P(PSTR(": "), false);
    // key
    if (pushed_key.keycode < 60) {
        oled_write_char(code_to_name[pushed_key.keycode], false);
    }
    oled_write_char('\n', false);
}
#endif