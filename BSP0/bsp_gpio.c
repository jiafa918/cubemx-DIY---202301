


#include "bsp_gpio.h"

//#include "main.h"


/*****************************************************************************
*                         unsigned char tester (void)
* 功  能：Magnet_test的测试程序
* 说  明：
* 参  数：无
* 返回值：无
****************************************************************************/

InputPort Input;	//输入端口扫描
OutputPort Output;	//PCBd的输出口映射到结构体变量中

//volatile int LastInputState = 0;  
//volatile int  EdageX[18]={0};

#define OUTn                             4
GPIO_TypeDef* OUT_PORT[OUTn] = {OUT1_GPIO_Port,
                                OUT2_GPIO_Port,
                                OUT3_GPIO_Port,
                                OUT4_GPIO_Port
                               };

const uint16_t OUT_PIN[LEDn] = {OUT1_Pin,
                                OUT2_Pin,
                                OUT3_Pin,
                                OUT4_Pin
                               };


GPIO_TypeDef* LED_PORT[LEDn] = {LED1_GPIO_PORT,
                                LED2_GPIO_PORT,
                                LED3_GPIO_PORT,
                                LED4_GPIO_PORT
                               };

const uint16_t LED_PIN[LEDn] = {LED1_PIN,
                                LED2_PIN,
                                LED3_PIN,
                                LED4_PIN
                               };

															 
															 
/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured.
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  */
void BSP_LED_Init(Led_TypeDef Led)
{

}

void BSP_LED_On(Led_TypeDef Led)
{
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

void BSP_LED_Off(Led_TypeDef Led)
{
    HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}

void BSP_LED_Toggle(Led_TypeDef Led)
{
    HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}

void BSP_OUT_Toggle(OUT_TypeDef Led)
{
    HAL_GPIO_TogglePin(OUT_PORT[Led], OUT_PIN[Led]);
}



/*******************************************************************************
功  能 : 扫描输入口的状态 端口扫描,将所有输入端口的状态存入结构体中
参  数 : 无
返回值 ：无
********************************************************************************/
void ScanInput(void)
{
    X1  = IN1;
    X2  = IN2;
    X3  = IN3;
    X4  = IN4;
//    X5  = IN5;
////    X5  = IN6;
////    X6  = IN7;
////    X7  = IN8;
////    X10 = IN9;
////    X11 = IN10;
////    X12 = IN11;
////    X13 = IN12;
////    X14 = IN13;
////    X15 = IN14;
////    X16 = IN15;
////    X17 = IN16;
//	printf("Input.ALL is 1234567\r\n"); 
	printf("Input.ALL is %07X\r\n",	Input.ALL); 
}

/*******************************************************************************
功  能 : 扫描输出口的状态 端口扫描,将所有输入端口的状态存入结构体中
参  数 : 无
返回值 ：无
********************************************************************************/
void ScanOutput(void)
{
//    Y1 =  O1;
//    O2 =  !Y2;
//    O3 =  !Y3;
//    O4 =  !Y4;		
//    OUT4(Y3);		
//    OUT5(Y4);		
//    OUT6(Y5);				
//    OUT7(Y6);		
//    OUT8(Y7);	
//	  OUT9(Y10);		
//    OUT10(Y11);		
//    OUT11(Y12);	
//	  OUT12(Y13);		
//    OUT13(Y14);		
//    OUT14(Y15);	
//	  OUT15(Y16);		
//    OUT16(Y17);
//    OUT7(PinState) =  !Y6;		
//    OUT8(PinState) =  !Y7;		
//    OUT9(PinState) =  !Y10;		
//    OUT10(PinState) = !Y11;		
//    OUT11(PinState) = !Y12;		
//    OUT12(PinState) = !Y13;		
//    OUT13(PinState) = !Y14;		
//    OUT14(PinState) = !Y15;		
//    OUT15(PinState) = !Y16;		
//    OUT16(PinState) = !Y17;		


}

///*******************************************************************************
//功  能 : 根据变量扫描所有输出
//参  数 : 无
//返回值 ：无
//********************************************************************************/
//void SetOutput(unsigned char Channel,unsigned char ONOFF)
//{
////    Output = ONOFF? Output | (1 << Channel-1): Output & ~(1<< Channel-1);
//    ScanOutput();
//}


///*******************************************************************************
//功  能 : 捕捉IO的边沿  上升沿  下降沿  无变化 
//执行完该函数后一定要清空所有边沿 ClearIOEdage
//if(EdageX[0] == InputEdgeUp)
//参  数 : 无
//返回值 ：无
//********************************************************************************/
// void GetIOEdage(void)
// {
//    char edageIndex = 0;
//	  char index = 0;

//	  for(index = 0;index < 16;index++)
//	  {
//	  	 edageIndex = index;
//	  	 if(GetBit(Input.ALL, index) > 0)	  //该次扫描为高电平
//		   {	    	
//					if(GetBit(LastInputState, index) == 0)	//上次为低电平 
//					{
//						EdageX[edageIndex] = InputEdgeUp;
////						printf("上升沿输入序号： %d\r\n",edageIndex);  //打印所有输入口的状态，无InputEdgeNone(0)   InputEdgeUp(1)  InputEdgeDown(2)
//					}
//					SetBit(LastInputState, index);
//		  }
//		  else   //该次扫描为低电平
//		  {	   	
//		    if(GetBit(LastInputState, index) > 0) //上次为高电平 
//				{
//					EdageX[edageIndex] = InputEdgeDown;
////					printf("下降沿输入序号： %d\r\n",edageIndex);  //打印所有输入口的状态，无InputEdgeNone(0)   InputEdgeUp(1)  InputEdgeDown(2)
//				}	 
//			    ClrBit(LastInputState, index);
//		  }
//	  }
// }
// 
// 
// /*******************************************************************************
//功  能 : 清除IO边沿信息
//参  数 : 无
//返回值 ：无
//********************************************************************************/
// void ClearIOEdage(void) 
// {
//	  char index = 0;
//	  for( index = 0;index < 18;index++ )
//	  {	 
//			EdageX[index] =InputEdgeNone;
//	  }
// }
// 

// /********************************************************************************            
// * 功  能：GPIO外部中断输入
//* 参  数：无
//* 返回值：无
//*********************************************************************************/
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
////	if(GPIO_Pin== GPIO_PIN_6)   //PA6下降沿中断
////	{
////		if(BigMotor_Set == 0)    //出料电机运行过程中
////		{		
////			BigMotor_Set = 1;
////			EXTRunFlag = 1;  //从匀速开始执行	
////			MotorMove(BigMotorType,MotorReverseDirection,MotorFEEDREXT * BigMotorMMPulse,RunSpeed);  //执行出料动作
////			BigMotor.OpticalInStopFlag = 1;
////			printf("BigMotorSensor On\r\n");
////		}
//		
////		if((BigMotor.Status != STOP) && (BigMotor_Set == 0))
////		{
////			BigMotor_Set = 1;
////			printf("BigMotorSensor On\r\n");
////			EXTRunFlag = 1;
////			MotorMove(BigMotorType,MotorReverseDirection,MotorFEEDREXT * BigMotorMMPulse,RunSpeed);
////			EXTRunFlag = 0;
////		}
////	}
//}
