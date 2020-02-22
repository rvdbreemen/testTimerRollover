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
 
//--- define USE_SAFETIMERS_H to include the real (production) safeTimers.h file
// #define USE_SAFETIMERS_H

//--- define SHOW_COUNTERS to print the testCounters at every wait
#define SHOW_COUNTERS

//--- select tests to run  1,2,3,4,5,6,7,8,9,10
bool      runTest[10] = {  1,1,1,1,1,0,0,0,0,0  };

#define DUE_TEST1       3000       // set 16Bit timer  3000ms
#define DUE_TEST2       3000       // set 16Bit timer  3000ms
#define DUE_TEST3       3000       // set 16Bit timer  3000ms
#define DUE_TEST4       8000       // set 16Bit timer  8000ms
#define DUE_TEST5      12000       // set 16Bit timer 12000ms

#ifdef USE_SAFETIMERS_H
  #include  "safeTimers.h"
  #define   DECLARE_TIMER_16BIT   DECLARE_TIMER 
  #define   CHANGE_TIMER_16BIT    CHANGE_TIMER 
  #define   RESTART_TIMER_16BIT   RESTART_TIMER 
  #define   TIME_LEFT_16BIT       TIME_LEFT
  #define   TIME_LEFT_SEC_16BIT   TIME_LEFT_SEC
  #define   TIME_PAST_16BIT       TIME_PAST
  #define   TIME_PAST_SEC_16BIT   TIME_PAST_SEC
  #define   DUE_16BIT             DUE
  #define   timer16Bit()          millis()

#else
  #include "safeTimersFastRO.h" // uses 16Bit timer --> rollover in 1 minute and some seconds
                                // and micros() -> rollover in 1 hour and 10 minutes
#endif

  //--- print text every INTERVAL timer16Bit() ms

  DECLARE_TIMER_16BIT(timerTest1_CatchUp, DUE_TEST1, SKIP_TO_NEXT_EVENT)
  DECLARE_TIMER_16BIT(timerTest2_Cnst,    DUE_TEST2, SKIP_TO_NEXT_EVENT)
  DECLARE_TIMER_16BIT(timerTest3_Skip,    DUE_TEST3, SKIP_TO_NEXT_EVENT)
  DECLARE_TIMER_16BIT(timerTest4,         DUE_TEST4)
  DECLARE_TIMER_16BIT(timerTest5,         DUE_TEST5, SKIP_TO_NEXT_EVENT)

//  DECLARE_TIMER_16BIT(timerTest1_CatchUp, DUE_TEST1, CATCH_UP_MISSED_EVENTS)
//  DECLARE_TIMER_16BIT(timerTest2_Cnst,    DUE_TEST2, SKIP_MISSED_EVENTS_WITH_SYNC)
//  DECLARE_TIMER_16BIT(timerTest3_Skip,    DUE_TEST3, SKIP_TO_NEXT_EVENT)
//  DECLARE_TIMER_16BIT(timerTest4,         DUE_TEST4)
//  DECLARE_TIMER_16BIT(timerTest5,         DUE_TEST5, CATCH_UP_MISSED_EVENTS)
  
  DECLARE_TIMER_SEC(startWaiting,  41)        // every 41 seconds 
  DECLARE_TIMER_SEC(startHolding, 130)

uint32_t  detect32BitRollover   = micros();
uint32_t  detect16BitRollover   = timer16Bit();
uint32_t  startTime             = 0;
uint32_t  test1Counter          = 0;
uint32_t  test2Counter          = 0;
uint32_t  test3Counter          = 0;
bool      bRandomDelays         = false;

