/*捕获UDP数据包，是在分析IP协议的基础上进行的，因为UDP协议是基于IP协议的。在之前分析IP协议的时候，有一个字段是协议字段，它表示的就是上层协议类型。如果它表示的是UDP协议，那么就可以继续分析UDP协议了。而分析IP协议是在分析以太网协议基础上进行的，所以也要分析以太网协议*/
#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include "nids.h"
struct ether_header//以太网协议的数据格式
{
   u_int8_t ether_dhost[6];//目的以太网地址
   u_int8_t ether_shost[6];//源以太网地址
   u_int16_t ether_type;//以太网类型
   
};
typedef u_int32_t in_addr_t;
/*struct in_addr
{
   in_addr_t s_addr;
};*/
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




//下面是实现捕获和分析TCP数据包的函数定义
void udp_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr *packet_header,const u_char *packet_content)
{
   struct udp_header *udp_protocol;//UDP协议变量
   u_short source_port;//源端口号
   u_short destination_port;//目的端口号
   u_short length;//长度
   udp_protocol=(struct udp_header *)(packet_content+14+20);//获得IP协议数据内容，去掉以太网头和IP头部分
   source_port=ntohs(udp_protocol->udp_source_port);//获得源端口号
   destination_port=ntohs(udp_protocol->udp_destination_port);//获得目的端口号
   length=ntohs(udp_protocol->udp_length);//长度   
   printf("---------------------UDP Procotol (Transport Layer)--------------------\n");
   printf("Source Port:%d\n",source_port);//输出源端口号
   printf("Destination Port:%d\n",destination_port);//输出源端口号
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
void ip_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr *packet_header,const u_char *packet_content)
{
   struct ip_header *ip_protocol;//ip协议变量
   u_int header_length;//长度
   u_int offset;//偏移
   u_char tos;//服务质量
   u_int16_t checksum;//校验和
   ip_protocol=(struct ip_header *)(packet_content+14);
//获得IP协议数据内容，去掉以太网头
   checksum=ntohs(ip_protocol->ip_checksum);//获得校验和
   header_length=ip_protocol->ip_header_length*4;//获得长度
   tos=ip_protocol->ip_tos;//获得tos
   offset=ntohs(ip_protocol->ip_off);//获得偏移量
   printf("---------------------IP Procotol (Network Layer)--------------------\n");
   printf("Header length:%d\n",header_length);
   printf("TOS:%d\n",tos);
   printf("Total length:%d\n",ntohs(ip_protocol->ip_length));//获得总长度
   printf("Identification:%d\n",ntohs(ip_protocol->ip_id));//获得标识
   printf("Offset:%d\n",(offset&0x1fff)*8);
   printf("TTL:%d\n",ip_protocol->ip_ttl);//获得TTL
   printf("Protocol:%d\n",ip_protocol->ip_protocol);//获得协议类型
   switch(ip_protocol->ip_protocol)  //判断协议类型的值
    {  
        case 6:printf("The Transport Layer Protocol is TCP\n");break;//如果协议类型为6,表示上层协议为TCP协议  
        case 17:printf("The Transport Layer Protocol is UDP\n");
                udp_protocol_packet_callback(argument,packet_header,packet_content);
                break;//如果协议类型为17,表示上层协议为UDP协议
        
        case 1:printf("The Transport Layer Protocol is ICMP\n");break;//如果协议类型为1,表示上层协议为ICMP协议 
        default:printf("Unknow Protocol!");break;
    }  
    printf("Header checksum:%d\n",checksum);
    printf("Source address is:%s\n",inet_ntoa(ip_protocol->ip_source_address));//获得源IP地址
    printf("Destination address is:%s\n",inet_ntoa(ip_protocol->ip_destination_address));//获得目的IP地址  
 };
 
//实现IP数据包分析的函数定义
void ip_protocol_packet_callback(const u_char *packet_content)
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
   printf("---------------------IP Procotol (Network Layer)--------------------\n");
   printf("IP版本%d\n",ip_protocol->version);
   printf("Header length:%d\n",header_length);
   printf("TOS:%d\n",tos);
   printf("Total length:%d\n",ntohs(ip_protocol->ip_length));//获得总长度
   printf("Identification:%d\n",ntohs(ip_protocol->ip_id));//获得标识
   printf("Offset:%d\n",(offset&0x1fff)*8);
   printf("TTL:%d\n",ip_protocol->ip_ttl);//获得TTL
   printf("Protocol:%d\n",ip_protocol->ip_protocol);//获得协议类型
   switch(ip_protocol->ip_protocol)  //判断协议类型的值
    {  
        case 6:printf("The Transport Layer Protocol is TCP\n");break;//如果协议类型为6,表示上层协议为TCP协议  
        case 17:printf("The Transport Layer Protocol is UDP\n");
                break;//如果协议类型为17,表示上层协议为UDP协议
        
        case 1:printf("The Transport Layer Protocol is ICMP\n");break;//如果协议类型为1,表示上层协议为ICMP协议 
        default:printf("Unknow Protocol!");break;
    }  
    printf("Header checksum:%d\n",checksum);
    printf("Source address is:%s\n",inet_ntoa(ip_protocol->ip_source_address));//获得源IP地址
    printf("Destination address is:%s\n",inet_ntoa(ip_protocol->ip_destination_address));//获得目的IP地址  
    switch(ip_protocol->ip_protocol)  //判断协议类型的值
    {  
        case 6:tcp_protocol_packet_callback(packet_content);
        break;//上层协议为TCP协议  
        case 17:udp_protocol_packet_callback(packet_content);
                break;//表示上层协议为UDP协议        
        case 1:icmp_protocol_packet_callback(packet_content);
        break;//如果协议类型为1,表示上层协议为ICMP协议 
        default:printf("Unknow Protocol!");break;
    } 
 };
