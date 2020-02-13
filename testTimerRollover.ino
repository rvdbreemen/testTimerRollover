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

#define MS_TICKS      100       // update timer8Bit() every 100ms
#define TEST_INTERVAL  30       // set 8bit timer to nr of ticks

#include "safeTimers.h"

  DECLARE_TIMERms(everyMsTick, MS_TICKS)        // update myTimer every msTick
  DECLARE_8BIT_TIMER(test8Bit, TEST_INTERVAL)   // print text every INTERVAL timer8Bit() 

  DECLARE_TIMERs(wait3Sec, 3)                   // delay 3 seconds
  DECLARE_TIMERs(doDelay, 10)                   // every 10 seconds 

//================================================================================================
void print8BitText()
{
  static uint32_t lastPrint = millis();
  int duration = millis() - lastPrint;
  
  if (duration > (TEST_INTERVAL * MS_TICKS))
  {
    Serial.printf("\r\n[%4d]ticks [%02d:%02d:%03d] timer8Bit()[%4u]/[%4d] => DUE_8BIT() TOOK TO LONG!!!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , timer8Bit()
                                                           , (int8_t)timer8Bit());
  }
  else
  {
    Serial.printf("[%4d]ticks [%02d:%02d:%03d]  DUE_8BIT() fired!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }
  lastPrint = millis();
  
} // print8BitText()


//================================================================================================
void update8BitTimer(char x)
{
  if ( DUE(everyMsTick))
  {
    myTimer++;
    Serial.print(x);
  }      
  yield();
  
} // update8BitTimer()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n.. and then it begins ...\r\n");
  Serial.printf("\nInterval [%d]ticks\r\n", TEST_INTERVAL);

  RESTART_8BIT_TIMER(test8Bit);
  
} // setup()


//================================================================================================
void loop() {
  update8BitTimer('.');   
  
  if ( DUE_8BIT(test8Bit) ) {
      print8BitText();
  }

  if ( DUE(doDelay) )
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
