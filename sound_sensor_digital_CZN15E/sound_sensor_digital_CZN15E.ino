byte readPin = 2; // digitalRead pin
<<<<<<< HEAD
unsigned long maxSample = 750; // no sound in [maxSample]ms? function will return totalTime
=======
unsigned long maxSample = 1500; // no sound in [maxSample]ms? function will return totalTime
>>>>>>> 7da941ae5719c9b45bd40ddf77f9ad1928607f04


void setup() {
  Serial.begin(9600); // init serial
  pinMode(readPin, INPUT);
}


unsigned long recordingTime(unsigned long timeOut)
{
  unsigned long currentTime = millis(); // get current time
  unsigned long totalTime = 0 ; // init total time recorded

  while (totalTime < timeOut) // if timeOut reached
  {
    if (digitalRead(readPin) == LOW) // sensor detects sound
    {
      totalTime = totalTime + millis() - currentTime;
      currentTime = millis();
    }

    if (millis() - currentTime > maxSample) // [maxSample]ms have passed and no sound detected
    {
      return totalTime;
    }
  }
  return timeOut;
}

void loop() {
  Serial.println(recordingTime(10000));
}
