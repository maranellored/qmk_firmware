#include QMK_KEYBOARD_H
//#include "debug.h"
//#include "action_layer.h"
//#include "version.h"
//#include "quantum.h"

#define BASE 0 // default layer
#define NUMB 1 // numbers
#define SYMB 2 // symbols
#define ADMIN 3 // admin

//enum custom_keycodes {
//  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
//  VRSN
//};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic Layer
*
* ,------+------+------+------+------+-------.                    ,------+------+------+------+------+------.
* | ESC  |   Q  |   W  |   E  |   R  |    T  |                    |   Y  |   U  |   I  |   O  |  P  |   =   |
* |------+------+------+------+------+-------|                    |------+------+------+------+-----+-------|
* | TAB  |   A   |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |  ;  |   '   |
* |------+------+------+------+------+-------|                    |------+------+------+------+-----+-------|
* |  [   |   Z   |   X  |   C  |   V  |   B  |                    |   N  |  M   |   ,  |   .  |  /  |   ]   |
* |------+------+------+------+------+-------'                    `------+------+------+------+-----+-------|
* | LCtrl| LAlt | LAlt | Left | Right|                                   |  Up  | Down |   -  |   \  | RAlt |
* `----------------------------------'                                  `-----------------------------------'
*                                      ,-------------.   ,--------------.
*                                      |       |      |  | MO   | Delete|
*                               ,------| LCtrl | RGUI |  |(SYMB)|       |-------.
*                               | Back |-------|      |  |      |-------|       |
*                               | Space|       | ---- |  |------|       | Space |
*                               |      | LShift| LGUI |  |Enter |  MO   |       |
*                               |      |       |      |  |      |(NUMB) |       |
*                               `---------------------'  `----------------------'
*
*/

[BASE] = LAYOUT_lightcycle(  // layer 0 : default
        // left hand
        KC_ESC,       KC_Q,      KC_W,     KC_E,     KC_R,    KC_T,                                               KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_EQL,
        KC_TAB,       KC_A,      KC_S,     KC_D,     KC_F,    KC_G,                                               KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN,  KC_QUOT,
        KC_LBRC,      KC_Z,      KC_X,     KC_C,     KC_V,    KC_B,                                               KC_N,  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_RBRC,
        KC_LCTL,      KC_LALT,   KC_LALT,  KC_LEFT,  KC_RGHT,                                                            KC_UP,  KC_DOWN,  KC_MINS,  KC_BSLS,  KC_GRAVE,
                                                                        KC_LCTL, KC_RGUI,     MO(SYMB), KC_DEL,
                                                              KC_BSPC,  KC_LSFT, KC_LGUI,     KC_ENT,   MO(NUMB), KC_SPC 
    ),

