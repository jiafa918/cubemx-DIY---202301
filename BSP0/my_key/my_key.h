//*******************************************************************************
//�ļ���:		key.h
//��  �ڣ�	2017��9��14��
//*******************************************************************************
#ifndef __MY_KEY_H
#define __MY_KEY_H



//*******************************************************************************
//   ����״̬����
//*******************************************************************************
#define        KEY_NUMB       	72
#define        KEY_SHORT        0x001       
#define        KEY_LONG         0x002
#define        KEY_ONCE         0xF40
#define        KEY_PRESS        0x080
#define				 KEY_L_H					0x100					//������
#define				 KEY_H_L					0x200					//�½���
#define				 KEY_H_L_D				0x0FF					//�����¼


//*******************************************************************************
//   key�ṹ�嶨��
//*******************************************************************************
typedef struct 
{
unsigned int 	uiGPIO;
char					iTime;
char					iTimed;
int 					cState;
}My_KEY_TypeDef;
//*******************************************************************************
//   ��������
//*******************************************************************************
void 					vKEY_Init(My_KEY_TypeDef* ptKEYx);
void 					vKEY_Scan(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Short(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Long(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Press(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Once(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Together(My_KEY_TypeDef* ptKEY1, My_KEY_TypeDef* ptKEY2);
void 					vKEY_Ret(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Edge(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Edge_L_H(My_KEY_TypeDef* ptKEYx);
unsigned char ucKEY_Edge_H_L(My_KEY_TypeDef* ptKEYx);
void 					vKEY_Edge_Ret(My_KEY_TypeDef* ptKEYx);

#endif


