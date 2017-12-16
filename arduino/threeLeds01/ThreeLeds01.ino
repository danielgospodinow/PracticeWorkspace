int greenLed =13;
int yellowLed = 12;
int redLed = 11;

int counter = 0;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  if(counter<5)
  {
    digitalWrite(greenLed,HIGH); 
    delay(1000);
    digitalWrite(greenLed,LOW);
    delay(1000);
    counter +=1;
  }
  else if (counter >= 5 && counter < 10)
  {
    digitalWrite(yellowLed, HIGH);
    delay(1000);
    digitalWrite(yellowLed,LOW);
    delay(1000);
    counter +=1;
  }
  else
  {
    counter +=1;
    
    if(counter == 15)
    {
     counter = 0; 
    }
    
    digitalWrite(redLed,HIGH);
    delay(1000);
    digitalWrite(redLed,LOW); 
    delay(1000);
  }
}
