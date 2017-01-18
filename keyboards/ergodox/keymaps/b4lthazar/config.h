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
#define MOUSEKEY_MOVE_DELTA           5
#define MOUSEKEY_WHEEL_DELTA          1
#define MOUSEKEY_DELAY                0
#define MOUSEKEY_INTERVAL             5
#define MOUSEKEY_MAX_SPEED            7
#define MOUSEKEY_TIME_TO_MAX         70
#define MOUSEKEY_WHEEL_MAX_SPEED     16
#define MOUSEKEY_WHEEL_TIME_TO_MAX   40


#undef IGNORE_MOD_TAP_INTERRUPT

#endif /* CONFIG_B4LTHAZAR_H */
