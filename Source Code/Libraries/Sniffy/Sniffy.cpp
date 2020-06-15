/*=========================================//
// Sniffy library code versie 1.7
// Copyright (c)2018 Naked Ninja
//
// Gebruik van deze code of een deel ervan 
// buiten de context van Sniffy is verboden.
//=========================================*/

#include "Arduino.h"
#include "Sniffy.h"

/*============Alle Bibliotheken=============//
// Alle benodigde bibliotheken worden in dit 
// deel van de code ge-include. Deze bibliotheken
// worden gebruikt om de programmeur pre-made 
// functies te geven.
//=========================================*/
#include <Adafruit_NeoPixel.h>    // RGB LED library
#include <SparkFunHTU21D.h>       // Sensor library
#include <ESP8266WiFi.h>          // ESP8266 WiFi library

/*======Creëer RGB op pin D5 (GPIO14)======//
// Het volgende deel creëert de RGB LED’s 
// klas naam. Dit deel definieert ook hoeveel
// RGBs er aangesloten zijn en aan welke pin.
// Data pin is pin GPIO14.
//=========================================*/
Adafruit_NeoPixel RGB(1, 14, NEO_GRB + NEO_KHZ800); // Creëer een klas naam voor de aangesloten RGB LED
#define RGBPowerSupply    12  // Definieer sensor voedingspin (GPIO12)
//=========================================//

/*======Create connection with sensor======//
// Het volgende deel definieert een klassenaam 
// voor de sensor, welke later gebruikt wordt
// door andere functies. 
// Ook wordt de voedingspin van de sensor hier
// definieert.
//=========================================*/
HTU21D mySensor;              // Creëer een klas naam voor de aangesloten sensor
#define SensorPowerSupply 13  // Definieer sensor voedingspin (GPIO12)
//=========================================//

/*
 * WiFi Client
 */
WiFiClient client;  // Creëer een klassenaam voor de WiFi bibliotheek


// constructor
Sniffy::Sniffy() 
{
	/* 
	 * Dit gedeelte bevat de WiFi naam (SSID) en het 
	 * WiFi wachtwoord. Deze waarden zullen worden 
	 * overgeschreven door de programmeur met 
	 * zijn/haar WiFi netwerk gegevens.
	 */ 
	_ssid = "XXXX";
	_password = "XXXX";
  _writeAPIKey = "XXXX";
	Humidity = 0;
	Temperature = 0;
	_temperatureColor = 0x000000; 
	_humidityColor = 0x000000;    
	_wifiColor = 0x000000; 
	_ledOff = 0x000000;  
}

// public methods

void Sniffy::begin() 
{
  //pinMode(LED_BUILTIN, OUTPUT);

  // Laat blauwe LED 1 seconde branden
  // digitalWrite(LED_BUILTIN, LOW); 
  // delay(2000); 
  // digitalWrite(LED_BUILTIN, HIGH);
  //delay(2000); 
  
  //===============Init RGB==================//
  pinMode(RGBPowerSupply, OUTPUT);     // Stel de sensor voedings pin D6(GPIO12) als een uitgang
  digitalWrite(RGBPowerSupply, HIGH);  // Maak D6 uitgang hoog (5V)
  RGB.begin();              // Begin communicatie met de RGB LED('s)
  delay(150);               // Wacht voor 150 ms om RGB.begin tijd te geven om de communicatie te beginnen
  RGB.setPixelColor(0,255,0,0);
  RGB.show();               // Initialiseer RGB LED naar 'uit'
  //=========================================//

  /*============Seriële monitor===============//
  // De seriële monitor is een communicatiemethode
  // met de pc/laptop. Voor meer informatie zie het
  // document dat met deze code is meegeleverd.
  // 
  // De seriële monitor is alleen ingeschakeld wanneer
  // de waarde van “DEBUG” 1 is. 
  //=========================================*/
  Serial.flush(); 
  Serial.println("\nSniffy begin!"); 
  //=========================================//

  //=============Init Sensor=================//
  pinMode(SensorPowerSupply, OUTPUT);     // Stel de sensor voedings pin D6(GPIO12) als een uitgang
  digitalWrite(SensorPowerSupply, HIGH);  // Maak D6 uitgang hoog (5V)
  mySensor.begin();                       // Begin communicatie met de sensor
  //=========================================//
}

