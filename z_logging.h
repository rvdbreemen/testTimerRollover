

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
Due_Test1[3000]ms, DUE_TEST3[8000]ms Due_Test4[12000]

StartTime[00:01:064]

[ 3736][ 3736]ms  [00:03:736]                               => test1 fired!
[ 3929][ 3929]ms            [00:03:929]                     => test2 fired!
[ 6736][ 2807]ms  [00:06:736]                               => test1 fired!
[ 7116][ 2860]ms            [00:07:116]                     => test2 fired!
[ 9672][ 9672]ms                      [00:09:672]           => test3 fired!
[ 9805][ 2689]ms  [00:09:805]                               => test1 fired!
[10116][ 2513]ms            [00:10:116]                     => test2 fired!
[12736][ 2908]ms  [00:12:736]                               => test1 fired!
[13116][ 2755]ms            [00:13:116]                     => test2 fired!
[13973][13973]ms                                [00:13:973] => test4 fired!
[15736][ 2879]ms  [00:15:736]                               => test1 fired!
[16128][ 2946]ms            [00:16:128]                     => test2 fired!
[17672][ 7867]ms                      [00:17:672]           => test3 fired!
[18736][ 2608]ms  [00:18:736]                               => test1 fired!
[19128][ 2632]ms            [00:19:128]                     => test2 fired!
[21736][ 2841]ms  [00:21:736]                               => test1 fired!
[22128][ 2619]ms            [00:22:128]                     => test2 fired!
[24736][ 2701]ms  [00:24:736]                               => test1 fired!
[25128][ 2977]ms            [00:25:128]                     => test2 fired!
[25672][ 7916]ms                      [00:25:672]           => test3 fired!
[25973][11536]ms                                [00:25:973] => test4 fired!
[27736][ 2745]ms  [00:27:736]                               => test1 fired!
[28128][ 2943]ms            [00:28:128]                     => test2 fired!
[30736][ 2873]ms  [00:30:736]                               => test1 fired!
[31128][ 2516]ms            [00:31:128]                     => test2 fired!
[33672][ 7825]ms                      [00:33:672]           => test3 fired!
[33997][ 3138]ms  [00:33:997]                               => test1 fired!
[34392][ 2899]ms            [00:34:392]                     => test2 fired!
[36736][ 2344]ms  [00:36:736]                               => test1 fired!
[37392][ 2730]ms            [00:37:392]                     => test2 fired!
[37973][11671]ms                                [00:37:973] => test4 fired!
[39736][ 2994]ms  [00:39:736]                               => test1 fired!
[40392][ 2808]ms            [00:40:392]                     => test2 fired!
[41672][ 7675]ms                      [00:41:672]           => test3 fired!
test1 counted[13] times fired in [13] events --> OK!
test2 counted[13] times fired in [13] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 54]sec., [  54876]ms, [ 0]min.
[46188][ 6352]ms  [00:46:188]                               => test1 fired!
[46555][ 5723]ms            [00:46:555]                     => test2 fired!
[46645][   91]ms  [00:46:645]                               => test1 fired!
[48736][ 1666]ms  [00:48:736]                               => test1 fired!
[49554][ 2909]ms            [00:49:554]                     => test2 fired!
[50044][ 8215]ms                      [00:50:044]           => test3 fired!
[50224][12211]ms                                [00:50:224] => test4 fired!
[51736][ 2977]ms  [00:51:736]                               => test1 fired!
[52554][ 2510]ms            [00:52:554]                     => test2 fired!
[54736][ 2997]ms  [00:54:736]                               => test1 fired!
[55554][ 2739]ms            [00:55:554]                     => test2 fired!
[57672][ 7448]ms                      [00:57:672]           => test3 fired!
[58123][ 3228]ms  [00:58:123]                               => test1 fired!
[58554][ 2852]ms            [00:58:554]                     => test2 fired!
[60736][ 2278]ms  [01:00:736]                               => test1 fired!
[61554][ 2991]ms            [01:01:554]                     => test2 fired!
[62224][11629]ms                                [01:02:224] => test4 fired!
[63736][ 2810]ms  [01:03:736]                               => test1 fired!
[64554][ 2643]ms            [01:04:554]                     => test2 fired!

********** 16bit timer Rollover *******

