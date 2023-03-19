#include QMK_KEYBOARD_H

#include "keymap_polish.h"

enum layer_names {
    _QWERTY,
    _NUMPAD,
    _NAVIGATE,
    _SYMBOL
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    
    KC_TAB,   LCTL_T(KC_A),    LALT_T(KC_S),     LGUI_T(KC_D),     LSFT_T(KC_F),    KC_G,               
    KC_H,     LSFT_T(KC_J),    LGUI_T(KC_K),     LALT_T(KC_L),     LCTL_T(KC_SCLN),  KC_QUOT,
    
    KC_DELETE,   LT(_NUMPAD, KC_Z),     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, QK_CAPS_WORD_TOGGLE,
                                            KC_LGUI,   KC_SPC,XXXXXXX,    LT(_NUMPAD, KC_ENTER),   OSL(_SYMBOL),    TT(_NAVIGATE)

  ),
  
  [_NUMPAD] = LAYOUT(
    _______,  XXXXXXX,  KC_F7,    KC_F8,  KC_F9,    KC_F10,            XXXXXXX,  KC_7,  KC_8,  KC_9,  KC_DOT,  _______,
    _______,  KC_LCTL,  LALT_T(KC_F4),  LGUI_T(KC_F5),  LSFT_T(KC_F6),   KC_F11,            KC_MINUS,  LSFT_T(KC_4),  LGUI_T(KC_5), LALT_T(KC_6), LCTL_T(KC_0),   XXXXXXX,
    _______,  XXXXXXX,   KC_F1,  KC_F2,  KC_F3,   KC_F12,            XXXXXXX,  KC_1,   KC_2,  KC_3,  KC_UNDERSCORE, XXXXXXX,
                                            TO(_QWERTY),   KC_SPC,XXXXXXX,  LT(_NUMPAD, KC_ENT),   OSL(_SYMBOL), TO(_NAVIGATE)
  ),
  
  [_NAVIGATE] = LAYOUT(
    _______,  KC_INSERT,     KC_PAGE_DOWN,     KC_UP,     KC_PAGE_UP,      KC_DELETE,               RGB_MOD,RGB_RMOD,XXXXXXX,XXXXXXX,XXXXXXX,_______,
    _______,  KC_HOME,  KC_LEFT,   KC_DOWN,  KC_RIGHT,   KC_END,            XXXXXXX,KC_LSFT,KC_LGUI,KC_LALT,KC_LCTL,XXXXXXX,
    _______,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                            TO(_QWERTY),   KC_SPC,XXXXXXX, LT(_NUMPAD, KC_ENT),  OSL(_SYMBOL), TO(_NAVIGATE)
  ),
  
  [_SYMBOL] = LAYOUT(
    _______,   KC_EXLM, KC_AT,  KC_HASH,  KC_DLR,   KC_BRIGHTNESS_UP,            KC_KB_VOLUME_UP,  KC_LEFT_BRACKET,  KC_RIGHT_BRACKET,  KC_UNDERSCORE,  KC_PLUS,  _______,
    
    _______,   TD(DANCE_0), TD(DANCE_1),  TD(DANCE_2), TD(DANCE_3),   KC_BRIGHTNESS_DOWN,        KC_KB_VOLUME_DOWN,  TD(DANCE_4),  TD(DANCE_5),  LALT_T(KC_MINUS),  LCTL_T(KC_EQUAL),  KC_PIPE,
    
    _______,   KC_GRV, KC_TILD,  XXXXXXX,  XXXXXXX,   XXXXXXX,
    KC_KB_MUTE,    KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE,  _______, _______,  KC_BACKSLASH,
                                            TO(_QWERTY),   KC_SPC,XXXXXXX,  LT(_NUMPAD, KC_ENT),  TO(_NUMPAD), TO(_NAVIGATE)
  ),
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

void keyboard_post_init_user(void) {
    // Enable the LED layers
    //rgblight_layers = my_rgb_layers;

    //rgblight_mode(10); // haven't found a way to set this in a more useful way

    pimoroni_trackball_set_rgbw(0, 0, 254, 0);
    oled_init(OLED_ROTATION_270);
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    // switch (get_highest_layer(layer_state)) {
    //     case _QWERTY:
    //         oled_write_P(PSTR("Default\n"), false);
    //         break;
    //     case _FN:
    //         oled_write_P(PSTR("FN\n"), false);
    //         break;
    //     case _ADJ:
    //         oled_write_P(PSTR("ADJ\n"), false);
    //         break;
    //     default:
    //         // Or use the write_ln shortcut over adding '\n' to the end of your string
    //         oled_write_ln_P(PSTR("Undefined"), false);
    // }

    // // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif


/**
 * Code below was copied from my moonlander configuration created via Oryx configurator.
 * This addresses the limitations of MT() used with shifted keycodes.
 *
 * More information: https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
 */
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[6];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

#define DANCE(X, MOD, KC) void on_##X##_dance(qk_tap_dance_state_t *state, void *user_data);\
    void dance_##X##_finished(qk_tap_dance_state_t *state, void *user_data);\
    void dance_##X##_reset(qk_tap_dance_state_t *state, void *user_data);\
    void on_##X##_dance(qk_tap_dance_state_t *state, void *user_data) {\
        if(state->count == 3) {\
            tap_code16(KC);\
            tap_code16(KC);\
            tap_code16(KC);\
        }\
        if(state->count > 3) {\
            tap_code16(KC);\
        }\
    }\
    void dance_##X##_finished(qk_tap_dance_state_t *state, void *user_data) {\
        dance_state[X].step = dance_step(state);\
        switch (dance_state[X].step) {\
            case SINGLE_TAP: register_code16(KC); break;\
            case SINGLE_HOLD: register_code16(MOD); break;\
            case DOUBLE_TAP: register_code16(KC); register_code16(KC); break;\
            case DOUBLE_SINGLE_TAP: tap_code16(KC); register_code16(KC);\
        }\
    }\
    \
    void dance_##X##_reset(qk_tap_dance_state_t *state, void *user_data) {\
        wait_ms(10);\
        switch (dance_state[X].step) {\
            case SINGLE_TAP: unregister_code16(KC); break;\
            case SINGLE_HOLD: unregister_code16(MOD); break;\
            case DOUBLE_TAP: unregister_code16(KC); break;\
            case DOUBLE_SINGLE_TAP: unregister_code16(KC); break;\
        }\
        dance_state[X].step = 0;\
    }   

DANCE(0, KC_LCTL, KC_PERC)
DANCE(1, KC_LALT, KC_CIRC)
DANCE(2, KC_LGUI, KC_AMPR)
DANCE(3, KC_LSFT, KC_ASTR)
DANCE(4, KC_LSFT, KC_LPRN)
DANCE(5, KC_LGUI, KC_RPRN)

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_0_dance, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_1_dance, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_2_dance, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_3_dance, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_4_dance, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_5_dance, dance_5_finished, dance_5_reset),
};

