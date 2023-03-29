#ifndef __bsp_timer_H
#define __bsp_timer_H

#include "bsp.h"
#include "bsp_gpio.h"

extern unsigned int LED_State_Count;
extern unsigned int PluseState;
extern void MyTIME_Init(void);
extern void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

typedef volatile struct
{
    char	   Enable;           //定时使能
    char	   edgeCount;        //边沿次数
    long long  TimerCount;       //定时计数
    char	   state;            //边沿次数  0：正在判断   1：固定电平状态  2：闪烁状态
    char	   update_flag;      //0:不更新数据记录  1：更新数据记录
    char	   flsh_flag;        //闪烁标志位
    char	   level_flag;       //闪烁标志位
} My_Timer;
extern  My_Timer MyTimer1,MyTimer2,MyTimer3,MyTimer4;  //程序中可能用到的四个定时时间

extern unsigned int none_input_update_flag;  //1:R G Y均无输入时更新队列标志位 0:R G Y均无输入时不更新队列标志位
#endif
