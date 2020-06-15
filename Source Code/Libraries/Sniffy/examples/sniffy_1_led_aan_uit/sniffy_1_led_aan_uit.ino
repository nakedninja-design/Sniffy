/* ==================================================
 * Sniffy source code versie 1.5
 * Copyright (c)2017 Naked Ninja
 *
 * Je kunt de LED aan en uit zetten door verschillende
 * waarden mee tegeven aan de functie setLEDColor().
 * Met setLEDColor(255,0,0) maak je de LED rood en met
 * setLEDColor(0,0,0) zet je 'm uit.
 * 
 * De tijd dat de LED brandt of uit staat wijzig je door
 * een andere waarde aan de functie delay() mee te geven.
 * Met delay(1000) wacht je 1 seconde.
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

/* 
 *  Maak je eigen Sniffy aan en geef 'm een naam.
 * bijv. "mySniffy". Deze naam moet je wel steeds 
 * blijven gebruiken in de programmacode.
 * 
 */
Sniffy mySniffy;

/* ================void setup()=============
 *  Verplichte standaard functie.
 *  Alle functies die je hier plaatst worden
 *  1 keer uitgevoerd bij het opstarten van
 *  jouw Sniffy.
 */
void setup() {
  mySniffy.begin();
}

/* ================void loop()==============
 *  Verplichte standaard functie.
 *  Alle functies die je hier plaatst worden
 *  herhaaldelijk uitgevoerd. 
 * =========================================*/
void loop() {
  // Verwijder de commentaarstreepjes '//' aan het BEGIN van onderstaande 4 regels
  
  //mySniffy.setLEDColor(255,0,0);  
  //delay(1000);                    // Wacht 1 seconde, verander de waarde om de LED korter of langer te laten branden.

  //mySniffy.setLEDColor(0,0,0);    
  //delay(1000);                    // Wacht 1 seconde
}

