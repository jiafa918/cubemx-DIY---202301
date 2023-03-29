/*
*********************************************************************************************************
*
*	模块名称 : LED指示灯驱动模块
*	文件名称 : bsp_led.c
*	版    本 : V1.0
*	说    明 : 驱动LED指示灯
*
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2013-02-01 armfly  正式发布
*
*	Copyright (C), 2013-2014, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/


#include "bsp_LED.h"

/**
 * @brief LED variables
 */
//GPIO_TypeDef* LED_PORT[LEDn] = {LED1_GPIO_PORT, 
//                                LED2_GPIO_PORT, 
//                                LED3_GPIO_PORT,
//                                LED4_GPIO_PORT};

//const uint16_t LED_PIN[LEDn] = {LED1_PIN, 
//                                LED2_PIN, 
//                                LED3_PIN,
//                                LED4_PIN};


/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
//void BSP_LED_Init(Led_TypeDef Led)
//{
//  GPIO_InitTypeDef  gpioinitstruct = {0};
//  
//  /* Enable the GPIO_LED clock */
//  LEDx_GPIO_CLK_ENABLE(Led);

//  /* Configure the GPIO_LED pin */
//  gpioinitstruct.Pin    = LED_PIN[Led];
//  gpioinitstruct.Mode   = GPIO_MODE_OUTPUT_PP;
//  gpioinitstruct.Pull   = GPIO_NOPULL;
//  gpioinitstruct.Speed  = GPIO_SPEED_FREQ_HIGH;

//  HAL_GPIO_Init(LED_PORT[Led], &gpioinitstruct);

