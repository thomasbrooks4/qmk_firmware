#include QMK_KEYBOARD_H

#include "keymap_colemak.h"

enum layer_names {
    BASE = 0,
    BASE_CM,
    SYMB,
    MACR
};

enum custom_keycodes {
    LWIN = SAFE_RANGE,
    KC_PC1,
    KC_PC2,
    KC_PC3,
    KC_PC4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0a: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |  O   |   '    |
 * |--------+------+------+------+------+------|   =  |           |   -  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt | LGui |       | LAlt | RAlt |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Backsp| Home |       | PgUp |        |      |
 *                                 | Space|ace/  |------|       |------|  Tab/  |Enter/|
 *                                 | /Shft|Ctrl  |  1)  |       |  2)  |  Ctrl  |Shift |
 *                                 `--------------------'       `----------------------'
 *
 * 1) End/L1
 * 2) PgDown/L2
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,     KC_2,   KC_3,   KC_4,          KC_5,   KC_LEFT,
        KC_DEL,         KC_Q,     KC_W,   KC_F,   KC_P,          KC_G,   TG(SYMB),
        KC_ESC,         KC_A,     KC_R,   KC_S,   KC_T,          KC_D,
        KC_LSFT,        KC_Z,     KC_X,   KC_C,   KC_V,          KC_B,   KC_EQL,
        LT(SYMB,KC_GRV),KC_QUOT,  LALT(KC_LSFT),  KC_LEFT,       KC_RGHT,
                                                             KC_LALT,       LWIN,
                                                                            KC_HOME,
                                               SFT_T(KC_SPC),CTL_T(KC_BSPC),LT(SYMB, KC_END),
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,          KC_BSLS,
                          KC_H,   KC_N,   KC_E,   KC_I,   KC_O,             KC_QUOT,
             KC_MINS,     KC_K,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          LT(SYMB,KC_NO),
             KC_LALT,         KC_RALT,
             KC_PGUP,
             LT(MACR,KC_PGDN),CTL_T(KC_TAB), SFT_T(KC_ENT)
    ),
/* Keymap 0b: Basic layer (Colemak keycodes or QWERTY)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |  O   |   '    |
 * |--------+------+------+------+------+------|   =  |           |   -  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt | LGui |       | LAlt | RAlt |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |Backsp| Home |       | PgUp |        |      |
 *                                 | Space|ace/  |------|       |------|  Tab/  |Enter/|
 *                                 | /Shft|Ctrl  |  1)  |       |  2)  |  Ctrl  |Shift |
 *                                 `--------------------'       `----------------------'
 *
 * 1) End/L1
 * 2) PgDown/L2
 */
[BASE_CM] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,     KC_2,   KC_3,   KC_4,          KC_5,   KC_LEFT,
        KC_DEL,         CM_Q,     CM_W,   CM_F,   CM_P,          CM_G,   TG(SYMB),
        KC_ESC,         CM_A,     CM_R,   CM_S,   CM_T,          CM_D,
        KC_LSFT,        CM_Z,     CM_X,   CM_C,   CM_V,          CM_B,   KC_EQL,
        LT(SYMB,KC_GRV),KC_QUOT,  LALT(KC_LSFT),  KC_LEFT,       KC_RGHT,
                                                             KC_LALT,       LWIN,
                                                                            KC_HOME,
                                               SFT_T(KC_SPC),CTL_T(KC_BSPC),LT(SYMB, KC_END),
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    CM_J,   CM_L,   CM_U,   CM_Y,   KC_P, /*CM_SCLN*/ KC_BSLS,
                          CM_H,   CM_N,   CM_E,   CM_I,   CM_O,             KC_QUOT,
             KC_MINS,     CM_K,   CM_M,   CM_COMM,CM_DOT, CTL_T(CM_SLSH),   KC_RSFT,
                                  KC_UP,  KC_DOWN,KC_LBRC,KC_RBRC,          LT(SYMB,KC_NO),
             KC_LALT,         KC_RALT,
             KC_PGUP,
             LT(MACR,KC_PGDN),CTL_T(KC_TAB), SFT_T(KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Macros
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | DLa  | DLb  |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | PC1  | PC2  | PC3  | PC4  |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MACROS
[MACR] = LAYOUT_ergodox(
       KC_NO,   KC_NO,     KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   DF(BASE),  DF(BASE_CM),  KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_PC1,    KC_PC2,       KC_PC3,  KC_PC4,  KC_NO,
       KC_NO,   KC_NO,     KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,     KC_NO,        KC_NO,   KC_NO,
                                           KC_TRNS,KC_TRNS,
                                                   KC_TRNS,
                                   KC_TRNS,KC_TRNS,KC_TRNS,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LWIN:
            if (record->event.pressed) {
                tap_code(KC_RSFT);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
            }
            return false;
        case KC_PC1:
            if (record->event.pressed) {
                tap_code_delay(KC_SLCK, 50);
                wait_ms(50);
                tap_code_delay(KC_1, 50);
                tap_code(KC_ENT);
            }
            return false;
        case KC_PC2:
            if (record->event.pressed) {
                tap_code_delay(KC_SLCK, 50);
                wait_ms(50);
                tap_code_delay(KC_2, 50);
                tap_code(KC_ENT);
            }
            return false;
        case KC_PC3:
            if (record->event.pressed) {
                tap_code_delay(KC_SLCK, 50);
                wait_ms(50);
                tap_code_delay(KC_3, 50);
                tap_code(KC_ENT);
            }
            return false;
        case KC_PC4:
            if (record->event.pressed) {
                tap_code_delay(KC_SLCK, 50);
                wait_ms(50);
                tap_code_delay(KC_4, 50);
                tap_code(KC_ENT);
            }
            return false;
    }
    return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(layer_state)) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MACR:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
}
