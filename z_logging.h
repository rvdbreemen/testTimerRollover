=======================
Date: 23-02-2020  13:10
=======================


Stresstest for safeTimersFastRO.h macro's 

---TYPE 0------CATCH_UP_MISSED_TICKS---------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor   >            |      |
 |             |     <     bussy     >            |      |
 d1<int>d2<int>d3<...................>d4.d5.d6.d7.d8<int>d9<int>d10 enz
                                      d3 --> d4 == longet then interval
                                      d4>d5>d6>d7<.>d8 < less then interval, then sync
                                      d8 --> d9 (etc) == interval  

---TYPE 1------SKIP_MISSED_TICKS_WITH_SYNC--------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor   >     |      |
 |             |     <     bussy     >     |      |
 d1<int>d2<int>d3<...................>d4<.>d5<int>d6<int>d7<int>d8 enz
                                      d3 --> d4 == longer then interval
                      t4     t5     t6 missed
                                      d4 -> d5 < less then interval, then sync
                                      d5 --> d6 (etc) == interval    

---TYPE 2------SKIP_MISSED_TICKS------------------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor    >           \      \
 |             |     <     bussy      >             \      \
 d1<int>d2<int>d3<....................>d4<int>d5<int>d6<int>d7<int>d8 enz
                                      d3 --> d4 == longer then interval
                      t4     t5     t6 missed
                                      d4 --> d5 (etc) == interval (shifted from time-ticks)

---TYPE 3------SKIP_MISSED_TICKS_WITH_SYNC2-------------------------------------
 t1     t2     t3     t4     t5     t6     t7     t8     t9     t10    t11    t12
 |             |     <   processor    >    |      |
 |             |     <     bussy      >    |      |
 d1<int>d2<int>d3<........................>d4<int>d5<int>d6<int>d7 enz
                      t4     t5     t6 missed
                                     d3 --> d4 == very long
                                     d4 --> d5 (etc) == interval


Due_Test1[ 3000]ms Due_Test2[ 3000]ms Due_Test3[ 3000]ms Due_Test4[ 9000]ms Due_Test5[12000]ms 
testType1[1]       testType2[2]       testType3[0]       testType4[0]       testType5[0]       

