#ifndef __MY_LED_H
#define __MY_LED_H

//*******************************************************************************
//   LED�ṹ�嶨��
//*******************************************************************************
typedef struct 
{
unsigned int  uiGPIO;						//LED�˿�	
unsigned int 	ucOnTime;					//LED����ʱ��
unsigned int 	ucOffTime;				//LEDϨ��ʱ��
unsigned int 	ucCountTime;			//LED��ʱ��
unsigned char ucPhase;					//��λ,0��ʾIO�͵�ƽ����LED,1��ʾIO�ߵ�ƽ����LED
}My_LED_TypeDef;

//*******************************************************************************
//   ��������
//*******************************************************************************
void vLED_Init(My_LED_TypeDef* g_ptLED);
void vLED_On(My_LED_TypeDef* g_ptLED);
void vLED_Off(My_LED_TypeDef* g_ptLED);
void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime, unsigned int  Offtime);
void vLED_Update(My_LED_TypeDef* g_ptLED);








#endif


