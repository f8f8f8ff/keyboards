#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define KY_CSPC LCTL(KC_SPC)
#define KY_ZMIN LCTL(KC_EQL)
#define KY_ZMOUT LCTL(KC_MINS)
#define KY_ZMRST LCTL(KC_0)
#define KY_ESCC LCTL_T(KC_ESC)

bool leader_listening = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |backsp|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| del   |    | lead  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
    KC_EQL,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KY_ESCC,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_DEL,    KC_LEAD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                            KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_DEL, KC_RALT \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |zmrst |zmout | zmin | wbak | wfwd |-------.    ,-------|   |  |   _  |   +  |   {  |   }  |   ~  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   \  |   -  |   =  |   [  |   ]  |   `  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER]= LAYOUT( \
    _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______,  KY_ZMRST, KY_ZMOUT, KY_ZMIN,  KC_WBAK,  KC_WFWD,                      KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_TILD,
    _______,  KC_APP,   KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_LGUI,  _______,  _______,  KC_BSLS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_GRV,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |-------.    ,-------| Left | Down |  Up  |Right | F11  | DEL  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  |-------|    |-------| home | pgdn | pgup | end  | F12  | INS  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
    _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
    KC_CAPS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_DEL,
    _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   KC_INS,
                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | play |vol up| stop |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | prev |vol dn| next |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      | mute |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT( \
    _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
                                  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln((leader_listening) ? "leader" : "", false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
    //oled_scroll_left();
  }
  return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    //set_timelog();
  }
  return true;
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_W, KC_Q) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
        SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING(SS_TAP(X_PSCR));
        }
        SEQ_THREE_KEYS(KC_C, KC_A, KC_D) {
            SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DEL))));
        }
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING(SS_TAP(X_CALC));
        }
        SEQ_ONE_KEY(KC_M) {
            SEND_STRING(SS_TAP(X_MSEL));
        }
        SEQ_TWO_KEYS(KC_C, KC_S) {
            SEND_STRING(SS_TAP(X_SYSTEM_SLEEP));
        }
#ifdef OLED_ENABLE
/*
        SEQ_TWO_KEYS(KC_O, KC_J) {
            oled_set_brightness(1);
        }
        SEQ_TWO_KEYS(KC_O, KC_K) {
            oled_set_brightness(255);
        }
        SEQ_TWO_KEYS(KC_O, KC_O) {
            if (is_oled_on()) {
                oled_off();
            } else {
                oled_on();
            }
        }
*/
#endif
    }
}

void leader_start(void) {
    leader_listening = true;
}

void leader_end(void) {
    leader_listening = false;
}
