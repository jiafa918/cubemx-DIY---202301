#include "bsp_usart.h"
#include "stdarg.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;

// #define RXBUFFERSIZE  256     //最大接收字节数
// char RxBuffer[RXBUFFERSIZE];   //接收数据
// uint8_t aRxBuffer;			//接收中断缓冲
// uint8_t Uart1_Rx_Cnt = 0;		//接收缓冲计数

#define APP_TX_DATA_SIZE 2048
uint8_t UserTxBufferFS[APP_TX_DATA_SIZE];

MSComm_Config MSComm1, MSComm2, MSComm3, MSComm4, MSComm5;

uint8_t BufferRxChar[5];                  // 每接收一个字符放入BufferRxChar[0]中
unsigned char CharCRLF[2] = {0x0D, 0x0A}; // 回车换行

/*****************************************************************************
 * 功  能：UART1发送字符串
 * 参  数：*String----发送字符串  0xffff为timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm1_Send_String(char *String)
{
    HAL_UART_Transmit(&huart1, (unsigned char *)String, Len((char *)String), 0xffff);
}

/*****************************************************************************
 * 功  能：UART1发送字符数组
 * 参  数：*String:发送字符数组  MSComm1.TX_Len：发送字符数组长度   0xffff:timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm1_Send_Bytes(char *String)
{
    HAL_UART_Transmit(&huart1, (unsigned char *)String, MSComm1.TX_Len, 0xffff);
}

/*****************************************************************************
 * 功  能：UART1发送回车换行
 * 参  数：*String----发送字符串  0xffff为timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm1_Send_CRLF(void)
{
    HAL_UART_Transmit(&huart1, CharCRLF, 2, 0xffff); // 发送回车换行
}

/*****************************************************************************
 * 功  能：UART1发送字符串
 * 参  数：*String----发送字符串  0xffff为timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm2_Send_String(char *String)
{
    //	HAL_UART_Transmit(&huart2,(unsigned char*)String ,Len((char*)String),0xffff);
}

/*****************************************************************************
 * 功  能：UART1发送字符数组
 * 参  数：*String:发送字符数组  MSComm1.TX_Len：发送字符数组长度   0xffff:timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm2_Send_Bytes(char *String)
{
    //	HAL_UART_Transmit(&huart2,(unsigned char*)String ,MSComm2.TX_Len,0xffff);
}

/*****************************************************************************
 * 功  能：UART1发送回车换行
 * 参  数：*String----发送字符串  0xffff为timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm2_Send_CRLF(void)
{
    //	HAL_UART_Transmit(&huart2,CharCRLF,2,0xffff);  //发送回车换行
}

/*****************************************************************************
 * 功  能：UART1发送字符串
 * 参  数：*String----发送字符串  0xffff为timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm3_Send_String(char *String)
{
    HAL_UART_Transmit(&huart3, (unsigned char *)String, Len((char *)String), 0xffff);
}

/*****************************************************************************
 * 功  能：UART3发送字符数组
 * 参  数：*String:发送字符数组  MSComm2.TX_Len：发送字符数组长度   0xffff:timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm3_Send_Bytes(char *String, int16_t length)
{
    //    write_rf_flag = 0;
    //    memset(&rf_buff,0,20);   //清空rf_buff
    //    my_printf(uart_debug,"TX3:");
    Clear(MSComm3.RX_Str);
    HAL_UART_Transmit(&huart3, (unsigned char *)String, length, 0xffff);
    //    for(int i = 0; i < length; i++)
    //    {
    //        my_printf(uart_debug,"[%02X] ",*String++);
    //    }
    //	 my_printf(uart_debug,"\r\n");
}

/*****************************************************************************
 * 功  能：UART1发送回车换行
 * 参  数：*String----发送字符串  0xffff为timeout的最大值
 * 返回值：无
 ****************************************************************************/
void MSComm3_Send_CRLF(void)
{
    HAL_UART_Transmit(&huart3, CharCRLF, 2, 0xffff); // 发送回车换行
}

