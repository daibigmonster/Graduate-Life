//请实现一个函数，把字符串中的每个空额替换成“%20”。例如输入“We are happy”,则输出“We%20are%20happy”
//我们可以先遍历一次字符串，这样就能统计出字符串中空格的总数，并可以由此计算出替换之后的字符串的总长。每替换一个空格，长度增加2,因此替换以后字符串的串读等原来的长度加上2乘以空格的数目。我们还是以前面的字符串“We are happy”为例，这个字符串的长度是14（包括结尾符号‘\0’）,里满由两个空格，因此替换之后字符串的长度是18。
//我们从字符串的后面开始复制和替换。首先准备两个指针，P1和P2。P1指向原始字符串的末尾。而P2指向那个替换之后的字符串的末尾。接下来我们向前移动指针P1,逐个把它指向的字符复制到P2指向的位置，直到碰到第一个空格为止。灰色背景的区域是做了字符拷贝（移动）区域。碰到第一个空格之后，把P1向前移动一格，在P2之前插入字符串“%20”。由于“%20”的长度为3,同时也要把P2向前移动3格。
//我们接着向前复制，直到碰到第二个空格。和上一次一样，我们再把P1向前移动1格，并把P2向前移动3个插入“%20”。此时P1和P2指向同一个位置，标明所有空额都已经替换完毕。
//从上面的分析我们可以看出，所有的字符都只复制一次，因此这个算法的时间效率是O（n）。
#include<iostream>
using namespace std;
void RB(char string[],int len)
{
    if(string==NULL&&len<=0)return;
    int orilen=0;
    int numbla=0;
    int i=0;
    while(string[i]!='\0'){
        ++orilen;
        if(string[i]==' ')++numbla;
        ++i;
    }
    int newlen=orilen+numbla*2;
    if(newlen>len)return;
    int inori=orilen;
    int innew=newlen;
    while(inori>=0&&innew>inori)
    {
            if(string[inori]==' ')
            {
                string[innew--]='0';
                string[innew--]='2';
                string[innew--]='%';
             }
             else
             {
                 string[innew--]=string[inori];
             }
             --inori;
     }
     
}
int main()
{
    char str[100]="We are great people";
    RB(str,100);
    cout<<str<<endl;
    return 0;
    
}

