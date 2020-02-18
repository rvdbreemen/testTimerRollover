/*
 * Author:  Willem Aandewiel
 * Date  : 14-02-2020
 * Thanks to Erik and Edgar Bonet
 * 
 * A program to test the micros() RollOver debacle
 * I have made some 16Bit macro's that are used with a semi millis()
 * (16 bit) timers so you don't have to wait 49 day's before a RollOver 
 * occurs.
 * Just remove the 16Bit macro's and change micros() to millis() if 
 * you want to use the safeTimers.h file in your program.
 */

#define DUE_TEST1       1100       // set 16Bit timer  3000ms
#define DUE_TEST2       8000       // set 16Bit timer  8000ms
#define DUE_TEST3      12000       // set 16Bit timer 12000ms

#include "safeTimers2.h"


  DECLARE_16Bit_TIMER(timerTest1, DUE_TEST1)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16Bit_TIMER(timerTest2, DUE_TEST2)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16Bit_TIMER(timerTest3, DUE_TEST3)      // print text every INTERVAL timer16Bit() ms

  DECLARE_TIMER_MS(wait3Sec, 3123)                    // delay 3+ seconds
  DECLARE_TIMER_SEC(delay47Secs, 47)                  // every 47 seconds 

  DECLARE_TIMER_SEC(after100Secs, 100)
  DECLARE_TIMER_SEC(hold15Secs, 15)

uint32_t microsDetectRollover = micros();

//================================================================================================
void print16BitTest1()
{
  static unsigned long lastPrint = 0;
  unsigned long msTime = millis();
  unsigned long duration = msTime - lastPrint;

  Serial.printf("[%5d][%5d]ms [%02d:%02d:%03d]           DUE_16Bit(Test1) fired!\r\n"
                                                           , timer16Bit()
                                                           , duration
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  lastPrint = millis();
  
} // print16BitTest1()


//================================================================================================
void print16BitTest2()
{
  static unsigned long lastPrint = 0;
  unsigned long  msTime = millis();
  unsigned long  duration = millis() - lastPrint;

  Serial.printf("[%5d][%5d]ms      [%02d:%02d:%03d]      DUE_16Bit(Test2) fired!\r\n"
                                                           , timer16Bit()
                                                           , duration
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  lastPrint = millis();
  
} // print16BitTest2()


//================================================================================================
void print16BitTest3()
{
  static unsigned long lastPrint = 0;
  unsigned long  msTime = millis();
  unsigned long  duration = millis() - lastPrint;

  Serial.printf("[%5d][%5d]ms           [%02d:%02d:%03d] DUE_16Bit(Test3) fired!\r\n"
                                                           , timer16Bit()
                                                           , duration
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  lastPrint = millis();
  delay(1000);  // emulate bussy
  
} // print16BitTest3()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\r\n\n.. and then it begins ...\r\n\n");
  Serial.printf("\nDue_Test1[%d]ms, Due_Test2[%d]ms Due_Test3[%d]\r\n\n", DUE_TEST1, DUE_TEST2, DUE_TEST3);
  delay(1000);
  RESTART_16Bit_TIMER(timerTest1);
  RESTART_16Bit_TIMER(timerTest2);
  RESTART_16Bit_TIMER(timerTest3);
  RESTART_TIMER(delay47Secs);
  RESTART_TIMER(after100Secs);

  Serial.printf("StartTime[%02d:%02d:%03d]\r\n" , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));

} // setup()


//================================================================================================
void loop() {
  int p;

  if ( DUE_16Bit(timerTest1, false) && 1 ) {
    if (timerTest1_last <= 0) timerTest1_last = timer16Bit();
    if ((int16_t)(timer16Bit() - timerTest1_last) < (DUE_TEST1 * 0.9))
    {
      Serial.printf("(%5d) Test1 last@[%5d] -> [%5d]ms since last due -> SKIPPING\r\n"
                                                                , timer16Bit()
                                                                , timerTest1_last
                                                                , (int16_t)(timer16Bit() - timerTest1_last));
    }
    else {
      print16BitTest1();
      timerTest1_last = timer16Bit();
    }
  }
  
  if ( DUE_16Bit(timerTest2, true) && 1 ) {
    //Serial.printf("[%5d] Test2 [%d]ms since last due\r\n", timerTest2_last
    //                                                     , SINCE_LAST_DUE_16Bit(timerTest2));
    if (timerTest2_last <= 0) timerTest2_last = timer16Bit();
    if ((int16_t)(timer16Bit() - timerTest2_last) < (DUE_TEST2 * 0.9))
    {
      Serial.printf("(%5d)  Test2 last@[%5d] -> [%5d]ms since last due -> SKIPPING\r\n"
                                                                , timer16Bit()
                                                                , timerTest2_last
                                                                , (int16_t)(timer16Bit() - timerTest2_last));
    }
    else {
      print16BitTest2();
      timerTest2_last = timer16Bit();
    }
  }

  if ( DUE_16Bit(timerTest3, true) && 1 ) {
    /*
    if (SINCE_LAST_DUE_16Bit(timerTest3) < (DUE_TEST3 * 0.9))
    {
      Serial.printf(" >>>>>  Test3 last@[%5d] -> [%5d]ms since last due -> SKIPPING\r\n"
                                                                , timerTest3_last
                                                                , SINCE_LAST_DUE_16Bit(timerTest3));
    }
    else
    */ 
    {
      print16BitTest3();
    }
  }

  //--- see what happens if the processor is occupied and can not handle timers (every 47 seconds)
  if ( DUE(delay47Secs) && 1)
  {
    //Serial.printf("delay47Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay47Secs)
    //                                                        , TIME_LEFT_MS(delay47Secs)
    //                                                        , TIME_LEFT_MIN(delay47Secs));
    //Serial.print("wait");
    RESTART_TIMER(wait3Sec);
    Serial.printf("wait3Sec:    Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(wait3Sec)
                                                            , TIME_LEFT_MS(wait3Sec)
                                                            , TIME_LEFT_MIN(wait3Sec));
    p=0;
    //--- be bussy for 3 seconds. This influance mainly Test1 
    while ( !DUE(wait3Sec) )
    {
      p++;
      if ((p%10000) == 0) Serial.print("w");
      yield();
    }
    Serial.println();
    //Serial.printf("delay47Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay47Secs)
    //                                                        , TIME_LEFT_MS(delay47Secs)
    //                                                        , TIME_LEFT_MIN(delay47Secs));
    RESTART_TIMER(delay47Secs);

    //Serial.printf("Test1: ms left [%3d]\r\n", TIME_LEFT_16Bit(timerTest1));
    //Serial.printf("Test2: ms left [%3d]\r\n", TIME_LEFT_16Bit(timerTest2));
  }

  //-- every 100 seconds do the stress test for all the timers --
  if (DUE(after100Secs))  
  {
    //--- test what happens if something keeps the system bussy for 15 seconds ---
    Serial.print("hold for 15 seconds ..");
    RESTART_TIMER(hold15Secs);
    p=0;
    //--- be bussy for 15 seconds ---
    while ( !DUE(hold15Secs) )
    {
      p++;
      if ((p%100000) == 0) Serial.print("h");
      yield();
    }
    Serial.println(".. continue!");
    Serial.printf("delay47Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay47Secs)
                                                            , TIME_LEFT_MS(delay47Secs)
                                                            , TIME_LEFT_MIN(delay47Secs));
    RESTART_TIMER(after100Secs);
  }

  if (micros() < microsDetectRollover)
  {
    Serial.println("\r\n\n*********** micros Rolled Over ****************\r\n\n");
  }
  microsDetectRollover = micros();

} // loop()
