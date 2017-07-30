#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
int main()
{
    FILE *fp,*output;
    if((fp = fopen("1707110.pcap","r")) == NULL)
    {
        printf("文件打开错误");
        exit(0);
    }
    
