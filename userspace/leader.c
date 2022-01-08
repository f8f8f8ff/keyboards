#include "leader.h"

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
    }
}
