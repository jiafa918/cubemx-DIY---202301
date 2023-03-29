#include "bsp_usart.h"

extern UART_HandleTypeDef huart1;

//MSComm_Config MSComm1,MSComm2,MSComm3,MSComm4,MSComm5;
//uint8_t BufferRxChar[5];  //ÿ����һ���ַ�����BufferRxChar[0]��
//unsigned char CharCRLF[2] = {0x0D,0x0A};  //�س�����


/////* �����ǵĹ����� __GNUC__ �϶��Ƕ����˵ģ������һ����ʵ��ֻ�� #define PUTCHAR_PROTOTYPE int __io_putchar(int ch) ��Ч�� */
/////* Private function prototypes -----------------------------------------------*/
////#ifdef __GNUC__
/////* With GCC, small printf (option LD Linker->Libraries->Small printf
////   set to 'Yes') calls __io_putchar() */
////#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
////#else
////#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
////#endif /* __GNUC__ */


/////* ����д�� PUTCHAR_PROTOTYPE ,�ⲻ�������涨����Ǹ�����Ҳ����˵������д�� int __io_putchar(int ch) ���������������� printf() ��ʲô��ϵ�أ� */
////PUTCHAR_PROTOTYPE
////{
////   HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
////   return ch;
////}

////__attribute__((weak)) int _write(int file, char *ptr, int len)
////{
////   int DataIdx;
////   for (DataIdx = 0; DataIdx < len; DataIdx++)
////   {
////      putchar(*ptr++);
////   }
////   return len;
////}



 /*****************************************************************************
 * ��  �ܣ��ض���printf����  ע����option for target�ﹴѡUse MicroLib
 * ��  ����ch----���͵����ַ�
 * ����ֵ����
 ****************************************************************************/
 int fputc(int ch,FILE *f)
 {
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart1,temp,1,2);        //UartHandle�Ǵ��ڵľ��
 		return 1;
 }


 /*****************************************************************************
 * ��  �ܣ��ض���scanf����  ע����option for target�ﹴѡUse MicroLib
 * ��  ����ch----���͵����ַ�
 * ����ֵ����
 ****************************************************************************/
 int fgetc(FILE *f)
 {
    uint8_t temp[1];
 		HAL_UART_Receive(&huart1,temp,1,2);        //UartHandle�Ǵ��ڵľ��
 		return temp[0];
 }





///*****************************************************************************
//* ��  �ܣ�UART1�����ַ���
//* ��  ����*String----�����ַ���  0xffffΪtimeout�����ֵ
//* ����ֵ����
//****************************************************************************/
//void MSComm1_Send_String(char *String)
//{
//	HAL_UART_Transmit(&huart1,(unsigned char*)String ,Len((char*)String),0xffff);
//}


///*****************************************************************************
//* ��  �ܣ�UART1�����ַ�����
//* ��  ����*String:�����ַ�����  MSComm1.TX_Len�������ַ����鳤��   0xffff:timeout�����ֵ
//* ����ֵ����
//****************************************************************************/
//void MSComm1_Send_Bytes(char *String)
//{
//	HAL_UART_Transmit(&huart1,(unsigned char*)String ,MSComm1.TX_Len,0xffff);
//}


///*****************************************************************************
//* ��  �ܣ�UART1���ͻس�����
//* ��  ����*String----�����ַ���  0xffffΪtimeout�����ֵ
//* ����ֵ����
//****************************************************************************/
//void MSComm1_Send_CRLF(void)
//{
//	HAL_UART_Transmit(&huart1,CharCRLF,2,0xffff);  //���ͻس�����
//}



///*****************************************************************************
//*                      UART���ջص�����(�����ж�)
//* ��  �ܣ�ÿ����һ���ַ�����һ�δ����ж�  
//* ��  ����
//* ����ֵ����
//****************************************************************************/
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	 unsigned char temp;   //���ڽ������ݷ��뻺����  	
////USB*************************************************************************************************************************************
//	 if(huart->Instance == USART1)  
//	 {
//		  temp = BufferRxChar[0];    //ÿ����һ���ַ���һ���жϷ���temp��
//			if(MSComm1.Mode == ASCII)  //**************************************ASCII����
//			{  
//					if(temp == 0x0A)              //���յ�������־,���ʾ������� (temp == 0x0D)  
//					{
//						MSComm1.RX_Flag =  MSComm1.RX_Len>0? 1: 0;    //������մ洢��������,��ʾ�ɹ����յ�һ��  
//  					MSComm1.Receiving = 1;                        //�ر�T1�ļ���
//						MSComm1.RX_Str[MSComm1.RX_Len] = '\0';        //��ӽ�����
//						MSComm1.RX_Len = 0;
//					}
//					else if(temp == 0x0D)          //���յ�CR������
//					{
//						;
//					}
//					else
//					{
//							MSComm1.RX_Str[MSComm1.RX_Len] = temp;     //��������
//							MSComm1.RX_Len ++;
//							if(MSComm1.RX_Len >= 100)                   //�������ݲ���ȷ, �ͽ����մ洢��ȫ���
//							{
//									MSComm1.RX_Len = 0;
//  								MSComm1.Receiving = 0;
//							}
//					}
//			 }
//			 if(MSComm1.Mode == RTU)  //**************************************RTU����
//			 {
//					MSComm1.RX_Chr[MSComm1.RX_Len++] = temp;
//					if(MSComm1.RX_Len >= 100)
//					{
//							MSComm1.RX_Len = 0;
//							MSComm1.Receiving = 0;
//					}
//       }
//		   HAL_UART_Receive_IT(&huart1,&BufferRxChar[0],1);  //ÿ�ν����ַ���֤�´ν����ַ����ܽ����ж�			 
//		}	 
//}

