/* Copyright
 *   2021 solartempest
 *   2021 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keyhive.h"

#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6    7  8  9  10 11 12 13
  //                                            ROWS
  // 5  6  17 18 29 30         43 44 55 56 67 68  0
  // 4     16    28               45    57    69  1  // Underglow
  // 3  7  15 19 27 31         42 46 54 58 66 70  2
  // 2  8  14 20 26 32         41 47 53 59 65 71  3
  // 1     13    25               48    60    72  4  // Underglow
  // 0  9  12 21 24 33         40 49 52 61 64 73  5
  //       11 22 23 34 35   38 39 50 51 62        6
  //    10             36   37             63        // Underglow



led_config_t g_led_config = {
    {
        {  5,    6,  17,  18,  29,  30},
        {  3,    7,  15,  19,  27,  31},
        {  2,    8,  14,  20,  26,  32},
        {  0,    9,  12,  21,  24,  33},
        {            11,  22,  23,  34,  35,  NO_LED },
        {               43,  44,  55,  56,  67,  68},
        {               42,  46,  54,  58,  66,  70},
        {               41,  47,  53,  59,  65,  71},
        {               40,  49,  52,  61,  64,  73},
        {  NO_LED, 38,  39,  50,  51,  62}
    },
    {
        // Left side Matrix leds are positioned column wise
        // 1
        {0, 48}, {0, 44}, {0, 36}, {0, 24}, {0, 20}, {0, 12},
        // 2
        {16, 12}, {16, 24}, {16, 36}, {16, 48}, {20, 53},
        // 3
        {32, 57}, {32, 45}, {32, 41}, {32, 33}, {32, 21}, {32, 17}, {32, 9},
        // 4
        {48, 7}, {48, 19}, {48, 31}, {48, 43}, {48, 55},
        // 5
        {64, 57}, {64, 45}, {64, 41}, {64, 33}, {64, 21}, {64, 17}, {64, 9},
        // 6
        {80, 10}, {80, 22}, {80, 34}, {80, 46}, {84, 60},
        // 7
        {96, 64}, {100, 57},

        
        // Right side Matrix leds are positioned column wise
        // 8
        {124, 57}, {128, 64},
        // 9
        {140, 60}, {144, 46}, {144, 34}, {144, 22}, {144, 10},
        // 10
        {160, 9}, {160, 17}, {160,21 }, {160, 33}, {160, 41}, {160, 45}, {160, 57},
        // 11
        {176, 53}, {176, 48}, {176, 36}, {176, 24}, {176, 12},
        // 12
        {192, 9}, {192, 17}, {192, 21}, {192, 33}, {192, 41}, {192, 45}, {192, 57},
        // 13
        {208, 53}, {208, 48}, {208, 36}, {208, 24}, {208, 12},
        // 14
        {224, 12}, {224, 20}, {224, 24}, {224, 36}, {224, 44}, {224, 48},
    },
    {
        LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_NONE,
        LED_FLAG_NONE,      LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT,  LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT,  LED_FLAG_KEYLIGHT, LED_FLAG_UNDERGLOW, LED_FLAG_KEYLIGHT
    }
};
#endif
