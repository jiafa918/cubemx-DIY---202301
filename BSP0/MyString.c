/*******************************************************************************
* �� ��: MyString.c
* �� ��: �ַ������ݵĴ�����
* ˵ ��:������UART��������
* �� д: Henry_zhu
* �� ��: 2018��12��24��16:38:32
*******************************************************************************/
#include "MyString.h"


/*******************************************************************************
* ���� : �����ַ�������
*******************************************************************************/
unsigned char Len(char *String)
{
    unsigned char count = 0;
    while(*String++!='\0') count++;
    return count;
}


/*******************************************************************************
*���� : ����ַ����е���������
*******************************************************************************/
void Clear(char *String)
{
    while(*String!='\0') *String++='\0';
}

/*******************************************************************************
*���� : ���ַ�������nλ
*******************************************************************************/
void Move(char *String,unsigned char Len)
{
    while(*String!='\0')
		{
//			*String ++ =*(String+Len);
			
		}			
}

/*******************************************************************************
*���� : ���ڶ����ַ���׷�ӵ���һ���ַ�������  ������ַ���������һ���ַ�Ҳ�������һ���ַ��ǿո�
*ע�� : ��һ���ַ���Ҫ����,�����м䲻���пո�,ĩβҪ�пո�
*******************************************************************************/
void Append(char *String1,char *String2)
{
    while(*String1++!='\0');
    String1--;
    while(*String2!='\0') *String1++=*String2++;
    *String1='\0';
}

/*******************************************************************************
*���� : ����߿�ʼ��ȡָ�����ȵ��ַ���
*******************************************************************************/
void Left(char *String,char *NewString,unsigned char len)
{
    unsigned char i=len;
    while(i--) *NewString++=*String++;
    *NewString = '\0';
}

/*******************************************************************************
*���� : ���ұ߿�ʼ��ȡָ�����ȵ��ַ���
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
*���� : ���м��ȡָ�����ȵ��ַ���
*******************************************************************************/
void Mid(char *String,char *NewString,unsigned char start,unsigned char len)
{
    unsigned char i=len;
    String+=--start;
    while(i--)*NewString++=*String++;
    *NewString='\0';
}

/*******************************************************************************
 * ���� : ��String������Search
 * ����ֵ: Search��String�г��ֵ�λ��, ���û��,����ֵΪ0
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
 * ���� : �ַ����ָ��
 * String: Ҫ���зָ����ַ���
 * NewString: ���ɵ����ַ���, �Ƕ�ά����, ÿ�����20��Ԫ��
 * split: �ָ��ַ�,�����ַ�
 * ����ֵ: ���صĶ�ά���������
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
*���� : �ַ����ȽϺ��� ��ͬ����0,����ͬ����1
*˵�� : len��Ҫ�Ƚϵ��ַ�������, len=0��ʾȫ���Ƚ�
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
* ���� : 2λʮ�����ַ�ת�ֽ�������
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
* ���� : 2λʮ�������ַ�ת�ֽ�������
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
* ���� : 4λʮ�������ַ�ת��������
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
* ���� : 4λʮ�����ַ�ת��������
*******************************************************************************/
unsigned int DecToInt(char *String)
{
    unsigned int num1,num2,num3,num4,num = 0;
    num1 = *String++ - 0x30; //ת��ǧλ
    num2 = *String++ - 0x30; //ת����λ
    num3 = *String++ - 0x30; //ת��ʮλ
    num4 = *String++ - 0x30; //ת����λ
    num = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
    return num;
}

/*******************************************************************************
* ���� : 4λʮ�������ַ�ת��������
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
* ���� : 8λ�ֽ�������ת2λʮ�������ַ�
*******************************************************************************/
void CharToHex(unsigned char dats,char *String)
{
    *String++ = Cchr((dats>>4)&0x0f);
    *String++ = Cchr(dats & 0x0f);
    *String = '\0';
}

/*******************************************************************************
* ���� : 16λ��������ת4λʮ�������ַ�
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
* ��  �ܣ�������������ת��������ַ���
* ��  ����int num����������
          char *str��Ҫת��Ϊ��Ŀ���ַ���
          int radix������  ֧���������
* ����ֵ��0
*********************************************************************************/
char myitoa(int num,char *str,int radix) 
{ 
	/* ������ */ 
	const char index[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	unsigned unum; /* �м���� */ 
	int i=0,j,k; 
	/* ȷ��unum��ֵ */ 
	if(radix==10&&num<0) /* ʮ���Ƹ��� */ 
	{ 
		unum=(unsigned)-num; 
		str[i++]='-'; 
	} 
	else unum=(unsigned)num; /* ������� */ 
	/* ���� */ 
	do  
	{ 
		str[i++]=index[unum%(unsigned)radix]; 
		unum/=radix; 
	}while(unum); 
	str[i]='\0'; 
	/* ת�� */ 
	if(str[0]=='-') k=1; /* ʮ���Ƹ��� */ 
	else k=0; 
	/* ��ԭ���ġ�/2����Ϊ��/2.0������֤��num��16~255֮�䣬radix����16ʱ��Ҳ�ܵõ���ȷ��� */ 
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
* ��  �ܣ�4λ�ֽ�������תʮ�����ַ�
* ��  ����unsigned int dats��16λ��������
          char *String��Ҫת��Ϊ��Ŀ���ַ���
* ����ֵ��0
*********************************************************************************/
void DecToString(unsigned int dats,char *String)
{
	char temp;
	temp = dats /1000;  //ǧλ
	*String++ =temp + 0x30;
	temp = dats % 1000 / 100;   //��λ
//	temp = dats / 100;
	*String++ =temp + 0x30;
	temp = dats % 1000% 100/ 10;   //ʮλ
//	temp = dats % 100;
//	temp = dats / 10;
	*String++ =temp + 0x30;
	temp = dats % 1000% 100% 10;   //��λ
//	temp = dats % 100;
//	temp = dats % 10;
	*String++ =temp + 0x30;
}

/*******************************************************************************
* ���� : 32λ����������ת8λʮ�������ַ�
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
 * ����: ����LRCУ��ֵ,׷�ӵ�������ַ���֮��
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
 * ����: ����CSУ��ֵ,׷�ӵ�������ַ���֮��
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
 * ���� : У�������ַ���LRC�Ƿ���ȷ
 * ����ֵ: 1:У��ɹ�, 0:У��ʧ��
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
 * ���� : У�������ַ���CS�Ƿ���ȷ
 * ����ֵ : 1:У��ɹ�, 0:У��ʧ��
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
* ���� : ���ֽ�����תʮ�������ַ�
*******************************************************************************/
unsigned char Cchr(unsigned char dats)
{
    if(dats < 10) return(dats + 0x30);
    else return(dats + 0x37);
}

/*******************************************************************************
* ���� : ���ֽ�ʮ�������ַ�ת����
*******************************************************************************/
unsigned char Cnum(unsigned char dats)
{
    if(dats < 0x40) return(dats - 0x30);
    else return(dats - 0x37);
}
