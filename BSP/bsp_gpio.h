#ifndef __bsp_gpio_H
#define __bsp_gpio_H

#include "main.h"
#include "stm32f1xx_hal_gpio.h"


//位带操作,实现51类似的GPIO控制功能
//具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).
//IO口操作宏定义
//// 把“位带地址+位序号”转换成别名地址的宏
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x02000000+((addr & 0x000FFFFF)<<5)+(bitnum<<2)) 
//// 把一个地址转换成一个指针
//#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
//// 把位带别名区地址转换成指针
//#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))
//// GPIO ODR 和 IDR 寄存器地址映射 

# define BITBAND_REG(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (((uint32_t)&(Reg) - (uint32_t)0x40000000u)<<5) + (((uint32_t)(Bit))<<2))))	//Reg是操作部分的基地址，Bit就是第几位了
//# define OUT4 BITBAND_REG(GPIOC->ODR,9)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED2 BITBAND_REG(GPIOA->ODR,15)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED3 BITBAND_REG(GPIOA->ODR,8)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED4 BITBAND_REG(GPIOE->ODR,0)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED5 BITBAND_REG(GPIOB->ODR,9)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED6 BITBAND_REG(GPIOB->ODR,8)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED7 BITBAND_REG(GPIOB->ODR,5)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED8 BITBAND_REG(GPIOB->ODR,4)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED9 BITBAND_REG(GPIOB->ODR,3)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED10 BITBAND_REG(GPIOD->ODR,7)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED11 BITBAND_REG(GPIOD->ODR,6)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED12 BITBAND_REG(GPIOD->ODR,5)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED13 BITBAND_REG(GPIOD->ODR,4)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED14 BITBAND_REG(GPIOD->ODR,3)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED15 BITBAND_REG(GPIOD->ODR,1)	//Reg是操作部分的基地址，Bit就是第几位了
//# define LED16 BITBAND_REG(GPIOD->ODR,0)	//Reg是操作部分的基地址，Bit就是第几位了




extern void ScanInput(void);  //扫描输入口的状态
extern void ScanOutput(void);
extern void SetOutput(unsigned char Channel,unsigned char ONOFF);

//********************************************************************输入端口扫描
typedef union
{
    struct
    {
        unsigned B1 :   1;
        unsigned B2 :   1;
        unsigned B3 :   1;
        unsigned B4 :   1;
        unsigned B5 :   1;
        unsigned B6 :   1;
        unsigned B7 :   1;
        unsigned B8 :   1;
        unsigned B9 :   1;
        unsigned B10 :  1;
        unsigned B11 :  1;
        unsigned B12 :  1;
        unsigned B13 :  1;
        unsigned B14 :  1;
        unsigned B15 :  1;
        unsigned B16 :  1;												      
    }OneBit;
     unsigned long ALL;
}InputPort;
extern InputPort Input;  //PCBd的输入口映射到结构体变量中


//GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
#define IN1  HAL_GPIO_ReadPin(I1_GPIO_Port,I1_Pin)   //低:有输入
#define IN2  HAL_GPIO_ReadPin(I2_GPIO_Port,I2_Pin)   //低:有输入
#define IN3  HAL_GPIO_ReadPin(I3_GPIO_Port,I3_Pin)   //低:有输入
#define IN4  HAL_GPIO_ReadPin(I4_GPIO_Port,I4_Pin)   //低:有输入
#define IN5  HAL_GPIO_ReadPin(I5_GPIO_Port,I5_Pin)   //低:有输入
#define IN6  HAL_GPIO_ReadPin(I6_GPIO_Port,I6_Pin)   //低:有输入
#define IN7  HAL_GPIO_ReadPin(I7_GPIO_Port,I7_Pin)   //低:有输入
#define IN8  HAL_GPIO_ReadPin(I8_GPIO_Port,I8_Pin)   //低:有输入
#define IN9  HAL_GPIO_ReadPin(I9_GPIO_Port,I9_Pin)   //低:有输入
#define IN10  HAL_GPIO_ReadPin(I10_GPIO_Port,I10_Pin)   //低:有输入
#define IN11  HAL_GPIO_ReadPin(I11_GPIO_Port,I11_Pin)   //低:有输入
#define IN12  HAL_GPIO_ReadPin(I12_GPIO_Port,I12_Pin)   //低:有输入
#define IN13  HAL_GPIO_ReadPin(I13_GPIO_Port,I13_Pin)   //低:有输入
#define IN14  HAL_GPIO_ReadPin(I14_GPIO_Port,I14_Pin)   //低:有输入
#define IN15  HAL_GPIO_ReadPin(I15_GPIO_Port,I15_Pin)   //低:有输入
#define IN16  HAL_GPIO_ReadPin(I16_GPIO_Port,I16_Pin)   //低:有输入


#define X1  Input.OneBit.B1
#define X2  Input.OneBit.B2
#define X3  Input.OneBit.B3
#define X4  Input.OneBit.B4
#define X5  Input.OneBit.B5
#define X6  Input.OneBit.B6
#define X7  Input.OneBit.B7
#define X8  Input.OneBit.B8
#define X9 Input.OneBit.B9
#define X10 Input.OneBit.B10
#define X11 Input.OneBit.B11
#define X12 Input.OneBit.B12
#define X13 Input.OneBit.B13
#define X14 Input.OneBit.B14
#define X15 Input.OneBit.B15
#define X16 Input.OneBit.B16

