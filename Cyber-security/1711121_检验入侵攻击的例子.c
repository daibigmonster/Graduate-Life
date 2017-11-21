#include "mylibnids.h"
#include "nids.h"
#include <stdio>
#include <stdlib>
#include<arpa/inet.h>


static void (my_nids_syslog(int type,int errnum,
		struct iphdr* iph,void* data))(){
	static int scan_number = 0;
	string source_ip;
	string dest_ip;
	string string_content;
	struct host* host_info;
	unsigned char flagsend = 255,flagsor = 0;
	int i;
	string content[1024];
	struct in_addr ipaddr;
	switch(type){
//	case NIDS_WARN_IP:
//		if(errnum != )
	case NIDS_WARN_SCAN:
		scan_number++;
		cout << "---------------" << scan_number
			 << "---------------" << endl;
		cout << "----发现扫描攻击-----" << endl;
		host_info = (struct host *)data;
		cout << "扫描者IP地址为:\n";
		ipaddr.s_addr = host_info->addr;
		cout <<  inet_ntoa(ipaddr);
		break;
	default:
		cout << "未知" << endl;
	}
}
int main(){
	struct nids_chksum_ctl temp;
	temp.netaddr = 0;
	temp.mask = 0;
	temp.action = 1;
	nids_register_chksum_ctl(&temp,1);
	struct nids_prm nids_para;
	nids_params.syslog = my_nids_syslog;
	nids_params.pcap_filter = "ip";
	if(!nids_init()){
		cout << "出现错误: %s\n",nids_errbuf ;
		exit(1);
	}
	nids_run();
	return 0;
}
