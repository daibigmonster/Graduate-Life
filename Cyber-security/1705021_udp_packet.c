#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <nids.h>
#include <libnet.h>
int main()
{
    //const u_char *packet_content; 
    int a=nids_init();
    //它的主要内容包括打开网络接口、打开文件、编译过滤规则、设置过滤规则、判断网络链路层类型、进行必要的初始化工作
    if(a)
    {
        printf("初始化成功！\n");
    }
    else
    {
    printf("出现错误：%s\n",nids_errbuf);
    }
    int b=nids_next();//调用捕获数据包函数pcap_next()
    if(b)
    {
        printf("捕捉数据包成功！\n");
    }
    nids_register_udp(udp_callback());
    nids_run();//它实际上是调用Libpcap函数pcap_loop()来循环捕获数据包
	return 0; 
}
