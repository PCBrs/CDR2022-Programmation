#include <hal_conf_extra.h>
#include <STM32CAN.h>

#define LED PB15

#define P1 PA0
#define V1 PA1
#define P2 PA2
#define V2 PA3
#define P3 PA4
#define V3 PA5
#define P4 PA6
#define V4 PA7
#define P5 PB0
#define V5 PB1
#define P6 PA8
#define V6 PA9
#define P7 PA10
#define V7 PA11
#define P8 PA15
#define V8 PB3
#define P9 PB4
#define V9 PB5
#define P10 PB6
#define V10 PB7

CAN_message_t Transmit_msg;
CAN_message_t Received_msg;

void InitPump();
void CtrPump(uint8_t Pump, uint8_t State);
void CtrValve(uint8_t Valve, uint8_t State);
void Test();
void Off();
void setup()
{
  Can1.begin(CAN_BPS_1000K);
  delay(10);
  // Indication du démarrage du lidar et du can par un clignotement de la LED
  pinMode(LED, OUTPUT);
  digitalToggle(LED);
  delay(50);
  digitalToggle(LED);
  delay(50);
  digitalToggle(LED);
  delay(50);
  digitalToggle(LED);
  delay(50);
  digitalWrite(LED, HIGH);
  InitPump();
}

void loop()
{
  if (Can1.available())
  {
    Can1.read(Received_msg);
    switch (Received_msg.id)
    {
    case 0x101:
      Transmit_msg.id = 0x701;
      Transmit_msg.data.bytes[0] = 0x700;
      Can1.write(Transmit_msg);
      break;
    case 0x102:
      Off();
      break;
    case 0x105:
      if (Received_msg.data.bytes[0] == 'P')
      {
        CtrPump(Received_msg.data.bytes[1], Received_msg.data.bytes[2]);
      }
      if (Received_msg.data.bytes[0] == 'V')
      {
        CtrValve(Received_msg.data.bytes[1], Received_msg.data.bytes[2]);
      }
      break;
    }
  }
  Transmit_msg.id = 0x701;
  Transmit_msg.data.bytes[0] = 0x70;
  Can1.write(Transmit_msg);
  delay(500);
}

void InitPump()
{
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(P4, OUTPUT);
  pinMode(P5, OUTPUT);
  pinMode(P6, OUTPUT);
  pinMode(P7, OUTPUT);
  pinMode(P8, OUTPUT);
  pinMode(P9, OUTPUT);
  pinMode(P10, OUTPUT);

  pinMode(V1, OUTPUT);
  pinMode(V2, OUTPUT);
  pinMode(V3, OUTPUT);
  pinMode(V4, OUTPUT);
  pinMode(V5, OUTPUT);
  pinMode(V6, OUTPUT);
  pinMode(V7, OUTPUT);
  pinMode(V8, OUTPUT);
  pinMode(V9, OUTPUT);
  pinMode(V10, OUTPUT);
}
void CtrPump(uint8_t Pump, uint8_t State)
{
  switch (Pump)
  {
  case 1:
    if (State)
    {
      digitalWrite(P1, HIGH);
    }
    else
    {
      digitalWrite(P1, LOW);
    }
    break;
  case 2:
    if (State)
    {
      digitalWrite(P2, HIGH);
    }
    else
    {
      digitalWrite(P2, LOW);
    }
    break;
  case 3:
    if (State)
    {
      digitalWrite(P3, HIGH);
    }
    else
    {
      digitalWrite(P3, LOW);
    }
    break;
  case 4:
    if (State)
    {
      digitalWrite(P4, HIGH);
    }
    else
    {
      digitalWrite(P4, LOW);
    }
    break;
  case 5:
    if (State)
    {
      digitalWrite(P5, HIGH);
    }
    else
    {
      digitalWrite(P5, LOW);
    }
    break;
  case 6:
    if (State)
    {
      digitalWrite(P6, HIGH);
    }
    else
    {
      digitalWrite(P6, LOW);
    }
    break;
  case 7:
    if (State)
    {
      digitalWrite(P7, HIGH);
    }
    else
    {
      digitalWrite(P7, LOW);
    }
    break;
  case 8:
    if (State)
    {
      digitalWrite(P8, HIGH);
    }
    else
    {
      digitalWrite(P8, LOW);
    }
    break;
  case 9:
    if (State)
    {
      digitalWrite(P9, HIGH);
    }
    else
    {
      digitalWrite(P9, LOW);
    }
    break;
  case 10:
    if (State)
    {
      digitalWrite(P10, HIGH);
    }
    else
    {
      digitalWrite(P10, LOW);
    }
    break;
  }
}
void CtrValve(uint8_t Valve, uint8_t State)
{
  switch (Valve)
  {
  case 1:
    if (State)
    {
      digitalWrite(V1, HIGH);
    }
    else
    {
      digitalWrite(V1, LOW);
    }
    break;
  case 2:
    if (State)
    {
      digitalWrite(V2, HIGH);
    }
    else
    {
      digitalWrite(V2, LOW);
    }
    break;
  case 3:
    if (State)
    {
      digitalWrite(V3, HIGH);
    }
    else
    {
      digitalWrite(V3, LOW);
    }
    break;
  case 4:
    if (State)
    {
      digitalWrite(V4, HIGH);
    }
    else
    {
      digitalWrite(V4, LOW);
    }
    break;
  case 5:
    if (State)
    {
      digitalWrite(V5, HIGH);
    }
    else
    {
      digitalWrite(V5, LOW);
    }
    break;
  case 6:
    if (State)
    {
      digitalWrite(V6, HIGH);
    }
    else
    {
      digitalWrite(V6, LOW);
    }
    break;
  case 7:
    if (State)
    {
      digitalWrite(V7, HIGH);
    }
    else
    {
      digitalWrite(V7, LOW);
    }
    break;
  case 8:
    if (State)
    {
      digitalWrite(V8, HIGH);
    }
    else
    {
      digitalWrite(V8, LOW);
    }
    break;
  case 9:
    if (State)
    {
      digitalWrite(V9, HIGH);
    }
    else
    {
      digitalWrite(V9, LOW);
    }
    break;
  case 10:
    if (State)
    {
      digitalWrite(V10, HIGH);
    }
    else
    {
      digitalWrite(V10, LOW);
    }
    break;
  }
}
void Test()
{
  for (uint8_t i = 1; i <= 10; i++)
  {
    CtrPump(i, 1);
    CtrValve(i, 1);
    delay(500);
    CtrPump(i, 0);
    CtrValve(i, 0);
  }
}
void Off()
{
  for (uint8_t i = 1; i <= 10; i++)
  {
    CtrPump(i, 0);
    CtrValve(i, 0);
  }
}