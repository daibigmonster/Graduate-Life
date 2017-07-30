#include<pcap.h>
#include<iostream>
#include<cstring>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include<vector>
#include <algorithm>
//#include<map>
struct result
{
    u_int32_t ts_s;
    u_int32_t ts_us;
    u_int16_t packet_length;
    u_int32_t src_ip;
    u_int32_t dis_ip;
    u_int16_t sport;
    u_int16_t dport;
    u_char proto:8;
};
struct ip_header{
    int header_len:4;
    int version:4;
    u_char tos:8;
    int total_len:16;
    int ident:16;
    int flag:16;
    u_char ttl:8;
    u_char proto:8;
    int checksum:16;
    u_int32_t src_ip;
    u_int32_t dis_ip;
};
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
using namespace std;
vector<struct result> all_data;
void flowratio(vector<struct result> &data)
{
    //double ratio=0.0;
    int srclen=0;
    int deslen=0;
    char* src;
    src=(char *)malloc(sizeof(char));
    char* des;
    des=(char *)malloc(sizeof(char));
    struct in_addr* src_a;
    src_a=(struct in_addr *)malloc(sizeof(struct in_addr));
    struct in_addr* des_a;
    des_a=(struct in_addr *)malloc(sizeof(struct in_addr));
    cout<<"请输入源地址：";
    cin>>src;
    cout<<"请输入目的地址：";
    cin>>des;
    //cout<<data[0].src_ip<<endl;
    inet_aton(src,src_a);
    inet_aton(des,des_a);
    //cout<<src_a->s_addr<<endl;
    for(int i=0;i<data.size();++i)
    {
        if((data[i].src_ip==src_a->s_addr)&&(data[i].dis_ip==des_a->s_addr))
        {
          //  cout<<i+1<<endl;
            srclen+=data[i].packet_length;
        }
        if((data[i].src_ip==des_a->s_addr)&&(data[i].dis_ip==src_a->s_addr))
        {
           // cout<<i<<endl;
            deslen+=data[i].packet_length;
        }
    }
    //FILE *sp;
    cout<<"上下行流量分别是：";
    cout<<srclen<<" "<<deslen<<endl;
    if(deslen==0)
        cout<<"上行流量为:"<<srclen<<" 下行流量为：0"<<endl;
    else
        cout<<(double)srclen/deslen<<endl; 
}
void call_back(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{   
    struct result*res;
    res=(struct result *)malloc(sizeof(struct result));
    ip_header* iph;
    iph=(struct ip_header *)(sp+14); 
    //cout<<"IP源地址："<<inet_ntoa(*((in_addr *)&(iph->src_ip)))<<" ";
    //cout<<"目的地址："<<inet_ntoa(*((in_addr *)&(iph->des_ip)))<<endl;
    res->ts_s=h->ts.tv_sec;
    res->ts_us=h->ts.tv_usec;
    res->packet_length=h->caplen;
    res->src_ip=iph->src_ip;
    res->dis_ip=iph->dis_ip;
    switch(iph->proto)
    {
        case 6:
        tcp_header* th;
        th=(tcp_header*)(sp+14+20);
        res->sport=ntohs(th->sport);
        res->dport=ntohs(th->dport);
        break;
        case 17:
        udp_header* uh;
        uh=(udp_header*)(sp+14+20);
        uh->sport=ntohs(uh->sport);
        uh->dport=ntohs(uh->dport);
        break;
        default:
        break;
    }
    res->proto=iph->proto;
    all_data.push_back(*res);
    free(res);
}
int main(int argc,char *argv[])
{
    pcap_t *handle;
    char error[100];
    char file[]="1707110.pcap";
    bpf_u_int32 ip;
    struct bpf_program bpf_filter;
    if((handle=pcap_open_offline(file,error))==NULL)
    {
        printf("%s\n",error);
        return 0;
    }
    char ip_filter[]="ip";
    pcap_compile(handle,&bpf_filter,ip_filter,0,ip);
    pcap_setfilter(handle,&bpf_filter);
    pcap_loop(handle, -1, call_back, NULL);
    pcap_close(handle);
   // Datafecture(all_data);
    //Lengthdistribution(all_data);
    //test(all_data);
    flowratio(all_data);
    all_data.clear();
    return 0;
}
