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


#define LED1_PIN				M_O11_Pin
#define LED1_GPIO_PORT	M_O11_GPIO_Port  
#define LED2_PIN				M_O12_Pin
#define LED2_GPIO_PORT	M_O12_GPIO_Port  
#define LED3_PIN				M_O13_Pin
#define LED3_GPIO_PORT	M_O13_GPIO_Port  
#define LED4_PIN				M_O14_Pin
#define LED4_GPIO_PORT	M_O14_GPIO_Port  
/**
 * @brief LED Types Definition
 */
typedef enum 
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3,

  LED_GREEN  = LED1,
  LED_ORANGE = LED2,
  LED_RED    = LED3,
  LED_BLUE   = LED4

} Led_TypeDef;


  
/** @defgroup STM3210E_EVAL_LED STM3210E EVAL LED
  * @{
  */
#define LEDn                             4

//#define LED1_PIN                         GPIO_PIN_9             /* PF.06*/
//#define LED1_GPIO_PORT                   GPIOB
//#define LED1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOE_CLK_ENABLE()
//#define LED1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOE_CLK_DISABLE()
//  
//#define LED2_PIN                         GPIO_PIN_8             /* PF.07*/
//#define LED2_GPIO_PORT                   GPIOB
//#define LED2_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()
//#define LED2_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()


//#define LED3_PIN                         GPIO_PIN_5            /* PF.08*/
//#define LED3_GPIO_PORT                   GPIOB
//#define LED3_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()
//#define LED3_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()


//#define LED4_PIN                         GPIO_PIN_4            /* PF.09*/
//#define LED4_GPIO_PORT                   GPIOB
//#define LED4_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()
//#define LED4_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__LED__) do { if ((__LED__) == LED1) LED1_GPIO_CLK_ENABLE(); else\
                                           if ((__LED__) == LED2) LED2_GPIO_CLK_ENABLE(); else \
                                           if ((__LED__) == LED3) LED3_GPIO_CLK_ENABLE(); else\
                                           if ((__LED__) == LED4) LED4_GPIO_CLK_ENABLE();} while(0)

#define LEDx_GPIO_CLK_DISABLE(__LED__)   (((__LED__) == LED1) ? LED1_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED2) ? LED2_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED3) ? LED3_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED4) ? LED4_GPIO_CLK_DISABLE() : 0 )
																					 
uint32_t                BSP_GetVersion(void);
void                    BSP_LED_Init(Led_TypeDef Led);
void                    BSP_LED_On(Led_TypeDef Led);
void                    BSP_LED_Off(Led_TypeDef Led);
void                    BSP_LED_Toggle(Led_TypeDef Led);	
																					 
																					 
///* ʹ�ñ�׼�Ĺ̼������IO*/
//#define LED1(a)	if (a)	\
//					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
//					else		\
//					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

//#define LED2(a)	if (a)	\
//					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
//					else		\
//					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

//#define LED3(a)	if (a)	\
//					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
//					else		\
//					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)


///* ֱ�Ӳ����Ĵ����ķ�������IO */
//#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
//#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
//#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


///* �������IO�ĺ� */
//#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
//#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
//#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

//#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
//#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
//#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

//#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
//#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
//#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

///* �����ڶ�Ӧ��RCCʱ�� */
////#define RCC_ALL_LED 	(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE)

///*
//	�ó��������ڰ�����STM32-V4 ������
//	�����������Ӳ�������޸�GPIO����
//	����û���LEDָʾ�Ƹ���С��4�������Խ������LEDȫ������Ϊ�͵�1��LEDһ��������Ӱ�������
//*/




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

																				 
																					 

///* ���ⲿ���õĺ������� */
//void bsp_InitLed(void);
//void bsp_LedOn(uint8_t _no);
//void bsp_LedOff(uint8_t _no);
//void bsp_LedToggle(uint8_t _no);
//uint8_t bsp_IsLedOn(uint8_t _no);

//void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime);
//void vLED_Update(My_LED_TypeDef* g_ptLED);


#endif

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
