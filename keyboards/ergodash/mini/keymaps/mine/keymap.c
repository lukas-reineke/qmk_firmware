#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
bool is_tmux_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    SCREENSHOT,
    TMUX_1,
    TMUX_2,
    TMUX_3,
    TMUX_4,
    TMUX_5,
    TMUX_6,
    TMUX_7,
    TMUX_8,
    TMUX_9,
    TMUX_C,
    TMUX_V,
    TMUX_H,
    TMUX_J,
    TMUX_K,
    TMUX_L,
    TMUX_O,
    TMUX_SCLN,
    FOO,
};

void tmux_command(uint16_t keycode) {
    register_code(KC_LCTRL);
    tap_code(KC_SPC);
    unregister_code(KC_LCTRL);
    tap_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FOO:
            if (record->event.pressed) {
                is_tmux_active = true;
            } else {
                is_tmux_active = false;
            }
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_RALT);
                    alt_tab_timer = timer_read();
                } else {
                    register_code(KC_TAB);
                    alt_tab_timer = timer_read();
                }
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case SCREENSHOT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_4);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
            }
            break;
    }


    if (record->event.pressed) {
        switch (keycode) {
            case TMUX_1:
                if (is_tmux_active) {
                    tmux_command(KC_1);
                } else {
                    tap_code(KC_Q);
                }
                break;
            case TMUX_2:
                if (is_tmux_active) {
                    tmux_command(KC_2);
                } else {
                    tap_code(KC_W);
                }
                break;
            case TMUX_3:
                if (is_tmux_active) {
                    tmux_command(KC_3);
                } else {
                    tap_code(KC_E);
                }
                break;
            case TMUX_4:
                if (is_tmux_active) {
                    tmux_command(KC_4);
                } else {
                    tap_code(KC_R);
                }
                break;
            case TMUX_5:
                if (is_tmux_active) {
                    tmux_command(KC_5);
                } else {
                    tap_code(KC_T);
                }
                break;
            case TMUX_6:
                if (is_tmux_active) {
                    tmux_command(KC_6);
                } else {
                    tap_code(KC_Y);
                }
                break;
            case TMUX_7:
                if (is_tmux_active) {
                    tmux_command(KC_7);
                } else {
                    tap_code(KC_U);
                }
                break;
            case TMUX_8:
                if (is_tmux_active) {
                    tmux_command(KC_8);
                } else {
                    tap_code(KC_I);
                }
                break;
            case TMUX_9:
                if (is_tmux_active) {
                    tmux_command(KC_9);
                } else {
                    tap_code(KC_O);
                }
                break;
            case TMUX_V:
                if (is_tmux_active) {
                    tmux_command(KC_V);
                } else {
                    tap_code(KC_V);
                }
                break;
            case TMUX_C:
                if (is_tmux_active) {
                    tmux_command(KC_C);
                } else {
                    tap_code(KC_C);
                }
                break;
            case TMUX_H:
                if (is_tmux_active) {
                    tmux_command(KC_H);
                } else {
                    tap_code(KC_H);
                }
                break;
            case TMUX_J:
                if (is_tmux_active) {
                    tmux_command(KC_J);
                } else {
                    tap_code(KC_J);
                }
                break;
            case TMUX_K:
                if (is_tmux_active) {
                    tmux_command(KC_K);
                } else {
                    tap_code(KC_K);
                }
                break;
            case TMUX_L:
                if (is_tmux_active) {
                    tmux_command(KC_L);
                } else {
                    tap_code(KC_L);
                }
                break;
            case TMUX_SCLN:
                if (is_tmux_active) {
                    tmux_command(KC_O);
                } else {
                    tap_code(KC_SCLN);
                }
                break;
        }
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB, TMUX_1, TMUX_2, TMUX_3, TMUX_4, TMUX_5, KC_MINS,
        KC_LBRC, TMUX_6, TMUX_7, TMUX_8, TMUX_9, KC_P, KC_BSPC,

        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_EQL,
        KC_RBRC, TMUX_H, TMUX_J, TMUX_K, TMUX_L, TMUX_SCLN, KC_QUOT,

        MT(MOD_LSFT, KC_GRV), KC_Z, KC_X, TMUX_C, TMUX_V, KC_B, KC_NO,
        KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_BSLS),

        TT(3), KC_NO, KC_NO, KC_BSPC, LT(1, KC_SPC), LGUI_T(KC_ESC), TT(2),
        FOO, RCTL_T(KC_ESC), LT(1, KC_ENT), KC_TAB, ALT_TAB, KC_NO, TT(3)
    ),
    [1] = LAYOUT(
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
        KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,

        KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_NO,
        KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,

        KC_LSFT, KC_NO, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_NO,
        KC_NO, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_NO, MT(MOD_RSFT, KC_BSLS),

        KC_NO, SCREENSHOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [2] = LAYOUT(
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
        KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_QUOT, KC_BSLS,

        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [3] = LAYOUT(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO,
        KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC,

        KC_NO, TMUX_1, TMUX_2, TMUX_3, TMUX_4, TMUX_5, KC_NO,
        KC_NO, TMUX_6, TMUX_7, TMUX_8, TMUX_9, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, TMUX_C, TMUX_V, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ),
    [4] = LAYOUT(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO,
        KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC,

        KC_NO, TMUX_1, TMUX_2, TMUX_3, TMUX_4, TMUX_5, KC_NO,
        KC_NO, TMUX_6, TMUX_7, TMUX_8, TMUX_9, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, TMUX_C, TMUX_V, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ),
};

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 500) {
            unregister_code(KC_RALT);
            is_alt_tab_active = false;
        }
    }
}
