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
void call_back1(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
    cout << 123 << endl;
}
void call_back(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
    static int pnumber = 0;
    struct t_header* packet_t = (struct t_header*) sp;
    u_short ethertype = ntohs(packet_t->ether_type);

    switch (ethertype)
    {
        case 0x800:
            cout << dec << pnumber++ << endl;
            cout << "包长\t" << h->caplen << "\t所抓包长\t" << h->len << endl;
            cout << "包类型\t" << hex << ethertype << endl;
            cout << "ts" <<ctime( &(h->ts.tv_sec)) <<endl;
            ip_header* h;
            h = (ip_header*) (sp + 14);
            cout << "由";
            cout << dec << (int) (h->sourceIP[0]) << ".";
            cout << (int) (h->sourceIP[1]) << ".";
            cout << (int) (h->sourceIP[2]) << ".";
            cout << (int) (h->sourceIP[3]) << "至";
            cout << dec << (int) (h->destIP[0]) << ".";
            cout << (int) (h->destIP[1]) << ".";
            cout << (int) (h->destIP[2]) << ".";
            cout << (int) (h->destIP[3]) << endl;
            switch (h->proto)
            {
                case 6:
                    cout << "TCP\t";
                    tcp_header* th;
                    th = (tcp_header*) (sp + 14 + h->header_len * 4);
                    cout << ntohs(th->sport) << '\t' << ntohs(th->dport) << endl;
                    break;
                case 17:
                    cout << "UDP\t";
                    udp_header* uh;
                    uh = (udp_header*) (sp + 14 + h->header_len * 4);
                    cout << ntohs(uh->sport) << '\t' << ntohs(uh->dport) << endl;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    //cout << strlen(sp) << endl;
}
FILE *fp = NULL;
void search_packet(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
    pcap_dump((u_char*) fp, h, sp);
}
int main()
{

    char err[PCAP_ERRBUF_SIZE] = "";
    /*fopen("out.bin", "w");
     if (fp == NULL)
     {
     cout << "打开文件失败" << endl;
     return 0;
     }*/

    pcap_t * device_handle = pcap_open_offline("out.bin", err);
    //pcap_t * device_handle = pcap_open_live("wlan0", BUFSIZ, 1, 0, err);
    // pcap_set_rfmon(device_handle,1);
   // pcap_dispatch()
    pcap_loop(device_handle, -1, call_back, NULL);
    cerr << "end" << endl;
    // pcap_t * device_handle = pcap_open_offline("/media/woqucc/新加卷/pcap_data/data01.pcap", err);
    //pcap_loop(device_handle, -1, search_packet, NULL);
    bpf_program bpf_filter;
    char ip_filter[] = "ip";

    return 0;
}
