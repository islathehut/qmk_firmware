/* *

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

bool linux = false; // when true shortcuts like copy/paste follow the linux spec, otherwise they follow the mac spec
char *layer_text = "DEFAULT";
bool gaming_on = false;
bool old_gaming_on = false;


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

#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLD, 10);
        } else {
            tap_code_delay(KC_VOLU, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            rgblight_decrease_val();
        } else {
            rgblight_increase_val();
        }

    } else if (index == 2) { /* Third encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    } else if (index == 3) { /* Fourth encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
    } else if (index == 4) { /* Fifth encoder */
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    return true;
}

#endif

#include "images/cyberpunk_4_3_ansi_320x240.qgf.c"
#include "fonts/notosans32.qff.h"

static painter_device_t display;
static painter_image_handle_t image;
static painter_font_handle_t my_font;

// st7789 enable, comment out the following line if not using a st7789
painter_device_t qp_st7789_make_spi_device(uint16_t panel_width, uint16_t panel_height, pin_t chip_select_pin, pin_t dc_pin, pin_t reset_pin, uint16_t spi_divisor, int spi_mode);
// gc9a01 enable, comment out the following line if not using a gc9a01
// painter_device_t qp_gc9a01_make_spi_device(uint16_t panel_width, uint16_t panel_height, pin_t chip_select_pin, pin_t dc_pin, pin_t reset_pin, uint16_t spi_divisor, int spi_mode);

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=false;
  debug_matrix=false;
  debug_keyboard=false;
  debug_mouse=false;
}

uint32_t deferred_init(uint32_t trigger_time, void *cb_arg) {

    print("doing stuff\n");

// ##st7789 screen support, comment out this section if not using a st7789 screen
    display = qp_st7789_make_spi_device(320, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 3);
    if (is_keyboard_left()) {
        qp_power(display, true);
        }
    if (is_keyboard_left()) {
        qp_init(display, QP_ROTATION_270);
        }
// If using pointing device on right side, comment out following 3 lines
        // else {
        // qp_init(display, QP_ROTATION_0);
        // }
    if (is_keyboard_left()) {
        image = qp_load_image_mem(gfx_cyberpunk_4_3_ansi_320x240);
        my_font = qp_load_font_mem(font_notosans32);
    }
// If using pointing device on right side, comment out following 3 lines
    // else {
    //     image = qp_load_image_mem(gfx_ZodiarkPiLogoSTpink);
    // }
    // ##end st7789 screen support

    // ##gc9a01 screeen support, comment out this section if not using a gc9a01 screen
    // display = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, 0);
    // qp_power(display, true);
    // if (is_keyboard_left()) {
    //     qp_init(display, QP_ROTATION_0);
    //     }
    // If using pointing device on right side, comment out following 3 lines
    //     else {
    //     qp_init(display, QP_ROTATION_0);
    //     }

    //     if (is_keyboard_left()) {
    //     image = qp_load_image_mem(gfx_ZodiarkPiLogoGC);
    //      }
    // If using pointing device on right side, comment out following 3 lines
    //     else {
    //     image = qp_load_image_mem(gfx_ZodiarkPiLogoGC);
    // }
    // ##end GC9A01 screeen support

    if (image != NULL) {
        print("image was not null\n");
        if (is_keyboard_left()) {
            qp_drawimage(display, 0, 0, image);
            // if (my_font != NULL) {
            //     int16_t width = qp_textwidth(my_font, layer_text);
            //     qp_drawtext(display, (320 - width), (240 - my_font->line_height), my_font, layer_text);
            // }
        }
    // If using pointing device on right side, comment out following 3 lines
        // else {
        //     qp_drawimage(display, 0, 0, image);
        // }
    }


    return(0);
}

void keyboard_post_init_kb(void)
{
    debug_enable=false;
    defer_exec(3000, deferred_init, NULL);
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // toggle the linux flag on/off
        case U_CHG_OS:
            if (record->event.pressed) {
                linux = !linux;
                return false;
            }
        case U_GAMING_TOG:
            if (record->event.pressed) {
                if (!gaming_on) {
                    layer_on(_GAMING);
                    layer_text = "GAMING";
                    gaming_on = true;
                } else {
                    layer_off(_GAMING);
                    layer_text = "DEFAULT";
                    gaming_on = false;
                }
                // if (my_font != NULL) {
                //     int16_t width = qp_textwidth(my_font, layer_text);
                //     qp_drawtext(display, (320 - width), (240 - my_font->line_height), my_font, layer_text);
                // }
                return false;
            }
        // use correct copy shortcut
        case U_CPY:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("c")) : SEND_STRING(SS_LCMD("c"));
                return false;
            }
        // use correct paste shortcut
        case U_PST:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("v")) : SEND_STRING(SS_LCMD("v"));
                return false;
            }
        // use correct cut shortcut
        case U_CUT:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("x")) : SEND_STRING(SS_LCMD("x"));
                return false;
            }
        // use correct undo shortcut
        case U_UND:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("z")) : SEND_STRING(SS_LCMD("z"));
                return false;
            }
        // use correct redo shortcut
        case U_RDO:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("y")) : SEND_STRING(SS_LCMD(SS_LSFT("z")));
                return false;
            }
        // use correct select all shortcut
        case U_SLCTALL:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("a")) : SEND_STRING(SS_LCMD("a"));
                return false;
            }
        // use correct deselect shortcut
        case U_SAVE:
            if (record->event.pressed) {
                linux ? SEND_STRING(SS_LCTL("s")) : SEND_STRING(SS_LCMD("s"));
                return false;
            }
    }

    return true;
}
