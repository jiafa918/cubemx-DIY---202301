/*
*********************************************************************************************************
*
*	ģ������ : LEDָʾ������ģ��
*	�ļ����� : bsp_led.h
*	��    �� : V1.0
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2013-2014, ���������� www.armfly.com
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
////   LED�ṹ�嶨��
////*******************************************************************************
//typedef struct 
//{
//unsigned int  uiGPIO;						//LED�˿�	
//unsigned int 	ucOnTime;					//LED����ʱ��
//unsigned int 	ucOffTime;				//LEDϨ��ʱ��
//unsigned int 	ucCountTime;			//LED��ʱ��
//unsigned char ucPhase;					//��λ,0��ʾIO�͵�ƽ����LED,1��ʾIO�ߵ�ƽ����LED
//}My_LED_TypeDef;


///***************led����*******************/
//static 	My_LED_TypeDef			s_t_led_start 	= {Y0_PORT,0,0,0,1};
//				My_LED_TypeDef*			g_pt_led_start	= &s_t_led_start;


//static 	My_LED_TypeDef			s_t_led_reset 	= {Y1_PORT,0,0,0,1};
//				My_LED_TypeDef*			g_pt_led_reset	= &s_t_led_reset;

//void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime);
//void vLED_Update(My_LED_TypeDef* g_ptLED);


#endif

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
