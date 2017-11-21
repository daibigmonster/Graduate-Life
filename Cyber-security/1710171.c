#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char error_content[PCAP_ERRBUF_SIZE];
	char *net_interface;
	net_interface = pcap_lookupdev(error_content);
	printf("%s",net_interface);
}
