/* Copyright 2021 Yiancar-Designs
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
#include QMK_KEYBOARD_H

enum nasu_layers {
  _QWERTY,
  _WINQW,
  _WISHI,
  _UTIL,
  _WUTIL,
  _DESKTOP,
  _DIGITS,
  _WMANAGE,
  _CONFIG,
};

/*********************** [START] Aliases ************************/

// Aliases to shorten code
#define LT_1 LT(_DIGITS, KC_TAB) // layer digits when held, tab when tapped
#define UTIL MO(_UTIL) // change to utility layer while held
#define CONFI MO(_CONFIG) // change to configuration layer while held
#define SF_UN RSFT_T(KC_RO) // shift when held, underscore when tapped
#define WMANA LM(_WMANAGE, MOD_LCTL | MOD_LALT | MOD_LSFT)  // change to windows management layer
#define DESK MO(_DESKTOP)  // change to desktop control layer
#define SPOT A(G(KC_SPC))  // Open spotlight, It may need to change the hotkey inside configuration
#define SCREEN G(S(KC_4))  // Mac screenshot hotkey
#define TERMF C(S(KC_T))   // New terminal at folder, (it needs configuration inside shortcuts -> services)
#define CGUI C(KC_LGUI) // Control + Left Gui
#define MINE TG(_MINE)
#define JP_BACK A(KC_BSPC) // [on mac] delete the whole word
#define DEL_LIN G(KC_BSPC) // delete the whole line

#define SYM_AT KC_LBRC // @ symbol using JIS config

#define MM_LE G(KC_LEFT) // move to the start of the current line (*1)
#define MM_RI G(KC_RGHT) // move to the end of the current line   (*2)
#define SP_LE A(KC_LEFT) // move the caret one word to the left   (*3)
#define SP_RI A(KC_RGHT) // move the caret one word to the right  (*4)
#define BSLS A(KC_JYEN)  // backslash
#define PIPE S(KC_JYEN) // pipe
#define MM_N A(KC_N) // input ˜ character JIS keyboard
#define BACKTIK S(KC_LBRC) // input ` character (JIS)
#define ACCENT A(KC_E) // input spanish accent using JIS
#define JI_LBRC KC_RBRC // input [ using JIS
#define JI_QUOT S(KC_7) // input ' using JIS
#define JI_LCBR S(KC_RBRC) // input { using JIS
#define JI_LPRN S(KC_8) // input ( using JIS
#define ALFRED LGUI(LALT(KC_SPC)) // activate alfred in MacOs

// Windows-specific codes to emulate the JIS keyboard on a US layout setup
#define WUTIL MO(_WUTIL)
#define WISHIFT MO(_WISHI)
#define WI_SLSH KC_SLSH
#define WM_LE A(KC_LEFT) // moves caret to the start of the line
#define WM_RI A(KC_RGHT) // moves caret to the end of the line
#define WP_LE C(KC_LEFT) // moves caret to the start of the previous word
#define WP_RI C(KC_RIGHT) // moves caret tot the next word
#define WI_ON TG(_WINQW) // toggles the layer on or off

// Custom mod-tap
#define MO_7 LT(0, KC_7) // () on hold 7 on tap
#define MO_8 LT(0, KC_8) // [] on hold 8 on tap
#define MO_9 LT(0, KC_9) // {} on hold 9 on tap
#define MO_P LT(0, KC_P) // @ on hold p on tap
#define MO_X LT(0, KC_X) // Cut on hold X on tap
#define MO_C LT(0, KC_C) // Copy on hold C on tap
#define MO_V LT(0, KC_V) // Paste on hold V on tap
#define ROKA LT(0, KC_HANJ) // change to Romaji input on tap, change to kanji on hold
#define DOT_3 LT(0, KC_3) // dot on hold 3 on tap,
#define COMM_2 LT(0, KC_2) // comma on hold, 2 on tap
#define W_SHIFT LT(0, KC_SLSH) // exclusive use for windows underscore and shift

// Desktop control related aliases
#define DC_MENU LCTL(KC_F2) // Move focus to menu bar default keybinding in MacOS
#define DC_DOCK LCTL(KC_F3) // Move focus to dock
#define DC_TOOL LCTL(KC_F5) // Move focus to window toolbar
#define DC_STAT LCTL(KC_F8) // Move focus to status bar side of menu bar
#define DC_DRWR LALT(LGUI(KC_QUOTE)) // Move focus to window drawer
#define DC_LPAD LALT(LGUI(KC_Q)) // Show Launchpad
#define DC_NOTI LALT(LGUI(LCTL(KC_B))) // Show Notification Center
#define DC_DASH LALT(LGUI(LCTL(KC_C))) // Show Dashboard
#define DC_HELP LSFT(LGUI(KC_SLASH)) // Position in menu Help search box
#define DC_LEFT C(KC_LEFT) // move to left desktop
#define DC_RGHT C(KC_RGHT) // move to right desktop
#define DC_EXPO C(KC_DOWN) // show expose
#define DC_MISI C(KC_UP)   // show mission control



