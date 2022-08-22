#include QMK_KEYBOARD_H

// make keebio/iris/rev4:1redkeyio

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _LINUX 4
#define _KEYPADandSYM 5
#define _MEDIAandLED 6
#define _GAMER 7
#define _TEMP1 8
#define _TEMP2 9

#define LT_LOWER_SPACE LT(_LOWER, KC_SPC)
#define LT_RAISE_BCKSPACE LT(_RAISE, KC_BSPC)
#define LT_KEYPADandSYM_BCKSPACE LT(_KEYPADandSYM, KC_BSPC)
#define LT_MEDIAandLED_ENT LT(_MEDIAandLED, KC_ENT)
#define MT_ALT_TAB MT(MOD_RALT, KC_TAB)
#define MT_CTL_MINUS MT(MOD_RCTL, KC_MINUS)
#define MT_LCTL_BCKSPACE MT(MOD_LCTL, KC_BSPC)
#define MT_ALT_DEL MT(MOD_RALT, KC_DEL)
// #define MT_SHIFT_SPC MT(MOD_RSFT, KC_SPC)


#define LT_LOWER_LBRC LT(_LOWER, KC_LBRC)
#define LT_RAISE_RBRC LT(_RAISE, KC_RBRC)
#define LT_TEMP1_BSPC LT(_TEMP1, KC_BSPC)
#define LT_TEMP2_DEL LT(_TEMP2, KC_DEL)
#define MT_LGUI_ENT MT(MOD_LGUI, KC_ENT)
#define MT_LCTL_SPACE MT(MOD_LCTL, KC_SPACE)
#define MT_ALT_EQUAL MT(MOD_LALT, KC_EQUAL)
#define MT_ALT_BSPC MT(MOD_LALT, KC_BSPC)

/**
 * TAPDANCE
 */
enum tapdance_keycodes {
    ESC_or_BACKTICK,
    NULL_or_ESC,
    SFT_LCK,
    ONEHALF_TWOTHIRD,
    ONEFOURTH_MOVELEFT,
    FULLSCREEN_MOVERIGHT,
    ONE_SIX,
    TWO_SEVEN,
    THREE_EIGHT,
    FOUR_NINE,
    FIVE_ZERO
};

/**
 * MACROS
 */
