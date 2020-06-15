/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Verbind met Wifi, meet de temperatuur
 * en luchtvochtigheid, verstuur de data
 * naar ThingSpeak en ga 10 minuten slapen. 
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
  mySniffy.connectWifi("XXXX","XXXX"); // Maak Wifi verbinding
  mySniffy.measureTemperature();       // Meet de temperatuur
  mySniffy.measureHumidity();          // Meet de luchtvochtigheid
  mySniffy.sendDataToThingSpeak();     // Verstuur meetdata naar ThingSpeak
  mySniffy.disconnectWifi();           // Verbreek de Wifi verbinding
  mySniffy.sleep(600);                 // Slaap 10 minuten
}

