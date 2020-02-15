/*
 * safeTimers.h is developed by Erik
 * 
 * I made some small changes due to the "how can I handle the micros() rollover"
 * by Edgar Bonet
 * 
 * DECLARE_TIMER(timername, interval)
 *  Declares two unsigned long var's: 
 *    <timername>_last for last execution
 *    <timername>_interval for interval in seconds
 *    
 *    
 * DECLARE_TIMER_MS is same as DECLARE_TIMER **but** uses microseconds!
 *    
 * DUE(timername) 
 *  returns false (0) if interval hasn't elapsed since last DUE-time
 *          true (current micros) if it has
 *  updates <timername>_last
 *    
 * DUE_INTERVAL(timername) 
 *  With this macro the time between two tests is always less or equal to interval
 *  Once started at x:35 with an interval of 1 minute it will fire at n:35 every time.
 *  If the time between two successive DUE_INTERVAL() calls is longer then
 *  the interval it will catch up until it is at n:35 again. 
 *  
 *  returns false (0) if interval hasn't elapsed since last DUE_INTERVAL-time
 *          true (current micros) if it has
 *  updates <timername>_last
 *  
 *  RESTART_TIMER(timername)
 *   it restarts the timer
 *   updates <timername>_last
 *  
 *  Usage example:
 *  
 *  DECLARE_TIMER(screenUpdate, 200) // update screen every 200 ms
 *  ...
 *  setup()
 *  {
 *  ..
 *    RESTART_TIMER(screenUpdate);  // restart the timer for 200 ms!
 *  }
 *  ...
 *  loop()
 *  {
 *  ..
 *    if ( DUE(screenUpdate) ) {
 *      // update screen
 *    }
 *  }
 *  
 *  https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-micros-rollover
 *  
 *  Be awair in some rare situations the timer's take twice as long as antisipated!
 *  
 */
#define DECLARE_TIMER_MIN(timerName, timerTime) static unsigned long timerName##_interval = timerTime * 60 * 1000 * 1000,     \
                                                timerName##_last = micros()+random(timerName##_interval,(timerName##_interval*1.5));
#define DECLARE_TIMER_SEC(timerName, timerTime) static unsigned long timerName##_interval = timerTime * 1000 * 1000,          \
                                                timerName##_last = micros()+random(timerName##_interval,(timerName##_interval*1.5));
#define DECLARE_TIMER_MS(timerName, timerTime)  static unsigned long timerName##_interval = timerTime * 1000,                 \
                                                timerName##_last = micros()+random(timerName##_interval,(timerName##_interval*1.5));

#define DECLARE_TIMER   DECLARE_TIMER_SEC

#define TIME_LEFT_MIN(timerName)                 (__TIME_LEFT(timerName##_last, micros(), 60000) )
#define TIME_LEFT_SEC(timerName)                 (__TIME_LEFT(timerName##_last, micros(),  1000) )
#define TIME_LEFT_MS(timerName)                  (__TIME_LEFT(timerName##_last, micros(),     1) )
#define TIME_LEFT     TIMER_LEFT_SEC

#define RESTART_TIMER(timerName)                 { timerName##_last = micros()+timerName##_interval; }

#define SINCE(timerName)                         ((signed long)(micros() - timerName##_last))

#define DUE(timerName)                           (__DUE__(timerName##_last, timerName##_interval) )

unsigned long __DUE__(unsigned long &sLast, unsigned long sInterval)
{ 
  if (micros() > sLast) // overdue ...?
  {
    bool bPrint = true;
    while ( (micros() - sLast) > sInterval )  // long overdue!
    {
      //if (bPrint) Serial.printf("32Bit[%d] last[%d] >> last+=%d\r\n", micros(), sLast, sInterval);
      sLast += (sInterval +20); // micro's go sooo fast!
      bPrint = false;
      yield();
    }
    //if (!bPrint) Serial.printf("32Bit[%d] > last[%d] ==> [%d]ms to go\r\n", micros(), sLast, ((micros() - sLast) / 1000));
  }

  if (micros() >= sLast)
  {
    //Serial.printf("32Bit timer[%d] - last[%d] => [%d] < interval[%d]?\r\n", micros(), sLast, (micros() - sLast), sInterval);
    if ((micros() - sLast) > sInterval)
          return  0;
    else  return (sLast += sInterval);
  }
  //--- not yet due!
  return 0;
  
} // __DUE__()

unsigned long __TIME_LEFT(unsigned long sLast, unsigned long sTimer, unsigned long divider)
{
  if (sLast > sTimer) return ((sLast - sTimer) / (divider * 1000));
  return 0;
  
} // __TIME_LEFT()

//-------------------------------------------------------------------------------------
//--- to test the roll-over in a reasanable time frame I defined the same functions ---
//--- but with a 16 bit unsigned integer                                             ---
//--- Rollover takes place every ~65 seconds                                         ---
//-------------------------------------------------------------------------------------

uint16_t timer16Bit()
{
  return ((millis() & 0b1111111111111111)); // only 16 bits
  
} // timer16Bit()

#define DECLARE_16Bit_TIMER(timerName, timerTime)   static uint16_t timerName##_interval = timerTime,  \
                                                    timerName##_last = timer16Bit()+random(timerName##_interval,(timerName##_interval*1.5));

#define RESTART_16Bit_TIMER(timerName)              { timerName##_last = timer16Bit()+timerName##_interval; }

#define SINCE_16Bit(timerName)                      ((int16_t)(timer16Bit() - timerName##_last))

//#define TIME_LEFT_16Bit(timerName)                   ((uint16_t)((timerName##_last - timer16Bit()) - 0x7FFF))
#define TIME_LEFT_16Bit(timerName)                  (__TIME_LEFT_16Bit(timerName##_last))

#define DUE_16Bit(timerName)              (__DUE_16Bit(timerName##_last, timerName##_interval) )

uint16_t __DUE_16Bit(uint16_t &last, uint16_t interval)
{
  if (timer16Bit() > last)
  {
    bool bPrint = true;
    //Serial.printf("[a](timer[%4d] - last[%4d]) => [%4d] > interval[%d]", timer, last, ((int16_t)(timer - last)), ((int16_t)interval));
    while ( (timer16Bit() - last) > interval) 
    {
      //if (bPrint) Serial.printf("16Bit[%5d] last[%5d] >> last+=%d\r\n", timer16Bit(), last, interval);
      last += interval;
      bPrint = false;
      yield();
    }
    //if (!bPrint) Serial.printf("16Bit[%5d] >>>> last[%5d] \r\n", timer16Bit(), last);
  }

  if (timer16Bit() > last)
  {
    if ((timer16Bit() - last) > interval)
          return 0;
    else  return (last += interval);
  }
  return 0;
}

uint16_t __TIME_LEFT_16Bit(uint16_t last)
{
  if (last > timer16Bit()) return (last - timer16Bit());
  return 0;
  
} // __TIME_LEFT_16Bit()

/* 
**      
** eof 
*/ 
