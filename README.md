# testTimerRollover
This program is to test the millis() rollover in just a few seconds ...

There is an ongoing discussion on the internat about the problems due to 
the rollover of the millis() timer function.

The timer-rollover problem is explained by `Edgar Bonet` on `StackExchange`.

You can find the discussion [here](https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover).



This program tackles the rollover problem by means of a `safeTimers.h` file originally created by **Erik**
and modified by *Willem Aandewiel* and *Robert van den Breemen*.

In the `safeTimers.h` file (original `timer.h` by Erik) you will find the following macro definitions:
```
#define DECLARE_TIMER_MIN(timerName, timerTime, doSkip)                                                   \
                                          static uint32_t timerName##_interval = (timerTime * 60 * 1000), \
                                          timerName##_due = millis()+timerName##_interval                 \
                                                               +random(timerName##_interval / 3);         \
                                          static bool timerName##_skip = doSkip;
#define DECLARE_TIMER_SEC(timerName, timerTime, doSkip)                                                   \
                                          static uint32_t timerName##_interval = (timerTime * 1000),      \
                                          timerName##_due = millis()+timerName##_interval                 \
                                                               +random(timerName##_interval / 3);         \
                                          static bool timerName##_skip = doSkip;
#define DECLARE_TIMER_MS(timerName, timerTime, doSkip)                                                    \
                                          static uint32_t timerName##_interval = timerTime,               \
                                          timerName##_due = millis()+timerName##_interval                 \
                                                               +random(timerName##_interval / 3);         \
                                          static bool timerName##_skip = doSkip;

#define DECLARE_TIMER       DECLARE_TIMER_SEC

#define CHANGE_INTERVAL_MIN(timerName, timerTime, doSkip)                                   \
                                          timerName##_interval = (timerTime * 60 * 1000)    \
                                          timerName##_due = millis()+timerName##_interval;  \
                                          timerName##_skip = doSkip;
#define CHANGE_INTERVAL_SEC(timerName, timerTime, doSkip)                                   \
                                          timerName##_interval = (timerTime * 1000)         \
                                          timerName##_due = millis()+timerName##_interval;  \
                                          timerName##_skip = doSkip;
#define CHANGE_INTERVAL_MS(timerName, timerTime, doSkip)                                    \
                                          timerName##_interval = timerTime                  \
                                          timerName##_due = millis()+timerName##_interval;  \
                                          timerName##_skip = doSkip;

#define CHANGE_INTERVAL     CHANGE_INTERVAL_SEC

#define TIME_LEFT_MIN(timerName)          ( (timerName##_due - millis()) / (60 * 1000) )
#define TIME_LEFT_SEC(timerName)          ( (timerName##_due - millis()) / (1000) )
#define TIME_LEFT_MS(timerName)           ( (timerName##_due - millis()) )
#define TIME_LEFT           TIMER_LEFT_SEC

#define RESTART_TIMER(timerName)          timerName##_due = millis()+timerName##_interval; 

#define DUE(timerName)                    (__DUE__(timerName##_due, timerName##_interval, timerName##_skip))
```

In the file `safeTimersFastRO.h` we have changed the `millis()` into `micros()` so the rollover will occur 
rougly in 1 hour and 11 minutes.
For even faster testing there are also definitions for 16 bit timers:
```

#define DECLARE_16BIT_TIMER(timerName, timerTime, doSkip)  \
                                            static uint16_t timerName##_interval = timerTime,         \
                                            timerName##_due  = timer16Bit()                           \
                                                                  +timerName##_interval               \
                                                                  +random(timerName##_interval / 3);  \
                                            static bool timerName##_skip = doSkip;

#define CHANGE_16BIT_INTERVAL(timerName, timerTime, doSkip) \
                                            timerName##_interval = timerTime                          \
                                            timerName##_due = micros()+timerName##_interval;          \
                                            timerName##_skip = doSkip;
                                                    
#define RESTART_16BIT_TIMER(timerName)      timerName##_due = timer16Bit()+timerName##_interval;

#define TIME_LEFT_16BIT(timerName)          ((int16_t)(timerName##_due-timer16Bit()))

#define DUE_16BIT(timerName)                (__DUE_16BIT(timerName##_due, timerName##_interval, timerName##_skip))
```
Those macro's work the same as the 32 bit equevalents but the rollover time is reduced to 1 minute and some 
seconds.

If you want to use the rollover-safe-timers in your program just copy `safeTimers.h` and
include it at the beginning of your program.
```
     #include "safeTimers.h"
```