/*********************** [END] Aliases ************************/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
[_BLANK] = LAYOUT_alice_split_bs(
 _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,    _______,
 _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,          _______,
          _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,      _______, _______,
          _______,          _______,          _______, _______,               _______,          _______,                                          _______
),

*/
[_QWERTY] = LAYOUT_alice_split_bs(
 KC_ESC , KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,           MO_7   , MO_8   , MO_9   , KC_0   , KC_MINS, KC_EQL , KC_DEL , KC_DEL ,
 KC_PGUP, LT_1   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                 KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,    KC_BSPC,
 KC_PGDN, UTIL   , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J   , KC_K   , KC_L   , KC_QUOT, KC_QUOT,          KC_ENT ,
          KC_LSFT, KC_Z   , MO_X   , MO_C   , MO_V   , KC_B   ,               ROKA   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,      SF_UN  , CONFI  ,
          KC_LALT,          KC_LGUI,          ALFRED , ROKA   ,               KC_SPC ,          KC_LCTL,                                          CONFI
),

[_WINQW] = LAYOUT_alice_split_bs(
KC_ESC , KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,           MO_7   , MO_8   , MO_9   , KC_0   , KC_MINS, KC_EQL , KC_DEL , KC_DEL ,
KC_PGUP, LT_1   , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                 KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,    KC_BSPC,
KC_PGDN, WUTIL  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J   , KC_K   , KC_L   , KC_QUOT, KC_QUOT,          KC_ENT ,
         WISHIFT, KC_Z   , MO_X   , MO_C   , MO_V   , KC_B   ,               ROKA   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,      SF_UN  , CONFI  ,
         KC_LALT,          KC_LGUI,          ALFRED , ROKA   ,               KC_SPC ,          KC_LCTL,                                          CONFI
),

[_UTIL] = LAYOUT_alice_split_bs(
 _______, KC_PLUS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,           _______, KC_AMPR, BACKTIK, PIPE   , KC_EQL , _______, _______, DEL_LIN,
 _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                 KC_PGUP, MM_LE  , KC_UP  , MM_RI  , ACCENT , _______, _______,    JP_BACK,
 _______, _______, _______, DESK   , WMANA  , KC_F11 , KC_F12 ,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, _______,          _______,
          _______, _______, _______, _______, _______, _______,               _______, MM_N   , SP_LE  , _______, SP_RI  , KC_BSLS,      _______, _______,
          _______,          _______,          CGUI   , _______,               SPOT   ,          _______,                                          _______
),

[_WUTIL] = LAYOUT_alice_split_bs(
 _______, KC_PLUS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,           _______, KC_AMPR, BACKTIK, PIPE   , KC_EQL , _______, _______, _______,
 _______, _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                 KC_PGUP, MM_LE  , KC_UP  , MM_RI  , _______, _______, _______,    KC_DEL ,
 _______, _______, _______, DESK   , WMANA  , KC_F11 , KC_F12 ,                    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, _______,          _______,
          _______, _______, _______, _______, _______, _______,               _______, MM_N   , WP_LE  , _______, WP_RI  , KC_BSLS,      _______, _______,
          _______,          _______,          _______, _______,               _______,          _______,                                          _______
),

[_DESKTOP] = LAYOUT_alice_split_bs(
 _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,                 DC_MENU, DC_NOTI, DC_MISI, DC_DASH, _______, _______, _______,    _______,
 _______, _______, _______, _______, _______, _______, _______,                    DC_DOCK, DC_LEFT, DC_EXPO, DC_RGHT, _______, _______,          _______,
          _______, _______, _______, _______, _______, _______,               _______, DC_TOOL, DC_STAT, DC_DRWR, DC_LPAD, _______,      _______, _______,
          _______,          _______,          _______, _______,               DC_HELP,          _______,                                          _______
),

