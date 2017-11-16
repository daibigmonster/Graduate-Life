#include "libp_head.cpp"
#include <iostream>
#include <pcap.h>

using std::cout;
using std::endl;

void Initialize_libppcap_online(){
	char err[PCAP_ERRBUF_SIZE] = "";
	char *device = pcap_lookupdev(err);
	if(device == nullptr){
		cout << "没有可用网络接口" << err;
		return ;
	}
	cout << "网络接口初始化成功 : " << device << endl;
	bpf_u_int32 ip,mask;
	pcap_lookupnet(device,&ip,&mask,err);
}
