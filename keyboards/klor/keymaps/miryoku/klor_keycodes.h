#ifndef KLOR_KEYCODE_H
#define KLOR_KEYCODE_H

#include QMK_KEYBOARD_H

// #if defined (MIRYOKU_CLIPBOARD_FUN)
//   #define U_RDO KC_AGIN
//   #define U_PST KC_PSTE
//   #define U_CPY KC_COPY
//   #define U_CUT KC_CUT
//   #define U_UND KC_UNDO
//   #define U_SLCTALL KC_SELECT
//   #define U_DESLCT KC_SELECT
// #elif defined (MIRYOKU_CLIPBOARD_MAC)
//   #define U_RDO SCMD(KC_Z)
//   #define U_PST LCMD(KC_V)
//   #define U_CPY LCMD(KC_C)
//   #define U_CUT LCMD(KC_X)
//   #define U_UND LCMD(KC_Z)
//   #define U_SLCTALL LCMD(KC_A)
//   #define U_DESLCT LCMD(KC_U)
// #elif defined (MIRYOKU_CLIPBOARD_WIN)
//   #define U_RDO C(KC_Y)
//   #define U_PST C(KC_V)
//   #define U_CPY C(KC_C)
//   #define U_CUT C(KC_X)
//   #define U_UND C(KC_Z)
//   #define U_SLCTALL C(KC_A)
//   #define U_DESLCT C(KC_U)
// #else
//   #define U_RDO KC_AGIN
//   #define U_PST S(KC_INS)
//   #define U_CPY C(KC_INS)
//   #define U_CUT S(KC_DEL)
//   #define U_UND KC_UNDO
//   #define U_SLCTALL C(KC_A)
//   #define U_DESLCT C(KC_U)
// #endif
#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)
#define U_SLCTALL LCMD(KC_A)
#define U_DESLCT LCMD(KC_U)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

typedef enum {
    U_MEDIA,
    U_NAV,
    U_MOUSE,
    U_SYM,
    U_NUM,
    U_FUN
} custom_keycodes;

#endif
