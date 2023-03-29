#include "bsp_usart.h"
#include "bsp_timer.h"
#include "main.h"

extern TIM_HandleTypeDef htim2;

//unsigned int LED_State_Count,LED_State_Flag = 0;
//unsigned int PluseState = 1;

// My_Timer MyTimer1,MyTimer2,MyTimer3,MyTimer4;  //程序中可能用到的四个定时时间

///*****************************************************************************                    
//* 功  能：启动定时中断Time2 采用内部时钟  定时中断优先级最高为0
//* 参  数：
//* 返回值：
//****************************************************************************/
//void MyTIME_Init(void)
//{
//	HAL_TIM_Base_Start_IT(&htim2);
//}


///*****************************************************************************                       
//* 功  能:10mS一次中断
//* 参  数：
//* 返回值：无
//****************************************************************************/
//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
//{
//  static unsigned int count = 0;
//	
//	if (htim->Instance == TIM2)  //****************************************MCU状态指示灯闪烁，上电时快闪  稳定后慢闪
//	{
//			count++;
//			if(count == LED_State_Count)
//			{
//					count = 0;
////				  LEDStateToggle;  //LED状态指示灯状态取反
//			}
//			
//			//******************************************************程序中可能用到独立的4个定时时间
//			((MyTimer1.Enable > 0))?  MyTimer1.TimerCount++  :  (MyTimer1.TimerCount = 0);
//			((MyTimer2.Enable > 0))?  MyTimer2.TimerCount++  :  (MyTimer2.TimerCount = 0);
//			((MyTimer3.Enable > 0))?  MyTimer3.TimerCount++  :  (MyTimer3.TimerCount = 0);
//			((MyTimer4.Enable > 0))?  MyTimer4.TimerCount++  :  (MyTimer4.TimerCount = 0);
//	}
//}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
//    if(htim->Instance == htim1.Instance)
//    {
////	HAL_GPIO_TogglePin(M_O5_GPIO_Port,M_O5_Pin); //开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(RUNLED_GPIO_Port,RUNLED_Pin);
//		}
    if(htim->Instance == htim2.Instance)
    {
//	HAL_GPIO_TogglePin(M_O5_GPIO_Port,M_O5_Pin); //开启定时器5  控制LED闪烁
        HAL_GPIO_TogglePin(STATE_GPIO_Port,STATE_Pin);
    }
//    if(htim->Instance == htim3.Instance)
//    {
////	HAL_GPIO_TogglePin(M_O5_GPIO_Port,M_O5_Pin); //开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(M_O13_GPIO_Port,M_O13_Pin);
//    }
//    if(htim->Instance == htim4.Instance)
//    {
////	HAL_GPIO_TogglePin(M_O5_GPIO_Port,M_O5_Pin); //开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(M_O14_GPIO_Port,M_O14_Pin);
//    }
//    if(htim->Instance == htim5.Instance)
//    {
////		HAL_GPIO_TogglePin(RUNLED_GPIO_Port,RUNLED_Pin);

////		HAL_UART_Transmit(&huart5, uart5_rxbuf, 10, 100);    // 把收到的字节原样发送出去
////		HAL_UART_Receive_IT(&huart5, uart5_rxbuf, 10);
////
//        HAL_GPIO_TogglePin(ERRLED_GPIO_Port,ERRLED_Pin); //开启定时器5  控制LED闪烁

//    }
}
