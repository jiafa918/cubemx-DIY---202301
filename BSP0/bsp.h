//ͷ�ļ���ֻ��š���������������š����塱��
//ͷ�ļ�ֻ�ܰ��������ͺ��������������ܰ������壬�����ڶ������ʱ�������ظ��������
//ע��ͷ�ļ���ֻ��������û�ж��壬���Ҳ�������ͷ�ļ��ж��庯����������ܶ಻��Ҫ���鷳
//���ᳫʹ��ȫ�ֱ�����������Ҫ��ͷ�ļ��г������� extern int value ����������

#ifndef __bsp_H
#define __bsp_H


#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#include "main.h"
#include "bsp_gpio.h"
//#include "bsp_led.h"
//#include "bsp_key.h"
#include "bsp_timer.h"
//#include "bsp_string.h"
#include "bsp_usart.h"


//#define TesterDebug   1     //printf��ӡʹ��

//extern uint8_t aRxBuffer[20];


//extern int8_t TesterMode ;


//extern UART_HandleTypeDef huart1;
//extern void vKEY_Scan(My_KEY_TypeDef* ptKEYx);
//extern unsigned char ucKEY_Short(My_KEY_TypeDef* ptKEYx);

int wait_ready();           //���Գ���
int work_flow();    //ִ�ж�������

//extern void TesterInt (void);        //���Գ�ʼ������
//extern void tester (void);           //���Գ���
//extern void testerProgress(void);    //ִ�ж�������
//extern int Handle_UART1(void);           //���ڽ��պ���
//extern int Handle_UART2(void);           //UART2���պ���

//uint32_t  BSP_GetVersion(void);

#endif

