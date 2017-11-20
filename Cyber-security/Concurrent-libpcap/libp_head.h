/*struct pcap_pkthdr
{
	struct timeval ts;     time stamp
	bpf_u_int32 caplen;    length of portion present
	bpf_u_int32 len;       length this packet (off wire)
};  */

/*struct nids_prm
{
	int n_tcp_strams;
	int n_hosts;
	char* device;
	char* filename;
	int sk_buff_size;数据结构是sk_buff是Linux内核中一个重要的数据结构，是用来进行数据包排队
	操作的，默认值为168
	int dev_addon;
	void (*syslog){};这是一个函数指针，默认值为nids_syslog()函数。在syslog函数中可以
加测入侵攻击，如网络扫描攻击，也可以检测一些异常情况，如无效TCP标记
	int suslog_level;
	int scan_num_hosts;
	int scan_delay;
	int scan_num_ports;
	int (*no_men)(char *);
	int (*ip_filter)();
	char* pcap_filter;
	int promisc;
	int one_loop_less;
	int pcap_time_out;
}*/
#ifndef _INTERNET_HEADER_
#define _INTERNET_HEADER_
#include <pcap.h>
#include <iostream>
#include <algorithm>
struct iphdr
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
	unsigned int header_len:4;
	unsigned int version:4;
#elif __BYTE_ORDER == __BIG_ENDIAN
	unsigned int version:4;
	unsigned int header_len:4;
#else
# error "Please fix <bits/endian.h>"
#endif
	u_int8_t tos;
	u_int16_t tot_len;
	u_int16_t id;
	u_int16_t frag_off;
	u_int8_t ttl;
	u_int8_t protocol;
	u_int16_t check;
	u_int32_t saddr;
	u_int32_t daddr;
	/*The options start here. */
};


struct tcp_header
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
};

struct udp_header
{
    u_int16_t sport;
    u_int16_t dport;
    u_int16_t total_len;
    u_int16_t checksum;
};

void Initialize_libppcap_online();
void Initialize_libppcap_offline(char* filename);
#endif