enum macros_keycodes {
    IAMWEALTHYANDHAPPY = SAFE_RANGE,
    PRINTRPRE,
    SELECT_COPY_ALL,
    SELECT_COPY,
    SELECT_PASTE,
    MAKEKEYBOARDFIRMWARE,
    EQUALX3,
    EXCLAIMEQUALX2,
    DASHGT,
    PHPTHIS,
    GITADDALL,
    GITCOMMITM,
    GITPUSHORIGMAST,
    GITSTATUS,
    PARANSEMCOL,
    CODECOMMENT,
    CODECOMMENTBIG,
    EQUALGT,
    COPYLINEDOWN,
    SWITCH_CENTER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    TD(ESC_or_BACKTICK), KC_1, KC_2, KC_3, KC_4, KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQUAL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  MT_LGUI_ENT,           _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(SFT_LCK),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
      MT_ALT_BSPC, LT_LOWER_LBRC,   MT_LCTL_SPACE,                      KC_SPACE,  LT_RAISE_RBRC,   MT_ALT_EQUAL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),  
  
  // 9/16/20 backup
  // [_QWERTY] = LAYOUT(
  // //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
  //   TD(ESC_or_BACKTICK), KC_1, KC_2, KC_3, KC_4, KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  // //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //    MT_ALT_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  // //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
  //    KC_EQUAL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  // //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  //    KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  LT_MEDIAandLED_ENT,           _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(SFT_LCK),
  // //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
  //     KC_LGUI, LT_LOWER_SPACE,   MT_LCTL_BCKSPACE,                      KC_SPC,  LT_RAISE_BCKSPACE,   MT_ALT_DEL
  //                               // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  // ),  

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                 KC_F12,  KC_F13,  _______, KC_PSLS,  KC_PAST, KC_HOME,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,   _______,  _______, _______,  _______,  KC_PIPE,                             KC_DOT,    KC_P7,   KC_P8,   KC_P9,    KC_EQL,  KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______,   _______,  _______, KC_DEL,  _______,  KC_BSLS,                              _______,   KC_P4,   KC_P5,    KC_P6,   KC_PLUS,  KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  _______,  _______, _______,  _______,  _______, _______,             _______, _______,  KC_P1,   KC_P2,    KC_P3,   KC_MINS,  KC_END,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                            _______, _______, _______,                          _______, _______,         KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG(_GAMER),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     GITADDALL,   GITSTATUS,  _______, _______,  PHPTHIS,  PRINTRPRE,                            KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_HOME, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     GITCOMMITM,   _______,  EXCLAIMEQUALX2, EQUALX3,  DASHGT,  PARANSEMCOL,                            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_END, KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     GITPUSHORIGMAST, _______, _______, CODECOMMENT, EQUALGT, CODECOMMENTBIG, KC_LEAD,       _______, _______, _______,  _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RALT, _______, _______,                   _______, _______, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐

     KC_MEH, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, IAMWEALTHYANDHAPPY, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, MAKEKEYBOARDFIRMWARE, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_TEMP1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐

     _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_TEMP2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐

     _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_KEYPADandSYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  _______,   _______,   _______,   _______,   _______,                             _______, KC_PLUS, KC_EQL, KC_LT, KC_GT,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                            _______, KC_RPRN, KC_RBRC, KC_RCBR, KC_UNDS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                                             _______,  KC_LPRN, KC_LBRC, KC_LCBR, KC_MINS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,   _______, _______, _______, _______, _______, _______,     _______,   _______,   KC_COLN,  KC_SCLN,  KC_BSLS, KC_PIPE, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MEDIAandLED] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  RGB_M_P,   RGB_M_B,   RGB_M_R,   RGB_M_SW,   RGB_M_SN,                        RGB_M_K,   RGB_M_X,   RGB_M_G,   RGB_M_T,   _______,  KC_VOLU,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______,   _______, _______,  _______,                            _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_VOLD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______,  RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, RGB_TOG,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
    
  [_GAMER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    TD(NULL_or_ESC), KC_1, KC_2, KC_3, KC_4, KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQUAL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSHIFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,             KC_ENT,             _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TD(SFT_LCK),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_LALT, KC_SPC,  KC_LCTL,                     KC_SPC,  TG(_GAMER),   KC_DEL
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

    //   [_MOUSE] = LAYOUT(
    //   //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
    //      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    //      _______, KC_MS_BTN2, KC_MS_UP, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //   //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    //      _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    //      KC_MS_BTN1, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //   //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
    //                                     _______, _______, _______,                   _______, _______, _______
    //                                 // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    //   ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PRINTRPRE:	
        if (record->event.pressed) {	
            SEND_STRING("echo '<pre>',print_r($arr,1),'</pre>';");	
        }	
        return false;
    case SELECT_COPY_ALL:
        // Selects all and text and copy
        if (record->event.pressed) {
            tap_code16(LGUI(KC_A));
            tap_code16(LGUI(KC_C));
        }
        return false;
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
    case IAMWEALTHYANDHAPPY:
        if (record->event.pressed) {
            SEND_STRING("iamwealthyandhappy");
            tap_code(KC_ENT);
        }
        return false;
    case EQUALX3:
        if (record->event.pressed) {
            SEND_STRING("===");
        }
        return false;
    case EXCLAIMEQUALX2:
        if (record->event.pressed) {
            SEND_STRING("!==");
        }
        return false;
    case DASHGT:
        if (record->event.pressed) {
            SEND_STRING("->");
        }
        return false;
    case PHPTHIS:
        if (record->event.pressed) {
            SEND_STRING("$this->");
        }
        return false;        
    case GITADDALL:
        if (record->event.pressed) {
            SEND_STRING("git add -A");
            tap_code(KC_ENT);
        }
        return false;
    case GITCOMMITM:
        if (record->event.pressed) {
            SEND_STRING("git commit -m ''");
            tap_code16(KC_LEFT);
        }
        return false;
    case GITPUSHORIGMAST:
        if (record->event.pressed) {
            SEND_STRING("git push origin master");
            tap_code(KC_ENT);
        }
        return false;
    case GITSTATUS:
        if (record->event.pressed) {
            SEND_STRING("git status");
            tap_code(KC_ENT);
        }
        return false;
    case PARANSEMCOL:
        if (record->event.pressed) {
            SEND_STRING(");");
        }
        return false;
    case CODECOMMENT:
        if (record->event.pressed) {
            SEND_STRING("/*  */");
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
            tap_code16(KC_LEFT);
        }
        return false;
    case CODECOMMENTBIG:
        if (record->event.pressed) {
            SEND_STRING("/**");
            tap_code16(KC_ENT);
        }
        return false;
    case EQUALGT:
        if (record->event.pressed) {
            SEND_STRING("=>");
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
    case SWITCH_CENTER:
        if (record->event.pressed) {
            tap_code16(LGUI(KC_GRAVE));
            tap_code16(HYPR(KC_F10));
        }
        return false;
    case MAKEKEYBOARDFIRMWARE:
        if (record->event.pressed) {
            tap_code(KC_F13);
            _delay_ms(100); 
            SEND_STRING("terminal");
            _delay_ms(100); 
            tap_code(KC_ENT);
            _delay_ms(500); 
            tap_code16(LGUI(KC_N));
            _delay_ms(100); 
            SEND_STRING("cd Documents/GitHub/keebs");
            tap_code(KC_ENT);
            SEND_STRING("make keebio/iris/rev4:1redkeyio");
            tap_code(KC_ENT);
            tap_code(KC_F13);
            _delay_ms(100);
            SEND_STRING("qmk");
            tap_code(KC_ENT);
        }
        return false;
  }
  return true;
}

