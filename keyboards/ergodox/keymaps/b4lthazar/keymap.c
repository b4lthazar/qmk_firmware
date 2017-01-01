// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

// Layer names
#define _QW 0 // QWERTY
#define _LW 1 // LOWERED
#define _RS 2 // RAISED
#define _FN 3 // FUNCTION LAYER
#define _DL _QW // DEFAULT LAYER

#define _RSHT_ESC 4

// Some aliases just for clarity
#define ________ KC_NO
#define OOOOOOOO KC_TRNS
#define KC_LCMD  KC_LGUI
#define KC_RCMD  KC_RGUI
#define KC_LOPT  KC_LALT
#define KC_ROPT  KC_RALT

//------------------------------------------------------------------------------
// Keymap defines
//------------------------------------------------------------------------------

#define SHFT_ESC SFT_T(KC_ESC)    // Hold for shift, tap for escape
#define RSHT_ESC F(_RSHT_ESC)     // Hold for right shift, tap for escape
#define BL_MAC   M(0)             // Backlight macro is macro 0
#define PARENS   M(1)             // Insert parens
#define BRACKS   M(2)             // Insert square brackets
#define BRACES   M(3)             // Insert curly braces
#define SLEP     M(4)             // Sleep laptop display on OSX
#define SLEP2    M(5)             // Sleep display on OSX
#define FAT_ARR  M(6)             // Inserts () =>
#define PSCR1    LGUI(LSFT(KC_3)) // Print screen on OSX
#define PSCR2    LGUI(LSFT(KC_4)) // Print screen on OSX with bounding box

// These have to be functions for some reason
#define MO_TG_LW F(_LW)
#define MO_TG_RS F(_RS)
#define MO_TG_FN F(_FN)

// Go to various layers
// Using ON_PRESS actually does a temporary switch, perhaps this could be used later?
#define GO_TO_DL TO(_DL, ON_RELEASE) // Go to default layer
#define GO_TO_QW TO(_QW, ON_RELEASE) // Go to qwerty layer
#define GO_TO_LW TO(_LW, ON_RELEASE) // Go to lower layer
#define GO_TO_RS TO(_RS, ON_RELEASE) // Go to raise layer
#define GO_TO_FN TO(_FN, ON_RELEASE) // Go to fn layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QW] = KEYMAP(
  // layer 0 : Qwerty
  // left hand
  //  ,--------------------------------------------------.
  //  |  ____  | ____ | ____ | ____ | ____ | ____ | ____ |
  //  |--------+------+------+------+------+-------------|
  //  | Tab    |   Q  |   W  |   E  |   R  |   T  | ____ |
  //  |--------+------+------+------+------+------|      |
  //  | BkSp   |   A  |   S  |   D  |   F  |   G  |------|
  //  |--------+------+------+------+------+------| ____ |
  //  |LSft/esc|   Z  |   X  |   C  |   V  |   B  |      |
  //  `--------+------+------+------+------+-------------'
  //    | CTRL |  OPT | f(3) | f(1) |  CMD |
  //    `----------------------------------'
  //                                         ,-------------.
  //                                         | ____ | ____ |
  //                                  ,------|------|------|
  //                                  |      |      | Home |
  //                                  | Space| ____ |------|
  //                                  |      |      | End  |
  //                                  `--------------------'

  ________, ________, ________, ________, ________, ________, ________,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     ________,
  KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  SHFT_ESC, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     ________,
  KC_LCTL,  KC_LOPT,  MO_TG_FN, MO_TG_LW, KC_LCMD,

                                                    ________, ________,
                                                              KC_HOME,
                                          KC_SPC,   ________, KC_END,

  //----------------------------------------------------------------------------

  // right hand
  //   ,--------------------------------------------------.
  //   | ____ | ____ | ____ | ____ | ____ | ____ |  ____  |
  //   |------+------+------+------+------+------+--------|
  //   | ____ |   Y  |   U  |   I  |   O  |   P  |   ()   |
  //   |      |------+------+------+------+------+--------|
  //   |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  //   | ____ |------+------+------+------+------+--------|
  //   |      |   N  |   M  |   ,  |   .  |   /  |RSft/esc|
  //   `-------------+------+------+------+------+--------'
  //                 | Ent  | f(2) |  []  |  {}  | ____ |
  //                 `----------------------------------'
  // ,-------------.
  // | ____ | ____ |
  // |------|------|------.
  // | PgUp |      |      |
  // |------| ____ | Space|
  // | PgDn |      |      |
  // `--------------------'

  ________, ________, ________, ________,  ________, ________, ________,
  ________, KC_Y,     KC_U,     KC_I,      KC_O,     KC_P,     PARENS,
            KC_H,     KC_J,     KC_K,      KC_L,     KC_SCLN,  KC_QUOT,
  ________, KC_N,     KC_M,     KC_COMM,   KC_DOT,   KC_SLSH,  RSHT_ESC,
                      KC_ENT,   MO_TG_RS,  BRACKS,   BRACES,   ________,
  ________, ________,
  KC_PGUP,
  KC_PGDN,  ________, KC_SPC
),

[_LW] = KEYMAP(
  // layer 1 : Lowered
  // left hand
  //  ,--------------------------------------------------.
  //  |        |      |      |      |      |      |      |
  //  |--------+------+------+------+------+-------------|
  //  |    `   |   1  |   2  |   3  |   4  |   5  |      |
  //  |--------+------+------+------+------+------|      |
  //  |        |   _  |   +  |   {  |   }  |   |  |------|
  //  |--------+------+------+------+------+------|      |
  //  |        |   ~  | ____ | ____ | ____ | ____ |      |
  //  `--------+------+------+------+------+-------------'
  //    |      |      | g(3) | g(0) |      |
  //    `----------------------------------'
  //                                         ,-------------.
  //                                         |      |      |
  //                                  ,------|------|------|
  //                                  |      |      |      |
  //                                  |      |      |------|
  //                                  |      |      |      |
  //                                  `--------------------'

  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     OOOOOOOO,
  OOOOOOOO, KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
  OOOOOOOO, KC_TILD,  ________, ________, ________, ________, OOOOOOOO,
  OOOOOOOO, OOOOOOOO, GO_TO_FN, GO_TO_DL, OOOOOOOO,

                                                    OOOOOOOO, OOOOOOOO,
                                                              OOOOOOOO,
                                          OOOOOOOO, OOOOOOOO, OOOOOOOO,

  //----------------------------------------------------------------------------

  // right hand
  //   ,--------------------------------------------------.
  //   |      |      |      |      |      |      |        |
  //   |------+------+------+------+------+------+--------|
  //   |      |   6  |   7  |   8  |   9  |   0  | () =>  |
  //   |      |------+------+------+------+------+--------|
  //   |------| ____ |   -  |   =  |   {  |   }  |   \    |
  //   |      |------+------+------+------+------+--------|
  //   |      | ____ |   `  |      |      |      |        |
  //   `-------------+------+------+------+------+--------'
  //                 |      | g(2) |      |      | g(0) |
  //                 `----------------------------------'
  // ,-------------.
  // |      |      |
  // |------|------|------.
  // |      |      |      |
  // |------|      |      |
  // |      |      |      |
  // `--------------------'

  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
  OOOOOOOO, KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     FAT_ARR,
            ________, KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
  OOOOOOOO, ________, KC_GRV,   OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
                      OOOOOOOO, GO_TO_RS, OOOOOOOO, OOOOOOOO, GO_TO_DL,

  OOOOOOOO, OOOOOOOO,
  OOOOOOOO,
  OOOOOOOO, OOOOOOOO, OOOOOOOO
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
