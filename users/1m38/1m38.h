#ifdef OLED_DRIVER_ENABLE
void oled_render_host_led_state(void);
void count_type(void);
void oled_render_type_count(void);
void oled_render_uptime(void);
#ifdef RGBLIGHT_ENABLE
void oled_render_rgb_value(void);
#endif
void set_keylog(uint16_t keycode, keyrecord_t *record);
void oled_render_key(void);
#endif