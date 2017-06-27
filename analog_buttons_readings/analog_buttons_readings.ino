#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // set up the LCD screen if present
int lastRead, currentRead;
int analogPin = 0; // the analog pin number where the buttons are connected

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  currentRead = analogRead(analogPin);
  if (currentRead > lastRead + 20 || currentRead < lastRead - 20) // the tolerance is set to 20
  {
    lcd.clear();
    lcd.print(currentRead);
    Serial.println(currentRead);
    lastRead = currentRead;
  }
}
