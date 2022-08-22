/* Copyright 2019 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

/**
 * TAPDANCE
 */
enum tapdance_keycodes {
    I3_WINDOW_LEFT,
    I3_WINDOW_DOWN,
    I3_WINDOW_UP,
    I3_WINDOW_RIGHT,
    MAKE_WINDOW_VERT_HORZ
};

/**
 * MACROS
 */
enum macros_keycodes {
    SWITCH_WINDOW = SAFE_RANGE,
    MOUSE_CENTER,
    SWITCH_CENTER,
    SELECT_COPY_CTL,
    SELECT_PASTE_CTL,
    PRINTRPRE
};

/**
***********************************
 * Mac OSX
 **/

/**
 * Open Apps
 **/
#define CHROME HYPR(KC_F1)
#define BRAVE HYPR(KC_F2)
#define TOGGLE HYPR(KC_F3)
#define POSTBOX HYPR(KC_F4)
#define VSCODE HYPR(KC_F5)
#define FINDER HYPR(KC_F6)
#define TRANSMIT HYPR(KC_F7)
#define TERMINAL HYPR(KC_F8)
#define ESPRESSO HYPR(KC_F9)
#define TEXTEDIT HYPR(KC_F10)
#define PS HYPR(KC_F11)
#define GMUSIC HYPR(KC_F12)

/**
 * Managing Widnows
 **/
#define HIDE_WINDOW LGUI(KC_H)
#define CENTER_WINDOW MEH(KC_F1)
#define FULL_WINDOW MEH(KC_F2)

// One Half
#define L_ONEHALF MEH(KC_F3)
#define B_ONEHALF MEH(KC_F4)
#define T_ONEHALF MEH(KC_F5)
#define R_ONEHALF MEH(KC_F6)

// One Fourth Rectangle
#define TL_ONEFOURTH MEH(KC_F7)
#define TR_ONEFOURTH MEH(KC_F8)
#define BL_ONEFOURTH MEH(KC_F9)
#define BR_ONEFOURTH MEH(KC_F10)

// Two Thirds
#define L_TWOTHIRDS MEH(KC_F11)
#define R_TWOTHIRDS MEH(KC_F12)

// One Third
#define L_ONETHIRD MEH(KC_A)
#define M_ONETHIRD MEH(KC_B)
#define R_ONETHIRD MEH(KC_C)

// One Sixth
#define TL_ONESIXTH MEH(KC_D)
#define TM_ONESIXTH MEH(KC_E)
#define TR_ONESIXTH MEH(KC_F)
#define BL_ONESIXTH MEH(KC_G)
#define BM_ONESIXTH MEH(KC_H)
#define BR_ONESIXTH MEH(KC_I)

// One Fourth Tall
#define L_ONEFOURTHTALL MEH(KC_J)
#define R_ONEFOURTHTALL MEH(KC_K)

/**
***********************************
 * Linux
 **/

// Macros
#define COPY_LINE_UP MEH(KC_UP)
#define COPY_LINE_DOWN MEH(KC_DOWN) 
#define MOVE_LINE_UP LALT(KC_UP)
#define MOVE_LINE_DOWN LALT(KC_DOWN) 
#define UNDO LCTL(KC_Z) 
#define REDO LCTL(LSFT(KC_Z)) 

// Bottom row -- 2nd from left first and then first from left to reset
// ----
// ----
// ----
// 21--

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  //
  // LINUX 1
  [0] = LAYOUT_ortho_4x4( 
    COPY_LINE_UP, MOVE_LINE_UP, SELECT_COPY_CTL, SELECT_PASTE_CTL,
    COPY_LINE_DOWN, MOVE_LINE_DOWN, UNDO, REDO,
    KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,
    KC_EQUAL, KC_PLUS, _______, MO(1)
  ),
  //
  // LINUX 2
  [1] = LAYOUT_ortho_4x4( 
    PRINTRPRE, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, RESET, _______, _______
  ),
  
  //
  // Mac OS X Apps
  // [0] = LAYOUT_ortho_4x4( 
  //   CHROME,       BRAVE,        TOGGLE,       POSTBOX,
  //   VSCODE,       FINDER,       TRANSMIT,     TERMINAL,
  //   ESPRESSO,     TEXTEDIT,     PS,           GMUSIC,
  //   MO(1),        MO(2),        HIDE_WINDOW,  SWITCH_CENTER
  // ),
  // //
  // // Mac OS X Window Management 1
  // [1] = LAYOUT_ortho_4x4( 
  //   L_ONEHALF,     B_ONEHALF,       T_ONEHALF,       R_ONEHALF,
  //   TL_ONEFOURTH,  TR_ONEFOURTH,    BL_ONEFOURTH,    BR_ONEFOURTH,
  //   CENTER_WINDOW, FULL_WINDOW,     L_TWOTHIRDS,     R_TWOTHIRDS,
  //   _______,       L_ONETHIRD,      M_ONETHIRD,      R_ONETHIRD
  // ),
  // //
  // // Mac OS X Window Management 2
  // [2] = LAYOUT_ortho_4x4( 
  //   TL_ONESIXTH,   TM_ONESIXTH,   TR_ONESIXTH,   L_ONEFOURTHTALL,
  //   BL_ONESIXTH,   BM_ONESIXTH,   BR_ONESIXTH,   R_ONEFOURTHTALL,
  //   _______,       _______,       RGB_MOD,       RGB_RMOD,
  //   RESET,       _______,         TG(3),       RGB_TOG
  // ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SWITCH_WINDOW:
        if (record->event.pressed) {
            tap_code16(LGUI(KC_GRAVE));
        }
        return false;
    case MOUSE_CENTER:
        if (record->event.pressed) {
            tap_code16(HYPR(KC_A));
        }
        return false;
    case SWITCH_CENTER:
        if (record->event.pressed) {
            tap_code16(LGUI(KC_GRAVE));
            tap_code16(HYPR(KC_A));
        }
        return false;
    case SELECT_COPY_CTL:
        if (record->event.pressed) {
            tap_code(KC_BTN1);
            wait_ms(50);
            tap_code(KC_BTN1);
            tap_code16(LCTL(KC_C));
        }
        return false;
    case SELECT_PASTE_CTL:
        if (record->event.pressed) {
            tap_code(KC_BTN1);
            wait_ms(50);
            tap_code(KC_BTN1);
            tap_code16(LCTL(KC_V));
        }
        return false;
      case PRINTRPRE:
        if (record->event.pressed) {
            SEND_STRING("echo '<pre>',print_r($arr,1),'</pre>';");
        }
        return false;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}


qk_tap_dance_action_t tap_dance_actions[] = {
    [I3_WINDOW_LEFT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_H), LGUI(LSFT(KC_H))),
    [I3_WINDOW_DOWN] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_J), LGUI(LSFT(KC_J))),
    [I3_WINDOW_UP] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_K), LGUI(LSFT(KC_K))),
    [I3_WINDOW_RIGHT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_L), LGUI(LSFT(KC_L))),
    [MAKE_WINDOW_VERT_HORZ] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_M), LGUI(KC_N))
};