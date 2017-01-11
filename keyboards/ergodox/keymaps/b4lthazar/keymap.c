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

#undef TO
#define TO(layer, when) (layer | QK_TO | (when << 0x4))

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
#define CMD_GRV  LGUI(KC_GRV)     // CMD+`

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
  // Layer 0 : Qwerty
  // Left Hand
  // ,--------------------------------------------------.
  // |  ____  | ____ | ____ | ____ | ____ | ____ | ____ |
  // |--------+------+------+------+------+-------------|
  // | Tab    |   Q  |   W  |   E  |   R  |   T  | ____ |
  // |--------+------+------+------+------+------|      |
  // | BkSp   |   A  |   S  |   D  |   F  |   G  |------|
  // |--------+------+------+------+------+------| ____ |
  // |LSft/esc|   Z  |   X  |   C  |   V  |   B  |      |
  // `--------+------+------+------+------+-------------'
  //   | CTRL |  OPT | f(3) | f(1) |  CMD |
  //   `----------------------------------'
  //                                        ,-------------.
  //                                        | ____ | ____ |
  //                                 ,------|------|------|
  //                                 |      |      | Home |
  //                                 | Space| ____ |------|
  //                                 |      |      | End  |
  //                                 `--------------------'

  ________, ________, ________, ________, ________, ________, ________,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     ________,
  KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  SHFT_ESC, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     ________,
  KC_LCTL,  KC_LOPT,  MO_TG_FN, MO_TG_LW, KC_LCMD,

                                                    ________, ________,
                                                              KC_HOME,
                                          KC_SPC,   ________, KC_END,

  //----------------------------------------------------------------------------

  // Right hand
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
  // Layer 1 : Lowered
  // Left Hand
  // ,--------------------------------------------------.
  // |        |      |      |      |      |      |      |
  // |--------+------+------+------+------+-------------|
  // |    `   |   1  |   2  |   3  |   4  |   5  |      |
  // |--------+------+------+------+------+------|      |
  // |        |   _  |   +  |   {  |   }  |   |  |------|
  // |--------+------+------+------+------+------|      |
  // |        |   ~  | ____ | ____ | ____ | ____ |      |
  // `--------+------+------+------+------+-------------'
  //   |      |      | g(3) | g(0) |      |
  //   `----------------------------------'
  //                                        ,-------------.
  //                                        |      |      |
  //                                 ,------|------|------|
  //                                 |      |      |      |
  //                                 |      |      |------|
  //                                 |      |      |      |
  //                                 `--------------------'

  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     OOOOOOOO,
  OOOOOOOO, KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
  OOOOOOOO, KC_TILD,  ________, ________, ________, ________, OOOOOOOO,
  OOOOOOOO, OOOOOOOO, GO_TO_FN, GO_TO_DL, OOOOOOOO,

                                                    OOOOOOOO, OOOOOOOO,
                                                              OOOOOOOO,
                                          OOOOOOOO, OOOOOOOO, OOOOOOOO,

  //----------------------------------------------------------------------------

  // Right hand
  //   ,--------------------------------------------------.
  //   |      |      |      |      |      |      |        |
  //   |------+------+------+------+------+------+--------|
  //   |      |   6  |   7  |   8  |   9  |   0  | () =>  |
  //   |      |------+------+------+------+------+--------|
  //   |------| ____ |   -  |   =  |   [  |   ]  |   \    |
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


[_RS] = KEYMAP(
  // Layer 2 : Raised
  // Left Hand
  // ,--------------------------------------------------.
  // |        |      |      |      |      |      |      |
  // |--------+------+------+------+------+-------------|
  // |   ~    |   !  |   @  |   #  |   $  |   %  |      |
  // |--------+------+------+------+------+------|      |
  // |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|
  // |--------+------+------+------+------+------|      |
  // |        |  F7  |  F8  |  F9  |  F10 |  F11 |      |
  // `--------+------+------+------+------+-------------'
  //   |      |      | g(3) | g(1) |      |
  //   `----------------------------------'
  //                                        ,-------------.
  //                                        |      |      |
  //                                 ,------|------|------|
  //                                 |      |      |      |
  //                                 |      |      |------|
  //                                 |      |      |      |
  //                                 `--------------------'

  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  OOOOOOOO,
  OOOOOOOO, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
  OOOOOOOO, KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   OOOOOOOO,
  OOOOOOOO, OOOOOOOO, GO_TO_FN, GO_TO_LW, OOOOOOOO,

                                                    OOOOOOOO, OOOOOOOO,
                                                              OOOOOOOO,
                                          OOOOOOOO, OOOOOOOO, OOOOOOOO,

  //----------------------------------------------------------------------------

  // Right hand
  //   ,--------------------------------------------------.
  //   |      |      |      |      |      |      |        |
  //   |------+------+------+------+------+------+--------|
  //   |      |   ^  |   &  |   *  |   (  |   )  |        |
  //   |      |------+------+------+------+------+--------|
  //   |------| ____ |   _  |   +  |   {  |   }  |   |    |
  //   |      |------+------+------+------+------+--------|
  //   |      | ____ |   ~  |      |      |      |        |
  //   `-------------+------+------+------+------+--------'
  //                 |      | g(0) |      |      | g(0) |
  //                 `----------------------------------'
  // ,-------------.
  // |      |      |
  // |------|------|------.
  // |      |      |      |
  // |------|      |      |
  // |      |      |      |
  // `--------------------'

  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, RESET,
  OOOOOOOO, KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  OOOOOOOO,
            KC_F6,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,
  OOOOOOOO, KC_F12,   KC_TILD,  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
                      OOOOOOOO, GO_TO_DL, OOOOOOOO, OOOOOOOO, GO_TO_DL,

  OOOOOOOO, OOOOOOOO,
  OOOOOOOO,
  OOOOOOOO, OOOOOOOO, OOOOOOOO
),

