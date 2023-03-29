#ifndef __MY_STM32F1_GPIO_H_
#define __MY_STM32F1_GPIO_H_	

#include "stm32f10x.h"
	
//定义GPIO设置专用参数,GPIO模式结构体变量
typedef enum 
{
	AN_IN					= 0x0,//模拟输入模式
	FL_IN					= 0x4,//浮空输入模式
	UD_IN					= 0x8,//上下拉输入模式
	
	PP_OUT_2MHZ		= 0x1,//通用推挽输出模式速度2M
	PP_OUT_10MHZ	= 0x2,//通用推挽输出模式速度10M
	PP_OUT_50MHZ	= 0x3,//通用推挽输出模式速度50M
	
	OD_OUT_2MHZ		= 0x5,//通用开漏输出模式速度2M
	OD_OUT_10MHZ	= 0x6,//通用开漏输出模式速度10M
	OD_OUT_50MHZ	= 0x7,//通用开漏输出模式速度50M
	
	PP_AF_2MHZ		= 0x9,//复用推挽输出模式速度2M
	PP_AF_10MHZ		= 0xA,//复用推挽输出模式速度10M
	PP_AF_50MHZ		= 0xB,//复用推挽输出模式速度50M

	OD_AF_2MHZ		= 0xD,//复用开漏输出模式速度2M
	OD_AF_10MHZ		= 0xE,//复用开漏输出模式速度10M
	OD_AF_50MHZ		= 0xF,//复用开漏输出模式速度50M		
}GPIO_MODE;

//以下为GPIO简写宏定义
#define 		PA0					(GPIOA_BASE | 0)
#define 		PA1					(GPIOA_BASE | 1)
#define 		PA2					(GPIOA_BASE | 2)
#define 		PA3					(GPIOA_BASE | 3)
#define 		PA4					(GPIOA_BASE | 4)
#define 		PA5					(GPIOA_BASE | 5)
#define 		PA6					(GPIOA_BASE | 6)
#define 		PA7					(GPIOA_BASE | 7)
#define 		PA8					(GPIOA_BASE | 8)
#define 		PA9					(GPIOA_BASE | 9)
#define 		PA10				(GPIOA_BASE | 10)
#define 		PA11				(GPIOA_BASE | 11)
#define 		PA12				(GPIOA_BASE | 12)
#define 		PA13				(GPIOA_BASE | 13)
#define 		PA14				(GPIOA_BASE | 14)
#define 		PA15				(GPIOA_BASE | 15)

#define 		PB0					(GPIOB_BASE | 0)
#define 		PB1					(GPIOB_BASE | 1)
#define 		PB2					(GPIOB_BASE | 2)
#define 		PB3					(GPIOB_BASE | 3)
#define 		PB4					(GPIOB_BASE | 4)
#define 		PB5					(GPIOB_BASE | 5)
#define 		PB6					(GPIOB_BASE | 6)
#define 		PB7					(GPIOB_BASE | 7)
#define 		PB8					(GPIOB_BASE | 8)
#define 		PB9					(GPIOB_BASE | 9)
#define 		PB10				(GPIOB_BASE | 10)
#define 		PB11				(GPIOB_BASE | 11)
#define 		PB12				(GPIOB_BASE | 12)
#define 		PB13				(GPIOB_BASE | 13)
#define 		PB14				(GPIOB_BASE | 14)
#define 		PB15				(GPIOB_BASE | 15)

#define 		PC0					(GPIOC_BASE | 0)
#define 		PC1					(GPIOC_BASE | 1)
#define 		PC2					(GPIOC_BASE | 2)
#define 		PC3					(GPIOC_BASE | 3)
#define 		PC4					(GPIOC_BASE | 4)
#define 		PC5					(GPIOC_BASE | 5)
#define 		PC6					(GPIOC_BASE | 6)
#define 		PC7					(GPIOC_BASE | 7)
#define 		PC8					(GPIOC_BASE | 8)
#define 		PC9					(GPIOC_BASE | 9)
#define 		PC10				(GPIOC_BASE | 10)
#define 		PC11				(GPIOC_BASE | 11)
#define 		PC12				(GPIOC_BASE | 12)
#define 		PC13				(GPIOC_BASE | 13)
#define 		PC14				(GPIOC_BASE | 14)
#define 		PC15				(GPIOC_BASE | 15)

#define 		PD0					(GPIOD_BASE | 0)
#define 		PD1					(GPIOD_BASE | 1)
#define 		PD2					(GPIOD_BASE | 2)
#define 		PD3					(GPIOD_BASE | 3)
#define 		PD4					(GPIOD_BASE | 4)
#define 		PD5					(GPIOD_BASE | 5)
#define 		PD6					(GPIOD_BASE | 6)
#define 		PD7					(GPIOD_BASE | 7)
#define 		PD8					(GPIOD_BASE | 8)
#define 		PD9					(GPIOD_BASE | 9)
#define 		PD10				(GPIOD_BASE | 10)
#define 		PD11				(GPIOD_BASE | 11)
#define 		PD12				(GPIOD_BASE | 12)
#define 		PD13				(GPIOD_BASE | 13)
#define 		PD14				(GPIOD_BASE | 14)
#define 		PD15				(GPIOD_BASE | 15)

#define 		PE0					(GPIOE_BASE | 0)
#define 		PE1					(GPIOE_BASE | 1)
#define 		PE2					(GPIOE_BASE | 2)
#define 		PE3					(GPIOE_BASE | 3)
#define 		PE4					(GPIOE_BASE | 4)
#define 		PE5					(GPIOE_BASE | 5)
#define 		PE6					(GPIOE_BASE | 6)
#define 		PE7					(GPIOE_BASE | 7)
#define 		PE8					(GPIOE_BASE | 8)
#define 		PE9					(GPIOE_BASE | 9)
#define 		PE10				(GPIOE_BASE | 10)
#define 		PE11				(GPIOE_BASE | 11)
#define 		PE12				(GPIOE_BASE | 12)
#define 		PE13				(GPIOE_BASE | 13)
#define 		PE14				(GPIOE_BASE | 14)
#define 		PE15				(GPIOE_BASE | 15)

