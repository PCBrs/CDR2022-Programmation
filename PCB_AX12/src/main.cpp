#include <Arduino.h>
#include "AX12A.h"
#include "can.h"

#define DirectionPin (PA7)
#define BaudRate (1000000ul)

#define SERVO_1 2
#define SERVO_2 3
#define SERVO_3 11
#define SERVO_ARR_DROIT 6

#define POS_DEFAUT_AV_DROIT 512
#define POS_PRISE_AV_DROIT 163
#define POS_DEFAUT_AV_GAUCHE 117
#define POS_PRISE_AV_GAUCHE 401

#define POS_DEFAUT_ARR_DROIT 948
#define POS_PRISE_ARR_DROIT 690
#define POS_DEFAUT_ARR_GAUCHE 746
#define POS_PRISE_ARR_GAUCHE 1020


void setup() {

Serial1.setHalfDuplex();
	ax12a.begin(BaudRate, DirectionPin, &Serial1);
   


msg[3]=0x14;
MX_CAN_Init();
HAL_CAN_MspInit(&hcan);
delay(10);


}

void loop() {
	 HAL_CAN_AddTxMessage(&hcan, &Txheader, msg, &TxMailbox);
  	/*ax12a.move(SERVO_2, POS_DEFAUT_AV_DROIT);
	delay(1000);
	ax12a.move(SERVO_2, POS_PRISE_AV_DROIT);
	delay(1000);
	ax12a.move(SERVO_1, POS_DEFAUT_AV_GAUCHE);
	delay(1000);
	ax12a.move(SERVO_1, POS_PRISE_AV_GAUCHE);
	delay(1000);
	ax12a.move(SERVO_3, POS_DEFAUT_ARR_GAUCHE);
	delay(1000);
	ax12a.move(SERVO_3, POS_PRISE_ARR_GAUCHE);
	delay(1000);
	ax12a.move(SERVO_ARR_DROIT, POS_DEFAUT_ARR_DROIT);
	delay(1000);
	ax12a.move(SERVO_ARR_DROIT, POS_PRISE_ARR_DROIT);*/
	delay(100);
}