[  136][ 7549]ms                      [01:05:672]           => test3 fired!
[ 1200][ 2784]ms  [01:06:736]                               => test1 fired!
[ 2018][ 2936]ms            [01:07:554]                     => test2 fired!
[ 4200][ 2966]ms  [01:09:736]                               => test1 fired!
[ 5018][ 2836]ms            [01:10:554]                     => test2 fired!
[ 7200][ 2723]ms  [01:12:736]                               => test1 fired!
[ 8018][ 2887]ms            [01:13:554]                     => test2 fired!
[ 8401][ 8190]ms                      [01:13:937]           => test3 fired!
[ 8688][11830]ms                                [01:14:224] => test4 fired!
[10200][ 2896]ms  [01:15:736]                               => test1 fired!
[11018][ 2617]ms            [01:16:554]                     => test2 fired!
[13200][ 2544]ms  [01:18:736]                               => test1 fired!
[14018][ 2848]ms            [01:19:554]                     => test2 fired!
[16136][ 7640]ms                      [01:21:672]           => test3 fired!
[16509][ 2956]ms  [01:22:045]                               => test1 fired!
[17018][ 2836]ms            [01:22:554]                     => test2 fired!
[19200][ 2442]ms  [01:24:736]                               => test1 fired!
[20018][ 2933]ms            [01:25:554]                     => test2 fired!
[20688][11650]ms                                [01:26:224] => test4 fired!
test1 counted[28] times fired in [28] events --> OK!
test2 counted[27] times fired in [28] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [  9]sec., [   9753]ms, [ 0]min.
[25775][ 6229]ms  [01:31:311]                               => test1 fired!
[26071][ 5801]ms            [01:31:607]                     => test2 fired!
[26362][ 9853]ms                      [01:31:898]           => test3 fired!
[26764][  693]ms  [01:32:300]                               => test1 fired!
[28200][ 1295]ms  [01:33:736]                               => test1 fired!
[29071][ 2709]ms            [01:34:607]                     => test2 fired!
[31200][ 2839]ms  [01:36:736]                               => test1 fired!
[32071][ 2502]ms            [01:37:607]                     => test2 fired!
[32229][ 5465]ms                      [01:37:765]           => test3 fired!
[32688][11743]ms                                [01:38:224] => test4 fired!
[34200][ 2919]ms  [01:39:736]                               => test1 fired!
[35071][ 2842]ms            [01:40:607]                     => test2 fired!
hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue!
delay41Secs: Time left [ 16]sec., [  16246]ms, [ 0]min.
[50529][15835]ms  [01:56:065]                               => test1 fired!
[50940][15574]ms            [01:56:476]                     => test2 fired!
[51229][18987]ms                      [01:56:765]           => test3 fired!
[51551][18545]ms                                [01:57:087] => test4 fired!
[51763][  823]ms  [01:57:299]                               => test1 fired!
[51914][  363]ms                      [01:57:450]           => test3 fired!
[52151][  237]ms  [01:57:687]                               => test1 fired!
[52494][    0]ms  [01:58:030]                               => test1 fired!
[52793][    0]ms  [01:58:329]                               => test1 fired!
[53153][    0]ms  [01:58:689]                               => test1 fired!
[53940][ 2711]ms            [01:59:476]                     => test2 fired!
[55200][ 1840]ms  [02:00:736]                               => test1 fired!
[56136][ 3985]ms                      [02:01:672]           => test3 fired!
[56940][ 2695]ms            [02:02:476]                     => test2 fired!
[58200][ 2922]ms  [02:03:736]                               => test1 fired!
[59940][ 2998]ms            [02:05:476]                     => test2 fired!
[61200][ 2728]ms  [02:06:736]                               => test1 fired!
[62940][ 2827]ms            [02:08:476]                     => test2 fired!
[63551][11788]ms                                [02:09:087] => test4 fired!
[64136][ 7568]ms                      [02:09:672]           => test3 fired!
[64368][ 2942]ms  [02:09:904]                               => test1 fired!

********** 16bit timer Rollover *******

[  404][ 2885]ms            [02:11:476]                     => test2 fired!
test1 counted[43] times fired in [43] events --> OK!
test2 counted[37] times fired in [43] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 79]sec., [  79630]ms, [ 1]min.
[ 5362][ 6381]ms  [02:16:434]                               => test1 fired!
[ 5522][ 4824]ms            [02:16:594]                     => test2 fired!
[ 5715][  193]ms  [02:16:787]                               => test1 fired!
      .
      .
      .
[20283][11669]ms                                [18:54:395] => test4 fired!
[20624][ 2673]ms  [18:54:736]                               => test1 fired!
hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue!
delay41Secs: Time left [4291]sec., [4291352]ms, [71]min.
[37062][16290]ms  [19:11:174]                               => test1 fired!
[37539][18014]ms            [19:11:651]                     => test2 fired!
[37585][21905]ms                      [19:11:697]           => test3 fired!
[38067][17626]ms                                [19:12:179] => test4 fired!
test1 counted[379] times fired in [383] events --> ERROR! (4 off)

