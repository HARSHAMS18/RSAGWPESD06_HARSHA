#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
unsigned long startTime = 0;
bool running = false;
const int startStopButton = 8;
const int resetButton = 9;

void setup() {
  pinMode(startStopButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
  lcd.begin(16, 2);
  lcd.print("Stopwatch: ");
}

void loop() {
  if (digitalRead(startStopButton) == LOW) {
    delay(200); // Debounce delay
    running = !running;
    if (running) startTime = millis();
  }

  if (digitalRead(resetButton) == LOW) {
    delay(200); // Debounce delay
    startTime = 0;
    running = false;
  }

  if (running) {
    unsigned long elapsed = (millis() - startTime) / 1000;
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(elapsed);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print((startTime / 1000));
  }
}

