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
    u_int32_t ackn;
    u_int32_t ack;
    u_int16_t other;
    u_int16_t winsize;
    u_int16_t checksum;
    u_int16_t urg_ptr;
    u_int16_t option;
}tcp_header;
typedef struct
{
    u_int16_t sport;
    u_int16_t dport;
    u_int16_t len;
    u_len16_t checksum;
}udp_header;
void ip_callback(struct ip * a_packet, int len)
{

    cout << dec << p_number++ << endl;
    switch (a_packet->ip_p)
    {
        case 6:
                       cout << "TCP\t";
            tcp_header* th;
            th = (tcp_header*) (a_packet + 1);
            cout << inet_ntoa(a_packet->ip_src) << ":";
            cout<<ntohs(th->sport) << " --> ";
            cout << inet_ntoa(a_packet->ip_dst) << ":";
            cout << ntohs(th->dport) << endl;

            break;
        case 17:
            cout << "UDP\t";
            udp_header* uh;
            uh = (udp_header*) (a_packet + 1);
            cout << inet_ntoa(a_packet->ip_src) << ":" ;
            cout<< ntohs(uh->sport) << " --> ";
            cout<< inet_ntoa(a_packet->ip_dst) << ":";
            cout<< ntohs(uh->dport) << endl;
            break;
        default:
            break;
    }
}
void tcp_callback(struct tcp_stream *a_tcp, void ** this_time_not_needed)
{
    cout << "tcp" << endl;

}
void udp_callback(u_char* content)
{
    cout << "udp" << endl;
}
int main()
{
    if(!nid_init())
    {
        cout<<"初始化失败！"<<endl;
    }
    nids_register_ip_frag((void*)ip_callback);
    nids_run();
    cerr<<"end"<<endl;
    return 0;
}
