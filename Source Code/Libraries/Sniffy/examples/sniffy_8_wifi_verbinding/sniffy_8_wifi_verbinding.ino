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

  // Verwijder de commentaarstrepjes '//' aan het BEGIN van de regel 

  //mySniffy.setWifiColor(255,0,0); // Verander deze waarde
}

void loop() {
  // Verwijder de commentaarstrepjes '//' aan het BEGIN van de 4 regels 

  //mySniffy.connectWifi("XXXX","XXXX");  // Vul naam en toegangscode van het Wifi netwerk in
  //delay(4000);            // Wacht 4 seconden
  
  //mySniffy.disconnectWifi();  // Verbreek de Wifi verbinding
  //delay(4000);            // Wacht 4 seconden
}

