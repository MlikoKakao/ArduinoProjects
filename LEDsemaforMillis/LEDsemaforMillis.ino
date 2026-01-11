const int leds[] = {8, 9, 10, 11, 12, 13}; // 0,1 = green; 2,3 = yellow; 4,5 = red
const int ledCount = 6;
const long LEDDuration = 1000;
unsigned long previous_time = 0;

void setup() {
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }

}

void loop() {
  unsigned long current_time = millis();
  if (current_time - previous_time >= LEDDuration)
  {
    previous_time = current_time;
    if (digitalRead(leds[4]) == HIGH)
    {
      allOff();
      yellowOn();
    }
    else if (digitalRead(leds[3]) == HIGH)
    {
      allOff();
      greenOn();
    }
    else
    {
      allOff();
      redOn();
    }
  }
}

void redOn()
{
  digitalWrite(leds[4], HIGH);
  digitalWrite(leds[5], HIGH);
}


void yellowOn()
{
  digitalWrite(leds[3], HIGH);
  digitalWrite(leds[2], HIGH);
}


void greenOn()
{
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
}

int allOff()
{
  for (int i = 0; i < ledCount; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}