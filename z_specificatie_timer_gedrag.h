xx=======================
Date: 22-02-2020  12:14
=======================

---TEST 1-----------------------------------------------------------------------------
time t   t1-----t2-----t3-----t4-----t5-----t6-----t7-----t8-----t9-----t10----t11-----
                                    <processor>
                                    <--bussy-->
start    vv~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ [no resets]
next due d1-----d2-----d3-----d4-----d5-----d6-----d7-----d8-----d9-----d10----d11----  [constant interval, no skip
fire due x1-----x2-----x3-----x4---------------x5x6x7-----x8-----x9-----x10----x11----  [0 missed events]
drift    ------------------------------------------------------------------------------ [0 ticks]
 
Test 1 haalt de gemiste "due's" in, aangezien de due next achterloopt. 
Op het moment dat de processor ergens mee bezig is, zal het nadien dus 
inderdaad inhalen zijn. Het voordeel van deze benadering is de eenvoud, het
nadeel is dat er een korte periode van inhalen en afvuren van de timer zal zijn.

Voordeel:
- Er worden NOOIT events overgeslagen.
- Er is geen drift ten opzicht van een startpunt, op tijdslijn t.

Nadeel:
- Tijd tussen (due fire en due next) zal nihil zijn dan interval, na een drukke periode.
- Events worden net zo lang afgevuurd totdat je de tijd (t) ingehaald hebt. 
- Rapid firing van de timer totdat je ingehaald hebt.

--TEST 2-------------------------------------------------------------------------------
         t1-----t2-----t3-----t4-----t5-----t6-----t7-----t8-----t9-----t10----t11-----t12
                                    <processor>
                                    <  bussy  >
start    vv~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ [no resets]
next due d1-----d2-----d3-----d4-----d5------------d7-----d8-----d9-----d10----d11----- [constant interval with skip]
fire due x1-----x2-----x3-----x4---------------x5--x7-----x8-----x9-----x10----x11----- [1 missed events]
drift    ------------------------------------------------------------------------------ [0 ticks]

Test2 vuurt het gelijk na de busy periode. Vervolgens is next_due de 
eerst volgende due die daarna komt. Je slaat dus de periode over. 
Dit zal een kortere interval zijn, aangezien je altijd uitgaat van
het startpunt van de due.s De "timer" zelf blijft dus altijd in hetzelfde
ritme afvuren hierdoor, tov start moment.

Voordeel:
- Gemiste events worden overgeslagen.
- Er is geen drift ten opzicht van een startpunt, op tijdslijn t.

Nadeel:
- Tijd tussen (due fire en due next) zal korter zijn dan interval, na een drukke periode.
- Je kan events gaan missen, dus als je hier een teller op baseert tel je het 
  aantal uitgevoerde events. Niet het aantal events dat je had moeten uitvoeren.

---TEST 3-------------------------------------------------------------------------------------------------------------
         t1-----t2-----t3-----t4-----t5-----t6-----t7-----t8-----t9-----t10----t11-----t12
                                    <processor>
                                    <  bussy  >
start    vv~~~~~vv~~~~~vv~~~~~vv~~~~~~~~~~~~~~~vv~~~~~vv~~~~~vv~~~~~vv~~~~~vv~~~~~vv~~~~~[resets every interval]                                    
next due d1-----d2-----d3-----d4-----d5---------------d6-----d7-----d8-----d9-----d10----[constant interval after fire]
fire due x1-----x2-----x3-----x4---------------x5-----x6-----x7-----x8-----x9-----x10----[1 missed events]
drift    --------------------------------------3ticks------------------------------------[3 ticks]


Test3 vuurt direct na een lange pauze (omdat de processor met andere, 
tijdrovende, zaken bezig was) en stelt de eerst volgende interval in op
het moment gelijk naar de pauze. De start van de timer reset elke keer als 
hij werkelijk afgevuurd wordt. Dit draagt zorg voor constante interval na elke
afvuren. 

Het voordeel:
- Constant interval tijd tussen fire due en next due.
- Gemiste events worden overgeslagen. 

Het nadeel:
- Er is sprake van drift ten opzicht van een startpunt, op tijdslijn t. Immers
  je reset due timer na elke "fire due" voor een volgend vast interval.
- Events kunnen worden overgeslagen, als de processor busy is.

---TEST 4-------------------------------------------------------------------------------------------------------------
         t1-----t2-----t3-----t4-----t5-----t6-----t7-----t8-----t9-----t10----t11-----t12
                                    <processor>
                                    <  bussy  >
start    vv~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[no resetl]                                    
next due d1-----d2-----d3-----d4-----d5------------d7-----d8-----d9-----d10----d11-----d12-[really skip]
fire due x1-----x2-----x3-----x4-------------------x7-----x8-----x9-----x10----x11-----x12-[2 missed events]
drift    ----------------------------------------------------------------------------------[0 ticks drift]


Test4 vuurt op de volgende interval moment dat voorbij komt. 
Deze timer haalt niets in, maar slaat de gemiste due momenten over,
en wacht op eerste echt interval moment na weer beschikbaar komen.
Vuurt dus niet onmiddelijk na event. De timer zou geen drift moeten kenne
en blijft vanaf de start altijd in hetzelfde ritme.

In feite is dit "true" skipping van events. Je wacht altijd op het eerste
due event dat je gaat krijgen, op basis van time t interval tijdslijn.
Geen net na gemist fire due, maar altijd wachten op eerst volgende. 

Hier zit een groot risico in, dat je nooit meer afvuurt, als de processor
telkens bezig zou zijn, terwijl je een due moment verwacht. 

Dus hoewel dit de "meest zuivere" variant is, zou deze  mogelijk de minst 
praktische variant zijn. Je kan namelijk heel lang timer due events missen.

Denkertje: Hoe implementeer je dit uberhaubt, en hoe zinvol is het dan?

Het voordeel:
- Constant interval tijd tussen fire due en next due.
- Gemiste events worden overgeslagen. 

Het nadeel:
- Events kunnen worden overgeslagen, als de processor busy is.
- Eerste next_due moment na een <bussy> periode, kan maximaal 1 interval duren.
