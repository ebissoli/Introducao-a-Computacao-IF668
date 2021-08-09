#include <Arduino.h>
/* void state(int RED, int GREEN, int BLUE, int wait); */
/* void pinInterrupt(); */
volatile byte previousState = LOW;
void pinInterrupt() { previousState = HIGH; }

void state(int RED, int GREEN, int BLUE, int wait) {
  analogWrite(A5, RED);
  analogWrite(A4, GREEN);
  analogWrite(A3, BLUE);
  delay(wait);
}

void setup() {
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), pinInterrupt, CHANGE);
}

void loop() {
  if (previousState == HIGH) {
    state(0, 255, 0, 1000);
    state(255, 255, 0, 1000); // amarelo
    state(255, 0, 0, 1000);
    previousState = LOW;
  } else {
    state(0, 255, 0, 2000);
    state(255, 255, 0, 2000);
    state(255, 0, 0, 2000);
  }
}
