const int pirPin = 8;
const int buzzerPin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Motion Detected!");
    delay(1000); // Log timestamp every second
  } else {
    digitalWrite(buzzerPin, LOW);
  }
}
