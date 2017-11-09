/*题目1：输入一个英文句子，反转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串“I am a student”,则输出“student. a am I”
第一步：反转句子中所有的字符。比如反转"I am a student."中所有的字符得到".tneduts a ma I"，此时不但反转了句子中单词的顺序，连单词内的字符顺序也翻转了。第二步再反转每个单词中字符的顺序。*/
//第一步：
void Reverse(char* pBegin,char* pEnd)
{
    if(pBegin==NULL||pEnd==NULL)return;
    while(pBegin<pEnd)
    {
        char temp=*pbegin;
        *pbegin=*pEnd;
        *pEnd=temp;
        pBegin++,pEnd--;
    }
}
char* ReverseSentence(char *pData)
{
     if(pData)return NULL;
     char* pBegin=pData;
     char* pEnd=pData;
     while(*pEnd!='\0')
         pEnd++;
     pEnd--;
     Reverse(pBegin,pEnd);
     pBegin=pEnd=pData;
     while(*pbegin!='\0')
     {
         if(*pbegin==' ')
         {
             pBegin++;
             pEnd++;
         }
         else if(*pEnd==' '||*pEnd='0'){
             Reverse(pBegin,--pEnd);
             pBegin=++pEnd;
         }
         else
             pEnd++;
     }
     return pData;
}
