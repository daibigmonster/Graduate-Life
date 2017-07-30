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
static int p_number = 0;
void tcp_callback(struct tcp_stream *tcp_connection, void ** argv)
{
    //cout<<tcp_connection->nids_state<<endl;
    struct tuple4 ip_and_port=tcp_connection->addr;
    static int stream_num=0;
switch(tcp_connection->nids_state)//判断LIBNIDS的状态
{
    case NIDS_JUST_EST://表示TCP客户端和TCP服务器端建立连接状态
       tcp_connection->client.collect++;//客户端接收数据
       tcp_connection->server.collect++;//服务器接收数据
       tcp_connection->server.collect_urg++;//服务器接收紧急数据
       tcp_connection->client.collect_urg++;//客户端接收紧急数据
      //printf("%sTCP连接建立\n",address_string);
      cout<<inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr)))<<":"<<ip_and_port.source;
    cout<<"<--->";
    cout<<inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr)))<<":"<<ip_and_port.dest<<endl;
      cout<<"TCP连接建立,流数量为"<<++stream_num<<endl;
      break;
   case NIDS_CLOSE://表示TCP连接正常关闭
      cout<<inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr)))<<":"<<ip_and_port.source;
      cout<<"<--->";
      cout<<inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr)))<<":"<<ip_and_port.dest<<endl;
      cout<<"TCP连接正常关闭,流数量为"<<--stream_num<<endl;
      break;
   case NIDS_RESET://表示TCP连接被RST关闭
      cout<<inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr)))<<":"<<ip_and_port.source;
    cout<<"<--->";
    cout<<inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr)))<<":"<<ip_and_port.dest<<endl;
      cout<<"TCP连接被RST关闭,流数量为"<<--stream_num<<endl;
      break;
   default:
        break;
  //case NIDS_DATA://表示有新的数据到达
    //  cout << "有新的数据到达" << endl;
      //  break;
    
    
}
}
/*void udp_callback(u_char* content)
{
    cout << "udp" << endl;
}*/
int main()
{
  //  freopen("/media/woqucc/新加卷/pcap_data/data01result.txt", "w", stdout);
    nids_params.device = NULL;
    nids_params.filename = "1707141.pcap";
   // nids_params.device ="enp2s0";
    struct nids_chksum_ctl temp;
    temp.netaddr = 0;
    temp.mask = 0;
    temp.action = 1;
    nids_register_chksum_ctl(&temp,1);
    if (!nids_init())
    {
        cout << "初始化失败" << endl;
    }
    //nids_register_ip_frag((void*)ip_call_back);
    //nids_register_ip_frag((void*) ip_callback);
    nids_register_tcp((void*)tcp_callback);
    //nids_register_udp((void*)udp_callback);
    //nids_next();

    nids_run();
    cerr << "end" << endl;
    return 0;
}
