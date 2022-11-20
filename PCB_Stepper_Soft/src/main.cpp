#include <hal_conf_extra.h>
#include <STM32CAN.h>
#include <AccelStepper.h>
#include <TMCStepper.h>


#define STEP PA3
#define DIR PA2
#define SLP PA4
#define RST PA5
#define M2 PA6
#define M1 PA7
#define M0 PA8
#define EN PA9

#define LED PB7
#define ADD1 PB13
#define ADD2 PB14
#define ADD3 PB15

AccelStepper DRV8825(1, STEP, DIR);
CAN_message_t Transmit_msg;
CAN_message_t Received_msg;
uint8_t value_DIP;
uint16_t AddressCAN = 0x70; // Adresse de base de la carte stepper

void CheckAdress();
void InitStepper();
void setup()
{

  // Can1.begin(CAN_BPS_1000K);
  Serial.println("Init");
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
  Serial.println("value_Address=");
  CheckAdress();
  AddressCAN += value_DIP & 0x0F; // changement de l'adresse CAN correspondant a la valeur du DIP switch
  CheckDriver();
  InitStepper();
}

void loop()
{
  Serial.println(AddressCAN);
  delay(100);
}

void CheckAdress()
{
  pinMode(ADD1, INPUT);
  pinMode(ADD2, INPUT);
  pinMode(ADD3, INPUT);
  value_DIP = (bool)(digitalRead(ADD1) & 0x1) + ((bool)(digitalRead(ADD2) & 0x1) << 1) + ((bool)(digitalRead(ADD3) & 0x1) << 2);
  Serial.println(value_DIP);
}
void InitStepper()
{
   pinMode(RST, OUTPUT); // le reset se fait a l'état bas
   digitalWrite(RST, HIGH);

   pinMode(SLP, OUTPUT);
   digitalWrite(SLP, HIGH);

   pinMode(EN, OUTPUT);
   digitalWrite(EN, LOW);
}