****************** times fired 4 events behind ******************

test2 counted[315] times fired in [383] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 94]sec., [  94776]ms, [ 1]min.
[42286][ 4747]ms  [19:16:398]                               => test1 fired!
[42387][ 4802]ms            [19:16:499]                     => test2 fired!
[42411][ 4344]ms                      [19:16:523]           => test3 fired!
[42757][  370]ms  [19:16:869]                               => test1 fired!
[42816][   59]ms                      [19:16:928]           => test3 fired!
[43046][  230]ms  [19:17:159]                               => test1 fired!
[43107][    0]ms  [19:17:219]                               => test1 fired!
[43455][    0]ms  [19:17:567]                               => test1 fired!
[43837][    0]ms  [19:17:949]                               => test1 fired!
[44624][  769]ms  [19:18:736]                               => test1 fired!
[45387][ 2976]ms            [19:19:499]                     => test2 fired!
[47560][ 4514]ms                      [19:21:672]           => test3 fired!
[47699][ 2961]ms  [19:21:811]                               => test1 fired!
[48387][ 2893]ms            [19:22:499]                     => test2 fired!
[50067][11905]ms                                [19:24:179] => test4 fired!
[50624][ 2745]ms  [19:24:736]                               => test1 fired!
[51387][ 2818]ms            [19:25:499]                     => test2 fired!
[53624][ 2898]ms  [19:27:736]                               => test1 fired!
[54387][ 2787]ms            [19:28:499]                     => test2 fired!
[55560][ 7861]ms                      [19:29:672]           => test3 fired!
[56624][ 2533]ms  [19:30:736]                               => test1 fired!
[57387][ 2507]ms            [19:31:499]                     => test2 fired!
[59624][ 2822]ms  [19:33:736]                               => test1 fired!
[60387][ 2880]ms            [19:34:499]                     => test2 fired!
[62067][11749]ms                                [19:36:179] => test4 fired!
[62624][ 2737]ms  [19:36:736]                               => test1 fired!
[63387][ 2645]ms            [19:37:499]                     => test2 fired!
[63760][ 7977]ms                      [19:37:872]           => test3 fired!

********** 16bit timer Rollover *******

[   88][ 2883]ms  [19:39:736]                               => test1 fired!
[  851][ 2627]ms            [19:40:499]                     => test2 fired!
[ 3088][ 2921]ms  [19:42:736]                               => test1 fired!
[ 3851][ 2688]ms            [19:43:499]                     => test2 fired!
[ 6024][ 7392]ms                      [19:45:672]           => test3 fired!
[ 6187][ 2608]ms  [19:45:835]                               => test1 fired!
[ 6851][ 2678]ms            [19:46:499]                     => test2 fired!
[ 8531][11946]ms                                [19:48:179] => test4 fired!
[ 9088][ 2791]ms  [19:48:736]                               => test1 fired!
[ 9851][ 2977]ms            [19:49:499]                     => test2 fired!
[12088][ 2996]ms  [19:51:736]                               => test1 fired!
[12851][ 2749]ms            [19:52:499]                     => test2 fired!
[14024][ 7837]ms                      [19:53:672]           => test3 fired!
[15088][ 2794]ms  [19:54:736]                               => test1 fired!
[15851][ 3000]ms            [19:55:499]                     => test2 fired!

****************** times fired catched up with events ******************
              vvv                  vvv             vv!
test1 counted[398] times fired in [398] events --> OK!
test2 counted[329] times fired in [398] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 49]sec., [  49652]ms, [ 0]min.
[21873][ 6415]ms  [20:01:521]                               => test1 fired!
[22349][ 6003]ms            [20:01:997]                     => test2 fired!
[22512][ 8157]ms                      [20:02:160]           => test3 fired!
[22622][13878]ms                                [20:02:270] => test4 fired!
[23017][  668]ms  [20:02:665]                               => test1 fired!
[24088][  805]ms  [20:03:736]                               => test1 fired!
[25349][ 2837]ms            [20:04:997]                     => test2 fired!
[27088][ 2973]ms  [20:06:736]                               => test1 fired!
      .
      .
      .
