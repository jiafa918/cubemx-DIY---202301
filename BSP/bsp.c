/*****************************************************************************
 *STLINK  PIN1:VCC3V3  PIN7:SWDIO  PIN9:SWCLK  PIN20:GND
 ****************************************************************************/

#include "bsp.h"
#include "bsp_gpio.h"
#include "string.h"

#define STM3210E_EVAL_BSP_VERSION "CPLCV2.0-STM32F103VET6"

//uint8_t aTxStartMessage[] = "\r\nUART-Hyperterminal communication based on IT\r\nEnter 10 characters using keyboard :\r\n";
///* Buffer used for reception */
//uint8_t aRxBuffer[20];
//uint8_t senddata_IT[23] = " Transmit IT or DMA.\r\n";

int ledtesk = 0; // ռ�ձ�
int LEDtime = 0; // ���Ӵ���

// char MSComm3SendStr[200];

// uint8_t progress=0;	 				//��������״̬��

// int32_t AutoRunFlag = 0;                          //�ϵ�ʱ�Զ�ģʽ�±��밴Run�����Զ�ִ�г���
// int8_t TesterMode = 0;                           //����ģʽ0����ִ���κζ���  ����ֵʱִ����ض���
// char ManualAutoRun = 1;                        //�ֶ�״̬���Զ����б�־λ

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim8;

/********************************************************************************
 * ��  �ܣ��û���ʼ������
 * ��  ������
 * ����ֵ����
 *********************************************************************************/
int wait_ready() //	�û���ʼ������
{

    ////    HAL_TIM_PWM_Init(&htim1);
    ////     HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    ////    HAL_TIM_PWM_Init(&htim2);
    ////     HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
    ////    HAL_TIM_PWM_Init(&htim3);
    ////     HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_4);
    HAL_TIM_Base_Init(&htim1); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim2); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim3); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim4); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim5); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim6); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim7); // ������ʱ��5  ����LED��˸
    HAL_TIM_Base_Init(&htim8); // ������ʱ��5  ����LED��˸

    HAL_TIM_Base_Start_IT(&htim1);
    HAL_TIM_Base_Start_IT(&htim2);
    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start_IT(&htim4);
    HAL_TIM_Base_Start_IT(&htim5);
    HAL_TIM_Base_Start_IT(&htim6);
    HAL_TIM_Base_Start_IT(&htim7);
    HAL_TIM_Base_Start_IT(&htim8);

//  HAL_GPIO_WritePin(I1_GPIO_Port,I1_Pin,((numbers & 0x01)>>0)?GPIO_PIN_SET:GPIO_PIN_RESET);

    LED_State_Count = 5;     //�ϵ��ʼ��ʱLED����   50mS����50MS��

    MyTIME_Init();           //��ʱ����ʼ��TIME2����10MS��ʱ�ж�ʹLED��˸

    MSComm1.Mode = ASCII ;                            //UART1����ASCIIģʽ
    MSComm1.RX_Len = 0;
    HAL_UART_Receive_IT(&huart1,&BufferRxChar[0],1);  //UART1ͨѶ���ڽ����ж�ģʽ

    MyTimer1.Enable = 0;
    MyTimer1.TimerCount = 0;
    MyTimer1.flsh_flag = 1;
    MyTimer1.level_flag = 1;
    MyTimer1.edgeCount = 0;     //���ö�ʱ�� ��
		
    MyTimer1.Enable = 1;   //������ʱ��
    MyTimer1.update_flag = 1;
    none_input_update_flag = 1;   //��ѭ�����Ե�һ�μ�������״̬
		
		EN_24V(1); //��24V������ƿ���
		
    printf("The system init ok---\r\n");
    printf("---------------------: %s %s\r\n", __DATE__, __TIME__); // ��ȡ����һ�εı���ʱ��
}

/********************************************************************************
 * ��  �ܣ��û���loop����
 * ��  ������
 * ����ֵ����
 *********************************************************************************/
int work_flow() // ִ���û���loop����
{
//			Output.ALL=8;
//	        HAL_Delay(200);
////	SetOutput(12,0);
//			Output.ALL=1023;	
	 		ScanInput();
	 		ScanOutput();
		if(MSComm1.RX_Flag)    //Debug�����ж�
		{
			MSComm1.RX_Flag = 0;
			Handle_UART1();
			Clear(MSComm1.RX_Str);
		}
    //	char str[] = "Hello,HaiCoder,Hello,World";
    //	const char s[2] = ",";
    //	char *token;
    //	// ��ȡ��һ�����ַ���
    //	token = strtok(str, s);
    //	/* ������ȡ���������ַ��� */
    //	while ( token != NULL )
    //	{
    //		printf("Str =\n");
    //		token = strtok(NULL, s);
    //	}

    //    PDout(0)=1;
    //    HAL_Delay(200);
    //    PDout(0)=0;
    //    HAL_Delay(200);

    //    PDout(6)=0;
    //    HAL_Delay(200);
    //    PDout(6)=1;
    //    HAL_Delay(200);

    // OUT16(1);
    // HAL_Delay(200);

    // OUT16(0);
    // HAL_Delay(200);

    ////��֤PCBA���
    // HAL_Delay(200);					HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_9); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O4_GPIO_Port, O4_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O5_GPIO_Port, O5_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O6_GPIO_Port, O6_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O7_GPIO_Port, O7_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O8_GPIO_Port, O8_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O9_GPIO_Port, O9_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O10_GPIO_Port, O10_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O11_GPIO_Port, O11_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O12_GPIO_Port, O12_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O13_GPIO_Port, O13_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O14_GPIO_Port, O14_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O15_GPIO_Port, O15_Pin); // ������ʱ��5  ����LED��˸
    // HAL_Delay(200);	        HAL_GPIO_TogglePin(O16_GPIO_Port, O16_Pin); // ������ʱ��5  ����LED��˸
}

///**
//  * @brief  This method returns the STM3210E EVAL BSP Driver revision
//  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
//  */
// uint32_t BSP_GetVersion(void)
//{
//  return STM3210E_EVAL_BSP_VERSION;
//}
