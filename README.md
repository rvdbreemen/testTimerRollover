# millis_RollOver
This program is to test the millis() rollover in just a few seconds ...

There is an ongoing discussion on the internat about the problems due to 
the rollover of the millis() timer function.

This program shows how to tackle this problem by means of a macro.h file by Erik (with some changes by me).

In the `timers.h` file (original `timer.h` by Erik) I have made three macro's
```
#define DECLARE_8BIT_TIMER(timerName, timerTime)  static uint8_t timerName##_interval = timerTime,      timerName##_last = myTimer+random(timerName##_interval);
#define SINCE_8BIT(timerName)                     ((int8_t)(myTimer - timerName##_last))
#define DUE_8BIT(timerName)                       ((SINCE_8BIT(timerName) < timerName##_interval) ? 0 : (timerName##_last=myTimer))
```

that uses 8 bit timers and a substitute `millis()` (`myTimer`).
If you want to use the `timers.h` file in your own sketches, just remove the last 6 lines.

The solution to the problem is explained by `Edgar Bonet` on `StackExchange`.

You can find that [here](https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover).