[  508] StartTime[00:00:508]
[ 3508] [00:03:508]                                         => test1 runned! ([ 3.5]Sec.) -> 1_due[ 6508]
[ 4008]           [00:04:008]                               => test2 runned! ([ 4.0]Sec.) -> 2_due[ 7008]
[ 4508]                     [00:04:508]                     => test3 runned! ([ 4.5]Sec.) -> 3_due[ 7508]
[ 5901] timerTest5: Time past/left [ 5393/ 6607]ms next due after [12500]!
[ 6508] [00:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9508]
[ 7008]           [00:07:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[10008]
[ 7508]                     [00:07:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[10508]
[ 9508] [00:09:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[12508]
[10008]           [00:10:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[13008]
[10508]                     [00:10:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[13508]
[10901] timerTest5: Time past/left [10393/ 1607]ms next due after [12500]!
[11728]                               [00:11:728]           => test4 runned! ([11.7]Sec.) -> 4_due[20728]
[12508] [00:12:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15508]
[12518]                                         [00:12:518] => test5 runned! ([12.5]Sec.) -> 5_due[24518]
[13008]           [00:13:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[16008]
[13508]                     [00:13:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[16508]
[15508] [00:15:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[18508]
[15901] timerTest5: Time past/left [ 3383/ 8617]ms next due after [24510]!
[16008]           [00:16:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[19008]
[16508]                     [00:16:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[19508]
[18508] [00:18:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[21508]
[19008]           [00:19:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[22008]
[19508]                     [00:19:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[22508]
[20728]                               [00:20:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[29728]
[20901] timerTest5: Time past/left [ 8383/ 3617]ms next due after [24510]!
[21508] [00:21:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[24508]
[22008]           [00:22:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[25008]
[22508]                     [00:22:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[25508]
[24508] [00:24:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[27508]
[24518]                                         [00:24:518] => test5 runned! ([12.0]Sec.) -> 5_due[36518]
[25008]           [00:25:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[28008]
[25508]                     [00:25:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[28508]
[25902] timerTest5: Time past/left [ 1385/10615]ms next due after [36510]!
[27508] [00:27:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[30508]
[28008]           [00:28:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[31008]
[28508]                     [00:28:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[31508]
[29728]                               [00:29:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[38728]
[30508] [00:30:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[33508]
[30902] timerTest5: Time past/left [ 6385/ 5615]ms next due after [36510]!
[31008]           [00:31:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[34008]
[31508]                     [00:31:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[34508]
[33508] [00:33:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[36508]
[34008]           [00:34:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[37008]
[34508]                     [00:34:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[37508]
[35902] timerTest5: Time past/left [11384/  616]ms next due after [36510]!
[36508] [00:36:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[39508]
[36518]                                         [00:36:518] => test5 runned! ([12.0]Sec.) -> 5_due[48518]
[37008]           [00:37:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[40008]
[37508]                     [00:37:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[40508]
[38728]                               [00:38:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[47728]
[39508] [00:39:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[42508]
[40008]           [00:40:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[43008]
[40508]                     [00:40:508]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[43508]
[40902] timerTest5: Time past/left [ 4384/ 7616]ms next due after [48510]!

[41508] test1 counted[13] times run in [13] events --> EQUAL
[41508] test2 counted[13] times run in [13] events --> EQUAL
[41509] test3 counted[13] times run in [13] events --> EQUAL
[41513] test4 counted[4] times run in [4] events --> EQUAL
[41518] test5 counted[3] times run in [3] events --> EQUAL

[41524] timerTest1: Time past/left [ 2016/  984]ms  next due after [42500]!
[41531] timerTest2: Time past/left [ 1523/ 1477]ms  next due after [43000]!
[41537] timerTest3: Time past/left [ 1029/ 1971]ms  next due after [43500]!
[41544] timerTest4: Time past/left [ 2816/ 6184]ms  next due after [47720]!
[41551] timerTest5: Time past/left [    5/    6]sec next due after [48510]!

[41557] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[45562] startHolding: Time left [  84946]ms, [   84]sec, [ 1]min.
[45562] timerTest1: Time past/left [ 3000/    0]ms  next due after [45560]!
[45564] timerTest2: Time past/left [ 3000/    0]ms  next due after [45560]!
[45571] timerTest3: Time past/left [ 3000/    0]ms  next due after [45570]!
[45578] timerTest4: Time past/left [ 6850/ 2150]ms  next due after [47720]!
[45584] timerTest5: Time past/left [    9/    2]sec next due after [48510]!


[45592] [00:45:592]                                         => test1 runned! ([ 6.1]Sec.) -> 1_due[45508]
[45612]           [00:45:612]                               => test2 runned! ([ 5.6]Sec.) -> 2_due[46008]
[45622]                     [00:45:622]                     => test3 runned! ([ 5.1]Sec.) -> 3_due[48622]
[45632] [00:45:632]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[48508]
[45902] timerTest5: Time past/left [ 9384/ 2616]ms next due after [48510]!
[46008]           [00:46:008]                               => test2 runned! ([ 0.4]Sec.) -> 2_due[49008]
[47728]                               [00:47:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[56728]
[48508] [00:48:508]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[51508]
[48518]                                         [00:48:518] => test5 runned! ([12.0]Sec.) -> 5_due[60518]
[48622]                     [00:48:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[51622]
[49008]           [00:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[52008]
[50902] timerTest5: Time past/left [ 2384/ 9616]ms next due after [60510]!
[51508] [00:51:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[54508]
[51622]                     [00:51:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[54622]
[52008]           [00:52:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[55008]
[54508] [00:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[57508]
[54622]                     [00:54:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[57622]
[55008]           [00:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[58008]
[55902] timerTest5: Time past/left [ 7384/ 4616]ms next due after [60510]!
[56728]                               [00:56:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[  192]
[57508] [00:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[60508]
[57622]                     [00:57:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[60622]
[58008]           [00:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[61008]
[60508] [01:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[63508]
[60518]                                         [01:00:518] => test5 runned! ([12.0]Sec.) -> 5_due[ 6982]
[60622]                     [01:00:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[63622]
[60902] timerTest5: Time past/left [  385/11615]ms next due after [72510]!
[61008]           [01:01:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[64008]
[63508] [01:03:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[  972]
[63622]                     [01:03:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 1086]
[64008]           [01:04:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1472]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 2028/  972]ms  next due after [  970]!
[    0] timerTest2: Time past/left [ 1528/ 1472]ms  next due after [ 1470]!
[    7] timerTest3: Time past/left [ 1921/ 1079]ms  next due after [ 1080]!
[   13] timerTest4: Time past/left [ 8821/  179]ms  next due after [  190]!
[   20] timerTest5: Time past/left [    5/    6]sec next due after [ 6980]!

[  192]                               [01:05:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 9192]
[  366] timerTest5: Time past/left [ 5384/ 6616]ms next due after [ 6980]!
[  972] [01:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3972]
[ 1086]                     [01:06:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 4086]
[ 1472]           [01:07:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4472]
[ 3972] [01:09:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6972]
[ 4086]                     [01:09:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 7086]
[ 4472]           [01:10:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 7472]
[ 5366] timerTest5: Time past/left [10384/ 1616]ms next due after [ 6980]!
[ 6972] [01:12:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9972]
[ 6982]                                         [01:12:518] => test5 runned! ([12.0]Sec.) -> 5_due[18982]
[ 7086]                     [01:12:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[10086]
[ 7472]           [01:13:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[10472]
[ 9192]                               [01:14:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[18192]
[ 9972] [01:15:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[12972]
[10086]                     [01:15:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[13086]
[10366] timerTest5: Time past/left [ 3384/ 8616]ms next due after [18980]!
[10472]           [01:16:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[13472]
[12972] [01:18:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15972]
[13086]                     [01:18:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[16086]
[13472]           [01:19:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[16472]
[15366] timerTest5: Time past/left [ 8384/ 3616]ms next due after [18980]!
[15972] [01:21:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[18972]
[16086]                     [01:21:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[19086]
[16472]           [01:22:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[19472]
[18192]                               [01:23:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[27192]
[18972] [01:24:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[21972]
[18982]                                         [01:24:518] => test5 runned! ([12.0]Sec.) -> 5_due[30982]
[19086]                     [01:24:622]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[22086]
[19472]           [01:25:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[22472]
[20366] timerTest5: Time past/left [ 1384/10616]ms next due after [30980]!

[21055] test1 counted[28] times run in [28] events --> EQUAL
[21056] test2 counted[28] times run in [28] events --> EQUAL
[21056] test3 counted[27] times run in [28] events --> ? (1 off)
[21061] test4 counted[9] times run in [9] events --> EQUAL
[21066] test5 counted[7] times run in [7] events --> EQUAL

[21072] timerTest1: Time past/left [ 2100/  900]ms  next due after [21970]!
[21078] timerTest2: Time past/left [ 1606/ 1394]ms  next due after [22470]!
[21085] timerTest3: Time past/left [ 1999/ 1001]ms  next due after [22080]!
[21092] timerTest4: Time past/left [ 2900/ 6100]ms  next due after [27190]!
[21098] timerTest5: Time past/left [    2/    9]sec next due after [30980]!

[21105] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[25109] startHolding: Time left [  39862]ms, [   39]sec, [ 0]min.
[25110] timerTest1: Time past/left [ 3000/    0]ms  next due after [25110]!
[25112] timerTest2: Time past/left [ 3000/    0]ms  next due after [25110]!
[25118] timerTest3: Time past/left [ 3000/    0]ms  next due after [25110]!
[25125] timerTest4: Time past/left [ 6933/ 2067]ms  next due after [27190]!
[25132] timerTest5: Time past/left [    6/    5]sec next due after [30980]!


[25139] [01:30:675]                                         => test1 runned! ([ 6.2]Sec.) -> 1_due[24972]
[25159]           [01:30:695]                               => test2 runned! ([ 5.7]Sec.) -> 2_due[25472]
[25169]                     [01:30:705]                     => test3 runned! ([ 6.1]Sec.) -> 3_due[28169]
[25179] [01:30:715]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[27972]
[25366] timerTest5: Time past/left [ 6384/ 5616]ms next due after [30980]!
[25472]           [01:31:008]                               => test2 runned! ([ 0.3]Sec.) -> 2_due[28472]
[27192]                               [01:32:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[36192]
[27972] [01:33:508]                                         => test1 runned! ([ 2.8]Sec.) -> 1_due[30972]
[28169]                     [01:33:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[31169]
[28472]           [01:34:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[31472]
[30366] timerTest5: Time past/left [11384/  616]ms next due after [30980]!
[30972] [01:36:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[33972]
[30982]                                         [01:36:518] => test5 runned! ([12.0]Sec.) -> 5_due[42982]
[31169]                     [01:36:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[34169]
[31472]           [01:37:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[34472]
[33972] [01:39:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[36972]
[34169]                     [01:39:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[37169]
[34472]           [01:40:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[37472]
[35366] timerTest5: Time past/left [ 4384/ 7616]ms next due after [42980]!
[36192]                               [01:41:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[45192]
[36972] [01:42:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[39972]
[37169]                     [01:42:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[40169]
[37472]           [01:43:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[40472]
[39972] [01:45:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[42972]
[40169]                     [01:45:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[43169]
[40366] timerTest5: Time past/left [ 9384/ 2616]ms next due after [42980]!
[40472]           [01:46:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[43472]
[42972] [01:48:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[45972]
[42982]                                         [01:48:518] => test5 runned! ([12.0]Sec.) -> 5_due[54982]
[43169]                     [01:48:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[46169]
[43472]           [01:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[46472]
[45192]                               [01:50:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[54192]
[45366] timerTest5: Time past/left [ 2384/ 9616]ms next due after [54980]!
[45972] [01:51:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[48972]
[46169]                     [01:51:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[49169]
[46472]           [01:52:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[49472]
[48972] [01:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[51972]
[49169]                     [01:54:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[52169]
[49472]           [01:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[52472]
[50366] timerTest5: Time past/left [ 7384/ 4616]ms next due after [54980]!
[51972] [01:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[54972]
[52169]                     [01:57:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[55169]
[52472]           [01:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[55472]
[54192]                               [01:59:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[63192]
[54972] [02:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[57972]
[54982]                                         [02:00:518] => test5 runned! ([12.0]Sec.) -> 5_due[ 1446]
[55169]                     [02:00:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[58169]
[55366] timerTest5: Time past/left [  385/11615]ms next due after [66980]!
[55472]           [02:01:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[58472]
[57972] [02:03:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[60972]
[58169]                     [02:03:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[61169]
[58472]           [02:04:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[61472]
[60366] timerTest5: Time past/left [ 5385/ 6615]ms next due after [66980]!
[60972] [02:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[63972]
[61169]                     [02:06:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[64169]
[61472]           [02:07:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[64472]
[63192]                               [02:08:728]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 6656]
[63972] [02:09:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1436]
[64169]                     [02:09:705]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 1633]
[64472]           [02:10:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1936]

[64972] timerTest1: Time past/left [ 1001/ 1999]ms  next due after [66970]!
[64973] timerTest2: Time past/left [  502/ 2498]ms  next due after [67470]!
[64975] timerTest3: Time past/left [  807/ 2193]ms  next due after [67160]!
[64982] timerTest4: Time past/left [ 1791/ 7209]ms  next due after [72190]!
[64988] timerTest5: Time past/left [   10/    1]sec next due after [66980]!


[64995] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
************************* using Random Delays from here on ***********************

[14464] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[14468] timerTest1: Time past/left [ 3000/    0]ms  next due after [14460]!
[14474] timerTest2: Time past/left [ 3000/    0]ms  next due after [14470]!
[14481] timerTest3: Time past/left [ 3000/    0]ms  next due after [14480]!
[14488] timerTest4: Time past/left [ 9000/    0]ms  next due after [14480]!
[14494] timerTest5: Time past/left [   12/    0]sec next due after [14490]!


[14682] timerTest5: Time past/left [12000/    0]ms next due after [14680]!
[14682] [02:25:754]                                         => test1 runned! ([16.2]Sec.) -> 1_due[ 4436]
[14698]           [02:25:770]                               => test2 runned! ([15.8]Sec.) -> 2_due[16936]
[14708]                     [02:25:780]                     => test3 runned! ([16.1]Sec.) -> 3_due[17708]
[14718]                               [02:25:790]           => test4 runned! ([17.1]Sec.) -> 4_due[23718]
[14728]                                         [02:25:800] => test5 runned! ([25.3]Sec.) -> 5_due[26728]
[14813] [02:25:885]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[ 7436]
[14968] [02:26:040]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[10436]
[15085] [02:26:157]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[13436]
[15320] [02:26:392]                                         => test1 runned! ([ 0.2]Sec.) -> 1_due[16436]
[16448] [02:27:520]                                         => test1 runned! ([ 1.1]Sec.) -> 1_due[19436]
[17180]           [02:28:252]                               => test2 runned! ([ 2.5]Sec.) -> 2_due[19936]
[17763]                     [02:28:835]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[20763]
[19438] [02:30:510]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[22436]
[19740] timerTest5: Time past/left [ 5012/ 6988]ms next due after [26720]!
[20074]           [02:31:146]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[22936]
[20877]                     [02:31:949]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[23877]
[22497] [02:33:569]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[25436]
[23124]           [02:34:196]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[25936]
[23771]                               [02:34:843]           => test4 runned! ([ 9.1]Sec.) -> 4_due[32771]
[23918]                     [02:34:990]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[26918]
[24757] timerTest5: Time past/left [10029/ 1971]ms next due after [26720]!
[25508] [02:36:580]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[28436]
[25967]           [02:37:039]                               => test2 runned! ([ 2.8]Sec.) -> 2_due[28936]
[26831]                                         [02:37:903] => test5 runned! ([12.1]Sec.) -> 5_due[38831]
[27006]                     [02:38:078]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[30006]
[28535] [02:39:607]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[31436]
[28941]           [02:40:013]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[31936]
[29812] timerTest5: Time past/left [ 2982/ 9018]ms next due after [38830]!
[30030]                     [02:41:102]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[33030]
[31439] [02:42:511]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[34436]
[31970]           [02:43:042]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[34936]
[32797]                               [02:43:869]           => test4 runned! ([ 9.0]Sec.) -> 4_due[41797]
[33067]                     [02:44:139]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[36067]
[34514] [02:45:586]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[37436]
[34939] timerTest5: Time past/left [ 8108/ 3892]ms next due after [38830]!
[34940]           [02:46:012]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[37936]
[36151]                     [02:47:223]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[39151]
[37658] [02:48:730]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[40436]
[38026]           [02:49:098]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[40936]
[38938]                                         [02:50:010] => test5 runned! ([12.1]Sec.) -> 5_due[50938]
[39270]                     [02:50:342]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[42270]
[39968] timerTest5: Time past/left [ 1030/10970]ms next due after [50930]!
[40557] [02:51:629]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[43436]
[41091]           [02:52:163]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[43936]
[41836]                               [02:52:908]           => test4 runned! ([ 9.0]Sec.) -> 4_due[50835]
[42384]                     [02:53:456]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[45384]
[43581] [02:54:653]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[46436]
[44010]           [02:55:082]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[46936]
[45066] timerTest5: Time past/left [ 6128/ 5872]ms next due after [50930]!
[45527]                     [02:56:599]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[48527]
[46531] [02:57:603]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[49436]
[47002]           [02:58:074]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[49936]
[48581]                     [02:59:653]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[51581]
[49561] [03:00:633]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[52436]
[49954]           [03:01:026]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[52936]
[50097] timerTest5: Time past/left [11159/  841]ms next due after [50930]!
[50874]                               [03:01:946]           => test4 runned! ([ 9.0]Sec.) -> 4_due[59874]
[51010]                                         [03:02:082] => test5 runned! ([12.1]Sec.) -> 5_due[63010]
[51652]                     [03:02:724]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[54652]
[52454] [03:03:526]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[55436]
[53081]           [03:04:153]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[55936]
[54791]                     [03:05:863]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[57791]
[55139] timerTest5: Time past/left [ 4129/ 7871]ms next due after [63010]!
[55472] [03:06:544]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[58436]

[55696] test1 counted[62] times run in [62] events --> EQUAL
[55696] test2 counted[57] times run in [62] events --> ? (5 off)
[55697] test3 counted[55] times run in [62] events --> ? (7 off)
[55702] test4 counted[19] times run in [20] events --> ? (1 off)
[55708] test5 counted[14] times run in [15] events --> ? (1 off)

[55714] timerTest1: Time past/left [  278/ 2722]ms  next due after [58430]!
[55720] timerTest2: Time past/left [ 2784/  216]ms  next due after [55930]!
[55727] timerTest3: Time past/left [  936/ 2064]ms  next due after [57790]!
[55734] timerTest4: Time past/left [ 4860/ 4140]ms  next due after [59870]!
[55740] timerTest5: Time past/left [    4/    7]sec next due after [63010]!

[55747] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[60349] startHolding: Time left [  84152]ms, [   84]sec, [ 1]min.
[60350] timerTest1: Time past/left [ 3000/    0]ms  next due after [60350]!
[60351] timerTest2: Time past/left [ 3000/    0]ms  next due after [60350]!
[60358] timerTest3: Time past/left [ 3000/    0]ms  next due after [60350]!
[60365] timerTest4: Time past/left [ 9000/    0]ms  next due after [60360]!
[60371] timerTest5: Time past/left [    9/    2]sec next due after [63010]!


[60513] timerTest5: Time past/left [ 9503/ 2497]ms next due after [63010]!
[60514] [03:11:586]                                         => test1 runned! ([ 5.0]Sec.) -> 1_due[61436]
[60530]           [03:11:602]                               => test2 runned! ([ 7.4]Sec.) -> 2_due[61936]
[60540]                     [03:11:612]                     => test3 runned! ([ 5.7]Sec.) -> 3_due[63540]
[60550]                               [03:11:622]           => test4 runned! ([ 9.7]Sec.) -> 4_due[ 4014]
[61459] [03:12:531]                                         => test1 runned! ([ 0.9]Sec.) -> 1_due[64436]
[62020]           [03:13:092]                               => test2 runned! ([ 1.5]Sec.) -> 2_due[64936]
[63034]                                         [03:14:106] => test5 runned! ([12.0]Sec.) -> 5_due[ 9498]
[63584]                     [03:14:656]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 1048]
[64509] [03:15:581]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1900]
[64951]           [03:16:023]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[ 2400]
[65532] timerTest5: Time past/left [ 2499/ 9501]ms next due after [75030]!

[  114] ***** timer16Bit() has rolled-over! *****

[  114] timerTest1: Time past/left [ 1214/ 1786]ms  next due after [ 1900]!
[  115] timerTest2: Time past/left [  715/ 2285]ms  next due after [ 2400]!
[  121] timerTest3: Time past/left [ 2073/  927]ms  next due after [ 1040]!
[  128] timerTest4: Time past/left [ 5114/ 3886]ms  next due after [ 4010]!
[  134] timerTest5: Time past/left [    2/    9]sec next due after [ 9490]!

[ 1137]                     [03:17:745]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 4137]
[ 2117] [03:18:725]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[ 4900]
[ 2408]           [03:19:016]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5400]
[ 4108]                               [03:20:716]           => test4 runned! ([ 9.1]Sec.) -> 4_due[13108]
[ 4208]                     [03:20:816]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 7208]
[ 4908] [03:21:516]                                         => test1 runned! ([ 2.8]Sec.) -> 1_due[ 7900]
[ 5092] timerTest5: Time past/left [ 7594/ 4406]ms next due after [ 9490]!
[ 5490]           [03:22:098]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[ 8400]
[ 7238]                     [03:23:847]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[10238]
[ 8044] [03:24:652]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[10900]
[ 8510]           [03:25:118]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[11400]
[ 9507]                                         [03:26:115] => test5 runned! ([12.0]Sec.) -> 5_due[21507]
[10206] timerTest5: Time past/left [  699/11301]ms next due after [21500]!
[10383]                     [03:26:991]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[13383]
[11122] [03:27:730]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[13900]
[11413]           [03:28:021]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[14400]
[13217]                               [03:29:825]           => test4 runned! ([ 9.1]Sec.) -> 4_due[22217]
[13387]                     [03:29:995]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[16387]
[13936] [03:30:544]                                         => test1 runned! ([ 2.8]Sec.) -> 1_due[16900]
[14467]           [03:31:075]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[17400]
[15319] timerTest5: Time past/left [ 5812/ 6188]ms next due after [21500]!
[16428]                     [03:33:036]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[19428]
[16937] [03:33:545]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[19900]
[17518]           [03:34:126]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[20400]
[19435]                     [03:36:043]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[22435]
[19937] [03:36:545]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[22900]
[20355] timerTest5: Time past/left [10848/ 1152]ms next due after [21500]!
[20430]           [03:37:038]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[23400]
[21714]                                         [03:38:322] => test5 runned! ([12.2]Sec.) -> 5_due[33714]
[22415]                               [03:39:023]           => test4 runned! ([ 9.2]Sec.) -> 4_due[31415]
[22485]                     [03:39:093]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[25485]
[22908] [03:39:516]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[25900]
[23429]           [03:40:037]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[26400]
[25372] timerTest5: Time past/left [ 3659/ 8341]ms next due after [33710]!
[25571]                     [03:42:179]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[28571]
[25931] [03:42:539]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[28900]
[26438]           [03:43:046]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[29400]
[28727]                     [03:45:335]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[31727]
[28960] [03:45:568]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[31900]
[29446]           [03:46:054]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[32400]
[30389] timerTest5: Time past/left [ 8676/ 3324]ms next due after [33710]!
[31532]                               [03:48:140]           => test4 runned! ([ 9.1]Sec.) -> 4_due[40532]
[31840]                     [03:48:448]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[34840]
[31918] [03:48:526]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[34900]
[32493]           [03:49:101]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[35400]
[33827]                                         [03:50:435] => test5 runned! ([12.1]Sec.) -> 5_due[45827]
[35003] [03:51:611]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[37900]
[35013]                     [03:51:621]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[38013]
[35420] timerTest5: Time past/left [ 1593/10407]ms next due after [45820]!
[35420]           [03:52:028]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[38400]

[35957] test1 counted[77] times run in [77] events --> EQUAL
[35957] test2 counted[72] times run in [77] events --> ? (5 off)
[35957] test3 counted[69] times run in [77] events --> ? (8 off)
[35963] test4 counted[24] times run in [25] events --> ? (1 off)
[35968] test5 counted[18] times run in [19] events --> ? (1 off)

[35974] timerTest1: Time past/left [ 1074/ 1926]ms  next due after [37900]!
[35981] timerTest2: Time past/left [  581/ 2419]ms  next due after [38400]!
[35988] timerTest3: Time past/left [  975/ 2025]ms  next due after [38010]!
[35994] timerTest4: Time past/left [ 4462/ 4538]ms  next due after [40530]!
[36001] timerTest5: Time past/left [    2/    9]sec next due after [45820]!

[36008] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[40142] startHolding: Time left [  38823]ms, [   38]sec, [ 0]min.
[40142] timerTest1: Time past/left [ 3000/    0]ms  next due after [40140]!
[40144] timerTest2: Time past/left [ 3000/    0]ms  next due after [40140]!
[40150] timerTest3: Time past/left [ 3000/    0]ms  next due after [40150]!
[40157] timerTest4: Time past/left [ 8625/  375]ms  next due after [40530]!
[40164] timerTest5: Time past/left [    6/    5]sec next due after [45820]!


[40174] [03:56:782]                                         => test1 runned! ([ 5.2]Sec.) -> 1_due[40900]
[40191]           [03:56:799]                               => test2 runned! ([ 4.8]Sec.) -> 2_due[41400]
[40202]                     [03:56:810]                     => test3 runned! ([ 5.2]Sec.) -> 3_due[43202]
[40574] timerTest5: Time past/left [ 6747/ 5253]ms next due after [45820]!
[40575]                               [03:57:183]           => test4 runned! ([ 9.0]Sec.) -> 4_due[49575]
[40930] [03:57:538]                                         => test1 runned! ([ 0.7]Sec.) -> 1_due[43900]
[41452]           [03:58:061]                               => test2 runned! ([ 1.3]Sec.) -> 2_due[44400]
[43240]                     [03:59:848]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[46240]
[43919] [04:00:527]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[46900]
[44409]           [04:01:017]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[47400]
[45590] timerTest5: Time past/left [11763/  237]ms next due after [45820]!
[45973]                                         [04:02:581] => test5 runned! ([12.1]Sec.) -> 5_due[57973]
[46384]                     [04:02:992]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[49384]
[46913] [04:03:521]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[49900]
[47576]           [04:04:184]                               => test2 runned! ([ 3.2]Sec.) -> 2_due[50400]
[49385]                     [04:05:993]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[52385]
[49810]                               [04:06:418]           => test4 runned! ([ 9.2]Sec.) -> 4_due[58810]
[49969] [04:06:577]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[52900]
[50429]           [04:07:037]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[53400]
[50683] timerTest5: Time past/left [ 4710/ 7290]ms next due after [57970]!
[52594]                     [04:09:202]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[55594]
[53060] [04:09:668]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[55900]
[53586]           [04:10:194]                               => test2 runned! ([ 3.2]Sec.) -> 2_due[56400]
[55633]                     [04:12:241]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[58633]
[55801] timerTest5: Time past/left [ 9828/ 2172]ms next due after [57970]!
[55954] [04:12:562]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[58900]
[56511]           [04:13:119]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[59400]
[58012]                                         [04:14:620] => test5 runned! ([12.0]Sec.) -> 5_due[ 4476]
[58779]                     [04:15:387]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[61779]
[58820]                               [04:15:428]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 2284]
[59026] [04:15:634]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[61900]
[59498]           [04:16:106]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[62400]
[60817] timerTest5: Time past/left [ 2806/ 9194]ms next due after [70010]!
[61904] [04:18:512]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[64900]
[61914]                     [04:18:522]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[64914]
[62610]           [04:19:218]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[65400]
[64928] [04:21:536]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2364]
[64939]                     [04:21:547]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 2403]
[65407]           [04:22:015]                               => test2 runned! ([ 2.8]Sec.) -> 2_due[ 2864]

[  168] ***** timer16Bit() has rolled-over! *****

[  169] timerTest1: Time past/left [  805/ 2195]ms  next due after [ 2360]!
[  169] timerTest2: Time past/left [  305/ 2695]ms  next due after [ 2860]!
[  176] timerTest3: Time past/left [  773/ 2227]ms  next due after [ 2400]!
[  182] timerTest4: Time past/left [ 6898/ 2102]ms  next due after [ 2280]!
[  189] timerTest5: Time past/left [    7/    4]sec next due after [ 4470]!

[  298] timerTest5: Time past/left [ 7822/ 4178]ms next due after [ 4470]!
[ 2337]                               [04:24:481]           => test4 runned! ([ 9.1]Sec.) -> 4_due[11337]
[ 2478] [04:24:622]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[ 5364]
[ 2488]                     [04:24:632]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 5487]
[ 2981]           [04:25:125]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[ 5864]
[ 4520]                                         [04:26:664] => test5 runned! ([12.0]Sec.) -> 5_due[16520]
[ 5381] timerTest5: Time past/left [  861/11139]ms next due after [16520]!
[ 5382] [04:27:526]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[ 8364]
[ 5559]                     [04:27:703]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 8559]
[ 5989]           [04:28:134]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8864]
[ 8430] [04:30:574]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[11364]
[ 8672]                     [04:30:816]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[11672]
[ 8888]           [04:31:032]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[11864]
[10386] timerTest5: Time past/left [ 5866/ 6134]ms next due after [16520]!
[11422] [04:33:566]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[14364]
[11433]                               [04:33:577]           => test4 runned! ([ 9.1]Sec.) -> 4_due[20433]
[11765]                     [04:33:909]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[14765]
[11979]           [04:34:123]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[14864]

[13478] timerTest1: Time past/left [ 2114/  886]ms  next due after [14360]!
[13478] timerTest2: Time past/left [ 1614/ 1386]ms  next due after [14860]!
[13480] timerTest3: Time past/left [ 1715/ 1285]ms  next due after [14760]!
[13487] timerTest4: Time past/left [ 2054/ 6946]ms  next due after [20430]!
[13494] timerTest5: Time past/left [    8/    3]sec next due after [16520]!


[13501] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
*********************** using NO random delays! from here on *********************

[28506] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[28509] timerTest1: Time past/left [ 3000/    0]ms  next due after [28500]!
[28516] timerTest2: Time past/left [ 3000/    0]ms  next due after [28510]!
[28523] timerTest3: Time past/left [ 3000/    0]ms  next due after [28520]!
[28529] timerTest4: Time past/left [ 9000/    0]ms  next due after [28520]!
[28536] timerTest5: Time past/left [   12/    0]sec next due after [28530]!


[28543] timerTest5: Time past/left [12000/    0]ms next due after [28540]!
[28550] [04:50:694]                                         => test1 runned! ([17.1]Sec.) -> 1_due[17364]
[28570]           [04:50:714]                               => test2 runned! ([16.6]Sec.) -> 2_due[29864]
[28580]                     [04:50:724]                     => test3 runned! ([16.8]Sec.) -> 3_due[31580]
[28590]                               [04:50:734]           => test4 runned! ([17.2]Sec.) -> 4_due[37590]
[28600]                                         [04:50:744] => test5 runned! ([24.1]Sec.) -> 5_due[40600]
[28610] [04:50:754]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[20364]
[28620] [04:50:764]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[23364]
[28630] [04:50:774]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[26364]
[28640] [04:50:784]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[29364]
[29364] [04:51:508]                                         => test1 runned! ([ 0.7]Sec.) -> 1_due[32364]
[29864]           [04:52:008]                               => test2 runned! ([ 1.3]Sec.) -> 2_due[32864]
[31580]                     [04:53:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[34580]
[32364] [04:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[35364]
[32864]           [04:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[35864]
[33543] timerTest5: Time past/left [ 4943/ 7057]ms next due after [40600]!
[34580]                     [04:56:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[37580]
[35364] [04:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[38364]
[35864]           [04:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[38864]
[37580]                     [04:59:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[40580]
[37590]                               [04:59:734]           => test4 runned! ([ 9.0]Sec.) -> 4_due[46590]
[38364] [05:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[41364]
[38543] timerTest5: Time past/left [ 9943/ 2057]ms next due after [40600]!
[38864]           [05:01:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[41864]
[40580]                     [05:02:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[43580]
[40600]                                         [05:02:744] => test5 runned! ([12.0]Sec.) -> 5_due[52600]
[41364] [05:03:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[44364]
[41864]           [05:04:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[44864]
[43543] timerTest5: Time past/left [ 2943/ 9057]ms next due after [52600]!
[43580]                     [05:05:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[46580]
[44364] [05:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[47364]
[44864]           [05:07:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[47864]
[46580]                     [05:08:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[49580]
[46590]                               [05:08:734]           => test4 runned! ([ 9.0]Sec.) -> 4_due[55590]
[47364] [05:09:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[50364]
[47864]           [05:10:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[50864]
[48543] timerTest5: Time past/left [ 7943/ 4057]ms next due after [52600]!
[49580]                     [05:11:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[52580]
[50364] [05:12:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[53364]
[50864]           [05:13:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[53864]
[52580]                     [05:14:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[55580]
[52600]                                         [05:14:744] => test5 runned! ([12.0]Sec.) -> 5_due[64600]
[53364] [05:15:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[56364]
[53543] timerTest5: Time past/left [  943/11057]ms next due after [64600]!
[53864]           [05:16:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[56864]
[55580]                     [05:17:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[58580]
[55590]                               [05:17:734]           => test4 runned! ([ 9.0]Sec.) -> 4_due[64590]
[56364] [05:18:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[59364]
[56864]           [05:19:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[59864]
[58543] timerTest5: Time past/left [ 5943/ 6057]ms next due after [64600]!
[58580]                     [05:20:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[61580]
[59364] [05:21:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[62364]
[59864]           [05:22:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[62864]
[61580]                     [05:23:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[64580]
[62364] [05:24:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[65364]
[62864]           [05:25:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[  328]
[63543] timerTest5: Time past/left [10943/ 1057]ms next due after [64600]!
[64580]                     [05:26:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 2044]
[64590]                               [05:26:734]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 8054]
[64600]                                         [05:26:744] => test5 runned! ([12.0]Sec.) -> 5_due[11064]
[65364] [05:27:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2828]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [  172/ 2828]ms  next due after [ 2820]!
[    0] timerTest2: Time past/left [ 2672/  328]ms  next due after [  320]!
[    7] timerTest3: Time past/left [  963/ 2037]ms  next due after [ 2040]!
[   13] timerTest4: Time past/left [  959/ 8041]ms  next due after [ 8050]!
[   20] timerTest5: Time past/left [    0/   11]sec next due after [11060]!

[  328]           [05:28:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3328]
[ 2044]                     [05:29:724]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5044]
[ 2828] [05:30:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 5828]
[ 3007] timerTest5: Time past/left [ 3943/ 8057]ms next due after [11060]!
[ 3328]           [05:31:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 6328]

[ 4007] test1 counted[110] times run in [110] events --> EQUAL
[ 4007] test2 counted[101] times run in [110] events --> ? (9 off)
[ 4008] test3 counted[96] times run in [110] events --> ? (14 off)
[ 4013] test4 counted[34] times run in [36] events --> ? (2 off)
[ 4019] test5 counted[25] times run in [27] events --> ? (2 off)

[ 4025] timerTest1: Time past/left [ 1197/ 1803]ms  next due after [ 5820]!
[ 4032] timerTest2: Time past/left [  704/ 2296]ms  next due after [ 6320]!
[ 4038] timerTest3: Time past/left [ 1994/ 1006]ms  next due after [ 5040]!
[ 4045] timerTest4: Time past/left [ 4991/ 4009]ms  next due after [ 8050]!
[ 4052] timerTest5: Time past/left [    4/    7]sec next due after [11060]!

[ 4059] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[ 8064] startHolding: Time left [  84943]ms, [   84]sec, [ 1]min.
[ 8064] timerTest1: Time past/left [ 3000/    0]ms  next due after [ 8060]!
[ 8066] timerTest2: Time past/left [ 3000/    0]ms  next due after [ 8060]!
[ 8073] timerTest3: Time past/left [ 3000/    0]ms  next due after [ 8070]!
[ 8080] timerTest4: Time past/left [ 9000/    0]ms  next due after [ 8080]!
[ 8086] timerTest5: Time past/left [    9/    2]sec next due after [11060]!


[ 8094] timerTest5: Time past/left [ 9030/ 2970]ms next due after [11060]!
[ 8100] [05:35:780]                                         => test1 runned! ([ 5.3]Sec.) -> 1_due[ 8828]
[ 8121]           [05:35:801]                               => test2 runned! ([ 4.8]Sec.) -> 2_due[ 9328]
[ 8131]                     [05:35:811]                     => test3 runned! ([ 6.1]Sec.) -> 3_due[11130]
[ 8140]                               [05:35:821]           => test4 runned! ([ 9.1]Sec.) -> 4_due[17140]
[ 8828] [05:36:508]                                         => test1 runned! ([ 0.7]Sec.) -> 1_due[11828]
[ 9328]           [05:37:008]                               => test2 runned! ([ 1.2]Sec.) -> 2_due[12328]
[11064]                                         [05:38:744] => test5 runned! ([12.0]Sec.) -> 5_due[23064]
[11130]                     [05:38:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[14130]
[11828] [05:39:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[14828]
[12328]           [05:40:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[15328]
[13094] timerTest5: Time past/left [ 2030/ 9970]ms next due after [23060]!
[14130]                     [05:41:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[17130]
[14828] [05:42:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[17828]
[15328]           [05:43:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[18328]
[17130]                     [05:44:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[20130]
[17140]                               [05:44:820]           => test4 runned! ([ 9.0]Sec.) -> 4_due[26140]
[17828] [05:45:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[20828]
[18094] timerTest5: Time past/left [ 7030/ 4970]ms next due after [23060]!
[18328]           [05:46:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[21328]
[20130]                     [05:47:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[23130]
[20828] [05:48:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[23828]
[21328]           [05:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[24328]
[23064]                                         [05:50:744] => test5 runned! ([12.0]Sec.) -> 5_due[35064]
[23094] timerTest5: Time past/left [   31/11969]ms next due after [35060]!
[23130]                     [05:50:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[26130]
[23828] [05:51:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[26828]
[24328]           [05:52:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[27328]
[26130]                     [05:53:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[29130]
[26140]                               [05:53:820]           => test4 runned! ([ 9.0]Sec.) -> 4_due[35140]
[26828] [05:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[29828]
[27328]           [05:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[30328]
[28094] timerTest5: Time past/left [ 5031/ 6969]ms next due after [35060]!
[29130]                     [05:56:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[32130]
[29828] [05:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[32828]
[30328]           [05:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[33328]
[32130]                     [05:59:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[35130]
[32828] [06:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[35828]
[33094] timerTest5: Time past/left [10030/ 1970]ms next due after [35060]!
[33328]           [06:01:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[36328]
[35064]                                         [06:02:744] => test5 runned! ([12.0]Sec.) -> 5_due[47064]
[35130]                     [06:02:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[38130]
[35140]                               [06:02:820]           => test4 runned! ([ 9.0]Sec.) -> 4_due[44140]
[35828] [06:03:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[38828]
[36328]           [06:04:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[39328]
[38094] timerTest5: Time past/left [ 3030/ 8970]ms next due after [47060]!
[38130]                     [06:05:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[41130]
[38828] [06:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[41828]
[39328]           [06:07:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[42328]
[41130]                     [06:08:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[44130]
[41828] [06:09:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[44828]
[42328]           [06:10:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[45328]
[43094] timerTest5: Time past/left [ 8030/ 3970]ms next due after [47060]!
[44130]                     [06:11:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[47130]
[44140]                               [06:11:820]           => test4 runned! ([ 9.0]Sec.) -> 4_due[53140]
[44828] [06:12:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[47828]
[45328]           [06:13:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[48328]
[47064]                                         [06:14:744] => test5 runned! ([12.0]Sec.) -> 5_due[59064]
[47130]                     [06:14:810]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[50130]
[47828] [06:15:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[50828]
[48094] timerTest5: Time past/left [ 1030/10970]ms next due after [59060]!
[48328]           [06:16:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[51328]

[49094] test1 counted[125] times run in [125] events --> EQUAL
[49094] test2 counted[116] times run in [125] events --> ? (9 off)
[49094] test3 counted[110] times run in [125] events --> ? (15 off)
[49100] test4 counted[39] times run in [41] events --> ? (2 off)
[49106] test5 counted[29] times run in [31] events --> ? (2 off)

[49112] timerTest1: Time past/left [ 1284/ 1716]ms  next due after [50820]!
[49118] timerTest2: Time past/left [  790/ 2210]ms  next due after [51320]!
[49125] timerTest3: Time past/left [ 1995/ 1005]ms  next due after [50130]!
[49132] timerTest4: Time past/left [ 4992/ 4008]ms  next due after [53140]!
[49138] timerTest5: Time past/left [    2/    9]sec next due after [59060]!

[49145] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[53150] startHolding: Time left [  39857]ms, [   39]sec, [ 0]min.
[53150] timerTest1: Time past/left [ 3000/    0]ms  next due after [53150]!
[53153] timerTest2: Time past/left [ 3000/    0]ms  next due after [53150]!
[53159] timerTest3: Time past/left [ 3000/    0]ms  next due after [53150]!
[53166] timerTest4: Time past/left [ 9000/    0]ms  next due after [53160]!
[53173] timerTest5: Time past/left [    6/    5]sec next due after [59060]!


[53180] timerTest5: Time past/left [ 6116/ 5884]ms next due after [59060]!
[53186] [06:20:866]                                         => test1 runned! ([ 5.3]Sec.) -> 1_due[53828]
[53207]           [06:20:887]                               => test2 runned! ([ 4.9]Sec.) -> 2_due[54328]
[53217]                     [06:20:897]                     => test3 runned! ([ 6.1]Sec.) -> 3_due[56217]
[53227]                               [06:20:907]           => test4 runned! ([ 9.1]Sec.) -> 4_due[62227]
[53828] [06:21:508]                                         => test1 runned! ([ 0.6]Sec.) -> 1_due[56828]
[54328]           [06:22:008]                               => test2 runned! ([ 1.1]Sec.) -> 2_due[57328]
[56217]                     [06:23:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[59217]
[56828] [06:24:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[59828]
[57328]           [06:25:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[60328]
[58180] timerTest5: Time past/left [11116/  884]ms next due after [59060]!
[59064]                                         [06:26:744] => test5 runned! ([12.0]Sec.) -> 5_due[ 5528]
[59217]                     [06:26:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[62217]
[59828] [06:27:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[62828]
[60328]           [06:28:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[63328]
[62217]                     [06:29:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[65217]
[62227]                               [06:29:907]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 5691]
[62828] [06:30:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[  292]
[63180] timerTest5: Time past/left [ 4117/ 7883]ms next due after [71060]!
[63328]           [06:31:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[  792]
[65217]                     [06:32:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 2681]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 2708/  292]ms  next due after [  290]!
[    0] timerTest2: Time past/left [ 2208/  792]ms  next due after [  790]!
[    7] timerTest3: Time past/left [  326/ 2674]ms  next due after [ 2680]!
[   13] timerTest4: Time past/left [ 3322/ 5678]ms  next due after [ 5690]!
[   20] timerTest5: Time past/left [    6/    5]sec next due after [ 5520]!

[  292] [06:33:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3292]
[  792]           [06:34:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 3792]
[ 2644] timerTest5: Time past/left [ 9116/ 2884]ms next due after [ 5520]!
[ 2681]                     [06:35:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 5681]
[ 3292] [06:36:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6292]
[ 3792]           [06:37:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 6792]
[ 5528]                                         [06:38:744] => test5 runned! ([12.0]Sec.) -> 5_due[17528]
[ 5681]                     [06:38:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8681]
[ 5691]                               [06:38:907]           => test4 runned! ([ 9.0]Sec.) -> 4_due[14691]
[ 6292] [06:39:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9292]
[ 6792]           [06:40:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 9792]
[ 7644] timerTest5: Time past/left [ 2116/ 9884]ms next due after [17520]!
[ 8681]                     [06:41:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[11681]
[ 9292] [06:42:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[12292]
[ 9792]           [06:43:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[12792]
[11681]                     [06:44:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[14681]
[12292] [06:45:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15292]
[12644] timerTest5: Time past/left [ 7116/ 4884]ms next due after [17520]!
[12792]           [06:46:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[15792]
[14681]                     [06:47:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[17681]
[14691]                               [06:47:907]           => test4 runned! ([ 9.0]Sec.) -> 4_due[23691]
[15292] [06:48:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[18292]
[15792]           [06:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[18792]
[17528]                                         [06:50:744] => test5 runned! ([12.0]Sec.) -> 5_due[29528]
[17644] timerTest5: Time past/left [  116/11884]ms next due after [29520]!
[17681]                     [06:50:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[20681]
[18292] [06:51:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[21292]
[18792]           [06:52:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[21792]
[20681]                     [06:53:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[23681]
[21292] [06:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[24292]
[21792]           [06:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[24792]
[22644] timerTest5: Time past/left [ 5116/ 6884]ms next due after [29520]!
[23681]                     [06:56:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[26681]
[23691]                               [06:56:907]           => test4 runned! ([ 9.0]Sec.) -> 4_due[32691]
[24292] [06:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[27292]
[24792]           [06:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[27792]
[26681]                     [06:59:897]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[29681]
[27292] [07:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[30292]

[27471] timerTest1: Time past/left [  179/ 2821]ms  next due after [30290]!
[27472] timerTest2: Time past/left [ 2680/  320]ms  next due after [27790]!
[27474] timerTest3: Time past/left [  793/ 2207]ms  next due after [29680]!
[27480] timerTest4: Time past/left [ 3789/ 5211]ms  next due after [32690]!
[27487] timerTest5: Time past/left [    9/    2]sec next due after [29520]!


[27494] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
************************* using Random Delays from here on ***********************

[42500] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[42504] timerTest1: Time past/left [ 3000/    0]ms  next due after [42500]!
[42510] timerTest2: Time past/left [ 3000/    0]ms  next due after [42510]!
[42517] timerTest3: Time past/left [ 3000/    0]ms  next due after [42510]!
[42524] timerTest4: Time past/left [ 9000/    0]ms  next due after [42520]!
[42530] timerTest5: Time past/left [   12/    0]sec next due after [42530]!


[42584] timerTest5: Time past/left [12000/    0]ms next due after [42580]!
[42584] [07:15:800]                                         => test1 runned! ([15.3]Sec.) -> 1_due[33292]
[42600]           [07:15:816]                               => test2 runned! ([17.8]Sec.) -> 2_due[42792]
[42610]                     [07:15:826]                     => test3 runned! ([15.9]Sec.) -> 3_due[45610]
[42620]                               [07:15:836]           => test4 runned! ([18.9]Sec.) -> 4_due[51620]
[42630]                                         [07:15:846] => test5 runned! ([25.1]Sec.) -> 5_due[54630]
[42698] [07:15:914]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[36292]
[42724] [07:15:940]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[39292]
[42815] [07:16:031]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[42292]
[42825]           [07:16:041]                               => test2 runned! ([ 0.2]Sec.) -> 2_due[45792]
[42914] [07:16:130]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[45292]
[45479] [07:18:695]                                         => test1 runned! ([ 2.6]Sec.) -> 1_due[48292]
[45704]                     [07:18:920]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[48704]
[45824]           [07:19:040]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[48792]
[47730] timerTest5: Time past/left [ 5100/ 6900]ms next due after [54630]!
[48333] [07:21:549]                                         => test1 runned! ([ 2.8]Sec.) -> 1_due[51292]
[48908]           [07:22:124]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[51792]
[48919]                     [07:22:135]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[51919]
[51344] [07:24:560]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[54292]
[51706]                               [07:24:922]           => test4 runned! ([ 9.1]Sec.) -> 4_due[60706]
[51879]           [07:25:095]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[54792]
[52101]                     [07:25:317]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[55101]
[52788] timerTest5: Time past/left [10158/ 1842]ms next due after [54630]!
[54505] [07:27:721]                                         => test1 runned! ([ 3.2]Sec.) -> 1_due[57292]
[54647]                                         [07:27:863] => test5 runned! ([12.0]Sec.) -> 5_due[ 1111]
[54794]           [07:28:010]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[57792]
[55165]                     [07:28:381]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[58165]
[57360] [07:30:576]                                         => test1 runned! ([ 2.8]Sec.) -> 1_due[60292]
[57813] timerTest5: Time past/left [ 3167/ 8833]ms next due after [66640]!
[57814]           [07:31:030]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[60792]
[58249]                     [07:31:465]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[61249]
[60359] [07:33:575]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[63292]
[60839]           [07:34:055]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[63792]
[60849]                               [07:34:065]           => test4 runned! ([ 9.1]Sec.) -> 4_due[ 4313]
[61273]                     [07:34:489]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[64273]
[62952] timerTest5: Time past/left [ 8306/ 3694]ms next due after [66640]!
[63304] [07:36:520]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[  756]
[63865]           [07:37:081]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 1256]
[64401]                     [07:37:617]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[ 1864]

[   10] ***** timer16Bit() has rolled-over! *****

[   10] timerTest1: Time past/left [ 2254/  746]ms  next due after [  750]!
[   10] timerTest2: Time past/left [ 1754/ 1245]ms  next due after [ 1250]!
[   17] timerTest3: Time past/left [ 1153/ 1847]ms  next due after [ 1860]!
[   24] timerTest4: Time past/left [ 4711/ 4289]ms  next due after [ 4310]!
[   30] timerTest5: Time past/left [   10/    1]sec next due after [ 1110]!

[  799] [07:39:551]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 3756]
[ 1297]           [07:40:049]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 4256]
[ 1308]                                         [07:40:060] => test5 runned! ([12.2]Sec.) -> 5_due[13308]
[ 2051]                     [07:40:803]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[ 5051]
[ 2471] timerTest5: Time past/left [ 1163/10837]ms next due after [13300]!
[ 3852] [07:42:604]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 6756]
[ 4417]           [07:43:169]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[ 7256]
[ 4427]                               [07:43:179]           => test4 runned! ([ 9.1]Sec.) -> 4_due[13427]
[ 5078]                     [07:43:830]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8077]
[ 6866] [07:45:618]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 9756]
[ 7297]           [07:46:049]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[10256]
[ 7636] timerTest5: Time past/left [ 6328/ 5672]ms next due after [13300]!
[ 8115]                     [07:46:867]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[11115]
[ 9789] [07:48:541]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[12756]
[10374]           [07:49:126]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[13256]
[11214]                     [07:49:966]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[14214]
[12701] timerTest5: Time past/left [11393/  607]ms next due after [13300]!
[12840] [07:51:592]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[15756]
[13274]           [07:52:026]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[16256]
[13495]                               [07:52:247]           => test4 runned! ([ 9.1]Sec.) -> 4_due[22495]
[13506]                                         [07:52:258] => test5 runned! ([12.2]Sec.) -> 5_due[25506]
[14337]                     [07:53:089]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[17337]
[15769] [07:54:521]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[18756]
[16403]           [07:55:155]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[19256]
[17360]                     [07:56:112]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[20360]
[17813] timerTest5: Time past/left [ 4307/ 7693]ms next due after [25500]!

[18007] test1 counted[158] times run in [158] events --> EQUAL
[18007] test2 counted[145] times run in [158] events --> ? (13 off)
[18007] test3 counted[138] times run in [158] events --> ? (20 off)
[18013] test4 counted[49] times run in [52] events --> ? (3 off)
[18019] test5 counted[36] times run in [39] events --> ? (3 off)

[18025] timerTest1: Time past/left [ 2269/  731]ms  next due after [18750]!
[18032] timerTest2: Time past/left [ 1776/ 1224]ms  next due after [19250]!
[18038] timerTest3: Time past/left [  678/ 2322]ms  next due after [20360]!
[18045] timerTest4: Time past/left [ 4550/ 4450]ms  next due after [22490]!
[18052] timerTest5: Time past/left [    4/    7]sec next due after [25500]!

[18058] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[22152] startHolding: Time left [  84849]ms, [   84]sec, [ 1]min.
[22153] timerTest1: Time past/left [ 3000/    0]ms  next due after [22150]!
[22154] timerTest2: Time past/left [ 3000/    0]ms  next due after [22150]!
[22161] timerTest3: Time past/left [ 3000/    0]ms  next due after [22160]!
[22167] timerTest4: Time past/left [ 8673/  327]ms  next due after [22490]!
[22174] timerTest5: Time past/left [    8/    3]sec next due after [25500]!


[22325] [08:01:077]                                         => test1 runned! ([ 6.5]Sec.) -> 1_due[21756]
[22336]           [08:01:088]                               => test2 runned! ([ 5.9]Sec.) -> 2_due[25256]
[22346]                     [08:01:098]                     => test3 runned! ([ 5.0]Sec.) -> 3_due[25346]
[22412] [08:01:164]                                         => test1 runned! ([ 0.1]Sec.) -> 1_due[24756]
[22654]                               [08:01:406]           => test4 runned! ([ 9.2]Sec.) -> 4_due[31654]
[22837] timerTest5: Time past/left [ 9331/ 2669]ms next due after [25500]!
[24793] [08:03:545]                                         => test1 runned! ([ 2.4]Sec.) -> 1_due[27756]
[25258]           [08:04:010]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[28256]
[25548]                     [08:04:300]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[28548]
[25558]                                         [08:04:310] => test5 runned! ([12.1]Sec.) -> 5_due[37558]
[27775] [08:06:527]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[30756]
[27971] timerTest5: Time past/left [ 2414/ 9585]ms next due after [37550]!
[28442]           [08:07:194]                               => test2 runned! ([ 3.2]Sec.) -> 2_due[31256]
[28559]                     [08:07:311]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[31559]
[30786] [08:09:538]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[33756]
[31281]           [08:10:033]                               => test2 runned! ([ 2.8]Sec.) -> 2_due[34256]
[31667]                     [08:10:419]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[34667]
[31677]                               [08:10:429]           => test4 runned! ([ 9.0]Sec.) -> 4_due[40677]
[33046] timerTest5: Time past/left [ 7488/ 4512]ms next due after [37550]!
[33920] [08:12:672]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[36756]
[34292]           [08:13:044]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[37256]
[34702]                     [08:13:454]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[37701]
[36880] [08:15:632]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[39756]
[37262]           [08:16:014]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[40256]
[37682]                                         [08:16:434] => test5 runned! ([12.1]Sec.) -> 5_due[49682]
[37850]                     [08:16:602]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[40850]
[38115] timerTest5: Time past/left [  433/11567]ms next due after [49680]!
[39800] [08:18:552]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[42756]
[40299]           [08:19:051]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[43256]
[40736]                               [08:19:488]           => test4 runned! ([ 9.1]Sec.) -> 4_due[49736]
[40931]                     [08:19:683]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[43931]
[42814] [08:21:566]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[45756]
[43184] timerTest5: Time past/left [ 5502/ 6498]ms next due after [49680]!
[43394]           [08:22:146]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[46256]
[43944]                     [08:22:696]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[46943]
[45910] [08:24:662]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[48756]
[46361]           [08:25:113]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[49256]
[47118]                     [08:25:870]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[50118]
[48250] timerTest5: Time past/left [10568/ 1432]ms next due after [49680]!
[48829] [08:27:581]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[51756]
[49432]           [08:28:185]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[52256]
[49709]                                         [08:28:461] => test5 runned! ([12.0]Sec.) -> 5_due[61709]
[49760]                               [08:28:512]           => test4 runned! ([ 9.0]Sec.) -> 4_due[58760]
[50171]                     [08:28:923]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[53171]
[51900] [08:30:652]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[54756]
[52294]           [08:31:046]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[55256]
[53342] timerTest5: Time past/left [ 3633/ 8367]ms next due after [61700]!
[53343]                     [08:32:095]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[56343]
[54817] [08:33:569]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[57756]
[55359]           [08:34:111]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[58256]
[56448]                     [08:35:200]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[59448]
[57838] [08:36:590]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[60756]
[58258]           [08:37:010]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[61256]
[58516] timerTest5: Time past/left [ 8807/ 3193]ms next due after [61700]!
[58766]                               [08:37:518]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 2230]
[59595]                     [08:38:347]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[62595]
[60922] [08:39:674]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[63756]
[61359]           [08:40:111]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[64256]
[61767]                                         [08:40:519] => test5 runned! ([12.1]Sec.) -> 5_due[ 8231]
[62635]                     [08:41:387]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[   99]

[63206] test1 counted[173] times run in [173] events --> EQUAL
[63206] test2 counted[159] times run in [173] events --> ? (14 off)
[63207] test3 counted[152] times run in [173] events --> ? (21 off)
[63213] test4 counted[54] times run in [57] events --> ? (3 off)
[63218] test5 counted[40] times run in [43] events --> ? (3 off)

[63224] timerTest1: Time past/left [ 2468/  532]ms  next due after [63750]!
[63231] timerTest2: Time past/left [ 1975/ 1025]ms  next due after [64250]!
[63238] timerTest3: Time past/left [  604/ 2396]ms  next due after [65630]!
[63244] timerTest4: Time past/left [ 4479/ 4521]ms  next due after [67760]!
[63251] timerTest5: Time past/left [    1/   10]sec next due after [73760]!

[63258] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[ 2197] startHolding: Time left [  39268]ms, [   39]sec, [ 0]min.
[ 2197] timerTest1: Time past/left [ 3000/    0]ms  next due after [ 2190]!
[ 2199] timerTest2: Time past/left [ 3000/    0]ms  next due after [ 2190]!
[ 2205] timerTest3: Time past/left [ 3000/    0]ms  next due after [ 2200]!
[ 2212] timerTest4: Time past/left [ 8982/   18]ms  next due after [ 2230]!
[ 2219] timerTest5: Time past/left [    5/    6]sec next due after [ 8230]!



[ 2226] ***** timer16Bit() has rolled-over! *****

[ 2230] timerTest1: Time past/left [ 3000/    0]ms  next due after [ 2230]!
[ 2237] timerTest2: Time past/left [ 3000/    0]ms  next due after [ 2230]!
[ 2244] timerTest3: Time past/left [ 3000/    0]ms  next due after [ 2240]!
[ 2250] timerTest4: Time past/left [ 9000/    0]ms  next due after [ 2250]!
[ 2257] timerTest5: Time past/left [    6/    5]sec next due after [ 8230]!

[ 2452] timerTest5: Time past/left [ 6221/ 5779]ms next due after [ 8230]!
[ 2453] [08:46:741]                                         => test1 runned! ([ 7.1]Sec.) -> 1_due[ 1220]
[ 2468]           [08:46:757]                               => test2 runned! ([ 6.6]Sec.) -> 2_due[ 4720]
[ 2478]                     [08:46:766]                     => test3 runned! ([ 5.4]Sec.) -> 3_due[ 5478]
[ 2488]                               [08:46:776]           => test4 runned! ([ 9.3]Sec.) -> 4_due[11488]
[ 2746] [08:47:034]                                         => test1 runned! ([ 0.3]Sec.) -> 1_due[ 4220]
[ 4376] [08:48:664]                                         => test1 runned! ([ 1.6]Sec.) -> 1_due[ 7220]
[ 4806]           [08:49:094]                               => test2 runned! ([ 2.3]Sec.) -> 2_due[ 7720]
[ 5479]                     [08:49:767]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 8479]
[ 7309] [08:51:597]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[10220]
[ 7476] timerTest5: Time past/left [11245/  755]ms next due after [ 8230]!
[ 7793]           [08:52:081]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[10720]
[ 8312]                                         [08:52:600] => test5 runned! ([12.1]Sec.) -> 5_due[20312]
[ 8507]                     [08:52:795]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[11507]
[10344] [08:54:632]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[13220]
[10782]           [08:55:070]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[13720]
[11508]                     [08:55:796]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[14508]
[11518]                               [08:55:806]           => test4 runned! ([ 9.0]Sec.) -> 4_due[20518]
[12603] timerTest5: Time past/left [ 4291/ 7709]ms next due after [20310]!
[13309] [08:57:597]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[16220]
[13757]           [08:58:045]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[16720]
[14638]                     [08:58:926]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[17638]
[16312] [09:00:600]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[19220]
[16824]           [09:01:112]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[19720]
[17764] timerTest5: Time past/left [ 9452/ 2548]ms next due after [20310]!
[17765]                     [09:02:053]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[20765]
[19326] [09:03:614]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[22220]
[19830]           [09:04:118]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[22720]
[20313]                                         [09:04:601] => test5 runned! ([12.0]Sec.) -> 5_due[32313]
[20553]                               [09:04:841]           => test4 runned! ([ 9.0]Sec.) -> 4_due[29553]
[20826]                     [09:05:114]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[23826]
[22302] [09:06:590]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[25220]
[22798] timerTest5: Time past/left [ 2485/ 9515]ms next due after [32310]!
[22799]           [09:07:087]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[25720]
[23858]                     [09:08:146]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[26858]
[25286] [09:09:574]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[28220]
[25745]           [09:10:033]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[28720]
[26958]                     [09:11:246]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[29958]
[27852] timerTest5: Time past/left [ 7539/ 4461]ms next due after [32310]!
[28380] [09:12:668]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[31220]
[28840]           [09:13:128]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[31720]
[29569]                               [09:13:857]           => test4 runned! ([ 9.0]Sec.) -> 4_due[38569]
[30048]                     [09:14:336]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[33048]
[31374] [09:15:662]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[34220]
[31767]           [09:16:055]                               => test2 runned! ([ 2.9]Sec.) -> 2_due[34720]
[32348]                                         [09:16:636] => test5 runned! ([12.0]Sec.) -> 5_due[44348]
[32895] timerTest5: Time past/left [  547/11453]ms next due after [44340]!
[33132]                     [09:17:420]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[36132]
[34294] [09:18:582]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[37220]
[34794]           [09:19:082]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[37720]
[36182]                     [09:20:470]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[39182]
[37376] [09:21:664]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[40220]
[37783]           [09:22:071]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[40720]
[38023] timerTest5: Time past/left [ 5675/ 6325]ms next due after [44340]!
[38575]                               [09:22:863]           => test4 runned! ([ 9.0]Sec.) -> 4_due[47575]
[39348]                     [09:23:636]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[42348]
[40220] [09:24:508]                                         => test1 runned! ([ 2.8]Sec.) -> 1_due[43220]
[40770]           [09:25:058]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[43720]

[41498] timerTest1: Time past/left [ 1278/ 1722]ms  next due after [43220]!
[41499] timerTest2: Time past/left [  779/ 2221]ms  next due after [43720]!
[41501] timerTest3: Time past/left [ 2153/  847]ms  next due after [42340]!
[41507] timerTest4: Time past/left [ 2932/ 6068]ms  next due after [47570]!
[41514] timerTest5: Time past/left [    9/    2]sec next due after [44340]!


[41521] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
*********************** using NO random delays! from here on *********************

[56526] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[56530] timerTest1: Time past/left [ 3000/    0]ms  next due after [56530]!
[56536] timerTest2: Time past/left [ 3000/    0]ms  next due after [56530]!
[56543] timerTest3: Time past/left [ 3000/    0]ms  next due after [56540]!
[56550] timerTest4: Time past/left [ 9000/    0]ms  next due after [56550]!
[56556] timerTest5: Time past/left [   12/    0]sec next due after [56550]!


[56565] timerTest5: Time past/left [12000/    0]ms next due after [56560]!
[56570] [09:40:858]                                         => test1 runned! ([16.3]Sec.) -> 1_due[46220]
[56590]           [09:40:878]                               => test2 runned! ([15.8]Sec.) -> 2_due[58720]
[56600]                     [09:40:888]                     => test3 runned! ([17.3]Sec.) -> 3_due[59600]
[56610]                               [09:40:898]           => test4 runned! ([18.0]Sec.) -> 4_due[   74]
[56620]                                         [09:40:908] => test5 runned! ([24.3]Sec.) -> 5_due[ 3084]
[56631] [09:40:919]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[49220]
[56640] [09:40:928]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[52220]
[56650] [09:40:938]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[55220]
[56660] [09:40:948]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[58220]
[58220] [09:42:508]                                         => test1 runned! ([ 1.6]Sec.) -> 1_due[61220]
[58720]           [09:43:008]                               => test2 runned! ([ 2.1]Sec.) -> 2_due[61720]
[59600]                     [09:43:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[62600]
[61220] [09:45:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[64220]
[61565] timerTest5: Time past/left [ 4946/ 7054]ms next due after [68610]!
[61720]           [09:46:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[64720]
[62600]                     [09:46:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[   64]
[64220] [09:48:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 1684]
[64720]           [09:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2184]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [ 1316/ 1684]ms  next due after [ 1680]!
[    0] timerTest2: Time past/left [  816/ 2184]ms  next due after [ 2180]!
[    7] timerTest3: Time past/left [ 2943/   57]ms  next due after [   60]!
[   13] timerTest4: Time past/left [ 8939/   61]ms  next due after [   70]!
[   20] timerTest5: Time past/left [    8/    3]sec next due after [ 3080]!

[   64]                     [09:49:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 3064]
[   74]                               [09:49:898]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 9074]
[ 1029] timerTest5: Time past/left [ 9945/ 2055]ms next due after [ 3080]!
[ 1684] [09:51:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 4684]
[ 2184]           [09:52:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5184]
[ 3064]                     [09:52:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 6064]
[ 3084]                                         [09:52:908] => test5 runned! ([12.0]Sec.) -> 5_due[15084]
[ 4684] [09:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 7684]
[ 5184]           [09:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8184]
[ 6029] timerTest5: Time past/left [ 2945/ 9055]ms next due after [15080]!
[ 6064]                     [09:55:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 9064]
[ 7684] [09:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[10684]
[ 8184]           [09:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[11184]
[ 9064]                     [09:58:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[12064]
[ 9074]                               [09:58:898]           => test4 runned! ([ 9.0]Sec.) -> 4_due[18074]
[10684] [10:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[13684]
[11029] timerTest5: Time past/left [ 7945/ 4055]ms next due after [15080]!
[11184]           [10:01:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[14184]
[12064]                     [10:01:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[15064]
[13684] [10:03:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[16684]
[14184]           [10:04:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[17184]
[15064]                     [10:04:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[18064]
[15084]                                         [10:04:908] => test5 runned! ([12.0]Sec.) -> 5_due[27084]
[16029] timerTest5: Time past/left [  945/11055]ms next due after [27080]!
[16684] [10:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[19684]
[17184]           [10:07:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[20184]
[18064]                     [10:07:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[21064]
[18074]                               [10:07:898]           => test4 runned! ([ 9.0]Sec.) -> 4_due[27074]
[19684] [10:09:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[22684]
[20184]           [10:10:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[23184]
[21029] timerTest5: Time past/left [ 5945/ 6055]ms next due after [27080]!
[21064]                     [10:10:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[24064]
[22684] [10:12:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[25684]
[23184]           [10:13:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[26184]
[24064]                     [10:13:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[27064]
[25684] [10:15:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[28684]
[26029] timerTest5: Time past/left [10945/ 1055]ms next due after [27080]!
[26184]           [10:16:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[29184]
[27064]                     [10:16:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[30064]
[27074]                               [10:16:898]           => test4 runned! ([ 9.0]Sec.) -> 4_due[36074]
[27084]                                         [10:16:908] => test5 runned! ([12.0]Sec.) -> 5_due[39084]
[28684] [10:18:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[31684]
[29184]           [10:19:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[32184]
[30064]                     [10:19:888]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[33064]
[31029] timerTest5: Time past/left [ 3946/ 8054]ms next due after [39080]!
[31684] [10:21:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[34684]

[32027] test1 counted[207] times run in [207] events --> EQUAL
[32028] test2 counted[187] times run in [207] events --> ? (20 off)
[32028] test3 counted[179] times run in [207] events --> ? (28 off)
[32034] test4 counted[64] times run in [69] events --> ? (5 off)
[32040] test5 counted[47] times run in [51] events --> ? (4 off)

[32046] timerTest1: Time past/left [  363/ 2637]ms  next due after [34680]!
[32052] timerTest2: Time past/left [ 2868/  132]ms  next due after [32180]!
[32059] timerTest3: Time past/left [ 1996/ 1004]ms  next due after [33060]!
[32066] timerTest4: Time past/left [ 4993/ 4007]ms  next due after [36070]!
[32072] timerTest5: Time past/left [    4/    7]sec next due after [39080]!

[32079] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[36083] startHolding: Time left [  84943]ms, [   84]sec, [ 1]min.
[36084] timerTest1: Time past/left [ 3000/    0]ms  next due after [36080]!
[36086] timerTest2: Time past/left [ 3000/    0]ms  next due after [36080]!
[36093] timerTest3: Time past/left [ 3000/    0]ms  next due after [36090]!
[36099] timerTest4: Time past/left [ 9000/    0]ms  next due after [36090]!
[36106] timerTest5: Time past/left [    9/    2]sec next due after [39080]!


[36113] timerTest5: Time past/left [ 9029/ 2971]ms next due after [39080]!
[36120] [10:25:944]                                         => test1 runned! ([ 4.4]Sec.) -> 1_due[37684]
[36140]           [10:25:964]                               => test2 runned! ([ 7.0]Sec.) -> 2_due[38184]
[36150]                     [10:25:974]                     => test3 runned! ([ 6.1]Sec.) -> 3_due[39150]
[36160]                               [10:25:984]           => test4 runned! ([ 9.1]Sec.) -> 4_due[45160]
[37684] [10:27:508]                                         => test1 runned! ([ 1.5]Sec.) -> 1_due[40684]
[38184]           [10:28:008]                               => test2 runned! ([ 2.0]Sec.) -> 2_due[41184]
[39084]                                         [10:28:908] => test5 runned! ([12.0]Sec.) -> 5_due[51084]
[39150]                     [10:28:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[42150]
[40684] [10:30:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[43684]
[41113] timerTest5: Time past/left [ 2029/ 9971]ms next due after [51080]!
[41184]           [10:31:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[44184]
[42150]                     [10:31:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[45150]
[43684] [10:33:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[46684]
[44184]           [10:34:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[47184]
[45150]                     [10:34:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[48150]
[45160]                               [10:34:984]           => test4 runned! ([ 9.0]Sec.) -> 4_due[54160]
[46113] timerTest5: Time past/left [ 7029/ 4971]ms next due after [51080]!
[46684] [10:36:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[49684]
[47184]           [10:37:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[50184]
[48150]                     [10:37:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[51150]
[49684] [10:39:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[52684]
[50184]           [10:40:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[53184]
[51084]                                         [10:40:908] => test5 runned! ([12.0]Sec.) -> 5_due[63084]
[51113] timerTest5: Time past/left [   29/11971]ms next due after [63080]!
[51150]                     [10:40:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[54150]
[52684] [10:42:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[55684]
[53184]           [10:43:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[56184]
[54150]                     [10:43:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[57150]
[54160]                               [10:43:984]           => test4 runned! ([ 9.0]Sec.) -> 4_due[63160]
[55684] [10:45:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[58684]
[56113] timerTest5: Time past/left [ 5029/ 6971]ms next due after [63080]!
[56184]           [10:46:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[59184]
[57150]                     [10:46:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[60150]
[58684] [10:48:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[61684]
[59184]           [10:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[62184]
[60150]                     [10:49:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[63150]
[61113] timerTest5: Time past/left [10029/ 1971]ms next due after [63080]!
[61684] [10:51:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[64684]
[62184]           [10:52:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[65184]
[63084]                                         [10:52:908] => test5 runned! ([12.0]Sec.) -> 5_due[ 9548]
[63150]                     [10:52:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[  614]
[63160]                               [10:52:984]           => test4 runned! ([ 9.0]Sec.) -> 4_due[ 6624]
[64684] [10:54:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 2148]
[65184]           [10:55:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 2648]

[    0] ***** timer16Bit() has rolled-over! *****

[    0] timerTest1: Time past/left [  852/ 2148]ms  next due after [ 2140]!
[    0] timerTest2: Time past/left [  352/ 2648]ms  next due after [ 2640]!
[    7] timerTest3: Time past/left [ 2393/  607]ms  next due after [  610]!
[   13] timerTest4: Time past/left [ 2389/ 6611]ms  next due after [ 6620]!
[   20] timerTest5: Time past/left [    2/    9]sec next due after [ 9540]!

[  577] timerTest5: Time past/left [ 3029/ 8971]ms next due after [ 9540]!
[  614]                     [10:55:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 3614]
[ 2148] [10:57:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 5148]
[ 2648]           [10:58:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 5648]
[ 3614]                     [10:58:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 6614]
[ 5148] [11:00:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[ 8148]
[ 5577] timerTest5: Time past/left [ 8029/ 3971]ms next due after [ 9540]!
[ 5648]           [11:01:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[ 8648]
[ 6614]                     [11:01:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[ 9614]
[ 6624]                               [11:01:984]           => test4 runned! ([ 9.0]Sec.) -> 4_due[15624]
[ 8148] [11:03:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[11148]
[ 8648]           [11:04:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[11648]
[ 9548]                                         [11:04:908] => test5 runned! ([12.0]Sec.) -> 5_due[21548]
[ 9614]                     [11:04:974]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[12614]
[10577] timerTest5: Time past/left [ 1029/10971]ms next due after [21540]!
[11148] [11:06:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[14148]

[11577] test1 counted[222] times run in [222] events --> EQUAL
[11577] test2 counted[201] times run in [222] events --> ? (21 off)
[11578] test3 counted[193] times run in [222] events --> ? (29 off)
[11584] test4 counted[69] times run in [74] events --> ? (5 off)
[11590] test5 counted[51] times run in [55] events --> ? (4 off)

[11595] timerTest1: Time past/left [  447/ 2553]ms  next due after [14140]!
[11602] timerTest2: Time past/left [ 2954/   46]ms  next due after [11640]!
[11609] timerTest3: Time past/left [ 1995/ 1005]ms  next due after [12610]!
[11615] timerTest4: Time past/left [ 4991/ 4009]ms  next due after [15620]!
[11622] timerTest5: Time past/left [    2/    9]sec next due after [21540]!

[11629] wait ... wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww.. continue

[15633] startHolding: Time left [  39858]ms, [   39]sec, [ 0]min.
[15634] timerTest1: Time past/left [ 3000/    0]ms  next due after [15630]!
[15636] timerTest2: Time past/left [ 3000/    0]ms  next due after [15630]!
[15642] timerTest3: Time past/left [ 3000/    0]ms  next due after [15640]!
[15649] timerTest4: Time past/left [ 9000/    0]ms  next due after [15640]!
[15656] timerTest5: Time past/left [    6/    5]sec next due after [21540]!


[15663] timerTest5: Time past/left [ 6115/ 5885]ms next due after [21540]!
[15669] [11:11:029]                                         => test1 runned! ([ 4.5]Sec.) -> 1_due[17148]
[15690]           [11:11:050]                               => test2 runned! ([ 7.0]Sec.) -> 2_due[17648]
[15700]                     [11:11:060]                     => test3 runned! ([ 6.1]Sec.) -> 3_due[18700]
[15710]                               [11:11:070]           => test4 runned! ([ 9.1]Sec.) -> 4_due[24710]
[17148] [11:12:508]                                         => test1 runned! ([ 1.5]Sec.) -> 1_due[20148]
[17648]           [11:13:008]                               => test2 runned! ([ 2.0]Sec.) -> 2_due[20648]
[18700]                     [11:14:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[21700]
[20148] [11:15:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[23148]
[20648]           [11:16:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[23648]
[20663] timerTest5: Time past/left [11115/  885]ms next due after [21540]!
[21548]                                         [11:16:908] => test5 runned! ([12.0]Sec.) -> 5_due[33548]
[21700]                     [11:17:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[24700]
[23148] [11:18:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[26148]
[23648]           [11:19:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[26648]
[24700]                     [11:20:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[27700]
[24710]                               [11:20:070]           => test4 runned! ([ 9.0]Sec.) -> 4_due[33710]
[25663] timerTest5: Time past/left [ 4116/ 7884]ms next due after [33540]!
[26148] [11:21:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[29148]
[26648]           [11:22:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[29648]
[27700]                     [11:23:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[30700]
[29148] [11:24:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[32148]
[29648]           [11:25:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[32648]
[30663] timerTest5: Time past/left [ 9116/ 2884]ms next due after [33540]!
[30700]                     [11:26:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[33700]
[32148] [11:27:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[35148]
[32648]           [11:28:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[35648]
[33548]                                         [11:28:908] => test5 runned! ([12.0]Sec.) -> 5_due[45548]
[33700]                     [11:29:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[36700]
[33710]                               [11:29:070]           => test4 runned! ([ 9.0]Sec.) -> 4_due[42710]
[35148] [11:30:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[38148]
[35648]           [11:31:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[38648]
[35663] timerTest5: Time past/left [ 2115/ 9885]ms next due after [45540]!
[36700]                     [11:32:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[39700]
[38148] [11:33:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[41148]
[38648]           [11:34:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[41648]
[39700]                     [11:35:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[42700]
[40663] timerTest5: Time past/left [ 7115/ 4885]ms next due after [45540]!
[41148] [11:36:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[44148]
[41648]           [11:37:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[44648]
[42700]                     [11:38:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[45700]
[42710]                               [11:38:070]           => test4 runned! ([ 9.0]Sec.) -> 4_due[51710]
[44148] [11:39:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[47148]
[44648]           [11:40:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[47648]
[45548]                                         [11:40:908] => test5 runned! ([12.0]Sec.) -> 5_due[57548]
[45663] timerTest5: Time past/left [  115/11885]ms next due after [57540]!
[45700]                     [11:41:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[48700]
[47148] [11:42:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[50148]
[47648]           [11:43:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[50648]
[48700]                     [11:44:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[51700]
[50148] [11:45:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[53148]
[50648]           [11:46:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[53648]
[50663] timerTest5: Time past/left [ 5115/ 6885]ms next due after [57540]!
[51700]                     [11:47:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[54700]
[51710]                               [11:47:070]           => test4 runned! ([ 9.0]Sec.) -> 4_due[60710]
[53148] [11:48:508]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[56148]
[53648]           [11:49:008]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[56648]
[54700]                     [11:50:060]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[57700]

[55491] timerTest1: Time past/left [ 2343/  657]ms  next due after [56140]!
[55492] timerTest2: Time past/left [ 1844/ 1156]ms  next due after [56640]!
[55494] timerTest3: Time past/left [  794/ 2206]ms  next due after [57700]!
[55501] timerTest4: Time past/left [ 3791/ 5209]ms  next due after [60710]!
[55508] timerTest5: Time past/left [    9/    2]sec next due after [57540]!


[55514] hold ... 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 .. continue
************************* using Random Delays from here on ***********************

[ 4984] startWaiting: Time left [      0]ms, [    0]sec., [ 0]min.

[ 4987] timerTest1: Time past/left [ 3000/    0]ms  next due after [ 4980]!
[ 4994] timerTest2: Time past/left [ 3000/    0]ms  next due after [ 4990]!
[ 5000] timerTest3: Time past/left [ 3000/    0]ms  next due after [ 5000]!
[ 5007] timerTest4: Time past/left [ 9000/    0]ms  next due after [ 5000]!
[ 5014] timerTest5: Time past/left [   12/    0]sec next due after [ 5010]!


[ 5148] timerTest5: Time past/left [12000/    0]ms next due after [ 5140]!
[ 5148] [12:06:044]                                         => test1 runned! ([17.5]Sec.) -> 1_due[59148]
[ 5164]           [12:06:060]                               => test2 runned! ([17.1]Sec.) -> 2_due[ 6112]
[ 5174]                     [12:06:070]                     => test3 runned! ([16.0]Sec.) -> 3_due[ 8174]
[ 5184]                               [12:06:080]           => test4 runned! ([19.0]Sec.) -> 4_due[14184]
[ 5194]                                         [12:06:090] => test5 runned! ([25.2]Sec.) -> 5_due[17194]
[ 5399] [12:06:295]                                         => test1 runned! ([ 0.2]Sec.) -> 1_due[62148]
[ 5654] [12:06:550]                                         => test1 runned! ([ 0.2]Sec.) -> 1_due[65148]
[ 5712] [12:06:608]                                         => test1 runned! ([ 0.0]Sec.) -> 1_due[ 2612]
[ 5940] [12:06:836]                                         => test1 runned! ([ 0.2]Sec.) -> 1_due[ 5612]
[ 6165] [12:07:061]                                         => test1 runned! ([ 0.2]Sec.) -> 1_due[ 8612]
[ 6175]           [12:07:071]                               => test2 runned! ([ 1.0]Sec.) -> 2_due[ 9112]
[ 8195]                     [12:09:091]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[11194]
[ 8653] [12:09:549]                                         => test1 runned! ([ 2.5]Sec.) -> 1_due[11612]
[ 9155]           [12:10:051]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[12112]
[10248] timerTest5: Time past/left [ 5054/ 6946]ms next due after [17190]!
[11277]                     [12:12:173]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[14277]
[11655] [12:12:551]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[14612]
[12236]           [12:13:132]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[15112]
[14333]                     [12:15:229]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[17333]
[14344]                               [12:15:240]           => test4 runned! ([ 9.2]Sec.) -> 4_due[23344]
[14667] [12:15:563]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[17612]
[15346] timerTest5: Time past/left [10152/ 1848]ms next due after [17190]!
[15347]           [12:16:243]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[18112]
[17268]                                         [12:18:164] => test5 runned! ([12.1]Sec.) -> 5_due[29268]
[17500]                     [12:18:396]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[20499]
[17669] [12:18:565]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[20612]
[18128]           [12:19:024]                               => test2 runned! ([ 2.8]Sec.) -> 2_due[21112]
[20513] timerTest5: Time past/left [ 3245/ 8755]ms next due after [29260]!
[20514]                     [12:21:410]                     => test3 runned! ([ 3.0]Sec.) -> 3_due[23514]
[20763] [12:21:659]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[23612]
[21119]           [12:22:015]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[24112]
[23508]                               [12:24:404]           => test4 runned! ([ 9.2]Sec.) -> 4_due[32508]
[23661] [12:24:557]                                         => test1 runned! ([ 2.9]Sec.) -> 1_due[26612]
[23671]                     [12:24:567]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[26671]
[24147]           [12:25:043]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[27112]
[25563] timerTest5: Time past/left [ 8295/ 3705]ms next due after [29260]!
[26657] [12:27:553]                                         => test1 runned! ([ 3.0]Sec.) -> 1_due[29612]
[26769]                     [12:27:665]                     => test3 runned! ([ 3.1]Sec.) -> 3_due[29769]
[27222]           [12:28:118]                               => test2 runned! ([ 3.1]Sec.) -> 2_due[30112]
[29330]                                         [12:30:226] => test5 runned! ([12.1]Sec.) -> 5_due[41330]
[29729] [12:30:625]                                         => test1 runned! ([ 3.1]Sec.) -> 1_due[32612]
[29981]                     [12:30:877]                     => test3 runned! ([ 3.2]Sec.) -> 3_due[32981]
[30180]           [12:31:076]                               => test2 runned! ([ 3.0]Sec.) -> 2_due[33112]
[30643] timerTest5: Time past/left [ 1314/10686]ms next due after [41320]!
