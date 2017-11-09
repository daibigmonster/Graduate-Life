 /*给定两个字符串s1和s2,要求判定s2是否能被s1做循环移位（rotate）的到的字符串包含。例如，给定s1=AABCD和s2=CDAA，返回true;给定s1=ABCD和ACBD，返回false。*/
//从题目中可以看出，我们可以使用最直接的方法对s1进行循环移位，在进行包含的判断，从而便利其所有的可能性
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 20
int compare(char src[num],char des[num])
{
    int len=strlen(src);
    for(int i=0;i<len;i++)
    {
        char tempchar=src[0];
        for(int j=0;j<len-1;j++)
            src[j]=src[j+1];
        src[len-1]=tempchar;
        if(strstr(src,des)==0)//strstr(str1,str2)函数用于判断字符串str2是否是str1的字串。如果是，则该函数返回str2在str1中首次出现的地址;否则，返回NULL
        {
            return 1;
        }
     }
 return 0;
 }
 int main()
 {
     int a;
     char src[num]="AABBCD";
     char des[num]="CDAA";
     if(compare(src,des))
     {printf("配对成功！\n");}
     return 0;
 }    
//本题目的关键在于如何循环字符串的操作;
         
         
