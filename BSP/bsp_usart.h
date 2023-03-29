#ifndef __bsp_usart_H
#define __bsp_usart_H	 

#include "bsp.h"
#include "stm32f1xx_hal_uart.h"


//extern UART_HandleTypeDef huart1;

#define uart_debug        &huart1
//#define uart_rf           &huart3


#define ASCII   0
#define RTU     1

 
typedef struct
{
//    unsigned long  BPS;                        //波特率
//    unsigned char PDS;                         //校验方式
//    unsigned char DataLen;                     //数据长度
//    unsigned char StopBit;                     //停止位长度
    unsigned char Mode;                          //数据格式:ASCII or RTU
             char RX_Str[100];                   //接收数据缓冲区,ASCII
             char TX_Str[100];                   //发送数据缓冲区,ASCII
    unsigned char RX_Chr[100];                   //接收数据缓冲区,RTU
    unsigned char TX_Chr[100];                   //发送数据缓冲区,RTU
             char RX_Len;                        //接收到的数据数量
    unsigned char TX_Len;                        //要发送的数据数量,ASCII模式下可以不用
    unsigned char RX_Flag;                       //接收完成标志
    unsigned char Receiving;                     //接收中的标志
    unsigned char RX_Timer;                      //两个字符接收间隔期定时器发生中断的次数,用于判断数据是否接收完成
//    unsigned char TX_IE;                       //发送中断使能
//    unsigned char TX_IP;                       //发送中断优先级
//    unsigned char RX_IE;                       //接收中断使能
//    unsigned char RX_IP;                       //接收中断优先级
}MSComm_Config; 

extern MSComm_Config MSComm1,MSComm2,MSComm3,MSComm4,MSComm5;    //三个串口的相关数据
//extern char BufferRxChar[2];  //每接收一个字符放入BufferRxChar[0]中
extern uint8_t BufferRxChar[5];  //对应5个串口

extern void MSComm1_Send_String(char *String);
extern void MSComm1_Send_Bytes(char *String);
extern void MSComm1_Send_CRLF(void);


extern void MSComm2_Send_String(char *String);
extern void MSComm2_Send_Bytes(char *String);
extern void MSComm2_Send_CRLF(void);

extern void MSComm3_Send_String(char *String);
extern void MSComm3_Send_CRLF(void);
extern void MSComm3_Send_Bytes(char *String,int16_t length);

extern void my_printf(UART_HandleTypeDef *huart,const char *format, ...);

extern int fputc(int ch,FILE *f);  //重定义printf函数

int Handle_UART1();

#endif