void Sniffy::measureTemperature() 
{
  if (_temperatureColor>0) {                   // Als TemperatureColor is gedefinieerd
    _setColor(_temperatureColor);             // Visualiseer de gedefinieerde kleur op de RGB LED
  }   

  delay(1000);

  Temperature = mySensor.readTemperature(); // Lees de temperatuur data van de sensor en sla het op in Temperature
  Serial.print("Temperature: ");
  Serial.println(Temperature);
  if (_temperatureColor>0) {                   // Als TemperatureColor is gedefinieerd
    _setColor(_ledOff);                     // Zet de RGB LED uit
  }
}


void Sniffy::measureHumidity()
{
  if (_humidityColor>0) {                      // Als HumidityColor is gedefinieerd
    _setColor(_humidityColor);                // Visualiseer de gedefinieerde kleur op de RGB LED
  }

  Humidity = mySensor.readHumidity();       // Lees de luchtvochtigheid data van de sensor en sla het op in Humidity
  Serial.print("Humidity: ");
  Serial.println(Humidity);

  if(_humidityColor>0) {                      // Als HumidityColor is gedefinieerd
    _setColor(_ledOff);                     // Zet de RGB LED uit
  }  
}


void Sniffy::measureTemperatureContinuously()
{
  uint32_t tC;

  if(_temperatureColor==0) {  // Als TemperatureColor niet is gedefinieerd
    tC = RGB.Color(255, 0, 0); // Definieer TemperatureColor als rood
  } else {
  	tC = _temperatureColor;
  }                                         
  
  #ifndef minTemperature      // Als minTemperature niet is gedefinieerd
    #define minTemperature 18 // Definieer mintemperature als 18 graden Celcius
  #endif                      
  
  #ifndef maxTemperature      // Als maxTemperature niet is gedefinieerd
    #define maxTemperature 28 // Definieer maxTemperature als 28 graden Celcius
  #endif                      

  int x = tC;         // Creëer variabel x en sla TemperatureColor er in op
  int arr[3] = {0};                 // Creëer een lege buffer array
  for (int i = 0; i < 3; i++) {     // Kleine lus op de 32 bit integer kleur op te splitsen in
    arr[i] = x & 0xFF;              // 3 kleuren en deze kleuren op te slaan in arr[]
    x = x >> 8;                     
  }
  
  Serial.println("Measuring temperature continuously.");
  Serial.println("LED color changes ...");

  float colorBrightness[3];                     // Creëer float array colorBrightness
  while(1) {                                    // Oneidige lus
    Temperature = mySensor.readTemperature();   // Lees de tempratuur waarde af en sla het op in Temperature
    for (int i = 0; i < 3; i++) {               // Bereken de helderheid
      colorBrightness[i] = (arr[i] / (maxTemperature - minTemperature)) * constrain(((Temperature) - minTemperature), 0, (maxTemperature-minTemperature));
    }
    int colorBrightnessTotal = ((int)colorBrightness[2] << 16)  + ((int)colorBrightness[1] << 8) + ((int)colorBrightness[0]); // Creëer een nieuwe 32 bit integer kleur waarde
    _setColor(colorBrightnessTotal);               // Visualiseer de nieuwe kleur op de RGB LED
    delay(5);
    yield();
  }
}

void Sniffy::measureHumidityContinuously()
{
  uint32_t tH;

  if(_humidityColor==0) {                         // Als HumidityColor niet is gedefinieerd
    tH = RGB.Color(0, 0, 255);  // Definieer HumidityColor als blauw
  } else {
  	tH = _humidityColor;
  }                  
  
  #ifndef minHumidity       // Als minHumidity niet is gedefinieerd
    #define minHumidity 40  // Definieer minHumidity als 40
  #endif                    
  
  #ifndef maxHumidity       // Als maxHumidity niet is gedefinieerd
    #define maxHumidity 80  // Definieer maxHumidity als 80
  #endif                    

  int x = tH;            // Creëer variabel x en sla HumidityColor er in op
  int arr[3] = {0};                 // Creëer een lege buffer array
  for (int i = 0; i < 3; i++) {     // Kleine lus op de 32 bit integer kleur op te splitsen in
    arr[i] = x & 0xFF;              // 3 kleuren en deze kleuren op te slaan in arr[]
    x = x >> 8;                     
  }
  
  Serial.println("Measuring humidity continuously.");
  Serial.println("LED color changes ...");

  float colorBrightness[3];             // Creëer float array colorBrightness
  while(1) {                            // Oneindige lus
    Humidity = mySensor.readHumidity(); //  Lees de luchtvochtigheid waarde af en sla het op in Humidity
    for (int i = 0; i < 3; i++) {       // Bereken de helderheid
      colorBrightness[i] = (arr[i] / (maxHumidity - minHumidity)) * constrain(((Humidity) - minHumidity), 0, (maxHumidity-minHumidity));
    }
    int colorBrightnessTotal = ((int)colorBrightness[2] << 16)  + ((int)colorBrightness[1] << 8) + ((int)colorBrightness[0]); // Creëer een nieuwe 32 bit integer kleur waarde
    _setColor(colorBrightnessTotal);               // Visualiseer de nieuwe kleur op de RGB LED
    delay(5);
    yield();
  }
}

