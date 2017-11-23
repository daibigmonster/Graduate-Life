#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
using namespace std;
void call_back(u_char * user,const struct pcap_pkthdr *h,const u_char *sp)
{
    static int num=1;
    cout<<"数据包："<<num++<<endl;
<<<<<<< HEAD
    cout << "包长:" << h->caplen << "\t所抓包长:" << h->len << endl;
    cout<<"源地址:"<<inet_ntoa(ip_packet->saddr)<<endl;
    cout<<"目的地址:"<<inet_ntoa(ip_packet->daddr)<<endl;
=======
>>>>>>> d8df3be00c7fa3e8aeb2ea4adcc7d5d5126a257c
}
int main(){
    char err[PCAP_ERRBUF_SIZE];
    char *dev=pcap_lookupdev(err);
    cout<<"网络接口为："<<dev<<endl;
    bpf_u_int32 ip,mask;
    pcap_lookupnet(dev,&ip,&mask,err);
    struct in_addr a,b;
    a.s_addr=ip;
    b.s_addr=mask;
  //  cout<<ip<<mask<<endl;
<<<<<<< HEAD
    cout<<"网址:"<<inet_ntoa(a)<<endl;
    cout<<"掩码："<<inet_ntoa(b)<<endl;
=======
    cout<<inet_ntoa(a)<<endl;
    cout<<inet_ntoa(b)<<endl;
    /*pcap_t *dev_hdle=pcap_open_live(dev,BUFSIZ,1,0,err);
     bpf_program bpf_filter;
     char ip_filter[]="ip";
     pcap_compile(dev_hdle,&bpf_filter,ip_filter,0,ip);
     pcap_setfilter(dev_hdle,&bpf_filter);
     pcap_loop(dev_hdle,4,call_back,NULL);
     pcap_close(dev_hdle);*/
    
>>>>>>> d8df3be00c7fa3e8aeb2ea4adcc7d5d5126a257c
    pcap_t * dh=pcap_open_live(dev,BUFSIZ,1,0,err);
    bpf_program bpf_filter;
    char ip_filter[]="ip";
    pcap_compile(dh,&bpf_filter,ip_filter,0,ip);
    pcap_setfilter(dh,&bpf_filter);
    pcap_loop(dh,4,call_back,NULL);
    pcap_close(dh);
    return 0;
}
