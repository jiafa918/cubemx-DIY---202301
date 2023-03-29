/*******************************************************************************
* 文 件: My String.h
* 功 能: 字符及数据的处理函数
* 说 明:常用在UART处理数据
* 编 写: Henry_zhu
* 日 期: 2018年12月24日16:36:25
*******************************************************************************/
#ifndef __MyString_H
#define __MyString_H	
#include "stdio.h"

/*******************************************************************************
itoa()：将整型值转换为字符串。
ltoa()：将长整型值转换为字符串。
ultoa()：将无符号长整型值转换为字符串。
gcvt()：将浮点型数转换为字符串，取四舍五入。
ecvt()：将双精度浮点型值转换为字符串，转换结果中不包含十进制小数点。
fcvt()：指定位数为转换精度，其余同ecvt()。

atof()：将字符串转换为双精度浮点型值。  验证OK
atoi()：将字符串转换为整型值。          验证OK  15.500000(六位小数点)
atol()：将字符串转换为长整型值。        验证OK
strtod()：将字符串转换为双精度浮点型值，并报告不能被转换的所有剩余数字。
strtol()：将字符串转换为长整值，并报告不能被转换的所有剩余数字。
strtoul()：将字符串转换为无符号长整型值，并报告不能被转换的所有剩余数字。
*********************************************************************************/

extern char myitoa(int num,char *str,int radix) ;      //数值转换为字符串(任意进制)
extern unsigned char Len(char *String);                                                //计算字符串长度
extern void Clear(char *String);                                                       //清除字符串中的所有数据
extern void Move(char *String,unsigned char Len);                                      //将字符串左移n位
extern void Append(char *String1,char *String2);                                       //将第二个字符串追加到第一个字符串后面   注意 : 第一个字符串要够长,并且中间不能有空格,末尾要有空格  后面的字符串可以是一个字符
extern void Left(char *String,char *NewString,unsigned char len);                      //从左边开始截取指定长度的字符串
extern void Right(char *String,char *NewString,unsigned char len);                     //从右边开始截取指定长度的字符串
extern void Mid(char *String,char *NewString,unsigned char start,unsigned char len);   // 从中间截取指定长度的字符串
extern unsigned char InStr(char *String,char *Search);                                 //在String中搜索Search    返回值: Search在String中出现的位置, 如果没有,返回值为0

extern unsigned char Split(char *String,char (*NewString)[20],char Split); 
/*******************************************************************************
 * 功能 : 字符串分割函数
 * String: 要进行分隔的字符串
 * NewString: 生成的新字符串, 是二维数组, 每行最多20个元素
 * split: 分隔字符,单个字符
 * 返回值: 返回的二维数组的行数************************************************/

extern unsigned char StringCompare(char *String1,char *String2,unsigned char len);  
/*******************************************************************************
*功能 : 字符串比较函数 相同返回0,不相同返回1
*说明 : len是要比较的字符串长度, len=0表示全部比较*/

extern unsigned char HexToChar(char *String);                  //2位十六进制字符转字节型数据
extern unsigned char DecToChar(char *String);                  //2位十进制字符转字节型数据
extern unsigned int HexToInt(char *String);                    //4位十六进制字符转int整形数据
extern unsigned long HexToLong(char *String);                  //4位十六进制字符转Long整形数据
extern unsigned int DecToInt(char *String);                    //4位十进制字符转整形数据
extern void CharToHex(unsigned char dats,char *String);        //8位字节型数据转2位十六进制字符
void DecToString(unsigned int dats,char *String);              //16位字节型数据转十进制字符
extern void IntToHex(unsigned int dats,char *String);          //16位整型数据转4位十六进制字符
extern void LongToHex(unsigned long dats,char *String);        // 32位长整型数据转8位十六进制字符
extern void Append_LRC(char *String);                          //计算LRC校验值,追加到调入的字符串之后
extern void Append_CS(char *String);                           //计算CS校验值,追加到调入的字符串之后
extern unsigned char Check_LRC(char *String);                  //校验调入的字符串LRC是否正确 返回值: 1:校验成功, 0:校验失败
extern unsigned char Check_CS(char *String);                   //校验调入的字符串CS是否正确    返回值 : 1:校验成功, 0:校验失败
extern unsigned char Cchr(unsigned char dats);                  //半字节数字转十六进制字符
extern unsigned char Cnum(unsigned char dats);                  //半字节十六进制字符转数字
#endif