//qmk flash -kb iris/rev4 -km 1redkeyio


bool did_leader_succeed;
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;

    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("QMK is awesome.");
      did_leader_succeed = true;
    }
    
    // Delete Row
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LSFT(SS_LGUI("k")));
      did_leader_succeed = true;
    }
    
    // Switch to Chrome and Hard Refresh
    SEQ_TWO_KEYS(KC_R, KC_R) {
       tap_code16(HYPR(KC_F1));
       SEND_STRING(SS_LSFT(SS_LGUI("r")));
       did_leader_succeed = true;
    }
    
    // PHP Print R Pre
    SEQ_TWO_KEYS(KC_Q, KC_Q) {
       SEND_STRING("echo '<pre>',print_r($arr,1),'</pre>';");
       did_leader_succeed = true;
    }
    
    // PHP Foreach Loop
    SEQ_TWO_KEYS(KC_Q, KC_W) {
       SEND_STRING("foreach ($things as $thing) {");
       tap_code16(KC_ENT);
       did_leader_succeed = true;
    }
    
    // Make keyboards
    SEQ_TWO_KEYS(KC_K, KC_1) {
       SEND_STRING("make keebio/iris/rev4:1redkeyio");
       tap_code16(KC_ENT);
       did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_K, KC_2) {
       SEND_STRING("make launchpad/rev1:1redkeyio:dfu-util");
       tap_code16(KC_ENT);
       did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_K, KC_3) {
       SEND_STRING("make 1upkeyboards/super16:1redkeyio:dfu-util");
       tap_code16(KC_ENT);
       did_leader_succeed = true;
    }
    // Address
   //  SEQ_TWO_KEYS(KC_A, KC_1) {
   //    SEND_STRING("1856 Gershwin Dr");
   //    did_leader_succeed = true;
   //  }
   //  SEQ_TWO_KEYS(KC_A, KC_2) {
   //    SEND_STRING("Virginia Beach");
   //    did_leader_succeed = true;
   //  }
   //  SEQ_TWO_KEYS(KC_A, KC_3) {
   //    SEND_STRING("23454");
   //    did_leader_succeed = true;
   //  }
    
    // Emails
    SEQ_TWO_KEYS(KC_E, KC_1) {
      SEND_STRING("chrezar@gmail.com");
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_E, KC_2) {
      SEND_STRING("dave@redkey.io");
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_E, KC_3) {
      SEND_STRING("info@redkeydesigns.com");
      did_leader_succeed = true;
    }
    
    leader_end();
  }
}

