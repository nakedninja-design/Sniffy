/* 
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Stel een kleur in voor het meten van de luchtvochtigheid,
 * stel het bereik dat je wilt meten, bijv. LED uit bij 30% 
 * en LED op zijn felst bij 60%, en blaas vervolgens met je 
 * adem op de sensor. 
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


/* 
 * Dit gedeelte bevat de minimale en maximale
 * waarden vooe de temperatuurschaal. Ze worden 
 * gebruikt in measureTemperatureContinuously(). 
 */
#define minHumidity      0   // Verander deze waarde
#define maxHumidity    100   // Verander deze waarde

Sniffy mySniffy;

void setup() {
  mySniffy.begin();
  
  mySniffy.setHumidityColor(0,0,255); // Zet de kleur voor luchtvochtigheid op BLAUW
}

void loop() {
  // Verwijder de commentaarstrepjes '//' die voor mySniffy.... staan 
  
  //mySniffy.measureHumidityContinuously();
}

