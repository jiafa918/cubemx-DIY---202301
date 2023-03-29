#include "bsp_usart.h"
#include "bsp_timer.h"
#include "main.h"

unsigned int LED_State_Count,LED_State_Flag = 0;
unsigned int PluseState = 1;
unsigned int none_input_update_flag = 1;  //1:R G Y均无输入时更新队列标志位 0:R G Y均无输入时不更新队列标志位

My_Timer mytimer_r,mytimer;  //程序中可能用到的定时时间

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim8;

uint8_t i = 0;

// 定义PWM变量
unsigned int pwmCnt = 0;
unsigned int pwmVal = 0;
unsigned int pwmDir = 0;
My_Timer MyTimer1,MyTimer2,MyTimer3,MyTimer4;  //程序中可能用到的四个定时时间

/*****************************************************************************
* 功  能：启动定时中断Time2 采用内部时钟  定时中断优先级最高为0
* 参  数：
* 返回值：
****************************************************************************/
void MyTIME_Init(void)
{
    HAL_TIM_Base_Start_IT(&htim2);
}

/*****************************************************************************
* 功  能:10mS一次中断
* 参  数：
* 返回值：无
****************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    static unsigned int count = 0;

    if (htim->Instance == TIM2)  //****************************************MCU状态指示灯闪烁，上电时快闪  稳定后慢闪
    {
        count++;
        if(count == LED_State_Count)
        {
            count = 0;
//				  LEDStateToggle;  //LED状态指示灯状态取反
        }

        //******************************************************程序中可能用到独立的4个定时时间
        ((MyTimer1.Enable > 0))?  MyTimer1.TimerCount++  :  (MyTimer1.TimerCount = 0);
        ((MyTimer2.Enable > 0))?  MyTimer2.TimerCount++  :  (MyTimer2.TimerCount = 0);
        ((MyTimer3.Enable > 0))?  MyTimer3.TimerCount++  :  (MyTimer3.TimerCount = 0);
        ((MyTimer4.Enable > 0))?  MyTimer4.TimerCount++  :  (MyTimer4.TimerCount = 0);
    }

    if (htim->Instance == htim1.Instance)
    {
        HAL_GPIO_TogglePin(ERRLED_GPIO_Port, ERRLED_Pin);
    }
    if (htim->Instance == htim2.Instance)
    {
        HAL_GPIO_TogglePin(RUNLED_GPIO_Port, RUNLED_Pin);
        count++;
        if(count == LED_State_Count)
        {
            count = 0;
//				  LEDStateToggle;  //LED状态指示灯状态取反
        }

        //*******************************程序中可能用到独立的4个定时时间***********************
        ((MyTimer1.Enable > 0))?  MyTimer1.TimerCount++  :  (MyTimer1.TimerCount = 0);
        ((MyTimer2.Enable > 0))?  MyTimer2.TimerCount++  :  (MyTimer2.TimerCount = 0);
        ((MyTimer3.Enable > 0))?  MyTimer3.TimerCount++  :  (MyTimer3.TimerCount = 0);
        ((MyTimer4.Enable > 0))?  MyTimer4.TimerCount++  :  (MyTimer4.TimerCount = 0);

    }
    if (htim->Instance == htim3.Instance)
    {
//        HAL_GPIO_TogglePin(O9_GPIO_Port, O9_Pin);   // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O10_GPIO_Port, O10_Pin); // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O11_GPIO_Port, O11_Pin); // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O12_GPIO_Port, O12_Pin); // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O13_GPIO_Port, O13_Pin); // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O14_GPIO_Port, O14_Pin); // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O15_GPIO_Port, O15_Pin); // 开启定时器5  控制LED闪烁
//        HAL_GPIO_TogglePin(O16_GPIO_Port, O16_Pin); // 开启定时器5  控制LED闪烁
    }
    if (htim->Instance == htim4.Instance)
    {
//        HAL_GPIO_TogglePin(O4_GPIO_Port, O4_Pin); // 开启定时器5  控制LED闪烁
        //    HAL_GPIO_TogglePin(Y14_GPIO_Port,Y14_Pin);
    }
//    if (htim->Instance == htim5.Instance)
//    {
//        HAL_GPIO_TogglePin(O5_GPIO_Port, O5_Pin); // 开启定时器5  控制LED闪烁
//    }
//    if (htim->Instance == htim6.Instance)
//    {
//        HAL_GPIO_TogglePin(O6_GPIO_Port, O6_Pin); // 开启定时器5  控制LED闪烁
//        //    HAL_GPIO_TogglePin(Y14_GPIO_Port,Y14_Pin);
//    }
//    if (htim->Instance == htim7.Instance)
//    {
//        HAL_GPIO_TogglePin(O7_GPIO_Port, O7_Pin); // 开启定时器5  控制LED闪烁
//        //    HAL_GPIO_TogglePin(Y14_GPIO_Port,Y14_Pin);
//    }
//    if (htim->Instance == htim8.Instance)
//    {
//        HAL_GPIO_TogglePin(O8_GPIO_Port, O8_Pin); // 开启定时器5  控制LED闪烁

//    }
}

