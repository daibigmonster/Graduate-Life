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
//static int number=0;
/*void ip_callback(struct ip * content)
{
    cout<<"IP "<<number++<<" captured:";
    switch(content->ip_p)
    {
        case 6:
            cout<<"TCP123124145234344"<<endl;
            break;
        case 17:
            cout<<"UDP"<<endl;
            break;
        default:
            cout<<"Others"<<endl;
            break;
        }}*/
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
    struct nids_chksum_ctl temp;
    temp.netaddr = 0;
    temp.mask = 0;
    temp.action = 1;
    nids_register_chksum_ctl(&temp,1);
    nids_init();
    //nids_register_ip((void*)ip_callback);
    nids_register_tcp((void*)tcp_callback);
    nids_register_udp((void*)udp_callback);
    nids_run();
    return 0;
    }
