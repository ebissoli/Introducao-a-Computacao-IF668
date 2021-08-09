#include <Arduino.h>
#include <HardwareSerial.h>
#include <Print.h>
#include <Stream.h>

char leitura = 0;

void ledSetup(int first, int second, int third) {
  first == 1 ? digitalWrite(13, HIGH) : digitalWrite(13, LOW);
  second == 1 ? digitalWrite(12, HIGH) : digitalWrite(12, LOW);
  third == 1 ? digitalWrite(11, HIGH) : digitalWrite(11, LOW);
}
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  ledSetup(1, 1, 1);
}

void loop() {
  if (Serial.available()) {
    leitura = Serial.read();
    Serial.println(leitura);
    switch (leitura) {
    case '0':
      ledSetup(1, 0, 0);
      break;
    case '1':
      ledSetup(0, 1, 0);
      break;
    case '2':
      ledSetup(0, 0, 1);
      break;
    default:
      ledSetup(0, 0, 0);
    }
  }
}
