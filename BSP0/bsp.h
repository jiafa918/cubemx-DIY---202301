//头文件中只存放“声明”，而不存放“定义”。
//头文件只能包含变量和函数的声明，不能包含定义，否则在多次引入时会引起重复定义错误
//注意头文件中只是声明，没有定义，而且不建议在头文件中定义函数，会引起很多不必要的麻烦
//不提倡使用全局变量，尽量不要在头文件中出现现象 extern int value 这类声明。

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


//#define TesterDebug   1     //printf打印使用

//extern uint8_t aRxBuffer[20];


//extern int8_t TesterMode ;


//extern UART_HandleTypeDef huart1;
//extern void vKEY_Scan(My_KEY_TypeDef* ptKEYx);
//extern unsigned char ucKEY_Short(My_KEY_TypeDef* ptKEYx);

int wait_ready();           //测试程序
int work_flow();    //执行动作程序

//extern void TesterInt (void);        //测试初始化程序
//extern void tester (void);           //测试程序
//extern void testerProgress(void);    //执行动作程序
//extern int Handle_UART1(void);           //串口接收函数
//extern int Handle_UART2(void);           //UART2接收函数

//uint32_t  BSP_GetVersion(void);

#endif

