/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IFM1_Pin GPIO_PIN_0
#define IFM1_GPIO_Port GPIOA
#define IFM1_EXTI_IRQn EXTI0_1_IRQn
#define IFM2_Pin GPIO_PIN_1
#define IFM2_GPIO_Port GPIOA
#define IFM2_EXTI_IRQn EXTI0_1_IRQn
#define IFM3_Pin GPIO_PIN_2
#define IFM3_GPIO_Port GPIOA
#define IFM3_EXTI_IRQn EXTI2_3_IRQn
#define IFM4_Pin GPIO_PIN_3
#define IFM4_GPIO_Port GPIOA
#define IFM4_EXTI_IRQn EXTI2_3_IRQn
#define SERVO1_Pin GPIO_PIN_4
#define SERVO1_GPIO_Port GPIOA
#define SERVO2_Pin GPIO_PIN_5
#define SERVO2_GPIO_Port GPIOA
#define SERVO3_Pin GPIO_PIN_6
#define SERVO3_GPIO_Port GPIOA
#define SERVO4_Pin GPIO_PIN_7
#define SERVO4_GPIO_Port GPIOA
#define FOURCHE1_Pin GPIO_PIN_4
#define FOURCHE1_GPIO_Port GPIOB
#define FOURCHE1_EXTI_IRQn EXTI4_15_IRQn
#define FOURCHE2_Pin GPIO_PIN_5
#define FOURCHE2_GPIO_Port GPIOB
#define FOURCHE2_EXTI_IRQn EXTI4_15_IRQn
#define FOURCHE3_Pin GPIO_PIN_6
#define FOURCHE3_GPIO_Port GPIOB
#define FOURCHE3_EXTI_IRQn EXTI4_15_IRQn
#define FOURCHE4_Pin GPIO_PIN_7
#define FOURCHE4_GPIO_Port GPIOB
#define FOURCHE4_EXTI_IRQn EXTI4_15_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
