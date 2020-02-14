/*
 * Author:  Willem Aandewiel
 * Date  : 14-02-2020
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
#define DUE_TEST1       20       // set 8bit timer to nr of ticks
#define DUE_TEST2       60       // set 8bit timer to nr of ticks

#include "safeTimers.h"

uint32_t  loopCount = 0;

  DECLARE_TIMER_MS(everyMsTick, MS_TICKS)           // update myTimer every msTick
  DECLARE_8BIT_TIMER(test8BitTest1, DUE_TEST1)      // print text every INTERVAL timer8Bit() ticks
  DECLARE_8BIT_TIMER(test8BitTest2, DUE_TEST2)      // print text every INTERVAL timer8Bit() ticks

  DECLARE_TIMER_MS(wait3Sec, 3123)                  // delay 3+ seconds
  DECLARE_TIMER_SEC(doDelay, 17)                    // every 17 seconds 

//================================================================================================
void print8BitTest1()
{
  static uint32_t lastPrint = 0;
  int duration = millis() - lastPrint;

/**
  Serial.printf("\r\n[%4d]ticks [%02d:%02d:%03d]  timer8Bit()[%4d]/[%4d] \r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , (int8_t)(timer8Bit()*1)
                                                           , (int8_t)(test8BitDue_last*1));
**/
  if (duration > (DUE_TEST1 * MS_TICKS))
  {
    Serial.printf("\r\n[%4d]ticks [%02d:%02d:%03d]            timer8Bit()[%4d]/[%4d] => DUE_8BIT(Test1) TOOK TO LONG!!!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , timer8Bit()
                                                           , (int8_t)(timer8Bit()*1));
  }
  else
  {
    Serial.printf("[%4d]ticks [%02d:%02d:%03d]            DUE_8BIT(Test1) fired!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }

  lastPrint = millis();
  
} // print8BitTest1()


//================================================================================================
void print8BitTest2()
{
  static uint32_t lastPrint = millis();
  int duration = millis() - lastPrint;
  
  if (duration > (DUE_TEST2 * MS_TICKS))
  {
    Serial.printf("\r\n[%4d]ticks            [%02d:%02d:%03d] timer8Bit()[%4d]/[%4d] => DUE_8BIT(Test2) TOOK TO LONG!!!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , timer8Bit()
                                                           , (int8_t)(timer8Bit()*1));
  }
  else
  {
    Serial.printf("[%4d]ticks            [%02d:%02d:%03d] DUE_8BIT(Test2) fired!\r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }
  lastPrint = millis();
  
} // print8BitTest2()


//================================================================================================
void update8BitTimer(char x)
{
  if ( DUE(everyMsTick))
  {
    loopCount++;
    myTimer++;
    if (x != ' ') Serial.print(x);
    /**
      Serial.printf("timer[%3d] last[%3d] interv[%3d] -> ticks left[%4d]\r\n", (uint8_t)timer8Bit()
                                                              , (uint8_t)test8BitDue_last
                                                              , test8BitDue_interval
                                                              , TIME_LEFT_8BIT(test8BitDue));
    **/
  }      
  yield();
  
} // update8BitTimer()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n.. and then it begins ...\r\n");
  Serial.printf("\nDue_Test1[%d]ticks, Due_Test2[%d]ticks\r\n", DUE_TEST1, DUE_TEST2);

  RESTART_8BIT_TIMER(test8BitTest1);
  RESTART_8BIT_TIMER(test8BitTest2);
  RESTART_TIMER(doDelay);
  myTimer = 111;

  Serial.printf("StartTime[%02d:%02d:%03d]\r\n" , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));

} // setup()


//================================================================================================
void loop() {
  update8BitTimer(' ');   

  if ( DUE_SKIP_8BIT(test8BitTest1) ) {
    print8BitTest1();
  }
  
  if ( DUE_SKIP_8BIT(test8BitTest2) ) {
      print8BitTest2();
  }

  if ( DUE(doDelay) && 1)
  {
    Serial.printf("doDelay: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(doDelay)
                                                            , TIME_LEFT_MS(doDelay)
                                                            , TIME_LEFT_MIN(doDelay));
    //Serial.print("wait");
    RESTART_TIMER(wait3Sec);
    Serial.printf("wait3Sec:    Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(wait3Sec)
                                                            , TIME_LEFT_MS(wait3Sec)
                                                            , TIME_LEFT_MIN(wait3Sec));
    while ( !DUE(wait3Sec) )
    {
      update8BitTimer('_');
    }
    Serial.printf("\r\ndoDelay: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(doDelay)
                                                            , TIME_LEFT_MS(doDelay)
                                                            , TIME_LEFT_MIN(doDelay));
    RESTART_TIMER(doDelay);

    Serial.printf("Test1: Ticks left [%3d]\r\n", TIME_LEFT_8BIT(test8BitTest1));
    Serial.printf("Test2: Ticks left [%3d]\r\n", TIME_LEFT_8BIT(test8BitTest2));
  }
  
  if (loopCount > 400)  // 40.000 ms => 40 sec
  {
    Serial.print("hold ..");
    delay(15000);
    Serial.println(".. continue!");
    loopCount = 0;
    Serial.printf("doDelay: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(doDelay)
                                                            , TIME_LEFT_MS(doDelay)
                                                            , TIME_LEFT_MIN(doDelay));

  }

} // loop()