[43976][ 7993]ms                      [07:21:672]           => test3 fired!
[44168][ 2762]ms  [07:21:864]                               => test1 fired!
[44492][ 2934]ms            [07:22:188]                     => test2 fired!
[47040][ 2548]ms  [07:24:736]                               => test1 fired!
[47492][ 2594]ms            [07:25:188]                     => test2 fired!
[50040][ 2722]ms  [07:27:736]                               => test1 fired!
test1 counted[1349] times fired in [1348] events --> ERROR! (-1 off)
test2 counted[1102] times fired in [1348] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 74]sec., [  74664]ms, [ 1]min.
[54290][ 4124]ms  [07:31:986]                               => test1 fired!
[54370][ 6635]ms            [07:32:066]                     => test2 fired!
[54577][10409]ms                      [07:32:273]           => test3 fired!
[54588][12098]ms                                [07:32:284] => test4 fired!
[56040][ 1670]ms  [07:33:736]                               => test1 fired!
[57370][ 2793]ms            [07:35:066]                     => test2 fired!
[59040][ 2957]ms  [07:36:736]                               => test1 fired!
[59976][ 5388]ms                      [07:37:672]           => test3 fired!
[60370][ 2606]ms            [07:38:066]                     => test2 fired!
      .
      .
[24834][ 2745]ms            [08:08:066]                     => test2 fired!
[25243][11883]ms                                [08:08:475] => test4 fired!
[26440][ 7996]ms                      [08:09:672]           => test3 fired!
[26879][ 2963]ms  [08:10:111]                               => test1 fired!
[27834][ 2726]ms            [08:11:066]                     => test2 fired!
[29504][ 2137]ms  [08:12:736]                               => test1 fired!
test1 counted[1364] times fired in [1363] events --> ERROR! (-1 off)
test2 counted[1116] times fired in [1363] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 29]sec., [  29541]ms, [ 0]min.
[33877][ 4313]ms  [08:17:109]                               => test1 fired!
[33942][ 5805]ms            [08:17:174]                     => test2 fired!
[34440][ 7561]ms                      [08:17:672]           => test3 fired!
      .
      .
[57942][ 2704]ms            [08:41:174]                     => test2 fired!
[58440][ 7773]ms                      [08:41:672]           => test3 fired!
[59504][ 2897]ms  [08:42:736]                               => test1 fired!
[60942][ 2509]ms            [08:44:174]                     => test2 fired!
[61251][11998]ms                                [08:44:483] => test4 fired!
[62504][ 2557]ms  [08:45:736]                               => test1 fired!
hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue!
delay41Secs: Time left [4291]sec., [4291426]ms, [71]min.
[12883][15444]ms  [09:01:651]                               => test1 fired!
[13230][17552]ms            [09:01:998]                     => test2 fired!
[13579][20374]ms                      [09:02:347]           => test3 fired!
[13694][17618]ms                                [09:02:462] => test4 fired!
test1 counted[1376] times fired in [1380] events --> ERROR! (4 off)
test2 counted[1127] times fired in [1380] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 94]sec., [  94749]ms, [ 1]min.
[18134][ 4904]ms  [09:06:902]                               => test1 fired!
[18153][ 4574]ms            [09:06:921]                     => test2 fired!
[18599][ 4905]ms                      [09:07:367]           => test3 fired!
[19014][  861]ms  [09:07:782]                               => test1 fired!
[19448][  434]ms                      [09:08:216]           => test3 fired!
[19572][  124]ms  [09:08:340]                               => test1 fired!
[19617][    0]ms  [09:08:385]                               => test1 fired!
[20021][    0]ms  [09:08:789]                               => test1 fired!
[20298][    0]ms  [09:09:066]                               => test1 fired!
[20968][  310]ms  [09:09:736]                               => test1 fired!
[21424][ 2825]ms            [09:10:192]                     => test2 fired!
[23968][ 2544]ms  [09:12:736]                               => test1 fired!
[24424][ 2739]ms            [09:13:192]                     => test2 fired!
[24904][ 5332]ms                      [09:13:672]           => test3 fired!
      .
      .
[53968][ 2655]ms  [09:42:736]                               => test1 fired!
[54424][ 2800]ms            [09:43:192]                     => test2 fired!
[56904][ 7941]ms                      [09:45:672]           => test3 fired!
[57319][ 3061]ms  [09:46:087]                               => test1 fired!
[57573][ 2717]ms            [09:46:341]                     => test2 fired!
test1 counted[1395] times fired in [1395] events --> OK!
test2 counted[1141] times fired in [1395] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 49]sec., [  49625]ms, [ 0]min.
[63257][ 5684]ms  [09:52:025]                               => test1 fired!
[63721][ 5849]ms            [09:52:489]                     => test2 fired!
[64004][14123]ms                                [09:52:772] => test4 fired!
[64473][  752]ms  [09:53:241]                               => test1 fired!
[64904][ 7585]ms                      [09:53:672]           => test3 fired!

