#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum adb_layers {
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  LOWER,
  RAISE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_m0116_ansi(											LOWER,
    KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,     KC_DELETE, KC_EQL, KC_PSLS, KC_PAST,
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_P7,   KC_P8,  KC_P9,   KC_PMNS,
    KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,      KC_P4,   KC_P5,  KC_P6,   KC_PPLS,
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,     KC_P1,   KC_P2,  KC_P3,
    KC_LCAP, KC_LALT, KC_LGUI, KC_GRV,                 KC_SPC,         KC_BSLS, KC_LEFT, KC_RGHT, KC_DOWN,  KC_UP,               KC_P0,           KC_PDOT, KC_PENT
    ),
[_LOWER] = LAYOUT_m0116_ansi(											QWERTY,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_DEL,      KC_NLCK, KC_EQL, KC_PSLS, KC_PAST,
    KC_TAB,  KC_EXLM, KC_AT,   KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,              KC_P7,   KC_P8,  KC_P9,   KC_PMNS,
    KC_LCTL, KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,   KC_LCBR,    KC_RCBR,    KC_QUES, KC_PLUS, KC_PIPE,          KC_ENT,      KC_P4,   KC_P5,  KC_P6,   KC_PPLS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,   KC_B,   S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,                    KC_RSFT,     KC_P1,   KC_P2,  KC_P3,
    KC_LCAP, KC_LALT, KC_LGUI, _______,                KC_SPC,             _______,    KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,                KC_P0,           KC_PDOT, KC_PENT
    ),
[_RAISE] = LAYOUT_m0116_ansi(											QWERTY,
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,     KC_NLCK, KC_EQL, KC_PSLS, KC_PAST,
    KC_TAB,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_SLSH, KC_EQL,               KC_P7,   KC_P8,  KC_P9,   KC_PMNS,
    KC_LCTL, KC_A,    KC_O,    KC_E,   KC_U,   KC_I,   KC_D,   KC_LBRC,KC_RBRC, KC_SLSH, KC_EQL,  KC_BSLS,          KC_ENT,      KC_P4,   KC_P5,  KC_P6,   KC_PPLS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,   KC_K,   KC_X,   KC_B,   KC_NUHS,KC_NUBS, KC_PGUP, KC_PGDN,                   KC_RSFT,     KC_P1,   KC_P2,  KC_P3,
    KC_LCAP, KC_LALT, KC_LGUI, _______,                KC_SPC,         _______, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,                KC_P0,           KC_PDOT, KC_PENT
    )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        //update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
