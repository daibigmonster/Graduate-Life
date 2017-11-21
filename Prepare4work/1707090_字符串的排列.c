//题目：输入一个字符串，打印出该字符串中字符的所有排列，例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba
//#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
void Permutation1(char* pStr,char* pBegin)
{
   static int i=0;
   //printf("第%d遍:",i++);
   if(*pBegin=='\0')printf("%d:排列结果 %s\n",i++,pStr);
   else
   {
      for(char* pCh=pBegin;*pCh!='\0';++pCh)
      {
      	  char temp=*pCh;
      	  *pCh=*pBegin;
      	  *pBegin=temp;
      	  printf(" %s\n",pStr);
      	 // Permutation1(pStr,pBegin+1);
      	  temp=*pCh;
      	  *pCh=*pBegin;
      	  *pBegin=temp;
      	  //printf(" %s\n",pStr);
      }
   }
}
void Permutation(char* pStr)
{
    
    if(pStr==NULL)return;
    Permutation1(pStr,pStr);
    
}


int main()
{
   char pStr[]="abc";
   Permutation(pStr);
   return 0;
   }
