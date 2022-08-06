/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum layers{
    _QWERTY,
    _QWERTY2,
    _NUM,
    _CONFIG
};

enum custom_keycodes {
	KX_A = SAFE_RANGE,
    KX_E,
	KX_I,
	KX_O,
	KX_U,
	KX_N,
};

#define KC_WAVE S(KC_GRV)
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define UT_CAP LT(_QWERTY2, KC_CAPS)
#define UT_ENT LT(_QWERTY2, KC_ENT)
#define UT_TAB LT(_NUM, KC_TAB)

#define TOCONFI MO(_CONFIG)

bool g_bOsNumLockOn = false;

void led_set_user(uint8_t usb_led) {

	// Update saved numlock state

	if (usb_led & (1<<USB_LED_NUM_LOCK))
	{
		g_bOsNumLockOn = true;
	}
	else
	{
		g_bOsNumLockOn = false;
	}
}

void send_altcode(uint16_t mask, keyrecord_t *record) {

	/* Sends the "alt code" defined in mask, i.e. send_altcode(1234)
	holds left alt while sending KP_1, KP_2, KP_3 and KP_4 taps,
	then releases left alt if it wasn't being held by the user.

	NOTE: If your alt code starts with a 0, leave that out, else the
	mask will be treated as octal and your firmware won't compile.
	send_altcode(123) will output KP_0, KP_1, KP_2 and KP_3. */

	// Check & save mod state

	static uint8_t lalt_mask;
	lalt_mask = keyboard_report->mods & KC_LALT;

	// Check & save numlock state

	bool bNumLockWasOn = g_bOsNumLockOn;

	// Split up the mask into its 4 decimals

	static uint16_t kp[4];

	kp[0] = mask / 1000;
	kp[1] = mask / 100 - kp[0] * 100;
	kp[2] = mask / 10 - kp[0] * 1000 - kp[1] * 10;
	kp[3] = mask - kp[0] * 1000 - kp[1] * 100 - kp[2] * 10;

	// Convert to keycodes

	for (uint8_t i=0; i<=3; i++) {
		switch(kp[i]) {
			case 0:
				kp[i] = KC_KP_0; break;
			case 1:
				kp[i] = KC_KP_1; break;
			case 2:
				kp[i] = KC_KP_2; break;
			case 3:
				kp[i] = KC_KP_3; break;
			case 4:
				kp[i] = KC_KP_4; break;
			case 5:
				kp[i] = KC_KP_5; break;
			case 6:
				kp[i] = KC_KP_6; break;
			case 7:
				kp[i] = KC_KP_7; break;
			case 8:
				kp[i] = KC_KP_8; break;
			case 9:
				kp[i] = KC_KP_9; break;
		}
	}

	// Put ALT into pressed state

	if (!lalt_mask) {
		register_code(KC_LALT);
		send_keyboard_report();
	}

	// If not enabled, enable numlock

	if (!bNumLockWasOn) {
			register_code(KC_LNUM);
			send_keyboard_report();
	}

	// The send_keyboard_report() spam is not pretty, but necessary.

	add_key(kp[0]);
	send_keyboard_report();
	del_key(kp[0]);
	send_keyboard_report();
	add_key(kp[1]);
	send_keyboard_report();
	del_key(kp[1]);
	send_keyboard_report();
	add_key(kp[2]);
	send_keyboard_report();
	del_key(kp[2]);
	send_keyboard_report();
	add_key(kp[3]);
	send_keyboard_report();
	del_key(kp[3]);
	send_keyboard_report();

	// If user wasn't pressing ALT, release it

	if (!lalt_mask) {
		unregister_code(KC_LALT);
	}

	send_keyboard_report();

	// If it wasn't enabled before, disable numlock

	if (!bNumLockWasOn) {
			unregister_code(KC_LNUM);
			send_keyboard_report();
	}
}

