// Copyright 2025 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Custom keycodes
enum custom_keycodes {
    PD_AT = SAFE_RANGE,    // @ unshifted, ^ shifted
    PD_AMPR,               // & unshifted, % shifted
    PD_LBRC,               // [ unshifted, 7 shifted
    PD_LCBR,               // { unshifted, 5 shifted
    PD_RCBR,               // } unshifted, 3 shifted
    PD_LPRN,               // ( unshifted, 1 shifted
    PD_EQL,                // = unshifted, 9 shifted
    PD_ASTR,               // * unshifted, 0 shifted
    PD_RPRN,               // ) unshifted, 2 shifted
    PD_PLUS,               // + unshifted, 4 shifted
    PD_RBRC,               // ] unshifted, 6 shifted
    PD_EXLM,               // ! unshifted, 8 shifted
    PD_HASH,               // # unshifted, ` shifted
    PD_DLR,                // $ unshifted, ~ shifted
    PD_SCLN,               // ; unshifted, : shifted
    PD_COMM,               // , unshifted, < shifted
    PD_DOT,                // . unshifted, > shifted
    PD_SLSH,               // / unshifted, ? shifted
    PD_MINS,               // - unshifted, _ shifted
    PD_QUOT,               // ' unshifted, " shifted
    PD_BSLS                // \ unshifted, | shifted
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        PD_DLR,  PD_AMPR, PD_LBRC, PD_LCBR, PD_RCBR, PD_LPRN, PD_EQL,  PD_ASTR, PD_RPRN, PD_PLUS, PD_RBRC, PD_EXLM, PD_HASH, PD_BSLS, PD_AT,
        KC_TAB,  PD_SCLN, PD_COMM, PD_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    PD_SLSH, PD_DLR,  KC_BSPC,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    PD_MINS, KC_ENT,
        KC_LSFT, PD_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, MO(1),
        KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT
    ),

    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______, _______, _______,
        _______, _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
    set_single_persistent_default_layer(0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    // Check if shift is held
    uint8_t mods = get_mods();
    bool shifted = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case PD_AT:    // @ → ^
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(S(KC_6));  // ^
                register_mods(mods);
            } else {
                tap_code16(S(KC_2));  // @
            }
            return false;
            
        case PD_AMPR:  // & → %
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code16(S(KC_5));  // %
                register_mods(mods);
            } else {
                tap_code16(S(KC_7));  // &
            }
            return false;
            
        case PD_LBRC:  // [ → 7
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_7);
                register_mods(mods);
            } else {
                tap_code(KC_LBRC);
            }
            return false;
            
        case PD_LCBR:  // { → 5
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_5);
                register_mods(mods);
            } else {
                tap_code16(S(KC_LBRC));  // {
            }
            return false;
            
        case PD_RCBR:  // } → 3
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_3);
                register_mods(mods);
            } else {
                // For }, we need to send what produces } on YOUR system
                // Since S(KC_GRV) is producing }, use that
                tap_code16(S(KC_GRV));
            }
            return false;
            
        case PD_LPRN:  // ( → 1
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_1);
                register_mods(mods);
            } else {
                tap_code16(S(KC_9));  // (
            }
            return false;
            
        case PD_EQL:   // = → 9
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_9);
                register_mods(mods);
            } else {
                tap_code(KC_EQL);
            }
            return false;
            
        case PD_ASTR:  // * → 0
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_0);
                register_mods(mods);
            } else {
                tap_code16(S(KC_8));  // *
            }
            return false;
            
        case PD_RPRN:  // ) → 2
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_2);
                register_mods(mods);
            } else {
                tap_code16(S(KC_0));  // )
            }
            return false;
            
        case PD_PLUS:  // + → 4
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_4);
                register_mods(mods);
            } else {
                tap_code16(S(KC_EQL));  // +
            }
            return false;
            
        case PD_RBRC:  // ] → 6
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_6);
                register_mods(mods);
            } else {
                tap_code(KC_RBRC);
            }
            return false;
            
        case PD_EXLM:  // ! → 8
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_8);
                register_mods(mods);
            } else {
                tap_code16(S(KC_1));  // !
            }
            return false;
            
        case PD_HASH:  // # → `
            if (shifted) {
                unregister_mods(MOD_MASK_SHIFT);
                tap_code(KC_GRV);  // `
                register_mods(mods);
            } else {
                tap_code16(S(KC_3));  // #
            }
            return false;
            
        case PD_DLR:   // $ → ~
            if (shifted) {
                // For ~, we need to send what produces ~ on YOUR system
                // Since S(KC_RBRC) is producing ~, use that
                tap_code16(S(KC_RBRC));
            } else {
                tap_code16(S(KC_4));  // $
            }
            return false;
            
        case PD_SCLN:  // ; → :
            if (shifted) {
                tap_code16(S(KC_SCLN));
            } else {
                tap_code(KC_SCLN);
            }
            return false;
            
        case PD_COMM:  // , → <
            if (shifted) {
                tap_code16(S(KC_COMM));
            } else {
                tap_code(KC_COMM);
            }
            return false;
            
        case PD_DOT:   // . → >
            if (shifted) {
                tap_code16(S(KC_DOT));
            } else {
                tap_code(KC_DOT);
            }
            return false;
            
        case PD_SLSH:  // / → ?
            if (shifted) {
                tap_code16(S(KC_SLSH));
            } else {
                tap_code(KC_SLSH);
            }
            return false;
            
        case PD_MINS:  // - → _
            if (shifted) {
                tap_code16(S(KC_MINS));
            } else {
                tap_code(KC_MINS);
            }
            return false;
            
        case PD_QUOT:  // ' → "
            if (shifted) {
                tap_code16(S(KC_QUOT));
            } else {
                tap_code(KC_QUOT);
            }
            return false;
            
        case PD_BSLS:  // \ → |
            if (shifted) {
                tap_code16(S(KC_BSLS));
            } else {
                tap_code(KC_BSLS);
            }
            return false;
    }
    
    return true;
}