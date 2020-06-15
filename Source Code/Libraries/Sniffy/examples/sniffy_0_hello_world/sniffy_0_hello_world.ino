/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Toon tekst "Hello World!" in de
 * seriele monitor en zet de LED
 * 1 seconde aan en 1 seconde uit.
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
  debugSerialPrintln("Hello World!");  // Print tekst in seriele monitor
  
  mySniffy.setLEDColor(255,0,0);
  delay(1000);
  
  mySniffy.setLEDColor(0,0,0);
  delay(1000);
}
