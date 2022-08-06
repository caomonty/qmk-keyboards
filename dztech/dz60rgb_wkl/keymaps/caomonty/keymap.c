#include QMK_KEYBOARD_H

/**************** SOME GLOBALS *********************/

bool onMac = false;
const float led_dim_ratio = 0.50;

/**************** [START] LAYOUT lightning *********************/

/*
[LEDS]
 0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14
15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29
30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,       42,  43
44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,       56,  57
58,  59,  60,            61,                 62,  63,  64,  65,  66,  67

[KEYS]
ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   -,   =,  BCK, INS
TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   [,   ],    \,PGUP
CPS, A,   S,   D,   F,   G,   H,   J,   K,   L,   COL, QOT,  RETURN,PGDN
SFT, Z,   X,   C,   V,   B,   N,   M,   COM, DOT, SLS, SHIFT,    UP, DEL
CTL, GUI, ALT,           SPACEBAR,           ALT, FN, CTL, LFT, DWN, RIT
*/

/**************** [END] LAYOUT lightning *********************/


/***********************  [START] Layer mapping  ************************/


enum layers {
    _QWERTY,
    _UTIL,
    _DESKTOP,
    _DIGITS,
    _WMANAGE,
    _CONFIG,
    _MINE,
};

/***********************  [END] Layer mapping  ************************/


/***********************  [START] Layer lighting mapping  ************************/

//const layers_leds_map[] = {
//    [_WIN] = 29,
//    [_MAC] = 30,
//    [_UTIL] = 14,
//    [_UTIL2] = 15,
//    [_MOUSE] = 16,
//    [_DI] = 17
//};

/***********************  [END] Layer lighting mapping  ************************/


/*********************** MACROS DEFINITION START ************************/


/*********************** MACROS DEFINITION END ************************/

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

// Custom mod-tap
#define MO_7 LT(0, KC_7) // () on hold 7 on tap
#define MO_8 LT(0, KC_8) // [] on hold 8 on tap
#define MO_9 LT(0, KC_9) // {} on hold 9 on tap
#define MO_P LT(0, KC_P) // @ on hold p on tap
#define MO_X LT(0, KC_X) // Cut on hold X on tap
#define MO_C LT(0, KC_C) // Copy on hold C on tap
#define MO_V LT(0, KC_V) // Paste on hold V on tap
#define MO_P LT(0, KC_P)  // P on tap @ on hold
#define ROKA LT(0, KC_HANJ) // change to Romaji input on tap, change to kanji on hold

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

