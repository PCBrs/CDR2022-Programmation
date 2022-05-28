/*
 * uart_lib.cpp
 *
 *  Created on: Nov 6, 2020
 *      Author: reon
 */

#include <uart_lib.h>

void Uart::begin(UART_HandleTypeDef *huart)
{
	phuart = huart;
}

unsigned char Uart::getc()
{
	unsigned char data[1] = {0};
	HAL_UART_Receive(phuart, data, 1, 1000);
	return data[0];
}

void Uart::putc(unsigned char put_data)
{
	unsigned char data[1] = {0};
	data[0] = put_data;
	HAL_UART_Transmit(phuart, data, 1, 1000);
}
