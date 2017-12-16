#include <VirtualWire.h>

const int gotOkMessage = 2;
const int gotNoOkMessage = 4;
const unsigned int RX_RECIEVER_PIN = 12;
const unsigned int RX_BIT_PER_SEC = 4000;
const char* EXPECTED_MESSAGE = "Opi";

unsigned long lastMessage = 0;
unsigned long currentMessage = 0;

void setup() 
{  
  Serial.begin(9600);
  
  pinMode(gotOkMessage, OUTPUT);
  pinMode(gotNoOkMessage, OUTPUT);
  pinMode(13, OUTPUT);
  
  init_vw();
}

void loop() 
{
  uint8_t bufLen = VW_MAX_MESSAGE_LEN;
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  
  if(vw_get_message(buf, &bufLen))
  {
    currentMessage = millis();
    Serial.print((currentMessage - lastMessage) / 1000);
    Serial.println(" sec");
    lastMessage = currentMessage;
      
    digitalWrite(13,HIGH);
    delay(50);
    digitalWrite(13,LOW);
  }
}

void init_vw()
{
  vw_set_rx_pin(RX_RECIEVER_PIN);
  vw_set_ptt_inverted(true);

  vw_setup(RX_BIT_PER_SEC);
  vw_rx_start();
}

bool areStrEqual(const char* str01, const uint8_t* str02, int str02Size)
{
    if(getStrLen(str01) != str02Size)
      return false;
    
    for(int i=0; i<str02Size; i++)
      if(str01[i] != (char) str02[i])
        return false;
    
    return true;
}

int getStrLen(const char* str)
{
    int len = 0;
    while(*str++)
        ++len;
    return len;
}
