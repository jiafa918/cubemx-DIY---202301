#ifndef __MY_STM32F1_GPIO_H_
#define __MY_STM32F1_GPIO_H_	

#include "stm32f10x.h"
	
//����GPIO����ר�ò���,GPIOģʽ�ṹ�����
typedef enum 
{
	AN_IN					= 0x0,//ģ������ģʽ
	FL_IN					= 0x4,//��������ģʽ
	UD_IN					= 0x8,//����������ģʽ
	
	PP_OUT_2MHZ		= 0x1,//ͨ���������ģʽ�ٶ�2M
	PP_OUT_10MHZ	= 0x2,//ͨ���������ģʽ�ٶ�10M
	PP_OUT_50MHZ	= 0x3,//ͨ���������ģʽ�ٶ�50M
	
	OD_OUT_2MHZ		= 0x5,//ͨ�ÿ�©���ģʽ�ٶ�2M
	OD_OUT_10MHZ	= 0x6,//ͨ�ÿ�©���ģʽ�ٶ�10M
	OD_OUT_50MHZ	= 0x7,//ͨ�ÿ�©���ģʽ�ٶ�50M
	
	PP_AF_2MHZ		= 0x9,//�����������ģʽ�ٶ�2M
	PP_AF_10MHZ		= 0xA,//�����������ģʽ�ٶ�10M
	PP_AF_50MHZ		= 0xB,//�����������ģʽ�ٶ�50M

	OD_AF_2MHZ		= 0xD,//���ÿ�©���ģʽ�ٶ�2M
	OD_AF_10MHZ		= 0xE,//���ÿ�©���ģʽ�ٶ�10M
	OD_AF_50MHZ		= 0xF,//���ÿ�©���ģʽ�ٶ�50M		
}GPIO_MODE;

//����ΪGPIO��д�궨��
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

#define 		Ftsr					1  		//�½��ش���
#define 		Rtsr					2  		//�����ش���

/*******����ΪGPIOλ�����궨��*******/
#define Port(GPIO)		((GPIO_TypeDef *)(GPIO&0xffffff00))			//��ȡһ��GPIO�Ķ˿�
#define Pin(GPIO)		((unsigned char)(GPIO&0xff))				//��ȡһ��GPIO��Pin

#define Set(GPIO)		(Port(GPIO)->BSRR  	= (1<<Pin(GPIO)))		//ָ��GPIO�ø� 			
#define Ret(GPIO)		(Port(GPIO)->BRR  	= (1<<Pin(GPIO))) 		//ָ��GPIO�õ�
#define Non(GPIO)		(Port(GPIO)->ODR 	 ^= (1<<Pin(GPIO)))		//ָ��GPIO״̬ȡ��
#define Read(GPIO)		(((Port(GPIO)->IDR)>>Pin(GPIO)) & 1) 		//��ȡָ��GPIO��ƽ      

/**********************************************************************
V3.5��ɵ��õ�һЩ����GPIOλ�����������ɣ���ϸ�÷������stm32�̼����ֲ�
				      ����													����							����ʾ��
GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)       		��ȡָ��GPIO�ܽ������ƽ    ReadValue = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) 
GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)	   		��ȡָ��GPIO�ܽ������ƽ	ReadValue = GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_7);
GPIO_ReadInputData(GPIO_TypeDef* GPIOx)								��ȡָ��GPIO�˿�����		ReadValue = GPIO_ReadInputData(GPIOC);
GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)							��ȡָ��GPIO�˿����		ReadValue = GPIO_ReadOutputData(GPIOC);
GPIO_SetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)						ָ��GPIO�ܽ��ø�			GPIO_SetBits(GPIOA, GPIO_Pin_10 | GPIO_Pin_15);
GPIO_ResetBits(GPIO_TypeDef* GPIOx, u16 GPIO_Pin)					ָ��GPIO�ܽ��õ�			GPIO_ResetBits(GPIOA, GPIO_Pin_10 | GPIO_Pin_15);
GPIO_WriteBit(GPIO_TypeDef* GPIOx, u16 GPIO_Pin, BitAction BitVal)	�趨ָ��GPIO�ܽ�״̬		GPIO_WriteBit(GPIOA, GPIO_Pin_15, Bit_SET);		BitAction BitVal	=	Bit_SET/Bit_RESET
GPIO_Write(GPIO_TypeDef* GPIOx, u16 PortVal)						ָ��GPIO�˿�д������		GPIO_Write(GPIOA, 0x1101);

**********************************************************************/

/*******************************************************
λ������,ʵ��51���Ƶ�GPIO���ƹ���      
����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
IO�ڲ����궨��
���´��빦���ѱ�������빦�ܰ��������Բ�ʹ����
*******************************************************/
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO�ڵ�ַӳ��
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
 
#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //��� 			//IO�ڲ���,ֻ�Ե�һ��IO��!   //ȷ��n��ֵС��16!
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //���� 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //��� 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //���� 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //��� 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //���� 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //��� 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //���� 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //��� 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //����

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //��� 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //����

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //��� 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //����




/************����Ϊ��������***********/
void OUTPUT_GPIO_Init(void);			//GPIO�����ʼ��		��׼�⺯����ʽ		�����޸��鷳�����Ƽ�ʹ��
void INPUT_GPIO_Init(void);				//GPIO�����ʼ��		��׼�⺯����ʽ		�����޸��鷳�����Ƽ�ʹ��

void vGPIO_Init(unsigned int uiGpio,  GPIO_MODE tMode, unsigned char ucOut);		//GPIO��ʼ������
void vIn_Mode(unsigned int uiGpio);				//����GPIOΪ��������
void vOut_Mode(unsigned int uiGpio);			//����GPIOΪ��©���
void vCLOSE_SWJ(void);				//�ر�jtag-dp���ܣ�PA15��PB3��PB4��Ϊ��ͨIO��ʹ�ã�PA13��PA14��ΪSW-DP����ʹ��   ���ã�һ��������Ҫ�ڶ������ؾ���Ҫ����flash���������ݲſ���



#endif



