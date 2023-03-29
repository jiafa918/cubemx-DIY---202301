#ifndef __bsp_key_H
#define __bsp_key_H	 

#include "bsp_gpio.h"
	
//*******************************************************************************
//   key结构体定义
// struct{																												//	typedef struct stu{
//        char *name;  //姓名																			//										char name[20];
//        int num;  //学号																				//										int age;
//        int age;  //年龄																				//										char sex;
//        char group;  //所在小组																	//										} STU;
//        float score;  //成绩																	 //	STU 是 struct stu 的别名，可以用 STU 定义结构体变量：
//    } stu1 = { "Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;   	 //	STU body1,body2;它等价于：struct stu body1, body2;
//(*pstu).name 它等价于： pstu->name	//	

//*******************************************************************************
typedef struct 
{
char 					uiGPIO;		//IO端口
char					iTime;		//IO点亮时间
char					iTimed;		//IO熄灭时间
int 					cState;		//IO状态
}My_KEY_TypeDef;

typedef unsigned char  u8;
typedef unsigned int  u16;
typedef unsigned char uint8;
typedef unsigned int  uint16;

/***************按键定义*******************/
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

