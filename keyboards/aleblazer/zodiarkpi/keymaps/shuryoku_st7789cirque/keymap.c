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

char *layer_text = "DEFAULT";
bool gaming_on = false;
bool old_gaming_on = false;

static const int macos = 1000;
static const int linux = 2000;
static const int win = 3000;

/* list of possible os key swaps */
static const int os_options[3] = { macos, linux, win };
static const int max_os_index = (sizeof(os_options)/sizeof(os_options[0])) - 1;
/* default to macos */
int os_index = 0;
int current_os = os_options[0];

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

#include "images/cyberpunk_4_3_ansi_linux_320x240.qgf.c"
#include "images/cyberpunk_4_3_ansi_macos_320x240.qgf.c"
#include "images/cyberpunk_4_3_ansi_win_320x240.qgf.c"

static painter_device_t display;
static painter_image_handle_t image_linux;
static painter_image_handle_t image_macos;
static painter_image_handle_t image_win;

void update_image_os(void)
{
    switch (current_os) {
        case macos:
            qp_drawimage(display, 0, 0, image_macos);
            break;
        case linux:
            qp_drawimage(display, 0, 0, image_linux);
            break;
        case win:
            qp_drawimage(display, 0, 0, image_win);
            break;
        default:
            qp_drawimage(display, 0, 0, image_macos);
    }
}

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
        image_linux = qp_load_image_mem(gfx_cyberpunk_4_3_ansi_linux_320x240);
        image_macos = qp_load_image_mem(gfx_cyberpunk_4_3_ansi_macos_320x240);
        image_win = qp_load_image_mem(gfx_cyberpunk_4_3_ansi_win_320x240);
        update_image_os();
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

    // if (image != NULL) {
    //     if (is_keyboard_left()) {
    //         qp_drawimage(display, 0, 0, image);
    //     }
    // }


    return(0);
}

void keyboard_post_init_kb(void)
{
    debug_enable=false;
    defer_exec(2000, deferred_init, NULL);
}

void inc_dec_os_index(int direction) {
    if (direction == 1) {
        os_index++;
        if (os_index > max_os_index) {
            os_index = 0;
        }
    } else if (direction == -1) {
        os_index--;
        if (os_index < 0) {
            os_index = max_os_index;
        }
    }
    current_os = os_options[os_index];
    update_image_os();
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // cycle through the os options
        case U_CHG_OS:
            if (record->event.pressed) {
                inc_dec_os_index(1);
                return false;
            }
        // toggle the base gaming map
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
                return false;
            }
        // use correct copy shortcut
        case U_CPY:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD("c"));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("c"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("c"));
                        return false;
                }
                return false;
            }
        // use correct paste shortcut
        case U_PST:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD("v"));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("v"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("v"));
                        return false;
                }
                return false;
            }
        // use correct cut shortcut
        case U_CUT:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD("x"));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("x"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("x"));
                        return false;
                }
                return false;
            }
        // use correct undo shortcut
        case U_UND:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD("z"));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("z"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("z"));
                        return false;
                }
                return false;
            }
        // use correct redo shortcut
        case U_RDO:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD(SS_LSFT("z")));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("y"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("y"));
                        return false;
                }
                return false;
            }
        // use correct select all shortcut
        case U_SLCTALL:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD("a"));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("a"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("a"));
                        return false;
                }
                return false;
            }
        // use correct deselect shortcut
        case U_SAVE:
            if (record->event.pressed) {
                switch (current_os) {
                    case macos:
                        SEND_STRING(SS_LCMD("s"));
                        return false;
                    case linux:
                        SEND_STRING(SS_LCTL("s"));
                        return false;
                    case win:
                        SEND_STRING(SS_LCTL("s"));
                        return false;
                }
                return false;
            }
    }

    return true;
}

static fast_timer_t last_encoding_time = 0;
static const fast_timer_t ENCODER_DEBOUNCE = 125;

#ifdef ENCODER_ENABLE

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (TIMER_DIFF_FAST(timer_read_fast(), last_encoding_time) >= ENCODER_DEBOUNCE) {
        last_encoding_time = timer_read_fast();
    }
    else {
        return false;
    }
    if (!encoder_update_user(index, clockwise)) {
      return false; /* Don't process further events if user function exists and returns false */
    }
    if (index == 0) { /* First encoder - left hand */
        if (clockwise) {
            inc_dec_os_index(-1);
        } else {
            inc_dec_os_index(1);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            rgblight_decrease_val();
        } else {
            rgblight_increase_val();
        }

    } else if (index == 2) { /* Third encoder - right hand */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 5);
        } else {
            tap_code_delay(KC_VOLD, 5);
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
