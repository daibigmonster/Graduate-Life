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
typedef struct
{
   u_short sport;
   u_short dport;
   u_int32_t tcp_acknow;
   u_int32_t tcp_ack;
   u_int16_t other;
   u_int16_t win;
   u_int16_t checksum;
   u_int16_t urg_ptr;
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
void ip_callback(struct ip * a_packet)
{
    cout<<number++<<endl;
    switch(a_packet->ip_p){
        case 6:
            cout<<"TCP数据包："<<endl;
            tcp_header* th;
            th=(tcp_header*)(a_packet+20);
            cout<<"源地址："<<inet_ntoa(a_packet->ip_src)<<":"<<ntohs(th->sport)<<endl;
            cout<<"目的地址："<<inet_ntoa(a_packet->ip_dst)<<":"<<ntohs(th->dport)<<endl;
            break;
        case 17:
            cout<<"UDP数据包："<<endl;
            udp_header* uh;
            uh=(udp_header*)(a_packet+20);
            cout<<"源地址："<<inet_ntoa(a_packet->ip_src)<<":"<<ntohs(uh->sport)<<endl;
            cout<<"目的地址："<<inet_ntoa(a_packet->ip_dst)<<":"<<ntohs(uh->dport)<<endl;
            break;
        default:
            break;
    }
}
int main()
{
   nids_params.device ="enp2s0";
   if(!nids_init()){
      cout<<"初始化失败！"<<endl;
   }
   nids_register_ip((void *)ip_callback);
   nids_run();
   cerr<<"end"<<endl;
   return 0;
}
