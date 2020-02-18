

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

Meer loggin volgt!

```
[14614][ 3000]ms            [14:26:582]                     => test2 fired!
[16064][ 3000]ms  [14:28:032]                               => test1 fired!
[17614][ 3000]ms            [14:29:582]                     => test2 fired!
[19064][ 3000]ms  [14:31:032]                               => test1 fired!
test1 counted[290] events in [290] seconds --> OK!  <<<<<<<<********************************
test2 counted[241] events in [290] seconds
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 30]sec., [  30362]ms, [ 0]min.
[23737][ 4673]ms  [14:35:705]                               => test1 fired!
[23737][ 6123]ms            [14:35:705]                     => test2 fired!
[23744][10451]ms                      [14:35:712]           => test3 fired!
[25064][ 1327]ms  [14:37:032]                               => test1 fired!
[25609][12000]ms                                [14:37:577] => test4 fired!
[26737][ 2993]ms            [14:38:705]                     => test2 fired!
[28064][ 3000]ms  [14:40:032]                               => test1 fired!
[29293][ 5542]ms                      [14:41:261]           => test3 fired!
[29737][ 3000]ms            [14:41:705]                     => test2 fired!
[31064][ 3000]ms  [14:43:032]                               => test1 fired!
[32737][ 3000]ms            [14:44:705]                     => test2 fired!
[34064][ 3000]ms  [14:46:032]                               => test1 fired!
[35737][ 3000]ms            [14:47:705]                     => test2 fired!
[37064][ 3000]ms  [14:49:032]                               => test1 fired!
[37293][ 8000]ms                      [14:49:261]           => test3 fired!
[37609][12000]ms                                [14:49:577] => test4 fired!
[38737][ 3000]ms            [14:50:705]                     => test2 fired!
[40064][ 3000]ms  [14:52:032]                               => test1 fired!
[41737][ 3000]ms            [14:53:705]                     => test2 fired!
[43064][ 3000]ms  [14:55:032]                               => test1 fired!
[44737][ 3000]ms            [14:56:705]                     => test2 fired!
[45293][ 8000]ms                      [14:57:261]           => test3 fired!
[46064][ 3000]ms  [14:58:032]                               => test1 fired!
[47737][ 3000]ms            [14:59:705]                     => test2 fired!
[49064][ 3000]ms  [15:01:032]                               => test1 fired!
[49609][12000]ms                                [15:01:577] => test4 fired!
[50737][ 3000]ms            [15:02:705]                     => test2 fired!
[52064][ 3000]ms  [15:04:032]                               => test1 fired!
[53293][ 8000]ms                      [15:05:261]           => test3 fired!
[53737][ 3000]ms            [15:05:705]                     => test2 fired!
hold for 15 seconds ..hhhhhhhhhhhhhhhhh.. continue!
delay41Secs: Time left [4290]sec., [4290604]ms, [71]min.
[ 3564][17036]ms  [15:21:068]                               => test1 fired!
[ 3565][15364]ms            [15:21:069]                     => test2 fired!
[ 3572][15815]ms                      [15:21:076]           => test3 fired!
[ 3578][19505]ms                                [15:21:082] => test4 fired!
test1 counted[302] events in [306] seconds --> ERROR!  <<<<<<<<**** zie regel 121 **********************
test2 counted[253] events in [306] seconds
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 95]sec., [  95855]ms, [ 1]min.
[ 7708][ 4143]ms  [15:25:212]                               => test1 fired!
[ 7709][ 4137]ms            [15:25:213]                     => test2 fired!
[ 7716][ 4138]ms                      [15:25:220]           => test3 fired!
[ 7722][   13]ms  [15:25:226]                               => test1 fired! <<<< inhaal aktie!
[ 7729][    0]ms  [15:25:233]                               => test1 fired! <<<< inhaal aktie!
[ 7736][    0]ms  [15:25:240]                               => test1 fired! <<<< inhaal aktie!
[ 7742][    0]ms  [15:25:246]                               => test1 fired! <<<< inhaal aktie!
[ 7749][    0]ms  [15:25:253]                               => test1 fired! <<<< inhaal aktie!
[ 8073][ 4488]ms                                [15:25:577] => test4 fired!
[10528][ 2772]ms  [15:28:032]                               => test1 fired!
[10709][ 2994]ms            [15:28:213]                     => test2 fired!
[11757][ 4035]ms                      [15:29:261]           => test3 fired!
[13528][ 3000]ms  [15:31:032]                               => test1 fired!
[13709][ 3000]ms            [15:31:213]                     => test2 fired!
[16528][ 3000]ms  [15:34:032]                               => test1 fired!
[16709][ 3000]ms            [15:34:213]                     => test2 fired!
[19528][ 3000]ms  [15:37:032]                               => test1 fired!
[19709][ 3000]ms            [15:37:213]                     => test2 fired!
[19757][ 8000]ms                      [15:37:261]           => test3 fired!
[20073][12000]ms                                [15:37:577] => test4 fired!
[22528][ 3000]ms  [15:40:032]                               => test1 fired!
[22709][ 3000]ms            [15:40:213]                     => test2 fired!
[25528][ 3000]ms  [15:43:032]                               => test1 fired!
[25709][ 3000]ms            [15:43:213]                     => test2 fired!
[27757][ 8000]ms                      [15:45:261]           => test3 fired!
[28528][ 3000]ms  [15:46:032]                               => test1 fired!
[28709][ 3000]ms            [15:46:213]                     => test2 fired!
[31528][ 3000]ms  [15:49:032]                               => test1 fired!
[31709][ 3000]ms            [15:49:213]                     => test2 fired!
[32073][12000]ms                                [15:49:577] => test4 fired!
[34528][ 3000]ms  [15:52:032]                               => test1 fired!
[34709][ 3000]ms            [15:52:213]                     => test2 fired!
[35757][ 8000]ms                      [15:53:261]           => test3 fired!
[37528][ 3000]ms  [15:55:032]                               => test1 fired!
[37709][ 3000]ms            [15:55:213]                     => test2 fired!
[40528][ 3000]ms  [15:58:032]                               => test1 fired!
[40709][ 3000]ms            [15:58:213]                     => test2 fired!
[43528][ 3000]ms  [16:01:032]                               => test1 fired!
[43709][ 3000]ms            [16:01:213]                     => test2 fired!
[43757][ 8000]ms                      [16:01:261]           => test3 fired!
[44073][12000]ms                                [16:01:577] => test4 fired!
[46528][ 3000]ms  [16:04:032]                               => test1 fired!
[46709][ 3000]ms            [16:04:213]                     => test2 fired!
test1 counted[321] events in [321] seconds --> OK!  <<<<<<<<********************************
test2 counted[267] events in [321] seconds
wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
after100Secs: Time left [ 50]sec., [  50732]ms, [ 0]min.
[52832][ 6304]ms  [16:10:336]                               => test1 fired!
[52832][ 6123]ms            [16:10:336]                     => test2 fired!
[52839][ 9082]ms                      [16:10:343]           => test3 fired!
[52846][   14]ms  [16:10:350]                               => test1 fired!
[55528][ 2676]ms  [16:13:032]                               => test1 fired!
[55832][ 2993]ms            [16:13:336]                     => test2 fired!
[56073][12000]ms                                [16:13:577] => test4 fired!
[58528][ 3000]ms  [16:16:032]                               => test1 fired!
```