void Sniffy::rainbow(uint8_t loops)
{
   digitalWrite(RGBPowerSupply,HIGH);
   for (uint16_t j = 0; j < 256 * loops; j++) {  // Lus die 256*loops keer loopt
     RGB.setPixelColor(0, _cycle(j & 255));       // Stel RGB pixel naar de juiste waarde. Krijgt de waarde van de functie Cycle
     RGB.show();                                 // Visualiseer de nieuwe kleur op de RGB LED
     delay(50);
     yield();
   }
   _setColor(_ledOff); // Stel de RGB pixel kleur in op de correcte waarde   
}

void Sniffy::setLEDColor(uint8_t r,uint8_t g,uint8_t b)
{
   _setColor(RGB.Color(r,g,b)); // Stel de RGB pixel kleur in op de correcte waarde
}

void Sniffy::_setColor(uint32_t color)
{
   RGB.setPixelColor(0, color); // Stel de RGB pixel kleur in op de correcte waarde
   RGB.show();                  // Visualiseer de nieuwe kleur op de RGB LED
   delay(50); 
}


void Sniffy::setTemperatureColor(uint8_t r, uint8_t g, uint8_t b)
{
	_temperatureColor = RGB.Color(r,g,b);
}


void Sniffy::setHumidityColor(uint8_t r, uint8_t g, uint8_t b)
{
	_humidityColor = RGB.Color(r,g,b);
}


void Sniffy::setWifiColor(uint8_t r, uint8_t g, uint8_t b)
{
	_wifiColor = RGB.Color(r,g,b);
}


void Sniffy::connectWifi(char* s, char* p)
{
  _ssid = s;
  _password = p;

  if(strcmp(_ssid, "XXXX") == 0 || strcmp(_password, "XXXX") == 0 ) {  // Als WiFi parameters niet zijn gegeven
      Serial.println("Geen ssid of password ingevuld.");           // Debug Seriële Print: Print tekst om duidelijk te maken dat parameters ontbreken
  }
  else{                      // Als WiFi parameters zijn gegeven
    if(_wifiColor>0) {       // Als WiFiColor is gedefinieerd
      _setColor(_wifiColor);  // Visualiseer de gedefinieerde kleur op de RGB LED
    }

    if (WiFi.status() != WL_CONNECTED) {        // Als Sniffy nog niet is verbonden met WiFi
      Serial.println("");                   // Debug Seriële Print: Print een lege regel voor helderheid
      Serial.print("Verbinden met: ");      // Debug Seriële Print: Print tekst voor helderheid
      Serial.println(_ssid);              // Debug Seriële Print: Print de netwerk naam (SSID)
  
      int retries = 0;
      int MAX_RETRIES = 50;

      WiFi.begin(_ssid, _password);    
                                       // Start het proberen te verbinden metWiFi
      while (WiFi.status() != WL_CONNECTED && (++retries < MAX_RETRIES)) {  // Lus om te zorgen dat de WiFi connectie verbinding paar keer geprobeerd wordt
        delay(500);                                                           // Kleine wachttijd zodat de seriële monitor niet vol raakt met tekst
        Serial.println("Bezig te verbinden ...");                                // Debug Seriële Print: Laat zien wat er gebeurt
        yield();
      }

      if (retries >= MAX_RETRIES) {                   // Als de waarde van retries groter dan of gelijk aan MAX_Retries is
        Serial.print("Kon niet verbinden met: "); // Debug Seriële Print: Toon status
        Serial.println(_ssid);                  // Debug Seriële Print: Print de naam van het Wifi toegangspunt
      } else {      
        Serial.print("Verbonden met: ");        // Debug Seriële Print: Toon status
        Serial.println(_ssid);                // Debug Seriële Print: Print de naam van het Wifi toegangspunt
        Serial.print("Ip: ");                   // Debug Seriële Print: Toon status
        Serial.println(WiFi.localIP());         // Debug Seriële Print: Print het netwerk IP adres
      }
    }
    else                                        // Als Sniffy al is verbonden met WiFi
    {
      Serial.println("Reeds verbonden.");  // Debug Seriële Print: Toon status
    }
    
    if(_wifiColor>0) {     // Als WiFiColor is gedefinieerd
      _setColor(_ledOff);   // Zet de RGB LED uit
    }                 
  } 
}


