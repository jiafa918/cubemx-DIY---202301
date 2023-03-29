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
//    unsigned long  BPS;                        //������
//    unsigned char PDS;                         //У�鷽ʽ
//    unsigned char DataLen;                     //���ݳ���
//    unsigned char StopBit;                     //ֹͣλ����
    unsigned char Mode;                          //���ݸ�ʽ:ASCII or RTU
             char RX_Str[100];                   //�������ݻ�����,ASCII
             char TX_Str[100];                   //�������ݻ�����,ASCII
    unsigned char RX_Chr[100];                   //�������ݻ�����,RTU
    unsigned char TX_Chr[100];                   //�������ݻ�����,RTU
             char RX_Len;                        //���յ�����������
    unsigned char TX_Len;                        //Ҫ���͵���������,ASCIIģʽ�¿��Բ���
    unsigned char RX_Flag;                       //������ɱ�־
    unsigned char Receiving;                     //�����еı�־
    unsigned char RX_Timer;                      //�����ַ����ռ���ڶ�ʱ�������жϵĴ���,�����ж������Ƿ�������
//    unsigned char TX_IE;                       //�����ж�ʹ��
//    unsigned char TX_IP;                       //�����ж����ȼ�
//    unsigned char RX_IE;                       //�����ж�ʹ��
//    unsigned char RX_IP;                       //�����ж����ȼ�
}MSComm_Config; 

extern MSComm_Config MSComm1,MSComm2,MSComm3,MSComm4,MSComm5;    //�������ڵ��������
//extern char BufferRxChar[2];  //ÿ����һ���ַ�����BufferRxChar[0]��
extern uint8_t BufferRxChar[5];  //��Ӧ5������

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

extern int fputc(int ch,FILE *f);  //�ض���printf����

int Handle_UART1();

#endif
