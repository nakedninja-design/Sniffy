/* ==================================================
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * De kleur van de LED veranderen. Jr kunt de kleur 
 * zelf bepalen door 3 primaire kleuren (rood, groen, blauw) 
 * te mixen: Rood maak je zo:
 * mySniffy.setLEDColor(255,0,0);
 * En groen maak je zo:
 * mySniffy.setLEDColor(0,255,0);
 * Iedere waarde moet tussen 0 en 255 liggen.
 * ==================================================
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
}

void loop() {
  // Verwijder de commentaarstreepjes '//' aan het BEGIN van onderstaande regel
  
  //mySniffy.setLEDColor(255,0,0);  // Met (255,0,0) wordt de kleur ROOD
  delay(1000);                    // Wacht 1 seconde, verander de waarde om de LED korter of langer te laten branden.

  mySniffy.setLEDColor(0,0,0);    // Met (0,0,0) zet je de LED uit
  delay(1000);                    // Wacht 1 seconde
}

