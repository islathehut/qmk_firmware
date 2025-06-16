/**

███████ ██   ██ ██    ██ ██████  ██    ██  ██████  ██   ██ ██    ██
██      ██   ██ ██    ██ ██   ██  ██  ██  ██    ██ ██  ██  ██    ██
███████ ███████ ██    ██ ██████    ████   ██    ██ █████   ██    ██
     ██ ██   ██ ██    ██ ██   ██    ██    ██    ██ ██  ██  ██    ██
███████ ██   ██  ██████  ██   ██    ██     ██████  ██   ██  ██████

*/

#include "layers.h"
#include <stdio.h>
#include <string.h>

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_R MT(MOD_LALT, KC_R)
#define CTL_S MT(MOD_LCTL, KC_S)
#define SHT_T MT(MOD_LSFT, KC_T)

// RIGHT HAND HOME ROW MODS ├───────────────────────────────────┐

#define SHT_N MT(MOD_RSFT, KC_N)
#define CTL_E MT(MOD_LCTL, KC_E)
#define ALT_I MT(MOD_LALT, KC_I)
#define GUI_O MT(MOD_LGUI, KC_O)


// ┌───────────────────────────────────────────────────────────┐
// │ l a y o u t  a n d  k e y m a p                           │
// └───────────────────────────────────────────────────────────┘

// This is the shuryoku keymap definition
#include "layouts/shuryoku/keymap_shuryoku.h"

char layer_state_str[24];
char o_text[24] = "";
int dmacro_num = 0;
bool win = false; // when true shortcuts like copy/paste follow the windows spec, otherwise they follow the mac spec


// ┌───────────────────────────────────────────────────────────┐
// │ c o n f i g u r a t i o n                                 │
// └───────────────────────────────────────────────────────────┘

// configure tapping term based on keys pressed
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_T:
            return TAPPING_TERM - 70;
        case SHT_N:
            return TAPPING_TERM - 70;
        default:
            return TAPPING_TERM;
    }
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // toggle the windows flag on/off
        case U_CHG_OS:
            if (record->event.pressed) {
                win = !win;
                return false;
            }
        // use correct copy shortcut
        case U_CPY:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("c")) : SEND_STRING(SS_LCMD("c"));
                return false;
            }
        // use correct paste shortcut
        case U_PST:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("v")) : SEND_STRING(SS_LCMD("v"));
                return false;
            }
        // use correct cut shortcut
        case U_CUT:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("x")) : SEND_STRING(SS_LCMD("x"));
                return false;
            }
        // use correct undo shortcut
        case U_UND:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("z")) : SEND_STRING(SS_LCMD("z"));
                return false;
            }
        // use correct redo shortcut
        case U_RDO:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("y")) : SEND_STRING(SS_LCMD(SS_LSFT("z")));
                return false;
            }
        // use correct select all shortcut
        case U_SLCTALL:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("a")) : SEND_STRING(SS_LCMD("a"));
                return false;
            }
        // use correct deselect shortcut
        case U_DESLCT:
            if (record->event.pressed) {
                win ? SEND_STRING(SS_LCTL("u")) : SEND_STRING(SS_LCMD("u"));
                return false;
            }
    }

    return true;
}
