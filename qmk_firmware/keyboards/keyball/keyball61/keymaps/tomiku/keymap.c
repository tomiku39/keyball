/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum.h"

// clang-format off
// キー配置はdefaultで持ってくるとかRemapで変更する等してください。
// レイヤでLEDの色が変わるようにするとどうやらTO()等でレイヤを移動する時にレイヤ番号が変わるらしく、RemapでTO(1)等と設定してもLEDの色は変わりません。
// ここのキーマップで設定したレイヤ番号とRemapで表示されている内容を照らし合わせてCustomのCode(Hex)に設定するとVIA上で設定したレイヤ移動でも色が変化しました。（正しい使い方なのかはわかりません。）
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_universal(
  KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
  KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
  KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
  KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,   KC_RBRC  ,            KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RO    ,
  KC_LCTL  , KC_LCTL  , KC_LALT  , KC_LGUI,LT(1,KC_GRV),LT(2,KC_MHEN),LT(3, KC_SPC),        KC_BSPC, KC_ENT   , _______  , _______  , _______  , KC_RALT  , KC_RCTL
),

[1] = LAYOUT_universal(
  S(KC_ESC),KC_NO    , KC_NO    , KC_NO    , KC_NO     , KC_NO   ,                              KC_NUM_LOCK  , KC_7     , KC_8     , KC_9    , _______  , KC_EQL  ,
  _______ , KC_NO    , KC_NO    , KC_NO    , KC_NO     , KC_NO   ,                                  _______  , KC_4     , KC_5     , KC_6    , _______  , _______  ,
  _______ , KC_NO    , KC_NO    , KC_RBRC  , S(KC_RBRC), KC_NO   ,                                  _______  , KC_1     , KC_2     , KC_3    , _______  , _______  ,
  _______ , KC_NO    , KC_NO    , KC_NUHS  , S(KC_NUHS), KC_NO   , _______  ,            KC_INT3  , _______  , KC_0     , KC_DOT   , KC_COMM , _______  , _______  ,
  _______ , _______  , _______  , _______  , _______   , _______ , _______  ,            _______  , _______  , _______  , _______  , _______ , _______  , _______
),

[2] = LAYOUT_universal(
  _______,_______                    , _______  , _______  , _______  , _______ ,                       _______  , _______  , _______  , _______  , _______ , _______ ,
  TO(0)  ,S(LCTL(LALT(LGUI(KC_F12)))), KC_NO    , KC_NO    , KC_NO    , KC_NO   ,                       KC_BTN5  , KC_HOME  , KC_UP    , KC_END   ,KC_PAGE_UP, _______ ,
  _______,LCTL(KC_A)                 , KC_NO    , KC_NO    , TO(0)    , KC_NO   ,                      KC_BTN4  , KC_LEFT  , KC_DOWN  , KC_RGHT,KC_PAGE_DOWN, _______  ,
  _______,LCTL(KC_Z)                 ,LCTL(KC_X),LCTL(KC_C),LCTL(KC_V), TO(0)   , TO(0)  ,    TO(0)   , SCRL_TO  , KC_BTN1  , KC_BTN2  , SCRL_MO  , KC_BTN3  , _______  ,
  _______,_______                    , _______  , _______  , _______  , _______, _______ ,     KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
),


[3] = LAYOUT_universal(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
  _______ , COUNT_U , THR_U   , _______ , KC_PSCR  , KC_PAUS  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KC_F12   ,
  _______ , COUNT_D , THR_D   , _______ , KC_INS   , TO(1)    ,                                  _______  , _______  , KC_MSTP  , _______  , KC_VOLU  , KBC_RST  ,
  _______ , _______ , _______ , _______ , _______  , TO(0)    ,   TO(2)  ,            KC_MUTE  , KC_MSTP  , KC_MPRV  , KC_MPLY  , KC_MNXT  , KC_VOLD  , KBC_SAVE ,
  _______ , _______ , _______ , _______ , _______  , _______  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , EEP_RST
),
};

#if defined(RGBLIGHT_ENABLE) && defined(RGBLIGHT_LAYERS)
// LEDの色が左手のみ変わっていますが、数値を74とかに変えても右手が変わってくれなかったため左手のみのままでやりました。
// 普通にできると思うので必要に応じて設定してみてください。
// レイヤ0の色指定
const rgblight_segment_t PROGMEM ZERO_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{0, 34, HSV_CYAN}
);
// レイヤ1の色指定
const rgblight_segment_t PROGMEM ONE_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{0, 34, HSV_GREEN}
);
// レイヤ2の色指定
const rgblight_segment_t PROGMEM TWO_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{0, 34, HSV_YELLOW}
);
// レイヤ3の色指定
const rgblight_segment_t PROGMEM THREE_layer[] = RGBLIGHT_LAYER_SEGMENTS(
{0, 34, HSV_RED}
);

const rgblight_segment_t* const PROGMEM user_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
ZERO_layer,
ONE_layer,
TWO_layer,
THREE_layer
);
int16_t abs(int16_t num) {
    if (num < 0) {
        num = -num;
    }
    return num;
}



uint8_t pointingDeviceLayer_moveCount = 0;
uint8_t countThreshold = 10;
uint8_t threshold = 10;


// トラックボールが動いた時のフック
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    int16_t current_x = abs(mouse_report.x);
    int16_t current_y = abs(mouse_report.y);

    // thresholdの数値を変えてどれぐらいの速度でトラックボールを動かしたらレイヤを変更するか調整
    if ((current_x > threshold || current_y > threshold)) {
        // 移動先レイヤの数字を入れる
        if(pointingDeviceLayer_moveCount > countThreshold){
          layer_move(2);
          pointingDeviceLayer_moveCount = 0;
        } else {
              pointingDeviceLayer_moveCount++;
        }
  }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
      pointingDeviceLayer_moveCount = 0;
      switch(keycode){
        case THR_U:
            threshold++;
            if(threshold > 100){
                threshold = 100;
            }
            break;
        case THR_D:
            threshold--;
            if(threshold < 1){
                threshold = 1;
            }
            break;
        case COUNT_U:
            countThreshold++;
            if(countThreshold > 100){
                countThreshold = 100;
            }
            break;
        case COUNT_D:
            countThreshold--;
            if(countThreshold < 1){
                countThreshold = 1;
            }
            break;
    default:
        return true;
      }
    }


    return true;
}


void keyboard_post_init_user(void) {
    rgblight_layers = user_rgb_layers;
}

// clang-format on
// レイヤガ切り替わったときのフック
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));

    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}
#endif

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo(pointingDeviceLayer_moveCount, threshold, countThreshold);

}
#endif
