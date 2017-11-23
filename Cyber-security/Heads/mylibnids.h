#ifndef _MYLIBNIDS_
#define _MYLIBNIDS_
#include <pcap.h>
#include <nids.h>
#include <arpa/inet.h>
/*struct iphdr
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
	The options start here.
};*/
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

/*struct tuple4
{
	u_int16_t source;
	u_int16_t dest;
	u_int32_t saddr;
	u_int32_t daddr;

};*/

/*
struct half_stream
{
	char state;
	char collect;//用来表示有数据到达，此数据放在data成员中。如果大于0就存储，否则就忽略
	char collect_urg;
	char *data;
	int offset;
	int count;
	int count_new;
	int bufsize;
	int rmen_alloc;
	u_int acked;
	u_int seq;
	u_int ack_seq;
	u_int first_data_seq;
	u_char urgdata;
	u_char count_new_urg;
	u_char urg_seen;
	u_int urg_ptr;
	u_short window;
	u_char ts_on;
	u_int curr_ts;
	struct skbuff *List;
	struct skbuff *Listtail;
};
*/

/*
struct tcp_stream
{
	struct suple4 addr;//	成员nids_state 表示连接的逻辑状态
//	NIDS_JUST_SET 标识TCP链接建立，在此状态下就可以决定是否
 * 对TCP连接进行数据分析，可以决定是否捕获TCP客户端接收的数据
 * TCP服务器端接收的数据、TCP客户接收的紧急数据或者
 * TCP服务器端接受的紧急数据
 * NIDS_CLOSE 表示TCP连接正常关闭
 * NIDS_RESET 表示TCP连接被重置关闭
 * NIDS_TIMED_OUT 表示由于超时TCP连接被关闭
 * NIDS_EXITING 表示Libnids正在退出，在这个状态下可以最后一次使用
 * 存储在half_stream数据结构中的缓存数据
 * NIDS——DATA 表示Libnids正在退出，在这个状态可以判断是否有新的数据
 * 到达，如果有就把数据存储起来，可以在这个状态之中来分析TCP传输
 * 的数据，此数据就存储在half_stream数据结构的缓存之中。
	char nids_state;
	struct lurker_node *Listeners;
	struct half_stream client;
	struct half_stream server;
	struct tcp_stream  *next_node;
	struct tcp_stream  *prev_node;
	int hash_index;
	struct tcp_stream *next_time;
	struct tcp_stream *prev_time;
	int read;
	struct tcp_stream *next_free;

};
*/

/*
struct nids_chksum_ctl temp;
temp.netaddr = 0;
temp.mask = 0;
temp.action = 1;
nids_register_chksum_ctl(&temp,1);
*/

#endif
