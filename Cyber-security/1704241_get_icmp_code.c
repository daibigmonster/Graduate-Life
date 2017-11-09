/*ICMP协议是基于IP协议的，在IP报文中传输，所以必须对IP协议进行分析，然后再分析ICMP协议。而IP协议是在以太网帧中传输的，所以又应该分析以太网协议*/
#include <pcap.h>
#include <stdio.h>
#include<stdlib.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>
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

struct icmp_header//IP协议格式
{
   u_int8_t icmp_type;//ICMP类型
   u_int8_t icmp_code;//ICMP代码
   u_int16_t icmp_checksum;//校验和
   u_int16_t icmp_id_dai; //标识符
   u_int16_t icmp_sequence;//序列号   
};







//下面是实现捕获和分析ICMP数据包的函数定义
void icmp_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr *packet_header,const u_char *packet_content)
{
   struct icmp_header *icmp_protocol;//UDP协议变量
   icmp_protocol=(struct icmp_header *)(packet_content+14+20);//获得ICMP协议数据内容，去掉以太网头和IP头部分 
   printf("---------------------ICMP Procotol (Transport Layer)--------------------\n");
   printf("ICMP Type:%d\n",icmp_protocol->icmp_type);//获得ICMP类型
   switch(icmp_protocol->icmp_type)  //判断上层协议类型
    {  
        case 8:printf("ICMP Echo Request Protocol\n");
        printf("ICMP Code:%d\n",icmp_protocol->icmp_code);//获得ICMP代码
        printf("Identifier:%d\n",icmp_protocol->icmp_id_dai);//获得标识符
        printf("Sequence Number:%d\n",icmp_protocol->icmp_sequence);//获得序列号
        break;
        case 0:printf("NBTBIOS Name Service\n");
        printf("ICMP Echo Reply Protocol\n");
        printf("ICMP Code:%d\n",icmp_protocol->icmp_code);//获得ICMP代码
        printf("Identifier:%d\n",icmp_protocol->icmp_id_dai);//获得标识符
        printf("Sequence Number:%d\n",icmp_protocol->icmp_sequence);//获得序列号
        break;//类型为0,表示是回显应答报文
        default:printf("Unknow Protocol!\n");break;
     } 
   printf("ICMP Checksum:%u\n",ntohs(icmp_protocol->icmp_checksum));//获得校验和
     
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
             //   udp_protocol_packet_callback(argument,packet_header,packet_content);
                break;//如果协议类型为17,表示上层协议为UDP协议
        
        case 1:printf("The Transport Layer Protocol is ICMP\n");
        icmp_protocol_packet_callback(argument,packet_header,packet_content);
        break;//如果协议类型为1,表示上层协议为ICMP协议 
        default:printf("Unknow Protocol!");break;
    }  
    printf("Header checksum:%d\n",checksum);
    printf("Source address is:%s\n",inet_ntoa(ip_protocol->ip_source_address));//获得源IP地址
    printf("Destination address is:%s\n",inet_ntoa(ip_protocol->ip_destination_address));//获得目的IP地址  
 };
 
 
 
 

