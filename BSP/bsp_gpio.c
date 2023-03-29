


#include "bsp_gpio.h"




/*****************************************************************************
*                         unsigned char tester (void)
* ��  �ܣ�Magnet_test�Ĳ��Գ���
* ˵  ����
* ��  ������
* ����ֵ����
****************************************************************************/

InputPort Input;	//����˿�ɨ��
OutputPort Output;	//PCBd�������ӳ�䵽�ṹ�������

volatile int LastInputState = 0;  
volatile int  EdageX[18]={0};


/*******************************************************************************
��  �� : ɨ������ڵ�״̬ �˿�ɨ��,����������˿ڵ�״̬����ṹ����
��  �� : ��
����ֵ ����
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
��  �� : ɨ������ڵ�״̬ �˿�ɨ��,����������˿ڵ�״̬����ṹ����
��  �� : ��
����ֵ ����
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
��  �� : ���ݱ���ɨ���������
��  �� : ��
����ֵ ����
********************************************************************************/
void SetOutput(unsigned char Channel,unsigned char ONOFF)
{
   int Output = ONOFF? Output | (1 << Channel-1): Output & ~(1<< Channel-1);
    ScanOutput();
}


/*******************************************************************************
��  �� : ��׽IO�ı���  ������  �½���  �ޱ仯 
ִ����ú�����һ��Ҫ������б��� ClearIOEdage
if(EdageX[0] == InputEdgeUp)
��  �� : ��
����ֵ ����
********************************************************************************/
 void GetIOEdage(void)
 {
    char edageIndex = 0;
	  char index = 0;

	  for(index = 0;index < 16;index++)
	  {
	  	 edageIndex = index;
	  	 if(GetBit(Input.ALL, index) > 0)	  //�ô�ɨ��Ϊ�ߵ�ƽ
		   {	    	
					if(GetBit(LastInputState, index) == 0)	//�ϴ�Ϊ�͵�ƽ 
					{
						EdageX[edageIndex] = InputEdgeUp;
//						printf("������������ţ� %d\r\n",edageIndex);  //��ӡ��������ڵ�״̬����InputEdgeNone(0)   InputEdgeUp(1)  InputEdgeDown(2)
					}
					SetBit(LastInputState, index);
		  }
		  else   //�ô�ɨ��Ϊ�͵�ƽ
		  {	   	
		    if(GetBit(LastInputState, index) > 0) //�ϴ�Ϊ�ߵ�ƽ 
				{
					EdageX[edageIndex] = InputEdgeDown;
//					printf("�½���������ţ� %d\r\n",edageIndex);  //��ӡ��������ڵ�״̬����InputEdgeNone(0)   InputEdgeUp(1)  InputEdgeDown(2)
				}	 
			    ClrBit(LastInputState, index);
		  }
	  }
 }
 
 
 /*******************************************************************************
��  �� : ���IO������Ϣ
��  �� : ��
����ֵ ����
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
 * ��  �ܣ�GPIO�ⲿ�ж�����
* ��  ������
* ����ֵ����
*********************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}
