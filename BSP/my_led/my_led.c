//**************************************************************************************************
//#include "my_stm32f1_gpio.h"
#include "my_led.h"



//**************************************************************************************************
//��������	vLED_Init()
//˵  ����	LED��ʼ��
//��  ����	My_LED_TypeDef* g_ptLED��LED���
//����ֵ��	��
//**************************************************************************************************
void vLED_Init(My_LED_TypeDef* g_ptLED)
{
	//�˿ڳ�ʼ��
  vGPIO_Init(g_ptLED->uiGPIO, PP_OUT_2MHZ, 1);
	//LED ��		
	if(g_ptLED->ucPhase)	Ret(g_ptLED->uiGPIO);
	else									Set(g_ptLED->uiGPIO);
}

//**************************************************************************************************
//��������	vLED_On()
//˵  ��������LED
//��  ����My_LED_TypeDef* g_ptLED��LED���
//����ֵ�� ��
//**************************************************************************************************
void vLED_On(My_LED_TypeDef* g_ptLED)
{
	//LED ��	
	if(g_ptLED->ucPhase)	Set(g_ptLED->uiGPIO);
	else									Ret(g_ptLED->uiGPIO);
	
	g_ptLED->ucOnTime = 100;
	g_ptLED->ucOffTime = 0;
	g_ptLED->ucCountTime = 0;
}
//**************************************************************************************************
//��������	vLED_Off()
//˵  �����ر�LED
//��  ����	My_LED_TypeDef* g_ptLED��LED���
//����ֵ�� ��
//**************************************************************************************************
void vLED_Off(My_LED_TypeDef* g_ptLED)
{
	//LED ��	
	if(g_ptLED->ucPhase)	Ret(g_ptLED->uiGPIO);
	else									Set(g_ptLED->uiGPIO);
	
	g_ptLED->ucOnTime = 0;
	g_ptLED->ucOffTime = 100;
	g_ptLED->ucCountTime = 0;
}
//**************************************************************************************************
//��������	vLED_Flash()
//˵  ����	LED��˸
//��  ����	My_LED_TypeDef* g_ptLED��LED���
//				unsigned int  Ontime�����Ƴ���ʱ��,ʱ�䵥λΪvLED_Update�����ĵ�������
//				unsigned int  Offtime��Ϩ�Ƶĳ���ʱ��,ʱ�䵥λΪvLED_Update�����ĵ�������
//����ֵ�� ��
//**************************************************************************************************
void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime)
{
	g_ptLED->ucOnTime 		= Ontime;
	g_ptLED->ucOffTime 		= Ontime+Offtime;
	g_ptLED->ucCountTime 	= 0;
}
//**************************************************************************************************
//��������	vLED_Update()
//˵  ����	����LED״̬���˺�����Ҫ�̶����ڵ��á�
//��  ����	My_LED_TypeDef* g_ptLED
//����ֵ�� ��
//**************************************************************************************************
void vLED_Update(My_LED_TypeDef* g_ptLED)
{		
	if(g_ptLED->ucCountTime < g_ptLED->ucOnTime)		
			{	
			//LED ��	
			if(g_ptLED->ucPhase)	Set(g_ptLED->uiGPIO);
			else									Ret(g_ptLED->uiGPIO);
			}

	else
			{	
			//LED ��		
			if(g_ptLED->ucPhase)	Ret(g_ptLED->uiGPIO);
			else									Set(g_ptLED->uiGPIO);
			}	
	g_ptLED->ucCountTime++;			
	if(g_ptLED->ucCountTime >= g_ptLED->ucOffTime)   
			{		
			//����������	
			g_ptLED->ucCountTime=0;	 
			}			
}