[_DIGITS] = LAYOUT_alice_split_bs(
 _______, _______, _______, _______, _______, _______, _______, _______,           _______, KC_RCBR, KC_PIPE, KC_PMNS, KC_PPLS, _______, _______, _______,
 _______, _______, _______, _______, _______, _______, _______,                 KC_JYEN, KC_7   , KC_8   , KC_9   , KC_PAST, _______, _______,    _______,
 _______, _______, _______, _______, _______, _______, _______,                    KC_DLR , KC_4   , KC_5   , KC_6   , KC_PSLS, _______,          _______,
          _______, _______, _______, _______, _______, _______,               KC_SPC , KC_EQL , KC_1   , KC_2   , KC_3   , KC_COMM,      _______, _______,
          _______,          _______,          _______, _______,               KC_0   ,          KC_PDOT,                                          _______
),

[_WMANAGE] = LAYOUT_alice_split_bs(
 _______, KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,           KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, _______, _______, KC_MINS,
 _______, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                 KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______, _______,    KC_BSPC,
 _______, _______, KC_A   , _______, KC_D   , KC_F   , KC_G   ,                    KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,          KC_ENT ,
          KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,               _______, KC_N   , KC_M   , KC_COMM, KC_DOT , _______,      _______, KC_RO  ,
          KC_LCTL,          KC_LALT,          KC_SPC , KC_LGUI,               KC_SPC ,          KC_M   ,                                          _______
),

[_CONFIG] = LAYOUT_alice_split_bs(
 _______, _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, KC_UP  , _______, SCREEN ,
 _______, _______, _______, WI_ON  , _______, _______, _______,                 _______, _______, KC_INS , _______, _______, KC_LEFT, KC_RGHT,    _______,
 _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, KC_DOWN,          TERMF  ,
          _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,      _______, _______,
          _______,          _______,          _______, _______,               _______,          _______,                                          _______
),

};


// [START] Layer indication with light layer_state_t
// layer_state_set_user(layer_state_t state){ switch (get_highest_layer(state))
// { case _UTIL: writePin(B0, false); break; // case _DESKTOP: //
// PLAY_SONG(desktop_on); //   break; // case _DIGITS: //
// PLAY_SONG(numeric_on); //   break; // case _WMANAGE: //
// PLAY_SONG(windows_on); //   break; // case _CONFIG: //
// PLAY_SONG(config_on); //   break; } return state; }

// [END] Layer indication with sound



// [START] custom mod tap definition
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_8:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(KC_LPRN);
                    tap_code16(KC_RPRN);
                    tap_code16(KC_LEFT);
                }
                else {
                    tap_code16(KC_ASTERISK); // intercept hold functon to send ()
                    tap_code16(KC_LEFT_PAREN);
                    tap_code16(KC_LEFT);

                }
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_7:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(KC_LBRC); // send [] on windows
                    tap_code16(KC_RBRC);
                    tap_code16(KC_LEFT);
                }
                else {
                    tap_code16(KC_RBRC); // intercept hold function to send [] (JIS)
                    tap_code16(KC_BSLS);
                    tap_code16(KC_LEFT);
                }

                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_9:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(KC_LCBR);
                    tap_code16(KC_RCBR);
                    tap_code16(KC_LEFT);
                }
                else {
                    tap_code16(KC_RCBR); // intercept hold function to send {}
                    tap_code16(KC_PIPE);
                    tap_code16(KC_LEFT);
                }

                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_P:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(S(KC_2)); // send @ on windows
                }
                else {
                    tap_code16(KC_LBRC); // intercept hold function to send @ (JIS
                }

                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_X:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(C(KC_X)); // cut on windows
                }
                else {
                    tap_code16(G(KC_X)); // intercept hold function to send cmd-X
                }

                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_C:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(C(KC_C)); // copy on windows
                }
                else {
                    tap_code16(G(KC_C)); // intercept hold function to send # cmd-C
                }

                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_V:
            if (!record->tap.count && record->event.pressed){
                if (biton32(layer_state) == _WINQW) {
                    tap_code16(C(KC_V)); // paste on windows
                }
                else {
                    tap_code16(G(KC_V)); // intercept hold function to send cmd-V
                }

                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case ROKA:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_HAEN); // intercept hold function to send HAEN
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case COMM_2:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_COMM); // intercept hold function to send comma
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case DOT_3:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_DOT); // intercept hold function to send dot
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case W_SHIFT:
            if (record->tap.count && record->event.pressed){
                tap_code16(KC_UNDS); // intercept tap function to send _
            } else if (record->event.pressed){
                // intercept hold function to press
                layer_on(_WISHI);
            } else {
                layer_off(_WISHI); // intercept hold function button release
            }
            return false;  // Return false to avoid normal processing of mod-tap
    }
    return true;
};

// try to enable rolling motion on custom mod-tap key to a better performance while fast typing
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        case W_SHIFT:
            return true; // immediately select the hold action when another key is pressed
        default:
            return false; // other keys behave as normal
    }
}
// [END] custom mod tap definition
