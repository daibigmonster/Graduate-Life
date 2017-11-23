/*
 * main.cpp
 *
 *  Created on: 2016年1月23日
 *      Author: root
 */
//c++11 -std=c++11
#include<pcap.h>
#include<iostream>
#include<cstring>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include<map>
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
char h[3] = "";
char * itoh(unsigned char i)
{
    h[0] = (i & 0xF0) >> 4;
    h[1] = (i & 0x0F);
    h[0] += h[0] > 9 ? 'A' - 10 : '0';
    h[1] += h[1] > 9 ? 'A' - 10 : '0';
    return h;
}
char sql[65535] = "";
map<string,pcap_dumper_t*> tcp;
map<string,pcap_dumper_t*> udp;
pcap_t * device_handle = NULL;
string file_name;
void call_back(u_char *user, const struct pcap_pkthdr *pcap_h, const u_char *sp)
{

    string packet = "";
    string protocol = "";
    stringstream src_ip;
    stringstream dest_ip;
    stringstream src_port;
    stringstream dest_port;
    string index;
    static int pnumber = 0;
    pnumber++;
    struct t_header* packet_t = (struct t_header*) sp;
    u_short ethertype = ntohs(packet_t->ether_type);
    map<string,pcap_dumper_t*>::iterator i;
    switch (ethertype)
    {
    case 0x800:
        ip_header* h;
        h = (ip_header*) (sp + 14);

        src_ip <<dec<< (int) (h->sourceIP[0]);
        src_ip << ".";
        src_ip <<dec <<(int) (h->sourceIP[1]);
        src_ip << ".";
        src_ip << (int) (h->sourceIP[2]);
        src_ip << ".";
        src_ip << (int) (h->sourceIP[3]);
        dest_ip << (int) (h->destIP[0]);
        dest_ip << ".";
        dest_ip << (int) (h->destIP[1]);
        dest_ip << ".";
        dest_ip << (int) (h->destIP[2]);
        dest_ip << ".";
        dest_ip << (int) (h->destIP[3]);

        if(src_ip.str() > dest_ip.str())
        {
            index = dest_ip.str() +"_"+ src_ip.str();
        }
        else
        {
            index = src_ip.str() +"_"+ dest_ip.str();
        }
        
        switch (h->proto)
        {
        case 6:
            protocol += "TCP";
            tcp_header* th;
            th = (tcp_header*) (sp + 14 + h->header_len * 4);
            src_port << (int)ntohs(th->sport);
            dest_port << (int)ntohs(th->dport);
            i = tcp.find(index);
            if(i == tcp.end())
            {
                
                pcap_dumper_t * new_file = pcap_dump_open(device_handle,(file_name + "_div/tcp_"+ index + ".pcap").c_str());
                tcp.insert(make_pair(index,new_file));
                i = tcp.find(index);
                
            }
            pcap_dump(reinterpret_cast<u_char*>(pcap_dump_file(i->second)),pcap_h,sp);
            break;
        case 17:
            protocol += "UDP";
            udp_header* uh;
            uh = (udp_header*) (sp + 14 + h->header_len * 4);
            src_port << (int)ntohs(uh->sport);
            dest_port << (int)ntohs(uh->dport);
            i = udp.find(index);
            if(i == udp.end())
            {
                pcap_dumper_t * new_file = pcap_dump_open(device_handle,(file_name + "_div/udp_"+ index + ".pcap").c_str());
                udp.insert(make_pair(index,new_file));
                i = udp.find(index);
  
            }
            pcap_dump(reinterpret_cast<u_char*>(pcap_dump_file(i->second)),pcap_h,sp);
            break;
            break;
        default:
            return;
        }
        break;
    default:
        break;
    }
}
int main(int argc,char *argv[])
{
    char err[65535] = "";
    if(argc < 2)return 0;
    file_name = argv[1];
    device_handle = pcap_open_offline(argv[1], err);
    pcap_loop(device_handle, -1, call_back, NULL);
    pcap_close(device_handle);
    for(auto i = tcp.begin();i!=tcp.end();++i)
    {   
        pcap_dump_flush(i->second);
        pcap_dump_close(i->second);
    }
    for(auto i = udp.begin();i!=udp.end();++i)
    {   
        pcap_dump_flush(i->second);
        pcap_dump_close(i->second);
    }


    return 0;
}

