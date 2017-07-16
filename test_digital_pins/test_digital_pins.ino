#import <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
byte pinNumber;
byte ignorePins[] = {4, 5, 6, 7, 8, 9, 10}; 
byte sizeOfIgnorePins;
unsigned long currentTime;
byte numberOfPins = 13;
bool print;


void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  pinNumber = 0;
  lcd.print("Current pin: ");
  sizeOfIgnorePins = sizeof(ignorePins);
}

void loop() {

  if (!isIgnored(pinNumber)) {
    currentTime = millis();
    print = true;
    while (millis() - currentTime < 1500) {
      digitalWrite(pinNumber, HIGH);
      if (digitalRead(pinNumber) != LOW) // reading stays low for 1.5 seconds?
      {
        print = false;
        break;
      }
    }
  }
  if (print)
  {
    lcd.setCursor(13, 0);
    lcd.print("  ");
    lcd.setCursor(13, 0);
    lcd.print(pinNumber);
  }
  pinNumber++;
  pinNumber %= numberOfPins;
}

bool isIgnored(byte pinNumber)
{
  for (byte i = 0; i < sizeOfIgnorePins ; i++)
  {
    if (pinNumber == ignorePins[i])
    {
      return true;
    }
  }
  return false;
}