//================================================================================================
void printTimerTypes()
{
//  Serial.println(F("---TEST 1------CATCH_UP_MISSED_EVENTS---------------------------------------------"));
//  Serial.println(F(" t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12"));
//  Serial.println(F(" |             |    <   processor   >      |"));
//  Serial.println(F(" |             |    <     bussy     >      |"));
//  Serial.println(F(" d1<int>d2<int>d3....................d4.d5.d6<int>d7<int>d8<int>d9<int>d10 enz"));
//  Serial.println(F("                                     d4>d5>d6 < less then interval, then sync"));
//  Serial.println(F("                                           d6 --> d7 (etc) == interval  "));   
//  Serial.println(); 
//
//  Serial.println(F("---TEST 2------SKIP_MISSED_EVENTS_WITH_SYNC--------------------------------------"));
//  Serial.println(F(" t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12"));
//  Serial.println(F(" |             |    <   processor   >             |"));
//  Serial.println(F(" |             |    <     bussy     >             |"));
//  Serial.println(F(" d1<int>d2<int>d3....................d5<->>d6<int>d7<int>d8<int>d9 enz"));
//  Serial.println(F("                      t4     t5     t6 missed"));
//  Serial.println(F("                                     d5 -> d6 < less then interval, then sync"));
//  Serial.println(F("                                           d6 --> d7 (etc) == interval    "));
//  Serial.println(); 
//
//  Serial.println(F("---TEST 3------SKIP_MISSED_EVENTS------------------------------------------------"));
//  Serial.println(F(" t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12"));
//  Serial.println(F(" |             |    <   processor   >  "));
//  Serial.println(F(" |             |    <     bussy     >  "));
//  Serial.println(F(" d1<int>d2<int>d3....................d5<int>d6<int>d7<int>d8<int>d9 enz"));
//  Serial.println(F("                      t4     t5     t6 missed"));
//  Serial.println(F("                                     d5 --> d6 (etc) == interval"));
//  Serial.println(); 

} // printTimerTypes()

//================================================================================================
void printTestData(int testNr, uint32_t duration, uint32_t next_due)
{
                  // 1...5....10...5....20...5....30...5....40...5....50...5....60
  char spaces[61] = "                                                            ";
  char spaceB[61] = "";
  char spaceA[61] = "";
  uint8_t a = 0;  // after
  uint8_t b = 0;  // before
  for (int n=0; n<sizeof(runTest); n++)
  {
    if ((testNr-1) == n) b = a;
    if (runTest[n]) a++;
  }
  //Serial.printf("testNr[%d], position[%d] => spaceB[%d], spaceA[%d]\r\n", testNr, b, (b*10), (((a-1)* 10)-(b*10)) );
  //Serial.flush();
  strncpy( spaceB, spaces, (b*10) );
  strncpy( spaceA, spaces, (((a-1)* 10)-(b*10)) );
  if (runTest[(testNr-1)]) 
  {
    Serial.printf("[%5d]%s [%02d:%02d:%03d] %s=> test%d runned! ([%4.1f]Sec.) -> %d_due[%5d]\r\n"
                                                           , timer16Bit()
                                                           , spaceB
                                                           , ((millis() / (60 * 1000)) % 60)
                                                           , ((millis() / 1000) % 60)
                                                           , (millis() % 1000)
                                                           , spaceA
                                                           , testNr
                                                           , (round(duration / 100.0) / 10.0)
                                                           , testNr
                                                           , next_due);
  }
  Serial.flush();
    
} // printTestData()


//================================================================================================
void printTimersLeftTime()
{
  if (runTest[0]) {
    Serial.printf("[%5d] timerTest1: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_16BIT(timerTest1_CatchUp)
                                , TIME_LEFT_16BIT(timerTest1_CatchUp)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest1_CatchUp)) / 10) * 10 );
  }
  if (runTest[1]) {
    Serial.printf("[%5d] timerTest2: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , (uint32_t)TIME_PAST_16BIT(timerTest2_Cnst)
                                , (uint32_t)TIME_LEFT_16BIT(timerTest2_Cnst)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest2_Cnst)) / 10) * 10 );
  }
  if (runTest[2]) {
    Serial.printf("[%5d] timerTest3: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_16BIT(timerTest3_Skip)
                                , TIME_LEFT_16BIT(timerTest3_Skip)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest3_Skip)) / 10) * 10 );
  }
  if (runTest[3]) {
    Serial.printf("[%5d] timerTest4: Time past/left [%5d/%5d]ms  next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_16BIT(timerTest4)
                                , TIME_LEFT_16BIT(timerTest4)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest4)) / 10) * 10 );
  }
  if (runTest[4]) {
    Serial.printf("[%5d] timerTest5: Time past/left [%5d/%5d]sec next due after [%5d]!\r\n"
                                , timer16Bit()
                                , TIME_PAST_SEC_16BIT(timerTest5)
                                , TIME_LEFT_SEC_16BIT(timerTest5)
                                , ((timer16Bit() + TIME_LEFT_16BIT(timerTest5)) / 10) * 10 );
  }
  Serial.println();

} // printTimersLeftTime()