// #define Input   InputPort.ALL


//#define	X0_PORT		0
//#define	X1_PORT		1
//#define	X2_PORT		2
//#define	X3_PORT		3
//#define	X4_PORT		4
//#define	X5_PORT		5
//#define	X6_PORT		6
//#define	X7_PORT		7
//#define	X10_PORT	8
//#define	X11_PORT	9
//#define	X12_PORT	10
//#define	X13_PORT	11
//#define	X14_PORT	12
//#define	X15_PORT	13
//#define	X16_PORT	14
//#define	X17_PORT	15



////********************************************************************输出端口扫描
typedef union   
{
    struct
    {
        unsigned B1 :   1;
        unsigned B2 :   1;
        unsigned B3 :   1;
        unsigned B4 :   1;
        unsigned B5 :   1;
        unsigned B6 :   1;
        unsigned B7 :   1;
        unsigned B8 :   1;
        unsigned B9 :   1;
        unsigned B10 :  1;
        unsigned B11 :  1;
        unsigned B12 :  1;
        unsigned B13 :  1;
        unsigned B14 :  1;
        unsigned B15 :  1;
        unsigned B16 :  1;
    }OneBit;
     unsigned int ALL;
}OutputPort;
extern OutputPort Output;  //PCBd的输出口映射到结构体变量中



//void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
//#define	OUT1(PinState)		HAL_GPIO_WritePin(O1_GPIO_Port,O1_Pin,PinState)  //低:有输出
//#define	OUT16(PinState)		HAL_GPIO_WritePin(M_O16_GPIO_Port,M_O16_Pin,PinState)   //低:有输出


# define OUT4 BITBAND_REG(GPIOE->ODR,7)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT5 BITBAND_REG(GPIOB->ODR,9)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT6 BITBAND_REG(GPIOB->ODR,8)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT7 BITBAND_REG(GPIOB->ODR,5)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT8 BITBAND_REG(GPIOB->ODR,4)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT9 BITBAND_REG(GPIOB->ODR,3)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT10 BITBAND_REG(GPIOD->ODR,7)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT11 BITBAND_REG(GPIOD->ODR,6)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT12 BITBAND_REG(GPIOD->ODR,5)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT13 BITBAND_REG(GPIOD->ODR,4)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT14 BITBAND_REG(GPIOD->ODR,3)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT15 BITBAND_REG(GPIOD->ODR,1)	//Reg是操作部分的基地址，Bit就是第几位了
# define OUT16 BITBAND_REG(GPIOD->ODR,0)	//Reg是操作部分的基地址，Bit就是第几位了



#define Y1  Output.OneBit.B1
#define Y2  Output.OneBit.B2
#define Y3  Output.OneBit.B3
#define Y4  Output.OneBit.B4
#define Y5  Output.OneBit.B5
#define Y6  Output.OneBit.B6
#define Y7  Output.OneBit.B7
#define Y8  Output.OneBit.B8
#define Y9 Output.OneBit.B9
#define Y10 Output.OneBit.B10
#define Y11 Output.OneBit.B11
#define Y12 Output.OneBit.B12
#define Y13 Output.OneBit.B13
#define Y14 Output.OneBit.B14
#define Y15 Output.OneBit.B15
#define Y16 Output.OneBit.B16

//#define Output  OutputPort.ALL


//#define	Y1_PORT		0
//#define	Y2_PORT		1
//#define	Y3_PORT		2
//#define	Y4_PORT		3
//#define	Y5_PORT		4
//#define	Y6_PORT		5
//#define	Y7_PORT		6
//#define	Y8_PORT		7
//#define	Y9_PORT		8
//#define	Y10_PORT	9
//#define	Y11_PORT	10
//#define	Y12_PORT	11
//#define	Y13_PORT	12
//#define	Y14_PORT	13
//#define	Y15_PORT	14
//#define	Y16_PORT	15


#define ON     0  //针对所有的输入和输出(16个输出 20个输入)
#define OFF    1

#define InputEdgeNone  	0		//IO输入边沿无变化
#define InputEdgeUp 		1		//检测到上升沿
#define InputEdgeDown 	2		//检测到下降沿

#define GetBit(var, n)    (var & (0x0001 << n))      //判断n位为0或1
#define SetBit(var, n)    (var |= (0x0001 << n))     //n位置1
#define ClrBit(var, n)    (var &= ~(0x0001 << n))    //n为清0
#define FlipBit(var,n)    (var  ^= (0x0001 << n))	   //n位取反

#define EN_24V(ONOFF)    HAL_GPIO_WritePin(EN_24V_GPIO_Port, EN_24V_Pin, ONOFF);
#define G_IN              IN1   //红灯输入     地址非100号电路板

 extern void GetIOEdage(void);    //捕捉IO的边沿  上升  下降  无变化
 extern void ClearIOEdage(void);  //清除IO边沿信息
 
 extern volatile int  EdageX[18];  //获取每个Input的边沿状态 InputEdgeNone InputEdgeUp InputEdgeDown
 
#define Send                 1   //RS485的发送接收使能端
#define Receive              0



#endif