********** 16bit timer Rollover *******

[  432][ 1384]ms  [09:54:736]                               => test1 fired!
[ 1185][ 2717]ms            [09:55:489]                     => test2 fired!
[ 3432][ 2556]ms  [09:57:736]                               => test1 fired!
[ 4185][ 2965]ms            [09:58:489]                     => test2 fired!
      .
      .
      .
[13832][ 7718]ms                      [11:13:672]           => test3 fired!
[15114][ 2790]ms            [11:14:954]                     => test2 fired!
[15896][ 2862]ms  [11:15:736]                               => test1 fired!
[18114][ 2640]ms            [11:17:954]                     => test2 fired!
test1 counted[1425] times fired in [1425] events --> OK!
test2 counted[1165] times fired in [1425] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 74]sec., [  74361]ms, [ 1]min.
[22450][ 6271]ms  [11:22:290]                               => test1 fired!
[22790][ 4464]ms            [11:22:630]                     => test2 fired!
[23290][ 9259]ms                      [11:23:130]           => test3 fired!
[23661][13689]ms                                [11:23:501] => test4 fired!
[23700][  910]ms  [11:23:540]                               => test1 fired!
[24896][ 1135]ms  [11:24:736]                               => test1 fired!
[25790][ 2500]ms            [11:25:630]                     => test2 fired!
[27896][ 2746]ms  [11:27:736]                               => test1 fired!
[28790][ 2780]ms            [11:28:630]                     => test2 fired!
[29832][ 6171]ms                      [11:29:672]           => test3 fired!
[30896][ 2693]ms  [11:30:736]                               => test1 fired!
[31790][ 2968]ms            [11:31:630]                     => test2 fired!
[33896][ 2627]ms  [11:33:736]                               => test1 fired!
[34790][ 2921]ms            [11:34:630]                     => test2 fired!


************************ micros() Rolled Over *****************************


