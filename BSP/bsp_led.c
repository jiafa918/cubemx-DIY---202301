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

#include "bsp_led.h"

uint16_t buf[8][10]={{0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100},
									   {0X0000,0X0001,0X0002,0X0004,0X0008,0X0010,0X0020,0X0040,0X0080,0X0100} };
//uint16_t        buf[0][0]=R0;
//uint16_t        buf[0][1]=R10;
//uint16_t        buf[0][2]=R100;
//uint16_t        buf[0][3]=R1K;
//uint16_t        buf[0][4]=R10K;
//uint16_t        buf[0][5]=R100K;
//uint16_t        buf[0][6]=R1M;
//uint16_t        buf[0][7]=R10M;
///**
// * @brief LED variables
// */
//GPIO_TypeDef* LED_PORT[LEDn] = {LED1_GPIO_PORT,
//                                LED2_GPIO_PORT,
//                                LED3_GPIO_PORT,
//                                LED4_GPIO_PORT};

//const uint16_t LED_PIN[LEDn] = {LED1_PIN,
//                                LED2_PIN,
//                                LED3_PIN,
//                                LED4_PIN};


#define Yn                             13
GPIO_TypeDef* Y_PORT[Yn] = {
//                                Y1_GPIO_Port,
//                                Y2_GPIO_Port,
//                                Y3_GPIO_Port,
    O4_GPIO_Port,
    O5_GPIO_Port,
    O6_GPIO_Port,
    O7_GPIO_Port,
    O8_GPIO_Port,
    O9_GPIO_Port,
    O10_GPIO_Port,
    O11_GPIO_Port,
    O12_GPIO_Port,
    O13_GPIO_Port,
    O14_GPIO_Port,
    O15_GPIO_Port,
    O16_GPIO_Port,
};

const uint16_t Y_PIN[Yn] = {
//                                Y1_Pin,
//                                Y2_Pin,
//                                Y3_Pin,
    O4_Pin,
    O5_Pin,
    O6_Pin,
    O7_Pin,
    O8_Pin,
    O9_Pin,
    O10_Pin,
    O11_Pin,
    O12_Pin,
    O13_Pin,
    O14_Pin,
    O15_Pin,
    O16_Pin,
};

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on.
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
//void BSP_LED_Init(Led_TypeDef Led)
//{
//}

//void BSP_LED_On(Y_TypeDef Led)
//{
//  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
//}

//void BSP_LED_Off(Led_TypeDef Led)
//{
////  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
//}

//void BSP_LED_Toggle(Led_TypeDef Led)
//{
////  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
//}

//uint32_t BSP_PB_GetState(Button_TypeDef Button)
//{
//    return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
//}

/*
*********************************************************************************************************
*	�� �� ��: bsp_InitLed
*	����˵��: ����LEDָʾ����ص�GPIO,  �ú����� bsp_Init() ���á�
*	��    ��:  ��
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_InitLed(void)
{
//STM32CUBEMX�Ѿ���ʼ�����
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_LedOn
*	����˵��: ����ָ����LEDָʾ�ơ�
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_Y_On(uint8_t _no)
{
  HAL_GPIO_WritePin(Y_PORT[_no], Y_PIN[_no], GPIO_PIN_SET);
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_LedOff
*	����˵��: Ϩ��ָ����LEDָʾ�ơ�
*	��    ��:  Led : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void bsp_Y_Off(uint8_t _no)
{
  HAL_GPIO_WritePin(Y_PORT[_no], Y_PIN[_no], GPIO_PIN_RESET);
}

/*
*********************************************************************************************************
*	�� �� ��: bsp_LedToggle
*	����˵��: ��תָ����LEDָʾ�ơ�
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: ��������
*********************************************************************************************************
*/
void BSP_Y_Toggle(O_TypeDef _no)
{
    HAL_GPIO_TogglePin(Y_PORT[_no], Y_PIN[_no]);
}
/*
*********************************************************************************************************
*	�� �� ��: bsp_IsLedOn
*	����˵��: �ж�LEDָʾ���Ƿ��Ѿ�������
*	��    ��:  _no : ָʾ����ţ���Χ 1 - 4
*	�� �� ֵ: 1��ʾ�Ѿ�������0��ʾδ����
*********************************************************************************************************
*/
uint8_t bsp_Is_Y_On(uint8_t _no)
{
    return HAL_GPIO_ReadPin(Y_PORT[_no], Y_PIN[_no]);	
}

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
