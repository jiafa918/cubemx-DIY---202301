#ifndef __bsp_key_H
#define __bsp_key_H	 

#include "bsp_gpio.h"
	
//*******************************************************************************
//   key�ṹ�嶨��
// struct{																												//	typedef struct stu{
//        char *name;  //����																			//										char name[20];
//        int num;  //ѧ��																				//										int age;
//        int age;  //����																				//										char sex;
//        char group;  //����С��																	//										} STU;
//        float score;  //�ɼ�																	 //	STU �� struct stu �ı����������� STU ����ṹ�������
//    } stu1 = { "Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;   	 //	STU body1,body2;���ȼ��ڣ�struct stu body1, body2;
//(*pstu).name ���ȼ��ڣ� pstu->name	//	

//*******************************************************************************
typedef struct 
{
char 					uiGPIO;		//IO�˿�
char					iTime;		//IO����ʱ��
char					iTimed;		//IOϨ��ʱ��
int 					cState;		//IO״̬
}My_KEY_TypeDef;

typedef unsigned char  u8;
typedef unsigned int  u16;
typedef unsigned char uint8;
typedef unsigned int  uint16;

/***************��������*******************/
static  My_KEY_TypeDef   		s_t_sw_reset  	= {X1_PORT,0,0,0};  
				My_KEY_TypeDef*     g_pt_sw_reset	= &s_t_sw_reset;


static  My_KEY_TypeDef   		s_t_start  	= {X0_PORT,0,0,0};  
				My_KEY_TypeDef*     g_pt_start	= &s_t_start;


void vKEY_Scan(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Short(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Long(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Once(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Press(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Edge(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Edge_L_H(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Edge_H_L(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Together(My_KEY_TypeDef* ptKEY1, My_KEY_TypeDef* ptKEY2);
void vKEY_Ret(My_KEY_TypeDef* ptKEYx);
void vKEY_Edge_Ret(My_KEY_TypeDef* ptKEYx);


#endif

