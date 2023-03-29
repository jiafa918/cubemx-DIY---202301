#ifndef __bsp_gpio_H
#define __bsp_gpio_H

#include "main.h"
#include "stm32f1xx_hal_gpio.h"


//λ������,ʵ��51���Ƶ�GPIO���ƹ���
//����ʵ��˼��,�ο�<<CM3Ȩ��ָ��>>������(87ҳ~92ҳ).
//IO�ڲ����궨��
//// �ѡ�λ����ַ+λ��š�ת���ɱ�����ַ�ĺ�
//#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x02000000+((addr & 0x000FFFFF)<<5)+(bitnum<<2)) 
//// ��һ����ַת����һ��ָ��
//#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
//// ��λ����������ַת����ָ��
//#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))
//// GPIO ODR �� IDR �Ĵ�����ַӳ�� 

# define BITBAND_REG(Reg,Bit) (*((uint32_t volatile*)(0x42000000u + (((uint32_t)&(Reg) - (uint32_t)0x40000000u)<<5) + (((uint32_t)(Bit))<<2))))	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define OUT4 BITBAND_REG(GPIOC->ODR,9)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED2 BITBAND_REG(GPIOA->ODR,15)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED3 BITBAND_REG(GPIOA->ODR,8)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED4 BITBAND_REG(GPIOE->ODR,0)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED5 BITBAND_REG(GPIOB->ODR,9)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED6 BITBAND_REG(GPIOB->ODR,8)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED7 BITBAND_REG(GPIOB->ODR,5)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED8 BITBAND_REG(GPIOB->ODR,4)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED9 BITBAND_REG(GPIOB->ODR,3)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED10 BITBAND_REG(GPIOD->ODR,7)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED11 BITBAND_REG(GPIOD->ODR,6)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED12 BITBAND_REG(GPIOD->ODR,5)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED13 BITBAND_REG(GPIOD->ODR,4)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED14 BITBAND_REG(GPIOD->ODR,3)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED15 BITBAND_REG(GPIOD->ODR,1)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
//# define LED16 BITBAND_REG(GPIOD->ODR,0)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��




extern void ScanInput(void);  //ɨ������ڵ�״̬
extern void ScanOutput(void);
extern void SetOutput(unsigned char Channel,unsigned char ONOFF);

//********************************************************************����˿�ɨ��
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
extern InputPort Input;  //PCBd�������ӳ�䵽�ṹ�������


//GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
#define IN1  HAL_GPIO_ReadPin(I1_GPIO_Port,I1_Pin)   //��:������
#define IN2  HAL_GPIO_ReadPin(I2_GPIO_Port,I2_Pin)   //��:������
#define IN3  HAL_GPIO_ReadPin(I3_GPIO_Port,I3_Pin)   //��:������
#define IN4  HAL_GPIO_ReadPin(I4_GPIO_Port,I4_Pin)   //��:������
#define IN5  HAL_GPIO_ReadPin(I5_GPIO_Port,I5_Pin)   //��:������
#define IN6  HAL_GPIO_ReadPin(I6_GPIO_Port,I6_Pin)   //��:������
#define IN7  HAL_GPIO_ReadPin(I7_GPIO_Port,I7_Pin)   //��:������
#define IN8  HAL_GPIO_ReadPin(I8_GPIO_Port,I8_Pin)   //��:������
#define IN9  HAL_GPIO_ReadPin(I9_GPIO_Port,I9_Pin)   //��:������
#define IN10  HAL_GPIO_ReadPin(I10_GPIO_Port,I10_Pin)   //��:������
#define IN11  HAL_GPIO_ReadPin(I11_GPIO_Port,I11_Pin)   //��:������
#define IN12  HAL_GPIO_ReadPin(I12_GPIO_Port,I12_Pin)   //��:������
#define IN13  HAL_GPIO_ReadPin(I13_GPIO_Port,I13_Pin)   //��:������
#define IN14  HAL_GPIO_ReadPin(I14_GPIO_Port,I14_Pin)   //��:������
#define IN15  HAL_GPIO_ReadPin(I15_GPIO_Port,I15_Pin)   //��:������
#define IN16  HAL_GPIO_ReadPin(I16_GPIO_Port,I16_Pin)   //��:������


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



////********************************************************************����˿�ɨ��
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
extern OutputPort Output;  //PCBd�������ӳ�䵽�ṹ�������



//void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
//#define	OUT1(PinState)		HAL_GPIO_WritePin(O1_GPIO_Port,O1_Pin,PinState)  //��:�����
//#define	OUT16(PinState)		HAL_GPIO_WritePin(M_O16_GPIO_Port,M_O16_Pin,PinState)   //��:�����


# define OUT4 BITBAND_REG(GPIOE->ODR,7)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT5 BITBAND_REG(GPIOB->ODR,9)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT6 BITBAND_REG(GPIOB->ODR,8)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT7 BITBAND_REG(GPIOB->ODR,5)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT8 BITBAND_REG(GPIOB->ODR,4)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT9 BITBAND_REG(GPIOB->ODR,3)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT10 BITBAND_REG(GPIOD->ODR,7)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT11 BITBAND_REG(GPIOD->ODR,6)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT12 BITBAND_REG(GPIOD->ODR,5)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT13 BITBAND_REG(GPIOD->ODR,4)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT14 BITBAND_REG(GPIOD->ODR,3)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT15 BITBAND_REG(GPIOD->ODR,1)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��
# define OUT16 BITBAND_REG(GPIOD->ODR,0)	//Reg�ǲ������ֵĻ���ַ��Bit���ǵڼ�λ��



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


#define ON     0  //������е���������(16����� 20������)
#define OFF    1

#define InputEdgeNone  	0		//IO��������ޱ仯
#define InputEdgeUp 		1		//��⵽������
#define InputEdgeDown 	2		//��⵽�½���

#define GetBit(var, n)    (var & (0x0001 << n))      //�ж�nλΪ0��1
#define SetBit(var, n)    (var |= (0x0001 << n))     //nλ��1
#define ClrBit(var, n)    (var &= ~(0x0001 << n))    //nΪ��0
#define FlipBit(var,n)    (var  ^= (0x0001 << n))	   //nλȡ��

#define EN_24V(ONOFF)    HAL_GPIO_WritePin(EN_24V_GPIO_Port, EN_24V_Pin, ONOFF);
#define G_IN              IN1   //�������     ��ַ��100�ŵ�·��

 extern void GetIOEdage(void);    //��׽IO�ı���  ����  �½�  �ޱ仯
 extern void ClearIOEdage(void);  //���IO������Ϣ
 
 extern volatile int  EdageX[18];  //��ȡÿ��Input�ı���״̬ InputEdgeNone InputEdgeUp InputEdgeDown
 
#define Send                 1   //RS485�ķ��ͽ���ʹ�ܶ�
#define Receive              0



#endif