[35661][11961]ms                                [11:35:501] => test4 fired!
[36896][ 2726]ms  [11:36:736]                               => test1 fired!
[37790][ 2519]ms            [11:37:630]                     => test2 fired!
[37997][ 7711]ms                      [11:37:837]           => test3 fired!
[39896][ 2514]ms  [11:39:736]                               => test1 fired!
[40790][ 2793]ms            [11:40:630]                     => test2 fired!
[42896][ 2896]ms  [11:42:736]                               => test1 fired!
[43790][ 2722]ms            [11:43:630]                     => test2 fired!
[45832][ 7555]ms                      [11:45:672]           => test3 fired!
[45973][ 2928]ms  [11:45:813]                               => test1 fired!
[46790][ 2645]ms            [11:46:630]                     => test2 fired!
[47661][11807]ms                                [11:47:501] => test4 fired!
[48896][ 2663]ms  [11:48:736]                               => test1 fired!
[49790][ 2712]ms            [11:49:630]                     => test2 fired!
[51896][ 2957]ms  [11:51:736]                               => test1 fired!
[52790][ 2525]ms            [11:52:630]                     => test2 fired!
[53832][ 7859]ms                      [11:53:672]           => test3 fired!
[54896][ 2566]ms  [11:54:736]                               => test1 fired!
[55790][ 2785]ms            [11:55:630]                     => test2 fired!
[57896][ 2892]ms  [11:57:736]                               => test1 fired!
[58790][ 2847]ms            [11:58:630]                     => test2 fired!
[59661][11803]ms                                [11:59:501] => test4 fired!
[60896][ 2697]ms  [12:00:736]                               => test1 fired!
[61790][ 2554]ms            [12:01:630]                     => test2 fired!
[61892][ 7956]ms                      [12:01:732]           => test3 fired!
test1 counted[1440] times fired in [1440] events --> OK!
test2 counted[1179] times fired in [1440] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 29]sec., [  29238]ms, [ 0]min.
[ 2037][ 6430]ms  [12:07:413]                               => test1 fired!
[ 2114][ 5758]ms            [12:07:490]                     => test2 fired!
[ 2266][  152]ms  [12:07:642]                               => test1 fired!
[ 4296][ 7582]ms                      [12:09:672]           => test3 fired!
[ 4646][ 1949]ms  [12:10:022]                               => test1 fired!
[ 5114][ 2849]ms            [12:10:490]                     => test2 fired!
[ 6125][11667]ms                                [12:11:501] => test4 fired!
[ 7360][ 2643]ms  [12:12:736]                               => test1 fired!
[ 8114][ 2765]ms            [12:13:490]                     => test2 fired!
[10360][ 2731]ms  [12:15:736]                               => test1 fired!
[11114][ 2859]ms            [12:16:490]                     => test2 fired!
[12296][ 7650]ms                      [12:17:672]           => test3 fired!
[13360][ 2521]ms  [12:18:736]                               => test1 fired!
[14114][ 2638]ms            [12:19:490]                     => test2 fired!
[16360][ 2884]ms  [12:21:736]                               => test1 fired!
[17114][ 2583]ms            [12:22:490]                     => test2 fired!
[18125][11735]ms                                [12:23:501] => test4 fired!
[19360][ 2936]ms  [12:24:736]                               => test1 fired!
[20114][ 2820]ms            [12:25:490]                     => test2 fired!
[20298][ 7936]ms                      [12:25:674]           => test3 fired!
[22360][ 2638]ms  [12:27:736]                               => test1 fired!
[23114][ 2816]ms            [12:28:490]                     => test2 fired!
[25360][ 2799]ms  [12:30:736]                               => test1 fired!
[26114][ 2952]ms            [12:31:490]                     => test2 fired!
[28296][ 7642]ms                      [12:33:672]           => test3 fired!
[28478][ 3104]ms  [12:33:854]                               => test1 fired!
[29114][ 2980]ms            [12:34:490]                     => test2 fired!
[30125][11785]ms                                [12:35:501] => test4 fired!
hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue!
delay41Secs: Time left [4291]sec., [4291729]ms, [71]min.
[46276][17672]ms  [12:51:652]                               => test1 fired!
[46333][17030]ms            [12:51:709]                     => test2 fired!
[46507][18029]ms                      [12:51:883]           => test3 fired!
[46606][16326]ms                                [12:51:982] => test4 fired!
test1 counted[1452] times fired in [1457] events --> ERROR! (5 off)
test2 counted[1190] times fired in [1457] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 95]sec., [  95202]ms, [ 1]min.
[51074][ 4741]ms  [12:56:450]                               => test1 fired!
[51541][ 5034]ms            [12:56:917]                     => test2 fired!
[51877][ 5272]ms                      [12:57:253]           => test3 fired!
[51938][  397]ms  [12:57:314]                               => test1 fired!
[52314][  376]ms                      [12:57:690]           => test3 fired!
[52616][  302]ms  [12:57:992]                               => test1 fired!
[53093][    0]ms  [12:58:469]                               => test1 fired!
[53281][    0]ms  [12:58:657]                               => test1 fired!
[53408][    0]ms  [12:58:784]                               => test1 fired!
[53576][    0]ms  [12:58:952]                               => test1 fired!
[54541][ 2664]ms            [12:59:917]                     => test2 fired!
[55360][ 1456]ms  [13:00:736]                               => test1 fired!
[57541][ 2739]ms            [13:02:917]                     => test2 fired!
[58360][ 2569]ms  [13:03:736]                               => test1 fired!
[58829][11879]ms                                [13:04:205] => test4 fired!
[60296][ 7681]ms                      [13:05:672]           => test3 fired!
[60541][ 2517]ms            [13:05:917]                     => test2 fired!
[61360][ 2531]ms  [13:06:736]                               => test1 fired!
[63541][ 2707]ms            [13:08:917]                     => test2 fired!
[64360][ 2829]ms  [13:09:736]                               => test1 fired!

********** 16bit timer Rollover *******

