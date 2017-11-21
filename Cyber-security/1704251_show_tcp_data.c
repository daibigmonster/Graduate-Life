//Libnids提供了TCP数据流重组的功能，它可以显示任何基于TCP协议的应用层。利用Libnids可以很好地实现显示TCP的连接过程，并对它们的传输数据进行详细的分析。
#include "nids.h"//Libnids头文件
#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
char ascii_string[10000];
char* char_to_ascii(char ch)//该函数的功能主要用于把协议数据进行显示
{
   char* string;
   ascii_string[0]=0;
   string=ascii_string;
   if(isgraph(ch))//可打印字符
   {
      *string++=ch;
   }
   else if (ch==' ')
   {
      *string++=ch;
   }
   else if(ch=='\n'||ch=='\r')//回车和换行
   {
      *string++=ch;
   }
   else//其他字符以"."表示
   {
      *string++='.';
   }
   *string=0;
   return ascii_string;
}
//下面的函数是回调函数，用于分析TCP连接和TCP连接状态，并对TCP协议传输的数据进行分析
void tcp_protocol_callback(struct tcp_stream * tcp_connection,void ** arg)
{
   int i;
   char address_string[1024];
   char content[65535];
   char content_urgent[65535];
   struct tuple4 ip_and_port=tcp_connection->addr;//获取TCP连接的地址和端口对
   strcpy(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr))));//获取源地址
   sprintf(address_string+strlen(address_string)," : %i",ip_and_port.source);//获取源端口
   strcat(address_string,"<--->");
   /*将两个char类型连接。
   char d[20]="GlodenGlobal",char *s="View";
   stracat(d,s);
   结果放在d中，printf("%s",d);输出d为GolednGlobalView*/
   strcat(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr))));//获得目的地址
   sprintf(address_string+strlen(address_string)," : %i",ip_and_port.dest);//获取目的端口
