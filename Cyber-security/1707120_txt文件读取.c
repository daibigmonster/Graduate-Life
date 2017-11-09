#include<stdio.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
#include<iostream>
using namespace std;
int main()
{
    FILE *fp;
    int unit=sizeof(char);
    cout<<"字符的长度是："<<unit<<"字节"<<endl;
    char str[5];
    memset(str, 0, sizeof(str));
    if((fp=fopen("test.txt","r"))==NULL)
    {
       cout<<"错误文件"<<endl;
       exit(0);
    }
    fseek(fp,1,SEEK_SET);
    if(fread(str,1,5,fp)!=1)
    {
       cout<<"字符串读取完成！"<<endl;
    }
    for(int i=0;i<5;i++)
    {
        cout<<str[i]<<" ";
    }
    cout<<endl;
    fclose(fp);
    return 0;
}
