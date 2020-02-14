/*
 * safeTimers.h is developed by Erik
 * 
 * I made some small changes due to the "how can I handle the millis() rollover"
 * by Edgar Bonet
 * 
 * DECLARE_TIMER(timername, interval)
 *  Declares two unsigned longs: 
 *    <timername>_last for last execution
 *    <timername>_interval for interval in seconds
 *    
 *    
 * DECLARE_TIMERms is same as DECLARE_TIMER **but** uses milliseconds!
 *    
 * DUE(timername) 
 *  returns false (0) if interval hasn't elapsed since last DUE-time
 *          true (current millis) if it has
 *  updates <timername>_last
 *    
 * DUE_INTERVAL(timername) 
 *  With this macro the time between two tests is always less or equal to interval
 *  Once started at x:35 with an interval of 1 minute it will fire at n:35 every time.
 *  If the time between two successive DUE_INTERVAL() calls is longer then
 *  the interval it will catch up until it is at n:35 again. 
 *  
 *  returns false (0) if interval hasn't elapsed since last DUE_INTERVAL-time
 *          true (current millis) if it has
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
 *  https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
 *  
 *  Be awair in some rare situations the timer's take twice as long as antisipated!
 *  
 */
#define DECLARE_TIMERm(timerName, timerTime)    static unsigned long timerName##_interval = timerTime * 60 * 1000,     \
                                                timerName##_last = millis();
#define DECLARE_TIMER(timerName, timerTime)     static unsigned long timerName##_interval = timerTime * 1000,          \
                                                timerName##_last = millis();
#define DECLARE_TIMERms(timerName, timerTime)   static unsigned long timerName##_interval = timerTime,                 \
                                                timerName##_last = millis();
#define DECLARE_TIMERs DECLARE_TIMER


#define TIME_LEFT_MIN(timerName)                  (uint32_t)((timerName##_interval + timerName##_last - millis()) / 60 / 1000)
#define TIME_LEFT_SEC(timerName)                  (uint32_t)((timerName##_interval + timerName##_last - millis())/ 1000)
#define TIME_LEFT_MS(timerName)                   (uint32_t)( timerName##_interval + timerName##_last - millis())
#define TIME_LEFT TIMER_LEFT_SEC

#define RESTART_TIMER(timerName)                { timerName##_last = millis(); }

#define SINCE(timerName)        ((signed long)(millis() - timerName##_last))
#define PAST(timerName)          (( SINCE(timerName) < timerName##_interval) \
                                              ? 0 : (timerName##_last = millis()))
#define DUE(timerName)          (( SINCE(timerName) < timerName##_interval) \
                                              ? 0 : (timerName##_last += timerName##_interval))

//-------------------------------------------------------------------------------------
//--- to test the roll-over in a reasanable time frame I defined the same functions ---
//--- but with a 8 bit unsigned integer                                             ---
//--- Rollover takes place every 25 seconds                                         ---
//-------------------------------------------------------------------------------------
uint8_t myTimer = 0;

uint8_t timer8Bit()
{
  return myTimer;
  
} // timer8Bit()

#define DECLARE_8BIT_TIMER(timerName, timerTime)    static uint8_t timerName##_interval = timerTime,  \
                                                    timerName##_last = timer8Bit();

#define RESTART_8BIT_TIMER(timerName)               { timerName##_last = timer8Bit(); }

#define SINCE_8BIT(timerName)                       ((int8_t)(timer8Bit() - timerName##_last))
#define PAST_8BIT(timerName)                         ((SINCE_8BIT(timerName) < timerName##_interval)   \
                                                        ? 0 : (timerName##_last=timer8Bit()))
#define DUE_8BIT(timerName)                          ((SINCE_8BIT(timerName) < timerName##_interval)   \
                                                        ? 0 : (timerName##_last+=timerName##_interval))

/* 
**      
** eof 
*/ 
