#include "phantom.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------------------------.
   * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|	|Prnt|ScLk|Paus|
   * |-----------------------------------------------------------|	|--------------|
   * | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |	| Ins|Home|PgUp|
   * |-----------------------------------------------------------|	|--------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|	| Del| End|PgDn|
   * |-----------------------------------------------------------|	`--------------'
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|		   ,----.
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |		   | Up |
   * |-----------------------------------------------------------|	,-------------.
   * |Ctrl||Alt | Cmd|      Space            |Cmd |R-ck|Alt|CTRL |	|Lft | Dn |Rig|
   * `-----------------------------------------------------------'	`-------------'
   */
[_BL] = KEYMAP(
  KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, \
  KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP, \
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_DELETE, KC_END, KC_PGDN, \
  KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,  \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, \
  KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_BTN2, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT)
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  // switch (id) {
  //   case SHIFT_ESC:
  //     shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
  //     if (record->event.pressed) {
  //       if (shift_esc_shift_mask) {
  //         add_key(KC_GRV);
  //         send_keyboard_report();
  //       } else {
  //         add_key(KC_ESC);
  //         send_keyboard_report();
  //       }
  //     } else {
  //       if (shift_esc_shift_mask) {
  //         del_key(KC_GRV);
  //         send_keyboard_report();
  //       } else {
  //         del_key(KC_ESC);
  //         send_keyboard_report();
  //       }
  //     }
  //     break;
  // }
}
