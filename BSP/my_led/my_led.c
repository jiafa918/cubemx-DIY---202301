//**************************************************************************************************
//#include "my_stm32f1_gpio.h"
#include "my_led.h"



//**************************************************************************************************
//函数名：	vLED_Init()
//说  明：	LED初始化
//参  数：	My_LED_TypeDef* g_ptLED：LED编号
//返回值：	无
//**************************************************************************************************
void vLED_Init(My_LED_TypeDef* g_ptLED)
{
	//端口初始化
  vGPIO_Init(g_ptLED->uiGPIO, PP_OUT_2MHZ, 1);
	//LED 灭		
	if(g_ptLED->ucPhase)	Ret(g_ptLED->uiGPIO);
	else									Set(g_ptLED->uiGPIO);
}

//**************************************************************************************************
//函数名：	vLED_On()
//说  明：点亮LED
//参  数：My_LED_TypeDef* g_ptLED：LED编号
//返回值： 无
//**************************************************************************************************
void vLED_On(My_LED_TypeDef* g_ptLED)
{
	//LED 亮	
	if(g_ptLED->ucPhase)	Set(g_ptLED->uiGPIO);
	else									Ret(g_ptLED->uiGPIO);
	
	g_ptLED->ucOnTime = 100;
	g_ptLED->ucOffTime = 0;
	g_ptLED->ucCountTime = 0;
}
//**************************************************************************************************
//函数名：	vLED_Off()
//说  明：关闭LED
//参  数：	My_LED_TypeDef* g_ptLED：LED编号
//返回值： 无
//**************************************************************************************************
void vLED_Off(My_LED_TypeDef* g_ptLED)
{
	//LED 灭	
	if(g_ptLED->ucPhase)	Ret(g_ptLED->uiGPIO);
	else									Set(g_ptLED->uiGPIO);
	
	g_ptLED->ucOnTime = 0;
	g_ptLED->ucOffTime = 100;
	g_ptLED->ucCountTime = 0;
}
//**************************************************************************************************
//函数名：	vLED_Flash()
//说  明：	LED闪烁
//参  数：	My_LED_TypeDef* g_ptLED：LED编号
//				unsigned int  Ontime：亮灯持续时间,时间单位为vLED_Update函数的调用周期
//				unsigned int  Offtime：熄灯的持续时间,时间单位为vLED_Update函数的调用周期
//返回值： 无
//**************************************************************************************************
void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime,unsigned int  Offtime)
{
	g_ptLED->ucOnTime 		= Ontime;
	g_ptLED->ucOffTime 		= Ontime+Offtime;
	g_ptLED->ucCountTime 	= 0;
}
//**************************************************************************************************
//函数名：	vLED_Update()
//说  明：	跟新LED状态，此函数需要固定周期调用。
//参  数：	My_LED_TypeDef* g_ptLED
//返回值： 无
//**************************************************************************************************
void vLED_Update(My_LED_TypeDef* g_ptLED)
{		
	if(g_ptLED->ucCountTime < g_ptLED->ucOnTime)		
			{	
			//LED 亮	
			if(g_ptLED->ucPhase)	Set(g_ptLED->uiGPIO);
			else									Ret(g_ptLED->uiGPIO);
			}

	else
			{	
			//LED 灭		
			if(g_ptLED->ucPhase)	Ret(g_ptLED->uiGPIO);
			else									Set(g_ptLED->uiGPIO);
			}	
	g_ptLED->ucCountTime++;			
	if(g_ptLED->ucCountTime >= g_ptLED->ucOffTime)   
			{		
			//计数器清零	
			g_ptLED->ucCountTime=0;	 
			}			
}

