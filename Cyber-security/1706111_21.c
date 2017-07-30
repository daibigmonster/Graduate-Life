#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
using namespace std;
void call_back(u_char *user,const struct pcap_pkthdr *h,const u_char *sp){
    static int num=0;
    cout<<"数据包："<<num++<<endl;
    cout<<"包长："<<h->caplen<<endl;
    cout<<"所抓包长："<<h->len<<endl;
    }
int main()
{
    char err[PCAP_ERRBUF_SIZE];
    char *dev=pcap_lookupdev(err);
    if(dev==NULL)
    {
        cout<<"网络错误："<<err;
        return 0;
     }
     cout<<"网络端口："<<dev<<endl;
     bpf_u_int32 ip,mask;
     pcap_lookupnet(dev,&ip,&mask,err);
     struct in_addr a,b;
     a.s_addr=ip;
     b.s_addr=mask;
     cout<<"源网络地址："<<inet_ntoa(a)<<endl;
     cout<<"网络掩码："<<inet_ntoa(b)<<endl;
     pcap_t *dev_hdle=pcap_open_live(dev,BUFSIZ,1,0,err);
     bpf_program bpf_filter;
     char ip_filter[]="ip";
     pcap_compile(dev_hdle,&bpf_filter,ip_filter,0,ip);
     pcap_setfilter(dev_hdle,&bpf_filter);
     pcap_loop(dev_hdle,4,call_back,NULL);
     pcap_close(dev_hdle);
     return 0;
}
