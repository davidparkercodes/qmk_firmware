#include QMK_KEYBOARD_H

// &&&&&&&&&&&&&&&&&&&&&&&& make lily58/rev1:redkeyio
// &&& qmk compile -kb lily58/rev1 -km redkeyio

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
#include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number
{
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMERRR
};

// Macros
enum macros_keycodes
{
  IAMWEALTHYANDHAPPY = SAFE_RANGE,
  SELECT_COPY,
  SELECT_PASTE
};

// LTs
#define LT_LOWER_ENT LT(_LOWER, KC_ENT)
#define LT_RAISE_SPACE LT(_RAISE, KC_SPACE)

// MTs
#define MT_ALT_SPACE MT(MOD_LALT, KC_SPACE)
#define MT_LGUI_DEL MT(MOD_LGUI, KC_DEL)

// Macros
#define COPY_LINE_UP LSA(KC_UP)
#define COPY_LINE_DOWN MEH(KC_DOWN)
#define MOVE_LINE_UP LALT(KC_UP)
#define MOVE_LINE_DOWN LALT(KC_DOWN)

// BetterSnapTool Window Positioning
// #define MEH_K MEH(KC_F11)
// #define MIDDLE_THIRD MEH(KC_F12)
// #define RIGHT_THIRD MEH(KC_F13)
// #define LEFT_HALF MEH(KC_F14)
// #define RIGHT_HALF MEH(KC_F15)
// #define TOP_LEFT_QUARTER MEH(KC_F16)
// #define TOP_RIGHT_QUARTER MEH(KC_F17)
// #define BOTTOM_LEFT_QUARTER MEH(KC_F18)
// #define BOTTOM_RIGHT_QUARTER MEH(KC_F19)

// Open Apps - Automater and Mac Keyboard Shortcuts
// #define CHROME HYPR(KC_F11)
// #define PHOTOSHOP HYPR(KC_F12)
// #define TRANSMIT HYPR(KC_F13)
// #define ESPRESSO HYPR(KC_F14)
// #define VSCODE HYPR(KC_F15)
// #define FINDER HYPR(KC_F16)
// #define TERMINAL HYPR(KC_F17)
// #define POSTBOX HYPR(KC_F18)
// #define CALENDAR HYPR(KC_F19)
// #define BRINGALLTOFRONT HYPR(KC_F10)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Enter /       \Space \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_QWERTY] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4,                       KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LCTRL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LEAD,      KC_LEAD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        MT_ALT_SPACE, MT_LGUI_DEL, KC_BSPC, LT_LOWER_ENT,     LT_RAISE_SPACE, KC_BSPC, KC_LALT, KC_RGUI),