/*********************** [START] keymap ************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_60_tsangan_hhkb(
        KC_GESC , KC_1    , KC_2   , KC_3    , KC_4    , KC_5    , KC_6    , MO_7    , MO_8    , MO_9    , KC_0    , KC_MINS , XXXXXXX , XXXXXXX , XXXXXXX ,
        LT_1       , KC_Q    , KC_W   , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , SYM_AT  , JI_QUOT ,       KC_BSPC  ,
        UTIL        , KC_A    , KC_S   , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_QUOT , KC_ENT  ,         KC_ENT          ,
        KC_LSFT        , KC_Z    , MO_X   , MO_C    , MO_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH ,       SF_UN          ,  CONFI  ,
        XXXXXXX , KC_LALT , KC_LGUI  ,                             KC_SPC                                    , KC_RGUI      , ROKA    ,            XXXXXXX
    ),
    [_MINE] = LAYOUT_60_tsangan_hhkb( // Specifically made for minecraft playing on mac
        // _______ , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        // _______    , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,       _______  ,
        // _______     , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,         _______         ,
        // _______        , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,       _______        , _______ ,
        // _______ , _______ , _______  ,                             _______                                   , _______      , _______ ,            _______
        _______ , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        KC_TAB     , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,       _______  ,
        KC_LCTL     , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,         _______         ,
        KC_DOT         , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,       _______        ,  _______,
        _______ , KC_LGUI , KC_LSFT  ,                             _______                                   , _______      , _______ ,             _______
    ),
    [_UTIL] = LAYOUT_60_tsangan_hhkb(
        KC_PLUS , KC_F1  , KC_F2  , KC_F3   , KC_F4   , KC_F5   , _______ , JI_LBRC , JI_LPRN , JI_LCBR , _______ , KC_EQL  , _______ , _______ , _______ ,
        _______    , KC_F6   , KC_F7  , KC_F8   , KC_F9   , KC_F10  , KC_PGUP , MM_LE ,  KC_UP     , MM_RI   , ACCENT  , KC_DEL  , _______ ,       KC_DEL ,
        _______     , _______ , DESK   , WMANA   , KC_F11  , KC_F12  , KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , KC_SCLN , _______ ,         _______        ,
        KC_CAPS        , _______ , _______, C(KC_C) , _______ , _______ , MM_N    , SP_LE   , _______ , SP_RI   , BSLS    ,       _______       , _______ ,
        _______ , _______ , CGUI     ,                             SPOT                                      , _______      , _______ ,           _______
    ),
    [_DESKTOP] = LAYOUT_60_tsangan_hhkb(
        _______ , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______    , _______ , _______, _______ , _______ , _______ , DC_MENU , DC_NOTI , DC_MISI , DC_DASH , _______ , _______ , _______ ,       _______  ,
        _______     , _______ , _______, _______ , _______ , _______ , DC_DOCK , DC_LEFT , DC_EXPO , DC_RGHT , _______ , _______ ,         _______         ,
        _______        , _______ , _______, _______ , _______ , _______ , DC_TOOL , DC_STAT , DC_DRWR , DC_LPAD , _______ ,       _______        , _______ ,
        _______ , _______ , _______  ,                             DC_HELP                                   , _______      , _______ ,            _______
    ),
    [_WMANAGE] = LAYOUT_60_tsangan_hhkb(  // Window manager layer (macOS, moom)
    _______ , _______ , _______, _______ , _______ , _______ , _______ , KC_7    , KC_8    , KC_9    , _______ , _______ , _______ , _______ , _______ ,
    _______    , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,       _______  ,
    _______     , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,         _______         ,
    _______        , _______ , KC_X   , KC_C    , KC_V    , _______ , _______ , _______ , _______ , _______ , KC_SLSH ,       KC_RO          , _______ ,
    _______ , _______ , _______  ,                             _______                                   , _______      , _______ ,            _______
    ),
    [_DIGITS] = LAYOUT_60_tsangan_hhkb(
        _______ , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______    , _______ , _______, _______ , _______ , _______ , KC_JYEN , KC_P7   , KC_P8   , KC_P9   , KC_PSLS , _______ , _______ ,       _______  ,
        _______     , _______ , _______, _______ , _______ , _______ , KC_DLR  , KC_P4   , KC_P5   , KC_P6   , KC_PAST , _______ ,         _______         ,
        _______        , _______ , _______, _______ , _______ , _______ , KC_EQL  , KC_P1   , KC_P2   , KC_P3   , KC_PMNS ,       _______        , _______ ,
        _______ , _______ , _______  ,                             KC_P0                                     , KC_PPLS      , KC_COMM ,            _______
    ),
    [_CONFIG] = LAYOUT_60_tsangan_hhkb(
        _______ , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
        _______    , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_UP   , _______ ,       _______  ,
        _______     , _______ , _______, _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LEFT , KC_RGHT ,         _______         ,
        _______        , _______ , _______, _______ , _______ , _______ , _______ , MINE    , _______ , _______ , KC_DOWN ,       _______        , _______ ,
        _______ , _______ , _______  ,                             _______                                   , _______      , _______ ,            _______
    )
};

/*********************** [END] keymap ************************/



//**************** [START] MATRIX SCANS Lightning *********************//

// void rgb_matrix_indicators_user(void) {
//
//     #ifdef RGB_MATRIX_ENABLE

    /*Ensure some leds don't completeley turn off if hsv value setting is below 100 in the rgb matrix config */
//    const uint8_t led_constant_val = rgb_matrix_config.hsv.v < 100 ? 100 : rgb_matrix_config.hsv.v;

    // Colors for layar indication
    // main
//    const uint8_t main_hsv_h = 0;
//    const uint8_t main_hsv_s = 255;
    // mac