void Sniffy::disconnectWifi()
{
  if (WiFi.status() == WL_CONNECTED){                         // Als Sniffy is verbonden met WiFi
    WiFi.mode(WIFI_OFF);                                      // Verbreek verbinding met WiFi
    Serial.println("WiFi verbinding verbroken.");            // Debug Seriële Print: Toon status 
  }
  else{                                                       // Als Sniffy niet is verbonden met WiFi 
    Serial.println("Sniffy was niet verbonden met WiFi.");   // Debug Seriële Print: Toon status
  }
}


bool Sniffy::_connectThingSpeak()
{
  if (WiFi.status() == WL_CONNECTED) {                    // Als Sniffy is verbonden met WiFi
    if (client.connect("api.thingspeak.com", 80)) {       // Probeer te verbinden met ThingsSpeak.
      Serial.println("Verbonden met ThingSpeak.");    // Debug Seriële Print: Prints bevestiging dat Sniffy is verbonden met ThingSpeak
      return true;
    }     
                                                    // Als Sniffy niet kon verbinden met ThingSpeak
    Serial.println("Kon niet verbinden met ThingSpeak.");  // Debug Seriële Print: Toon status
    return false; 
  } 
                                                         // Als Sniffy niet is verbonden met WiFi
  Serial.println("Sniffy is niet verbonden met WiFi en kan daardoor ook niet verbinden met de ThingSpeak server."); // Debug Seriële Print: Toon status
  return false;
}


void Sniffy::sendDataToThingSpeak(char* k)
{
  if (!_connectThingSpeak())
    return;

  _writeAPIKey = k;

  if(client.connected()) {                                    // Als Sniffy is verbonden met ThingSpeak
    if(_writeAPIKey != "XXXX"){  // Als een writeAPIKey is opgegeven
      String url = "field1=";                                 // Creëer een string met de meetwaarden
      url += String(Temperature);                             
      url += "&field2=";
      url += String(Humidity);
      
      client.print("POST /update HTTP/1.1\n");                // Verstuur de string naar de juiste locatie 
      client.print("Host: api.thingspeak.com\n");             
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + _writeAPIKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(url.length());
      client.print("\n\n");
      client.print(url);
      client.print("\n\n");
      delay(500);                                                     // Kleine wachttijd voor optimalisatie
    }
    else {                                                            // Als een channelID en writeAPIKey niet zijn opgegeven
      Serial.println("Geen writeAPIKey ingevuld.");  // Debug Seriële Print: Toon status
    }
    _disconnectThingSpeak();
  } 
  else {                                                           // Als Sniffy niet is verbonden met de ThingSpeak server
     Serial.println("Sniffy kon niet verbinden met ThingSpeak en kan daardoor geen data op ThingSpeak plaatsen."); // Debug Seriële Print: Toon status
  }
}


void Sniffy::_disconnectThingSpeak()
{
  if(client.connected()){                                           // Als Sniffy is verbonden met ThingSpeak 
    client.stop();                                                  // Verbreek verbinding met ThingSpeak
    Serial.println("Verbinding met ThingSpeak verbroken.");      // Debug Seriële Print: Print bevestiging dat de verbinding is verbroken
  }
  else{                                                             // Als Sniffy niet is verbonden met ThingSpeak
    Serial.println("Sniffy was niet verbonden met ThingSpeak."); // Debug Seriële Print: Toon status
  }
}


void Sniffy::sleep(int sleepTime)
{
  if(client.connected())            {_disconnectThingSpeak();} // Als Sniffy is verbonden met de ThingSpeak network -> Verbreek de verbinding
  if(WiFi.status() == WL_CONNECTED) {disconnectWifi();      } // Als Sniffy is verbonden met de WiFi network -> Verbreek de verbinding
  _setColor(_ledOff);
  digitalWrite(RGBPowerSupply, LOW);     // Maak D6 uitgang hoog (5V)
  digitalWrite(SensorPowerSupply, LOW);  // Maak D6 uitgang hoog (5V)
                                         // Zet de RGB LED uit
  Serial.print("Going to sleep for ");
  Serial.print(sleepTime);
  Serial.println(" seconds.");
  delay(5);
  ESP.deepSleep(sleepTime * 1000000); 
}


// private methods

uint32_t Sniffy::_cycle(uint8_t wheelPos)
{
  if (wheelPos < 85) {
    return RGB.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
  } else if (wheelPos < 170) {
    wheelPos -= 85;
    return RGB.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  } else {
    wheelPos -= 170;
    return RGB.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
}

