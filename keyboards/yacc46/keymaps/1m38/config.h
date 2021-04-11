#define ENCODER_RESOLUTION 4
#define TAPPING_TERM 160
#define PERMISSIVE_HOLD

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef ENCODER_ENABLE
  #define ENCODER_RESOLUTION 4
#endif

#if RGBRIGHT_ENABLE
#define RGBLIGHT_LIMIT_VAL 200
#define RGBLIGHT_LAYERS
#endif
