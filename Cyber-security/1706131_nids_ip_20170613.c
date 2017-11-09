#include<iostream>
#include<nids.h>
#include<pcap.h>
#include<arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>
#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include<unistd.h>
struct ip_header
{
    #ifdef WORD_BIGENDIAN
    u_int8_t ip_ver:4;
    short int ip_h_len:4;
    #else 
    short int ip_h_len:4;
    u_int8_t ip_ver:4;
    #endif
    u_int8_t ip_tos:4;
    u_int16_t ip_len;
    u_int16_t ip_id,ip_off;
    u_int8_t ip_ttl,ip_pro;
    u_int16_t ip_check;
    struct in_addr ip_saddr;
    struct in_addr ip_daddr;
};

typedef struct
{
    u_int16_t sport;
    u_int16_t dport;
    u_int32_t tcp_ackn;
    u_int32_t tcp_ack;
    u_int16_t other;
    u_int16_t win;
    u_int16_t chesksun;
    u_int16_t urgptr;
    u_int32_t option;
}tcp_header;
typedef struct
{
    u_int16_t sport;
    u_int16_t dport;
    u_int16_t len;
    u_int16_t checksum;
}udp_header;
using namespace std;
static int number=0;
void ip_callback(struct ip * content)
{
    cout<<"IP "<<number++<<" captured:"<<endl;
    struct ip iplen=*content;
    struct ip iplen1=*(content+1);
    cout<<&iplen1<<"    "<<&iplen<<endl;
    struct ip_header *iph,*iph1;
    iph=(ip_header *)content;
    iph1=(ip_header *)(content+1);
    cout<<&*(iph)<<"    "<<&*(iph1)<<endl;
    cout<<"源地址："<<inet_ntoa(iph->ip_saddr)<<inet_ntoa(content->ip_src)<<endl;
    cout<<"目的地址："<<inet_ntoa(iph->ip_daddr)<<endl;
    cout<<"版本号"<<ntohs(content->ip_v)<<endl;
    switch(content->ip_p)
    {
        case 6:
            cout<<"TCP123124145234344"<<endl;
            
            break;
        case 17:
            cout<<"UDP"<<endl;
            udp_header *uh;
            udp_header *uh1;
            uh=(udp_header*)(content + 1);
            uh1=(udp_header*)content;
            cout<<&*(content)<<"\t"<<&*(content+1)<<endl;
            cout<<&*(uh1)<<"\t"<<&*(uh)<<endl;
           // cout<<sizeof()
            cout<< "源端口："<<ntohs(uh->sport) << endl;
            cout<< "目的端口："<<ntohs(uh->dport) << endl;
            cout<<"包长："<<ntohs(uh->len)<<endl;
            cout<< "目的端口："<<ntohs(uh1->dport) << endl;
            break;
            
        default:
            cout<<"Others"<<endl;
            break;
        }}
void tcp_callback(struct tcp_stream *a_tcp,void **argv)
{
     cout<<"TCPcallback captured!"<<endl;
}
void udp_callback(struct tuple4 * addr,char *buf,int len,struct ip * iph)
{
    cout<<"UDPcallback captured!"<<endl;
    cout<<inet_ntoa(*((struct in_addr *)&(addr->saddr)))<<endl;
}
int main()
{
   // struct nids_chksum_ctl temp;
   // temp.netaddr = 0;
   // temp.mask = 0;
   // temp.action = 1;
   // nids_register_chksum_ctl(&temp,1);
    nids_init();
    nids_register_ip((void*)ip_callback);
    nids_run();
    return 0;
    }
