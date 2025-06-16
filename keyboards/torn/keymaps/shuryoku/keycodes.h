#ifndef SHURYOKU_KEYCODE_H
#define SHURYOKU_KEYCODE_H

#include QMK_KEYBOARD_H

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

typedef enum {
    U_CHG_OS = 256, // the standard seems to be SAFE_RANGE but that didn't compile - SAFE_RANGE ensures custom keycodes are outside the range 0-255
    U_RDO,
    U_PST,
    U_CUT,
    U_CPY,
    U_UND,
    U_SLCTALL,
    U_DESLCT
} custom_keycodes;

#endif
