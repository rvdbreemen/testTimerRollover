

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
