#ifndef SHURYOKU_KEYCODE_H
#define SHURYOKU_KEYCODE_H

#include QMK_KEYBOARD_H

// // mac clipboard/function keycodes
// #define U_RDO_MAC SCMD(KC_Z)
// #define U_PST_MAC LCMD(KC_V)
// #define U_CPY_MAC LCMD(KC_C)
// #define U_CUT_MAC LCMD(KC_X)
// #define U_UND_MAC LCMD(KC_Z)
// #define U_SLCTALL_MAC LCMD(KC_A)
// #define U_DESLCT_MAC LCMD(KC_U)

// // win clipboard/function keycodes
// #define U_RDO_WIN C(KC_Y)
// #define U_PST_WIN C(KC_V)
// #define U_CPY_WIN C(KC_C)
// #define U_CUT_WIN C(KC_X)
// #define U_UND_WIN C(KC_Z)
// #define U_SLCTALL_WIN C(KC_A)
// #define U_DESLCT_WIN C(KC_U)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

typedef enum {
    U_CHG_OS = 256,
    U_RDO,
    U_PST,
    U_CUT,
    U_CPY,
    U_UND,
    U_SLCTALL,
    U_DESLCT
} custom_keycodes;

#endif
