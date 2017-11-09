#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
using namespace std;
void call_back(u_char *user,const struct pcap_pkthdr *h,const u_char *sp)
{
   static int number=0;
   cout<<"数据包\t"<<number++<<":"<<endl;
   cout<<"包长："<<h->caplen<<"\t所抓包长："<<h->len<<endl;
}
int main(){
   char err[PCAP_ERRBUF_SIZE];
   char *net_interface=pcap_lookupdev(err);
   if(net_interface==NULL)
   {
       cout<<"网络错误:"<<err;
       return 0;
   }
   cout<<"网络接口号是："<<net_interface<<endl;
   bpf_u_int32 ip,netmask;
   struct in_addr a,b;
   pcap_lookupnet(net_interface,&ip,&netmask,err);
   a.s_addr=ip;
   b.s_addr=netmask;
   cout<<"网络地址："<<inet_ntoa(a)<<endl;
   cout<<"网络掩码："<<inet_ntoa(b)<<endl;
   pcap_t * device_handle=pcap_open_live(net_interface,BUFSIZ,1,0,err);
   bpf_program bpf_filter;
   char ip_filter[]="ip";
   pcap_compile(device_handle,&bpf_filter,ip_filter,0,ip);
   pcap_setfilter(device_handle,&bpf_filter);
   pcap_loop(device_handle,4,call_back,NULL);
   pcap_close(device_handle);
   return 0;
   }
