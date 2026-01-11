const int leds[] = {8, 9, 10, 11, 12, 13};
int LED_state = LOW;
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
  if (current_time - previous_time >= LED_Duration)
  {
    previous_time = current_time;
    if (LED_state == LOW)
    {
      LED_state = HIGH;
    }
    else
    {
      LED_state = LOW;
    }
    all(LED_state);
  }
  
                                              
}

void all(int state)
{
  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], state);
  }
}

void allOn()
{
  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], HIGH);
  }
}

void allOff()
{
  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}