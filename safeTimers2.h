/*
 * safeTimers.h (original name timers.h) is developed by Erik
 * 
 * Willem Aandewiel made some small changes due to the "how can I handle the millis() rollover"
 * by Edgar Bonet and added CHANGE_INTERVAL() and RESTART_TIMER() macro's
 *
 * see: https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
 * 
 * DECLARE_TIMER(timername, interval)
 *  Declares two unsigned longs: 
 *    <timername>_last for last execution
 *    <timername>_interval for interval in seconds
 *    
 *    
 * DECLARE_TIMER_MS is same as DECLARE_TIMER **but** uses milliseconds!
 *    
 * DUE(timername) 
 *  returns false (0) if interval hasn't elapsed since last DUE-time
 *          true (current millis) if it has
 *  updates <timername>_last
 *  
 *  Usage example:
 *  
 *  DECLARE_TIMER(screenUpdate, 200) // update screen every 200 ms
 *  ...
 *  loop()
 *  {
 *  ..
 *    if ( DUE(screenUpdate) ) {
 *      // update screen
 *    }
 * 
 * CHANGE_INTERVAL(timername, interval)
 *  Changes the unsigned longs declared by DECLARE_TIMER(): 
 *    <timername>_last for last execution
 *    <timername>_interval for interval in seconds
 *    
 *    // to change the screenUpdate interval:
 *    CHANGE_INTERVAL(screenUpdate, 500);  // change interval to 500 ms
 *    
 * RESTART_TIMER(timername)
 *  Changes the unsigned long declared by DECLARE_TIMER(): 
 *    <timername>_last = millis()
 *    
 *    // to restart the screenUpdate interval:
 *    RESTART_TIMER(screenUpdate);        // restart timer so next DUE is in 500ms
 *  }
 *  
 */
#define DECLARE_TIMER_MIN(timerName, timerTime)   static uint32_t timerName##_interval = (timerTime * 60 * 1000 * 1000), \
                                                  timerName##_due = micros()+timerName##_interval;
#define DECLARE_TIMER_SEC(timerName, timerTime)   static uint32_t timerName##_interval = (timerTime * 1000 * 1000),      \
                                                  timerName##_due = micros()+timerName##_interval;
#define DECLARE_TIMER_MS(timerName, timerTime)    static uint32_t timerName##_interval = (timerTime * 1000),               \
                                                  timerName##_due = micros()+timerName##_interval;

#define DECLARE_TIMER   DECLARE_TIMER_SEC

#define CHANGE_INTERVAL_MIN(timerName, timerTime) timerName##_interval = (timerTime * 60 * 1000 * 1000);    
#define CHANGE_INTERVAL_SEC(timerName, timerTime) timerName##_interval = (timerTime * 1000 * 1000);
#define CHANGE_INTERVAL_MS(timerName, timerTime)  timerName##_interval = (timerTime * 1000);             

#define CHANGE_INTERVAL CHANGE_INTERVAL_SEC

#define TIME_LEFT_MIN(timerName)                  ((timerName##_due - micros()) / (60 * 1000 * 1000))
#define TIME_LEFT_SEC(timerName)                  ((timerName##_due - micros()) / (1000 * 1000))
#define TIME_LEFT_MS(timerName)                   ((timerName##_due - micros()) / (1000))
#define TIME_LEFT     TIMER_LEFT_SEC

#define RESTART_TIMER(timerName)                  timerName##_due = micros()+timerName##_interval; 

//#define SINCE(timerName)                          ((int32_t)(micros() - timerName##_due))
//#define DUE(timerName)                            (( SINCE(timerName) >= 0) ? (timerName##_due+=timerName##_interval):0)
#define DUE(timerName)                            (__DUE__(timerName##_due, timerName##_interval))


uint32_t __DUE__(uint32_t &timer_due, uint32_t timer_interval)
{
  if ((int32_t)(micros() - timer_due) >= 0) 
  {
    while ((int32_t)(micros() - timer_due) >= 0) 
    {
      timer_due += timer_interval;
    }
  } 
  else return 0;
  
  return timer_due;  
} // __DUE__()

/*
 *  16 bit timers macro's for testing purposes
 */

uint16_t timer16Bit()
{
  return ((millis() & 0b1111111111111111)); // only 16 bits
  
} // timer16Bit()

#define DECLARE_16Bit_TIMER(timerName, timerTime)   static uint16_t timerName##_interval = timerTime,       \
                                                    timerName##_due  = timer16Bit()+timerName##_interval,    \
                                                    timerName##_last = timer16Bit()+timerName##_interval;

#define RESTART_16Bit_TIMER(timerName)              timerName##_due = timer16Bit()+timerName##_interval;

#define TIME_LEFT_16Bit(timerName)                  ((int16_t)(timerName##_due-timer16Bit()))
#define SINCE_LAST_DUE_16Bit(timerName)             ((int16_t)(timer16Bit()-timerName##_last))

#define DUE_16Bit(timerName)                        (__DUE_16Bit(timerName##_due, timerName##_last, timerName##_interval))

uint16_t __DUE_16Bit(uint16_t &timer_due, uint16_t &timer_last, uint16_t timer_interval)
{
  if ((int16_t)(timer16Bit() - timer_due) >= 0) 
  {
//    while ((int16_t)(timer16Bit() - timer_due) >= 0) 
//    {
//      timer_due  += timer_interval;
//    }

Serial.printf("timer[%6d] due[%6d] interval[%6d] [%10d] [%10d] next[%10d]",
                          timer16Bit(), timer_due, timer_interval, 
                          (timer16Bit() - timer_due) ,
                          ((int)((timer16Bit() - timer_due) / timer_interval)+1),
                          ((int)((timer16Bit() - timer_due) / timer_interval)+1)  * timer_interval);
                          
        timer_due  += ((int)((timer16Bit() - timer_due) / timer_interval)+1)  * timer_interval;

  } 
  else return 0;

  return timer_due;  
  
} // __DUE_16Bit()

/*
 * 
*/
