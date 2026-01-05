const int leds[] = {8, 9, 10, 11, 12, 13};
const int ledCount = 6;


#include "DHT.h"
#define DHT11_PIN 2

DHT dht11(DHT11_PIN, DHT11);
float lastTempC;
float tempC;

void setup() {
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
  dht11.begin();
  lastTempC = dht11.readTemperature();
}

void loop() {
  // wait a few seconds between measurements.
  delay(2000);
  // read humidity
  float humi  = dht11.readHumidity();
  // read temperature as Celsius
  tempC = dht11.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    if (lastTempC > tempC)
    {
      digitalWrite(leds[5], HIGH);
      digitalWrite(leds[4], HIGH);
    }
    else if (lastTempC < tempC)
    {
      digitalWrite(leds[0], HIGH);
      digitalWrite(leds[1], HIGH);
    }
    else if (lastTempC == tempC)
    {
      digitalWrite(leds[2], HIGH);
      digitalWrite(leds[3], HIGH);
    }

    Serial.print("DHT11# Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
    
  }
}


void allOff()
{
  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}
