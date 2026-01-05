const int leds[] = {8, 9, 10, 11, 12, 13};
const int ledCount = 6;
unsigned long previous_time = 0;
const long LED_Duration = 100;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

}

void loop() {
  unsigned long current_time = millis();
  if (current_time - previous_time >= LED_Duraion)
  
                                              
}

void allOn()
{
  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
}