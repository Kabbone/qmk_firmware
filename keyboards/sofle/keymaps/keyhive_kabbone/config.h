 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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
#pragma once


//#define USE_MATRIX_I2C

/* Select hand configuration */

///https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/


#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding


#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif
//#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
//#define PERMISSIVE_HOLD
//#define RETRO_SHIFT 175
#define AUTO_SHIFT_TIMEOUT 250
//#define RETRO_TAPPING

#define ENCODER_DIRECTION_FLIP


#define RGBLIGHT_SLEEP //Turn off LEDs when computer sleeping (+72)
//
#define RGBLIGHT_LAYERS //Enable layer light indicators. Not required as updates are done in layer_state_set_user and led_update_user (+588).

/* ws2812 RGB LED */
#define RGB_DI_PIN D3


#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 37    // Number of LEDs
#define RGBLED_NUM 37    // Number of LEDs
#define DRIVER_LED_TOTAL RGBLED_NUM
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM

    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
    #define RGBLIGHT_DEFAULT_HUE 30
    #define RGBLIGHT_STATIC_LIGHT
    //#define RGBLIGHT_ANIMATIONS
	//#define RGBLIGHT_EFFECT_BREATHING
	//#define RGBLIGHT_EFFECT_RAINBOW_MOOD
	//#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
	//#define RGBLIGHT_EFFECT_SNAKE
	//#define RGBLIGHT_EFFECT_KNIGHT
	//#define RGBLIGHT_EFFECT_CHRISTMAS
	//#define RGBLIGHT_EFFECT_STATIC_GRADIENT
	//#define RGBLIGHT_EFFECT_RGB_TEST
	//#define RGBLIGHT_EFFECT_ALTERNATING
	//#define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 74
    #define RGBLED_SPLIT {37,37}



    #define RGBLIGHT_LIMIT_VAL 100 // LED Brightness, high power draw may exceed the USB limitations of 0.6A and cause a crash.
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

