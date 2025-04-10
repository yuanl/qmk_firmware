#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        QK_GESC,KC_Q, KC_W, KC_E, KC_R, KC_T,                                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_TAB, LSFT_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LCTL_T(KC_F), KC_G,       KC_H, RCTL_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
        KC_ENT, KC_SPC, MO(1),                                                      KC_ENT, KC_BSPC, KC_RSFT
        ),
    [1] = LAYOUT_split_3x6_3(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                           KC_6, KC_7, KC_8, KC_9, KC_0, KC_PMNS,
        KC_TRNS, KC_TRNS, KC_TRNS, S(C(KC_TAB)), C(KC_TAB), KC_TRNS,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_EQL, KC_PPLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_T, KC_Z,
        KC_NO, KC_NO, KC_NO,                                            MO(2), KC_PGUP, KC_PGDN
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_PGUP, KC_NO, KC_NO, KC_PGDN, KC_TRNS, KC_PEQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_BSLS,
        KC_NO, KC_NO, MO(3),                                            KC_NO, KC_NO, KC_NO
        ),
    [3] = LAYOUT_split_3x6_3(
        KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO,       KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLD, KC_VOLU,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           DT_PRNT, DT_DOWN, DT_UP, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, MO(0), KC_NO,                                KC_NO, KC_NO, KC_NO
        )
};

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case LGUI_T(KC_S):
            if (other_keycode == KC_C || other_keycode == KC_V) {
                return true;
            }
            break;

        case LALT_T(KC_D):
            if (other_keycode == KC_O) {
                return false;
            } else if (other_keycode == KC_SPC) {
                return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
