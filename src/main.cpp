#include <Arduino.h>
#include <SoftwareSerial.h>

const int TX = 3;
const int RX = 4;
const int SPEED = 9600;

SoftwareSerial softSerial(TX, RX);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(9600);
  softSerial.begin(SPEED);
  Serial.println("Serial bridge initialzed!");
  char buffer[25];
  sprintf(buffer, "RX=%i TX=%i SPEED=%i\n", RX, TX, SPEED);
  Serial.println("Ready!");
  Serial.print(buffer);

  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{

  if (Serial.available())
  {
    digitalWrite(LED_BUILTIN, HIGH);
    softSerial.write(Serial.read());
    digitalWrite(LED_BUILTIN, LOW);
  }

  if (softSerial.available())
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.write(softSerial.read());
    digitalWrite(LED_BUILTIN, LOW);
  }
}