/*****************************************************************************
 * 功  能：重定义printf函数  注意在option for target里勾选Use MicroLib
 * 参  数：ch----发送单个字符
 * 返回值：无
 ****************************************************************************/
int fputc(int ch, FILE *f)
{
    uint8_t temp[1] = {ch};
    HAL_UART_Transmit(&huart1, temp, 1, 2); // UartHandle是串口的句柄
    return 1;
}

/*****************************************************************************
 * 功  能：重定义printf函数  可以映射到各个串口
 * 参  数：ch----发送单个字符
 * 返回值：无
 ****************************************************************************/
void my_printf(UART_HandleTypeDef *huart, const char *format, ...)
{
    va_list args;
    uint32_t length;
    va_start(args, format);
    length = vsnprintf((char *)UserTxBufferFS, APP_TX_DATA_SIZE, (char *)format, args);
    va_end(args);
    HAL_UART_Transmit(huart, UserTxBufferFS, length, 0xffff); // 只需要更改这儿就能一直到其他平台
}

/*****************************************************************************
 * 功  能：重定义scanf函数  注意在option for target里勾选Use MicroLib
 * 参  数：ch----发送单个字符
 * 返回值：无
 ****************************************************************************/
int fgetc(FILE *f)
{
    uint8_t temp[1];
    HAL_UART_Receive(&huart1, temp, 1, 2); // UartHandle是串口的句柄
    return temp[0];
}

///////////////////////////////////////////////////////////////////////////////////
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    __NOP(); // test if we reach this position
}

/*****************************************************************************
 *                      UART接收回调函数(接收中断)
 * 功  能：每接收一个字符进入一次串口中断
 * 参  数：
 * 返回值：无
 ****************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    unsigned char temp; // 串口接收数据放入缓存中
    // USB********************************************************************************
    if (huart->Instance == USART1)
    {
        temp = BufferRxChar[0];    // 每接收一个字符进一次中断放入temp中
        if (MSComm1.Mode == ASCII) //**************************************ASCII处理
        {
            if (temp == 0x0A) // 判断接收到的数据是否为结束标志（0x0A，ASCII码中的换行符） (temp == 0x0D)
            {
                MSComm1.RX_Flag = ((MSComm1.RX_Len > 0) ? 1 : 0); // 如果接收到的数据存储区中有数据（即接收到了有效的数据），则将接收标志位设置为1，否则设置为0。
                MSComm1.Receiving = 1;                            // 关闭T1计数，表示接收完成。
                MSComm1.RX_Str[MSComm1.RX_Len] = '\0';            // 给接收到的数据添加结束符，将接收到的数据字符串的最后一个字符设置为'\0'。
                MSComm1.RX_Len = 0;                               // 将接收到的数据长度清零，为下一次接收做准备。
            }
            // 这段代码的作用是判断接收到的数据是否为结束标志，并将接收到的数据存储区清零，并添加结束符。
            else if (temp == 0x0D) // 接收到CR结束符
            {
                ;
            }
            else
            {
                MSComm1.RX_Str[MSComm1.RX_Len] = temp; // 保存数据 将接收到的数据保存到接收存储区数组中，存储区数组是一个字符型数组。
                MSComm1.RX_Len++;                      // 接收存储区数组长度加1。
                if (MSComm1.RX_Len >= 100)             // 判断接收存储区数组长度是否超过了100个字符。
                {
                    MSComm1.RX_Len = 0;    // 如果接收存储区数组长度超过了100个字符，则将数组长度清零。
                    MSComm1.Receiving = 0; // 将串口接收标志位清零，表示当前没有接收到数据。
                }
                // 这段代码的作用是将接收到的数据保存到接收存储区数组中，
                //并判断接收存储区数组长度是否超过了100个字符，如果超过了则将数组长度清零，并将接收标志位清零。
            }
        }
        if (MSComm1.Mode == RTU) //**************************************RTU处理
        {
            MSComm1.RX_Chr[MSComm1.RX_Len++] = temp;
            if (MSComm1.RX_Len >= 100)
            {
                MSComm1.RX_Len = 0;
                MSComm1.Receiving = 0;
            }
        }
        HAL_UART_Receive_IT(&huart1, &BufferRxChar[0], 1); // 每次接收字符后保证下次接收字符还能进入中断
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //    if(Uart1_Rx_Cnt >= 255)  //溢出判断
    //    {
    //        Uart1_Rx_Cnt = 0;
    ////		memset(RxBuffer,0x00,sizeof(RxBuffer));
    //        HAL_UART_Transmit(&huart1, (uint8_t *)"数据溢出", 10,0xFFFF);
    //    }
    //    else
    //    {
    //        RxBuffer[Uart1_Rx_Cnt++] = aRxBuffer;   //接收数据转存
    //        if((RxBuffer[Uart1_Rx_Cnt-1] == 0x0A)&&(RxBuffer[Uart1_Rx_Cnt-2] == 0x0D)) //判断结束位
    //        {
    //            HAL_UART_Transmit(&huart1, (uint8_t *)&RxBuffer, Uart1_Rx_Cnt,0xFFFF); //将收到的信息发送出去
    //            while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束
    //            Uart1_Rx_Cnt = 0;
    ////			memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
    //        }
    //    }
    //    HAL_UART_Receive_IT(&huart1, (uint8_t *)&aRxBuffer, 1);   //再开启接收中断
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/*****************************************************************************
 * 功  能：连接调试接口
 * 参  数：ch----发送单个字符
 * 返回值：0:正确命令   1：错误命令
 ****************************************************************************/
