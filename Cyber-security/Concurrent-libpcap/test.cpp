
#include "libp_head.h"

int main(int argc,char* argv[]) {
	if(argv[1] == nullptr)Initialize_libppcap_online();
	else Initialize_libppcap_offline(argv[1]);
	return 0;
}
