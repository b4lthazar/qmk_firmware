#ifndef CONFIG_B4LTHAZAR_H
#define CONFIG_B4LTHAZAR_H
#include "../../config.h"

#undef  TAPPING_TERM
#define TAPPING_TERM 200

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

/* faster mousekeys than the default */
#undef MOUSEKEY_MOVE_DELTA
#undef MOUSEKEY_WHEEL_DELTA
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_MOVE_DELTA          8
#define MOUSEKEY_WHEEL_DELTA         1
#define MOUSEKEY_DELAY               0
#define MOUSEKEY_INTERVAL            7
#define MOUSEKEY_MAX_SPEED           8
#define MOUSEKEY_TIME_TO_MAX         50
#define MOUSEKEY_WHEEL_MAX_SPEED     16
#define MOUSEKEY_WHEEL_TIME_TO_MAX   40


/*

#### `MOUSEKEY_DELAY`

When one of the mouse movement buttons is pressed this setting is used to define the delay between that button press and the mouse cursor moving. Some people find that small movements are impossible if this setting is too low, while settings that are too high feel sluggish.

#### `MOUSEKEY_INTERVAL`

When a movement key is held down this specifies how long to wait between each movement report. Lower settings will translate into an effectively higher mouse speed.

#### `MOUSEKEY_MAX_SPEED`

As a movement key is held down the speed of the mouse cursor will increase until it reaches `MOUSEKEY_MAX_SPEED`.

#### `MOUSEKEY_TIME_TO_MAX`

How long you want to hold down a movement key for until `MOUSEKEY_MAX_SPEED` is reached. This controls how quickly your cursor will accelerate.

#### `MOUSEKEY_WHEEL_MAX_SPEED`

The top speed for scrolling movements.

#### `MOUSEKEY_WHEEL_TIME_TO_MAX`

How long you want to hold down a scroll key for until `MOUSEKEY_WHEEL_MAX_SPEED` is reached. This controls how quickly your scrolling will accelerate.
*/

#undef IGNORE_MOD_TAP_INTERRUPT

#endif /* CONFIG_B4LTHAZAR_H */
