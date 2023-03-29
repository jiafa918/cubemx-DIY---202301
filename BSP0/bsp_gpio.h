#ifndef __bsp_gpio_H
#define __bsp_gpio_H

#include "bsp.h"
#include "stm32f1xx_hal.h"

#include "stm32f1xx.h"
#include "stdio.h"
#include "stdlib.h"
#include "TIME.h"

////λ������,ʵ��51���Ƶ�GPIO���ƹ���
////����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
////IO�ڲ����궨��

//// �ѡ�λ����ַ+λ��š�ת���ɱ�����ַ�ĺ�
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x02000000+((addr & 0x000FFFFF)<<5)+(bitnum<<2)) 

//// ��һ����ַת����һ��ָ��
//#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))

//// ��λ����������ַת����ָ��
//#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

# define BITBAND_REG(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (((uint32_t)&(Reg) - (uint32_t)0x40000000u)<<5) + (((uint32_t)(Bit))<<2))))	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define RGBLED BITBAND_REG(GPIOB->ODR,11)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define IN2 BITBAND_REG(GPIOA->ODR,15)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED3 BITBAND_REG(GPIOB->ODR,15)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED4 BITBAND_REG(GPIOC->ODR,7)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��


/**
 * @brief LED Types Definition
 */
typedef enum 
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3,

//  LED_GREEN  = LED1,
//  LED_ORANGE = LED2,
//  LED_RED    = LED3,
//  LED_BLUE   = LED4

} Led_TypeDef;


typedef enum 
{
  OUT1 = 0,
  OUT2 = 1,
  OUT3 = 2,
  OUT4 = 3,

//  LED_GREEN  = LED1,
//  LED_ORANGE = LED2,
//  LED_RED    = LED3,
//  LED_BLUE   = LED4

} OUT_TypeDef;

#define LEDn                             4

#define LED1_PIN                         GPIO_PIN_13             /* PF.06*/
#define LED1_GPIO_PORT                   GPIOB
#define LED1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()
  
#define LED2_PIN                         GPIO_PIN_14             /* PF.07*/
#define LED2_GPIO_PORT                   GPIOB
#define LED2_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()


#define LED3_PIN                         GPIO_PIN_15            /* PF.08*/
#define LED3_GPIO_PORT                   GPIOB
#define LED3_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOB_CLK_DISABLE()


#define LED4_PIN                         GPIO_PIN_6            /* PF.09*/
#define LED4_GPIO_PORT                   GPIOC
#define LED4_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOC_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOC_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__LED__) do { if ((__LED__) == LED1) LED1_GPIO_CLK_ENABLE(); else\
                                           if ((__LED__) == LED2) LED2_GPIO_CLK_ENABLE(); else \
                                           if ((__LED__) == LED3) LED3_GPIO_CLK_ENABLE(); else\
                                           if ((__LED__) == LED4) LED4_GPIO_CLK_ENABLE();} while(0)

#define LEDx_GPIO_CLK_DISABLE(__LED__)   (((__LED__) == LED1) ? LED1_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED2) ? LED2_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED3) ? LED3_GPIO_CLK_DISABLE() :\
                                          ((__LED__) == LED4) ? LED4_GPIO_CLK_DISABLE() : 0 )


void                    BSP_LED_Init(Led_TypeDef Led);
void                    BSP_LED_On(Led_TypeDef Led);
void                    BSP_LED_Off(Led_TypeDef Led);
void                    BSP_LED_Toggle(Led_TypeDef Led);

void                    BSP_OUT_Toggle(OUT_TypeDef Led);
//																					 
extern void ScanInput(void);  //ɨ������ڵ�״̬
//extern void ScanOutput(void);
//extern void SetOutput(unsigned char Channel,unsigned char ONOFF);

//********************************************************************����˿�ɨ��
typedef union
{
    struct
    {
        unsigned B1 :   1;
        unsigned B2 :   1;
        unsigned B3 :   1;
        unsigned B4 :   1;
        // unsigned B5 :   1;
        // unsigned B6 :   1;
        // unsigned B7 :   1;
        // unsigned B8 :   1;
        // unsigned B9 :   1;
        // unsigned B10 :  1;
        // unsigned B11 :  1;
        // unsigned B12 :  1;
        // unsigned B13 :  1;
        // unsigned B14 :  1;
        // unsigned B15 :  1;
        // unsigned B16 :  1;												      
    }OneBit;
     unsigned long ALL;
}InputPort;
extern InputPort Input;  //PCBd�������ӳ�䵽�ṹ�������


//GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
#define IN1  HAL_GPIO_ReadPin(IN1_GPIO_Port,IN1_Pin)   //��:������
#define IN2  HAL_GPIO_ReadPin(IN2_GPIO_Port,IN2_Pin)   //��:������
#define IN3  HAL_GPIO_ReadPin(IN3_GPIO_Port,IN3_Pin)   //��:������
#define IN4  HAL_GPIO_ReadPin(IN4_GPIO_Port,IN4_Pin)  //��:������
//#define IN5  HAL_GPIO_ReadPin(IN4_GPIO_Port,IN4_Pin)  //��:������
//#define IN6  HAL_GPIO_ReadPin(M_I6_GPIO_Port,M_I6_Pin)   //��:������
//#define IN7  HAL_GPIO_ReadPin(M_I7_GPIO_Port,M_I7_Pin)   //��:������
//#define IN8  HAL_GPIO_ReadPin(M_I8_GPIO_Port,M_I8_Pin)   //��:������
//#define IN9  HAL_GPIO_ReadPin(M_I9_GPIO_Port,M_I9_Pin)   //��:������
//#define IN10  HAL_GPIO_ReadPin(M_I10_GPIO_Port,M_I10_Pin)   //��:������
//#define IN11  HAL_GPIO_ReadPin(M_I11_GPIO_Port,M_I11_Pin)   //��:������
//#define IN12  HAL_GPIO_ReadPin(M_I12_GPIO_Port,M_I12_Pin)   //��:������
//#define IN13  HAL_GPIO_ReadPin(M_I13_GPIO_Port,M_I13_Pin)   //��:������
//#define IN14  HAL_GPIO_ReadPin(M_I14_GPIO_Port,M_I14_Pin)   //��:������
//#define IN15  HAL_GPIO_ReadPin(M_I15_GPIO_Port,M_I15_Pin)   //��:������
//#define IN16  HAL_GPIO_ReadPin(M_I16_GPIO_Port,M_I16_Pin)   //��:������

//#define Input   InputPort.ALL
#define X1  Input.OneBit.B1
#define X2  Input.OneBit.B2
#define X3  Input.OneBit.B3
#define X4  Input.OneBit.B4
#define X5  Input.OneBit.B5
//#define X6  Input.OneBit.B7
//#define X7  Input.OneBit.B8
//#define X10 Input.OneBit.B9
//#define X11 Input.OneBit.B10
//#define X12 Input.OneBit.B11
//#define X13 Input.OneBit.B12
//#define X14 Input.OneBit.B13
//#define X15 Input.OneBit.B14
//#define X16 Input.OneBit.B15
//#define X17 Input.OneBit.B16




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



////********************************************************************����˿�ɨ��
typedef union   
{
    struct
    {
        unsigned B1 :   1;
        unsigned B2 :   1;
        unsigned B3 :   1;
        unsigned B4 :   1;
//        unsigned B5 :   1;
//        unsigned B6 :   1;
//        unsigned B7 :   1;
//        unsigned B8 :   1;
//        unsigned B9 :   1;
//        unsigned B10 :  1;
//        unsigned B11 :  1;
//        unsigned B12 :  1;
//        unsigned B13 :  1;
//        unsigned B14 :  1;
//        unsigned B15 :  1;
//        unsigned B16 :  1;
    }OneBit;
     unsigned int ALL;
}OutputPort;
extern OutputPort Output;  //PCBd�������ӳ�䵽�ṹ�������


