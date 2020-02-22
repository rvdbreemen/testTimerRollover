=======================
Date: 22-02-2020  17:15
=======================

//---TEST 1----CATCH_UP_MISSED_EVENTS---------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5.d6.d7<->d8<int>d9<int>d10 enz
//
Test1 moet dus de gemiste "due's" inhalen.
In het test-log (over ruim een uur hier op github) zul je zien hoe ik dat 
gebruik en waarom dit nodig is!
In het figuurtje hierboven "mist" test1 t5 en t6, maar haalt deze weer in
tot na t7 de ingestelde interval weer gebruikt wordt.

//---TEST 2-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// --- geen idee ---
//
Test2 ???

//---TEST 3-------------------------------------------------------------------
// t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11
//                            <processor>
//                            <  bussy  >
// d1<int>d2<int>d3<int>d4 ..............d5<int>d6<int>d7<int>d8<int>d9 enz
//
Test3 vuurt direct na een lange pauze (omdat de processor met andere, 
tijdrovende, zaken bezig was) maar herstelt daarna de interval.
In het figuurtje hierboven "mist" test3 t5 en t6, maar de eerstvolgende
keer dat het due-event gevuurd wordt (d5) wordt d6 pas gevuurd nadat
de interval is verstreken.





Stresstest for safeTimersFastRO.h macro's 

---TEST 1------CATCH_UP_MISSED_EVENTS---------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |    <   processor   >      |
 |             |    <     bussy     >      |
 d1<int>d2<int>d3....................d4.d5.d6<int>d7<int>d8<int>d9<int>d10 enz
                                     d4>d5>d6 < less then interval, then sync
                                           d6 --> d7 (etc) == interval  

---TEST 2------SKIP_MISSED_EVENTS_WITH_SYNC--------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |    <   processor   >             |
 |             |    <     bussy     >             |
 d1<int>d2<int>d3....................d5<->>d6<int>d7<int>d8<int>d9 enz
                      t4     t5     t6 missed
                                     d5 -> d6 < less then interval, then sync
                                           d6 --> d7 (etc) == interval    

---TEST 3------SKIP_MISSED_EVENTS------------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |    <   processor   >  
 |             |    <     bussy     >  
 d1<int>d2<int>d3....................d5<int>d6<int>d7<int>d8<int>d9 enz
                      t4     t5     t6 missed
                                     d5 --> d6 (etc) == interval

Due_Test1[ 3000]ms Due_Test2[ 3000]ms Due_Test3[ 3000]ms Due_Test5[12000]ms 
testType1[1]       testType2[2]       testType3[0]       testType5[1]       

