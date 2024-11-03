#include <SevSeg.h>

SevSeg sevseg;
const int irSensor1 = 8;
const int irSensor2 = 9;
const int trigPin = 10;
const int echoPin = 11;
int peopleCount = 0;

void setup() {
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 12, A0, A1, A2, A3};
  bool resistorsOnSegments = true;
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
}

void loop() {
  if (digitalRead(irSensor1) == HIGH) {
    delay(100); // Debounce delay
    if (digitalRead(irSensor2) == HIGH) {
      peopleCount++;
    }
  } else if (digitalRead(irSensor2) == HIGH) {
    delay(100); // Debounce delay
    if (digitalRead(irSensor1) == HIGH) {
      peopleCount--;
    }
  }

  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  // You can add logic for direction detection using the ultrasonic sensor here
  sevseg.setNumber(peopleCount);
  sevseg.refreshDisplay();
  delay(100);
}
