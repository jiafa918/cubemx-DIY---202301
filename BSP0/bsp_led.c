/*
*********************************************************************************************************
*
*	ģ������ : LEDָʾ������ģ��
*	�ļ����� : bsp_led.c
*	��    �� : V1.0
*	˵    �� : ����LEDָʾ��
*
*	�޸ļ�¼ :
*		�汾��  ����        ����     ˵��
*		V1.0    2013-02-01 armfly  ��ʽ����
*
*	Copyright (C), 2013-2014, ���������� www.armfly.com
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
//*	�� �� ��: bsp_InitLed
//*	����˵��: ����LEDָʾ����ص�GPIO,  �ú����� bsp_Init() ���á�
//*	��    ��:  ��
//*	�� �� ֵ: ��
//*********************************************************************************************************
//*/
//void bsp_InitLed(void)
//{
////    GPIO_InitTypeDef GPIO_InitStruct;

////    /* ��GPIOʱ�� */
//////	_RCC_APB2PeriphClockCmd(RCC_ALL_LED, ENABLE);
////    /* GPIO Ports Clock Enable */
////    __HAL_RCC_GPIOE_CLK_ENABLE();
////    __HAL_RCC_GPIOB_CLK_ENABLE();
////    /*
////    	�������е�LEDָʾ��GPIOΪ�������ģʽ
////    	���ڽ�GPIO����Ϊ���ʱ��GPIO����Ĵ�����ֵȱʡ��0����˻�����LED����.
////    	�����Ҳ�ϣ���ģ�����ڸı�GPIOΪ���ǰ���ȹر�LEDָʾ��
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
//*	�� �� ��: bsp_LedOn
//*	����˵��: ����ָ����LEDָʾ�ơ�
//*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
//*	�� �� ֵ: ��
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
//*	�� �� ��: bsp_LedOff
//*	����˵��: Ϩ��ָ����LEDָʾ�ơ�
//*	��    ��:  Led : ָʾ����ţ���Χ 1 - 4
//*	�� �� ֵ: ��
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
//*	�� �� ��: bsp_LedToggle
//*	����˵��: ��תָ����LEDָʾ�ơ�
//*	��    ��:  Led : ָʾ����ţ���Χ 1 - 4
//*	�� �� ֵ: ��������
//*********************************************************************************************************
//*/
///*
//*********************************************************************************************************
//*	�� �� ��: bsp_LedToggle
//*	����˵��: ��תָ����LEDָʾ�ơ�
//*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
//*	�� �� ֵ: ��������
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
//*	�� �� ��: bsp_IsLedOn
//*	����˵��: �ж�LEDָʾ���Ƿ��Ѿ�������
//*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
//*	�� �� ֵ: 1��ʾ�Ѿ�������0��ʾδ����
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
////		return 0;	/* �� */
////	}
////	else
////	{
////		return 1;	/* �� */
////	}
//}


//////**************************************************************************************************
//////��������	vLED_Flash()
//////˵  ����	LED��˸
//////��  ����	My_LED_TypeDef* g_ptLED��LED���
//////				unsigned int  Ontime�����Ƴ���ʱ��,ʱ�䵥λΪvLED_Update�����ĵ�������
//////				unsigned int  Offtime��Ϩ�Ƶĳ���ʱ��,ʱ�䵥λΪvLED_Update�����ĵ�������
//////����ֵ�� ��
//////**************************************************************************************************
////void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime)
////{
////    g_ptLED->ucOnTime 		= Ontime;
////    g_ptLED->ucOffTime 		= Ontime+Offtime;
////    g_ptLED->ucCountTime 	= 0;
////}
//////**************************************************************************************************
//////��������	vLED_Update()
//////˵  ����	����LED״̬���˺�����Ҫ�̶����ڵ��á�
//////��  ����	My_LED_TypeDef* g_ptLED
//////����ֵ�� ��
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
////        //LED ��
////        if(g_ptLED->ucPhase)	GetBit(Output.ALL,g_ptLED->uiGPIO);
////        else									SetBit(Output.ALL,g_ptLED->uiGPIO);
////    }
////    g_ptLED->ucCountTime++;
////    if(g_ptLED->ucCountTime >= g_ptLED->ucOffTime)
////    {
////        //����������
////        g_ptLED->ucCountTime=0;
////    }
////}





/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
