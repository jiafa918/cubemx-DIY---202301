/*******************************************************************************
* 文 件: MyString.c
* 功 能: 字符及数据的处理函数
* 说 明:常用在UART处理数据
* 编 写: Henry_zhu
* 日 期: 2018年12月24日16:38:32
*******************************************************************************/
#include "MyString.h"


/*******************************************************************************
* 功能 : 计算字符串长度
*******************************************************************************/
unsigned char Len(char *String)
{
    unsigned char count = 0;
    while(*String++!='\0') count++;
    return count;
}


/*******************************************************************************
*功能 : 清除字符串中的所有数据
*******************************************************************************/
void Clear(char *String)
{
    while(*String!='\0') *String++='\0';
}

/*******************************************************************************
*功能 : 将字符串左移n位
*******************************************************************************/
void Move(char *String,unsigned char Len)
{
    while(*String!='\0')
		{
//			*String ++ =*(String+Len);
			
		}			
}

/*******************************************************************************
*功能 : 将第二个字符串追加到第一个字符串后面  后面的字符串可以是一个字符也可以最后一个字符是空格
*注意 : 第一个字符串要够长,并且中间不能有空格,末尾要有空格
*******************************************************************************/
void Append(char *String1,char *String2)
{
    while(*String1++!='\0');
    String1--;
    while(*String2!='\0') *String1++=*String2++;
    *String1='\0';
}

/*******************************************************************************
*功能 : 从左边开始截取指定长度的字符串
*******************************************************************************/
void Left(char *String,char *NewString,unsigned char len)
{
    unsigned char i=len;
    while(i--) *NewString++=*String++;
    *NewString = '\0';
}

/*******************************************************************************
*功能 : 从右边开始截取指定长度的字符串
*******************************************************************************/
void Right(char *String,char *NewString,unsigned char len)
{
    unsigned char i=len;
    while(*String++!='\0');
    String-=++len;
    while(i--)*NewString++=*String++;
    *NewString = '\0';
}

/*******************************************************************************
*功能 : 从中间截取指定长度的字符串
*******************************************************************************/
void Mid(char *String,char *NewString,unsigned char start,unsigned char len)
{
    unsigned char i=len;
    String+=--start;
    while(i--)*NewString++=*String++;
    *NewString='\0';
}

/*******************************************************************************
 * 功能 : 在String中搜索Search
 * 返回值: Search在String中出现的位置, 如果没有,返回值为0
*******************************************************************************/
unsigned char InStr(char *String,char *Search)
{
    unsigned char i,j;
    unsigned char len1,len2;
    len1 = Len(String);
    len2 = Len(Search);
    if(len1<len2) return 0;
    for(i=0;i<=(len1-len2);i++)
    {
        for(j=0;j<len2;j++)
        {
            if(*(String+i+j)!=*(Search+j)) continue;
            if(j==len2-1) return i+1;
        }
    }
    return 0;
}

/*******************************************************************************
 * 功能 : 字符串分割函数
 * String: 要进行分隔的字符串
 * NewString: 生成的新字符串, 是二维数组, 每行最多20个元素
 * split: 分隔字符,单个字符
 * 返回值: 返回的二维数组的行数
*******************************************************************************/
unsigned char Split(char *String,char (*NewString)[20],char Split)
{
    unsigned char i=0,j=0;
    while(*String != '\0')
    {
        if(*String == Split)
        {
            NewString[i++][j] = '\0';
            j=0;
            String++;
        }
        else
        {
            NewString[i][j++] = *String++;
        }
    }
    NewString[i++][j] = '\0';
    return i;
}

/*******************************************************************************
*功能 : 字符串比较函数 相同返回0,不相同返回1
*说明 : len是要比较的字符串长度, len=0表示全部比较
*******************************************************************************/
unsigned char StringCompare(char *String1,char *String2,unsigned char len)
{
    unsigned char i,j;
    if(len)
    {
        for(i=0;i<len-1;i++) if(*String1++!=*String2++) return 1;
    }
    else
    {
        i = Len(String1);
        j = Len(String2);
        if(i!=j) return 1;
        while((*String1!='\0')||(*String2!='\0'))
        {
            if(*String1++!=*String2++) return 1;
        }
    }
    return 0;
}

