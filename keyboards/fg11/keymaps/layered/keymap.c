/**
 * Copyright 2022 Mark Everitt <hello@qubyte.codes> (@qubyte)
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

enum fg11_layers {
    LAYER_BASE = 0,
    LAYER_SYM,
    LAYER_NUM,
    LAYER_ADJ
};

#define SYM MO(LAYER_SYM)
#define NUM MO(LAYER_NUM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE
   * ┌────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┐
   * │   q    │   w    │   e    │   r    │   t    ││   y    │   u    │   i    │   o    │   p    │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │   a    │   s    │   d    │   f    │   g    ││   h    │   j    │   k    │   l    │   ;    │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │   z    │   x    │   c    │   v    │   b    ││   n    │   m    │   ,    │   .    │   /    │
   * └────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┘
   *                   │ super  │  ctrl  │  SYM   ││  NUM   │  bspc  │ shift  │
   *                   └────────┴────────┴────────┘└────────┴────────┴────────┘
   */
  [LAYER_BASE] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      KC_LGUI, KC_LCTL, SYM,     NUM,     KC_BSPC, KC_LSFT
  ),

  /* SYMBOL
   * ┌────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┐
   * │   !    │   @    │   #    │   $    │   %    ││   ^    │   &    │   *    │   (    │   )    │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │  esc   │   `    │   ~    │        │        ││        │   _    │   +    │   {    │   }    │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │  caps  │        │        │        │        ││        │        │        │   |    │   "    │
   * └────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┘
   *                   │        │        │        ││        │ enter  │        │
   *                   └────────┴────────┴────────┘└────────┴────────┴────────┘
   */
  [LAYER_SYM] = LAYOUT_split_3x5_3(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_ESC,  KC_GRV,  KC_TILD, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
    KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PIPE, KC_DQUO,
                      _______, _______, _______, _______, KC_ENT,  _______
  ),

  /* NUMBER
   * ┌────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┐
   * │   1    │   2    │   3    │   4    │   5    ││   6    │   7    │   8    │   9    │   0    │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │  tab   │  left  │  down  │   up   │ right  ││ shift  │   -    │   =    │   [    │   ]    │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │        │        │        │        │        ││  ctrl  │  alt   │        │   \    │   '    │
   * └────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┘
   *                   │        │ space  │        ││        │        │        │
   *                   └────────┴────────┴────────┘└────────┴────────┴────────┘
   */
  [LAYER_NUM] = LAYOUT_split_3x5_3(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_TAB,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LSFT, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, KC_LCTL, KC_LALT, _______, KC_BSLS, KC_QUOT,
                      _______, KC_SPC,  _______, _______, _______, _______
  ),

  /* FUNCTION (SYM+NUM)
   * ┌────────┬────────┬────────┬────────┬────────┐┌────────┬────────┬────────┬────────┬────────┐
   * │  mute  │  vol-  │  vol+  │  bri-  │  bri+  ││        │   F9   │  F10   │  F11   │  F12   │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │  play  │  prev  │  next  │        │        ││        │   F5   │   F6   │   F7   │   F8   │
   * ├────────┼────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┼────────┤
   * │        │        │        │        │        ││  boot  │   F1   │   F2   │   F3   │   F4   │
   * └────────┴────────┼────────┼────────┼────────┤├────────┼────────┼────────┼────────┴────────┘
   *                   │        │        │        ││        │        │        │
   *                   └────────┴────────┴────────┘└────────┴────────┴────────┘
   */
  [LAYER_ADJ] = LAYOUT_split_3x5_3(
    KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,
    _______, _______, _______, _______, _______, QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,
                      _______, _______, _______, _______, _______, _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, LAYER_SYM, LAYER_NUM, LAYER_ADJ);
}
