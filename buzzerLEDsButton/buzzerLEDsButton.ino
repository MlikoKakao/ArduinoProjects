const int leds[] = {8, 9, 10, 11, 12, 13};
const int ledCount = 6;

const int buzzer = 7;
int noteDuration = 850;
int noteDelay = 850;

const int button = 6;
bool lastReading = HIGH;
bool buttonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 20;

void chooseColor(int tone);
void allOff();

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  allOff();
  randomSeed(analogRead(A0));
}

void loop() {
  bool reading = digitalRead(button);

  if (reading != lastReading)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;

      if (buttonState == LOW)
      {
        int randomTone = random(1, 600);
        chooseColor(randomTone);
        tone(buzzer, randomTone, noteDuration);
        
        delay(noteDuration);
        allOff();
        noTone(buzzer);
        }
      }
    }
  lastReading = reading;
}


void chooseColor(int tone)
{
  allOff();
  if (tone < 200)
  {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
  }
  else if (tone <= 400)
  {
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
  }
  else
  {
    digitalWrite(leds[4], HIGH);
    digitalWrite(leds[5], HIGH);
  }
}

void allOff()
{
  for (int i = 0; i < ledCount; i++) digitalWrite(leds[i], LOW);
}



