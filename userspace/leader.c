#include "leader.h"
#include "quantum.h"

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_W, KC_Q) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
        // SHAREX
        // capture screen
        SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING(SS_TAP(X_PSCR));
        }
        // capture region
        SEQ_TWO_KEYS(KC_S, KC_R) {
            SEND_STRING(SS_LCTL(SS_TAP(X_PSCR)));
        }
        // capture active window
        SEQ_TWO_KEYS(KC_S, KC_W) {
            SEND_STRING(SS_LALT(SS_TAP(X_PSCR)));
        }
        // start / stop screen recording 
        SEQ_TWO_KEYS(KC_S, KC_V) {
            SEND_STRING(SS_LSFT(SS_TAP(X_PSCR)));
        }
        // start / stop gif recording 
        SEQ_TWO_KEYS(KC_S, KC_G) {
            SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_PSCR))));
        }
        // ctrl alt delete
        SEQ_THREE_KEYS(KC_C, KC_A, KC_D) {
            SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DEL))));
        }
        // powertoys color picker
        SEQ_TWO_KEYS(KC_C, KC_P) {
            SEND_STRING(SS_LGUI(SS_LSFT("c")));
        }
        // calculator
        SEQ_ONE_KEY(KC_C) {
            SEND_STRING(SS_TAP(X_CALC));
        }
        // open music player
        SEQ_ONE_KEY(KC_M) {
            SEND_STRING(SS_TAP(X_MSEL));
        }
        // audio mute
        SEQ_TWO_KEYS(KC_M, KC_U) {
            SEND_STRING(SS_TAP(X_MUTE));
        }
        // system sleep
        SEQ_TWO_KEYS(KC_C, KC_S) {
            SEND_STRING(SS_TAP(X_SYSTEM_SLEEP));
        }
    }
}
