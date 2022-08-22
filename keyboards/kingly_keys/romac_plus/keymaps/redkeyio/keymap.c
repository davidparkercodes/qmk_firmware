/* Copyright 2018 Jack Humbert
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

#define L0 0
#define L1 1
#define L2 2
#define L3 3
#define L4 4

/* Start - Tap Dance Toggle Layers */
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    DOUBLE_TAP,
    TRIPLE_TAP,
};

enum {
    TD_TOG_LAY,
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

/* End - Tap Dance Toggle Layers */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [L0] = LAYOUT(
		_______, _______, _______,
		_______, _______, _______,
		_______, _______, _______,
		_______, _______, MO(L1)
	),
  
  [L1] = LAYOUT(
		TO(2), TO(3), TO(4),
		_______, _______, _______,
		_______, _______, _______,
		_______, _______, MO(L1)
	),
  
	[L2] = LAYOUT(
		KC_7, KC_8, KC_9,
		KC_4, KC_5, KC_6,
		KC_1, KC_2, KC_3,
		TO(0), KC_0, MO(L1)
	),
  
	[L3] = LAYOUT(
		TD(TD_TOG_LAY), KC_A, KC_B,
		_______, _______, _______,
		_______, _______, _______,
		TO(0), _______, MO(L1)
	),
  
  [L4] = LAYOUT(
		TD(TD_TOG_LAY), KC_C, KC_D,
		_______, _______, _______,
		_______, _______, _______,
		TO(0), _______, MO(L1)
	)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  // Host Keyboard Layer Status
  
  switch (get_highest_layer(layer_state)) {
    case L0:
      oled_write_ln_P(PSTR("None"), false);
      break;
    case L1:
      oled_write_ln_P(PSTR("Sel-"), false);
      break;
    case L2:
      oled_write_ln_P(PSTR("NumP"), false);
      break;
    case L3:
      oled_write_ln_P(PSTR("L3"), false);
      break;
    case L4:
      oled_write_ln_P(PSTR("L4"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      oled_write_ln_P(PSTR("Undef"), false);
  }
  
  oled_write_ln_P(PSTR(""), false);
  
  oled_write_P(PSTR("Time\nTo\nGrind"), false);

  // Host Keyboard LED Status
  // uint8_t led_usb_state = host_keyboard_leds();
  // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NLCK ") : PSTR("     "), false);
  // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS ") : PSTR("       "), false);
  // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLK") : PSTR("       "), false);
}
#endif




// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
  switch (state->count) {
        case 1:
            return SINGLE_TAP;
        case 2:
            return DOUBLE_TAP;
        case 3:
            return TRIPLE_TAP;
    }
    return 8;
}

static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
            if (layer_state_is(L2)) {
                layer_off(L2);
            } else {
                layer_on(L2);
            }
            break;
        case DOUBLE_TAP:
            if (layer_state_is(L3)) {
                layer_off(L3);
            } else {
                layer_on(L3);
            }
            break;
        case TRIPLE_TAP:
            if (layer_state_is(L4)) {
                layer_off(L4);
            } else {
                layer_on(L4);
            }
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = 0;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_TOG_LAY] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
};