void leader_start(void) {
  rgblight_sethsv (HSV_TEAL);
}

void leader_end(void) {
   if (did_leader_succeed) {
      rgblight_sethsv (HSV_PURPLE);
      _delay_ms(300);
      rgblight_sethsv (HSV_GREEN);
   } else {
      rgblight_sethsv (HSV_RED);
      _delay_ms(300); 
      rgblight_sethsv (HSV_GREEN);
   }
}

uint32_t layer_state_set_user(uint32_t state) {
   switch (get_highest_layer(state)) {
      case _RAISE:
         rgblight_sethsv (HSV_RED);
         break;
      case _LOWER:
         rgblight_sethsv (HSV_BLUE);
         break;
      case _ADJUST:
         rgblight_sethsv (HSV_PURPLE);
         break;
      case _LINUX:
         rgblight_sethsv (HSV_TEAL);
         break;
      case _KEYPADandSYM:
         rgblight_sethsv (HSV_ORANGE);
         break;
      case _MEDIAandLED:
         rgblight_sethsv (HSV_PINK);
         break;
      case _GAMER:
         rgblight_sethsv (HSV_CYAN);
         break;
      default:
         rgblight_sethsv (HSV_GREEN);
         break;
   }
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Shift vs. capslock function. From bbaserdem's Planck keymap.
void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
    } else if (state->count == 2) {
        unregister_code (KC_LSFT);
        register_code (KC_CAPS);
    }
}
void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
    } else {
        unregister_code (KC_CAPS);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [ESC_or_BACKTICK] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
    [NULL_or_ESC] = ACTION_TAP_DANCE_DOUBLE(_______, KC_ESC),
    //Tap once for Shift, twice for Caps Lock
    [SFT_LCK] = ACTION_TAP_DANCE_FN_ADVANCED( caps_tap, NULL, caps_tap_end),
    [ONEFOURTH_MOVELEFT] = ACTION_TAP_DANCE_DOUBLE(MEH(KC_F14), MEH(KC_F10)),
    [ONEHALF_TWOTHIRD] = ACTION_TAP_DANCE_DOUBLE(MEH(KC_F15), MEH(KC_F16)),
    [FULLSCREEN_MOVERIGHT] = ACTION_TAP_DANCE_DOUBLE(MEH(KC_F17), MEH(KC_F13)),
    [ONE_SIX] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_6),
    [TWO_SEVEN] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_7),
    [THREE_EIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_8),
    [FOUR_NINE] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_9),
    [FIVE_ZERO] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_0)
};

//  ,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  //  | ESC| 1  | 2  | 3  | 4  | 5  |              | 6  | 7  | 8  | 9  | 0  | -  |
  //  |----+----+----+----+----+----|              |----+----+----+----+----+----|
  //  | TAB| Q  | W  | E  | R  | T  |              | Y  | U  | I  | O  | P  | BSP|
  //  |----+----+----+----+----+----|              |----+----+----+----+----+----|
  //  | CAP| A  | S  | D  | F  | G  |              | H  | J  | K  | L  | ;  | '  |
  //  |----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
  //  | SFT| Z  | X  | C  | V  | B  | SPC|    | SPC| N  | M  | ,  | .  | /  | ENT|
  //  `----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
  //                   \  GUI| ALT| CTL /      \RASE\ CTL | SFT /
  //                    `----+----+----'        `----+----+----'
