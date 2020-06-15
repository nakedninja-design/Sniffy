/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Bepaal zelf welke kleur gebruikt wordt
 * voor meting van de temperatuur en van 
 * de luchtvochtigheid.
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

  // Verwijder de commentaarstrepjes '//' aan het BEGIN van de 2 regels 

  //mySniffy.setTemperatureColor(255,0,0); // Verander deze waarde
  //mySniffy.setHumidityColor(0,0,255);    // Verander deze waarde
}

void loop() {
  mySniffy.measureTemperature(); 
  delay(3000);         
                          
  mySniffy.measureHumidity(); 
  delay(3000);         
}

