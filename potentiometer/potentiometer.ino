const int leds[] = {8, 9, 10, 11, 12, 13};
const int ledCount = 6;

int potPin = A1;
int potValue = 0;
int brightness = 0;
int tonePitch = 0;

const int buzzer = 7;

const int button = 6;

void allOn();
void allOff();
void chooseColor(int tone);

void setup() {
  pinMode(button, INPUT_PULLUP);
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  potValue = analogRead(potPin);
  brightness = map(potValue, 0, 1023, 0, 255);
  tonePitch = map(potValue, 0, 1023, 0, 600);
  tone(buzzer, tonePitch, 20);
  chooseColor(tonePitch);
  int randomTone = random(1, 600);
  if (digitalRead(button) == HIGH)
  {
    chooseColor(randomTone);
    tone(buzzer, randomTone, 200);
  }


  Serial.println(brightness);
}

void chooseColor(int tonePitch)
{
  allOff();
  if (tonePitch == 0)
  {
    allOn();
    delay(2000);
    allOff();
    delay(2000);
  }
  else if (tonePitch < 200)
  {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
  }
  else if (tonePitch <= 400)
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

void allOn()
{
  for (int i = 0; i < ledCount; i++) digitalWrite(leds[i], HIGH);
}