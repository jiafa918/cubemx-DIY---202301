#ifndef __MY_LED_H
#define __MY_LED_H

//*******************************************************************************
//   LED结构体定义
//*******************************************************************************
typedef struct 
{
unsigned int  uiGPIO;						//LED端口	
unsigned int 	ucOnTime;					//LED点亮时间
unsigned int 	ucOffTime;				//LED熄灭时间
unsigned int 	ucCountTime;			//LED计时器
unsigned char ucPhase;					//相位,0表示IO低电平点亮LED,1表示IO高电平点亮LED
}My_LED_TypeDef;

//*******************************************************************************
//   函数声明
//*******************************************************************************
void vLED_Init(My_LED_TypeDef* g_ptLED);
void vLED_On(My_LED_TypeDef* g_ptLED);
void vLED_Off(My_LED_TypeDef* g_ptLED);
void vLED_Flash(My_LED_TypeDef* g_ptLED, unsigned int  Ontime, unsigned int  Offtime);
void vLED_Update(My_LED_TypeDef* g_ptLED);








#endif


