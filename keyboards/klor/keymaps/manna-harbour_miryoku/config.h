// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include "custom_config.h"

#define XXX KC_NO

#define LAYOUT_miryoku( \
      K00,  K01,  K02,  K03,  K04,                     K05,  K06,  K07,  K08,  K09, \
      K10,  K11,  K12,  K13,  K14,                     K15,  K16,  K17,  K18,  K19, \
      K20,  K21,  K22,  K23,  K24,                     K25,  K26,  K27,  K28,  K29, \
      N30,  N31,  K32,  K33,  K34,                     K35,  K36,  K37,  N38,  N39 \
) \
LAYOUT_polydactyl( \
      K00,  K01,  K02,  K03,  K04,                     K05,  K06,  K07,  K08,  K09, \
KC_NO,  K10,  K11,  K12,  K13,  K14,                     K15,  K16,  K17,  K18,  K19,  KC_NO, \
KC_NO,  K20,  K21,  K22,  K23,  K24,  KC_NO,         KC_NO,  K25,  K26,  K27,  K28,  K29,  KC_NO , \
                  K32,  K33,  K34,  KC_NO,         KC_NO,  K35,  K36,  K37 \
)

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 100

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

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

// Thumb Combos
#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
  #define COMBO_COUNT 8
  #define COMBO_TERM 200
  #define EXTRA_SHORT_COMBOS
#endif
