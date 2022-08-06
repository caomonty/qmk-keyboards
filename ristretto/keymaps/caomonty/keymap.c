/* Copyright 2021 Brandon Lewis
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

enum layers {
    _QWERTY,
    _GAMING,
    _LOWER_R1,
    _UTIL,
    _DESKTOP,
    _DIGITS,
    _WMANAGE,
    _SYMBOLS,
    _CONFIG,
  };

  // enum keycodes {
  //   ROKA = SAFE_RANGE,
  //   ZUNDO,
  //   XCUT,
  //   CCOPY,
  //   VPASTE,
  // };

  // Aliases to shorten code
#define DITAB LT(_DIGITS, KC_TAB) // layer digits when held, tab when tapped
#define MO_SYM MO(_SYMBOLS)
#define NUM_SP LT(_LOWER_R1, KC_SPACE) // layer lower r when held, space when tapped
#define UTIL MO(_UTIL) // change to utility layer while held
#define CONFI MO(_CONFIG) // change to configuration layer while held
#define SF_UN RSFT_T(KC_RO) // shift when held, underscore when tapped
#define SF_CAPS LSFT_T(KC_CAPS) // shift when held, caps when tapped
#define WMANA LM(_WMANAGE, MOD_LCTL | MOD_LALT | MOD_LSFT)  // change to windows management layer
#define DESK MO(_DESKTOP)  // change to desktop control layer
#define SPOT A(G(KC_SPC))  // Open spotlight, It may need to change the hotkey inside configuration
#define SCREEN G(S(KC_4))  // Mac screenshot hotkey
#define TERMF C(S(KC_T))   // New terminal at folder, (it needs configuration inside shortcuts -> services)
#define CGUI C(KC_LGUI) // Control + Left Gui

// Custom mod-tap
#define MO_Q LT(0, KC_Q)
#define MO_W LT(0, KC_W)
#define MO_E LT(0, KC_E)
#define MO_R LT(0, KC_R)
#define MO_T LT(0, KC_T)
#define MO_Y LT(0, KC_Y)
#define MO_U LT(0, KC_U)
#define MO_I LT(0, KC_I)
#define MO_O LT(0, KC_O)
#define MO_P LT(0, KC_P)
#define MO_Z LT(0, KC_Z)
#define MO_X LT(0, KC_X)
#define MO_C LT(0, KC_C)
#define MO_V LT(0, KC_V)
#define MO_P LT(0, KC_P)  // P on tap @ on hold
#define MO_BSPC LT(0, KC_BSPC) // backspace on tap = on hold
#define MO_F LT(0, KC_F) // F on tap cmd + F on hold
// TODO add cmd+f for find

#define MM_LE G(KC_LEFT) // move to the start of the current line (*1)
#define MM_RI G(KC_RGHT) // move to the end of the current line   (*2)
#define SP_LE A(KC_LEFT) // move the caret one word to the left   (*3)
#define SP_RI A(KC_RGHT) // move the caret one word to the right  (*4)
#define BSLS A(KC_JYEN)  // backslash
#define PIPE S(KC_JYEN) // pipe
#define MM_N A(KC_N) // input ˜ character JIS keyboard
#define AMPR S(KC_2)
#define GAMING TG(_GAMING)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /// Characters use to build layout: ┌─┬─┐ └─┴─┘ ├─┼─┤ │
    ///* Blank
    // * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    // * │        │        │        │        │        │        │        │        │        │        │        │        │        │
    // * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    // * │        │        │        │        │        │        │        │        │        │        │        │        │        │
    // * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    // * │        │        │        │        │        │        │        │        │        │        │        │        │        │
    // * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
    // * │        │        │        │        │                 │        │                 │        │        │        │        │
    // * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
    // */
    //[_BLANK] = LAYOUT(
    //  _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______ , _______ ,
    //  _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______ , _______ ,
    //  _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______ , _______ ,
    //  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
    //),
    /* QWERTY
    * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    * │  Tab   │   Q    │    W   │    E   │    R   │   T    │        │   Y    │   U    │    I   │   O    │   P    │ Backsp │
    * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    * │ LayerU │   A    │    S   │    D   │    F   │   G    │        │   H    │   J    │    K   │   L    │   :    │   Ent  │
    * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    * │ Shift  │   Z    │    X   │    C   │    V   │   B    │        │   N    │   M    │    ,   │   .    │   /    │ shift _│
    * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
    * │ Ctl    │  Alt   │ Ro/Ka  │ GUI    │                 │ MUTE   │      Space      │ GUI    │ '      │   '    │ LayerC │
    * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
    */
    [_QWERTY] = LAYOUT(
     DITAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T              , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
     UTIL    , KC_A    , KC_S    , KC_D    , KC_F    , KC_G              , KC_H    , KC_J    , KC_K    , KC_L    , KC_QUOT , KC_ENT  ,
     KC_LSFT , KC_Z    , KC_X    , MO_C    , MO_V    , KC_B              , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
     KC_LCTL , KC_LALT , KC_ESC  , KC_LGUI , KC_SPC  , KC_SPC  , KC_MUTE , KC_SPC  , KC_RCTL , KC_RGUI , GAMING  , AMPR    , CONFI
    ),
    /* QWERTY
    * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    * │  Tab   │   Q    │    W   │    E   │    R   │   T    │        │   Y    │   U    │    I   │   O    │   P    │ Backsp │
    * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    * │ LayerU │   A    │    S   │    D   │    F   │   G    │        │   H    │   J    │    K   │   L    │   :    │   Ent  │
    * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    * │ Shift  │   Z    │    X   │    C   │    V   │   B    │        │   N    │   M    │    ,   │   .    │   /    │ shift _│
    * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
    * │ Ctl    │  Alt   │ Ro/Ka  │ GUI    │                 │ MUTE   │      Space      │ GUI    │ '      │   '    │ LayerC │
    * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
    */
    [_GAMING] = LAYOUT(
     KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T              , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
     KC_LCTL , KC_A    , KC_S    , KC_D    , KC_F    , KC_G              , KC_H    , KC_J    , KC_K    , KC_L    , KC_QUOT , KC_ENT  ,
     KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B              , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
     KC_LCTL , KC_LALT , KC_ESC  , KC_LGUI , _______ , _______ , KC_MUTE , _______ , KC_RCTL , KC_RGUI , _______ , _______ , CONFI
    ),
    /* LOWER_R1
    * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    * │   ESC  │    1   │    2   │    3   │   4    │    5   │        │    6   │    7   │    8   │   9    │   0    │   -    │
    * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    * │        │        │        │        │        │        │        │        │        │        │        │        │        │
    * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
    * │        │        │        │        │        │        │        │        │        │        │        │        │        │
    * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
    * │        │        │        │        │                 │        │                 │        │        │        │        │
    * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
    */
    [_LOWER_R1] = LAYOUT(
     KC_GESC , KC_1    , KC_2    , KC_3    , KC_4    , KC_5              , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS ,
     MO_SYM  , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______ , _______ ,
     SF_CAPS , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
     ),
     /* UTIL
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │                 │        │                 │        │        │        │        │
     * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
     */
     [_UTIL] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , KC_UP   , _______ , _______ , KC_DEL  ,
      _______ , _______ , DESK    , WMANA   , _______ , _______           , _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_SCLN , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , BSLS    , _______ ,
      _______ , _______ , _______ , _______ , MO_SYM  , MO_SYM  , _______ , SPOT    , SPOT    , _______ , _______ , _______ , _______
     ),
     /* DIGITS
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │    ¥   │   7    │   8    │   9    │   /    │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │    $   │   4    │   5    │   6    │   *    │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │    ^   │   1    │   2    │   3    │   -    │        │
     * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │                 │        │        0        │   .    │   ,    │   +    │        │
     * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
     */
     [_DIGITS] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______           , KC_JYEN , KC_P7   , KC_P8   , KC_P9   , KC_PSLS , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______           , KC_DLR  , KC_P4   , KC_P5   , KC_P6   , KC_PAST , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______           , KC_EQL  , KC_P1   , KC_P2   , KC_P3   , KC_PMNS , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_P0   , KC_P0   , KC_COMM , KC_PDOT , KC_PPLS , _______
     ),
     /* Wndows Management
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │                 │        │                 │        │        │        │        │
     * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
     */
     [_WMANAGE] = LAYOUT(
      KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T              , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
      _______ , KC_A    , KC_S    , _______ , KC_F    , KC_G              , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_ENT  ,
      KC_LSFT , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B              , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RO   ,
      KC_LCTL , KC_LALT , KC_UP   , KC_DOWN , KC_LEFT , KC_LEFT , _______ , KC_SPC  , KC_SPC  , KC_M    , KC_COMM , KC_DOT  , _______
     ),
     /* Desktop
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │                 │        │                 │        │        │        │        │
     * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
     */
     [_DESKTOP] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______           , DC_MENU , DC_NOTI , DC_MISI , DC_DASH , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______           , DC_DOCK , DC_LEFT , DC_EXPO , DC_RGHT , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______           , DC_TOOL , DC_STAT , DC_DRWR , DC_LPAD , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , DC_HELP , DC_HELP , _______ , _______ , _______ , _______
     ),
     /* SYMBOLS
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │                 │        │                 │        │        │        │        │
     * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
     */
     [_SYMBOLS] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , KC_RCBR , KC_PIPE , PIPE    , KC_EQL  ,
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , KC_RBRC , KC_BSLS , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , KC_ASTR , KC_LPRN , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
     ),
     /* CONFIG
     * ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │        │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┴────────┼────────┼────────┴────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │                 │        │                 │        │        │        │        │
     * └────────┴────────┴────────┴────────┴─────────────────┴────────┴─────────────────┴────────┴────────┴────────┴────────┘
     */
     [_CONFIG] = LAYOUT(
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , KC_INS  , _______ , _______ , SCREEN  ,
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , _______ , _______ , TERMF   ,
      _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , _______ , KC_UP   , _______ , _______ ,
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , _______
     ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_C:
            if (!record->tap.count && record->event.pressed){
                tap_code16(C(KC_C)); // intercept hold function to send # cmd-C
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_V:
            if (!record->tap.count && record->event.pressed){
                tap_code16(C(KC_V)); // intercept hold function to send cmd-V
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
    }
    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_QWERTY)) {
      if (clockwise) {
        register_code(KC_VOLU);
        unregister_code(KC_VOLU);
      } else {
        register_code(KC_VOLD);
        unregister_code(KC_VOLD);
      }
    }
    return false;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_E:
            return 250;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_E:
            // Do not select the hold action when another key is tapped.
            return false;
        default:
            //  Immediately select the hold action when another key is tapped.
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DITAB:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_ln_P(PSTR("Hola "), false);
    oled_write_ln_P(PSTR("Samy"), false);
    oled_write_P(PSTR("-----\n"), false);
    oled_write_P(PSTR("Modo:\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _UTIL:
            oled_write_P(PSTR("Util \n"), false);
            break;
        case _DESKTOP:
            oled_write_P(PSTR("Desk \n"), false);
            break;
        case _DIGITS:
            oled_write_P(PSTR("Digit\n"), false);
            break;
        case _WMANAGE:
            oled_write_P(PSTR("Manag\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbo\n"), false);
            break;
        case _CONFIG:
            oled_write_P(PSTR("Confi\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undef"), false);
    }
    // // NEW CODE
    oled_write_P(PSTR("-----\n"), false);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
    //

    return false;
}

#endif
