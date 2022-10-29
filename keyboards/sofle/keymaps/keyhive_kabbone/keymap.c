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
  // SOFLE RGB based on Keyhive
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {37+0, 1, hsv}

#define SET_UNDERGLOW(hsv) \
    {1, 1, hsv}, \
    {4, 1, hsv}, \
    {10, 1, hsv}, \
    {13, 1, hsv}, \
    {16, 1, hsv}, \
    {25, 1, hsv}, \
    {28, 1, hsv}, \
    {36, 2, hsv}, \
    {45, 1, hsv}, \
    {48, 1, hsv}, \
    {57, 1, hsv}, \
    {60, 1, hsv}, \
    {63, 1, hsv}, \
    {69, 1, hsv}, \
    {72, 1, hsv}

#define SET_NUMPAD(hsv) \
   {37+15, 5, hsv},\
   {37+22, 3, hsv},\
   {37+27, 3, hsv}

#define SET_NUMROW(hsv) \
   { 5, 2, hsv}, \
   {17, 2, hsv}, \
   {29, 2, hsv}, \
   {43, 2, hsv}, \
   {55, 2, hsv}, \
   {67, 2, hsv}

#define SET_INNER_COL(hsv) \
   {30, 4, hsv}, \
   {40, 4, hsv}

#define SET_OUTER_COL(hsv) \
   {0, 1, hsv}, \
   {2, 2, hsv}, \
   {5, 1, hsv}, \
   {68, 1, hsv}, \
   {70, 2, hsv}, \
   {73, 1, hsv}

#define SET_THUMB_CLUSTER(hsv) \
   {34, 2, hsv}, \
   {38, 2, hsv}

