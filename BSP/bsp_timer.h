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
    char	   Enable;           //��ʱʹ��
    char	   edgeCount;        //���ش���
    long long  TimerCount;       //��ʱ����
    char	   state;            //���ش���  0�������ж�   1���̶���ƽ״̬  2����˸״̬
    char	   update_flag;      //0:���������ݼ�¼  1���������ݼ�¼
    char	   flsh_flag;        //��˸��־λ
    char	   level_flag;       //��˸��־λ
} My_Timer;
extern  My_Timer MyTimer1,MyTimer2,MyTimer3,MyTimer4;  //�����п����õ����ĸ���ʱʱ��

extern unsigned int none_input_update_flag;  //1:R G Y��������ʱ���¶��б�־λ 0:R G Y��������ʱ�����¶��б�־λ
#endif
