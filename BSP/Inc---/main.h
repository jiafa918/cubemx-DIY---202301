/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#define M_I1_Pin GPIO_PIN_4
#define M_I1_GPIO_Port GPIOA
#define M_I2_Pin GPIO_PIN_5
#define M_I2_GPIO_Port GPIOA
#define M_I3_Pin GPIO_PIN_6
#define M_I3_GPIO_Port GPIOA
#define M_I4_Pin GPIO_PIN_7
#define M_I4_GPIO_Port GPIOA
#define M_I5_Pin GPIO_PIN_4
#define M_I5_GPIO_Port GPIOC
#define M_I6_Pin GPIO_PIN_5
#define M_I6_GPIO_Port GPIOC
#define M_I7_Pin GPIO_PIN_0
#define M_I7_GPIO_Port GPIOB
#define M_I8_Pin GPIO_PIN_1
#define M_I8_GPIO_Port GPIOB
#define M_I9_Pin GPIO_PIN_8
#define M_I9_GPIO_Port GPIOE
#define M_I10_Pin GPIO_PIN_9
#define M_I10_GPIO_Port GPIOE
#define M_I11_Pin GPIO_PIN_10
#define M_I11_GPIO_Port GPIOE
#define M_I12_Pin GPIO_PIN_11
#define M_I12_GPIO_Port GPIOE
#define M_I13_Pin GPIO_PIN_12
#define M_I13_GPIO_Port GPIOE
#define M_I14_Pin GPIO_PIN_13
#define M_I14_GPIO_Port GPIOE
#define M_I15_Pin GPIO_PIN_14
#define M_I15_GPIO_Port GPIOE
#define M_I16_Pin GPIO_PIN_15
#define M_I16_GPIO_Port GPIOE
#define I2C2_SCL_Pin GPIO_PIN_10
#define I2C2_SCL_GPIO_Port GPIOB
#define I2C2_SDA_Pin GPIO_PIN_11
#define I2C2_SDA_GPIO_Port GPIOB
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
#define TIM3_CH4_Pin GPIO_PIN_9
#define TIM3_CH4_GPIO_Port GPIOC
#define TIM1_CH1_Pin GPIO_PIN_8
#define TIM1_CH1_GPIO_Port GPIOA
#define TXD1_Pin GPIO_PIN_9
#define TXD1_GPIO_Port GPIOA
#define RXD1_Pin GPIO_PIN_10
#define RXD1_GPIO_Port GPIOA
#define TIM2_CH1_Pin GPIO_PIN_15
#define TIM2_CH1_GPIO_Port GPIOA
#define TXD4_Pin GPIO_PIN_10
#define TXD4_GPIO_Port GPIOC
#define RXD4_Pin GPIO_PIN_11
#define RXD4_GPIO_Port GPIOC
#define TXD5_Pin GPIO_PIN_12
#define TXD5_GPIO_Port GPIOC
#define M_O16_Pin GPIO_PIN_0
#define M_O16_GPIO_Port GPIOD
#define M_O15_Pin GPIO_PIN_1
#define M_O15_GPIO_Port GPIOD
#define RXD5_Pin GPIO_PIN_2
#define RXD5_GPIO_Port GPIOD
#define M_O14_Pin GPIO_PIN_3
#define M_O14_GPIO_Port GPIOD
#define M_O13_Pin GPIO_PIN_4
#define M_O13_GPIO_Port GPIOD
#define M_O12_Pin GPIO_PIN_5
#define M_O12_GPIO_Port GPIOD
#define M_O11_Pin GPIO_PIN_6
#define M_O11_GPIO_Port GPIOD
#define M_O10_Pin GPIO_PIN_7
#define M_O10_GPIO_Port GPIOD
#define M_O9_Pin GPIO_PIN_3
#define M_O9_GPIO_Port GPIOB
#define M_O8_Pin GPIO_PIN_4
#define M_O8_GPIO_Port GPIOB
#define M_O7_Pin GPIO_PIN_5
#define M_O7_GPIO_Port GPIOB
#define M_O6_Pin GPIO_PIN_8
#define M_O6_GPIO_Port GPIOB
#define M_O5_Pin GPIO_PIN_9
#define M_O5_GPIO_Port GPIOB
#define M_O4_Pin GPIO_PIN_0
#define M_O4_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
