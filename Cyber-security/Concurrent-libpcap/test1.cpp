#include <pcap.h>
#include <iostream>
using namespace std;

int main(){
    char err[PCAP_ERRBUF_SIZE];
    pcap_if_t* all_d;
    if(pcap_findalldevs(&all_d,err) == -1){
        cout << "获取设备失败" << err << endl;`:
    }

}

