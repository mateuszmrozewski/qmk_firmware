/* Copyright 2020 gtips
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
#include "config.h"

enum layer_names {
    _QWERTY,
    _NUMPAD,
    _NAVIGATE,
    _SYMBOL
};


/**
 * Missing:
 * space equals space macro
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    
    KC_TAB,   MT(MOD_LCTL, KC_A),    MT(MOD_LALT,  KC_S),     MT(MOD_LGUI, KC_D),     MT(MOD_LSFT, KC_F),    KC_G,               
    KC_H,     MT(MOD_LSFT, KC_J),    MT(MOD_LGUI, KC_K),      MT(MOD_LALT, KC_L),     MT(MOD_LCTL, KC_SCLN),  KC_QUOT,
    
    KC_DELETE,   LT(_NUMPAD, KC_Z),     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, CAPS_WORD,
                                            KC_LGUI,   KC_SPC,    LT(_NUMPAD, KC_ENTER),   OSL(_SYMBOL),    TT(_NAVIGATE)

  ),
  
  [_NUMPAD] = LAYOUT(
    _______,  XXXXXXX,  KC_F7,    KC_F8,  KC_F9,    KC_F10,            XXXXXXX,  KC_7,  KC_8,  KC_9,  KC_DOT,  _______,
    _______,  KC_LCTL,  MT(MOD_LALT, F4),  MT(MOD_LGUI, F5),  MT(MOD_LSFT, F6),   KC_F11,            KC_MINUS,  MT(MOD_LSFT, KC_4),  MT(MOD_LGUI, KC_5), MT(MOD_LALT, KC_6), MT(MOD_LCTL, KC_0),   XXXXXXX,
    _______,  XXXXXXX,   KC_F1,  KC_F2,  KC_F3,   KC_F12,            XXXXXXX,  KC_1,   KC_2,  KC_3,  KC_UNDERSCORE, XXXXXXX,
                                            TO(_QWERTY),   KC_SPC,  LT(_NUMPAD, KC_ENT),   OSL(_SYMBOL), TO(_NAVIGATE)
  ),
  
  [_NAVIGATE] = LAYOUT(
    _______,  KC_INSERT,     KC_PAGE_DOWN,     KC_UP,     KC_PAGE_UP,      KC_DELETE,               _______,_______,_______,_______,_______,_______,
    _______,  KC_HOME,  KC_LEFT,   KC_DOWN,  KC_RIGHT,   KC_END,            _______,_______,_______,_______,_______,_______,
    _______,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            _______,_______,_______,_______,_______,_______,
                                            TO(_QWERTY),   KC_SPC, LT(_NUMPAD, KC_ENT),  OSL(_SYMBOL), TO(_NAVIGATE)
  ),
  
  [_SYMBOL] = LAYOUT(
    _______,   KC_EXLM, KC_AT,  KC_HASH,  KC_DLR,   KC_BRIGHTNESS_UP,            KC_KB_VOLUME_UP,  KC_LEFT_BRACKET,  KC_RIGHT_BRACKET,  KC_UNDERSCORE,  KC_PLUS,  _______,
    
    _______,   MT(MOD_LCTL, KC_PERC), MT(MOD_LALT, KC_CIRC),  MT(MOD_LGUI, KC_AMPR), MT(MOD_LSFT, KC_ASTR),   KC_BRIGHTNESS_DOWN,            
    KC_KB_VOLUME_DOWN,  MT(MOD_LSFT, KC_LEFT_PAREN),  MT(MOD_LGUI, KC_RIGHT_PAREN),  MT(MOD_LALT, KC_MINUS),  MT(MOD_LCTL, KC_EQUAL),  KC_PIPE,
    
    _______,   KC_GRV, KC_TILD,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    KC_KB_MUTE,    KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,  _______, KC_EQUAL,  KC_BACKSLASH,
                                            TO(_QWERTY),   KC_SPC,  LT(_NUMPAD, KC_ENT),  TO(_NUMPAD), TO(_NAVIGATE)
  ),
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _NUMPAD, _NAVIGATE, _SYMBOL);
//}

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_RED}       // Light 4 LEDs, starting with LED 6
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(2, layer_state_cmp(state, _NAVIGATE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOL));
    return state;
}