[ 1005][ 2547]ms            [13:11:917]                     => test2 fired!
[ 1824][ 2971]ms  [13:12:736]                               => test1 fired!
[ 2760][ 7983]ms                      [13:13:672]           => test3 fired!
[ 4005][ 2735]ms            [13:14:917]                     => test2 fired!
[ 4824][ 2784]ms  [13:15:736]                               => test1 fired!
[ 5293][11924]ms                                [13:16:205] => test4 fired!
[ 7005][ 2772]ms            [13:17:917]                     => test2 fired!
[ 7824][ 2786]ms  [13:18:736]                               => test1 fired!
[10005][ 2734]ms            [13:20:917]                     => test2 fired!
[10760][ 7853]ms                      [13:21:672]           => test3 fired!
[11115][ 2976]ms  [13:22:027]                               => test1 fired!
[13005][ 2506]ms            [13:23:917]                     => test2 fired!
[13824][ 2651]ms  [13:24:736]                               => test1 fired!
[16005][ 2944]ms            [13:26:917]                     => test2 fired!
[16824][ 2658]ms  [13:27:736]                               => test1 fired!
[17293][11704]ms                                [13:28:205] => test4 fired!
[18760][ 7645]ms                      [13:29:672]           => test3 fired!
[19243][ 3213]ms            [13:30:155]                     => test2 fired!
[19824][ 2827]ms  [13:30:736]                               => test1 fired!
[22243][ 2883]ms            [13:33:155]                     => test2 fired!
[22824][ 2544]ms  [13:33:736]                               => test1 fired!
[25243][ 2530]ms            [13:36:155]                     => test2 fired!
[25824][ 2780]ms  [13:36:736]                               => test1 fired!
test1 counted[1472] times fired in [1472] events --> OK!
test2 counted[1204] times fired in [1472] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 50]sec., [  50078]ms, [ 0]min.
[30661][ 4586]ms  [13:41:573]                               => test1 fired!
[30728][ 5146]ms            [13:41:640]                     => test2 fired!
[31212][11969]ms                      [13:42:124]           => test3 fired!
[31240][13855]ms                                [13:42:152] => test4 fired!
[31824][ 1096]ms  [13:42:736]                               => test1 fired!
[33728][ 2516]ms            [13:44:640]                     => test2 fired!
[34760][ 3520]ms                      [13:45:672]           => test3 fired!
[35037][ 3053]ms  [13:45:949]                               => test1 fired!
[36728][ 2583]ms            [13:47:640]                     => test2 fired!
[37824][ 2563]ms  [13:48:736]                               => test1 fired!
[39728][ 2571]ms            [13:50:640]                     => test2 fired!
[40824][ 2639]ms  [13:51:736]                               => test1 fired!
[42728][ 2958]ms            [13:53:640]                     => test2 fired!
[43128][ 8091]ms                      [13:54:040]           => test3 fired!
[43240][11542]ms                                [13:54:152] => test4 fired!
[43824][ 2893]ms  [13:54:736]                               => test1 fired!
[45728][ 2600]ms            [13:56:640]                     => test2 fired!
[46824][ 2639]ms  [13:57:736]                               => test1 fired!
[48728][ 2772]ms            [13:59:640]                     => test2 fired!
[49824][ 2711]ms  [14:00:736]                               => test1 fired!
[50760][ 7585]ms                      [14:01:672]           => test3 fired!
[51728][ 2965]ms            [14:02:640]                     => test2 fired!
[52824][ 2540]ms  [14:03:736]                               => test1 fired!
[54728][ 2851]ms            [14:05:640]                     => test2 fired!
[55240][11851]ms                                [14:06:152] => test4 fired!
[55824][ 2911]ms  [14:06:736]                               => test1 fired!
[57728][ 2731]ms            [14:08:640]                     => test2 fired!
[58760][ 7690]ms                      [14:09:672]           => test3 fired!
[59088][ 3211]ms  [14:10:000]                               => test1 fired!
[60728][ 2643]ms            [14:11:640]                     => test2 fired!
[61824][ 2702]ms  [14:12:736]                               => test1 fired!
[63728][ 2694]ms            [14:14:640]                     => test2 fired!
[64824][ 2915]ms  [14:15:736]                               => test1 fired!

********** 16bit timer Rollover *******

