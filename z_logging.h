

//---TEST 1-------------------------------------------------------------------
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
// d1<int>d2<int>d3<int>d4 ..............d5<->d6<int>d7<int>d8<int>d9 enz
//
Test2 vuurt direct na een lange pauze (omdat de processor met andere, 
tijdrovende, zaken bezig was) maar herstelt daarna de interval.
In het figuurtje hierboven "mist" test2 t5 en t6, maar de eerstvolgende
keer dat het due-event gevuurd wordt (d5) wordt d6 pas gevuurd nadat
de interval is verstreken.

```

Stresstest for safeTimersFastRO.h macro's 

Due_Test1[3000]ms, Due_Test2[3000]ms, Due_Test3[8000]ms, Due_Test4[12000]

[01068] StartTime[00:01:068]

[39053] [31:45:421]                               => test1 runned! (after [ 3.0] seconds)
[40022]           [31:46:390]                     => test2 runned! (after [ 3.0] seconds)
[40885]                     [31:47:253]           => test3 runned! (after [ 8.0] seconds)
[42053] [31:48:421]                               => test1 runned! (after [ 3.0] seconds)
[42701]                               [31:49:069] => test4 runned! (after [12.0] seconds)
[43022]           [31:49:390]                     => test2 runned! (after [ 3.0] seconds)
[45053] [31:51:421]                               => test1 runned! (after [ 3.0] seconds)
[46022]           [31:52:390]                     => test2 runned! (after [ 3.0] seconds)
[48053] [31:54:421]                               => test1 runned! (after [ 3.0] seconds)
[48885]                     [31:55:253]           => test3 runned! (after [ 8.0] seconds)
[49022]           [31:55:390]                     => test2 runned! (after [ 3.0] seconds)
[51053] [31:57:421]                               => test1 runned! (after [ 3.0] seconds)
[52022]           [31:58:390]                     => test2 runned! (after [ 3.0] seconds)
[54053] [32:00:421]                               => test1 runned! (after [ 3.0] seconds)
[54701]                               [32:01:069] => test4 runned! (after [12.0] seconds)
[55022]           [32:01:390]                     => test2 runned! (after [ 3.0] seconds)
[56885]                     [32:03:253]           => test3 runned! (after [ 8.0] seconds)
[57053] [32:03:421]                               => test1 runned! (after [ 3.0] seconds)
[58022]           [32:04:390]                     => test2 runned! (after [ 3.0] seconds)
[60053] [32:06:421]                               => test1 runned! (after [ 3.0] seconds)
[61022]           [32:07:390]                     => test2 runned! (after [ 3.0] seconds)

[63014] test1 counted[9042] times fired in [9042] events --> OK!
[63015] test2 counted[7586] times fired in [9042] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
[ 1601] after180Secs: Time left [  31496]ms, [   31]sec, [ 0]min.
[ 1602] timerTest1: Time past/left [ 1549/ 1451]ms  next due after [ 3050]!
[ 1603] timerTest2: Time past/left [  581/ 2419]ms  next due after [ 4020]!
[ 1610] timerTest3: Time past/left [  725/ 7275]ms  next due after [ 8880]!
[ 1616] timerTest4: Time past/left [    6/    5]sec next due after [ 6700]!


[ 1623] hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue with Random Delays!
[16626] delay41Secs: Time left [   4887]ms, [    4]sec., [ 0]min.
[16627] timerTest1: Time past/left [ 1574/ 1426]ms  next due after [18050]!
[16630] timerTest2: Time past/left [  608/ 2392]ms  next due after [19020]!
[16637] timerTest3: Time past/left [ 7752/  248]ms  next due after [16880]!
[16644] timerTest4: Time past/left [    9/    2]sec next due after [18700]!

[16687] [32:28:591]                               => test1 runned! (after [22.2] seconds)
[16688]           [32:28:592]                     => test2 runned! (after [21.2] seconds)
[16692]                     [32:28:596]           => test3 runned! (after [25.3] seconds)
[16700]                               [32:28:604] => test4 runned! (after [27.5] seconds)
[16709] [32:28:613]                               => test1 runned! (after [ 0.0] seconds)
[16716]                               [32:28:620] => test4 runned! (after [ 0.0] seconds)
[16924] [32:28:828]                               => test1 runned! (after [ 0.2] seconds)
[16951] [32:28:855]                               => test1 runned! (after [ 0.0] seconds)
[17254] [32:29:158]                               => test1 runned! (after [ 0.3] seconds)
[17547] [32:29:451]                               => test1 runned! (after [ 0.3] seconds)
[18035] [32:29:939]                               => test1 runned! (after [ 0.5] seconds)
[18617] [32:30:521]                               => test1 runned! (after [ 0.6] seconds)
[19818]           [32:31:722]                     => test2 runned! (after [ 3.1] seconds)
[21553] [32:33:457]                               => test1 runned! (after [ 2.9] seconds)
[22914]           [32:34:818]                     => test2 runned! (after [ 3.1] seconds)
[24590] [32:36:494]                               => test1 runned! (after [ 3.0] seconds)
[24845]                     [32:36:749]           => test3 runned! (after [ 8.2] seconds)
[25336]                               [32:37:240] => test4 runned! (after [ 8.6] seconds)
[26147]           [32:38:051]                     => test2 runned! (after [ 3.2] seconds)
[27577] [32:39:481]                               => test1 runned! (after [ 3.0] seconds)
[29514]           [32:41:418]                     => test2 runned! (after [ 3.4] seconds)
[30829] [32:42:733]                               => test1 runned! (after [ 3.3] seconds)
[32750]           [32:44:654]                     => test2 runned! (after [ 3.2] seconds)
[32867]                     [32:44:771]           => test3 runned! (after [ 8.0] seconds)
[33656] [32:45:560]                               => test1 runned! (after [ 2.8] seconds)
[35836]           [32:47:740]                     => test2 runned! (after [ 3.1] seconds)
[36545] [32:48:449]                               => test1 runned! (after [ 2.9] seconds)
[37308]                               [32:49:212] => test4 runned! (after [12.0] seconds)
[39000]           [32:50:904]                     => test2 runned! (after [ 3.2] seconds)
[39882] [32:51:786]                               => test1 runned! (after [ 3.3] seconds)
[40984]                     [32:52:888]           => test3 runned! (after [ 8.1] seconds)
[42125]           [32:54:029]                     => test2 runned! (after [ 3.1] seconds)
[42772] [32:54:676]                               => test1 runned! (after [ 2.9] seconds)
[45508]           [32:57:412]                     => test2 runned! (after [ 3.4] seconds)
[45539] [32:57:443]                               => test1 runned! (after [ 2.8] seconds)
[48555] [33:00:459]                               => test1 runned! (after [ 3.0] seconds)
[48556]           [33:00:460]                     => test2 runned! (after [ 3.0] seconds)
[49235]                     [33:01:139]           => test3 runned! (after [ 8.3] seconds)
[49236]                               [33:01:140] => test4 runned! (after [11.9] seconds)
[51706] [33:03:610]                               => test1 runned! (after [ 3.2] seconds)
[51707]           [33:03:611]                     => test2 runned! (after [ 3.2] seconds)
[54699] [33:06:603]                               => test1 runned! (after [ 3.0] seconds)
[55089]           [33:06:993]                     => test2 runned! (after [ 3.4] seconds)
[57288]                     [33:09:192]           => test3 runned! (after [ 8.1] seconds)
[57756] [33:09:660]                               => test1 runned! (after [ 3.1] seconds)

[57757] test1 counted[9063] times fired in [9062] events --> ERROR! (-1 off)
[57761] test2 counted[7599] times fired in [9062] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
[62296] after180Secs: Time left [   5308]ms, [    5]sec, [ 0]min.
[62297] timerTest1: Time past/left [ 2245/  755]ms  next due after [63050]!
[62298] timerTest2: Time past/left [ 1674/ 1326]ms  next due after [63620]!
[62305] timerTest3: Time past/left [ 5017/ 2983]ms  next due after [65280]!
[62312] timerTest4: Time past/left [    7/    4]sec next due after [66700]!

[62684] [33:14:588]                               => test1 runned! (after [ 4.9] seconds)
[62685]           [33:14:589]                     => test2 runned! (after [ 7.6] seconds)
[62689]                               [33:14:593] => test4 runned! (after [13.5] seconds)
[63571] [33:15:475]                               => test1 runned! (after [ 0.9] seconds)
[65311]                     [33:17:215]           => test3 runned! (after [ 8.0] seconds)

[   96] ***** timer16Bit() has rollover! *****
[   96] timerTest1: Time past/left [ 2115/  885]ms  next due after [  980]!
[   97] timerTest2: Time past/left [ 2948/   52]ms  next due after [  140]!
[  103] timerTest3: Time past/left [  328/ 7672]ms  next due after [ 7770]!
[  109] timerTest4: Time past/left [    4/    7]sec next due after [ 7620]!

[  494]           [33:17:934]                     => test2 runned! (after [ 3.3] seconds)
[ 1254] [33:18:694]                               => test1 runned! (after [ 3.2] seconds)
[ 3553]           [33:20:993]                     => test2 runned! (after [ 3.1] seconds)
```
