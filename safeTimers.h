/*
 * safeTimers.h (original name timers.h) is developed by Erik
 * 
 * Willem Aandewiel and Robert van den Breemen made some changes due 
 * to the "how can I handle the millis() rollover" by Edgar Bonet 
 * Also added  CHANGE_INTERVAL(), RESTART_TIMER() and TIME_LEFT() macro's
 *
 * see: https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
 * 
 * DECLARE_TIMER_MIN(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in minutes
 * DECLARE_TIMER_SEC(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in seconds
 * DECLARE_TIMER_MS(timername,  interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in milliseconds
 * DECLARE_TIMER(timername,     interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})     // interval in seconds
 *  Declares two uint32_t's: 
 *    <timername>_due for next execution
 *    <timername>_interval for interval in seconds
 *    <timername>_skip boolean skip 'missed' events
 * 
 * TIME_LEFT_MIN(timerName)
 *  returns the time left in minutes
 * TIME_LEFT_SEC(timerName)
 *  returns the time left in seconds
 * TIME_LEFT_MS(timerName)
 *  returns the time left in milliseconds
 * TIME_LEFT_M(timerName)
 *  returns the time left in seconds
 * 
 * CHANGE_INTERVAL_MIN(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 * CHANGE_INTERVAL_SEC(timername, interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 * CHANGE_INTERVAL_MS(timername,  interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 * CHANGE_INTERVAL(timername,     interval, {CATCH_UP_MISSED_EVENTS | SKIP_MISSED_EVENTS})
 *  Changes the uint32_t's declared by DECLARE_TIMER(): 
 *    <timername>_due for next execution
 *    <timername>_interval for interval in seconds
 *    <timername>_skip (boolean) skip 'missed' events
 *    
 * RESTART_TIMER(timername)
 *  Changes the uint32_t declared by DECLARE_TIMER(): 
 *    <timername>_due = millis() + <timername>_interval
 *    
 * DUE(timername) 
 *  returns false (0) if interval hasn't elapsed since last DUE-time
 *          true (current millis) if it has
 *  updates <timername>_due
 *  
 *  Usage example:
 *  
 *  DECLARE_TIMER(screenUpdate, 200, SKIP_MISSED_EVENTS)          // update screen every 200 ms
 *  ...
 *  loop()
 *  {
 *  ..
 *    if ( DUE(screenUpdate) ) {
 *      // update screen code
 *    }
 *    
 *    // to change the screenUpdate interval:
 *    CHANGE_INTERVAL(screenUpdate, 500, CATCH_UP_MISSED_EVENTS); // change interval to 500 ms
 *    
 *    // to restart the screenUpdate interval:
 *    RESTART_TIMER(screenUpdate);                                // restart timer so next DUE is in 500ms
 *  }
 *  
 */

#define SKIP_MISSED_EVENTS      true
#define CATCH_UP_MISSED_EVENTS  false

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


uint32_t __DUE__(uint32_t &timer_due, uint32_t timer_interval, bool doSkip)
{
  if ((int32_t)(millis() - timer_due) >= 0) 
  {
    if (doSkip)
    {
      timer_due += timer_interval;
    }
    else
    {
      timer_due += timer_interval;
    }
  }
  else return 0;
  
  return timer_due;  
  
} // __DUE__()

/*
 * 
*/