[ 1192][ 2573]ms            [14:17:640]                     => test2 fired!
[ 1542][ 7990]ms                      [14:17:990]           => test3 fired!
[ 2035][11917]ms                                [14:18:483] => test4 fired!
[ 2288][ 2978]ms  [14:18:736]                               => test1 fired!
[ 4192][ 2650]ms            [14:20:640]                     => test2 fired!
[ 5288][ 2955]ms  [14:21:736]                               => test1 fired!
test1 counted[1487] times fired in [1487] events --> OK!
test2 counted[1218] times fired in [1487] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [  4]sec., [   4955]ms, [ 0]min.
[10248][ 4668]ms  [14:26:696]                               => test1 fired!
[10650][ 6405]ms            [14:27:098]                     => test2 fired!
[11106][ 9071]ms                      [14:27:554]           => test3 fired!
[11288][  638]ms  [14:27:736]                               => test1 fired!
[13650][ 2544]ms            [14:30:098]                     => test2 fired!
[14100][11864]ms                                [14:30:548] => test4 fired!
[14536][ 2810]ms  [14:30:984]                               => test1 fired!
hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue!
delay41Secs: Time left [ 21]sec., [  21044]ms, [ 0]min.
[30204][15293]ms  [14:46:652]                               => test1 fired!
[30559][16459]ms            [14:47:007]                     => test2 fired!
[31042][19901]ms                      [14:47:490]           => test3 fired!
[31371][16835]ms                                [14:47:819] => test4 fired!
[31382][  823]ms  [14:47:830]                               => test1 fired!
[31411][   40]ms                      [14:47:859]           => test3 fired!
[31640][  230]ms  [14:48:088]                               => test1 fired!
[32124][    0]ms  [14:48:572]                               => test1 fired!
[32427][    0]ms  [14:48:875]                               => test1 fired!
[32617][    0]ms  [14:49:065]                               => test1 fired!
[33224][ 1584]ms                      [14:49:672]           => test3 fired!
[33559][ 2517]ms            [14:50:007]                     => test2 fired!
[35288][ 2643]ms  [14:51:736]                               => test1 fired!
[36559][ 2722]ms            [14:53:007]                     => test2 fired!
[38288][ 2681]ms  [14:54:736]                               => test1 fired!
[39559][ 2979]ms            [14:56:007]                     => test2 fired!
[41224][ 7697]ms                      [14:57:672]           => test3 fired!
[41435][ 2746]ms  [14:57:883]                               => test1 fired!
[42559][ 2720]ms            [14:59:007]                     => test2 fired!
[43371][11989]ms                                [14:59:819] => test4 fired!
[44288][ 2386]ms  [15:00:736]                               => test1 fired!
[45559][ 2674]ms            [15:02:007]                     => test2 fired!
[47288][ 2558]ms  [15:03:736]                               => test1 fired!
[48559][ 2617]ms            [15:05:007]                     => test2 fired!
[49224][ 7789]ms                      [15:05:672]           => test3 fired!
[50288][ 2844]ms  [15:06:736]                               => test1 fired!
test1 counted[1502] times fired in [1502] events --> OK!
test2 counted[1227] times fired in [1502] events
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 74]sec., [  74832]ms, [ 1]min.
[55372][ 4618]ms  [15:11:820]                               => test1 fired!
[55396][ 6460]ms            [15:11:844]                     => test2 fired!
[55601][11957]ms                                [15:12:049] => test4 fired!
[56288][  892]ms  [15:12:736]                               => test1 fired!
[57224][ 7517]ms                      [15:13:672]           => test3 fired!
[58396][ 2795]ms            [15:14:844]                     => test2 fired!
[59288][ 2895]ms  [15:15:736]                               => test1 fired!
[61396][ 2649]ms            [15:17:844]                     => test2 fired!
[62288][ 2777]ms  [15:18:736]                               => test1 fired!
[64396][ 2868]ms            [15:20:844]                     => test2 fired!
[65224][ 7760]ms                      [15:21:672]           => test3 fired!
[65421][ 2896]ms  [15:21:869]                               => test1 fired!

********** 16bit timer Rollover *******

[ 1860][ 2746]ms            [15:23:844]                     => test2 fired!
[ 2170][11652]ms                                [15:24:154] => test4 fired!
[ 2752][ 2767]ms  [15:24:736]                               => test1 fired!
[ 4860][ 2690]ms            [15:26:844]                     => test2 fired!
[ 5752][ 2870]ms  [15:27:736]                               => test1 fired!
[ 7688][ 7803]ms                      [15:29:672]           => test3 fired!
[ 7897][ 2702]ms            [15:29:881]                     => test2 fired!
[ 8752][ 2965]ms  [15:30:736]                               => test1 fired!
[10897][ 2603]ms            [15:32:881]                     => test2 fired!
[11752][ 2905]ms  [15:33:736]                               => test1 fired!
[13897][ 2532]ms            [15:35:881]                     => test2 fired!
[14170][11760]ms                                [15:36:154] => test4 fired!
[14752][ 2737]ms  [15:36:736]                               => test1 fired!
[15688][ 7791]ms                      [15:37:672]           => test3 fired!
[16897][ 2812]ms            [15:38:881]                     => test2 fired!
[17752][ 2927]ms  [15:39:736]                               => test1 fired!
[19897][ 2815]ms            [15:41:881]                     => test2 fired!
[20752][ 2785]ms  [15:42:736]                               => test1 fired!
[22897][ 2515]ms            [15:44:881]                     => test2 fired!
[23688][ 7805]ms                      [15:45:672]           => test3 fired!
[23752][ 2609]ms  [15:45:736]                               => test1 fired!
[25897][ 2740]ms            [15:47:881]                     => test2 fired!
[26354][11766]ms                                [15:48:338] => test4 fired!
[26752][ 2919]ms  [15:48:736]                               => test1 fired!
```