/* Keymap 1: Number Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |          |  |  F9  |  F10 |  F11 |  F12 |                    | Calc |   7  |   8  |   9  |   -  |      |
 * |----------+--+------+------+------+------|                    |------+------+------+------+------+------|
 * |          |  |  F5  |  F6  |  F7  |  F8  |                    |Ctrl+\|   4  |   5  |   6  |   +  |      |
 * |----------+--+------+------+------+------|                    |------+------+------+------+------+------|
 * |          |  |  F1  |  F2  |  F3  |  F4  |                    |      |   1  |   2  |   3  |   *  |      |
 * |----------+------+------+------+------+--'                    `------+------+------+------+------+------|
 * |MO(ADMIN) |  |      | BACK | FWD  |                                  |   0  |   0  |   .  |   /  |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      | RCtrl|
 *                               ,------|      |      |  | RAlt |      |------.
 *                               |      |------|      |  |      |------|      |
 *                               |      |++++++|------|  |------|      |      |
 *                               |      |++++++|      |  |      | RShft|  0   |
 *                               |      |++++++|      |  | Menu |      |      |
 *                               |      |++++++|      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// Numbers
[NUMB] = LAYOUT_lightcycle(
       // left hand
          KC_TRNS,     KC_TRNS,   KC_F9,    KC_F10,    KC_F11,    KC_F12,
          KC_TRNS,     KC_TRNS,   KC_F5,    KC_F6,     KC_F7,     KC_F8,
          KC_TRNS,     KC_TRNS,   KC_F1,    KC_F2,     KC_F3,     KC_F4,
          MO(ADMIN),   KC_TRNS,   KC_TRNS,  KC_WBAK,   KC_WFWD,
                                                         KC_TRNS,  KC_TRNS,
                                               KC_TRNS,  KC_TRNS,  KC_TRNS,
       // right hand
                                KC_CALC,        KC_7,    KC_8,    KC_9,    KC_MINS,   KC_TRNS,
                                RCTL(KC_BSLS),  KC_4,    KC_5,    KC_6,    KC_PLUS,   KC_TRNS,
                                KC_TRNS,        KC_1,    KC_2,    KC_3,    KC_ASTR,   KC_TRNS,
                                                KC_0,    KC_0,    KC_DOT,  KC_SLSH,   KC_TRNS,
                      KC_RALT,  KC_RCTL,
                      KC_RGUI,  KC_RSFT,  KC_0
),

/* Keymap 2: Symbol Layer
 *
 * ,-------------------------------------------.                    ,-----------------------------------------.
 * |      |   !  |  Up  |  #   |  $   | Alt+F4 |                    | Cut  |      |   !  |  @   |  #   |      |
 * |------+------+------+------+------+--------|                    |------+------+------+------+------+------|
 * |   \  | Left | Down |Right |  *   | Insert |                    | Copy |      |   &  |  ^   |  %   |      |
 * |------+------+------+------+------+--------|                    |------+------+------+------+------+------|
 * |      |  (   |  )   |  -   |  =   | Lock   |                    | Paste|      |      |      |      |      |
 * |------------+------+------+------+--------+'                    `------+------+------+------+------+------|
 * |      |      |      |  `   |  |   |                                  |      |      |      |      |      |
 * `----------------------------------                                   `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | break| alt  |  |      |      |
 *                               ,------|      |  +   |  |      |      |------.
 *                               |      |------| prscr|  |      |------|      |
 *                               |      |      |------|  |------|++++++|      |
 *                               |  Caps| LShft|      |  |      |++++++|      |
 *                               |  Lock|      | Prt  |  |      |++++++|      |
 *                               |      |      | Scr  |  |      |++++++|      |
 *                               `--------------------'  `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_lightcycle(
       // left hand
          KC_TRNS,   KC_EXLM,  KC_AT,    KC_UP,  KC_DLR,  RALT(KC_F4),
          KC_BSLS,   KC_ASTR,  KC_LEFT,  KC_DOWN, KC_RIGHT, KC_INS,
          KC_TRNS,   KC_LPRN,  KC_RPRN,  KC_MINS,  KC_EQL,  RGUI(KC_L),
          KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_GRV,   KC_PIPE,
                                                         KC_PAUSE, RALT(KC_PSCR),
                                               KC_CAPS,  KC_LSFT,  KC_PSCR,
       // right hand
                RCTL(KC_X),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                RCTL(KC_C),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                RCTL(KC_V),  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS
),

// Admin Layer
[ADMIN] = LAYOUT_lightcycle(
       // left hand
          KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
          KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
          KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
          KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                         KC_TRNS,    KC_TRNS,
                                             KC_TRNS,    KC_TRNS,    KC_TRNS,
       // right hand
                KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   RESET,
                KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
                KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
                           KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,   KC_TRNS,   KC_TRNS
),
};

//const uint16_t PROGMEM fn_actions[] = {
//    //[1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
//};

//const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
//{
//  // MACRODOWN only works in this function
//  switch(id) {
//    case 0:
//        if (record->event.pressed) {
//        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//      }
//      break;
//    case 1:
//      if (record->event.pressed) { // For resetting EEPROM
//        eeconfig_init();
//      }
//      break;
//  }
//  return MACRO_NONE;
//};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  switch (keycode) {
//    case VRSN:
//      if (record->event.pressed) {
//        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
//      }
//      return false;
//      break;
//  }
//  return true;
//}

//// Runs just one time when the keyboard initializes.
//void matrix_init_user(void) {};


//// Runs constantly in the background, in a loop.
//void matrix_scan_user(void) {};
