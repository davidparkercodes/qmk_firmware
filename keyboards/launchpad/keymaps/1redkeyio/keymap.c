// Below layout is based upon /u/That-Canadian's planck layout
#include QMK_KEYBOARD_H

float my_song[][2] = SONG(FANTASIE_IMPROMPTU);

/**
 * TAPDANCE
 */
enum tapdance_keycodes {
    UNDO_REDO
};

/**
 * Macros
 */
enum zmacros_keycodes {
    TEST = SAFE_RANGE,
    SELECT_COPY,
    SELECT_PASTE,
    COPYLINEDOWN
};

#define UNDO LGUI(KC_Z)
#define REDO LSFT(LGUI(KC_Z))
#define SCREENSHOT LSFT(LGUI(KC_4))
#define MOVE_LINE_UP LALT(KC_UP)
#define MOVE_LINE_DOWN LALT(KC_DOWN)
#define DELETE_ROW LSFT(LGUI(KC_K))
#define SAVE_FOR_WEB LSFT(LGUI(LALT(KC_W)))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Mac
[0] = LAYOUT( \
    TG(2), TD(UNDO_REDO), \
    DELETE_ROW, SELECT_PASTE, \
    SCREENSHOT, SELECT_COPY, \
    MO(1),   COPYLINEDOWN  \
),

// Mac 2
[1] = LAYOUT( \
    SAVE_FOR_WEB, _______, \
    _______, _______, \
    MOVE_LINE_UP, MOVE_LINE_DOWN, \
    _______, RESET \
),

// Linux 1
[2] = LAYOUT( \
    TG(2), KC_I, \
    KC_UNDS, KC_PLUS, \
    KC_RBRC, KC_LBRC, \
    KC_RCBR, KC_LCBR \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SELECT_COPY:
        // Select word under cursor and copy. Double mouse click then cmd+c
        if (record->event.pressed) {
            tap_code16(KC_BTN1);
            tap_code16(KC_BTN1);
            tap_code16(LGUI(KC_C));
        }
        return false;
    case SELECT_PASTE:
        // Select word under cursor and copy. Double mouse click then cmd+v
        if (record->event.pressed) {
            tap_code16(KC_BTN1);
            tap_code16(KC_BTN1);
            tap_code16(LGUI(KC_V));
        }
        return false;
    case COPYLINEDOWN:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_LSFT);
            tap_code16(KC_DOWN);
            unregister_code(KC_LALT);
            unregister_code(KC_LSFT);
        }
        return false;
    case TEST:
        if (record->event.pressed) {
            PLAY_SONG(my_song);
        }
        return false;
        
  }
  return true;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [UNDO_REDO] = ACTION_TAP_DANCE_DOUBLE(UNDO, REDO)
};

void matrix_init_user(void) {

}
