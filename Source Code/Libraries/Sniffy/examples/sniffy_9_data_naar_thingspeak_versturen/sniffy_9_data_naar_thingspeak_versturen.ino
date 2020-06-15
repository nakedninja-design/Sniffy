/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Geeft naam en wachtwoord van het Wifi
 * netwerk op en stel de kleur in die 
 * laat zien wanneer er verbinding met 
 * Wifi gemaakt wordt. 
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

  mySniffy.setWifiColor(255,255,255); // WIT
}

void loop() {
  // Verwijder de commentaarstrepjes '//' aan het BEGIN van de 6 regels 
  // Vergeet niet bij connectWifi() naam en wachtwoord van het accesspoint in te vullen,
  // en bij sendDataToThingSpeak() het channelID en de WriteAPIKey.
  
  //mySniffy.connectWifi("XXXX","XXXX"); // Maak Wifi verbinding
  //mySniffy.measureTemperature();       // Meet de temperatuur
  //mySniffy.measureHumidity();          // Meet de luchtvochtigheid
  //mySniffy.sendDataToThingSpeak(0,"XXXX");     // Verstuur meetdata naar ThingSpeak
  //mySniffy.disconnectWifi();           // Verbreek de Wifi verbinding
  //delay(10000);                        // Wacht 10 seconden
}

