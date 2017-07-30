#include<iostream>
#include<stdio.h>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
#include<iomanip>
using namespce std;
typedef struct t_header
{
    u_int8_t src[6];
    u_int8_t dst[6];
    u_int32_t ether_type;
}ether_header;
typedef struct{
    int header_len:4;
    int version:4;
    u_char tos:8;
    int total_len:16;
    int ident:16;
    int flag:16;
    u_char ttl:8;
    u_char proto:8;
    int checksum:16;
    u_char src_ip[4];
    u_char des_ip[4];
}ip_header;
typedef struct{
    u_short sport;//源端口号
    u_short dport;//目的端口号
    u_int32_t sn;
    u_int32_t an;
    u_int16_t other;
    u_int16_t win_size;
    u_int16_t checksum;
    u_int16_t urg_ptr;
    u_int32_t option;
}tcp_header;
typeder struct
{
    u_int16_t sport;
    u_int16_t dport;
    u_int16_t total_len;
    u_int16_t checksum;
}udp_header;
void call_back(u_char *user,const struct pcap_pkthdr *h,const u_char *sp){
    static int pnumber=0;
    cout<<(FILE*)user;
    cout<}

