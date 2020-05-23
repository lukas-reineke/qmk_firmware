#include QMK_KEYBOARD_H

enum custom_keycodes {
    GUI_TAB = SAFE_RANGE,
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
    TMUX_X,
    TMUX_H,
    TMUX_J,
    TMUX_K,
    TMUX_L,
    TMUX_S,
    TMUX_O,
    TMUX_F,
    TMUX_COLON,
    TMUX_ESC,
};

void tmux_command(uint16_t keycode) {
    register_code(KC_LCTRL);
    tap_code(KC_SPC);
    unregister_code(KC_LCTRL);
    tap_code(keycode);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch (keycode) {
            case GUI_TAB:
                register_code(KC_RGUI);
                tap_code(KC_TAB);
                unregister_code(KC_RGUI);
                break;
            case SCREENSHOT:
                register_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_4);
                unregister_code(KC_LALT);
                unregister_code(KC_LSFT);
                break;
            case TMUX_1:
                tmux_command(KC_1);
                break;
            case TMUX_2:
                tmux_command(KC_2);
                break;
            case TMUX_3:
                tmux_command(KC_3);
                break;
            case TMUX_4:
                tmux_command(KC_4);
                break;
            case TMUX_5:
                tmux_command(KC_5);
                break;
            case TMUX_6:
                tmux_command(KC_6);
                break;
            case TMUX_7:
                tmux_command(KC_7);
                break;
            case TMUX_8:
                tmux_command(KC_8);
                break;
            case TMUX_9:
                tmux_command(KC_9);
                break;
            case TMUX_V:
                tmux_command(KC_V);
                break;
            case TMUX_C:
                tmux_command(KC_C);
                break;
            case TMUX_X:
                tmux_command(KC_X);
                break;
            case TMUX_H:
                tmux_command(KC_H);
                break;
            case TMUX_J:
                tmux_command(KC_J);
                break;
            case TMUX_K:
                tmux_command(KC_K);
                break;
            case TMUX_L:
                tmux_command(KC_L);
                break;
            case TMUX_S:
                tmux_command(KC_S);
                break;
            case TMUX_O:
                tmux_command(KC_O);
                break;
            case TMUX_F:
                tmux_command(KC_F);
                break;
            case TMUX_COLON:
                register_code(KC_LCTRL);
                tap_code(KC_SPC);
                unregister_code(KC_LCTRL);
                register_code(KC_LSFT);
                tap_code(KC_SCLN);
                unregister_code(KC_LSFT);
                break;
            case TMUX_ESC:
                tmux_command(KC_ESC);
                break;
        }
    }

    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_MINS,
        KC_LBRC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,

        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_EQL,
        KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,

        MT(MOD_LSFT, KC_GRV), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,
        KC_F13, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_BSLS),

        MO(3), KC_NO, KC_NO, LT(2, KC_BSPC), LT(1, KC_SPC), LGUI_T(KC_ESC), MO(2),
        MO(4), RCTL_T(KC_ESC), LT(1, KC_ENT), LT(4, KC_TAB), GUI_TAB, KC_NO, MO(3)
    ),
    [1] = LAYOUT(
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
        KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,

        KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_NO,
        KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,

        KC_LSFT, KC_NO, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_NO,
        KC_NO, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_NO, MT(MOD_RSFT, KC_BSLS),

        KC_NO, SCREENSHOT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [2] = LAYOUT(
        KC_NO, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO,
        KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,

        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,

        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS
    ),
    [3] = LAYOUT(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO,
        KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ),
    [4] = LAYOUT(
        KC_NO, TMUX_1, TMUX_2, TMUX_3, TMUX_4, TMUX_5, KC_NO,
        KC_NO, TMUX_6, TMUX_7, TMUX_8, TMUX_9, KC_NO, KC_NO,

        KC_NO, KC_NO, TMUX_S, KC_NO, TMUX_F, KC_NO, KC_NO,
        KC_NO, TMUX_H, TMUX_J, TMUX_K, TMUX_L, TMUX_COLON, KC_NO,

        KC_NO, KC_NO, TMUX_X, TMUX_C, TMUX_V, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        KC_TRNS, KC_NO, KC_NO, KC_NO, TMUX_O, TMUX_ESC, KC_TRNS,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS
    ),
};
