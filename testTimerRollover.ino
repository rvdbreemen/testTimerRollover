/*
 * Author:  Willem Aandewiel
 * Thanks to Erik and Edgar Bonet
 * 
 * The sole purpose of this program is to demonstrate that de timers 
 * declared with 'safeTimers.h' are rollover proof. 
 * It services no other use.
 * 
 * The 'safeTimers.h' file gives you a toolset to define and use timers 
 * in any program on a standard and easy way.
 * 
 * The file "safeTimersFastRO.h" uses uint32_t ('unsigned long') micros() 
 * in stead of millis() and so reduce the rollover time to only 1 hour 
 * 11 minutes and some seconds (the rollover time of the millis() function
 * is about 49 day's).
 * 
 * There is also an equivalent 16 bit timer and set of macro's.  
 * The timer16Bit() counts milli-seconds and has a rollover time of only
 * 1 minute and 6 seconds!
 * 
 * The timerTest1, 2, 3 and 4 make use of the timer16Bit()
 * 
 * If you want to use the safeTimers just copy the
 * tab "safeTimers.h" (or the file safeTimers.h) to your own program.
 */

//#define CONSTANT_INTERVAL_CATCH_UP_EVENTS 0
//#define CONSTANT_INTERVAL_SKIP_TO_NEXT 1
//#define CONSTANT_TIME_BETWEEN_EVENTS 2



#define DUE_TEST1       3000       // set 16Bit timer  3000ms
#define DUE_TEST2       5000       // set 16Bit timer  3000ms
#define DUE_TEST3       7000       // set 16Bit timer  8000ms
#define DUE_TEST4      11000       // set 16Bit timer 12000ms

#include "safeTimersFastRO.h" // uses 16Bit timer --> rollover in 1 minute and some seconds
                              // and micros() -> rollover in 1 hour and 10 minutes


  DECLARE_16BIT_TIMER(timerTest1, DUE_TEST1, CATCH_UP_MISSED_EVENTS)  // print text every INTERVAL timer16Bit() ms
  DECLARE_16BIT_TIMER(timerTest2,    DUE_TEST2, SKIP_MISSED_EVENTS)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16BIT_TIMER(timerTest3,         DUE_TEST3, SKIP_MISSED_EVENTS)      // print text every INTERVAL timer16Bit() ms
  DECLARE_16BIT_TIMER(timerTest4,         DUE_TEST4, CATCH_UP_MISSED_EVENTS)  // print text every INTERVAL timer16Bit() ms
  
  DECLARE_TIMER_MS(wait4Sec,     4123,  SKIP_MISSED_EVENTS)        // delay 4+ seconds
  DECLARE_TIMER_SEC(delay41Secs,   41,  SKIP_MISSED_EVENTS)        // every 41 seconds 

  DECLARE_TIMER_SEC(after180Secs, 180,  SKIP_MISSED_EVENTS)
  DECLARE_TIMER_SEC(hold15Secs,    15,  SKIP_MISSED_EVENTS)

uint32_t  microsDetectRollover     = micros();
uint32_t  timer16BitDetectRollover = timer16Bit();
uint32_t  startTime            = 0;
uint32_t  test1Counter         = 0;
uint32_t  test2Counter         = 0;
int       p;
bool      bRandomDelays        = false;

//================================================================================================
void print16BitTest(int testNr, uint32_t duration)
{
                  // 1...5....10...5....20...5....30...5....40...5....50...5....60
  char spaces[61] = "                                                            ";
  char spaceP[61] = "";
  char spaceE[61] = "";
  strncpy( spaceP, spaces, ((testNr-1)*10) );
  strncpy( spaceE, spaces, (30-((testNr-1)*10)) );
  Serial.printf("[%5d]%s [%02d:%02d:%03d] %s=> test%d runned! (after [%4.1f] seconds)\r\n"
                                                           , timer16Bit()
                                                           , spaceP
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , spaceE
                                                           , testNr
                                                           , (round(duration / 100.0) / 10.0) );
    
} // print16BitTest()


//================================================================================================
void printTimersLeftTime()
{
  Serial.printf("[%5d] timerTest1: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_16BIT(timerTest1)
                                , TIME_LEFT_16BIT(timerTest1)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest1)) / 10) * 10 );
  Serial.printf("[%5d] timerTest2: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_16BIT(timerTest2)
                                , TIME_LEFT_16BIT(timerTest2)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest2)) / 10) * 10 );
  Serial.printf("[%5d] timerTest3: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_16BIT(timerTest3)
                                , TIME_LEFT_16BIT(timerTest3)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest3)) / 10) * 10 );
  Serial.printf("[%5d] timerTest4: Time past/left [%5d/%5d]sec next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_SEC_16BIT(timerTest4)
                                , TIME_LEFT_SEC_16BIT(timerTest4)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest4)) / 10) * 10 );
  
} // printTimersLeftTime()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\r\n\n.. and then it begins ...\r\n\n");
  Serial.println(F("Stresstest for safeTimersFastRO.h macro's \r\n"));
  Serial.printf("Due_Test1[%d]ms, Due_Test2[%d]ms, Due_Test3[%d]ms, Due_Test4[%d]\r\n\n"
                                                , DUE_TEST1, DUE_TEST2, DUE_TEST3, DUE_TEST4);
  delay(1000);
  
  RESTART_TIMER(delay41Secs);
  RESTART_TIMER(after180Secs);
  RESTART_16BIT_TIMER(timerTest4);

  Serial.printf("[%5d] StartTime[%02d:%02d:%03d]\r\n" , millis()
                                                , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));
  startTime = millis();

  RESTART_TIMER(timerTest1);
  RESTART_TIMER(timerTest2);
  RESTART_TIMER(timerTest3);
  RESTART_TIMER(timerTest4);
  
  
} // setup()