//================================================================================================
void setup() {
  Serial.begin(115200);
  Serial.println("\r\n\n.. and then it begins ...\r\n\n");
#ifdef USE_SAFETIMERS_H
  Serial.println(F("Stresstest for safeTimers.h macro's \r\n"));
#else
  Serial.println(F("Stresstest for safeTimersFastRO.h macro's \r\n"));
#endif
  //--- This is 8266 HWRNG used to seed the Random PRNG: 
  //--- See: https://config9.com/arduino/getting-a-truly-random-number-in-arduino/ 
//  randomSeed(RANDOM_REG32); 
  delay(random(500));
  
  printTimerTypes();
  
  int8_t n;
  for (int n=0; n<sizeof(runTest); n++)
  {
    if (runTest[n])
    {
      switch(n) {
        case 0:   Serial.printf("Due_Test1[%5d]ms ", DUE_TEST1);
                  break;
        case 1:   Serial.printf("Due_Test2[%5d]ms ", DUE_TEST2);
                  break;
        case 2:   Serial.printf("Due_Test3[%5d]ms ", DUE_TEST3);
                  break;
        case 3:   Serial.printf("Due_Test4[%5d]ms ", DUE_TEST4);
                  break;
        case 4:   Serial.printf("Due_Test5[%5d]ms ", DUE_TEST5);
                  break;
      }
    }
  }
  Serial.println();
  for (int n=0; n<sizeof(runTest); n++)
  {
    if (runTest[n])
    {
      switch(n) {
        case 0:   Serial.printf("testType1[%d]       ", timerTest1_CatchUp_type);
                  break;
        case 1:   Serial.printf("testType2[%d]       ", timerTest2_Cnst_type);
                  break;
        case 2:   Serial.printf("testType3[%d]       ", timerTest3_Skip_type);
                  break;
        case 3:   Serial.printf("testType4[%d]       ", timerTest4_type);
                  break;
        case 4:   Serial.printf("testType5[%d]       ", timerTest5_type);
                  break;
      }
    }
  }
  Serial.println("\r\n");
  
  RESTART_TIMER(startWaiting);
  RESTART_TIMER(startHolding);
  RESTART_TIMER_16BIT(timerTest5);

  //--- ok, this is only to sequence the timers ----------
  timerTest1_CatchUp_due  = timer16Bit() + DUE_TEST1;
  timerTest2_Cnst_due     = timerTest1_CatchUp_due +  500;
  timerTest3_Skip_due     = timerTest1_CatchUp_due + 1000;

  Serial.printf("[%5d] StartTime[%02d:%02d:%03d]\r\n" , millis()
                                                , ((millis() / (60 * 1000)) % 60)
                                                , ((millis() / 1000) % 60)
                                                , (millis() % 1000));
  startTime = millis();
  
} // setup()


//================================================================================================
void loop() {

//============ Start 16 bit timers test's ==================================

//
  if ( DUE_16BIT(timerTest1_CatchUp) && runTest[0] ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;

    test1Counter++;
    printTestData(1, duration, timerTest1_CatchUp_due);

    lastDue = millis();
  }

  if ( DUE_16BIT(timerTest2_Cnst) && runTest[1] ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();

    test2Counter++;
    printTestData(2, duration, timerTest2_Cnst_due);
  }
  
  if ( DUE_16BIT(timerTest3_Skip) && runTest[2] ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();
    
    test3Counter++;
    printTestData(3, duration, timerTest3_Skip_due);
  }
  
  if ( DUE_16BIT(timerTest4) && runTest[3] ) 
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();
    
    printTestData(4, duration, timerTest4_due);
    
  }

  if ( DUE_16BIT(timerTest5) && runTest[4] )
  {
    static uint32_t lastDue = 0;
    uint32_t        duration = millis() - lastDue;
    lastDue = millis();
    
    printTestData(5, duration, timerTest5_due);

  }
