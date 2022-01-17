#pragma once

#include "quantum.h"

enum {
    TD_MNXT_MPRV = 0,
    TD_MPLY_MSEL
}

#define TD_NXT TD(TD_MNXT_MPRV)
#define TD_PLY TD(TD_MPLY_MSEL)