int Handle_UART1()
{
    char temp[4][20];             // 接收的字符串放在四个缓存中
    int OutputNum = 0;            // 用于记录输出次数；
    char temp_prmt[15][20] = {0}; // 接收的字符串放在四个缓存中 用于存储接收的字符串，共有十五个缓存；
    int32_t item;                 // 序列号  用于存储序列号；
    char buffer[15];              // 用于存储输入的字符串；

    Split(MSComm1.RX_Str, temp, ','); // UART1接收的字符按','分割 将串口接收到的字符串按照逗号进行分割，存储在 temp 数组中；
    //***************************调试命令---temp[0]*************************************************************
    if (StringCompare(temp[0], "get_version", 0) == 0) // 读程序版本号则使用 my_printf 函数将最新的编译时间输出到串口，然后返回 0；
    {
        my_printf(uart_debug, "uart_debug client Hex time: %s %s\r\n", __DATE__, __TIME__); // 获取最新一次的编译时间
        return 0;
    }

    if (StringCompare(temp[0], "get_in", 0) == 0) // 则使用 my_printf 函数将三个输入口的状态输出到串口，然后返回 0；
    {
        my_printf(uart_debug, "ok,get_in g_in[%d] \r\n", G_IN); // 三色灯输入口状态
        return 0;
    }
    //***************************调试命令----temp[1]*************************************************************
    if (StringCompare(temp[0], "set", 0) == 0) // 如果temp[0]表示的字符串与"set"相等（使用StringCompare函数比较）
    {
       Output.ALL = atoi(temp[1]);    //将temp[1]表示的字符串转换为整数类型（使用atoi函数），并将其赋值给Output.ALL。
			Output.ALL = atoi(temp[2]);    //将temp[1]表示的字符串转换为整数类型（使用atoi函数），并将其赋值给Output.ALL。
        my_printf(uart_debug, "ok,set Output %d \r\n", temp[1]); // 三色灯输入口状态
        return 0;
    }
    //***************************异常命令*************************************************************
    else
    {
        my_printf(uart_debug, "NG,%s,%s,%s\r\n", temp[0], temp[1], temp[2]);
        //	        printf("NG,%s,%s,%s\r\n", temp[0], temp[1], temp[2]);
        printf("6*********************\r\n");
        return 0;
    }
}
