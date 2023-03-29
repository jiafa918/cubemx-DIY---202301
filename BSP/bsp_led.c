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
*	函 数 名: bsp_InitLed
*	功能说明: 配置LED指示灯相关的GPIO,  该函数被 bsp_Init() 调用。
*	形    参:  无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_InitLed(void)
{
//STM32CUBEMX已经初始化完成
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedOn
*	功能说明: 点亮指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_Y_On(uint8_t _no)
{
  HAL_GPIO_WritePin(Y_PORT[_no], Y_PIN[_no], GPIO_PIN_SET);
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedOff
*	功能说明: 熄灭指定的LED指示灯。
*	形    参:  Led : 指示灯序号，范围 1 - 4
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_Y_Off(uint8_t _no)
{
  HAL_GPIO_WritePin(Y_PORT[_no], Y_PIN[_no], GPIO_PIN_RESET);
}

/*
*********************************************************************************************************
*	函 数 名: bsp_LedToggle
*	功能说明: 翻转指定的LED指示灯。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 按键代码
*********************************************************************************************************
*/
void BSP_Y_Toggle(O_TypeDef _no)
{
    HAL_GPIO_TogglePin(Y_PORT[_no], Y_PIN[_no]);
}
/*
*********************************************************************************************************
*	函 数 名: bsp_IsLedOn
*	功能说明: 判断LED指示灯是否已经点亮。
*	形    参:  _no : 指示灯序号，范围 1 - 4
*	返 回 值: 1表示已经点亮，0表示未点亮
*********************************************************************************************************
*/
uint8_t bsp_Is_Y_On(uint8_t _no)
{
    return HAL_GPIO_ReadPin(Y_PORT[_no], Y_PIN[_no]);	
}

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
