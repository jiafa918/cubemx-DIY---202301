/*
*********************************************************************************************************
*
*	模块名称 : LED指示灯驱动模块
*	文件名称 : bsp_led.h
*	版    本 : V1.0
*	说    明 : 头文件
*
*	Copyright (C), 2013-2014, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "bsp.h"

//typedef enum 
//{
//  LED1 = 0,
//  LED2 = 1,
//  LED3 = 2,
//  LED4 = 3,

////  LED_GREEN  = LED1,
////  LED_ORANGE = LED2,
////  LED_RED    = LED3,
////  LED_BLUE   = LED4
//} Led_TypeDef;

/**
 * @brief LED Types Definition
 */
typedef enum 
{
//  Y1 = 0,
//  Y2 = 1,
//  Y3 = 2,
   O4 = 3,
   O5 = 4,
   O6 = 5,
   O7 = 6,
   O8 = 7,
	 O9 = 8,
   O10 = 9,
   O11 = 10,
   O12 = 11,
   O13 = 12,
   O14 = 13,
   O15 = 14,
   O16 = 15,
	
//  LED_GREEN  = LED1,
//  LED_ORANGE = LED2,
//  LED_RED    = LED3,
//  LED_BLUE   = LED4
} O_TypeDef;

void bsp_Y_On(uint8_t _no);
void bsp_Y_Off(uint8_t _no);
void BSP_Y_Toggle(O_TypeDef _no);
uint8_t bsp_Is_Y_On(uint8_t _no);

////*******************************************************************************
////   LED结构体定义
////*******************************************************************************
//typedef struct 
//{
//unsigned int  uiGPIO;						//LED端口	
//unsigned int 	ucOnTime;					//LED点亮时间
//unsigned int 	ucOffTime;				//LED熄灭时间
//unsigned int 	ucCountTime;			//LED计时器
//unsigned char ucPhase;					//相位,0表示IO低电平点亮LED,1表示IO高电平点亮LED
//}My_LED_TypeDef;


///***************led定义*******************/
//static 	My_LED_TypeDef			s_t_led_start 	= {Y0_PORT,0,0,0,1};
//				My_LED_TypeDef*			g_pt_led_start	= &s_t_led_start;


//static 	My_LED_TypeDef			s_t_led_reset 	= {Y1_PORT,0,0,0,1};
//				My_LED_TypeDef*			g_pt_led_reset	= &s_t_led_reset;

//void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime);
//void vLED_Update(My_LED_TypeDef* g_ptLED);


#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