/*******************************************************************************
* 功能 : 2位十进制字符转字节型数据
*******************************************************************************/
unsigned char DecToChar(char *String)
{
//    unsigned char i = 2;
    unsigned char num1,num2,num = 0;
    num1 = *String++ - 0x30;
    num2 = *String - 0x30;
    num = num1 * 10 + num2;
    return num;
}

/*******************************************************************************
* 功能 : 2位十六进制字符转字节型数据
*******************************************************************************/
unsigned char HexToChar(char *String)
{
    unsigned char i = 2;
    unsigned int num = 0;
    while(i--)
    {
        num <<= 4;
        num += (*String<0x40?*String++-0x30:*String++-0x37);
    }
    return num;
}

/*******************************************************************************
* 功能 : 4位十六进制字符转整形数据
*******************************************************************************/
unsigned int HexToInt(char *String)
{
    unsigned char i=4;
    unsigned int num = 0;
    while(i--)
    {
        num <<= 4;
        num += (*String<0x40?*String++-0x30:*String++-0x37);
    }
    return num;
}

/*******************************************************************************
* 功能 : 4位十进制字符转整形数据
*******************************************************************************/
unsigned int DecToInt(char *String)
{
    unsigned int num1,num2,num3,num4,num = 0;
    num1 = *String++ - 0x30; //转换千位
    num2 = *String++ - 0x30; //转换百位
    num3 = *String++ - 0x30; //转换十位
    num4 = *String++ - 0x30; //转换个位
    num = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
    return num;
}

/*******************************************************************************
* 功能 : 4位十六进制字符转整形数据
*******************************************************************************/
unsigned long HexToLong(char *String)
{
    unsigned char i=8;
    unsigned long num = 0;
    while(i--)
    {
        num <<= 4;
        num += (*String<0x40?*String++-0x30:*String++-0x37);
    }
    return num;
}

/*******************************************************************************
* 功能 : 8位字节型数据转2位十六进制字符
*******************************************************************************/
void CharToHex(unsigned char dats,char *String)
{
    *String++ = Cchr((dats>>4)&0x0f);
    *String++ = Cchr(dats & 0x0f);
    *String = '\0';
}

/*******************************************************************************
* 功能 : 16位整型数据转4位十六进制字符
*******************************************************************************/
void IntToHex(unsigned int dats,char *String)
{
    *String++ = Cchr(dats>>12);
    *String++ = Cchr((dats>>8)&0x0f);
    *String++ = Cchr((dats>>4)&0x0f);
    *String++ = Cchr(dats&0x0f);
    *String = '\0';
}