// [START] Define here the custom alt keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	static uint8_t shift_mask;
	shift_mask = get_mods()&MODS_SHIFT_MASK;

	if (record->event.pressed) {
		switch(keycode) {
		case KX_A:
			if (shift_mask) { // We want a capital version of the German A Umlaut 'cause shift is pressed
				unregister_code(KC_LSFT); // Gotta temporarily disable both shift keys, else this whole thing may behave oddly
				unregister_code(KC_RSFT);
				send_keyboard_report();

				send_altcode(193, record); // Á

				if (shift_mask &MOD_BIT(KC_LSFT)) register_code(KC_LSFT); // Restore shift keys to previous state
				if (shift_mask &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

				send_keyboard_report();
			} else {
				send_altcode(225, record); // á
			}
			return false;
			break;
        case KX_E:
    			if (shift_mask) { // We want a capital version of the German A Umlaut 'cause shift is pressed
    				unregister_code(KC_LSFT); // Gotta temporarily disable both shift keys, else this whole thing may behave oddly
    				unregister_code(KC_RSFT);
    				send_keyboard_report();

    				send_altcode(201, record); // É

    				if (shift_mask &MOD_BIT(KC_LSFT)) register_code(KC_LSFT); // Restore shift keys to previous state
    				if (shift_mask &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

    				send_keyboard_report();
    			} else {
    				send_altcode(233, record); // é
    			}
    			return false;
    			break;
		case KX_I:
			if (shift_mask) {
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				send_keyboard_report();

				send_altcode(205, record); // Í

				if (shift_mask &MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
				if (shift_mask &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

				send_keyboard_report();
			} else {
				send_altcode(237, record); // í
			}
			return false;
			break;
		case KX_O:
			if (shift_mask) {
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				send_keyboard_report();

				send_altcode(211, record); // Ó

				if (shift_mask &MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
				if (shift_mask &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

				send_keyboard_report();
			} else {
				send_altcode(243, record); // ó
			}
			return false;
			break;
        case KX_U:
            if (shift_mask) {
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);
                send_keyboard_report();

                send_altcode(218, record); // Ú

                if (shift_mask &MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
                if (shift_mask &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

                send_keyboard_report();
            } else {
                send_altcode(250, record); // ú
            }
            return false;
            break;
        case KX_N:
			if (shift_mask) {
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				send_keyboard_report();

				send_altcode(209, record); // Ñ

				if (shift_mask &MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
				if (shift_mask &MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

				send_keyboard_report();
			} else {
				send_altcode(241, record); // ñ
			}
			return false;
			break;
		}
	}

	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ansi_67(
        // _______,  _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,    _______,    _______,
        // _______,    _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______,    _______,
        // _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,       _______,
        // _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______,     _______,           _______,
        // _______, _______, _______,                            _______,                             _______, _______, _______,                             _______, _______, _______

        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        UT_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        UT_CAP,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            UT_ENT,           KC_HOME,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LCMD, KC_LOPT,                            KC_SPC,                             KC_RCMD, XXXXXXX, TOCONFI, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_QWERTY2] = LAYOUT_ansi_67(
        _______,  _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,    _______,    _______,
        _______,    _______,   _______,    KX_E   ,    _______,    _______,    _______,    KX_U   ,   KX_I   ,    KX_O   ,    _______,    _______,  _______,  _______,    _______,
        _______,     KX_A   ,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______  ,    _______,       _______,       _______,
        _______,        _______,    _______,    _______,    _______,    _______,    KX_N   ,    _______,    _______,   _______,    _______,     _______,           _______,
        _______, KC_LOPT, KC_LCMD,                            _______,                             _______, _______, _______,                             _______, _______, _______
    ),
    [_NUM] = LAYOUT_ansi_67(
        _______,  KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,   KC_F5  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,  KC_F12 ,    _______,    _______,
        _______,    _______,   _______,    _______,    _______,    _______,    _______,    KC_P7  ,    KC_P8  ,    KC_P9  ,    KC_PSLS,    _______,  _______,  _______,    _______,
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    KC_P4  ,    KC_P5  ,    KC_P6  ,    KC_PAST,    _______,       _______,       _______,
        _______,       _______,    _______,    _______,    _______,    _______,    _______,    KC_P1  ,    KC_P2  ,   KC_P3  ,    KC_PMNS,     _______,           _______,
        _______, _______, _______,                            KC_P0  ,                             KC_PDOT, KC_PPLS, _______,                             _______, _______, _______
    ),
    [_CONFIG] = LAYOUT_ansi_67(
        _______,  _______,    _______,    _______,    _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,    _______,    _______,
        _______,    _______,   RGB_MOD,    RGB_HUI,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,  _______,  _______,    _______,
        _______,     _______,    RGB_RMOD,   RGB_HUD,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,       _______,
        _______,        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______,     _______,           KC_ASON,
        _______, _______, _______,                            _______,                             _______, _______, _______,                             _______, KC_ASOFF, _______
    ),

};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? 1 : 0));
    }
    return false;
}

//
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) > 1) {
        if (index == 0) {
            if (clockwise) {
                rgb_matrix_increase_hue();
            } else {
                rgb_matrix_decrease_hue();
            }
        }
    } else {  /* Layer 0 */
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return false;
}
#endif
