/*
  modes_esp.h - WS2812FX header file for ESP8266 and ESP32 microprocessors

  LICENSE

  The MIT License (MIT)

  Copyright (c) 2016  Harm Aldick

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.


  CHANGELOG

  2022-03-23   Separated from the original WS2812FX.h file
*/
#ifndef mode_h
#define mode_h

#include "WS2812FX.h"
#include <stdint.h>

#define MODE_COUNT (sizeof(_modes)/sizeof(_modes[0]))
#define MODE_PTR(x) _modes[x].mode_ptr
#define MODE_NAME(x) _modes[x].name

// 显示效果枚举
typedef enum
{
    FX_MODE_STATIC=0,
    FX_MODE_BLINK,
    FX_MODE_BREATH,
    FX_MODE_COLOR_WIPE,
    FX_MODE_COLOR_WIPE_INV,
    FX_MODE_COLOR_WIPE_REV,
    FX_MODE_COLOR_WIPE_REV_INV,
    FX_MODE_COLOR_WIPE_RANDOM,
    FX_MODE_RANDOM_COLOR,
    FX_MODE_SINGLE_DYNAMIC,
    FX_MODE_MULTI_DYNAMIC,
    FX_MODE_RAINBOW,
    FX_MODE_RAINBOW_CYCLE,
    FX_MODE_SCAN,
    FX_MODE_DUAL_SCAN,
    FX_MODE_FADE,
    FX_MODE_THEATER_CHASE,
    FX_MODE_THEATER_CHASE_RAINBOW,
    FX_MODE_RUNNING_LIGHTS,
    FX_MODE_TWINKLE,
    FX_MODE_TWINKLE_RANDOM,
    FX_MODE_TWINKLE_FADE,
    FX_MODE_TWINKLE_FADE_RANDOM,
    FX_MODE_SPARKLE,
    FX_MODE_FLASH_SPARKLE,
    FX_MODE_HYPER_SPARKLE,
    FX_MODE_STROBE,
    FX_MODE_STROBE_RAINBOW,
    FX_MODE_MULTI_STROBE,
    FX_MODE_BLINK_RAINBOW,
    FX_MODE_CHASE_WHITE,
    FX_MODE_CHASE_COLOR,
    FX_MODE_CHASE_RANDOM,
    FX_MODE_CHASE_RAINBOW,
    FX_MODE_CHASE_FLASH,
    FX_MODE_CHASE_FLASH_RANDOM,
    FX_MODE_CHASE_RAINBOW_WHITE,
    FX_MODE_CHASE_BLACKOUT,
    FX_MODE_CHASE_BLACKOUT_RAINBOW,
    FX_MODE_COLOR_SWEEP_RANDOM,
    FX_MODE_RUNNING_COLOR,
    FX_MODE_RUNNING_RED_BLUE,
    FX_MODE_RUNNING_RANDOM,
    FX_MODE_LARSON_SCANNER,
    FX_MODE_COMET,
    FX_MODE_FIREWORKS,
    FX_MODE_FIREWORKS_RANDOM,
    FX_MODE_MERRY_CHRISTMAS,
    FX_MODE_FIRE_FLICKER,
    FX_MODE_FIRE_FLICKER_SOFT,
    FX_MODE_FIRE_FLICKER_INTENSE,
    FX_MODE_CIRCUS_COMBUSTUS,
    FX_MODE_HALLOWEEN,
    FX_MODE_BICOLOR_CHASE,
    FX_MODE_TRICOLOR_CHASE,
    FX_MODE_TWINKLEFOX,
    FX_MODE_RAIN,
    FX_MODE_CUSTOM_0,
    FX_MODE_CUSTOM_1,
    FX_MODE_CUSTOM_2,
    FX_MODE_CUSTOM_3,
    FX_MODE_CUSTOM_4,
    FX_MODE_CUSTOM_5,
    FX_MODE_CUSTOM_6,
    FX_MODE_CUSTOM_7,
}Enm_FX_Effect;

// 显示效果数组元素定义
typedef struct
{
    const char* name;
    const char* category;
    uint16_t (*mode_ptr)(void);
}Tst_mode;

extern const Tst_mode _modes[65];
extern uint16_t (*customModes[8])(void);
#endif
