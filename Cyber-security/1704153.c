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
void call_back(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
    static int pnumber = 0;
    cout<<(FILE*)user;
    cout << "数据包\t" << pnumber++ << endl;
    cout << "包长\t" << h->caplen << "\t所抓包长\t" << h->len << endl;
    struct t_header* packet_t = (struct t_header*) sp;
    u_short ethertype = ntohs(packet_t->ether_type);
    cout << "包类型\t" << hex << ethertype << endl;
    switch (ethertype)
    {
        case 0x800:
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

    cout << endl;
    //cout << strlen(sp) << endl;
}
int main()
{
    char err[PCAP_ERRBUF_SIZE] = "";
    char *device = pcap_lookupdev(err);
    if (device == NULL)
    {
        cout << "无活动网络" << err;
        return 0;
    }
    cout <<"网络接口打开正常："<< device << endl;

    bpf_u_int32 ip, netmask;
    pcap_lookupnet(device, &ip, &netmask, err);

    pcap_t * device_handle = pcap_open_live(device, BUFSIZ, 1, 0, err);

    bpf_program bpf_filter;
    char ip_filter[] = "ip";
    pcap_compile(device_handle, &bpf_filter, ip_filter, 0, ip);
    pcap_setfilter(device_handle, &bpf_filter);

    FILE *fp = fopen("out.bin", "w");
    if (fp == NULL) cout << "打开文件失败" << endl;
    pcap_dumper_t* pdt = pcap_dump_fopen(device_handle, fp);
    cout<<fp;
    pcap_loop(device_handle, 10, pcap_dump, (u_char *)fp);
    //pcap_loop(device_handle, 10, call_back, (u_char *)fp);
    pcap_dump_flush(pdt);
    pcap_dump_close(pdt);
    fclose(fp);
    //if (pcap_datalink(device_handle) != DLT_EN10MB) return 0;
    //struct pcap_pkthdr p_header;
    // const u_char* packet = pcap_next(device_handle, &p_header);

    // cout <<ctime( &(p_header.ts.tv_sec))<<endl;
    pcap_close(device_handle);
    return 0;
}
