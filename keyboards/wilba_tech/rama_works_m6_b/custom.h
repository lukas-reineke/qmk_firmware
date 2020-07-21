RGB_MATRIX_EFFECT(CUSTOM)



bool CUSTOM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = hsv_to_rgb(hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
    }
    return true
}
