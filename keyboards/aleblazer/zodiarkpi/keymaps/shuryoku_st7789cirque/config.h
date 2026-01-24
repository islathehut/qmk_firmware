#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT

#undef TAPPING_TERM
#define TAPPING_TERM 180

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

// Screen support
#define ST7789_NUM_DEVICES 1
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
#define LCD_RST_PIN GP27
#define LCD_DC_PIN GP28
#define LCD_CS_PIN GP11
#define LCD_SPI_DIVISOR 8
#define QUANTUM_PAINTER_DEBUG
#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true

// Cirque support, comment out if using two screens
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE
#define CIRQUE_PINNACLE_DIAMETER_MM 40
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define POINTING_DEVICE_CS_PIN GP11
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define CIRQUE_PINNACLE_TAPPING_TERM 100
