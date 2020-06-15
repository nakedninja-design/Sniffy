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
  
  mySniffy.setLEDColor(0, 0, 0); // Zet LED uit
}

void loop() {
  // Verwijder de commentaarstrepjes '//' die voor mySniffy.setColor(...) staan 
  
  // Laat de LED steeds feller rood branden (0 -> 255)
  for (int i=0;i<255;i=i+1) {
     //mySniffy.setColor(R(i, 0, 0);
  }

  // Laat de LED steeds zwakker rood branden (255 -> 0)
  for (int i=255;i>0;i=i-1) {
     //mySniffy.setLEDColor(i, 0, 0);
  }
}

