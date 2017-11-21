#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
#include<pcap/bpf.h>
using namespace std;

void call_back(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{
    static int pnumber = 0;
    static double old_timestamp=0,new_timestamp=0,Persecond=0,lasttime;
    static int total_len=0,packet_num=0;
    cout.setf(ios_base::fixed,ios_base::floatfield);
    if(pnumber==0)
    {
        new_timestamp=h->ts.tv_sec+(double)(h->ts.tv_usec)/1000000;
        old_timestamp=new_timestamp;
  //      cout<<"数据包0"<<endl;
    }
    else
    {
        old_timestamp=new_timestamp;
        new_timestamp=h->ts.tv_sec+(double)(h->ts.tv_usec)/1000000;
    }
    cout << "数据包\t" << pnumber++ << ":" << "时间戳"<<h->ts.tv_sec<<" "<<h->ts.tv_usec<<endl;
    lasttime=Persecond;
    Persecond+=(new_timestamp-old_timestamp);
    if(Persecond<=1.000000)
    {
        packet_num++;
        total_len+=h->len;      
        cout<<"时间差"<<Persecond<<endl;
    }
    else
    {
        cout<<"单位时间捕获的数据包数量"<<packet_num<<endl;
        cout<<"单位时间捕获的数据包总长"<<total_len<<endl;
        if(packet_num>=3)
           cout<<"单位平均数据包的时间间隔："<<lasttime/(packet_num-1)<<endl;
        Persecond=new_timestamp-old_timestamp;
        packet_num=1;
        total_len=h->len;
        cout<<"时间差"<<Persecond<<endl;
    }
   // cout<<"时间戳:"<<old_timestamp<<"\t"<<new_timestamp<<endl;
    ///cout << "包长:" << h->caplen << "\t所抓包长:" << h->len << endl;
    
    //cout << "总包长:" <<total_len<<endl;
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
    pcap_loop(device_handle, 20, call_back, NULL);
    pcap_close(device_handle);
    return 0;
}
