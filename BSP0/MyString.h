/*******************************************************************************
* �� ��: My String.h
* �� ��: �ַ������ݵĴ�����
* ˵ ��:������UART��������
* �� д: Henry_zhu
* �� ��: 2018��12��24��16:36:25
*******************************************************************************/
#ifndef __MyString_H
#define __MyString_H	
#include "stdio.h"

/*******************************************************************************
itoa()��������ֵת��Ϊ�ַ�����
ltoa()����������ֵת��Ϊ�ַ�����
ultoa()�����޷��ų�����ֵת��Ϊ�ַ�����
gcvt()������������ת��Ϊ�ַ�����ȡ�������롣
ecvt()����˫���ȸ�����ֵת��Ϊ�ַ�����ת������в�����ʮ����С���㡣
fcvt()��ָ��λ��Ϊת�����ȣ�����ͬecvt()��

atof()�����ַ���ת��Ϊ˫���ȸ�����ֵ��  ��֤OK
atoi()�����ַ���ת��Ϊ����ֵ��          ��֤OK  15.500000(��λС����)
atol()�����ַ���ת��Ϊ������ֵ��        ��֤OK
strtod()�����ַ���ת��Ϊ˫���ȸ�����ֵ�������治�ܱ�ת��������ʣ�����֡�
strtol()�����ַ���ת��Ϊ����ֵ�������治�ܱ�ת��������ʣ�����֡�
strtoul()�����ַ���ת��Ϊ�޷��ų�����ֵ�������治�ܱ�ת��������ʣ�����֡�
*********************************************************************************/

extern char myitoa(int num,char *str,int radix) ;      //��ֵת��Ϊ�ַ���(�������)
extern unsigned char Len(char *String);                                                //�����ַ�������
extern void Clear(char *String);                                                       //����ַ����е���������
extern void Move(char *String,unsigned char Len);                                      //���ַ�������nλ
extern void Append(char *String1,char *String2);                                       //���ڶ����ַ���׷�ӵ���һ���ַ�������   ע�� : ��һ���ַ���Ҫ����,�����м䲻���пո�,ĩβҪ�пո�  ������ַ���������һ���ַ�
extern void Left(char *String,char *NewString,unsigned char len);                      //����߿�ʼ��ȡָ�����ȵ��ַ���
extern void Right(char *String,char *NewString,unsigned char len);                     //���ұ߿�ʼ��ȡָ�����ȵ��ַ���
extern void Mid(char *String,char *NewString,unsigned char start,unsigned char len);   // ���м��ȡָ�����ȵ��ַ���
extern unsigned char InStr(char *String,char *Search);                                 //��String������Search    ����ֵ: Search��String�г��ֵ�λ��, ���û��,����ֵΪ0

extern unsigned char Split(char *String,char (*NewString)[20],char Split); 
/*******************************************************************************
 * ���� : �ַ����ָ��
 * String: Ҫ���зָ����ַ���
 * NewString: ���ɵ����ַ���, �Ƕ�ά����, ÿ�����20��Ԫ��
 * split: �ָ��ַ�,�����ַ�
 * ����ֵ: ���صĶ�ά���������************************************************/

extern unsigned char StringCompare(char *String1,char *String2,unsigned char len);  
/*******************************************************************************
*���� : �ַ����ȽϺ��� ��ͬ����0,����ͬ����1
*˵�� : len��Ҫ�Ƚϵ��ַ�������, len=0��ʾȫ���Ƚ�*/

extern unsigned char HexToChar(char *String);                  //2λʮ�������ַ�ת�ֽ�������
extern unsigned char DecToChar(char *String);                  //2λʮ�����ַ�ת�ֽ�������
extern unsigned int HexToInt(char *String);                    //4λʮ�������ַ�תint��������
extern unsigned long HexToLong(char *String);                  //4λʮ�������ַ�תLong��������
extern unsigned int DecToInt(char *String);                    //4λʮ�����ַ�ת��������
extern void CharToHex(unsigned char dats,char *String);        //8λ�ֽ�������ת2λʮ�������ַ�
void DecToString(unsigned int dats,char *String);              //16λ�ֽ�������תʮ�����ַ�
extern void IntToHex(unsigned int dats,char *String);          //16λ��������ת4λʮ�������ַ�
extern void LongToHex(unsigned long dats,char *String);        // 32λ����������ת8λʮ�������ַ�
extern void Append_LRC(char *String);                          //����LRCУ��ֵ,׷�ӵ�������ַ���֮��
extern void Append_CS(char *String);                           //����CSУ��ֵ,׷�ӵ�������ַ���֮��
extern unsigned char Check_LRC(char *String);                  //У�������ַ���LRC�Ƿ���ȷ ����ֵ: 1:У��ɹ�, 0:У��ʧ��
extern unsigned char Check_CS(char *String);                   //У�������ַ���CS�Ƿ���ȷ    ����ֵ : 1:У��ɹ�, 0:У��ʧ��
extern unsigned char Cchr(unsigned char dats);                  //���ֽ�����תʮ�������ַ�
extern unsigned char Cnum(unsigned char dats);                  //���ֽ�ʮ�������ַ�ת����
#endif
