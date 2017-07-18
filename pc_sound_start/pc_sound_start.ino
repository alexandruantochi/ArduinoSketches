#import <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte onPin = 2;
byte soundPin = 3;
byte checkPC = A1;
unsigned long currentTime;
bool runningDisplayed;
unsigned long requiredSoundLength;
unsigned long soundSample;

void setup() {
  lcd.begin(16, 2);
  pinMode(onPin, OUTPUT);
  digitalWrite(onPin, HIGH);
  lcd.print("PC OFF");
  runningDisplayed = false;
  requiredSoundLength = 450; //ms
  soundSample = 300; //ms
}

void loop() {
  if (digitalRead(soundPin == LOW) &&  !pcRunning())
  {
    if (recordingTime() >= requiredSoundLength)
    {
      triggered();
    }
  }
  if (!runningDisplayed)
  {
    if (pcRunning())
    {
      lcd.clear();
      lcd.print("PC RUNNING");
      runningDisplayed = true;
    }
  }
  if (runningDisplayed)
  {
    if(!pcRunning())
    {
      lcd.clear();
      lcd.print("PC OFF");
      runningDisplayed = false;
    }
  }

}


bool pcRunning()
{
  unsigned long checkTime = 10;
  currentTime = millis();
  while (millis() - currentTime < checkTime)
  {
    if (analogRead(checkPC) < 930)
    {
      return false;
    }
  }
  return true;
}


void triggered()
{
  lcd.clear();
  lcd.print("Starting PC...");
  digitalWrite(onPin, LOW);
  delay(100);
  digitalWrite(onPin, HIGH);
}


// check if after hearing a sound, the sound time is >= timeOut;
unsigned long recordingTime()
{
  currentTime = millis(); // get current time
  unsigned long totalTime = 0 ; // init total time recorded

  while (totalTime < requiredSoundLength) // if requiredSoundLength not reached
  {
    if (digitalRead(soundPin) == LOW) // sensor detects sound
    {
      totalTime = totalTime + millis() - currentTime;
      currentTime = millis();
    }

    if (millis() - currentTime > soundSample) // 300ms have passed and no sound detected
    {
      return totalTime;
    }
  }
  return requiredSoundLength+1;
}

