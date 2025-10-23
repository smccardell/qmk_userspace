

#include QMK_KEYBOARD_H
#include <stdio.h>

enum totem_layers {
    _COLEMAK,
    _QWERTY,
    _SYNUM,
    _NAV,
    _ADJUST,
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    NAV_SPC,
    NAV_DEL,
    SYNUM_BSPC,
    SYNUM_TAB,
    ADJ_ESC,
    ADJ_CAP,
    RSFT_ENTER
};

#define COLEMAK PDF(_COLEMAK)
#define QWERTY PDF(_QWERTY)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_DEL LT(_NAV, KC_DEL)
#define SYNUM_BSPC LT(_SYNUM, KC_BSPC)
#define SYNUM_TAB LT(_SYNUM, KC_TAB)
#define ADJ_ESC LT(_ADJUST, KC_ESC)
#define ADJ_CAP LT(_ADJUST, QK_CAPS_WORD_TOGGLE)
#define RSFT_ENTER MT(MOD_RSFT, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3_ex2(
      OS_LALT,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,  XXXXXXX,     XXXXXXX,  KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,      OS_LGUI,
      OS_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,  QK_LEADER,     QK_LLCK,  KC_M,    KC_N,    KC_E,    KC_I,      KC_O,   RSFT_ENTER,
      OS_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_V,                         KC_K,    KC_M, KC_COMM,  KC_DOT,   KC_SLSH,       QK_REP,
                                      ADJ_ESC, SYNUM_TAB, NAV_SPC,           SYNUM_BSPC, NAV_DEL, ADJ_CAP

  ),

    [_QWERTY] = LAYOUT_split_3x6_3_ex2(
      OS_LALT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  XXXXXXX,     XXXXXXX,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     OS_LGUI,
      OS_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  QK_LEADER,     QK_LLCK,  KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, RSFT_ENTER,
      OS_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,     QK_REP,
                                      ADJ_ESC, SYNUM_TAB, NAV_SPC,           SYNUM_BSPC, NAV_DEL, ADJ_CAP
  ),

    [_SYNUM] = LAYOUT_split_3x6_3_ex2(
       _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,     _______,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,     _______,  KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                          _______, _______,  _______,     _______, _______, _______
  ),
 
    [_NAV] = LAYOUT_split_3x6_3_ex2(
       _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,   _______,     _______,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,     _______,  KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______,
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
  ),

    [_ADJUST] = LAYOUT_split_3x6_3_ex2(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______,     _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,  _______,     _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      _______, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                          _______, _______,  _______,     _______, _______, _______
  )
};

void leader_end_user(void) {
    if (leader_sequence_three_keys(KC_S, KC_S, KC_F)) {
        // Leader, s, s, f => select * from 
        SEND_STRING("select *\n  from ");
    } else if (leader_sequence_three_keys(KC_S, KC_C, KC_F)) {
        // Leader, s, c, f => select count(*) from 
        SEND_STRING("select count(*)\n  from ");
    }  
    // if (leader_sequence_one_key(KC_F)) {
    //     // Leader, f => Types the below string
    //     SEND_STRING("QMK is awesome.");
    // } else if (leader_sequence_two_keys(KC_D, KC_D)) {
    //     // Leader, d, d => Ctrl+A, Ctrl+C
    //     SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
    //     // Leader, d, d, s => Types the below string
    //     SEND_STRING("https://start.duckduckgo.com\n");
    // } else if (leader_sequence_two_keys(KC_A, KC_S)) {
    //     // Leader, a, s => GUI+S
    //     tap_code16(LGUI(KC_S));
    // }
}