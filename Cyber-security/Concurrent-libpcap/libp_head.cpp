#include "libp_head.h"
#include <iostream>
#include <pcap.h>
#include<arpa/inet.h>
#include <string>

using std::cout;
using std::endl;

void Initialize_libppcap_online(){
	char err[PCAP_ERRBUF_SIZE] ;
	char *device = pcap_lookupdev(err);
	if(device == nullptr){
		cout << "没有可用网络接口" << err;
		return ;
	}
	cout << "网络接口 : " << device << " 初始化成功"<< endl;
	bpf_u_int32 ip,mask;
	pcap_lookupnet(device,&ip,&mask,err);
	struct in_addr ipaddr,maskaddr;
	ipaddr.s_addr = ip;
	maskaddr.s_addr = mask;
	cout << "接口网络地址： " << inet_ntoa(ipaddr) << endl;
	cout << "接口掩码地址： " << inet_ntoa(maskaddr) << endl;
}

void Initialize_libppcap_offline(char* filename){
	char err[PCAP_ERRBUF_SIZE] ;
	pcap_t* handle;
	if((handle = pcap_open_offline(filename,err)) == nullptr){
		cout << err << endl;
		return ;
	}
	cout << "读取线下文件: " << filename << " 成功！" << endl;
}
int main(int argc,char* argv[]) {
	if(argv[1] == nullptr)Initialize_libppcap_online();
	if(argv[1] != nullptr)Initialize_libppcap_offline(argv[1]);
	return 0;
}
