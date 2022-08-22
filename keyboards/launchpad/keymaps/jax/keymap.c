#include QMK_KEYBOARD_H

// float my_song[][2] = SONG(FANTASIE_IMPROMPTU);



// make launchpad/rev1:jax:dfu-util

/**
 * TAPDANCE
 */
// enum tapdance_keycodes {
//     UNDO_REDO
// };

/**
 * Macros
 */
enum macros_keycodes {
    JAX_EMAIL = SAFE_RANGE,
    JAX_AWESOME,
    JAX_GOLDEN,
    E_LAUGH,
    AAA,
    SWORD_FACE,
};

// #define UNDO LGUI(KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------.
 * |   1  |  2   |
 * |------+------|
 * |   3  |  4   |
 * |------+------|
 * |   5  |  6   |
 * |------+------|
 * | FUNC |  8   |
 * `-------------'
 */
[0] = LAYOUT( \
    SWORD_FACE, AAA, \
    E_LAUGH, JAX_GOLDEN, \
    JAX_AWESOME, JAX_EMAIL, \
    MO(1), MO(1)  \
),

/* Function
 * ,-------------.
 * |   Q  |CALDEL|
 * |------+------|
 * |   A  |TSKMGR|
 * |------+------|
 * |   Z  |  X   |
 * |------+------|
 * |      |  C   |
 * `-------------'
 */
[1] = LAYOUT( \
    RESET, _______, \
    MU_TOG, MU_MOD, \
    _______, _______, \
    _______, _______ \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case JAX_EMAIL:
        if (record->event.pressed) {
            SEND_STRING("jaxsun.parker@gmail.com");
        }
        return false;        
    case JAX_AWESOME:
        if (record->event.pressed) {
            SEND_STRING("JaxIsAwesome6!");
        }
        return false;        
    case JAX_GOLDEN:
        if (record->event.pressed) {
            SEND_STRING("goldencard386!");
        }
        return false;        
    case E_LAUGH:
        if (record->event.pressed) {
            SEND_STRING("/e laugh");
            tap_code(KC_ENT);
        }
        return false;        
    case AAA:
        if (record->event.pressed) {
            tap_code(KC_B);
            tap_code(KC_6);
        }
        return false;
    case SWORD_FACE:
        if (record->event.pressed) {
            SEND_STRING("xD xD xD");
        }
        return false;
  }
  return true;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // [UNDO_REDO] = ACTION_TAP_DANCE_DOUBLE(UNDO, REDO)
};

void matrix_init_user(void) {

}