//================================================================================================


void loop() {

//============ Start 16 bit timers test's ================================

//---TEST 1-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5.d6.d7<->d8<int>d9<int>d10 enz
//
  if ( DUE_16BIT(timerTest1) && 1 ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;

    test1Counter++;
    print16BitTest(1, duration);

    lastDue = millis();
  }

//---TEST 2-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5<->d6<int>d7<int>d8<int>d9 enz
//
  if ( DUE_16BIT(timerTest2) && 1 ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();

    test2Counter++;
    print16BitTest(2,  duration);

  }
  
  if ( DUE_16BIT(timerTest3) && 1 ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();
    
    print16BitTest(3, duration);
    
  }

  if ( DUE_16BIT(timerTest4) && 1 )
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();
    
    print16BitTest(4, duration);

  }
//============ End of 16 bit timers test's ===============================
  
  //--- see what happens if the processor is occupied and can not handle timers (every 41 seconds)
  if ( DUE(delay41Secs) && 1)
  {
    RESTART_TIMER(wait4Sec);
    Serial.println();
    Serial.printf("[%5d] test1 counted[%d] times fired in [%d] events" 
                                                            , timer16Bit()
                                                            , test1Counter
                                                            , ((millis() - startTime) / DUE_TEST1));
    if (test1Counter ==  ((millis() - startTime) / DUE_TEST1))
          Serial.println(" --> OK!");
    else 
    {
      int16_t error = (int16_t)(((millis() - startTime) / DUE_TEST1) - test1Counter);
      Serial.printf(" --> ERROR! (%d off)\r\n", error);
    }
    Serial.printf("[%5d] test2 counted[%d] times fired in [%d] events\r\n" 
                                                            , timer16Bit()
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

    if (bRandomDelays)  delay(random(1000));
    Serial.println();
    Serial.printf("[%5d] after180Secs: Time left [%7d]ms, [%5d]sec, [%2d]min.\r\n"
                                                            , timer16Bit()
                                                            , TIME_LEFT_MS(after180Secs)
                                                            , TIME_LEFT_SEC(after180Secs)
                                                            , TIME_LEFT_MIN(after180Secs));
    printTimersLeftTime();
    Serial.println();
    RESTART_TIMER(delay41Secs);
  }

  //-- every 180 seconds do the stress test for all the timers --
  if (DUE(after180Secs))  
  {
    //--- test what happens if something keeps the system bussy for 15 seconds ---
    Serial.printf("\r\n[%5d] hold for 15 seconds ..", timer16Bit());
    RESTART_TIMER(hold15Secs);
    bRandomDelays = !bRandomDelays;
    p=0;
    //--- be bussy for 15 seconds ---
    while ( !DUE(hold15Secs) )
    {
      p++;
      if ((p%100000) == 0) Serial.print("h");
      yield();
    }
    Serial.print(".. continue with ");
    if (bRandomDelays)  
          Serial.println(F("Random Delays!"));
    else  Serial.println(F("NO random delays!"));
    Serial.printf("[%5d] delay41Secs: Time left [%7d]ms, [%5d]sec., [%2d]min.\r\n"
                                                            , timer16Bit()
                                                            , TIME_LEFT_MS(delay41Secs)
                                                            , TIME_LEFT_SEC(delay41Secs)
                                                            , TIME_LEFT_MIN(delay41Secs));
    printTimersLeftTime();
    Serial.println();
    RESTART_TIMER(delay41Secs);
    RESTART_TIMER(after180Secs);
    timer16BitDetectRollover = timer16Bit();
  }


  if (timer16Bit() < timer16BitDetectRollover)
  {
    Serial.printf("\r\n[%5d] ***** timer16Bit() has rollover! *****\r\n", timer16Bit());
    printTimersLeftTime();
    Serial.println();
  }
  timer16BitDetectRollover = timer16Bit();
  
  if (micros() < microsDetectRollover)
  {
    Serial.println(F("\r\n\n***************************************************************************"));
    Serial.println(F(      "************************ micros() Rolled Over *****************************"));
    Serial.println(F(      "***************************************************************************\r\n\n"));
    RESTART_TIMER(delay41Secs);
    RESTART_TIMER(after180Secs);
  }
  microsDetectRollover = micros();

  if (bRandomDelays)  delay(random(500));

} // loop()
