/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Firmware for the pump board v1 (v2 tbr)
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
CAN_TxHeaderTypeDef Txheader;
CAN_RxHeaderTypeDef Rxheader;
uint32_t Txmailbox;
uint8_t Rxmsg[8];
uint8_t Txmsg[8];
uint8_t msg[8];
uint8_t tstmsg[4]={0x1,0x2,0x3,0x4};
CAN_FilterTypeDef filter;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void conf_filter(void);
void TogglePump(uint16_t pin,uint16_t state);
void ToggleValve(uint16_t pin,uint16_t state);
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  
  /* USER CODE BEGIN 2 */
  conf_filter();
  //HAL_CAN_AddTxMessage(&hcan,&Txheader,tstmsg,&Txmailbox);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1)
	{
	//Waiting for interruption on the Canbus
    /* USER CODE END WHILE */
	//HAL_CAN_AddTxMessage(&hcan,&Txheader,tstmsg,&Txmailbox);
// 	HAL_CAN_GetRxMessage(&hcan, CAN_FILTER_FIFO1, &Rxheader,Rxmsg);
// 	uint8_t msg[8];
// 	msg[0]=Rxmsg[0];
// 	msg[1]=Rxmsg[1];
// 	msg[2]=Rxmsg[2];
// 	msg[3]=Rxmsg[3];
// 	msg[4]=Rxmsg[4];
// 	msg[5]=Rxmsg[5];
// 	msg[6]=Rxmsg[6];
// 	msg[7]=Rxmsg[7];
// 	if(msg[0]=='P'&&msg[1]=='b')
// 		TogglePump(msg[2],msg[3]);
// 	if(msg[0]=='V'&&msg[1]=='b')
// 		ToggleValve(msg[2], msg[3]);
// HAL_CAN_GetRxMessage(&hcan, CAN_FILTER_FIFO0, &Rxheader,Rxmsg);
// 	//uint8_t msg[8];
// 	msg[0]=Rxmsg[0];
// 	msg[1]=Rxmsg[1];
// 	msg[2]=Rxmsg[2];
// 	msg[3]=Rxmsg[3];
// 	msg[4]=Rxmsg[4];
// 	msg[5]=Rxmsg[5];
// 	msg[6]=Rxmsg[6];
// 	msg[7]=Rxmsg[7];
// 	if(msg[0]=='P'&&msg[1]=='b')
// 		TogglePump(msg[2],msg[3]);
// 	if(msg[0]=='V'&&msg[1]=='b')
// 		ToggleValve(msg[2], msg[3]);

ToggleValve('0','1');
HAL_Delay(1000);
ToggleValve('0','0');
HAL_CAN_AddTxMessage(&hcan,&Txheader, tstmsg, &Txmailbox);
    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void TogglePump(uint16_t pin, uint16_t state){

	switch(state){
	case '0':
		state = GPIO_PIN_RESET;
		break;
	case '1':
		state = GPIO_PIN_SET;
		break;
	}
	Txmsg[0]='R';
	Txmsg[1]='p';
	Txmsg[2]='b';
	switch (pin)
	{
	case '0':

		HAL_GPIO_WritePin(P1_GPIO_Port, P1_Pin, state);
		HAL_Delay(250);
		//HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '1':

		HAL_GPIO_WritePin(P2_GPIO_Port, P2_Pin, state);
		HAL_Delay(250);
		//HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '2':

		HAL_GPIO_WritePin(P3_GPIO_Port, P3_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '3':

		HAL_GPIO_WritePin(P4_GPIO_Port, P4_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '4':

		HAL_GPIO_WritePin(P5_GPIO_Port, P5_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '5':

		HAL_GPIO_WritePin(P6_GPIO_Port, P6_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	}
	
}

void ToggleValve(uint16_t pin, uint16_t state){

	switch(state){
	case '0':
		state = GPIO_PIN_RESET;
		break;
	case '1':
		state = GPIO_PIN_SET;
		break;
	}

	switch (pin)
	{
	case '0':
		HAL_GPIO_WritePin(V1_GPIO_Port, V1_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '1':

		HAL_GPIO_WritePin(V2_GPIO_Port, V2_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '2':

		HAL_GPIO_WritePin(V3_GPIO_Port, V3_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '3':

		HAL_GPIO_WritePin(V4_GPIO_Port, V4_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '4':

		HAL_GPIO_WritePin(V5_GPIO_Port, V5_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;
	case '5':

		HAL_GPIO_WritePin(V6_GPIO_Port, V6_Pin, state);
		HAL_Delay(250);
		HAL_CAN_AddTxMessage(&hcan,&Txheader, Txmsg, &Txmailbox);
		break;

	}
	
}
void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan){
	HAL_CAN_GetRxMessage(hcan, CAN_FILTER_FIFO1, &Rxheader,Rxmsg);
	uint8_t msg[8];
	msg[0]=Rxmsg[0];
	msg[1]=Rxmsg[1];
	msg[2]=Rxmsg[2];
	msg[3]=Rxmsg[3];
	msg[4]=Rxmsg[4];
	msg[5]=Rxmsg[5];
	msg[6]=Rxmsg[6];
	msg[7]=Rxmsg[7];
	TogglePump('0','1');
	if(msg[0]=='P'&&msg[1]=='b')
		TogglePump(msg[2],msg[3]);
	if(msg[0]=='V'&&msg[1]=='b')
		ToggleValve(msg[2], msg[3]);

}
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
	HAL_CAN_GetRxMessage(hcan, CAN_FILTER_FIFO0, &Rxheader,Rxmsg);
	uint8_t msg[8];
	msg[0]=Rxmsg[0];
	msg[1]=Rxmsg[1];
	msg[2]=Rxmsg[2];
	msg[3]=Rxmsg[3];
	msg[4]=Rxmsg[4];
	msg[5]=Rxmsg[5];
	msg[6]=Rxmsg[6];
	msg[7]=Rxmsg[7];
	TogglePump('0','1');
	if(msg[0]=='P'&&msg[1]=='b')
		TogglePump(msg[2],msg[3]);
	if(msg[0]=='V'&&msg[1]=='b')
		ToggleValve(msg[2], msg[3]);

}

void conf_filter(void){
	//HAL_CAN_MspInit(&hcan);

	filter.FilterIdHigh=0x400;
	filter.FilterFIFOAssignment=CAN_FILTER_FIFO0||CAN_FILTER_FIFO1;
	filter.FilterMode=CAN_FILTERMODE_IDMASK;
	filter.FilterScale=CAN_FILTERSCALE_32BIT;
	filter.FilterBank=0;
	filter.SlaveStartFilterBank=14;
	filter.FilterActivation=CAN_FILTER_ENABLE;

	Txheader.StdId = 0x500;      // Détermine l'adresse du périphérique au quel la trame est destiné.
	// Si plusieurs périphériques sur le bus comprennent cette adresse dans leur filtre, ils recevront tous la trame.
	Txheader.ExtId = 0x0;       // Adresse étendue, non utilisée dans note cas
	Txheader.RTR = CAN_RTR_DATA; // Précise que la trame contient des données
	Txheader.IDE = CAN_ID_STD;   // Précise que la trame est de type Standard
	Txheader.DLC =3;            // Précise le nombre d'octets de données que la trame transporte ( De 0 à 8 )
	Txheader.TransmitGlobalTime = DISABLE;
	HAL_CAN_ConfigFilter(&hcan,&filter);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
