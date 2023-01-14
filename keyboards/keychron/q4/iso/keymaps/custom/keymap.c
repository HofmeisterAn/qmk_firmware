#include QMK_KEYBOARD_H

// Enable unicode input mode in keyboards/keychron/q4/iso/config.h
// #define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS, UNICODE_MODE_WINCOMPOSE

enum layers {
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

enum unicode_names {
    DELAE,
    DELOE,
    DELUE,
    DEUAE,
    DEUOE,
    DEUUE,
    DELSS
};

const uint32_t PROGMEM unicode_map[] = {
    [DELAE] = U'ä',
    [DELOE] = U'ö',
    [DELUE] = U'ü',
    [DEUAE] = U'Ä',
    [DEUOE] = U'Ö',
    [DEUUE] = U'Ü',
    [DELSS] = U'ß',
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_iso_62(
        KC_ESC,           KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_BSPC,
        KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_LBRC,          KC_RBRC,
        KC_CAPS,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             KC_H,             KC_J,             KC_K,             KC_L,             KC_SCLN,          KC_QUOT,          KC_NUHS,          KC_ENT,
        KC_LSFT,          KC_NUBS,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_RSFT,
        KC_LCTL,          KC_LOPT,          KC_LGUI,                                                                KC_SPC,                                                                 KC_RGUI,          MO(_FN1),         MO(_FN3),         KC_RCTL),

    [WIN_BASE] = LAYOUT_iso_62(
        KC_ESC,           KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_BSPC,
        KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_LBRC,          KC_RBRC,
        KC_CAPS,          KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             KC_H,             KC_J,             KC_K,             KC_L,             KC_SCLN,          KC_QUOT,          KC_NUHS,          KC_ENT,
        KC_LSFT,          KC_NUBS,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_RSFT,
        KC_LCTL,          KC_LGUI,          KC_LALT,                                                                KC_SPC,                                                                 KC_RALT,          MO(_FN1),         MO(_FN3),         KC_RCTL),

    [_FN1] = LAYOUT_iso_62(
        KC_NO,            KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           KC_DEL,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           KC_PSCR,          XP(DELUE, DEUUE), XP(DELSS, DELSS),
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          XP(DELOE, DEUOE), XP(DELAE, DEUAE), KC_GRV,           KC_NO,
        KC_TRNS,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_TRNS,
        KC_NO,            KC_NO,            KC_NO,                                                                  KC_NO,                                                                  KC_NO,            KC_NO,            KC_NO,            KC_NO),

    [_FN2] = LAYOUT_iso_62(
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,                                                                KC_TRNS,                                                                KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS),

    [_FN3] = LAYOUT_iso_62(
        QK_BOOT,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            RGB_MOD,          RGB_HUI,          RGB_SAI,          RGB_VAI,          UC_NEXT,          KC_NO,            KC_MPLY,          KC_MSTP,          KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            RGB_RMOD,         RGB_HUD,          RGB_SAD,          RGB_VAD,          UC_PREV,          KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT,          KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,                                                                  KC_NO,                                                                  KC_NO,            KC_NO,            KC_NO,            KC_NO),
};

// clang-format on
