#include "mylibnids.h"
#include "nids.h"
#include <stdio.h>
#include <stdlib.h>
#include<arpa/inet.h>


static void my_nids_syslog(int type,int errnum,
		struct iphdr* iph,void* data){
	static int scan_number = 0;
	char source_ip[20];
	char dest_ip[20];
	char string_content[1024];
	struct host* host_info;
	unsigned char flagsend = 255,flagsor = 0;
	int i;
	char content[1024];
	struct in_addr ipaddr;
	switch(type){
//	case NIDS_WARN_IP:
//		if(errnum != )
	case NIDS_WARN_SCAN:
		scan_number++;
		sprintf(string_content,"---------------%d---------------\n",scan_number);
		printf("%s",string_content);
		printf( "----发现扫描攻击-----\n");
		host_info = (struct host *)data;
		printf( "扫描者IP地址为:\n");
		ipaddr.s_addr = host_info->addr;
		printf("%s\n",inet_ntoa(ipaddr));
		break;
	default:
		printf("未知\n");
	}
}
int main(){
	struct nids_chksum_ctl temp;
	temp.netaddr = 0;
	temp.mask = 0;
	temp.action = 1;
	nids_register_chksum_ctl(&temp,1);
	nids_params.syslog = my_nids_syslog;
	nids_params.pcap_filter = "";
	if(!nids_init()){
		printf("出现错误: %s\n",nids_errbuf) ;
		exit(1);
	}
	nids_run();
	return 0;
}