//sprintf函数
//字符串格式化命令，主要功能是把格式化的数据写入某个字符串中
//原型：int sprintf(char *buffer,const char *format,[argument]...);
//参数列表：
//buffer:char型指针。指向将要写入的字符串缓冲区
//firmat:格式化字符串
//[argument]...:可选参数，可以是任何类型的数据
   strcat(address_string,"\n");
   switch(tcp_connection->nids_state)//判断LIBNIDS的状态
   {
   case NIDS_JUST_EST://表示TCP客户端和TCP服务器端建立连接状态
      tcp_connection->client.collect++;//客户端接收数据
      tcp_connection->server.collect++;//服务器接收数据
      tcp_connection->server.collect_urg++;//服务器接收紧急数据
      tcp_connection->client.collect_urg++;//客户端接收紧急数据
      printf("%sTCP连接建立\n",address_string);
      break;
   case NIDS_CLOSE://表示TCP连接正常关闭
      printf("-----------------------------\n");
      printf("%sTCP连接正常关闭\n",address_string);
      break;
   case NIDS_RESET://表示TCP连接被RST关闭
      printf("-----------------------------\n");
      printf("%sTCP连接被RST关闭\n",address_string);
      break;
   /*case NIDS_DATA://表示有新的数据到达
      {
         struct half_stream * hlf;//表示TCP连接的一端信息，可以是客户端，也可以是服务器端  
         if(tcp_connection->server.count_new_urg)//表示TCP服务器端接收到新的紧急数据
         {
            printf("--------------------\n");
            strcpy(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr))));
            sprintf(address_string+strlen(address_string)," : %i",ip_and_port.source);
            strcat(address_string,"urgent--->");
            strcat(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr))));
            sprintf(address_string+strlen(address_string)," : %i",ip_and_port.dest);
            strcat(address_string,"\n");
            address_string[strlen(address_string)+1]=0;
            address_string[strlen(address_string)]=tcp_connection->server.urgdata;
            printf("%s",address_string);
            break;
         }
         if(tcp_connection->client.count_new_urg)//表示TCP客户端接收到新的紧急数据
         {
            printf("--------------------\n");
            strcpy(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr))));
            sprintf(address_string+strlen(address_string)," : %i",ip_and_port.source);
            strcat(address_string,"<---urgent");
            strcat(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr))));
            sprintf(address_string+strlen(address_string)," : %i",ip_and_port.dest);
            strcat(address_string,"\n");
            address_string[strlen(address_string)+1]=0;
            address_string[strlen(address_string)]=tcp_connection->server.urgdata;
            printf("%s",address_string);
            break;
         };
         if(tcp_connection->client.count_new)//表示客户端接收到新的数据
         {
            hlf=&tcp_connection->client;//此时hlf表示的是客户端的TCP连接信息
            strcpy(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr))));
            sprintf(address_string+strlen(address_string)," : %i",ip_and_port.source);
            strcat(address_string,"<---");            
            strcat(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr))));
            sprintf(address_string+strlen(address_string)," : %i",ip_and_port.dest);
            strcat(address_string,"\n");
            printf("--------------------\n");
            printf("%s",address_string);
            memcpy(content,hlf->data,hlf->count_new);
            content[hlf->count_new]='\0';
            printf("客户端接收数据\n");
            for(i=0;i<hlf->count_new;i++)
            {
               printf("%s",char_to_ascii(content[i]));
               //输出客户端接收的新的数据，也已打印字符进行显示
           }
           printf("\n");
         } 
      else
      {
         hlf=&tcp_connection->server;//此时hlf表示服务器端的TCP连接信息
         strcpy(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr))));
         sprintf(address_string+strlen(address_string),"%i",ip_and_port.source);
         sprintf(address_string,"--->");
         strcat(address_string,inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr))));
         sprintf(address_string+strlen(address_string),":%i",ip_and_port.dest);
         strcat(address_string,"\n");
         printf("--------------------\n");
            printf("%s",address_string);
            memcpy(content,hlf->data,hlf->count_new);
            content[hlf->count_new]='\0';
            printf("服务器端接收数据\n");
            for(i=0;i<hlf->count_new;i++)
            {
               printf("%s",char_to_ascii(content[i]));
               //输出服务端接收的新的数据
            }
           printf("\n");
         }
      }*/
   default:
      break;
   }
 //  break;
}
   
int main()
{
   struct nids_chksum_ctl temp;
   temp.netaddr = 0;
   temp.mask = 0;
   temp.action = 1;
   nids_register_chksum_ctl(&temp,1);//1代表不需要校验和
   //nids_params.device = "enp2s0";
   nids_params.filename = "1707110.pcap";
   int a=nids_init();
   if(!a)//Libnids初始化
   {
      printf("出现错误：%s\n",nids_errbuf);
      exit(1);
   }
   
   nids_register_tcp((void*)tcp_protocol_callback);//注册回调函数
   nids_run();//Libnids进入循环捕获数据包状态
   printf("%d\n",a);
   return 0;
}
/*
void tcp_callback(struct tcp_strea * ns,void **param);
参数描述：参数是一个回调函数
此函数是注册一个TCP连接的回调函数。回调函数的类型定义如下：
void tcp_callback(struct tcp_stream * ns,void ** param);
其中参数ns表示一个TCP连接的所有信息，它的类型是tcp_stream数据结构;参数param表示要传递的连接参数信息，可以指向一个TCP连接的私有数据。
此回调函数接受到的TCP数据存放在half_stream的缓存中，应该马上取出来，一旦此回调函数返回，此数据缓存中存储的数据就不存在了。half_stream成员offset描述了被丢弃的数据字节数。如果不想马上取出来，而是等到存储到一定量的数据之后再取出来，那么可以使用函数nids_discard(struct tcp_stream * a_tcp,int num_bytes)来处理。这样，回调函数返回时，Libnids将丢弃缓存数据之前的num_bytes字节的数据。如果不掉用nisd_discard()函数，那么缓存数据的字节应该为count_new字节。一般情况下，缓存中的数据应该是count_offset字节。*/
