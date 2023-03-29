#include "stm32f10x.h"
#include "my_stm32f1_gpio.h"	

/**********************************************
GPIO��ʼ�����ò���˵����

�˿�ʱ��ʹ�ܲ�����Χ��[RCC_APB2Periph_GPIOA,RCC_APB2Periph_GPIOG]    ʹ�� ENABLE  DISABLE
GPIO_Pin ������Χ	[GPIO_Pin_0,GPIO_Pin_15] & GPIO_Pin_ALL
GPIO_Mode ������Χ[GPIO_Mode_AIN,GPIO_Mode_IN_FLOATING,GPIO_Mode_IPD,GPIO_Mode_IPU,GPIO_Mode_Out_OD,GPIO_Mode_Out_PP,GPIO_Mode_AF_OD,GPIO_Mode_AF_PP]
				   ģ������		 ��������			   ��������		 ��������		��©���	    �������		 ���ÿ�©���	 �����������
GPIO_Speed ������Χ[GPIO_Speed_10MHz	GPIO_Speed_2MHz		GPIO_Speed_50MHz]
**********************************************/

/***********************************************
������		��OUTPUT_GPIO_Init
��������	����ʼ��GPIO����˿�
����		����
����		�����Ӧ
����		��2021/5/11
***********************************************/
void OUTPUT_GPIO_Init(void)		
{	
	GPIO_InitTypeDef GPIO_InitStructure;                        				 //����ṹ��ָ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);						//�˿�ʱ��ʹ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13; 	//ָ���ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 							//����ģʽ
														//��©���				�������			
														//GPIO_Mode_Out_OD		GPIO_Mode_Out_PP	GPIO_Mode_AF_OD		GPIO_Mode_AF_PP
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;							//����IO�ٶ�
	GPIO_Init(GPIOB, &GPIO_InitStructure);										//IO�ڳ�ʼ��
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13); 		//����IO�ڳ�ʼ״̬		
}


/***********************************************
������		��OUTPUT_GPIO_Init
��������	����ʼ��GPIO����˿�
����		����
����		�����Ӧ
����		��2021/5/11
***********************************************/
void INPUT_GPIO_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;                        				 //����ṹ��ָ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA, ENABLE);						//�˿�ʱ��ʹ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; 			//ָ���ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 								//����ģʽ
	GPIO_Init(GPIOE, &GPIO_InitStructure);										//IO�ڳ�ʼ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 									//ָ���ܽ�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 								//����ģʽ
	GPIO_Init(GPIOA, &GPIO_InitStructure);										//IO�ڳ�ʼ��
	
}


/**************************************************************************************************
//�� �� ����	GPIO_Init()
//��    �ܣ�	GPIO��ʼ��
//��ڲ�����	uiGpio�� PA0~PG5 �˿�
//          	tMode�� ģʽ
//          	ucOut�� ��ʼֵ
//�� �� ֵ��	��
//����ʾ����	vGPIO_Init(PC7,  PP_OUT_50MHZ, 1);      PC7�ܽų�ʼ��Ϊ����������ٶ�50MHZ����ʼ��ƽΪ�ߵ�ƽ
				      vGPIO_Init(PE2,  UD_IN, 1);				��ʼ��PE2�ܽ�Ϊ��������
**************************************************************************************************/
void vGPIO_Init(unsigned int uiGpio,  GPIO_MODE tMode, unsigned char ucOut)
{
	GPIO_TypeDef * PORT = Port(uiGpio);							//��ȡָ��GPIO�˿�
	unsigned int PIN = Pin(uiGpio);								//��ȡָ��GPIO��Pin
	unsigned char temp = (((uiGpio & 0xffffff00) - GPIOA_BASE)/0x0400);

	RCC->APB2ENR|=1<<(temp+2);  							//ʹ�ܶ�Ӧ�˿�ʱ��
	if(PIN<8)												//����ģʽ
	{
		PORT->CRL &= ~(0x0f<<((PIN%8)*4));
		PORT->CRL |=  (tMode<<((PIN%8)*4));
	}
	else
	{
		PORT->CRH &= ~(0x0f<<((PIN%8)*4)); 
		PORT->CRH |=  (tMode<<((PIN%8)*4));
	}
	if(ucOut)	PORT->ODR |= (1<<PIN);	//��������
	else		PORT->ODR &= ~(1<<PIN);	//��������
}


