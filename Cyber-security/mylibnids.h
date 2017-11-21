#ifndef _MYLIBNIDS_
#define _MYLIBNIDS_
#include <pcap.h>
#include <nids.h>
#include <iostream>
#include <algorithm>
//struct iphdr
//{
//#if __BYTE_ORDER == __LITTLE_ENDIAN
//	unsigned int header_len:4;
//	unsigned int version:4;
//#elif __BYTE_ORDER == __BIG_ENDIAN
//	unsigned int version:4;
//	unsigned int header_len:4;
//#else
//# error "Please fix <bits/endian.h>"
//#endif
//	u_int8_t tos;
//	u_int16_t tot_len;
//	u_int16_t id;
//	u_int16_t frag_off;
//	u_int8_t ttl;
//	u_int8_t protocol;
//	u_int16_t check;
//	u_int32_t saddr;
//	u_int32_t daddr;
//	/*The options start here. */
//};


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

struct scan{
	u_int32_t addr;
	u_int16_t port;
	u_char flags;
};

struct host
{
	struct host* next;
	struct host* prev;
	u_int32_t addr;
	int modtime;
	int n_packets;
	struct scan* packets;//扫描信息
};

/*
struct nids_chksum_ctl temp;
temp.netaddr = 0;
temp.mask = 0;
temp.action = 1;
nids_register_chksum_ctl(&temp,1);
*/

//void Initialize_libppcap_online();
//void Initialize_libppcap_offline(char* filename);
#endif
