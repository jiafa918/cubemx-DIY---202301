


#include "bsp_gpio.h"




/*****************************************************************************
*                         unsigned char tester (void)
* 功  能：Magnet_test的测试程序
* 说  明：
* 参  数：无
* 返回值：无
****************************************************************************/

InputPort Input;	//输入端口扫描
OutputPort Output;	//PCBd的输出口映射到结构体变量中

volatile int LastInputState = 0;  
volatile int  EdageX[18]={0};


/*******************************************************************************
功  能 : 扫描输入口的状态 端口扫描,将所有输入端口的状态存入结构体中
参  数 : 无
返回值 ：无
********************************************************************************/
void ScanInput(void)
{
	 X1  = ~IN1;
    X2  = ~IN2;
    X3  = ~IN3;
    X4  = ~IN4;
    X5  = ~IN5;
    X6  = ~IN6;
    X7  = ~IN7;
    X8  = ~IN8;
    X9  = ~IN9;
    X10 = ~IN10;
    X11 = ~IN11;
    X12 = ~IN12;
    X13 = ~IN13;
    X14 = ~IN14;
    X15 = ~IN15;
    X16 = ~IN16;

 	printf("Input.ALL is %05X\r\n",	Input.ALL); 
}

/*******************************************************************************
功  能 : 扫描输出口的状态 端口扫描,将所有输入端口的状态存入结构体中
参  数 : 无
返回值 ：无
********************************************************************************/
void ScanOutput(void)
{
//    OUT1 =  Y1;				
//    OUT2 =  Y2;		
//    OUT3 =  Y3;		
    OUT4=   !Y4;				
    OUT5 =  !Y5;		
    OUT6 =  !Y6;	
    OUT7 =  !Y7;				
    OUT8 =  !Y8;		
    OUT9 =  !Y9;					
    OUT10 = !Y10;		
    OUT11 = !Y11;		
    OUT12 = !Y12;		
    OUT13 = !Y13;		
    OUT14 = !Y14;		
    OUT15 = !Y15;		
    OUT16 = !Y16;		

 	printf("Output.ALL is %05X\r\n",	Output.ALL); 
}

/*******************************************************************************
功  能 : 根据变量扫描所有输出
参  数 : 无
返回值 ：无
********************************************************************************/
void SetOutput(unsigned char Channel,unsigned char ONOFF)
{
   int Output = ONOFF? Output | (1 << Channel-1): Output & ~(1<< Channel-1);
    ScanOutput();
}


/*******************************************************************************
功  能 : 捕捉IO的边沿  上升沿  下降沿  无变化 
执行完该函数后一定要清空所有边沿 ClearIOEdage
if(EdageX[0] == InputEdgeUp)
参  数 : 无
返回值 ：无
********************************************************************************/
 void GetIOEdage(void)
 {
    char edageIndex = 0;
	  char index = 0;

	  for(index = 0;index < 16;index++)
	  {
	  	 edageIndex = index;
	  	 if(GetBit(Input.ALL, index) > 0)	  //该次扫描为高电平
		   {	    	
					if(GetBit(LastInputState, index) == 0)	//上次为低电平 
					{
						EdageX[edageIndex] = InputEdgeUp;
//						printf("上升沿输入序号： %d\r\n",edageIndex);  //打印所有输入口的状态，无InputEdgeNone(0)   InputEdgeUp(1)  InputEdgeDown(2)
					}
					SetBit(LastInputState, index);
		  }
		  else   //该次扫描为低电平
		  {	   	
		    if(GetBit(LastInputState, index) > 0) //上次为高电平 
				{
					EdageX[edageIndex] = InputEdgeDown;
//					printf("下降沿输入序号： %d\r\n",edageIndex);  //打印所有输入口的状态，无InputEdgeNone(0)   InputEdgeUp(1)  InputEdgeDown(2)
				}	 
			    ClrBit(LastInputState, index);
		  }
	  }
 }
 
 
 /*******************************************************************************
功  能 : 清除IO边沿信息
参  数 : 无
返回值 ：无
********************************************************************************/
 void ClearIOEdage(void) 
 {
	  char index = 0;
	  for( index = 0;index < 18;index++ )
	  {	 
			EdageX[index] =InputEdgeNone;
	  }
 }
 

 /********************************************************************************            
 * 功  能：GPIO外部中断输入
* 参  数：无
* 返回值：无
*********************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}
