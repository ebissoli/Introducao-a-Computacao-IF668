#include "Tone.cpp"
#include <Arduino.h>

volatile byte previousState = LOW;
void pinInterrupt() { previousState = HIGH; }

void state(int PRESSED) {
  PRESSED ? tone(10, 1000) : noTone(10);
  PRESSED ? delay(2000) : delay(0);
}

void setup() {
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), pinInterrupt, CHANGE);
}

void loop() {
  if (digitalRead(2)) {
    state(1);
  } else
    state(0);
}
