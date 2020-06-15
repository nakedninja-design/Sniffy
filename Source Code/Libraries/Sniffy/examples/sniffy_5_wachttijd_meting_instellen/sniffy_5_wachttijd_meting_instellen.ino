/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Verander de wachttijd tussen de metingen.
 * De meting wordt getoond in de seriele monitor
 * omdat DEBUG op 1 staat.
 */

#include "Arduino.h"

/*===========Debug Seriële Print============//
// Het volgende deel definieert meerdere debug
// seriële prints die in-/uitgeschakeld kunnen
// worden met de “#define DEBUG”.
//
// Het instellen van de DEBUG waarde op 1 zal
// de seriële print inschakelen en het instellen 
// op 0 zal het uitschakelen. 
//=========================================*/
#define DEBUG true // flag to turn on/off debugging
#define Serial if(DEBUG)Serial 


Sniffy mySniffy;

void setup() {
  mySniffy.begin();
  mySniffy.setTemperatureColor(255,0,0); // Zet de kleur voor temperatuurmeting op ROOD
}

void loop() {
  // Verwijder de commentaarstrepjes '//' aan het BEGIN van de regels 
  
  //mySniffy.measureTemperature(); 
  //delay(10000);         // Wacht 10 seconden, verander de waarde om korter of langer te wachten met de volgende meting.
                          // Niet korter dan 4000!
}

