/*
 * Author:  Willem Aandewiel
 * Thanks to Erik and Edgar Bonet
 * 
 * A program to test the millis() RollOver debacle
 * I have made some 8bit macro's that are used with a semi millis()
 * (8 bit) timers so you don't have to wait 49 day's before a RollOver 
 * occurs.
 * Just remove the 8Bit macro's if you want to use the safeTimers.h file
 * in your program.
 */

#define MS_TICKS       100       // update timer8Bit() every 100ms
#define PAST_TEST       30       // set 8bit timer to nr of ticks
#define INTERVAL_TEST   25       // set 8bit timer to nr of ticks

#include "safeTimers.h"

  DECLARE_TIMERms(everyMsTick, MS_TICKS)                // update myTimer every msTick
  DECLARE_8BIT_TIMER(test8BitDue, PAST_TEST)             // print text every INTERVAL timer8Bit() 
  DECLARE_8BIT_TIMER(test8BitInterval, INTERVAL_TEST)   // print text every INTERVAL timer8Bit() 

  DECLARE_TIMERs(wait3Sec, 3)                   // delay 3 seconds
  DECLARE_TIMERs(doDelay, 13)                   // every 10 seconds 

//================================================================================================
void print8BitDue()
{
  static uint32_t lastPrint = millis();
  int duration = millis() - lastPrint;
  
  if (duration > (PAST_TEST * MS_TICKS))
  {
    Serial.printf("\r\n[%4d]ticks [%02d:%02d:%03d]            timer8Bit()[%4u]/[%4d] => PAST_8BIT()          TOOK TO LONG!!!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , timer8Bit()
                                                           , (int8_t)timer8Bit());
  }
  else
  {
    Serial.printf("[%4d]ticks [%02d:%02d:%03d]            PAST_8BIT()          fired!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }
  lastPrint = millis();
  
} // print8BitDue()


//================================================================================================
void print8BitInterval()
{
  static uint32_t lastPrint = millis();
  int duration = millis() - lastPrint;
  
  if (duration > (INTERVAL_TEST * MS_TICKS))
  {
    Serial.printf("\r\n[%4d]ticks            [%02d:%02d:%03d] timer8Bit()[%4u]/[%4d] => PAST_8BIT_INTERVAL() TOOK TO LONG!!!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , timer8Bit()
                                                           , (int8_t)timer8Bit());
  }
  else
  {
    Serial.printf("[%4d]ticks            [%02d:%02d:%03d] PAST_8BIT_INTERVAL() fired!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }
  lastPrint = millis();
  
} // print8BitInterval()


//================================================================================================
void update8BitTimer(char x)
{
  if ( PAST(everyMsTick))
  {
    myTimer++;
    if (x != ' ') Serial.print(x);
  }      
  yield();
  
} // update8BitTimer()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n.. and then it begins ...\r\n");
  Serial.printf("\nDue_Test[%d]ticks, Interval_Test [%d]ticks\r\n", PAST_TEST, INTERVAL_TEST);

  RESTART_8BIT_TIMER(test8BitDue);
  RESTART_8BIT_TIMER(test8BitInterval);
  
} // setup()


//================================================================================================
void loop() {
  update8BitTimer(' ');   
  
  if ( PAST_8BIT(test8BitDue) ) {
      print8BitDue();
  }
  
  if ( DUE_8BIT(test8BitInterval) ) {
      print8BitInterval();
  }

  if ( PAST(doDelay) )
  {
    Serial.print("wait");
    RESTART_TIMER(wait3Sec);
    while ( !DUE(wait3Sec) )
    {
      update8BitTimer('_');
    }
    RESTART_TIMER(doDelay);
  }

} // loop()