//============ End of 16 bit timers test's ===============================
  
  //--- see what happens if the processor is occupied and can not handle timers (every 41 seconds)
  if ( DUE(startWaiting) && 1)
  {
    Serial.println();
#ifdef SHOW_COUNTERS
    {
      Serial.printf("[%5d] test1 counted[%d] times run in [%d] events" 
                                                            , timer16Bit()
                                                            , test1Counter
                                                            , ((millis() - startTime) / DUE_TEST1));
      if (test1Counter ==  ((millis() - startTime) / DUE_TEST1))
          Serial.println(" --> EQUAL");
      else 
      {
        int16_t error = (int16_t)(((millis() - startTime) / DUE_TEST1) - test1Counter);
        Serial.printf(" --> ? (%d off)\r\n", error);
      }
      Serial.printf("[%5d] test2 counted[%d] times run in [%d] events" 
                                                            , timer16Bit()
                                                            , test2Counter
                                                            , ((millis() - startTime) / DUE_TEST2));
      if (test2Counter ==  ((millis() - startTime) / DUE_TEST1))
          Serial.println(" --> EQUAL");
      else 
      {
        int16_t error = (int16_t)(((millis() - startTime) / DUE_TEST2) - test2Counter);
        Serial.printf(" --> ? (%d off)\r\n", error);
      }
      Serial.printf("[%5d] test3 counted[%d] times run in [%d] events" 
                                                            , timer16Bit()
                                                            , test3Counter
                                                            , ((millis() - startTime) / DUE_TEST3));
      if (test3Counter ==  ((millis() - startTime) / DUE_TEST1))
          Serial.println(" --> EQUAL");
      else 
      {
        int16_t error = (int16_t)(((millis() - startTime) / DUE_TEST3) - test3Counter);
        Serial.printf(" --> ? (%d off)\r\n", error);
      }
    }
#endif

    Serial.println();
    printTimersLeftTime();
    //--- be bussy for 4 seconds. This influances mainly Test1 & 2 & 3
    Serial.printf("\r\n[%5d] wait ... ", timer16Bit());

    for(byte cc=0; cc<40; cc++)
    {
      Serial.printf("w");
      delay(100);
      yield();
    }
    Serial.println(F(".. continue"));


    if (bRandomDelays)  delay(random(1000));
    Serial.println();
    Serial.printf("[%5d] startHolding: Time left [%7d]ms, [%5d]sec, [%2d]min.\r\n"
                                                            , timer16Bit()
                                                            , TIME_LEFT_MS(startHolding)
                                                            , TIME_LEFT_SEC(startHolding)
                                                            , TIME_LEFT_MIN(startHolding));
    printTimersLeftTime();
    Serial.println();
    RESTART_TIMER(startWaiting);
  }

  //-- every x seconds do the stress test for all the timers --
  if (DUE(startHolding) && 1)  
  {
    printTimersLeftTime();

    //--- test what happens if something keeps the system bussy for 15 seconds ---
    Serial.printf("\r\n[%5d] hold ... ", timer16Bit());

    bRandomDelays = !bRandomDelays;
    byte cc = 15;
    //--- be bussy for 15 seconds ---
    while (cc > 0)
    {
      Serial.printf("%d ", cc--);
      delay(1000);
      yield();
    }
    Serial.println(F(".. continue"));
    if (bRandomDelays)  
          Serial.println(F("************************* using Random Delays from here on ***********************\r\n"));
    else  Serial.println(F("*********************** using NO random delays! from here on *********************\r\n"));

    Serial.printf("[%5d] startWaiting: Time left [%7d]ms, [%5d]sec., [%2d]min.\r\n\n"
                                                            , timer16Bit()
                                                            , TIME_LEFT_MS(startWaiting)
                                                            , TIME_LEFT_SEC(startWaiting)
                                                            , TIME_LEFT_MIN(startWaiting));
    printTimersLeftTime();
    Serial.println();
    RESTART_TIMER(startWaiting);
    RESTART_TIMER(startHolding);
    detect16BitRollover = timer16Bit();
  }


  if (timer16Bit() < detect16BitRollover)
  {
    Serial.printf("\r\n[%5d] ***** timer16Bit() has rolled-over! *****\r\n\n", timer16Bit());
    printTimersLeftTime();
  }
  detect16BitRollover = timer16Bit();
  
  if (micros() < detect32BitRollover)
  {
    Serial.println(F("\r\n\n***************************************************************************"));
    Serial.println(F(      "************************ micros() Rolled Over *****************************"));
    Serial.println(F(      "***************************************************************************\r\n\n"));
    RESTART_TIMER(startWaiting);
    RESTART_TIMER(startHolding);
  }
  detect32BitRollover = micros();

  if (bRandomDelays)  delay(random(500));

} // loop()