//**************************************************************************************************
//�� �� ����	In_Mode()
//��    �ܣ�	GPIO ����Ϊ��������
//��ڲ�����	uiGpio�� PA0~PG5 �˿�
//�� �� ֵ��	��
//��ע���ú��������ѱ�vGPIO_Init�������������Ƽ�ʹ��        2021��5��12�����Ӧ��ע
//**************************************************************************************************
void vIn_Mode(unsigned int uiGpio)
{
	GPIO_TypeDef * PORT = Port(uiGpio);
	unsigned int PIN = Pin(uiGpio);

	if(PIN<8)
			{
			PORT->CRL &= ~(0x0f<<((PIN%8)*4)); 
			PORT->CRL |=  (UD_IN<<((PIN%8)*4));		
			}
	else
			{
			PORT->CRH &= ~(0x0f<<((PIN%8)*4)); 
			PORT->CRH |=  (UD_IN<<((PIN%8)*4));								
			}
	PORT->ODR |= (1<<PIN);	//��������			
}


//**************************************************************************************************
//�� �� ����	Out_Mode()
//��    �ܣ�	GPIO ����ͨ�ÿ�©���ģʽ�ٶ�50M
//��ڲ�����	uiGpio�� PA0~PG5 �˿�
//�� �� ֵ��	��
//��ע���ú��������ѱ�vGPIO_Init�������������Ƽ�ʹ��        2021��5��12�����Ӧ��ע
//**************************************************************************************************
void vOut_Mode(unsigned int uiGpio)
{
	GPIO_TypeDef * PORT = Port(uiGpio);
	unsigned int PIN = Pin(uiGpio);

	if(PIN<8)
			{
			PORT->CRL &= ~(0x0f<<((PIN%8)*4)); 
			PORT->CRL |=  (OD_OUT_50MHZ<<((PIN%8)*4));		
			}
	else
			{
			PORT->CRH &= ~(0x0f<<((PIN%8)*4)); 
			PORT->CRH |=  (OD_OUT_50MHZ<<((PIN%8)*4));								
			}
}



//**************************************************************************************************
//�� �� ����	vCLOSE_SWJ()    
//��    �ܣ�	�ر�jtag-dp���ܣ�PA15��PB3��PB4��Ϊ��ͨIO��ʹ�ã�PA13��PA14��ΪSW-DP����ʹ��
//				
//��ڲ�����	��  
//�� �� ֵ��	��
//**************************************************************************************************
void vCLOSE_SWJ(void)
{
//    RCC->APB2ENR |= (1<<0);	     //��AFIOʱ��   ��ʹ��Ƭ�����عܽ�����Ϊ��ͨIO�����������Ҫ�ڶ������ؾ���Ҫ����flash���������ݲſ��ԣ�
//    AFIO->MAPR &= ~(7<<24);     //�ر�JTAG-DP������SW-DP
//	AFIO->MAPR |=  (2<<24);
	
//	GPIO_InitTypeDef  GPIO_InitStructure;
	/* ���� JTAG��PB3��PB4�ض���Ϊ��ͨIO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB |  RCC_APB2Periph_AFIO, ENABLE);//ʹ��PORTB��ʱ�ӡ���������PB3��PB4����
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);   //�ر�JTAG����(PB3/4)��ֻʹ��SWD(PA13/14)����
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST,ENABLE); 	//���⸴λ������³���
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_3;	//�˿�����
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//IO���ٶ�Ϊ50MHz
//	GPIO_Init(GPIOB, &GPIO_InitStructure);					//�����趨������ʼ��
	
//	GPIO_ResetBits(GPIOB,GPIO_Pin_4);	//PB.4 �����
//	GPIO_ResetBits(GPIOB,GPIO_Pin_3);	//PB.3 �����
 
//	/* PA15�ض���Ϊ��ͨIO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |  RCC_APB2Periph_AFIO, ENABLE);//ʹ��PORTA��ʱ�ӡ���������PA15����
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				//�˿�����
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//�������
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//IO���ٶ�Ϊ50MHz
//	GPIO_Init(GPIOA, &GPIO_InitStructure);					//�����趨������ʼ��
	
//	GPIO_ResetBits(GPIOA,GPIO_Pin_15);	//PA.15 �����	
	
}