//    const uint8_t mac_hsv_h = 0;
//    const uint8_t mac_hsv_s = 0;
     // gaming
//    const uint8_t gaming_hsv_h = 191;
//    const uint8_t gaming_hsv_s = 255;
    // const uint8_t gaming_comp_hsv_h = 64;
    // const uint8_t gaming_comp_hsv_s = 255;
//    const uint8_t gaming_second_hsv_h = 234;
//    const uint8_t gaming_second_hsv_s = 255;
    // util
//    const uint8_t util_hsv_h = 149;
//    const uint8_t util_hsv_s = 255;
    // util 2
//    const uint8_t util2_hsv_h = 85;
//    const uint8_t util2_hsv_s = 250;
    // mouse
//    const uint8_t mouse_hsv_h = 30;
//    const uint8_t mouse_hsv_s = 250;

    /* CapsLock LED indicator */
//    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
//        rgb_matrix_set_color_hsv(30, 999, 0, led_constant_val, 0.75); // WHITE
//    }
//    rgb matrix set color all TODO Check this function

    /* Current layer LED indicator */
    // rgb_matrix_set_color_hsv(layers_leds_map[get_highest_layer(layer_state)], 999, 0, led_constant_val, led_dim_ratio); // WHITE



    /* Blinking LED indicator when recording Dynamic Macro */

    /* Blinking LED indicator when playing Dynamic Macro */
    /* END Blinking LED indicator when playing Dynamic Macro */

// Layer indicators
//     switch (biton32(layer_state)) {
// //        case _WIN:
// //            rgb_matrix_set_color(index, r, g, b)
// // rgb(255, 107, 129) wild watermelon
// //            rgb_matrix_set_color_all(255, 107, 129);
// //            break;
// //        case _MAC:
//  //            watermelor color = rgb(255, 71, 87)
// //            rgb_matrix_set_color_all(200, 20, 5);
// //            break;
//         case _MINE:
//             rgb_matrix_set_color_all(255, 107, 129);
//             break;
//         case _UTIL:
//         // ufo green rgb(46, 213, 115)
//             rgb_matrix_set_color_all(46, 213, 115);
//             break;
//         case _UTIL2:
//         // lime soap rgb(123, 237, 159)
//             rgb_matrix_set_color_all(123, 237, 159);
//             break;
//         case _MOUSE:
//         // bright greek rgb(55, 66, 250)
//             rgb_matrix_set_color_all(55, 66, 250);
//             break;
//         case _DI:
//         // saturated sky rgb(83, 82, 237)
//             rgb_matrix_set_color_all(83, 82, 237);
//             break;
//         case _CONFIG: // color yellow as warning
//             rgb_matrix_set_color_all(255, 255, 0);
//             break;
//     }
//
//     #endif /* RGB_MATRIX */
// }

//**************** [END] MATRIX SCANS Lightning *********************//

//**************** [START] Custom tap *********************//

// [START] custom mod tap definition
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO_7:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_RBRC); // intercept hold function to send [] (JIS)
                tap_code16(KC_BSLS);
                tap_code16(KC_LEFT);
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_8:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_ASTERISK); // intercept hold functon to send ()
                tap_code16(KC_LEFT_PAREN);
                tap_code16(KC_LEFT);
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_9:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_RCBR); // intercept hold function to send {}
                tap_code16(KC_PIPE);
                tap_code16(KC_LEFT);
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_P:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_LBRC); // intercept hold function to send @ (JIS
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_X:
            if (!record->tap.count && record->event.pressed){
                tap_code16(G(KC_X)); // intercept hold function to send cmd-X
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_C:
            if (!record->tap.count && record->event.pressed){
                tap_code16(G(KC_C)); // intercept hold function to send # cmd-C
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case MO_V:
            if (!record->tap.count && record->event.pressed){
                tap_code16(G(KC_V)); // intercept hold function to send cmd-V
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
        case ROKA:
            if (!record->tap.count && record->event.pressed){
                tap_code16(KC_HAEN); // intercept hold function to send HAEN
                return false;
            }
            return true;  // Return true for normal processing of tap keycode
    }
    return true;
};

//**************** [END] Custom tap *********************//
