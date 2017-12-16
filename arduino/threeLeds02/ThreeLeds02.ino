int greenLed =11;
int yellowLed = 12;
int redLed = 13;

bool goodToGo = true;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  if(goodToGo)
  {
   turnLedON(greenLed, 4); 
   turnLedON(yellowLed, 1);
   goodToGo = false;
  }
  else 
  {
   digitalWrite(redLed, HIGH);
   delay(4000);
   digitalWrite(yellowLed,HIGH);
   delay(1000);
   digitalWrite(redLed,LOW);
   digitalWrite(yellowLed, LOW);
   goodToGo = true;
  }
}

void turnLedON(int led, int seconds)
{
  digitalWrite(led, HIGH);
  delay(seconds * 1000);
  digitalWrite(led,LOW);
  delay(150);
}