/*********************************************************************************              
* 功  能：整型数据数据转任意进制字符串
* 参  数：int num：整型数据
          char *str：要转换为的目标字符串
          int radix：进制  支持任意进制
* 返回值：0
*********************************************************************************/
char myitoa(int num,char *str,int radix) 
{ 
	/* 索引表 */ 
	const char index[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	unsigned unum; /* 中间变量 */ 
	int i=0,j,k; 
	/* 确定unum的值 */ 
	if(radix==10&&num<0) /* 十进制负数 */ 
	{ 
		unum=(unsigned)-num; 
		str[i++]='-'; 
	} 
	else unum=(unsigned)num; /* 其它情况 */ 
	/* 逆序 */ 
	do  
	{ 
		str[i++]=index[unum%(unsigned)radix]; 
		unum/=radix; 
	}while(unum); 
	str[i]='\0'; 
	/* 转换 */ 
	if(str[0]=='-') k=1; /* 十进制负数 */ 
	else k=0; 
	/* 将原来的“/2”改为“/2.0”，保证当num在16~255之间，radix等于16时，也能得到正确结果 */ 
	char temp; 
	for(j=k;j<=(i-k-1)/2.0;j++) 
	{ 
		temp=str[j]; 
		str[j]=str[i-j-1]; 
		str[i-j-1]=temp; 
	} 
	return 0; 
} 

/*********************************************************************************              
* 功  能：4位字节型数据转十进制字符
* 参  数：unsigned int dats：16位整型数据
          char *String：要转换为的目标字符串
* 返回值：0
*********************************************************************************/
void DecToString(unsigned int dats,char *String)
{
	char temp;
	temp = dats /1000;  //千位
	*String++ =temp + 0x30;
	temp = dats % 1000 / 100;   //百位
//	temp = dats / 100;
	*String++ =temp + 0x30;
	temp = dats % 1000% 100/ 10;   //十位
//	temp = dats % 100;
//	temp = dats / 10;
	*String++ =temp + 0x30;
	temp = dats % 1000% 100% 10;   //个位
//	temp = dats % 100;
//	temp = dats % 10;
	*String++ =temp + 0x30;
}

/*******************************************************************************
* 功能 : 32位长整型数据转8位十六进制字符
*******************************************************************************/
void LongToHex(unsigned long dats,char *String)
{
    *String++ = Cchr((dats>>28)&0x0f);
    *String++ = Cchr((dats>>24)&0x0f);
    *String++ = Cchr((dats>>20)&0x0f);
    *String++ = Cchr((dats>>16)&0x0f);
    *String++ = Cchr((dats>>12)&0x0f);
    *String++ = Cchr((dats>>8)&0x0f);
    *String++ = Cchr((dats>>4)&0x0f);
    *String++ = Cchr(dats&0x0f);
    *String = '\0';
}

/*******************************************************************************
 * 功能: 计算LRC校验值,追加到调入的字符串之后
*******************************************************************************/
void Append_LRC(char *String)
{
    unsigned char result = 0;
    char temp[3];
    while(*String != '\0') result += *String++;
    result = ~result;
    result++;
    CharToHex(result,temp);
    Append(String,temp);
}

/*******************************************************************************
 * 功能: 计算CS校验值,追加到调入的字符串之后
*******************************************************************************/
void Append_CS(char *String)
{
    unsigned char result = 0;
    char temp[3];
    while(*String != '\0') result += *String++;
    result = ~result;
    CharToHex(result,temp);
    Append(String,temp);
}

/*******************************************************************************
 * 功能 : 校验调入的字符串LRC是否正确
 * 返回值: 1:校验成功, 0:校验失败
*******************************************************************************/
unsigned char Check_LRC(char *String)
{
    unsigned char result = 0,result2 = 0,len;
    char temp[3];
    len = Len(String)-2;
    while(len--) result += *String++;
    result = ~result;
    result++;
    Right(String,temp,2);
    result2 = HexToChar(temp);
    if(result == result2) return 1;
    else return 0;
}

/*******************************************************************************
 * 功能 : 校验调入的字符串CS是否正确
 * 返回值 : 1:校验成功, 0:校验失败
*******************************************************************************/
unsigned char Check_CS(char *String)
{
    unsigned char result = 0,result2 = 0,len;
    char temp[3];
    len = Len(String)-2;
    while(len--) result += *String++;
    result = ~result;
    Right(String,temp,2);
    result2 = HexToChar(temp);
    if(result == result2) return 1;
    else return 0;
}

/*******************************************************************************
* 功能 : 半字节数字转十六进制字符
*******************************************************************************/
unsigned char Cchr(unsigned char dats)
{
    if(dats < 10) return(dats + 0x30);
    else return(dats + 0x37);
}

/*******************************************************************************
* 功能 : 半字节十六进制字符转数字
*******************************************************************************/
unsigned char Cnum(unsigned char dats)
{
    if(dats < 0x40) return(dats - 0x30);
    else return(dats - 0x37);
}