#define 		PF0					(GPIOF_BASE | 0)
#define 		PF1					(GPIOF_BASE | 1)
#define 		PF2					(GPIOF_BASE | 2)
#define 		PF3					(GPIOF_BASE | 3)
#define 		PF4					(GPIOF_BASE | 4)
#define 		PF5					(GPIOF_BASE | 5)
#define 		PF6					(GPIOF_BASE | 6)
#define 		PF7					(GPIOF_BASE | 7)
#define 		PF8					(GPIOF_BASE | 8)
#define 		PF9					(GPIOF_BASE | 9)
#define 		PF10				(GPIOF_BASE | 10)
#define 		PF11				(GPIOF_BASE | 11)
#define 		PF12				(GPIOF_BASE | 12)
#define 		PF13				(GPIOF_BASE | 13)
#define 		PF14				(GPIOF_BASE | 14)
#define 		PF15				(GPIOF_BASE | 15)

#define 		PG0					(GPIOG_BASE | 0)
#define 		PG1					(GPIOG_BASE | 1)
#define 		PG2					(GPIOG_BASE | 2)
#define 		PG3					(GPIOG_BASE | 3)
#define 		PG4					(GPIOG_BASE | 4)
#define 		PG5					(GPIOG_BASE | 5)
#define 		PG6					(GPIOG_BASE | 6)
#define 		PG7					(GPIOG_BASE | 7)
#define 		PG8					(GPIOG_BASE | 8)
#define 		PG9					(GPIOG_BASE | 9)
#define 		PG10				(GPIOG_BASE | 10)
#define 		PG11				(GPIOG_BASE | 11)
#define 		PG12				(GPIOG_BASE | 12)
#define 		PG13				(GPIOG_BASE | 13)
#define 		PG14				(GPIOG_BASE | 14)
#define 		PG15				(GPIOG_BASE | 15)

#define 		Ftsr					1  		//下降沿触发
#define 		Rtsr					2  		//上升沿触发

/*******以下为GPIO位操作宏定义*******/
#define Port(GPIO)		((GPIO_TypeDef *)(GPIO&0xffffff00))			//获取一个GPIO的端口
#define Pin(GPIO)		((unsigned char)(GPIO&0xff))				//获取一个GPIO的Pin

#define Set(GPIO)		(Port(GPIO)->BSRR  	= (1<<Pin(GPIO)))		//指定GPIO置高 			
#define Ret(GPIO)		(Port(GPIO)->BRR  	= (1<<Pin(GPIO))) 		//指定GPIO置低
#define Non(GPIO)		(Port(GPIO)->ODR 	 ^= (1<<Pin(GPIO)))		//指定GPIO状态取反
#define Read(GPIO)		(((Port(GPIO)->IDR)>>Pin(GPIO)) & 1) 		//读取指定GPIO电平      

/**********************************************************************
V3.5库可调用的一些常用GPIO位操作函数归纳，详细用法请查阅stm32固件库手册
				      函数													功能							调用示例
GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)       		读取指定GPIO管脚输入电平    ReadValue = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) 
GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)	   		读取指定GPIO管脚输出电平	ReadValue = GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_7);
GPIO_ReadInputData(GPIO_TypeDef* GPIOx)								读取指定GPIO端口输入		ReadValue = GPIO_ReadInputData(GPIOC);
GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)							读取指定GPIO端口输出		ReadValue = GPIO_ReadOutputData(GPIOC);
GPIO_SetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)						指定GPIO管脚置高			GPIO_SetBits(GPIOA, GPIO_Pin_10 | GPIO_Pin_15);
GPIO_ResetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)					指定GPIO管脚置低			GPIO_ResetBits(GPIOA, GPIO_Pin_10 | GPIO_Pin_15);
GPIO_WriteBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin, BitAction BitVal)	设定指定GPIO管脚状态		GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);		BitAction BitVal	=	Bit_SET/Bit_RESET
GPIO_Write(GPIO_TypeDef* GPIOx, u16 PortVal)						指定GPIO端口写入数据		GPIO_Write(GPIOA, 0x1101);

**********************************************************************/

/*******************************************************
位带操作,实现51类似的GPIO控制功能      
具体实现思想,参考<<CM3权威指南>>第五章(87页~92页).
IO口操作宏定义
以下代码功能已被上面代码功能包含，可以不使用啦
*******************************************************/
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO口地址映射
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 
 
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 			//IO口操作,只对单一的IO口!   //确保n的值小于16!
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入




/************以下为函数声明***********/
void OUTPUT_GPIO_Init(void);			//GPIO输出初始化		标准库函数方式		参数修改麻烦，不推荐使用
void INPUT_GPIO_Init(void);				//GPIO输入初始化		标准库函数方式		参数修改麻烦，不推荐使用

void vGPIO_Init(unsigned int uiGpio,  GPIO_MODE tMode, unsigned char ucOut);		//GPIO初始化函数
void vIn_Mode(unsigned int uiGpio);				//设置GPIO为上拉输入
void vOut_Mode(unsigned int uiGpio);			//设置GPIO为开漏输出
void vCLOSE_SWJ(void);				//关闭jtag-dp功能，PA15，PB3，PB4作为普通IO口使用，PA13，PA14作为SW-DP功能使用   慎用！一旦启用想要第二次下载就需要擦除flash中所有内容才可以



#endif



