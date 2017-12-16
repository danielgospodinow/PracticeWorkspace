unsigned long startTime;
unsigned long currentTime;

void setup() 
{
  pinMode(13, OUTPUT);
  startTime = millis();
}

void loop() 
{
  currentTime = millis();
  if(currentTime - startTime > 1000)
  {
    manipulateCar('r');
    return;
  }
}

void manipulateCar(char command)
{
  switch(command)
  {
    case 'r':
      invokeRelay('r');
      startTime = millis();
    default: break;
  }
}

void invokeRelay(char relay)
{
  manipulateRelay(relay, HIGH);
  delay(1500);
  manipulateRelay(relay, LOW);
}

void manipulateRelay(char relay, bool state)
{
  switch(relay)
  {
    case 'r': digitalWrite(13, state); break;
    default: break;
  }
}
