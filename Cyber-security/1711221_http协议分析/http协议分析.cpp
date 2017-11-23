#include <iostream>
#include <string>
#include "mylibnids.h"
using namespace std;

void http_callback(struct tcp_stream* tcp_http_conection
		,void** param)
{
	string address_content;
	string content;
	struct tuple4 ip_and_port = tcp_http_conection->addr;
	address_content = inet_ntoa(*((struct in_addr *)&(ip_and_port.saddr)));
	address_content = address_content + " : " + to_string(ip_and_port.source);
	address_content += "<--->";
	address_content += inet_ntoa(*((struct in_addr *)&(ip_and_port.daddr)));
	address_content = address_content + " : " + to_string(ip_and_port.dest);
	if(tcp_http_conection -> nids_state == NIDS_JUST_EST)
	{
		if(tcp_http_conection->addr.dest != 80)return;
		tcp_http_conection->client.collect++;
		tcp_http_conection->server.collect++;
		cout << "\n\n\n----------------------------------\n";
		cout << address_content << " 建立连接\n";
		return;
	}
	if(tcp_http_conection->nids_state == NIDS_CLOSE)
	{
		cout << "----------------------------------\n";
		cout << address_content << " 连接正常关闭\n";
		return;
	}
	if(tcp_http_conection->nids_state == NIDS_RESET)
	{
		cout << "----------------------------------------\n";
		cout << address_content << " 连接被RST关闭\n";
		return;
	}
}




int main(){
	struct nids_chksum_ctl temp;
	temp.netaddr = 0;
	temp.mask = 0;
	temp.action = 1;
	nids_register_chksum_ctl(&temp,1);
	if(!nids_init())return 0;
	nids_register_tcp((void*)http_callback);
	nids_run();
	return 0;
}
