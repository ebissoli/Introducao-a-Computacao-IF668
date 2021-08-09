#include <Arduino.h>
void setup() {
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  int pressed = digitalRead(2);
  digitalWrite(13, HIGH * pressed);
  digitalWrite(11, HIGH * !pressed);
  delay(200);
}
