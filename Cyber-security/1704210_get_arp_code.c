/*由于ARP是基于以太网协议的，所以必须先分析出以太网协议。然后根据以太网协议类型的值来判断上层协议是否是ARP协议。如果是，就分析ARP协议，如果不是，就跳过*/
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
struct arp_header//ARP协议格式
{
   u_int16_t arp_hardware_type;//硬件地址类型
   u_int16_t arp_protocol_type;//协议地址类型
   u_int8_t arp_hardware_length;//硬件地址长度
   u_int8_t arp_protocol_length;//协议地址长度
   u_int16_t arp_operation_code;//操作类型
   u_int8_t arp_source_ethernet_address[6];//源以太网地址
   u_int8_t arp_source_ip_address[4];//源IP地址
   u_int8_t arp_destination_ethernet_address[6];//目的以太网地址
   u_int8_t arp_destination_ip_address[4];//目的IP地址
};





//实现ARP协议分析的函数定义
void arp_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr *packet_header,const u_char *packet_content)
{
   struct arp_header *arp_protocol;//arp协议变量
   u_short protocol_type;//协议类型
   u_short hardware_type;//硬件类型
   u_short operation_code;//操作类型
   u_char *mac_string;//以太网地址
   struct in_addr source_ip_address;//源IP地址
   struct in_addr destination_ip_address;//目的IP地址
   u_char hardware_length;//硬件地址长度
   u_char protocol_length;//协议地址长度
   printf("---------------------ARP Procotol (Network Layer)--------------------\n");
   arp_protocol=(struct arp_header *)(packet_content+14);
//获得ARP协议数据。注意要跳过以太网数据部分，它的长度刚好是14,所以要在这里加上14,使指针跳过14字节
   hardware_type=ntohs(arp_protocol->arp_hardware_type);//获得硬件类型
   protocol_type=ntohs(arp_protocol->arp_protocol_type);//获得协议类型
   operation_code=ntohs(arp_protocol->arp_operation_code);//获得操作码
   hardware_length=arp_protocol->arp_hardware_length;//获得硬件地址长度
   protocol_length=arp_protocol->arp_protocol_length;//获得协议地址长度y函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
   printf("ARP Hardware Type:%d\n",hardware_type);
   printf("ARP Protocol Type:%d\n",protocol_type);
   switch(operation_code)  
    {  
        case 1:printf("ARP Request Protocol\n");break;//ARP查询协议  
        case 2:printf("ARP Reply Protocol\n");break;//ARP应答协议
        case 3:printf("RARP Request Protocol\n");break;//RARP查询协议  
        case 4:printf("RARP Reply Protocol\n");break;//RARP应答协议
        default:printf("Unknow Protocol!");break;
    }  
   printf("Ethernet Source Adress is :\n");
   mac_string=arp_protocol->arp_source_ethernet_address;//获得源以太网地址
   printf("%02x:%02x:%02x:%02x:%02x:%02x\n",*mac_string,*(mac_string+1),*(mac_string+2),*(mac_string+3),*(mac_string+4),*(mac_string+5));
 //要对以太网地址进行转换，使它变成字符串形式进行显示，如：11：11：11：11：11：11.因为读到的源以太网地址是字节流顺序的
   memcpy((void*) &source_ip_address,(void*) &arp_protocol->arp_source_ip_address,sizeof(struct in_addr));
   printf("Source IP Address:%s\n",inet_ntoa(source_ip_address));
//获得源IP地址   
   printf("Ethernet Destination Address is : \n");
   mac_string=arp_protocol->arp_destination_ethernet_address;//获得目的以太网地址
   printf("%02x:%02x:%02x:%02x:%02x:%02x\n",*mac_string,*(mac_string+1),*(mac_string+2),*(mac_string+3),*(mac_string+4),*(mac_string+5));
       //同样对其地址进行转换
   memcpy((void*) &destination_ip_address,(void*) &arp_protocol->arp_destination_ip_address,sizeof(struct in_addr));
   printf("Destination IP Address:%s\n",inet_ntoa(destination_ip_address));
//获得目的IP地址   
 }
 
 
 
 

//以下回调函数，实现对以太网的协议分析
void ethernet_protocol_packet_callback(u_char *argument,const struct pcap_pkthdr *packet_header,const u_char *packet_content)
{
   u_char *mac_string;//以太网地址
   u_short ethernet_type;//以太网类型
   struct ether_header *ethernet_protocol;//以太网协议变量
   static int packet_number=1;
   printf("---------------------*****--------------------\n");
   printf("The %d ARP packet is captured.\n",packet_number);
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
      case 0x0806:arp_protocol_packet_callback(argument,packet_header,packet_content);
      break;
   }
   //如果以太网类型是0x0806,表示上层协议是ARP协议，应该调用分析ARP协议的函数。注意此时的参数传递，全部是回调函数的参数，它代表的是同一个网络数据包，所以在这里，既分析此数据包的以太网协议部分，又分析此数据包的ARP协议部分
   printf("--------------------*****--------------------\n");
   packet_number++;
 }
int main()
{
  char error_content[PCAP_ERRBUF_SIZE];
  pcap_t *pcap_handle;//pcap_t类型指针
  char *net_interface;//用来存储网络接口
  struct bpf_program bpf_filter;//bpf过滤规则
  char bpf_filter_string[]="arp";
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
