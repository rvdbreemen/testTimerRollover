/*
 * timers.h is developed by Erik
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
 *  }
 *  
 *  https://arduino.stackexchange.com/questions/12587/how-can-i-handle-the-millis-rollover
 */
#define DECLARE_TIMERm(timerName, timerTime)    static unsigned long timerName##_interval = timerTime * 60 * 1000,      timerName##_last = millis()+random(timerName##_interval);
#define DECLARE_TIMER(timerName, timerTime)     static unsigned long timerName##_interval = timerTime * 1000,           timerName##_last = millis()+random(timerName##_interval);
#define DECLARE_TIMERms(timerName, timerTime)   static unsigned long timerName##_interval = timerTime,                  timerName##_last = millis()+random(timerName##_interval);

#define DECLARE_TIMERs DECLARE_TIMER

#define SINCE(timerName)  ((signed long)(millis() - timerName##_last))
#define DUE(timerName) (( SINCE(timerName) < timerName##_interval) ? 0 : (timerName##_last=millis()))

//--- to test the roll-over in a reasanable time frame I defined the same functions ---
//--- but with a 8 bit unsigned integer                                             ---
//-------------------------------------------------------------------------------------
#define DECLARE_8BIT_TIMER(timerName, timerTime)    static uint8_t timerName##_interval = timerTime,      timerName##_last = myTimer+random(timerName##_interval);
#define SINCE_8BIT(timerName)                       ((int8_t)(myTimer - timerName##_last))
#define DUE_8BIT(timerName)                         ((SINCE_8BIT(timerName) < timerName##_interval) ? 0 : (timerName##_last=myTimer))
