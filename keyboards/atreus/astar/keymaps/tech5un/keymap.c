// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _base 0
#define _nav_num 1
#define _sym 2
#define _fun 3

#define sh_Z LSFT_T(KC_Z)
#define sh_sl RSFT_T(KC_SLSH)
#define ct_esc LCTL_T(KC_ESC)
#define fun_app LT(_fun,KC_APP)
#define nn_spc LT(_nav_num,KC_SPC)
#define sym_bspc LT(_sym,KC_BSPC)
#define fun_del LT(_fun,KC_DEL)
#define undo LCTL(KC_Z)
#define cut LCTL(KC_X)
#define copy LCTL(KC_C)
#define paste LCTL(KC_V)
#define redo LCTL(KC_Y)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_base] = LAYOUT_pcb_up( /* colmak dh */
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT ,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O ,
    sh_Z,    KC_X,    KC_C,    KC_D,    KC_V,                       KC_K,    KC_H,    KC_COMM, KC_DOT,  sh_sl ,
    ct_esc,  KC_TAB, KC_LGUI,  KC_LALT, fun_app,  nn_spc, sym_bspc, fun_del, KC_RALT, KC_MINS, KC_QUOT, KC_ENT
  ),
  /*
   * insert    home  up    end    pgup                ||          *       7    8    9   -
   *  del      left  down  right  pgdn                ||          /       4    5    6   +
   *  undo     cut   copy  paste  redo                ||                  1    2    3   =
   *  ctrl/esc tab   lgui  lalt   fun/app nav_num/sps || symb/bsp fun/del 0    0    .   enter
   */
  [_nav_num] = LAYOUT_pcb_up( /* [> navigation and numbers <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_PAST, KC_7,   KC_8,  KC_9,   KC_PPLS ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_PSLS, KC_4,   KC_5,  KC_6,   KC_PMNS ,
    undo,    cut,     copy,    paste,   redo,                      KC_NO,   KC_1,   KC_2,  KC_3,   KC_EQL ,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,   KC_0,  KC_DOT, KC_TRNS  ),
  /*
   *  [        ]     (     )      `                   ||          *       &     *        +
   *  ;        '     |     _      \                   ||          /       $     %    ^   -
   *  ,        .     :     =                          ||                  !     @    #
   *  ctrl/esc tab   lgui  lalt   fun/app nav_num/sps || symb/bsp fun/del alt   -    .   enter
   */
  [_sym] = LAYOUT_pcb_up( /* [> symbols <] */
    KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,  KC_GRV,                    KC_ASTR,  KC_AMPR,  KC_ASTR,  KC_NO,    KC_PPLS  ,
    KC_SCLN,  KC_QUOT,  KC_PIPE,  KC_UNDS,  KC_BSLS,                   KC_SLSH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_PMNS  ,
    KC_LT,    KC_GT,    KC_COLN,  KC_EQL,   KC_NO,                     KC_NO,    KC_EXLM,  KC_AT,    KC_HASH,  KC_NO  ,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS ),
  /*
   * boot                                                    ||          volup   F7    F8    F9   F10
   *                   print screen                          ||          mute    F4    F5    F6   F11
   *                                                         ||          voldwn  F1    F2    F3   F12
   *  ctrl/esc tab   lgui  lalt   fun/app nav_num/sps        || symb/bsp fun/del alt   -     .    enter
   */
  [_fun] = LAYOUT_pcb_up( /* [> functions <] */
    QK_BOOT,  KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_VOLU,  KC_F7,    KC_F8,    KC_F9,    KC_F10  ,
    KC_NO,    KC_NO,    KC_PSCR,  KC_NO,    KC_NO,                        KC_MUTE,  KC_F4,    KC_F5,    KC_F6,    KC_F11  ,
    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_VOLD,  KC_F1,    KC_F2,    KC_F3,    KC_F12  ,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS )
};
