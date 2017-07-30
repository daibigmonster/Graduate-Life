#include<iostream>
#include<stdio.h>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
#include<iomanip>
using namespace std;
typedef struct t_header
{
    u_int8_t src[6];
    u_int8_t dst[6];
    u_int16_t ether_type;
} ether_header;
typedef struct
{
    int header_len :4;
    int version :4;
    u_char tos :8; //服务质量
    int total_len :16;
    int ident :16;
    int flags :16;
    u_char ttl :8;
    u_char proto :8;
    int checksum :16;
    u_char sourceIP[4];
    u_char destIP[4];
} ip_header;
typedef struct
{
    u_short sport;
    u_short dport;
    u_int32_t sn;
    u_int32_t an;
    u_int16_t other;
    u_int16_t win_size;
    u_int16_t checksum;
    u_int16_t urg_ptr;
    u_int32_t option;
} tcp_header;
typedef struct
{
    u_int16_t sport;
    u_int16_t dport;
    u_int16_t total_len;
    u_int16_t checksum;
} udp_header;
void call_back(u_char *user, const struct pcap_pkthdr *ph, const u_char *sp)
{
    static int pnumber = 0;
    struct t_header* packet_t = (struct t_header*) sp;
    u_short ethertype = ntohs(packet_t->ether_type);

    

    //cout << strlen(sp) << endl;
}
int main(int argc,char ** argv)
{
    char err[65535]="";
    pcap_t * device_handle = pcap_open_offline("1.pcap", err);
    pcap_t * out = pcap_open_live(argv[2],BUFSIZ,1,0,err);
    pcap_loop(device_handle, -1, call_back, NULL);
    return 0;
}
