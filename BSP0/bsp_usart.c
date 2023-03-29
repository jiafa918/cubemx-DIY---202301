#include "bsp_usart.h"

extern UART_HandleTypeDef huart1;

//MSComm_Config MSComm1,MSComm2,MSComm3,MSComm4,MSComm5;
//uint8_t BufferRxChar[5];  //每接收一个字符放入BufferRxChar[0]中
//unsigned char CharCRLF[2] = {0x0D,0x0A};  //回车换行


/////* 在我们的工程中 __GNUC__ 肯定是定义了的，因此这一段其实就只有 #define PUTCHAR_PROTOTYPE int __io_putchar(int ch) 生效了 */
/////* Private function prototypes -----------------------------------------------*/
////#ifdef __GNUC__
/////* With GCC, small printf (option LD Linker->Libraries->Small printf
////   set to 'Yes') calls __io_putchar() */
////#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
////#else
////#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
////#endif /* __GNUC__ */


/////* 这里写了 PUTCHAR_PROTOTYPE ,这不就是上面定义的那个宏吗，也就是说这里重写了 int __io_putchar(int ch) 这个函数，但是这跟 printf() 有什么关系呢？ */
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
 * 功  能：重定义printf函数  注意在option for target里勾选Use MicroLib
 * 参  数：ch----发送单个字符
 * 返回值：无
 ****************************************************************************/
 int fputc(int ch,FILE *f)
 {
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart1,temp,1,2);        //UartHandle是串口的句柄
 		return 1;
 }


 /*****************************************************************************
 * 功  能：重定义scanf函数  注意在option for target里勾选Use MicroLib
 * 参  数：ch----发送单个字符
 * 返回值：无
 ****************************************************************************/
 int fgetc(FILE *f)
 {
    uint8_t temp[1];
 		HAL_UART_Receive(&huart1,temp,1,2);        //UartHandle是串口的句柄
 		return temp[0];
 }





///*****************************************************************************
//* 功  能：UART1发送字符串
//* 参  数：*String----发送字符串  0xffff为timeout的最大值
//* 返回值：无
//****************************************************************************/
//void MSComm1_Send_String(char *String)
//{
//	HAL_UART_Transmit(&huart1,(unsigned char*)String ,Len((char*)String),0xffff);
//}


///*****************************************************************************
//* 功  能：UART1发送字符数组
//* 参  数：*String:发送字符数组  MSComm1.TX_Len：发送字符数组长度   0xffff:timeout的最大值
//* 返回值：无
//****************************************************************************/
//void MSComm1_Send_Bytes(char *String)
//{
//	HAL_UART_Transmit(&huart1,(unsigned char*)String ,MSComm1.TX_Len,0xffff);
//}


///*****************************************************************************
//* 功  能：UART1发送回车换行
//* 参  数：*String----发送字符串  0xffff为timeout的最大值
//* 返回值：无
//****************************************************************************/
//void MSComm1_Send_CRLF(void)
//{
//	HAL_UART_Transmit(&huart1,CharCRLF,2,0xffff);  //发送回车换行
//}



///*****************************************************************************
//*                      UART接收回调函数(接收中断)
//* 功  能：每接收一个字符进入一次串口中断  
//* 参  数：
//* 返回值：无
//****************************************************************************/
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
//{
//	 unsigned char temp;   //串口接收数据放入缓存中  	
////USB*************************************************************************************************************************************
//	 if(huart->Instance == USART1)  
//	 {
//		  temp = BufferRxChar[0];    //每接收一个字符进一次中断放入temp中
//			if(MSComm1.Mode == ASCII)  //**************************************ASCII处理
//			{  
//					if(temp == 0x0A)              //接收到结束标志,则表示接收完成 (temp == 0x0D)  
//					{
//						MSComm1.RX_Flag =  MSComm1.RX_Len>0? 1: 0;    //如果接收存储区有数据,表示成功接收到一次  
//  					MSComm1.Receiving = 1;                        //关闭T1的计数
//						MSComm1.RX_Str[MSComm1.RX_Len] = '\0';        //添加结束符
//						MSComm1.RX_Len = 0;
//					}
//					else if(temp == 0x0D)          //接收到CR结束符
//					{
//						;
//					}
//					else
//					{
//							MSComm1.RX_Str[MSComm1.RX_Len] = temp;     //保存数据
//							MSComm1.RX_Len ++;
//							if(MSComm1.RX_Len >= 100)                   //接收数据不正确, 就将接收存储区全清掉
//							{
//									MSComm1.RX_Len = 0;
//  								MSComm1.Receiving = 0;
//							}
//					}
//			 }
//			 if(MSComm1.Mode == RTU)  //**************************************RTU处理
//			 {
//					MSComm1.RX_Chr[MSComm1.RX_Len++] = temp;
//					if(MSComm1.RX_Len >= 100)
//					{
//							MSComm1.RX_Len = 0;
//							MSComm1.Receiving = 0;
//					}
//       }
//		   HAL_UART_Receive_IT(&huart1,&BufferRxChar[0],1);  //每次接收字符后保证下次接收字符还能进入中断			 
//		}	 
//}

