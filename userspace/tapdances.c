#include "tapdances.h"

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MNXT_MPRV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
    [TD_MPLY_MSEL] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MSEL)
};
