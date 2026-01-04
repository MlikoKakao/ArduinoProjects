const int leds[] = {8, 9, 10, 11, 12, 13};
const int ledCount = 6;

int soundSensorDigital = 6;
int soundSensorAnalog = A0;
bool is_on = false;
int brightness = 0;

void allOff();
void allOn();

void setup() {
  for (int i = 0; i < ledCount; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(soundSensorDigital, INPUT);
  pinMode(soundSensorAnalog, INPUT);
  Serial.begin(9600);
}

void loop() {
  int soundDigitalReading = digitalRead(soundSensorDigital);
  int soundAnalogReading = analogRead(soundSensorAnalog);
  Serial.print("Analog Reading---");
  Serial.print(soundAnalogReading);
  Serial.print("Digital Reading---");
  Serial.print(soundDigitalReading);
  Serial.print("\n");
  delay(100);
  brightness = map(soundAnalogReading, 44, 55, 0, 255);
  allControl(brightness);
}


void allOff()
{
  for (int i = 0; i < ledCount; i++) digitalWrite(leds[i], LOW);
}

void allOn()
{
  for (int i = 0; i < ledCount; i++) digitalWrite(leds[i], HIGH);
}

void allControl(int brightness)
{
  for (int i = 0; i < ledCount; i++) digitalWrite(leds[i], brightness);
}