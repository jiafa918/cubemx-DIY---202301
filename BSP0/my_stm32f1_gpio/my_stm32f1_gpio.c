#include "stm32f10x.h"
#include "my_stm32f1_gpio.h"	

/**********************************************
GPIO初始化配置参数说明：

端口时钟使能参数范围：[RCC_APB2Periph_GPIOA,RCC_APB2Periph_GPIOG]    使能 ENABLE  DISABLE
GPIO_Pin 参数范围	[GPIO_Pin_0,GPIO_Pin_15] & GPIO_Pin_ALL
GPIO_Mode 参数范围[GPIO_Mode_AIN,GPIO_Mode_IN_FLOATING,GPIO_Mode_IPD,GPIO_Mode_IPU,GPIO_Mode_Out_OD,GPIO_Mode_Out_PP,GPIO_Mode_AF_OD,GPIO_Mode_AF_PP]
				   模拟输入		 浮空输入			   下拉输入		 上拉输入		开漏输出	    推挽输出		 复用开漏输出	 复用推挽输出
GPIO_Speed 参数范围[GPIO_Speed_10MHz	GPIO_Speed_2MHz		GPIO_Speed_50MHz]
**********************************************/

/***********************************************
函数名		：OUTPUT_GPIO_Init
函数功能	：初始化GPIO输出端口
参数		：无
作者		：邱根应
日期		：2021/5/11
***********************************************/
void OUTPUT_GPIO_Init(void)		
{	
	GPIO_InitTypeDef GPIO_InitStructure;                        				 //定义结构体指针
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);						//端口时钟使能
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13; 	//指定管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; 							//设置模式
														//开漏输出				推挽输出			
														//GPIO_Mode_Out_OD		GPIO_Mode_Out_PP	GPIO_Mode_AF_OD		GPIO_Mode_AF_PP
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;							//配置IO速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);										//IO口初始化
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_12|GPIO_Pin_13); 		//设置IO口初始状态		
}


/***********************************************
函数名		：OUTPUT_GPIO_Init
函数功能	：初始化GPIO输入端口
参数		：无
作者		：邱根应
日期		：2021/5/11
***********************************************/
void INPUT_GPIO_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;                        				 //定义结构体指针
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA, ENABLE);						//端口时钟使能
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4; 			//指定管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 								//设置模式
	GPIO_Init(GPIOE, &GPIO_InitStructure);										//IO口初始化
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 									//指定管脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 								//设置模式
	GPIO_Init(GPIOA, &GPIO_InitStructure);										//IO口初始化
	
}


/**************************************************************************************************
//函 数 名：	GPIO_Init()
//功    能：	GPIO初始化
//入口参数：	uiGpio： PA0~PG5 端口
//          	tMode： 模式
//          	ucOut： 初始值
//返 回 值：	无
//调用示例：	vGPIO_Init(PC7,  PP_OUT_50MHZ, 1);      PC7管脚初始化为推挽输出，速度50MHZ，初始电平为高电平
				      vGPIO_Init(PE2,  UD_IN, 1);				初始化PE2管脚为上拉输入
**************************************************************************************************/
void vGPIO_Init(unsigned int uiGpio,  GPIO_MODE tMode, unsigned char ucOut)
{
	GPIO_TypeDef * PORT = Port(uiGpio);							//获取指定GPIO端口
	unsigned int PIN = Pin(uiGpio);								//获取指定GPIO的Pin
	unsigned char temp = (((uiGpio & 0xffffff00) - GPIOA_BASE)/0x0400);

	RCC->APB2ENR|=1<<(temp+2);  							//使能对应端口时钟
	if(PIN<8)												//设置模式
	{
		PORT->CRL &= ~(0x0f<<((PIN%8)*4));
		PORT->CRL |=  (tMode<<((PIN%8)*4));
	}
	else
	{
		PORT->CRH &= ~(0x0f<<((PIN%8)*4)); 
		PORT->CRH |=  (tMode<<((PIN%8)*4));
	}
	if(ucOut)	PORT->ODR |= (1<<PIN);	//设置下拉
	else		PORT->ODR &= ~(1<<PIN);	//设置上拉
}


//**************************************************************************************************
//函 数 名：	In_Mode()
//功    能：	GPIO 设置为上拉输入
//入口参数：	uiGpio： PA0~PG5 端口
//返 回 值：	无
//备注：该函数功能已被vGPIO_Init函数包含，不推荐使用        2021年5月12日邱根应备注
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
	PORT->ODR |= (1<<PIN);	//设置上拉			
}


//**************************************************************************************************
//函 数 名：	Out_Mode()
//功    能：	GPIO 设置通用开漏输出模式速度50M
//入口参数：	uiGpio： PA0~PG5 端口
//返 回 值：	无
//备注：该函数功能已被vGPIO_Init函数包含，不推荐使用        2021年5月12日邱根应备注
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
//函 数 名：	vCLOSE_SWJ()    
//功    能：	关闭jtag-dp功能，PA15，PB3，PB4作为普通IO口使用，PA13，PA14作为SW-DP功能使用
//				
//入口参数：	无  
//返 回 值：	无
//**************************************************************************************************
void vCLOSE_SWJ(void)
{
//    RCC->APB2ENR |= (1<<0);	     //打开AFIO时钟   会使单片机下载管脚配置为普通IO，导致如果想要第二次下载就需要擦除flash中所有内容才可以；
//    AFIO->MAPR &= ~(7<<24);     //关闭JTAG-DP，启用SW-DP
//	AFIO->MAPR |=  (2<<24);
	
//	GPIO_InitTypeDef  GPIO_InitStructure;
	/* 禁用 JTAG，PB3、PB4重定义为普通IO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB |  RCC_APB2Periph_AFIO, ENABLE);//使能PORTB口时钟、复用引脚PB3、PB4引脚
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);   //关闭JTAG功能(PB3/4)，只使用SWD(PA13/14)调试
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_NoJTRST,ENABLE); 	//避免复位后才能下程序
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_3;	//端口配置
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//IO口速度为50MHz
//	GPIO_Init(GPIOB, &GPIO_InitStructure);					//根据设定参数初始化
	
//	GPIO_ResetBits(GPIOB,GPIO_Pin_4);	//PB.4 输出低
//	GPIO_ResetBits(GPIOB,GPIO_Pin_3);	//PB.3 输出低
 
//	/* PA15重定义为普通IO */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |  RCC_APB2Periph_AFIO, ENABLE);//使能PORTA口时钟、复用引脚PA15引脚
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;				//端口配置
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		//推挽输出
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//IO口速度为50MHz
//	GPIO_Init(GPIOA, &GPIO_InitStructure);					//根据设定参数初始化
	
//	GPIO_ResetBits(GPIOA,GPIO_Pin_15);	//PA.15 输出低	
	
}





