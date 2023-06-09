#include "bsp_key.h"

//*******************************************************************************
//   按键状态定义
//*******************************************************************************
#define        KEY_NUMB       	72
#define        KEY_SHORT        0x001       
#define        KEY_LONG         0x002
#define        KEY_ONCE         0xF40
#define        KEY_PRESS        0x080
#define				 KEY_L_H					0x100					//上升沿
#define				 KEY_H_L					0x200					//下降沿
#define				 KEY_H_L_D				0x0FF					//清除记录




//**************************************************************************************************
//函数名：	vKEY_Scan()
//说  明：	按键扫描
//参  数：	ptKEYx：按键结构体指针
//返回值：	无
//**************************************************************************************************
void vKEY_Scan(My_KEY_TypeDef* ptKEYx)
{
		if(!(GetBit((u16)Input.ALL, ptKEYx->uiGPIO)))
    {
        //如果有按键按下超过40ms，判定按键被有效按下有没有高变低发生(发生上升沿)
        if(ptKEYx->iTime == 3)      ptKEYx->cState |= KEY_L_H;
        //如果有按键按下超过40ms，判定按键被有效按下
        if(ptKEYx->iTime >= 3)      ptKEYx->cState |= KEY_PRESS;
        //如果有按键按下等于40ms，判定按键被有效按下一次
        if(ptKEYx->iTime == 3)      ptKEYx->cState |= (KEY_ONCE&KEY_H_L_D);
        //如果有按键按下超过990ms，则触发长按事件，每扫描一次触发一次
        if(ptKEYx->iTime >= 100)    ptKEYx->cState |= KEY_LONG;
        //累加按下时间
        if(ptKEYx->iTime <= 110)		ptKEYx->iTime++;
        //清零计时
        ptKEYx->iTimed = 0;
    }
    else
    {
        //如果按键没有按下，清零状态，只保留按下一次的记录。
        ptKEYx->cState &= KEY_ONCE;
        //如果按键没有按下，判断按下时间是不是在20ms~1000ms之间，是则发生短按事件（按下再松开，才能判断为一次短按）
        if(ptKEYx->iTime > 3 && ptKEYx->iTime < 100)
        {
            ptKEYx->cState |= KEY_SHORT;
        }
        //清零计时
        ptKEYx->iTime = 0;
        //累加松开时间
        if(ptKEYx->iTimed <= 110)			ptKEYx->iTimed++;
        if(ptKEYx->iTimed == 2)      	ptKEYx->cState |= KEY_H_L;
    }
}
//**************************************************************************************************
//函数名：	ucKEY_Short()
//说  明：	短按判断
//参  数：	ptKEYx：按键结构体指针
//返回值：	1：有短按事件； 0：无短按事件
//**************************************************************************************************
unsigned char ucKEY_Short(My_KEY_TypeDef* ptKEYx)
{
    if( ptKEYx->cState & KEY_SHORT)
    {
        ptKEYx->cState = 0;
        return (1);
    }
    else
        return (0);
}

//**************************************************************************************************
//函数名：	ucKEY_Long()
//说  明：	长按判断
//参  数：	ptKEYx：按键结构体指针
//返回值：	1：有长按事件； 0：无长按事件
//**************************************************************************************************
unsigned char ucKEY_Long(My_KEY_TypeDef* ptKEYx)
{
    if( ptKEYx->cState & KEY_LONG)
    {
        return (1);
    }
    else
        return (0);
}
//**************************************************************************************************
//函数名：	ucKEY_Once()
//说  明：	按下一次判断
//参  数：	My_KEY_TypeDef* ptKEYx：按键
//返回值：	1：有长按事件； 0：无长按事件
//**************************************************************************************************
unsigned char ucKEY_Once(My_KEY_TypeDef* ptKEYx)
{
    if( ptKEYx->cState & KEY_ONCE)
    {
        ptKEYx->cState = 0;
        return (1);
    }
    else
        return (0);
}
//**************************************************************************************************
//函数名：	ucKEY_Press()
//说  明：	长按判断
//参  数：	ptKEYx：按键结构体指针
//返回值：	1：按键被按下； 0：按键弹起
//**************************************************************************************************
unsigned char ucKEY_Press(My_KEY_TypeDef* ptKEYx)
{
    if(ptKEYx->cState & KEY_PRESS)
    {
        return (1);
    }
    else
        return (0);
}
//**************************************************************************************************
//函数名：	ucKEY_edge()
//说  明：	边沿触发
//参  数：	ptKEYx：按键结构体指针
//返回值：	1.发生过上升沿 2发生过下降沿  0未发生边沿触发
//**************************************************************************************************
unsigned char ucKEY_Edge(My_KEY_TypeDef* ptKEYx)
{
    if((ptKEYx->cState & KEY_L_H)==KEY_L_H)
    {
        return 1;
    }
    else if((ptKEYx->cState & KEY_H_L)==KEY_H_L)
    {
        return 2;
    }
    else
        return 0;
}
//**************************************************************************************************
//函数名：	ucKEY_edge_L_H()
//说  明：	边沿触发  低变高
//参  数：	ptKEYx：按键结构体指针
//返回值：	1.发生过上升沿
//**************************************************************************************************
unsigned char ucKEY_Edge_L_H(My_KEY_TypeDef* ptKEYx)
{
    if((ptKEYx->cState & KEY_L_H)==KEY_L_H)
    {
        ptKEYx->cState &= KEY_H_L_D;
        return 1;
    }
    else
        return 0;
}
//**************************************************************************************************
//函数名：	ucKEY_edge_H_L()
//说  明：	边沿触发  高变低
//参  数：	ptKEYx：按键结构体指针
//返回值：	1.发生过下降沿
//**************************************************************************************************
unsigned char ucKEY_Edge_H_L(My_KEY_TypeDef* ptKEYx)
{
    if((ptKEYx->cState & KEY_H_L)==KEY_H_L)
    {
        ptKEYx->cState &= KEY_H_L_D;
        return 1;
    }
    else
        return 0;
}
//**************************************************************************************************
//函数名：	ucKEY_Together()
//说  明：	双启动判断
//参  数：	ptKEYx：按键结构体指针
//返回值：	1：按键被按下； 0：按键弹起
//**************************************************************************************************
unsigned char ucKEY_Together(My_KEY_TypeDef* ptKEY1, My_KEY_TypeDef* ptKEY2)
{
    if((ptKEY1->cState & KEY_PRESS) && (ptKEY2->cState & KEY_PRESS))
    {
        if((ptKEY1->iTime - ptKEY2->iTime)<30 && (ptKEY2->iTime - ptKEY1->iTime)<30)
        {
            ptKEY1->cState = 0;
            ptKEY2->cState = 0;
            return (1);
        }
    }
    return (0);
}
//**************************************************************************************************
//函数名：	ucKEY_Ret()
//说  明：	复位按键
//参  数：	ptKEYx：按键结构体指针
//返回值：	无
//**************************************************************************************************
void vKEY_Ret(My_KEY_TypeDef* ptKEYx)
{
    ptKEYx->cState = 0;
    ptKEYx->iTime  = 0;
    ptKEYx->iTimed = 0;
}
//**************************************************************************************************
//函数名：	vKEY_Edge_Ret(My_KEY_TypeDef* ptKEYx)
//说  明：	复位边沿触发变量
//参  数：	ptKEYx：按键结构体指针
//返回值：	无
//**************************************************************************************************
void vKEY_Edge_Ret(My_KEY_TypeDef* ptKEYx)
{
    ptKEYx->cState &= KEY_H_L_D;
}


