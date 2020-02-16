# testTimerRollover
This program is to test the millis() rollover in just a few seconds ...

There is an ongoing discussion on the internat about the problems due to 
the rollover of the millis() timer function.

This program tackles the rollover problem by means of a macro.h file originally created by Erik.

In the `safeTimers.h` file (original `timer.h` by Erik) there are four 16bit macro's
```
#define DECLARE_16Bit_TIMER(timerName, timerTime)   static uint16_t timerName##_interval = timerTime,                                       \
                                                    timerName##_next = timer16Bit()+random(timerName##_interval,(timerName##_interval*1.5)),\
                                                    timerName##_prev = timer16Bit(),                                                        \
                                                    timerName##_refTime = timer16Bit();

#define RESTART_16Bit_TIMER(timerName)              { timerName##_next = timer16Bit()+timerName##_interval; }

#define TIME_LEFT_16Bit(timerName)                  (__TIME_LEFT_16Bit(timerName##_next))

#define DUE_16Bit(timerName) (__DUE_16Bit(timerName##_next, timerName##_prev, timerName##_interval, timerName##_refTime) )
```

that uses a 16 bit timer to substitute `millis()` by `timer16Bit()`.
If you want to use the `safeTimers.h` file in your own sketches, just remove the last lines.

The timer-rollover problem is explained by `Edgar Bonet` on `StackExchange`.

You can find that [here](https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover).

