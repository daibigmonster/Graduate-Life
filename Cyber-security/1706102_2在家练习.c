#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
using namespace std;
void call_back(u_char *user,const struct pcap_pkthdr *h,const u_char *sp)
{
   static int number=0;
   cout<<"数据包："<<number++<<endl;
   cout<<"包长："<<h->caplen<<"所抓包长："<<h->len<<endl;
   }
int main(){
   char err[PCAP_ERRBUF_SIZE];
   char *inet_interface=pcap_lookupdev(err);
   if(inet_interface==NULL){
      cout<<err<<endl;
      return 0;
   }
   cout<<inet_interface<<endl;
   bpf_u_int32 ip,maskip;
   struct in_addr ip_addr,mask_addr;
   pcap_lookupnet(inet_interface,&ip,&maskip,err);
   ip_addr.s_addr=ip;
   mask_addr.s_addr=maskip;
   cout<<"网络地址："<<inet_ntoa(ip_addr)<<endl;
   cout<<"网络掩码："<<inet_ntoa(mask_addr)<<endl;
   pcap_t * device_handle=pcap_open_live(inet_interface,BUFSIZ,1,0,err);
   bpf_program bpf_filter;
   char ip_filter[]="ip";
   pcap_compile(device_handle,&bpf_filter,ip_filter,0,ip);
   pcap_setfilter(device_handle,&bpf_filter);
   pcap_loop(device_handle,4,call_back,NULL);
   pcap_close(device_handle);
   return 0;
   }
   
