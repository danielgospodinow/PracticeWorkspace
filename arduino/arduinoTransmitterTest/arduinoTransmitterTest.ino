#include <VirtualWire.h>

const char* TRANSMIT_MESSAGE = "Opi";
const int TX_TRANSMITTER_PIN = 12;
const int TX_BIT_PER_SEC = 4000;
const int TRANSMIT_DELAY = 200;

void setup() 
{
  init_vw();
  
  pinMode(13,OUTPUT);
}

void loop() 
{
  send(TRANSMIT_MESSAGE);
  delay(TRANSMIT_DELAY);
}

void send(const char* message)
{
  vw_send((uint8_t*) message, strlen(message));
  digitalWrite(13,HIGH);
  vw_wait_tx();
  digitalWrite(13,LOW);
}

void init_vw()
{
  vw_set_tx_pin(TX_TRANSMITTER_PIN);
  vw_set_ptt_inverted(true);
  
  vw_setup(TX_BIT_PER_SEC);
}
