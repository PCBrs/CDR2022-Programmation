#include <hal_conf_extra.h>
#include <STM32CAN.h>

CAN_message_t Transmit_msg;
CAN_message_t Received_msg;

#define LED_TX PB0
#define LED_RX PB1

void setup()
{
  Can1.begin(CAN_BPS_1000K);
  delay(100);

  pinMode(LED_TX, OUTPUT);
  pinMode(LED_RX, OUTPUT);
  digitalToggle(LED_TX);
  digitalToggle(LED_RX);
  delay(50);
  digitalToggle(LED_TX);
  digitalToggle(LED_RX);
  delay(50);
  digitalToggle(LED_TX);
  digitalToggle(LED_RX);
  delay(50);
  digitalToggle(LED_TX);
  digitalToggle(LED_RX);
  delay(50);

  Transmit_msg.id = 0x105;
  Transmit_msg.dlc = 3;
  Transmit_msg.data.bytes[0] = 'P';
  Transmit_msg.data.bytes[1] = 0x1;
  Transmit_msg.data.bytes[2] = 0x1;
  Can1.write(Transmit_msg);
}

void loop()
{
  if (Can1.available())
  {
    digitalToggle(LED_RX);
    Can1.read(Received_msg);
    //Serial.printf("Adresse: %i   %i  %i  %i  %i  %i  %i  %i  %i", Received_msg.id, Received_msg.data.bytes[0], Received_msg.data.bytes[1], Received_msg.data.bytes[2], Received_msg.data.bytes[3], Received_msg.data.bytes[4], Received_msg.data.bytes[5], Received_msg.data.bytes[6], Received_msg.data.bytes[7]);
    //Serial.println();
  }

  Can1.write(Transmit_msg);
  delay(500);
  Transmit_msg.data.bytes[2] = 0x0;
  Can1.write(Transmit_msg);
  delay(500);
  Transmit_msg.data.bytes[2] = 0x1;
  
}
