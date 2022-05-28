/*
 * uart_lib.h
 *
 *  Created on: Nov 6, 2020
 *      Author: reon
 */

#ifndef INC_UART_LIB_H_
#define INC_UART_LIB_H_

#include "main.h"

class Uart
{
public:
	void begin(UART_HandleTypeDef *huart);
	unsigned char getc();
	void putc(unsigned char data);

private:
	UART_HandleTypeDef* phuart;
};
#endif /* INC_UART_LIB_H_ */
