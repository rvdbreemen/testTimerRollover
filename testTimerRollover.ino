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

#define DUE_TEST1       3000       // set 16Bit timer  3000ms
#define DUE_TEST2       7000       // set 16Bit timer  7000ms
#define DUE_TEST3      11000       // set 16Bit timer 11000ms

//prime number wait times, so they shift thru

#include "safeTimers_rvdb1.h"


  DECLARE_16Bit_TIMER(test16BitTest1, DUE_TEST1)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16Bit_TIMER(test16BitTest2, DUE_TEST2)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16Bit_TIMER(test16BitTest3, DUE_TEST3)      // print text every INTERVAL timer16Bit() ms

  DECLARE_TIMER_MS(wait3Sec, 3123)                    // delay 3+ seconds
  DECLARE_TIMER_SEC(delay32Secs, 32)                  // every 32 seconds 

  DECLARE_TIMER_SEC(after100Secs, 100)
  DECLARE_TIMER_SEC(hold15Secs, 15)

//================================================================================================
void print16BitTest1()
{
  static unsigned long lastPrint = 0;
  unsigned long msTime = millis();
  unsigned long duration = msTime - lastPrint;

  Serial.printf("[%6d][%5d]ms [%02d:%02d:%03d]           DUE_16Bit(Test1) fired!"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  if (duration > DUE_TEST1)
  {
    Serial.printf(" TOOK LONG!!!");
  }
  Serial.printf(" next shot in [%d]ms\r\n", (uint16_t)TIME_LEFT_16Bit(test16BitTest1));
  lastPrint = millis();
  
} // print16BitTest1()


//================================================================================================
void print16BitTest2()
{
  static unsigned long lastPrint = 0;
  unsigned long  msTime = millis();
  unsigned long  duration = millis() - lastPrint;

  Serial.printf("[%6d][%5d]ms      [%02d:%02d:%03d]      DUE_16Bit(Test2) fired!"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  if (duration > DUE_TEST2)
  {
    Serial.printf(" TOOK LONG!!!");
  }
  Serial.printf(" next shot in [%d]ms\r\n", (uint16_t)TIME_LEFT_16Bit(test16BitTest2));
  lastPrint = millis();
  
} // print16BitTest2()


//================================================================================================
void print16BitTest3()
{
  static unsigned long lastPrint = 0;
  unsigned long  msTime = millis();
  unsigned long  duration = millis() - lastPrint;

  Serial.printf("[%6d][%5d]ms           [%02d:%02d:%03d] DUE_16Bit(Test3) fired!"
                                                           , timer16Bit()
                                                           , (msTime - lastPrint)
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000));
    
  if (duration > DUE_TEST2)
  {
    Serial.printf(" TOOK LONG!!!");
  }
  Serial.printf(" next shot in [%d]ms\r\n", (uint16_t)TIME_LEFT_16Bit(test16BitTest3));
  lastPrint = millis();
  
} // print16BitTest3()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\n.. and then it begins ...\r\n");
  Serial.printf("\nDue_Test1[%d]ms, Due_Test2[%d]ms Due_Test3[%d]\r\n", DUE_TEST1, DUE_TEST2, DUE_TEST3);
  delay(1000);
  RESTART_16Bit_TIMER(test16BitTest1);
  RESTART_16Bit_TIMER(test16BitTest2);
  RESTART_16Bit_TIMER(test16BitTest3);
  RESTART_TIMER(delay32Secs);
  RESTART_TIMER(after100Secs);

  Serial.printf("StartTime[%02d:%02d:%03d]\r\n" , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));

} // setup()


//================================================================================================
void loop() {
  int p;

  if ( DUE_16Bit(test16BitTest1) ) {
    //Serial.printf("[%5d]", test16BitTest1_prev);
    print16BitTest1();
  }
  
  if ( DUE_16Bit(test16BitTest2) ) {
    //Serial.printf("[%5d]", test16BitTest2_prev);
    print16BitTest2();
  }

  if ( DUE_16Bit(test16BitTest3) ) {
    //Serial.printf("[%5d]", test16BitTest3_prev);
    print16BitTest3();
  }

  //--- see what happens if the processor is occupied and can not handle timers (every 32 seconds)
  if ( DUE(delay32Secs) && 1)
  {
    //Serial.printf("delay32Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay32Secs)
    //                                                        , TIME_LEFT_MS(delay32Secs)
    //                                                        , TIME_LEFT_MIN(delay32Secs));
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
    //Serial.printf("delay32Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay32Secs)
    //                                                        , TIME_LEFT_MS(delay32Secs)
    //                                                        , TIME_LEFT_MIN(delay32Secs));
    RESTART_TIMER(delay32Secs);

    //Serial.printf("Test1: ms left [%3d]\r\n", TIME_LEFT_16Bit(test16BitTest1));
    //Serial.printf("Test2: ms left [%3d]\r\n", TIME_LEFT_16Bit(test16BitTest2));
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
    Serial.printf("delay32Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n", TIME_LEFT_SEC(delay32Secs)
                                                            , TIME_LEFT_MS(delay32Secs)
                                                            , TIME_LEFT_MIN(delay32Secs));
    RESTART_TIMER(after100Secs);
  }

} // loop()
