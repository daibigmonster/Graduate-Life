#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
#include<string>
#include <memory>
using namespace std;
int main()
{
    char err[PCAP_ERRBUF_SIZE] = "";
    char *device = pcap_lookupdev(err);
    if (device == NULL)
    {
        cout << "无网络" << err;
        return 0;
    }
    cout << device << endl;

    bpf_u_int32 ip, netmask;
    pcap_lookupnet(device, &ip, &netmask, err);
    cout<<ip<<endl;
    cout<<inet_ntoa(*((in_addr *)(&ip)))<<endl;
    char* ip_addr=new char;
    //shared_ptr<char *> ip_addr(new char());
    cout<<inet_ntop(AF_INET,&ip,ip_addr,16)<<endl;
    free(ip_addr);
    return 0;
}