//以下回调函数，实现对以太网的协议分析
void ethernet_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr *packet_header,const u_char *packet_content)
{
   u_short ethernet_type;//以太网类型
   struct ether_header *ethernet_protocol;//以太网协议变量    
   u_char *mac_string;//以太网地址
   static int packet_number=1;
   printf("---------------------*****--------------------\n");
   printf("The %d IP packet is captured.\n",packet_number);
   printf("---------------------Ethernet Protocol (Link Layer)--------------------\n");
   printf("Capture Time is:\n");
   printf("%s",ctime((const time_t*)&packet_header->ts.tv_sec));//输出数据包的时间信息
   printf("Packet Length is:\n");
   printf("%d\n",packet_header->len);//输出此数据包的长度信息
   ethernet_protocol=(struct ether_header *)packet_content;
   /*把此数据包缓存进行类型的强制转换，使它变成以太网协议格式的数据类型，然后就可以对它的各个字段进行访问。注意此处的强制转换功能，是对网络数据包进行分析的重点操作*/
   printf("Ethernet type is :\n");
   ethernet_type=ntohs(ethernet_protocol->ether_type);
   //获得以太网的类型，它表示上层协议的类型，即网络层的协议类型
   //ntohs()是一个函数名，作用是将一个16位数由网络字节顺序转换为主机字节顺序
   printf("%04x\n",ethernet_type);//输出以太网类型
   switch(ethernet_type)  
    {  
        case 0x0800:printf("The network layer is IP protocol\n");break;//如果以太网类型是0x0800就表示上层协议类型为ip协议  
        case 0x0806:printf("The network layer is ARP protocol\n");break;//如果以太网类型是0x0806就表示上层协议类型为arp协议  
        case 0x0835:printf("The network layer is RARP protocol\n");break;//如果以太网类型是0x0835就表示上层协议类型为rarp协议  
        default:printf("The network layer unknow!\n");break;  
    }  
   printf("Mac Source Adress is :\n");
   mac_string=ethernet_protocol->ether_shost;//获得源以太网地址
       printf("%02x:%02x:%02x:%02x:%02x:%02x\n",*mac_string,*(mac_string+1),*(mac_string+2),*(mac_string+3),*(mac_string+4),*(mac_string+5));
       //要对以太网地址进行转换，使它变成字符串形式进行显示，如：11：11：11：11：11：11.因为读到的源以太网地址是字节流顺序的
   printf("Mac Destination Adress is :\n");
   mac_string=ethernet_protocol->ether_dhost;//获得源以太网地址
       printf("%02x:%02x:%02x:%02x:%02x:%02x\n",*mac_string,*(mac_string+1),*(mac_string+2),*(mac_string+3),*(mac_string+4),*(mac_string+5));
   //获得目的以太网地址
   switch(ethernet_type)
   {
      case 0x0800:ip_protocol_packet_callback(argument,packet_header,packet_content);
      break;
      default:break;
   }
   //如果上层协议是IP协议，就调用分析IP协议的函数对IP协议进行分析。注意，此时传递的参数，与回调函数的参数是一样的，表示代表用一个数据包
   printf("--------------------*****--------------------\n");
   packet_number++;
 }
int main()
{
  char error_content[PCAP_ERRBUF_SIZE];
  pcap_t *pcap_handle;//pcap_t类型指针
  char *net_interface;//用来存储网络接口
  struct bpf_program bpf_filter;//bpf过滤规则
  char bpf_filter_string[]="icmp";
  bpf_u_int32 net_mask;//网络掩码
  bpf_u_int32 net_ip;//网络地址
  /*过滤规则，此处表示只捕获IP数据包，当然它也是以太网数据包，因为本程序的环境为以太网环境。IP数据包都是基于以太网协议的，所以捕获IP数据包，就相当与捕获以太网数据包，此处只是为了能捕获到以太网数据包，别无他意，当然，还可以使用其他过滤规则，只要能捕获到以太网协议就行，因为本程序的目的就是为了捕获到以太网数据包*/
  net_interface=pcap_lookupdev(error_content);//获取网络接口
  pcap_lookupnet(net_interface,&net_ip,&net_mask,error_content);//获取网络接口，地址和掩码
  pcap_handle=pcap_open_live(net_interface,BUFSIZ,1,0,error_content);//打开网络接口，返回pcap_t型指针
  if(pcap_handle==NULL)
  {
     printf("%s",error_content);
     exit(-1);
  }
  pcap_compile(pcap_handle,&bpf_filter,bpf_filter_string,0,net_ip);//编译过滤规则
  pcap_setfilter(pcap_handle,&bpf_filter);//设置过滤规则
  if(pcap_datalink(pcap_handle)!=DLT_EN10MB) return 0;
//获取3个网络数据包，调用callback函数，每捕获一个数据包就调用该函数进行操作
   pcap_loop(pcap_handle,2,ethernet_protocol_packet_callback,NULL);
   pcap_close(pcap_handle);
   return 0;
 }
