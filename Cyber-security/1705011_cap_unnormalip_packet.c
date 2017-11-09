#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <nids.h>
#include <libnet.h>
struct udp_header//UDP协议格式的定义
{
   u_int16_t udp_source_port;//源端口    
   u_int16_t udp_destination_port;//目的端口
   u_int16_t udp_length;//长度
   u_int16_t udp_checksum;//校验和
};
struct icmp_header//ICMP协议格式
{
   u_int8_t icmp_type;//ICMP类型
   u_int8_t icmp_code;//ICMP代码
   u_int16_t icmp_checksum;//校验和
   u_int16_t icmp_id_dai; //标识符
   u_int16_t icmp_sequence;//序列号   
};
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
struct tcp_header//TCP协议格式的定义
{
   u_int16_t tcp_source_port;//源端口    
   u_int16_t tcp_destination_port;//目的端口
   u_int32_t tcp_acknowledgement;//序列号
   u_int32_t tcp_ack;//确认号
   #ifdef WORDS_BIGENDIAN
   u_int8_t tcp_offset:4,
            tcp_reserved:4;//偏移
   #else
   u_int8_t tcp_reserved:4,
            tcp_offset:4;//偏移
   #endif
   u_int8_t tcp_flags;//标志int main()
{
    if(!nids_init())
        {
            printf("出现错误：%s\n",nids_errbuf);
        }
        nids_dispatch(3);
        nids_register_ip_frag(ip_callback);
        nids_run();//它实际上是调用Libpcap函数pcap_loop()来循环捕获数据包
	return 0; 
}
   u_int16_t tcp_windows;//窗口大小
   u_int16_t tcp_checksum;//校验和
   u_int16_t tcp_urgent_pointer;//紧急指针
   
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
//下面是实现捕获和分析ICMP数据包的函数定义
void icmp_protocol_packet_callback(const u_char *packet_content)
{
   struct icmp_header *icmp_protocol;//UDP协议变量
   icmp_protocol=(struct icmp_header *)(packet_content+14+20);//获得ICMP协议数据内容，去掉以太网头和IP头部分 
   printf("---------------------ICMP协议--------------------\n");
   printf("ICMP Type:%d\n",icmp_protocol->icmp_type);//获得ICMP类型
   switch(icmp_protocol->icmp_type)  //判断上层协议类型
    {  
        case 8:printf("ICMP回显请求协议\n");
        printf("ICMP代码:%d\n",icmp_protocol->icmp_code);//获得ICMP代码
        printf("标识符:%d\n",icmp_protocol->icmp_id_dai);//获得标识符
        printf("序列码:%d\n",icmp_protocol->icmp_sequence);//获得序列号
        break;
        case 0:printf("ICMP回显应答协议e\n");
        printf("ICMP代码:%d\n",icmp_protocol->icmp_code);//获得ICMP代码
        printf("标识符:%d\n",icmp_protocol->icmp_id_dai);//获得标识符
        printf("序列码:%d\n",icmp_protocol->icmp_sequence);//获得序列号
        break;//类型为0,表示是回显应答报文
        default:printf("Unknow Protocol!\n");break;
     } 
   printf("ICMP校验和:%u\n",ntohs(icmp_protocol->icmp_checksum));//获得校验和
     
}  
void tcp_protocol_packet_callback(const u_char *packet_content)
{
   struct tcp_header *tcp_protocol;//TCP协议变量
   u_char flags;//标记
   int header_length;//首部长度
   u_short source_port;//源端口号
   u_short destination_port;//目的端口号
   u_short windows;//窗口大小
   u_short urgent_pointer;//紧急指针
   u_int sequence;//序列号
   u_int acknowledgement;//确认号
   u_int16_t checksum;//校验和
   tcp_protocol=(struct tcp_header *)(packet_content+14+20);//获得IP协议数据内容，去掉以太网头和IP头部分
   source_port=ntohs(tcp_protocol->tcp_source_port);//获得源端口号
   destination_port=ntohs(tcp_protocol->tcp_destination_port);//获得目的端口号
   header_length=tcp_protocol->tcp_offset*4;//获得首部长度
   sequence=ntohl(tcp_protocol->tcp_acknowledgement);//获得序列号
   //ntohl()是将一个无符号长整形数从网络字节顺序转换为主机字节顺序
   //ntohs()是将一个无符号短整形数从网络字节顺序转换为主机字节顺序
   acknowledgement=ntohs(tcp_protocol->tcp_ack);//获得确认号
   windows=ntohs(tcp_protocol->tcp_windows);//获得窗口大小
   urgent_pointer=ntohs(tcp_protocol->tcp_urgent_pointer);//获得紧急指针
   flags=tcp_protocol->tcp_flags;//获得标记
   checksum=ntohs(tcp_protocol->tcp_checksum);//获得校验和
   printf("---------------------TCP Procotol (Transport Layer)--------------------\n");
   printf("Source Port:%d\n",source_port);//输出源端口号
   printf("Destination Port:%d\n",destination_port);//输出源端口号
   switch(destination_port)  //判断上层协议类型
    {  
        case 80:printf("HTTP Protocol\n");break;//端口是80,表示上层协议是HTTP协议  
        case 21:printf("FTP Protocol\n");break;//端口是21,表示上层协议是FTP协议
        case 23:printf("TELNET Protocol\n");break;//端口是23,表示上层协议是Telnet协议
        case 25:printf("SMTP Protocol\n");break;//端口是23,表示上层协议是SMTP协议
        case 110:printf("POP3 Protocol\n");break;//端口是23,表示上层协议是POP3协议
        default:printf("Unknow Protocol!");break;
   printf("Sequence Number:%u\n",sequence);//输出序列号
   printf("Acknowledge Number:%u\n",acknowledgement);//输出确认号
   printf("Header Length:%d\n",header_length);//输出首部长度
   printf("Reserved:%u\n",tcp_protocol->tcp_reserved);
   printf("Flags:");//输出标记
   if (flags&0x08)printf("PSH");
   if (flags&0x10)printf("ACK");
   if (flags&0x02)printf("SYN");
   if (flags&0x20)printf("URG");
   if (flags&0x01)printf("FIN");
   if (flags&0x04)printf("RST");
      printf("\n");
      printf("Windows Size:%d",windows);//输出窗口的大小
      printf("Checksum:%d",checksum);//输出校验和
      printf("Urgent pointer:%d\n",urgent_pointer);//输出紧急指针
    }  
}     
//下面是实现捕获和分析TCP数据包的函数定义
void udp_protocol_packet_callback(const u_char *packet_content)
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
        case 17:printf("The Transport Layer Protocol is UDP\n");break;//如果协议类型为17,表示上层协议为UDP协议
        case 1:printf("The Transport Layer Protocol is ICMP\n");break;//如果协议类型为1,表示上层协议为ICMP协议 
        default:printf("Unknow Protocol!");break;
    }  
    printf("Header checksum:%d\n",checksum);
    printf("Source address is:%s\n",inet_ntoa(ip_protocol->ip_source_address));//获得源IP地址
    printf("Destination address is:%s\n",inet_ntoa(ip_protocol->ip_destination_address));//获得目的IP地址  
 }
 
void ip_callback(struct ip* a_packet,int len)
{
    void ip_protocol_packet_callback(struct ip* a_packet);
}
s
