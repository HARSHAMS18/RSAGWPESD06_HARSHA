#include <SevSeg.h>

SevSeg sevseg;
const int trigPin = 9;
const int echoPin = 10;
const int touchPin = 8;
long distance = 0;

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
  if (digitalRead(touchPin) == HIGH) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    sevseg.setNumber(distance);
    sevseg.refreshDisplay();
    delay(5000); // Hold for 5 seconds
    sevseg.blank();
  }
  delay(100);
}
