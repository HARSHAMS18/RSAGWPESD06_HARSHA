#include <SevSeg.h>

SevSeg sevseg;
const int trigPin = 9;
const int echoPin = 10;
const int touchPin = 8;
int counter = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(touchPin, INPUT);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 11, 12, A0, A1, A2};
  bool resistorsOnSegments = true;
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 10) { // Adjust the threshold distance as needed
    counter++;
    delay(500);
  }

  if (digitalRead(touchPin) == HIGH) {
    counter = 0;
  }

  sevseg.setNumber(counter);
  sevseg.refreshDisplay();
  delay(100);
}