////void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
#define	O1(PinState)		HAL_GPIO_WritePin(OUT1_GPIO_Port,OUT1_Pin,PinState)  //��:�����
#define	O2(PinState)		HAL_GPIO_WritePin(OUT02_GPIO_Port,OUT02_Pin,PinState)   //��:�����
#define	O3(PinState)		HAL_GPIO_WritePin(OUT03_GPIO_Port,OUT03_Pin,PinState)   //��:�����
#define	O4(PinState)		HAL_GPIO_WritePin(OUT04_GPIO_Port,OUT04_Pin,PinState)   //��:�����
//// #define	OUT5(PinState)		HAL_GPIO_WritePin(M_O5_GPIO_Port,M_O5_Pin,PinState)   //��:�����
//// #define	OUT6(PinState)		HAL_GPIO_WritePin(M_O6_GPIO_Port,M_O6_Pin,PinState)   //��:�����
//// #define	OUT7(PinState)		HAL_GPIO_WritePin(M_O7_GPIO_Port,M_O7_Pin,PinState)   //��:�����
//// #define	OUT8(PinState)		HAL_GPIO_WritePin(M_O8_GPIO_Port,M_O8_Pin,PinState)   //��:�����
//// #define	OUT9(PinState)		HAL_GPIO_WritePin(M_O9_GPIO_Port,M_O9_Pin,PinState)   //��:�����
//// #define	OUT10(PinState)		HAL_GPIO_WritePin(M_O10_GPIO_Port,M_O10_Pin,PinState)   //��:�����
//// #define	OUT11(PinState)		HAL_GPIO_WritePin(M_O11_GPIO_Port,M_O11_Pin,PinState)   //��:�����
//// #define	OUT12(PinState)		HAL_GPIO_WritePin(M_O12_GPIO_Port,M_O12_Pin,PinState)   //��:�����
//// #define	OUT13(PinState)		HAL_GPIO_WritePin(M_O13_GPIO_Port,M_O13_Pin,PinState)   //��:�����
//// #define	OUT14(PinState)		HAL_GPIO_WritePin(M_O14_GPIO_Port,M_O14_Pin,PinState)   //��:�����
//// #define	OUT15(PinState)		HAL_GPIO_WritePin(M_O15_GPIO_Port,M_O15_Pin,PinState)   //��:�����
//// #define	OUT16(PinState)		HAL_GPIO_WritePin(M_O16_GPIO_Port,M_O16_Pin,PinState)   //��:�����

//#define Output  OutputPort.ALL
#define Y1  Output.OneBit.B1
#define Y2  Output.OneBit.B2
#define Y3  Output.OneBit.B3
#define Y4  Output.OneBit.B4
//// #define Y5  Output.OneBit.B6
//// #define Y6  Output.OneBit.B7
//// #define Y7  Output.OneBit.B8
//// #define Y10 Output.OneBit.B9
//// #define Y11 Output.OneBit.B10
//// #define Y12 Output.OneBit.B11
//// #define Y13 Output.OneBit.B12
//// #define Y14 Output.OneBit.B13
//// #define Y15 Output.OneBit.B14
//// #define Y16 Output.OneBit.B15
//// #define Y17 Output.OneBit.B16





#define	Y1_PORT		1
#define	Y2_PORT		2
#define	Y3_PORT		3
#define	Y4_PORT		4
//// #define	Y5_PORT		5
//// #define	Y6_PORT		6
//// #define	Y7_PORT		7
//// #define	Y10_PORT	8
//// #define	Y11_PORT	9
//// #define	Y12_PORT	10
//// #define	Y13_PORT	11
//// #define	Y14_PORT	12
//// #define	Y15_PORT	13
//// #define	Y16_PORT	14
//// #define	Y17_PORT	15

//#define ON     0  //������е���������(16����� 20������)
//#define OFF    1

//#define InputEdgeNone  	0		//IO��������ޱ仯
//#define InputEdgeUp 		1		//��⵽������
//#define InputEdgeDown 	2		//��⵽�½���

//#define GetBit(var, n)    (var & (0x0001 << n))      //�ж�nλΪ0��1
//#define SetBit(var, n)    (var |= (0x0001 << n))     //nλ��1
//#define ClrBit(var, n)    (var &= ~(0x0001 << n))    //nΪ��0
//#define FlipBit(var,n)    (var  ^= (0x0001 << n))	   //nλȡ��

// extern void GetIOEdage(void);    //��׽IO�ı���  ����  �½�  �ޱ仯
// extern void ClearIOEdage(void);  //���IO������Ϣ
// 
// extern volatile int  EdageX[18];  //��ȡÿ��Input�ı���״̬ InputEdgeNone InputEdgeUp InputEdgeDown
// 
//#define Send                 1   //RS485�ķ��ͽ���ʹ�ܶ�
//#define Receive              0



#endif

