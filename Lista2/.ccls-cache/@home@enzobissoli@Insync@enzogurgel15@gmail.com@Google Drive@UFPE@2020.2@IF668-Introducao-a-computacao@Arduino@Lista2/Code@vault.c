#include <Arduino.h>
#include <HardwareSerial.h>

int pinState = 0;
int leitura = 0;
void ledState(int green, int red);

void setup(void) {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  ledState(0, 1);
  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(A0);
  if (leitura != pinState) {
    Serial.println(leitura, DEC);
    pinState = leitura;
  }
  if (analogRead(A0) == 552) {
    ledState(1, 0);
  } else
    ledState(0, 1);
}

void ledState(int green, int red) {
  green == 1 ? digitalWrite(3, HIGH) : digitalWrite(3, LOW);
  red == 1 ? digitalWrite(4, HIGH) : digitalWrite(4, LOW);
}
