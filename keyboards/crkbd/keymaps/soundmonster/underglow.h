
#ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
RGB_MATRIX_EFFECT(ALPHAS_MODS_MINE)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV SOLID_REACTIVE_WIDE_USER_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);

    uint8_t layer = biton32(layer_state);

    if (layer == 1) {
        hsv.h = qadd8(rgb_matrix_config.hsv.h, 60);
    } else if (layer == 2) {
        hsv.h = qadd8(rgb_matrix_config.hsv.h, -60);
    } else if (layer == 3) {
        hsv.h = qadd8(rgb_matrix_config.hsv.h, -120);
    }

    return hsv;
}

// alphas = color1, mods = color2
bool ALPHAS_MODS_MINE(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t layer = biton32(layer_state);

    HSV hsv  = rgb_matrix_config.hsv;
    RGB rgb1 = hsv_to_rgb(hsv);
    hsv.h = qadd8(hsv.h, 60);
    /* hsv.h += rgb_matrix_config.speed; */
    RGB rgb2 = hsv_to_rgb(hsv);

    hsv.h = qadd8(rgb_matrix_config.hsv.h, -60);
    RGB rgb3 = hsv_to_rgb(hsv);

    hsv.h = qadd8(rgb_matrix_config.hsv.h, -120);
    RGB rgb4 = hsv_to_rgb(hsv);

    effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_WIDE_USER_math);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            if (layer == 1) {
                rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
            } else if (layer == 2) {
                rgb_matrix_set_color(i, rgb3.r, rgb3.g, rgb3.b);
            } else if (layer == 3) {
                rgb_matrix_set_color(i, rgb4.r, rgb4.g, rgb4.b);
            } else {

                rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
            }
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_ALPHAS_MODS
