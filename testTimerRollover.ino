/*
 * Author:  Willem Aandewiel
 * Date  : 14-02-2020
 * Thanks to Erik and Edgar Bonet
 * 
 * A program to test the millis() RollOver debacle
 * 
 * The file "safeTimersFastRO.h" uses micros() so the rollover time is 
 * only 1 hour 11 minutes and some seconds.
 * For the test1 to test4 it uses a 16Bit timer with a Rollover time of  
 * only 1 minute and 6 seconds!
 * 
 * If you want to use the safeTimers in your program, just copy the
 * tab "safeTimers.h".
 */

//#define CONSTANT_INTERVAL_CATCH_UP_EVENTS 0
//#define CONSTANT_INTERVAL_SKIP_TO_NEXT 1
//#define CONSTANT_TIME_BETWEEN_EVENTS 2



#define DUE_TEST1       3000       // set 16Bit timer  3000ms
#define DUE_TEST2       5000       // set 16Bit timer  3000ms
#define DUE_TEST3       7000       // set 16Bit timer  8000ms
#define DUE_TEST4      11000       // set 16Bit timer 12000ms

#include "safeTimersFastRO_rvdb.h" // uses 16Bit timer --> rollover in 1 minute and some seconds
                              // and micros() -> rollover in 1 hour and 10 minutes

  

  DECLARE_16BIT_TIMER(timerTest1,       DUE_TEST1, CONSTANT_INTERVAL_SKIP_TO_NEXT)       // print text every INTERVAL timer16Bit() ms
  DECLARE_16BIT_TIMER(timerTest2,       DUE_TEST2, CONSTANT_INTERVAL_SKIP_TO_NEXT)       // print text every INTERVAL timer16Bit() ms
  DECLARE_16BIT_TIMER(timerTest3,       DUE_TEST3, CONSTANT_INTERVAL_SKIP_TO_NEXT)     // print text every INTERVAL timer16Bit() ms
  DECLARE_16BIT_TIMER(timerTest4,       DUE_TEST4, CONSTANT_INTERVAL_SKIP_TO_NEXT)  // print text every INTERVAL timer16Bit() ms

  DECLARE_TIMER_MS(wait4Sec,     4123,  CONSTANT_TIME_BETWEEN_EVENTS)        // delay 4+ seconds
  DECLARE_TIMER_SEC(delay41Secs,   41,  CONSTANT_TIME_BETWEEN_EVENTS)        // every 41 seconds 

  DECLARE_TIMER_SEC(after100Secs, 100,  CONSTANT_TIME_BETWEEN_EVENTS)
  DECLARE_TIMER_SEC(hold15Secs,    15,  CONSTANT_TIME_BETWEEN_EVENTS)

uint32_t  microsDetectRollover = micros();
uint32_t  startTime            = 0;
uint32_t  test1Counter         = 0;
uint32_t  test2Counter         = 0;
uint32_t lastPrint1 = 0;
uint32_t lastPrint2 = 0;
uint32_t lastPrint3 = 0;
uint32_t lastPrint4 = 0;

//================================================================================================
void print16BitTest(int testNr, uint16_t duration)
{
                  // 1...5....10...5....20...5....30...5....40...5....50...5....60
  char spaces[61] = "                                                            ";
  char spaceP[61] = "";
  char spaceE[61] = "";
  strncpy( spaceP, spaces, ((testNr-1)*10) );
  strncpy( spaceE, spaces, (30-((testNr-1)*10)) );
  Serial.printf("[%5d][%5d]ms %s [%02d:%02d:%03d] %s=> test%d fired!\r\n"
                                                           , timer16Bit()
                                                           , duration
                                                           , spaceP
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , spaceE
                                                           , testNr);
    
} // print16BitTest()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\r\n\n.. and then it begins ...\r\n\n");
  Serial.printf("\nDue_Test1[%d]ms, Due_Test2[%d]ms, Due_Test3[%d]ms, Due_Test4[%d]\r\n\n"
                                                , DUE_TEST1, DUE_TEST2, DUE_TEST3, DUE_TEST4);
  delay(1000);
  
  RESTART_TIMER(delay41Secs);
  RESTART_TIMER(after100Secs);

  Serial.printf("StartTime[%02d:%02d:%03d]\r\n" , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));
  startTime = millis();
  lastPrint1 = startTime;
  lastPrint2 = startTime;
  lastPrint3 = startTime;
  lastPrint4 = startTime;
  RESTART_TIMER(timerTest1);
  RESTART_TIMER(timerTest2);
  RESTART_TIMER(timerTest3);
  RESTART_TIMER(timerTest4);
  
  
} // setup()