[  419] StartTime[00:00:419]
[ 3419] [00:03:419]                               => test1 runned! ([ 3.4]Sec.) -> 1_due[ 6419]
[ 3919]           [00:03:919]                     => test2 runned! ([ 3.9]Sec.) -> 2_due[ 6919]
[ 4419]                     [00:04:419]           => test3 runned! ([ 4.4]Sec.) -> 3_due[ 7419]
[ 6419] [00:06:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9419]
[ 6919]           [00:06:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 9919]
[ 7419]                     [00:07:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[10419]
[ 9419] [00:09:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[12419]
[ 9919]           [00:09:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[12919]
[10419]                     [00:10:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[13419]
[12419]                               [00:12:419] => test5 runned! ([12.4]Sec.) -> 5_due[24419]
[12428] [00:12:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[15419]
[12919]           [00:12:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[15919]
[13419]                     [00:13:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[16419]
[15419] [00:15:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[18419]
[15919]           [00:15:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[18919]
[16419]                     [00:16:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[19419]
[18419] [00:18:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[21419]
[18919]           [00:18:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[21919]
[19419]                     [00:19:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[22419]
[21419] [00:21:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[24419]
[21919]           [00:21:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[24919]
[22419]                     [00:22:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[25419]
[24419]                               [00:24:419] => test5 runned! ([12.0]Sec.) -> 5_due[36419]
[24428] [00:24:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[27419]
[24919]           [00:24:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[27919]
[25419]                     [00:25:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[28419]
[27419] [00:27:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[30419]
[27919]           [00:27:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[30919]
[28419]                     [00:28:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[31419]
[30419] [00:30:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[33419]
[30919]           [00:30:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[33919]
[31419]                     [00:31:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[34419]
[33419] [00:33:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[36419]
[33919]           [00:33:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[36919]
[34419]                     [00:34:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[37419]
[36419] [00:36:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[39419]
[36428]                               [00:36:428] => test5 runned! ([12.0]Sec.) -> 5_due[48419]
[36919]           [00:36:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[39919]
[37419]                     [00:37:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[40419]
[39419] [00:39:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[42419]
[39919]           [00:39:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[42919]
[40419]                     [00:40:419]           => test3 runned! ([ 3.0]Sec.) -> 3_due[43419]

[41420] test1 counted[13] times run in [13] events --> EQUAL
[41420] test2 counted[13] times run in [13] events --> EQUAL
[41420] test3 counted[13] times run in [13] events --> EQUAL

[41425] timerTest1: Time past/left [ 2006/  994]ms  next due after [42410]!
[41432] timerTest2: Time past/left [ 1513/ 1487]ms  next due after [42910]!
[41438] timerTest3: Time past/left [ 1019/ 1981]ms  next due after [43410]!
[41445] timerTest5: Time past/left [    5/    6]sec next due after [48410]!


[41452] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[45456] startHolding: Time left [  84963]ms, [   84]sec, [ 1]min.
[45457] timerTest1: Time past/left [ 3000/    0]ms  next due after [45450]!
[45459] timerTest2: Time past/left [ 3000/    0]ms  next due after [45450]!
[45466] timerTest3: Time past/left [ 3000/    0]ms  next due after [45460]!
[45472] timerTest5: Time past/left [    9/    2]sec next due after [48410]!


[45479] [00:45:479]                               => test1 runned! ([ 6.1]Sec.) -> 1_due[45419]
[45499]           [00:45:499]                     => test2 runned! ([ 5.6]Sec.) -> 2_due[45919]
[45508]                     [00:45:508]           => test3 runned! ([ 5.1]Sec.) -> 3_due[48508]
[45517] [00:45:517]                               => test1 runned! ([ 0.0]Sec.) -> 1_due[48419]
[45919]           [00:45:919]                     => test2 runned! ([ 0.4]Sec.) -> 2_due[48919]
[48419] [00:48:419]                               => test1 runned! ([ 2.9]Sec.) -> 1_due[51419]
[48428]                               [00:48:428] => test5 runned! ([12.0]Sec.) -> 5_due[60419]
[48508]                     [00:48:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[51508]
[48919]           [00:48:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[51919]
[51419] [00:51:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[54419]
[51508]                     [00:51:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[54508]
[51919]           [00:51:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[54919]
[54419] [00:54:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[57419]
[54508]                     [00:54:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[57508]
[54919]           [00:54:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[57919]
[57419] [00:57:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[60419]
[57508]                     [00:57:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[60508]
[57919]           [00:57:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[60919]
[60419] [01:00:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[63419]
[60428]                               [01:00:428] => test5 runned! ([12.0]Sec.) -> 5_due[ 6883]
[60508]                     [01:00:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[63508]
[60919]           [01:00:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[63919]
[63419] [01:03:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[  883]
[63508]                     [01:03:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[  972]
[63919]           [01:03:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1383]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 2117/  883]ms  next due after [  880]!
[    0] timerTest2: Time past/left [ 1617/ 1383]ms  next due after [ 1380]!
[    7] timerTest3: Time past/left [ 2035/  965]ms  next due after [  970]!
[   13] timerTest5: Time past/left [    5/    6]sec next due after [ 6880]!

[  883] [01:06:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3883]
[  972]                     [01:06:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 3972]
[ 1383]           [01:06:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4383]
[ 3883] [01:09:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6883]
[ 3972]                     [01:09:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 6972]
[ 4383]           [01:09:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 7383]
[ 6883] [01:12:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9883]
[ 6892]                               [01:12:428] => test5 runned! ([12.0]Sec.) -> 5_due[18883]
[ 6972]                     [01:12:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 9972]
[ 7383]           [01:12:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[10383]
[ 9883] [01:15:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[12883]
[ 9972]                     [01:15:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[12972]
[10383]           [01:15:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[13383]
[12883] [01:18:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[15883]
[12972]                     [01:18:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[15972]
[13383]           [01:18:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[16383]
[15883] [01:21:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[18883]
[15972]                     [01:21:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[18972]
[16383]           [01:21:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[19383]
[18883]                               [01:24:419] => test5 runned! ([12.0]Sec.) -> 5_due[30883]
[18892] [01:24:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[21883]
[18972]                     [01:24:508]           => test3 runned! ([ 3.0]Sec.) -> 3_due[21972]
[19383]           [01:24:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[22383]

[20943] test1 counted[28] times run in [28] events --> EQUAL
[20944] test2 counted[28] times run in [28] events --> EQUAL
[20944] test3 counted[27] times run in [28] events --> ? (1 off)

[20949] timerTest1: Time past/left [ 2066/  934]ms  next due after [21880]!
[20956] timerTest2: Time past/left [ 1573/ 1427]ms  next due after [22380]!
[20962] timerTest3: Time past/left [ 1990/ 1010]ms  next due after [21970]!
[20969] timerTest5: Time past/left [    2/    9]sec next due after [30880]!


[20976] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[24980] startHolding: Time left [  39903]ms, [   39]sec, [ 0]min.
[24981] timerTest1: Time past/left [ 3000/    0]ms  next due after [24980]!
[24983] timerTest2: Time past/left [ 3000/    0]ms  next due after [24980]!
[24989] timerTest3: Time past/left [ 3000/    0]ms  next due after [24980]!
[24996] timerTest5: Time past/left [    6/    5]sec next due after [30880]!


[25003] [01:30:539]                               => test1 runned! ([ 6.1]Sec.) -> 1_due[24883]
[25023]           [01:30:559]                     => test2 runned! ([ 5.6]Sec.) -> 2_due[25383]
[25032]                     [01:30:568]           => test3 runned! ([ 6.1]Sec.) -> 3_due[28032]
[25041] [01:30:577]                               => test1 runned! ([ 0.0]Sec.) -> 1_due[27883]
[25383]           [01:30:919]                     => test2 runned! ([ 0.4]Sec.) -> 2_due[28383]
[27883] [01:33:419]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[30883]
[28032]                     [01:33:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[31032]
[28383]           [01:33:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[31383]
[30883]                               [01:36:419] => test5 runned! ([12.0]Sec.) -> 5_due[42883]
[30892] [01:36:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[33883]
[31032]                     [01:36:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[34032]
[31383]           [01:36:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[34383]
[33883] [01:39:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[36883]
[34032]                     [01:39:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[37032]
[34383]           [01:39:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[37383]
[36883] [01:42:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[39883]
[37032]                     [01:42:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[40032]
[37383]           [01:42:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[40383]
[39883] [01:45:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[42883]
[40032]                     [01:45:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[43032]
[40383]           [01:45:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[43383]
[42883]                               [01:48:419] => test5 runned! ([12.0]Sec.) -> 5_due[54883]
[42892] [01:48:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[45883]
[43032]                     [01:48:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[46032]
[43383]           [01:48:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[46383]
[45883] [01:51:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[48883]
[46032]                     [01:51:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[49032]
[46383]           [01:51:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[49383]
[48883] [01:54:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[51883]
[49032]                     [01:54:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[52032]
[49383]           [01:54:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[52383]
[51883] [01:57:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[54883]
[52032]                     [01:57:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[55032]
[52383]           [01:57:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[55383]
[54883]                               [02:00:419] => test5 runned! ([12.0]Sec.) -> 5_due[ 1347]
[54892] [02:00:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[57883]
[55032]                     [02:00:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[58032]
[55383]           [02:00:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[58383]
[57883] [02:03:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[60883]
[58032]                     [02:03:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[61032]
[58383]           [02:03:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[61383]
[60883] [02:06:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[63883]
[61032]                     [02:06:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[64032]
[61383]           [02:06:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[64383]
[63883] [02:09:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1347]
[64032]                     [02:09:568]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 1496]
[64383]           [02:09:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1847]
[64884] timerTest1: Time past/left [ 1000/ 2000]ms  next due after [66880]!
[64884] timerTest2: Time past/left [  500/ 2500]ms  next due after [67380]!
[64886] timerTest3: Time past/left [  853/ 2147]ms  next due after [67030]!
[64893] timerTest5: Time past/left [   10/    1]sec next due after [66880]!


[64900] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
************************* using Random Delays from here on ***********************

[14369] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[14373] timerTest1: Time past/left [ 3000/    0]ms  next due after [14370]!
[14379] timerTest2: Time past/left [ 3000/    0]ms  next due after [14370]!
[14386] timerTest3: Time past/left [ 3000/    0]ms  next due after [14380]!
[14393] timerTest5: Time past/left [   12/    0]sec next due after [14390]!


[14820] [02:25:892]                               => test1 runned! ([16.5]Sec.) -> 1_due[ 4347]
[14830]           [02:25:902]                     => test2 runned! ([16.0]Sec.) -> 2_due[16847]
[14839]                     [02:25:911]           => test3 runned! ([16.3]Sec.) -> 3_due[17839]
[14848]                               [02:25:920] => test5 runned! ([25.5]Sec.) -> 5_due[13347]
[15117] [02:26:189]                               => test1 runned! ([ 0.3]Sec.) -> 1_due[ 7347]
[15127]                               [02:26:199] => test5 runned! ([ 0.3]Sec.) -> 5_due[25347]
[15356] [02:26:428]                               => test1 runned! ([ 0.2]Sec.) -> 1_due[10347]
[15438] [02:26:510]                               => test1 runned! ([ 0.1]Sec.) -> 1_due[13347]
[15811] [02:26:883]                               => test1 runned! ([ 0.4]Sec.) -> 1_due[16347]
[16615] [02:27:687]                               => test1 runned! ([ 0.8]Sec.) -> 1_due[19347]
[17029]           [02:28:101]                     => test2 runned! ([ 2.2]Sec.) -> 2_due[19847]
[18106]                     [02:29:178]           => test3 runned! ([ 3.3]Sec.) -> 3_due[21106]
[19459] [02:30:531]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[22347]
[19961]           [02:31:033]                     => test2 runned! ([ 2.9]Sec.) -> 2_due[22847]
[21464]                     [02:32:536]           => test3 runned! ([ 3.4]Sec.) -> 3_due[24464]
[22574] [02:33:646]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[25347]
[23013]           [02:34:085]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[25847]
[24532]                     [02:35:604]           => test3 runned! ([ 3.1]Sec.) -> 3_due[27532]
[25350] [02:36:422]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[28347]
[25360]                               [02:36:432] => test5 runned! ([10.2]Sec.) -> 5_due[37347]
[26076]           [02:37:148]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[28847]
[27733]                     [02:38:805]           => test3 runned! ([ 3.2]Sec.) -> 3_due[30733]
[28378] [02:39:450]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[31347]
[28850]           [02:39:922]                     => test2 runned! ([ 2.8]Sec.) -> 2_due[31847]
[30872]                     [02:41:944]           => test3 runned! ([ 3.1]Sec.) -> 3_due[33872]
[31521] [02:42:593]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[34347]
[32092]           [02:43:164]                     => test2 runned! ([ 3.2]Sec.) -> 2_due[34847]
[33940]                     [02:45:012]           => test3 runned! ([ 3.1]Sec.) -> 3_due[36940]
[34755] [02:45:827]                               => test1 runned! ([ 3.2]Sec.) -> 1_due[37347]
[34933]           [02:46:005]                     => test2 runned! ([ 2.8]Sec.) -> 2_due[37847]
[36973]                     [02:48:046]           => test3 runned! ([ 3.0]Sec.) -> 3_due[39973]
[37371] [02:48:443]                               => test1 runned! ([ 2.6]Sec.) -> 1_due[40347]
[37381]                               [02:48:453] => test5 runned! ([12.0]Sec.) -> 5_due[49347]
[37999]           [02:49:071]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[40847]
[40398] [02:51:470]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[43347]
[40408]                     [02:51:480]           => test3 runned! ([ 3.4]Sec.) -> 3_due[43408]
[41112]           [02:52:184]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[43847]
[43444] [02:54:516]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[46347]
[43454]                     [02:54:526]           => test3 runned! ([ 3.0]Sec.) -> 3_due[46454]
[43850]           [02:54:922]                     => test2 runned! ([ 2.7]Sec.) -> 2_due[46847]
[46417] [02:57:489]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[49347]
[46565]                     [02:57:637]           => test3 runned! ([ 3.1]Sec.) -> 3_due[49565]
[46894]           [02:57:966]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[49847]
[49418] [03:00:490]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[52347]
[49428]                               [03:00:500] => test5 runned! ([12.0]Sec.) -> 5_due[61347]
[49660]                     [03:00:732]           => test3 runned! ([ 3.1]Sec.) -> 3_due[52660]
[49956]           [03:01:028]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[52847]
[52479] [03:03:551]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[55347]
[52820]                     [03:03:892]           => test3 runned! ([ 3.2]Sec.) -> 3_due[55820]
[53227]           [03:04:299]                     => test2 runned! ([ 3.3]Sec.) -> 2_due[55847]
[55419] [03:06:491]                               => test1 runned! ([ 2.9]Sec.) -> 1_due[58347]

[55428] test1 counted[62] times run in [62] events --> EQUAL
[55429] test2 counted[57] times run in [62] events --> ? (5 off)
[55429] test3 counted[54] times run in [62] events --> ? (8 off)

[55434] timerTest1: Time past/left [   87/ 2912]ms  next due after [58340]!
[55441] timerTest2: Time past/left [ 2594/  406]ms  next due after [55840]!
[55448] timerTest3: Time past/left [ 2628/  372]ms  next due after [55820]!
[55455] timerTest5: Time past/left [    6/    5]sec next due after [61340]!


[55461] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[60148] startHolding: Time left [  84251]ms, [   84]sec, [ 1]min.
[60149] timerTest1: Time past/left [ 3000/    0]ms  next due after [60140]!
[60150] timerTest2: Time past/left [ 3000/    0]ms  next due after [60150]!
[60157] timerTest3: Time past/left [ 3000/    0]ms  next due after [60150]!
[60164] timerTest5: Time past/left [   10/    1]sec next due after [61340]!


[60509] [03:11:581]                               => test1 runned! ([ 5.1]Sec.) -> 1_due[61347]
[60518]           [03:11:591]                     => test2 runned! ([ 7.3]Sec.) -> 2_due[61847]
[60528]                     [03:11:600]           => test3 runned! ([ 7.7]Sec.) -> 3_due[63528]
[61404] [03:12:476]                               => test1 runned! ([ 0.9]Sec.) -> 1_due[64347]
[61413]                               [03:12:485] => test5 runned! ([12.0]Sec.) -> 5_due[ 7811]
[62102]           [03:13:174]                     => test2 runned! ([ 1.6]Sec.) -> 2_due[64847]
[63649]                     [03:14:721]           => test3 runned! ([ 3.1]Sec.) -> 3_due[ 1113]
[64644] [03:15:716]                               => test1 runned! ([ 3.2]Sec.) -> 1_due[ 1811]
[64895]           [03:15:967]                     => test2 runned! ([ 2.8]Sec.) -> 2_due[ 2311]

[  176] ***** timer16Bit() has rolled-over! *****

[  176] timerTest1: Time past/left [ 1365/ 1635]ms  next due after [ 1810]!
[  177] timerTest2: Time past/left [  866/ 2134]ms  next due after [ 2310]!
[  183] timerTest3: Time past/left [ 2070/  930]ms  next due after [ 1110]!
[  190] timerTest5: Time past/left [    4/    7]sec next due after [ 7810]!

[ 1300]                     [03:17:908]           => test3 runned! ([ 3.2]Sec.) -> 3_due[ 4300]
[ 2091] [03:18:699]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 4811]
[ 2368]           [03:18:976]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5311]
[ 4498]                     [03:21:106]           => test3 runned! ([ 3.2]Sec.) -> 3_due[ 7498]
[ 4970] [03:21:578]                               => test1 runned! ([ 2.9]Sec.) -> 1_due[ 7811]
[ 5384]           [03:21:992]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8311]
[ 7671]                     [03:24:279]           => test3 runned! ([ 3.2]Sec.) -> 3_due[10671]
[ 7964] [03:24:572]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[10811]
[ 7974]                               [03:24:582] => test5 runned! ([12.1]Sec.) -> 5_due[19811]
[ 8331]           [03:24:939]                     => test2 runned! ([ 2.9]Sec.) -> 2_due[11311]
[10762]                     [03:27:370]           => test3 runned! ([ 3.1]Sec.) -> 3_due[13762]
[10982] [03:27:590]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[13811]
[11373]           [03:27:981]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[14311]
[13950] [03:30:558]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[16811]
[13959]                     [03:30:567]           => test3 runned! ([ 3.2]Sec.) -> 3_due[16959]
[14513]           [03:31:121]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[17311]
[16908] [03:33:516]                               => test1 runned! ([ 2.9]Sec.) -> 1_due[19811]
[17220]                     [03:33:828]           => test3 runned! ([ 3.3]Sec.) -> 3_due[20220]
[17516]           [03:34:124]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[20311]
[19844] [03:36:452]                               => test1 runned! ([ 2.9]Sec.) -> 1_due[22811]
[19853]                               [03:36:461] => test5 runned! ([11.9]Sec.) -> 5_due[31811]
[20472]           [03:37:080]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[23311]
[20482]                     [03:37:090]           => test3 runned! ([ 3.3]Sec.) -> 3_due[23481]
[23048] [03:39:656]                               => test1 runned! ([ 3.2]Sec.) -> 1_due[25811]
[23424]           [03:40:032]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[26311]
[23543]                     [03:40:151]           => test3 runned! ([ 3.1]Sec.) -> 3_due[26543]
[26009] [03:42:617]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[28811]
[26572]           [03:43:180]                     => test2 runned! ([ 3.1]Sec.) -> 2_due[29311]
[26582]                     [03:43:190]           => test3 runned! ([ 3.0]Sec.) -> 3_due[29582]
[28865] [03:45:473]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[31811]
[29379]           [03:45:987]                     => test2 runned! ([ 2.8]Sec.) -> 2_due[32311]
[29678]                     [03:46:286]           => test3 runned! ([ 3.1]Sec.) -> 3_due[32678]
[31998] [03:48:606]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[34811]
[32007]                               [03:48:615] => test5 runned! ([12.2]Sec.) -> 5_due[43811]
[32595]           [03:49:203]                     => test2 runned! ([ 3.2]Sec.) -> 2_due[35311]
[33060]                     [03:49:668]           => test3 runned! ([ 3.4]Sec.) -> 3_due[36060]
[35115] [03:51:723]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[37811]
[35448]           [03:52:056]                     => test2 runned! ([ 2.9]Sec.) -> 2_due[38311]

[35869] test1 counted[77] times run in [77] events --> EQUAL
[35869] test2 counted[72] times run in [77] events --> ? (5 off)
[35869] test3 counted[67] times run in [77] events --> ? (10 off)

[35875] timerTest1: Time past/left [ 1064/ 1936]ms  next due after [37810]!
[35882] timerTest2: Time past/left [  571/ 2429]ms  next due after [38310]!
[35888] timerTest3: Time past/left [ 2828/  172]ms  next due after [36060]!
[35895] timerTest5: Time past/left [    4/    7]sec next due after [43810]!


[35902] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[40475] startHolding: Time left [  38388]ms, [   38]sec, [ 0]min.
[40476] timerTest1: Time past/left [ 3000/    0]ms  next due after [40470]!
[40477] timerTest2: Time past/left [ 3000/    0]ms  next due after [40470]!
[40484] timerTest3: Time past/left [ 3000/    0]ms  next due after [40480]!
[40491] timerTest5: Time past/left [    8/    3]sec next due after [43810]!


[40547] [03:57:155]                               => test1 runned! ([ 5.4]Sec.) -> 1_due[40811]
[40556]           [03:57:164]                     => test2 runned! ([ 5.1]Sec.) -> 2_due[41311]
[40565]                     [03:57:173]           => test3 runned! ([ 7.5]Sec.) -> 3_due[43565]
[41204] [03:57:812]                               => test1 runned! ([ 0.6]Sec.) -> 1_due[43811]
[41636]           [03:58:244]                     => test2 runned! ([ 1.1]Sec.) -> 2_due[44311]
[43822] [04:00:430]                               => test1 runned! ([ 2.6]Sec.) -> 1_due[46811]
[43832]                     [04:00:440]           => test3 runned! ([ 3.3]Sec.) -> 3_due[46832]
[43841]                               [04:00:449] => test5 runned! ([11.8]Sec.) -> 5_due[55811]
[44323]           [04:00:931]                     => test2 runned! ([ 2.7]Sec.) -> 2_due[47311]
[47257] [04:03:865]                               => test1 runned! ([ 3.4]Sec.) -> 1_due[49811]
[47267]                     [04:03:875]           => test3 runned! ([ 3.4]Sec.) -> 3_due[50267]
[47326]           [04:03:934]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[50311]
[50154] [04:06:762]                               => test1 runned! ([ 2.9]Sec.) -> 1_due[52811]
[50565]           [04:07:173]                     => test2 runned! ([ 3.2]Sec.) -> 2_due[53311]
[50574]                     [04:07:182]           => test3 runned! ([ 3.3]Sec.) -> 3_due[53574]
[53136] [04:09:744]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[55811]
[53520]           [04:10:128]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[56311]
[53837]                     [04:10:445]           => test3 runned! ([ 3.3]Sec.) -> 3_due[56837]
[55932] [04:12:540]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[58811]
[55941]                               [04:12:549] => test5 runned! ([12.1]Sec.) -> 5_due[ 2275]
[56495]           [04:13:103]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[59311]
[56998]                     [04:13:606]           => test3 runned! ([ 3.2]Sec.) -> 3_due[59997]
[58946] [04:15:554]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[61811]
[59332]           [04:15:940]                     => test2 runned! ([ 2.8]Sec.) -> 2_due[62311]
[60251]                     [04:16:859]           => test3 runned! ([ 3.3]Sec.) -> 3_due[63251]
[62049] [04:18:657]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[64811]
[62381]           [04:18:989]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[65311]
[63326]                     [04:19:934]           => test3 runned! ([ 3.1]Sec.) -> 3_due[  790]
[64858] [04:21:466]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[ 2275]
[65419]           [04:22:027]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2775]

[  348] ***** timer16Bit() has rolled-over! *****

[  348] timerTest1: Time past/left [ 1073/ 1927]ms  next due after [ 2270]!
[  349] timerTest2: Time past/left [  574/ 2426]ms  next due after [ 2770]!
[  355] timerTest3: Time past/left [ 2565/  435]ms  next due after [  790]!
[  362] timerTest5: Time past/left [   10/    1]sec next due after [ 2270]!

[  991]                     [04:23:135]           => test3 runned! ([ 3.2]Sec.) -> 3_due[ 3991]
[ 2544] [04:24:688]                               => test1 runned! ([ 3.2]Sec.) -> 1_due[ 5275]
[ 2554]                               [04:24:698] => test5 runned! ([12.1]Sec.) -> 5_due[14275]
[ 2800]           [04:24:944]                     => test2 runned! ([ 2.9]Sec.) -> 2_due[ 5775]
[ 4025]                     [04:26:169]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 7025]
[ 5357] [04:27:501]                               => test1 runned! ([ 2.8]Sec.) -> 1_due[ 8275]
[ 5967]           [04:28:111]                     => test2 runned! ([ 3.2]Sec.) -> 2_due[ 8775]
[ 7299]                     [04:29:443]           => test3 runned! ([ 3.3]Sec.) -> 3_due[10299]
[ 8339] [04:30:483]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[11275]
[ 8986]           [04:31:130]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[11775]
[10310]                     [04:32:454]           => test3 runned! ([ 3.0]Sec.) -> 3_due[13310]
[11469] [04:33:613]                               => test1 runned! ([ 3.1]Sec.) -> 1_due[14275]
[11932]           [04:34:076]                     => test2 runned! ([ 2.9]Sec.) -> 2_due[14775]
[13567]                     [04:35:711]           => test3 runned! ([ 3.3]Sec.) -> 3_due[16567]
[13576] timerTest1: Time past/left [ 2301/  699]ms  next due after [14270]!
[13577] timerTest2: Time past/left [ 1802/ 1198]ms  next due after [14770]!
[13579] timerTest3: Time past/left [   12/ 2988]ms  next due after [16560]!
[13586] timerTest5: Time past/left [   11/    0]sec next due after [14270]!


[13592] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
*********************** using NO random delays! from here on *********************

[28598] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[28601] timerTest1: Time past/left [ 3000/    0]ms  next due after [28600]!
[28608] timerTest2: Time past/left [ 3000/    0]ms  next due after [28600]!
[28615] timerTest3: Time past/left [ 3000/    0]ms  next due after [28610]!
[28621] timerTest5: Time past/left [   12/    0]sec next due after [28620]!


[28628] [04:50:772]                               => test1 runned! ([17.1]Sec.) -> 1_due[17275]
[28648]           [04:50:792]                     => test2 runned! ([16.7]Sec.) -> 2_due[29775]
[28657]                     [04:50:801]           => test3 runned! ([15.1]Sec.) -> 3_due[31657]
[28666]                               [04:50:810] => test5 runned! ([26.1]Sec.) -> 5_due[26275]
[28675] [04:50:819]                               => test1 runned! ([ 0.0]Sec.) -> 1_due[20275]
[28685]                               [04:50:829] => test5 runned! ([ 0.0]Sec.) -> 5_due[38275]
[28694] [04:50:838]                               => test1 runned! ([ 0.0]Sec.) -> 1_due[23275]
[28703] [04:50:847]                               => test1 runned! ([ 0.0]Sec.) -> 1_due[26275]
[28712] [04:50:856]                               => test1 runned! ([ 0.0]Sec.) -> 1_due[29275]
[29275] [04:51:419]                               => test1 runned! ([ 0.6]Sec.) -> 1_due[32275]
[29775]           [04:51:919]                     => test2 runned! ([ 1.1]Sec.) -> 2_due[32775]
[31657]                     [04:53:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[34657]
[32275] [04:54:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[35275]
[32775]           [04:54:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[35775]
[34657]                     [04:56:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[37657]
[35275] [04:57:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[38275]
[35775]           [04:57:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[38775]
[37657]                     [04:59:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[40657]
[38275]                               [05:00:419] => test5 runned! ([ 9.6]Sec.) -> 5_due[50275]
[38284] [05:00:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[41275]
[38775]           [05:00:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[41775]
[40657]                     [05:02:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[43657]
[41275] [05:03:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[44275]
[41775]           [05:03:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[44775]
[43657]                     [05:05:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[46657]
[44275] [05:06:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[47275]
[44775]           [05:06:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[47775]
[46657]                     [05:08:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[49657]
[47275] [05:09:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[50275]
[47775]           [05:09:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[50775]
[49657]                     [05:11:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[52657]
[50275]                               [05:12:419] => test5 runned! ([12.0]Sec.) -> 5_due[62275]
[50284] [05:12:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[53275]
[50775]           [05:12:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[53775]
[52657]                     [05:14:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[55657]
[53275] [05:15:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[56275]
[53775]           [05:15:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[56775]
[55657]                     [05:17:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[58657]
[56275] [05:18:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[59275]
[56775]           [05:18:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[59775]
[58657]                     [05:20:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[61657]
[59275] [05:21:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[62275]
[59775]           [05:21:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[62775]
[61657]                     [05:23:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[64657]
[62275]                               [05:24:419] => test5 runned! ([12.0]Sec.) -> 5_due[ 8739]
[62284] [05:24:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[65275]
[62775]           [05:24:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[  239]
[64657]                     [05:26:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 2121]
[65275] [05:27:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2739]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [  261/ 2739]ms  next due after [ 2730]!
[    0] timerTest2: Time past/left [ 2761/  239]ms  next due after [  230]!
[    7] timerTest3: Time past/left [  886/ 2114]ms  next due after [ 2120]!
[   13] timerTest5: Time past/left [    3/    8]sec next due after [ 8730]!

[  239]           [05:27:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3239]
[ 2121]                     [05:29:801]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5121]
[ 2739] [05:30:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 5739]
[ 3239]           [05:30:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 6239]

[ 4092] test1 counted[110] times run in [110] events --> EQUAL
[ 4093] test2 counted[101] times run in [110] events --> ? (9 off)
[ 4093] test3 counted[94] times run in [110] events --> ? (16 off)

[ 4099] timerTest1: Time past/left [ 1360/ 1640]ms  next due after [ 5730]!
[ 4106] timerTest2: Time past/left [  867/ 2133]ms  next due after [ 6230]!
[ 4112] timerTest3: Time past/left [ 1991/ 1009]ms  next due after [ 5120]!
[ 4119] timerTest5: Time past/left [    7/    4]sec next due after [ 8730]!


[ 4126] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[ 8131] startHolding: Time left [  84961]ms, [   84]sec, [ 1]min.
[ 8131] timerTest1: Time past/left [ 3000/    0]ms  next due after [ 8130]!
[ 8133] timerTest2: Time past/left [ 3000/    0]ms  next due after [ 8130]!
[ 8140] timerTest3: Time past/left [ 3000/    0]ms  next due after [ 8140]!
[ 8147] timerTest5: Time past/left [   11/    0]sec next due after [ 8730]!


[ 8154] [05:35:834]                               => test1 runned! ([ 5.4]Sec.) -> 1_due[ 8739]
[ 8173]           [05:35:853]                     => test2 runned! ([ 4.9]Sec.) -> 2_due[ 9239]
[ 8182]                     [05:35:862]           => test3 runned! ([ 6.1]Sec.) -> 3_due[11182]
[ 8739]                               [05:36:419] => test5 runned! ([12.0]Sec.) -> 5_due[20739]
[ 8748] [05:36:428]                               => test1 runned! ([ 0.6]Sec.) -> 1_due[11739]
[ 9239]           [05:36:919]                     => test2 runned! ([ 1.1]Sec.) -> 2_due[12239]
[11182]                     [05:38:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[14182]
[11739] [05:39:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[14739]
[12239]           [05:39:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[15239]
[14182]                     [05:41:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[17182]
[14739] [05:42:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[17739]
[15239]           [05:42:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[18239]
[17182]                     [05:44:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[20182]
[17739] [05:45:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[20739]
[18239]           [05:45:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[21239]
[20182]                     [05:47:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[23182]
[20739]                               [05:48:419] => test5 runned! ([12.0]Sec.) -> 5_due[32739]
[20748] [05:48:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[23739]
[21239]           [05:48:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[24239]
[23182]                     [05:50:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[26182]
[23739] [05:51:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[26739]
[24239]           [05:51:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[27239]
[26182]                     [05:53:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[29182]
[26739] [05:54:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[29739]
[27239]           [05:54:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[30239]
[29182]                     [05:56:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[32182]
[29739] [05:57:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[32739]
[30239]           [05:57:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[33239]
[32182]                     [05:59:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[35182]
[32739] [06:00:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[35739]
[32748]                               [06:00:428] => test5 runned! ([12.0]Sec.) -> 5_due[44739]
[33239]           [06:00:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[36239]
[35182]                     [06:02:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[38182]
[35739] [06:03:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[38739]
[36239]           [06:03:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[39239]
[38182]                     [06:05:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[41182]
[38739] [06:06:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[41739]
[39239]           [06:06:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[42239]
[41182]                     [06:08:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[44182]
[41739] [06:09:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[44739]
[42239]           [06:09:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[45239]
[44182]                     [06:11:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[47182]
[44739] [06:12:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[47739]
[44748]                               [06:12:428] => test5 runned! ([12.0]Sec.) -> 5_due[56739]
[45239]           [06:12:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[48239]
[47182]                     [06:14:862]           => test3 runned! ([ 3.0]Sec.) -> 3_due[50182]
[47739] [06:15:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[50739]
[48239]           [06:15:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[51239]

[49154] test1 counted[125] times run in [125] events --> EQUAL
[49154] test2 counted[116] times run in [125] events --> ? (9 off)
[49154] test3 counted[108] times run in [125] events --> ? (17 off)

[49160] timerTest1: Time past/left [ 1421/ 1579]ms  next due after [50730]!
[49167] timerTest2: Time past/left [  928/ 2072]ms  next due after [51230]!
[49174] timerTest3: Time past/left [ 1992/ 1008]ms  next due after [50180]!
[49180] timerTest5: Time past/left [    4/    7]sec next due after [56730]!


[49187] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[53191] startHolding: Time left [  39900]ms, [   39]sec, [ 0]min.
[53192] timerTest1: Time past/left [ 3000/    0]ms  next due after [53190]!
[53194] timerTest2: Time past/left [ 3000/    0]ms  next due after [53190]!
[53201] timerTest3: Time past/left [ 3000/    0]ms  next due after [53200]!
[53207] timerTest5: Time past/left [    8/    3]sec next due after [56730]!


[53216] [06:20:896]                               => test1 runned! ([ 5.5]Sec.) -> 1_due[53739]
[53234]           [06:20:914]                     => test2 runned! ([ 5.0]Sec.) -> 2_due[54239]
[53243]                     [06:20:923]           => test3 runned! ([ 6.1]Sec.) -> 3_due[56243]
[53739] [06:21:419]                               => test1 runned! ([ 0.5]Sec.) -> 1_due[56739]
[54239]           [06:21:919]                     => test2 runned! ([ 1.0]Sec.) -> 2_due[57239]
[56243]                     [06:23:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[59243]
[56739]                               [06:24:419] => test5 runned! ([12.0]Sec.) -> 5_due[ 3203]
[56748] [06:24:428]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[59739]
[57239]           [06:24:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[60239]
[59243]                     [06:26:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[62243]
[59739] [06:27:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[62739]
[60239]           [06:27:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[63239]
[62243]                     [06:29:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[65243]
[62739] [06:30:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[  203]
[63239]           [06:30:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[  703]
[65243]                     [06:32:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 2707]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 2797/  203]ms  next due after [  200]!
[    0] timerTest2: Time past/left [ 2297/  703]ms  next due after [  700]!
[    7] timerTest3: Time past/left [  300/ 2700]ms  next due after [ 2700]!
[   13] timerTest5: Time past/left [    8/    3]sec next due after [ 3200]!

[  203] [06:33:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3203]
[  703]           [06:33:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3703]
[ 2707]                     [06:35:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5707]
[ 3203] [06:36:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6203]
[ 3212]                               [06:36:428] => test5 runned! ([12.0]Sec.) -> 5_due[15203]
[ 3703]           [06:36:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 6703]
[ 5707]                     [06:38:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8707]
[ 6203] [06:39:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9203]
[ 6703]           [06:39:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[ 9703]
[ 8707]                     [06:41:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[11707]
[ 9203] [06:42:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[12203]
[ 9703]           [06:42:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[12703]
[11707]                     [06:44:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[14707]
[12203] [06:45:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[15203]
[12703]           [06:45:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[15703]
[14707]                     [06:47:923]           => test3 runned! ([ 3.0]Sec.) -> 3_due[17707]
[15203] [06:48:419]                               => test1 runned! ([ 3.0]Sec.) -> 1_due[18203]
[15212]                               [06:48:428] => test5 runned! ([12.0]Sec.) -> 5_due[27203]
[15703]           [06:48:919]                     => test2 runned! ([ 3.0]Sec.) -> 2_due[18703]
