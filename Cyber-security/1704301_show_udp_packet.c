#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <nids.h>
struct ip_header//IP协议格式
{
   #ifdef WORDS_BIGENDIAN
   u_int8_t ip_version:4,//IP协议版本
            ip_header_length:4;//ip协议首部长度
   #else 
   u_int8_t ip_header_length:4,
            ip_version:4;
   #endif
   u_int8_t ip_tos;//TOS服务质量
   u_int16_t ip_length;//总长度
   u_int16_t ip_id;//标识
   u_int16_t ip_off;//偏移
   u_int8_t ip_ttl;//生存时间
   u_int8_t ip_protocol;//协议类型
   u_int16_t ip_checksum;//校验和
   struct in_addr ip_source_address;//源IP地址
   struct in_addr ip_destination_address;//目的IP地址      
};




struct udp_header//UDP协议格式的定义
{
   u_int16_t udp_source_port;//源端口    
   u_int16_t udp_destination_port;//目的端口
   u_int16_t udp_length;//长度
   u_int16_t udp_checksum;//校验和
};

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

//UDP协议函数的定义
void udp_protocol_packet_callback(struct ip* packet_content)
{
   struct udp_header *udp_protocol;//UDP协议变量
   u_short source_port;//源端口号
   u_short destination_port;//目的端口号
   u_short length;//长度
   udp_protocol=(struct udp_header *)(packet_content+20);//获得UDP协议数据
   source_port=ntohs(udp_protocol->udp_source_port);//获得源端口号
   destination_port=ntohs(udp_protocol->udp_destination_port);//获得目的端口号
   length=ntohs(udp_protocol->udp_length);//长度   
   printf("---------------------UDP协议首部--------------------\n");
   printf("源端口:%d\n",source_port);//输出源端口号
   printf("目的端口:%d\n",destination_port);//输出源端口号
   switch(destination_port)  //判断上层协议类型
    {  
        case 138:printf("NBTBIOS Datagram Service\n");break;//端口是130,表示上层协议是NetBIOS数据包服务  
        case 137:printf("NBTBIOS Name Service\n");break;//端口是137,表示上层协议是NetBIOS名字服务
        case 139:printf("NBTBIOS session Service\n");break;//端口是139,表示上层协议是NetBIOS会话服务
        case 53:printf("name-domain server\n");break;//端口是53,表示上层协议是域名服务
        default:printf("Unknow Protocol!\n");break;
     } 
   printf("Length:%u\n",length);//长度
   printf("Checksum:%u\n",ntohs(udp_protocol->udp_checksum));//获得校验和
     
}    
//实现IP数据包分析的函数定义
void ip_protocol_packet_callback(struct ip* packet_content)
{
   struct ip_header *ip_protocol;//ip协议变量
   u_int header_length;//长度
   u_int offset;//偏移
   u_char tos;//服务质量
   u_int16_t checksum;//校验和
   ip_protocol=(struct ip_header *)(packet_content);
//获得IP协议数据内容，去掉以太网头
   checksum=ntohs(ip_protocol->ip_checksum);//获得校验和
   header_length=ip_protocol->ip_header_length*4;//获得长度
   tos=ip_protocol->ip_tos;//获得tos
   offset=ntohs(ip_protocol->ip_off);//获得偏移量
   printf("---------------------IP协议首部--------------------\n");
   printf("IP版本:%d\n",ip_protocol->ip_version);
   printf("首部长度:%d\n",header_length);
   printf("TOS:%d\n",tos);
   printf("总长度:%d\n",ntohs(ip_protocol->ip_length));//获得总长度
   printf("标识:%d\n",ntohs(ip_protocol->ip_id));//获得标识
   printf("偏移:%d\n",(offset&0x1fff)*8);
   printf("生存时间:%d\n",ip_protocol->ip_ttl);//获得TTL
   printf("协议:%d\n",ip_protocol->ip_protocol);//获得协议类型
   switch(ip_protocol->ip_protocol)  //判断协议类型的值
    {  
        case 6:printf("The Transport Layer Protocol is TCP\n");break;//如果协议类型为6,表示上层协议为TCP协议  
        case 17:printf("The Transport Layer Protocol is UDP\n");break;//如果协议类型为17,表示上层协议为UDP协议   
        case 1:printf("The Transport Layer Protocol is ICMP\n");break;//如果协议类型为1,表示上层协议为ICMP协议 
        default:printf("Unknow Protocol!");break;
    }  
    printf("校验和:%d\n",checksum);
    printf("源IP地址:%s\n",inet_ntoa(ip_protocol->ip_source_address));//获得源IP地址
    printf("目的IP地址:%s\n",inet_ntoa(ip_protocol->ip_destination_address));//获得目的IP地址
    switch(ip_protocol->ip_protocol)  //判断协议类型的值
    {    
        case 17:udp_protocol_packet_callback(packet_content);break;//如果协议类型为17,表示上层协议为UDP协议   
        default:printf("Unknow Protocol!");break;
    }    
 }
//下面是回调函数，此回函数在nids_register_udp中被注册
void udp_callback(struct tuple4* addr, char* buf,int len,struct ip* iph)
{
    int i;
   // char content[65535];
   // char content_urgent[65535];
   // char tcp_content[65535];
    char buffer[1024];
    strcpy(buffer,inet_ntoa(*((struct in_addr *)&(addr->saddr))));
    sprintf(buffer+strlen(buffer)," : %i",addr->source);
    strcat(buffer,"->");
    strcat(buffer,inet_ntoa(*((struct in_addr *)&(addr->daddr))));
    sprintf(buffer+strlen(buffer)," : %i",addr->dest);
    strcat(buffer,"\n");
    printf("--------------------BEGIN--------------------\n");
    printf("%s",buffer);
    ip_protocol_packet_callback(iph);//调用分析IP协议函数
    printf("----------UDP数据包内容-----------");
    for(i=0;i<len;i++)
    {
        if(i%50==0)
        {
            printf("\n");
        }
        printf("%s",char_to_ascii(buf[i]));
    }
    printf("\n");
    printf("--------------------END---------------------\n");
    printf("\n");
    return ;
}
int main()
{
 /*   struct nids_chksum_ctl temp;
    temp.netaddr = 0;
    temp.mask = 0;
    temp.action = 1;
    nids_register_chksum_ctl(&temp,1);*/
    if(!nids_init())
    {
        printf("%s\n",nids_errbuf);
        exit(1);
    }

    nids_register_udp((void *)udp_callback);
    nids_run();
    return 0;
}

        

