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
  sprintf(buffer, "RX=%i TX=%i SPEED=%i", RX, TX, SPEED);
  Serial.print(buffer);

  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{

  if (Serial.available())
  {
    softSerial.write(Serial.read());
  }

  if (softSerial.available())
  {
    Serial.write(softSerial.read());
  }
}