[_FN] = KEYMAP(
  // Layer 3 : Function
  // Left Hand
  // ,--------------------------------------------------.
  // |        |      |      |      |      |      |      |
  // |--------+------+------+------+------+-------------|
  // |  Tab   | L-clk|MousUp| R-clk| PSCR1| PSCR2|      |
  // |--------+------+------+------+------+------|      |
  // |        |MousLt|MousDn|MousRt| ____ | ____ |------|
  // |--------+------+------+------+------+------|      |
  // |        | ____ |Mous3 |Mous4 | ____ | RESET|      |
  // `--------+------+------+------+------+-------------'
  //   |      |      | g(0) | g(1) |      |
  //   `----------------------------------'
  //                                        ,-------------.
  //                                        |      |      |
  //                                 ,------|------|------|
  //                                 |      |      |      |
  //                                 |      |      |------|
  //                                 |      |      |      |
  //                                 `--------------------'

  OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO, OOOOOOOO,
  CMD_GRV,  KC_BTN1 , KC_MS_U,  KC_BTN2,  PSCR1,    PSCR2,    OOOOOOOO,
  OOOOOOOO, KC_MS_L,  KC_MS_D,  KC_MS_R,  ________, ________,
  OOOOOOOO, ________, KC_BTN3,  KC_BTN4,  ________, RESET,    OOOOOOOO,
  OOOOOOOO, OOOOOOOO, GO_TO_DL, GO_TO_LW, OOOOOOOO,

                                                    OOOOOOOO, OOOOOOOO,
                                                              OOOOOOOO,
                                          OOOOOOOO, OOOOOOOO, OOOOOOOO,

  //----------------------------------------------------------------------------

  // Right hand
  //   ,--------------------------------------------------.
  //   |      |      |      |      |      |      |        |
  //   |------+------+------+------+------+------+--------|
  //   |      | Slep2| Home |  Up  | PgUp | Ins  |        |
  //   |      |------+------+------+------+------+--------|
  //   |------| Slep | Left | Down | Right| ____ | Backlt |
  //   |      |------+------+------+------+------+--------|
  //   |      | ____ | End  | ____ | PgDn | Del  |        |
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
  OOOOOOOO, SLEP2,    KC_HOME,  KC_UP,    KC_PGUP,  KC_INS,   OOOOOOOO,
            SLEP,     KC_LEFT,  KC_DOWN,  KC_RGHT,  ________, BL_MAC,
  OOOOOOOO, ________, KC_END,   ________, KC_PGDN,  KC_DEL,   OOOOOOOO,
                      OOOOOOOO, GO_TO_RS, OOOOOOOO, OOOOOOOO, GO_TO_DL,

  OOOOOOOO, OOOOOOOO,
  OOOOOOOO,
  OOOOOOOO, OOOOOOOO, OOOOOOOO
),
};

const uint16_t PROGMEM fn_actions[] = {
  // NOTE: requires you to add
  // #define TAPPING_TOGGLE  1
  // to config.h
  // or else the default number of taps is 5

  // Momentary switch when held, toggle when tapped
  // For some reason, we have to have these as functions here
  // It won't work to just say
  //   define MO_TG_LW ACTION_LAYER_TAP_TOGGLE(_LW)
  [_LW] = ACTION_LAYER_TAP_TOGGLE(_LW),
  [_RS] = ACTION_LAYER_TAP_TOGGLE(_RS),
  [_FN] = ACTION_LAYER_TAP_TOGGLE(_FN),
  [_RSHT_ESC] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ESC)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        // do nothing
      }
    break;

    // Type parens
    case 1:
      if (record->event.pressed) {
        return MACRO(
          D(LSFT),
          T(9),
          T(0),
          U(LSFT),
          T(LEFT),
        END);
      }
    break;

    // Type square brackets
    case 2:
      if (record->event.pressed) {
        return MACRO(
          T(LBRC),
          T(RBRC),
          T(LEFT),
        END);
      }
    break;

    // Type curly braces
    case 3:
      if (record->event.pressed) {
        return MACRO(
          D(LSFT),
          T(LBRC),
          T(RBRC),
          U(LSFT),
          T(LEFT),
        END);
      }
    break;

    // Lock laptop screen on OSX
    // For some reason, this has to be a macro, otherwise the keydown and keyup
    // sequence is sometimes off and doesn't work
    // Tried ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_EJCT) // LCTL(LSFT(KC_EJCT))
    // and it was inconsistent
    case 4:
      if (record->event.pressed) {
        return MACRO(
          D(LSFT),
          D(LCTL),
          T(PWR),
          U(LCTL),
          U(LSFT),
        END);
      }
    break;

    // Sleep monitor in OSX
    case 5:
      if (record->event.pressed) {
        return MACRO(
          D(LSFT),
          D(LCTL),
          T(EJCT),
          U(LCTL),
          U(LSFT),
        END);
      }
    break;

    // Type parens followed by fat arrow
    case 6:
      if (record->event.pressed) {
        return MACRO(
          D(LSFT),
          T(9),
          T(0),
          U(LSFT),
          T(SPC),
          T(EQL),
          D(LSFT),
          T(DOT),
          U(LSFT),
          T(SPC),
        END);
      }
    break;

    case 7:
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
