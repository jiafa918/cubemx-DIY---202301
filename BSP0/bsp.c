/*****************************************************************************
*STLINK  PIN1:VCC3V3  PIN7:SWDIO  PIN9:SWCLK  PIN20:GND
****************************************************************************/

#include "bsp.h"

#include "bsp_gpio.h"
//#include "string.h"

//# define BITBAND_REG(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (((uint32_t)&(Reg) - (uint32_t)0x40000000u)<<5) + (((uint32_t)(Bit))<<2))))	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED0 BITBAND_REG(GPIOC->ODR,6)	//Reg是操作部分的基地址，Bit就是第几位了
////# define LED1 BITBAND_REG(GPIOF->ODR,10)	//Reg是操作部分的基地址，Bit就是第几位了

	uint8_t i;
extern TIM_HandleTypeDef htim2;

/********************************************************************************
* 功  能：用户初始化程序
* 参  数：无
* 返回值：无
*********************************************************************************/
int wait_ready()	//	用户初始化程序
{
//    HAL_GPIO_WritePin(OUT01_GPIO_Port,OUT01_Pin,GPIO_PIN_SET);

    HAL_TIM_Base_Start_IT(&htim2);

    printf("The system init ok---\r\n");

}
/********************************************************************************
* 功  能：用户的loop程序
* 参  数：无
* 返回值：无
*********************************************************************************/
int work_flow()					//执行用户的loop程序
{

	
//    HAL_GPIO_TogglePin(OUT02_GPIO_Port,OUT02_Pin);
//    HAL_Delay(500);
ScanInput();
//    printf("STM32F103RCTX---\r\n");
//IN2=0;
//////	  OUT3(1);
//    HAL_Delay(200);
////    OUT3(0);
////    HAL_Delay(200);
//	HAL_GPIO_TogglePin(RGBLED_GPIO_Port,RGBLED_Pin);
//RGBLED=1;
////    OUT4(1);
//    HAL_Delay(200);
////    OUT4(0);
//RGBLED=0;
//BSP_LED_Toggle(2);

//	for(i=0;i<4;i++)
//	{
//	BSP_LED_Toggle(i);
//    HAL_Delay(100);		
//	};
	for(i=0;i<4;i++)
	{
	BSP_OUT_Toggle(i);
    HAL_Delay(100);		
	};
//	{LED4=!LED4;}
//	{LED[i]=!LED[i];}	

}