/*
 * RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [_RAISE] = LAYOUT(
        KC_1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                                                KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        HYPR(KC_F11), HYPR(KC_F12), HYPR(KC_F13), HYPR(KC_F14), HYPR(KC_F15),                   _______, _______, _______, _______, _______, _______, _______,
        HYPR(KC_F16), HYPR(KC_F17), HYPR(KC_F18), HYPR(KC_F19), HYPR(KC_F20), TO(_GAMERRR),     KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______,
        HYPR(KC_F21), HYPR(KC_F22), _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _LOWER,                                                     _RAISE, _______, _______, _______),
/*
 * LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      | RESET|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   |  |   =  |  [   |   ]  |                    |      |  7   |  8   |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   \  |   +  |  {   |   }  |-------.    ,-------|      |   4  |  5   |   6  |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |  +-^ |  -^  |  -v  |  +-v |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \   0  \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_LOWER] = LAYOUT(
        MEH(KC_F11), MEH(KC_F12), MEH(KC_F13), SELECT_COPY, SELECT_PASTE, RESET,                _______, _______, _______, _______, _______, RESET,
        MEH(KC_F14), MEH(KC_F15), KC_PIPE, KC_EQUAL, KC_LBRC, KC_RBRC,                            _______, KC_7, KC_8, KC_9, _______, _______,
        MEH(KC_F16), MEH(KC_F17), KC_BSLS, KC_PLUS, KC_LCBR, KC_RCBR,                             _______, KC_4, KC_5, KC_6, _______, _______,
        MEH(KC_F18), MEH(KC_F19), COPY_LINE_UP, MOVE_LINE_DOWN, MOVE_LINE_UP, COPY_LINE_DOWN,     _______, KC_1, KC_2, KC_3, _______, _______, _______, _______,
        MEH(KC_F20), MEH(KC_F21), _______, _LOWER,                                           _RAISE, KC_0, _______, _______),

/*
 * ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,      TO(_GAMERRR), _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, IAMWEALTHYANDHAPPY, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,                        _______, _______, _______, _______),

/* GAMERRR
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
    [_GAMERRR] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4,                       KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                 KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LCTRL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LEAD,      KC_LEAD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TO(_QWERTY),
        MT_ALT_SPACE, MT_LGUI_DEL, KC_BSPC, KC_ENT,           KC_SPACE, KC_BSPC, KC_LALT, KC_RGUI)};

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3)
{
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2))
  {
    layer_on(layer3);
  }
  else
  {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
  if (!is_keyboard_master())
    return OLED_ROTATION_180; // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// Red Key Custom OLED
const char *custom_line_1(void);
const char *custom_line_2(void);
const char *custom_line_3(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void)
{
  if (is_keyboard_master())
  {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    // oled_write_ln(read_keylog(), false);
    // oled_write_ln(read_keylogs(), false);

    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);

    oled_write_ln(custom_line_1(), false);
    oled_write_ln(custom_line_2(), false);
    oled_write_ln(custom_line_3(), false);
  }
  else
  {
    oled_write(read_logo(), false);
  }

  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
  {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();

    switch (keycode)
    {
    case IAMWEALTHYANDHAPPY:
      if (record->event.pressed)
      {
        SEND_STRING("iamwealthyandhappy");
        tap_code(KC_ENT);
      }
      return false;
    case SELECT_COPY:
      // Select word under cursor and copy. Double mouse click then cmd+c
      if (record->event.pressed)
      {
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(LCTL(KC_C));
      }
      return false;
    case SELECT_PASTE:
      // Select word under cursor and copy. Double mouse click then cmd+v
      if (record->event.pressed)
      {
        tap_code16(KC_BTN1);
        tap_code16(KC_BTN1);
        tap_code16(LCTL(KC_V));
      }
      return false;
    }
  }
  return true;
}

// Adjust layer
uint32_t layer_state_set_user(uint32_t state)
{
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Encoder
// void encoder_update_user(uint8_t index, bool clockwise)
// {
//   if (index == 0)
//   {
//     if (clockwise)
//     {
//       tap_code(KC_PGDN);
//     }
//     else
//     {
//       tap_code(KC_PGUP);
//     }
//   }
// }

// Leader Key
/*
LEADER_EXTERNS();

void matrix_scan_user(void)
{
  LEADER_DICTIONARY()
  {
    leading = false;
    leader_end();

    // Emails
    SEQ_TWO_KEYS(KC_E, KC_1)
    {
      SEND_STRING("david@redkey.io");
    }
    SEQ_TWO_KEYS(KC_E, KC_2)
    {
      SEND_STRING("chrezar@gmail.com");
    }

    // Make Keyboard (mk)
    // SEQ_TWO_KEYS(KC_M, KC_K)
    // {
    //   tap_code16(TERMINAL);
    //   _delay_ms(1000);
    //   SEND_STRING("cd Documents/GitHub/keebs");
    //   tap_code(KC_ENT);
    //   SEND_STRING("make lily58/rev1:redkeyio:dfu");
    //   tap_code(KC_ENT);
    // }

    SEQ_ONE_KEY(KC_F)
    {
      SEND_STRING("QMK is awesome.");
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S)
    {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
  }
}

*/