//  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
//}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_On(Led_TypeDef Led)
{
//  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_Off(Led_TypeDef Led)
{
//  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
//  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}																
																
																
																

//#define GPIO_PORT_LED1  M_O14_GPIO_Port
//#define GPIO_PIN_LED1	M_O14_Pin

//#define GPIO_PORT_LED2  M_O13_GPIO_Port
//#define GPIO_PIN_LED2	M_O13_Pin

///*
//*********************************************************************************************************
//*	函 数 名: bsp_InitLed
//*	功能说明: 配置LED指示灯相关的GPIO,  该函数被 bsp_Init() 调用。
//*	形    参:  无
//*	返 回 值: 无
//*********************************************************************************************************
//*/
//void bsp_InitLed(void)
//{
////    GPIO_InitTypeDef GPIO_InitStruct;

////    /* 打开GPIO时钟 */
//////	_RCC_APB2PeriphClockCmd(RCC_ALL_LED, ENABLE);
////    /* GPIO Ports Clock Enable */
////    __HAL_RCC_GPIOE_CLK_ENABLE();
////    __HAL_RCC_GPIOB_CLK_ENABLE();
////    /*
////    	配置所有的LED指示灯GPIO为推挽输出模式
////    	由于将GPIO设置为输出时，GPIO输出寄存器的值缺省是0，因此会驱动LED点亮.
////    	这是我不希望的，因此在改变GPIO为输出前，先关闭LED指示灯
////    */
////    /*Configure GPIO pin Output Level */
////    HAL_GPIO_WritePin(M_O4_GPIO_Port,M_O4_Pin, GPIO_PIN_RESET);
////    /*Configure GPIO pin Output Level */
////    HAL_GPIO_WritePin(M_O5_GPIO_Port, M_O5_Pin, GPIO_PIN_RESET);

//////	bsp_LedOff(1);
//////	bsp_LedOff(2);
//////	bsp_LedOff(3);
//////	bsp_LedOff(4);

////    /*Configure GPIO pin : PtPin */
//////    GPIO_InitStruct.Pin = GPIO_PIN_5;
//////    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//////    GPIO_InitStruct.Pull = GPIO_NOPULL;
//////    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//////    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//////    GPIO_InitStruct.Pin = GPIO_PIN_5;
//////    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//////    GPIO_InitStruct.Pull = GPIO_NOPULL;
//////    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//////    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);


//}

///*
//*********************************************************************************************************
//*	函 数 名: bsp_LedOn
//*	功能说明: 点亮指定的LED指示灯。
//*	形    参:  _no : 指示灯序号，范围 1 - 4
//*	返 回 值: 无
//*********************************************************************************************************
//*/
//void bsp_LedOn(uint8_t _no)
//{
//    if (_no == 1)
//    {
////void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
//        HAL_GPIO_WritePin(M_O4_GPIO_Port,M_O4_Pin, GPIO_PIN_SET);
////		HC574_SetPin(LED1, 0);
//    }
//    else if (_no == 2)
//    {
////		HC574_SetPin(LED2, 0);
//        HAL_GPIO_WritePin(M_O5_GPIO_Port,M_O5_Pin, GPIO_PIN_SET);
//    }
////	else if (_no == 3)
////	{
//////		HC574_SetPin(LED3, 0);
////	}

//}

///*
//*********************************************************************************************************
//*	函 数 名: bsp_LedOff
//*	功能说明: 熄灭指定的LED指示灯。
//*	形    参:  Led : 指示灯序号，范围 1 - 4
//*	返 回 值: 无
//*********************************************************************************************************
//*/
//void bsp_LedOff(uint8_t _no)
//{
//    if (_no == 1)
//    {
////		HC574_SetPin(LED1, 1);
//        //void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
//        HAL_GPIO_WritePin(M_O4_GPIO_Port,M_O4_Pin,GPIO_PIN_RESET);
//    }
//    else if (_no == 2)
//    {
////		HC574_SetPin(LED2, 1);
//        //void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
//        HAL_GPIO_WritePin(M_O5_GPIO_Port,M_O5_Pin,GPIO_PIN_RESET);
//    }
////	else if (_no == 3)
////	{
////		HC574_SetPin(LED3, 1);
////	}


//}
///*
//*********************************************************************************************************
//*	函 数 名: bsp_LedToggle
//*	功能说明: 翻转指定的LED指示灯。
//*	形    参:  Led : 指示灯序号，范围 1 - 4
//*	返 回 值: 按键代码
//*********************************************************************************************************
//*/
///*
//*********************************************************************************************************
//*	函 数 名: bsp_LedToggle
//*	功能说明: 翻转指定的LED指示灯。
//*	形    参:  _no : 指示灯序号，范围 1 - 4
//*	返 回 值: 按键代码
//*********************************************************************************************************
//*/
//void bsp_LedToggle(uint8_t _no)
//{
////	uint32_t pin;

//    if (_no == 1)
//    {
////		pin = LED1;
//        HAL_GPIO_TogglePin(M_O4_GPIO_Port,M_O4_Pin);
//    }
//    else if (_no == 2)
//    {
////		pin = LED2;
//        HAL_GPIO_TogglePin(M_O5_GPIO_Port,M_O5_Pin);
//    }
////	else if (_no == 3)
////	{
////		pin = LED3;
////	}

//    else
//    {
//        return;
//    }

////	if (HC574_GetPin(pin))
////	{
////		HC574_SetPin(pin, 0);
////	}
////	else
////	{
////		HC574_SetPin(pin, 1);
////	}
//}

///*
//*********************************************************************************************************
//*	函 数 名: bsp_IsLedOn
//*	功能说明: 判断LED指示灯是否已经点亮。
//*	形    参:  _no : 指示灯序号，范围 1 - 4
//*	返 回 值: 1表示已经点亮，0表示未点亮
//*********************************************************************************************************
//*/
//uint8_t bsp_IsLedOn(uint8_t _no)
//{
////    uint32_t pin;
////    if (_no == 1)
////    {
////        pin = M_O4_Pin;
////    }
////    else if (_no == 2)
////    {
////        pin = M_O5_Pin;
////    }
//////	else if (_no == 3)
//////	{
//////		pin = LED3;
//////	}
//////	else if (_no == 4)
//////	{
//////		pin = LED4;
//////	}
////    else
////    {
////        return 0;
////    }

////	if (HC574_GetPin(pin))
////	{
////		return 0;	/* 灭 */
////	}
////	else
////	{
////		return 1;	/* 亮 */
////	}
//}


//////**************************************************************************************************
//////函数名：	vLED_Flash()
//////说  明：	LED闪烁
//////参  数：	My_LED_TypeDef* g_ptLED：LED编号
//////				unsigned int  Ontime：亮灯持续时间,时间单位为vLED_Update函数的调用周期
//////				unsigned int  Offtime：熄灯的持续时间,时间单位为vLED_Update函数的调用周期
//////返回值： 无
//////**************************************************************************************************
////void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime)
////{
////    g_ptLED->ucOnTime 		= Ontime;
////    g_ptLED->ucOffTime 		= Ontime+Offtime;
////    g_ptLED->ucCountTime 	= 0;
////}
//////**************************************************************************************************
//////函数名：	vLED_Update()
//////说  明：	跟新LED状态，此函数需要固定周期调用。
//////参  数：	My_LED_TypeDef* g_ptLED
//////返回值： 无
//////**************************************************************************************************
////void vLED_Update(My_LED_TypeDef* g_ptLED)
////{
////    if(g_ptLED->ucCountTime < g_ptLED->ucOnTime)
////    {
////        if(g_ptLED->ucPhase)	GetBit(Output.ALL,g_ptLED->uiGPIO);
////        else									SetBit(Output.ALL,g_ptLED->uiGPIO);
////    }

////    else
////    {
////        //LED 灭
////        if(g_ptLED->ucPhase)	GetBit(Output.ALL,g_ptLED->uiGPIO);
////        else									SetBit(Output.ALL,g_ptLED->uiGPIO);
////    }
////    g_ptLED->ucCountTime++;
////    if(g_ptLED->ucCountTime >= g_ptLED->ucOffTime)
////    {
////        //计数器清零
////        g_ptLED->ucCountTime=0;
////    }
////}





/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