#define SET_LAYER_ID(hsv) \
   {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
   {37+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
   {1, 1, hsv}, \
   {4, 1, hsv}, \
   {10, 1, hsv}, \
   {13, 1, hsv}, \
   {16, 1, hsv}, \
   {25, 1, hsv}, \
   {28, 1, hsv}, \
   {36, 2, hsv}, \
   {45, 1, hsv}, \
   {48, 1, hsv}, \
   {57, 1, hsv}, \
   {60, 1, hsv}, \
   {63, 1, hsv}, \
   {69, 1, hsv}, \
   {72, 1, hsv}, \
   {0, 1, hsv}, \
   {2, 2, hsv}, \
   {5, 1, hsv}, \
   {68, 1, hsv}, \
   {70, 2, hsv}, \
   {73, 1, hsv}, \
   {30, 4, hsv}, \
   {40, 4, hsv}

enum sofle_layers {
    _DEFAULTS = 0,
    _COLEMAKDH = 0,
    _QWERTY,
    _SYM,
    _NAV,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAKDH,
    KC_SYM,
    KC_NAV,
    KC_ADJUST,
    KC_D_MUTE
};

enum unicode_names {
    DESSS,
    DEBAE,
    DESAE,
    DEBOE,
    DESOE,
    DEBUE,
    DESUE
};

const uint32_t PROGMEM unicode_map[] = {
    [DESSS]  = 0x00DF,  // ß
    [DEBAE] = 0x00C4,  // Ä
    [DESAE]  = 0x00E4, // ä
    [DEBOE]  = 0x00D6,  // Ö
    [DESOE] = 0x00F6,  // ö
    [DEBUE]  = 0x00DC, // Ü
    [DESUE]  = 0x00FC, // ü
};

#define UE UC(0x00DC)

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_R LSFT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LALT_T(KC_T)

// Right-hand home row mods
#define HOME_N LALT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I RSFT_T(KC_I)
#define HOME_O RCTL_T(KC_O)
#define RSA_GUI RSA_T(KC_LGUI)
#define UML_A  ALGR(KC_Q)
#define UML_O  ALGR(KC_P)
#define UML_U  ALGR(KC_Y)
#define UML_SS ALGR(KC_S)

#define NAV_DEL LT(_NAV,KC_DEL)
#define SYM_ESC LT(_SYM,KC_ESC)
#define SWI_GUI LT(_SWITCH,KC_LGUI)
#define ADJ_GUI LT(_ADJUST,KC_LGUI)

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HOME_A:
            return true;
        case HOME_R:
            return true;
        case HOME_S:
            return true;
        case HOME_T:
            return true;
        case HOME_N:
            return true;
        case HOME_E:
            return true;
        case HOME_I:
            return true;
        case HOME_O:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYM | Enter| /Space  /       \Enter \  |SPACE |NAV | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,             LT(_SWITCH,KC_6), KC_7,   KC_8,    KC_9,    KC_0,    KC_GRV,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  LT(_NUMPAD,KC_TAB),KC_Q,KC_W,KC_E,  KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  DF(_COLEMAKDH), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  KC_D_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_BSPC, KC_LGUI, KC_SYM, KC_SPC,  KC_ENT   ,     KC_SPC, KC_ENT ,  KC_NAV, KC_RCTRL, KC_RALT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYM | Enter| /Space  /       \Enter \  |SPACE |NAV | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAKDH] = LAYOUT(
  KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5 ,                       KC_6 , KC_7  , KC_8   , KC_9  , KC_0   , KC_ESC ,
  QK_GESC, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B ,                       KC_J , KC_L  , KC_U   , KC_Y  , KC_QUOT, KC_BSLS,
  KC_TAB , HOME_A, HOME_R, HOME_S, HOME_T, KC_G ,                       KC_M , HOME_N, HOME_E , HOME_I, HOME_O , KC_SCLN,
  ADJ_GUI, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V , KC_MUTE,       KC_NO, KC_K , KC_H  , KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
                  KC_LCTRL,KC_LALT,MO(_SYM),KC_LSFT,KC_ENT,       KC_BSPC,KC_SPC, NAV_DEL, KC_LBRC, KC_RBRC
),

/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYM | Enter| /Space  /       \Enter \  |SPACE |NAV | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYM] = LAYOUT(
  _______    , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5 ,                  KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  KC_GRV     , KC_1   , KC_2   , KC_3   , KC_4   , KC_5  ,                  KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_F12 ,
  _______    , KC_DLR , KC_PLUS, KC_LPRN, KC_RPRN, KC_AT ,                  KC_PIPE, KC_MINS, KC_EQL , KC_UNDS, KC_ASTR, _______,
  DF(_QWERTY), KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRV, _______,_______, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
                 RGB_MODE_SWIRL, RGB_VAI, RGB_VAD, RGB_TOG, _______,   KC_BSPC, KC_COLN, _______, _______, _______
),
/* NAV
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYM | /Enter  /       \Space \  |NAV | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_MS_BTN1,KC_MS_BTN2,
  _______, XXXXXXX, KC_PSCR, KC_APP , XXXXXXX, XXXXXXX,                       KC_PGUP , KC_PASTE , KC_COPY, KC_CUT    , KC_UNDO  , KC_BSPC,
  _______, KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, KC_CAPS,                       KC_LEFT , KC_DOWN  , KC_UP  , KC_RGHT   , KC_DEL   , KC_BSPC,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    _______,  KC_PGDN , KC_HOME  , KC_END , KC_INS    , _______  , _______,
                   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|hue^ |sat ^ | bri ^|      |COLEMAK|-------.   ,-------|desk <|      |      |desk >|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYM | /Enter  /       \Space \  |NAV | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, UML_U,   XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, UML_A,   XXXXXXX, UML_SS,   XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UML_O,   XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, KC_LSFT, _______,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYM | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NLCK, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_EQL,  KC_PIPE,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,KC_PLUS, KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | qwer | cole |col_dh| low  | raise| adj  |                    |numpad|      |      |      |      |QK_BOOT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EEP_RST|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYM | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EEP_RST,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  UE,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_NO,    KC_NO,   KC_NO, KC_LSFT,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

	),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
    SET_NUMPAD(HSV_BLUE),
    SET_OUTER_COL(HSV_ORANGE)
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GREEN),
    SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_qwerty_lights,
	layer_num_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_numpad_lights,
	layer_switcher_lights,  // Overrides other layers
	layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
	rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


	rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NAV));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Dane\nEvans"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _COLEMAKDH:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYM\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
                update_tri_layer(_SYM, _NAV, _ADJUST);
            } else {
                layer_off(_SYM);
                update_tri_layer(_SYM, _NAV, _ADJUST);
            }
            return false;
        case KC_NAV:
            if (record->event.pressed) {
                layer_on(_NAV);
                update_tri_layer(_SYM, _NAV, _ADJUST);
            } else {
                layer_off(_NAV);
                update_tri_layer(_SYM, _NAV, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
            case _COLEMAKDH:
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDOWN);
                }
                break;
            case _NAV:
            case _SYM:
                if (clockwise) {
                    tap_code(KC_UP);
                } else {
                    tap_code(KC_DOWN);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
    }
    }
    return true;
}

#endif