//================================================================================================


void loop() {
  int p;
//============ Start 16 bit timers test's ================================

//---TEST 1-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5.d6.d7<->d8<int>d9<int>d10 enz
//
  if ( DUE_16BIT(timerTest1) && 1 ) 
  {

    test1Counter++;
    print16BitTest(1, millis() - lastPrint1);
    lastPrint1 = millis();
    //delay(random(500));
  }

//---TEST 2-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5<->d6<int>d7<int>d8<int>d9 enz
//
  if ( DUE_16BIT(timerTest2) && 1 ) 
  {
    
    test2Counter++;
    print16BitTest(2, millis() - lastPrint2);

    lastPrint2 = millis();
    //delay(random(500));
 }
  
  if ( DUE_16BIT(timerTest3) && 1 ) 
  {
   
    print16BitTest(3, millis() - lastPrint3);
    
    lastPrint3 = millis();
    //delay(random(500));
  }

  if ( DUE_16BIT(timerTest4) && 1 )
  {
   
    print16BitTest(4, millis() - lastPrint4);

    lastPrint4 = millis();
    //delay(random(500));
  }
//============ End of 16 bit timers test's ===============================
  
  //--- see what happens if the processor is occupied and can not handle timers (every 41 seconds)
  if ( DUE(delay41Secs) && 1)
  {
    RESTART_TIMER(wait4Sec);
    Serial.printf("test1 counted[%d] times fired in [%d] events" 
                                                            , test1Counter
                                                            , ((millis() - startTime) / DUE_TEST1));
    if (test1Counter ==  ((millis() - startTime) / DUE_TEST1))
          Serial.println(" --> OK!");
    else 
    {
      int16_t error = (int16_t)(((millis() - startTime) / DUE_TEST1) - test1Counter);
      Serial.printf(" --> ERROR! (%d off)\r\n", error);
    }
    Serial.printf("test2 counted[%d] times fired in [%d] events\r\n" 
                                                            , test2Counter
                                                            , ((millis() - startTime) / DUE_TEST2));
    
    p=0;
    //--- be bussy for 4 seconds. This influance mainly Test1 & 2
    while ( !DUE(wait4Sec) )
    {
      p++;
      if ((p%10000) == 0) Serial.print("w");
      yield();
    }
    //delay(random(1000));
    Serial.println();
    Serial.printf("after100Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n"
                                                            , TIME_LEFT_SEC(after100Secs)
                                                            , TIME_LEFT_MS(after100Secs)
                                                            , TIME_LEFT_MIN(after100Secs));
    RESTART_TIMER(delay41Secs);
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
    Serial.printf("delay41Secs: Time left [%3d]sec., [%7d]ms, [%2d]min.\r\n"
                                                            , TIME_LEFT_SEC(delay41Secs)
                                                            , TIME_LEFT_MS(delay41Secs)
                                                            , TIME_LEFT_MIN(delay41Secs));
    //delay(random(1000));
    RESTART_TIMER(after100Secs);
  }

  if (micros() < microsDetectRollover)
  {
    Serial.println(F("\r\n\n***************************************************************************"));
    Serial.println(F(      "************************ micros() Rolled Over *****************************"));
    Serial.println(F(      "***************************************************************************\r\n\n"));
  }
  microsDetectRollover = micros();

} // loop()
