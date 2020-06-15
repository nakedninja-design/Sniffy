/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Doe een temperatuurmeting en 
 * laat Sniffy 10 seconden slapen.
 * Als Sniffy slaapt verbruikt hij
 * heel weinig energie.
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

  mySniffy.setTemperatureColor(255,0,0,); // ROOD
}

void loop() {
  // Verwijder de commentaarstrepjes '//' aan het BEGIN van de 2 regels 

  //mySniffy.measureTemperature();    // Meet de temperatuur
  //sleep(10);                        // Slaap 10 seconden
}

