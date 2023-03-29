/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define RUNKEY_Pin GPIO_PIN_13
#define RUNKEY_GPIO_Port GPIOC
#define VDD_24VD_Pin GPIO_PIN_0
#define VDD_24VD_GPIO_Port GPIOC
#define EN_24V_Pin GPIO_PIN_1
#define EN_24V_GPIO_Port GPIOC
#define TXD2_Pin GPIO_PIN_2
#define TXD2_GPIO_Port GPIOA
#define RXD2_Pin GPIO_PIN_3
#define RXD2_GPIO_Port GPIOA
#define I1_Pin GPIO_PIN_4
#define I1_GPIO_Port GPIOA
#define I2_Pin GPIO_PIN_5
#define I2_GPIO_Port GPIOA
#define I3_Pin GPIO_PIN_6
#define I3_GPIO_Port GPIOA
#define I4_Pin GPIO_PIN_7
#define I4_GPIO_Port GPIOA
#define I5_Pin GPIO_PIN_4
#define I5_GPIO_Port GPIOC
#define I6_Pin GPIO_PIN_5
#define I6_GPIO_Port GPIOC
#define I7_Pin GPIO_PIN_0
#define I7_GPIO_Port GPIOB
#define I8_Pin GPIO_PIN_1
#define I8_GPIO_Port GPIOB
#define I9_Pin GPIO_PIN_8
#define I9_GPIO_Port GPIOE
#define I10_Pin GPIO_PIN_9
#define I10_GPIO_Port GPIOE
#define I11_Pin GPIO_PIN_10
#define I11_GPIO_Port GPIOE
#define I12_Pin GPIO_PIN_11
#define I12_GPIO_Port GPIOE
#define I13_Pin GPIO_PIN_12
#define I13_GPIO_Port GPIOE
#define I14_Pin GPIO_PIN_13
#define I14_GPIO_Port GPIOE
#define I15_Pin GPIO_PIN_14
#define I15_GPIO_Port GPIOE
#define I16_Pin GPIO_PIN_15
#define I16_GPIO_Port GPIOE
#define EN2_485_Pin GPIO_PIN_12
#define EN2_485_GPIO_Port GPIOB
#define EN3_485_Pin GPIO_PIN_13
#define EN3_485_GPIO_Port GPIOB
#define TXD3_Pin GPIO_PIN_8
#define TXD3_GPIO_Port GPIOD
#define RXD3_Pin GPIO_PIN_9
#define RXD3_GPIO_Port GPIOD
#define RUNLED_Pin GPIO_PIN_7
#define RUNLED_GPIO_Port GPIOC
#define ERRLED_Pin GPIO_PIN_8
#define ERRLED_GPIO_Port GPIOC
#define O1_Pin GPIO_PIN_9
#define O1_GPIO_Port GPIOC
#define O3_Pin GPIO_PIN_8
#define O3_GPIO_Port GPIOA
#define TXD1_Pin GPIO_PIN_9
#define TXD1_GPIO_Port GPIOA
#define RXD1_Pin GPIO_PIN_10
#define RXD1_GPIO_Port GPIOA
#define O2_Pin GPIO_PIN_15
#define O2_GPIO_Port GPIOA
#define TXD4_Pin GPIO_PIN_10
#define TXD4_GPIO_Port GPIOC
#define RXD4_Pin GPIO_PIN_11
#define RXD4_GPIO_Port GPIOC
#define TXD5_Pin GPIO_PIN_12
#define TXD5_GPIO_Port GPIOC
#define O16_Pin GPIO_PIN_0
#define O16_GPIO_Port GPIOD
#define O15_Pin GPIO_PIN_1
#define O15_GPIO_Port GPIOD
#define RXD5_Pin GPIO_PIN_2
#define RXD5_GPIO_Port GPIOD
#define O14_Pin GPIO_PIN_3
#define O14_GPIO_Port GPIOD
#define O13_Pin GPIO_PIN_4
#define O13_GPIO_Port GPIOD
#define O12_Pin GPIO_PIN_5
#define O12_GPIO_Port GPIOD
#define O11_Pin GPIO_PIN_6
#define O11_GPIO_Port GPIOD
#define O10_Pin GPIO_PIN_7
#define O10_GPIO_Port GPIOD
#define O9_Pin GPIO_PIN_3
#define O9_GPIO_Port GPIOB
#define O8_Pin GPIO_PIN_4
#define O8_GPIO_Port GPIOB
#define O7_Pin GPIO_PIN_5
#define O7_GPIO_Port GPIOB
#define O6_Pin GPIO_PIN_8
#define O6_GPIO_Port GPIOB
#define O5_Pin GPIO_PIN_9
#define O5_GPIO_Port GPIOB
#define O4_Pin GPIO_PIN_0
#define O4_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
