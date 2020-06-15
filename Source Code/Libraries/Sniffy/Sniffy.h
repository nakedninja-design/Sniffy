/*=========================================//
// Sniffy library code versie 1.7
// Copyright (c)2017 Naked Ninja
//
// Gebruik van deze code of een deel ervan 
// buiten de context van Sniffy is verboden.
//=========================================*/

#ifndef Sniffy_h
#define Sniffy_h

#include "Arduino.h"

/*====Stel parameters voor de sensor in====//
// Dit gedeelte bevat de definities van de 
// parameters die nodig zijn voor de functies:
// measureTemperatureContinuously() en
// measureHumidityContinuously(). 
//
// Vooraf gedefinieerde warden in de functies
// measureTemperatureContinuously() en 
// measureHumidityContinuously() zullen worden
// gebruikt als de programmeur geen waardes voorziet.
//=========================================*/
//#define minTemperature    22    // Voorbeeld waarde
//#define maxTemperature    28    // Voorbeeld waarde

//#define minHumidity       0     // Voorbeeld waarde
//#define maxHumidity       100   // Voorbeeld waarde
//=========================================//


class Sniffy
{
  public:
    Sniffy();
    float Temperature;
    float Humidity; 
    void begin();
    void measureTemperature();
    void measureHumidity();
    void measureTemperatureContinuously();
    void measureHumidityContinuously();
    void rainbow(uint8_t loops);
    void setLEDColor(uint8_t r, uint8_t g, uint8_t b);
    void setTemperatureColor(uint8_t r, uint8_t g, uint8_t b);
    void setHumidityColor(uint8_t r, uint8_t g, uint8_t b);
    void setWifiColor(uint8_t r, uint8_t g, uint8_t b);
    void connectWifi(char* s, char* p);
    void disconnectWifi();
    void sendDataToThingSpeak(char* k);
    void sleep(int sleepTime);

  private:
    char* _ssid;
    char* _password;
    String _writeAPIKey;
    /* 
	 * Globale Temperatuur & Luchtvochtigheid
	 * 
	 * Dit gedeelte bevat globale variabelen voor 
	 * de temperatuur en luchtvochtigheid data. 
	 * 
	 * Deze variabelen zullen worden overschreven 
	 * met werkelijke gemeten data door andere functies.
	 */
    float _temperature;
    float _humidity;
	uint32_t _temperatureColor; 
	uint32_t _humidityColor;    
	uint32_t _wifiColor;  
	uint32_t _ledOff;
    void _setColor(uint32_t color);
    bool _connectThingSpeak();
    void _disconnectThingSpeak();
    uint32_t _cycle(uint8_t wheelPos);
};

#endif
