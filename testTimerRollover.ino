/*
 * Author:  Willem Aandewiel
 * Date  : 14-02-2020
 * Thanks to Erik and Edgar Bonet
 * 
 * A program to test the micros() RollOver debacle
 * I have made some 16Bit macro's that are used with a semi micros()
 * (8 bit) timers so you don't have to wait 49 day's before a RollOver 
 * occurs.
 * Just remove the 16Bit macro's if you want to use the safeTimers.h file
 * in your program.
 */

#define DUE_TEST1       2000       // set 16Bit timer 2000ms
#define DUE_TEST2       6000       // set 16Bit timer 6000ms

#include "safeTimers.h"


  DECLARE_16Bit_TIMER(test16BitTest1, DUE_TEST1)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16Bit_TIMER(test16BitTest2, DUE_TEST2)      // print text every INTERVAL timer16Bit() ms

  DECLARE_TIMER_MS(wait3Sec, 3123)                  // delay 3+ seconds
  DECLARE_TIMER_SEC(delay17Secs, 17)                    // every 17 seconds 

  DECLARE_TIMER_SEC(after90Secs, 90)
  DECLARE_TIMER_SEC(hold15Secs, 15)

//================================================================================================
void print16BitTest1()
{
  static unsigned long lastPrint = 0;
  unsigned long msTime = millis();
  unsigned long duration = msTime - lastPrint;

/**
  Serial.printf("\r\n[%4d]ms [%02d:%02d:%03d]  timer16Bit()[%4d]/[%4d] \r\n"
                                                           , ((millis() - lastPrint) / MS_TICKS)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , (int16_t)(timer16Bit()*1)
                                                           , (int16_t)(test16BitDue_last*1));
**/
  if (duration > DUE_TEST1)
  {
    Serial.printf("\r\n[%6d][%5d]ms [%02d:%02d:%03d]            DUE_16Bit(Test1) TOOK TO LONG!!!\r\n"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
  }
  else
  {
    Serial.printf("[%6d][%5d]ms [%02d:%02d:%03d]            DUE_16Bit(Test1) fired!\r\n"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }

  lastPrint = millis();
  
} // print16BitTest1()


//================================================================================================
void print16BitTest2()
{
  static unsigned long lastPrint = 0;
  unsigned long  msTime = millis();
  unsigned long  duration = millis() - lastPrint;
  
  if (duration > DUE_TEST2)
  {
    Serial.printf("\r\n[%6d][%5d]ms            [%02d:%02d:%03d]   DUE_16Bit(Test2) TOOK TO LONG!!!\r\n"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
  }
  else
  {
    Serial.printf("[%6d][%5d]ms            [%02d:%02d:%03d]   DUE_16Bit(Test2) fired!\r\n"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  }
  lastPrint = millis();
  
} // print16BitTest2()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n.. and then it begins ...\r\n");
  Serial.printf("\nDue_Test1[%d]ms, Due_Test2[%d]ms\r\n", DUE_TEST1, DUE_TEST2);

  RESTART_16Bit_TIMER(test16BitTest1);
  RESTART_16Bit_TIMER(test16BitTest2);
  RESTART_TIMER(delay17Secs);
  RESTART_TIMER(after90Secs);

  Serial.printf("StartTime[%02d:%02d:%03d]\r\n" , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));

} // setup()


//================================================================================================
void loop() {
  int p;

  if ( DUE_16Bit(test16BitTest1) ) {
    print16BitTest1();
  }
  
  if ( DUE_16Bit(test16BitTest2) ) {
      print16BitTest2();
  }

  if ( DUE(delay17Secs) && 1)
  {
    Serial.printf("delay17Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay17Secs)
                                                            , TIME_LEFT_MS(delay17Secs)
                                                            , TIME_LEFT_MIN(delay17Secs));
    //Serial.print("wait");
    RESTART_TIMER(wait3Sec);
    Serial.printf("wait3Sec:    Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(wait3Sec)
                                                            , TIME_LEFT_MS(wait3Sec)
                                                            , TIME_LEFT_MIN(wait3Sec));
    p=0;
    while ( !DUE(wait3Sec) )
    {
      p++;
      if ((p%10000) == 0) Serial.print("w");
      yield();
    }
    Serial.printf("\r\ndelay17Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay17Secs)
                                                            , TIME_LEFT_MS(delay17Secs)
                                                            , TIME_LEFT_MIN(delay17Secs));
    RESTART_TIMER(delay17Secs);

    //Serial.printf("Test1: ms left [%3d]\r\n", TIME_LEFT_16Bit(test16BitTest1));
    //Serial.printf("Test2: ms left [%3d]\r\n", TIME_LEFT_16Bit(test16BitTest2));
  }

  if (DUE(after90Secs))  
  {
    //--- test what happens if something keeps the system hold15Secs ---
    Serial.print("hold for 15 seconds ..");
    RESTART_TIMER(hold15Secs);
    p=0;
    while ( !DUE(hold15Secs) )
    {
      p++;
      if ((p%100000) == 0) Serial.print("h");
      yield();
    }
    Serial.println(".. continue!");
    Serial.printf("delay17Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay17Secs)
                                                            , TIME_LEFT_MS(delay17Secs)
                                                            , TIME_LEFT_MIN(delay17Secs));
  }

} // loop()
