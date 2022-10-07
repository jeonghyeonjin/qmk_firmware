
#include "gicho56.h"
// #include "transactions.h"
#include <string.h>
// #include "drivers/sensors/pimoroni_trackball.h"
// #include "drivers/sensors/analog_joystick.h"


#ifdef SWAP_HANDS_ENABLE
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {         {5, 6},  {4, 6},  {3, 6},  {2, 6},  {1, 6}          },
    {{6, 7},  {5, 7},  {4, 7},  {3, 7},  {2, 7},  {1, 7}          },
    {{6, 8},  {5, 8},  {4, 8},  {3, 8},  {2, 8},  {1, 8}          },
    {{6, 9},  {5, 9},  {4, 9},  {3, 9},  {2, 9},  {1, 9},  {0, 9} },
    {                           {3, 10}, {2, 10}, {1, 10}, {0, 10}},
    /* Right hand, matrix positions */
    {         {5, 0},  {4, 0},  {3, 0},  {2, 0},  {1, 0}          },
    {         {5, 1},  {4, 1},  {3, 1},  {2, 1},  {1, 1},  {0, 1} },
    {         {5, 2},  {4, 2},  {3, 2},  {2, 2},  {1, 2},  {0, 2} },
    {{6, 3},  {5, 3},  {4, 3},  {3, 3},  {2, 3},  {1, 3},  {0, 3} },
    {{6, 4},  {5, 4},  {4, 4},  {3, 4},                           }};

#    ifdef ENCODER_MAP_ENABLE
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = {1, 0};
#    endif
#endif

#ifdef RGB_MATRIX_ENABLE
  // Physical Layout
  // Columns
  // 0  1  2  3  4  5  6  7  8  9  10 11 12 13
  //                                           ROWS
  //    30 29 21 20 11       11 20 21 29 30     0
  //    03    02    01       01    02    03
  // 36 31 28 22 19 12       12 19 22 28 31 36  1
  //    04                               04
  // 35 32 27 23 18 13       13 18 23 27 32 35  2
  //
  // 34 33 26 24 17 14 10 10 14 17 24 26 33 34  3
  //
  //    25  16  15  09       09  15  16  25      4
  //    05  06  07  08       08  07  06  05

led_config_t g_led_config = {
    {
        /* Key Matrix to LED index. */
        // Left split.
        { NO_LED,     29,     28,     20,     19,     10, NO_LED }, // 0 row
        {     35,     30,     27,     21,     18,     11, NO_LED }, // 1 row
        {     34,     31,     26,     22,     17,     12, NO_LED }, // 2 row
        {     33,     32,     25,     23,     16,     13,      9 }, // 3 row
        { NO_LED, NO_LED, NO_LED,     24,     15,     14,      8 }, // Thumb cluster
        // Right split.
        { NO_LED,     65,     64,     56,     55,     46, NO_LED }, // 0 row
        {     71,     66,     63,     57,     54,     47, NO_LED }, // 1 row
        {     70,     67,     62,     58,     53,     48, NO_LED }, // 2 row
        {     69,     68,     61,     59,     52,     49,     45 }, // 3 row
        { NO_LED, NO_LED, NO_LED,     60,     51,     50,     44 }, // Thumb cluster
    },
    {
        // Left side underglow
        // {96, 40}, {16, 20}, {48, 10}, {80, 18}, {88, 57}, {56, 57}, {24, 57}, {12, 60},
        {80, 12}, {48, 12}, {16, 12}, {16, 25}, {16, 40}, {48, 49}, {80, 51}, {96, 61},
        // Left side Matrix
        {96, 64}, {96, 39},
        {80, 60}, {80, 39}, {80, 26}, {80, 13}, {80,  0},
        {64, 53}, {64, 39}, {64, 26}, {64, 13}, {64,  0},
        {48, 52}, {48, 39}, {48, 26}, {48, 13}, {48,  0},
                  {32, 39}, {32, 26}, {32, 13}, {32,  0},
                  {16, 39}, {16, 26}, {16, 13}, {16,  0},
                  { 0, 39}, { 0, 26}, { 0, 13},


        // Right side underglow
        // {128, 40}, {208, 20}, {176, 10}, {144, 18}, {136, 57}, {168, 57}, {200, 57}, {212, 60},
        {144, 12}, {176, 12}, {208, 12}, {208, 25}, {208, 40}, {176, 49}, {144, 51}, {128, 61},
        // Right side Matrix
        {128, 64}, {128, 39},
        {144, 60}, {144, 39}, {144, 26}, {144, 13}, {144,  0},
        {160, 53}, {160, 39}, {160, 26}, {160, 13}, {160,  0},
        {176, 52}, {176, 39}, {176, 26}, {176, 13}, {176,  0},
                   {192, 39}, {192, 26}, {192, 13}, {192,  0},
                   {208, 39}, {208, 26}, {208, 13}, {208,  0},
                   {224, 39}, {224, 26}, {224, 13},
    },
    {
        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                           LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                           LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                           LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,

        LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                           LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                           LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
                           LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    }
};
#endif
