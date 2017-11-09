#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
using namespace std;

void call_back(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
    static int pnumber = 0,old_timestamp=0,new_timestamp=0;
    cout << "数据包\t" << pnumber++ << ":" << endl;
    old_timestamp=new_timestamp;
    new_timestamp=h->ts.tv_sec;
    cout<<"时间戳:"<<old_timestamp<<"\t"<<new_timestamp<<endl;
    cout << "包长:" << h->caplen << "\t所抓包长:" << h->len << endl;

    //cout << strlen(sp) << endl;
}
int main()
{
    char err[PCAP_ERRBUF_SIZE] = "";
    char *device = pcap_lookupdev(err);
    if (device == NULL)
    {
        cout << "无活动网络" << err;
        return 0;
    }
    cout << device << endl;

    bpf_u_int32 ip, netmask;
    pcap_lookupnet(device, &ip, &netmask, err);
    cout << ip << netmask << endl;

    pcap_t * device_handle = pcap_open_live(device, BUFSIZ, 1, 0, err);

    bpf_program bpf_filter;
    char ip_filter[] = "ip";
    pcap_compile(device_handle, &bpf_filter, ip_filter, 0, ip);
    pcap_setfilter(device_handle,&bpf_filter);
    pcap_loop(device_handle, 10, call_back, NULL);
    pcap_close(device_handle);
    return 0;
}
