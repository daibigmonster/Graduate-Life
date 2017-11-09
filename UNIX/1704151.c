#include<iostream>
#include<pcap.h>
#include<arpa/inet.h>
using namespace std;
int main()
{
    char err[PCAP_ERRBUF_SIZE] = "";
    // char * device = pcap_lookupdev(err);
    pcap_if_t *all_d;
    if (pcap_findalldevs(&all_d, err) == -1)
    {
        cout << "获取设备失败" << err << endl;
    }
    for (; all_d; all_d = all_d->next)
    {
        cout <<"接口名称\t "<< all_d->name << endl;
        if(all_d->description)cout <<"描述 \t"<< all_d->description<< endl;
        for (pcap_addr *a = all_d->addresses; a; a = a->next)
        {
            switch (a->addr->sa_family)
            {
                case AF_INET:
                    if (a->addr) cout << "地址\t"<<inet_ntoa(((struct sockaddr_in *) (a->addr))->sin_addr) << endl;
                    if (a->broadaddr) cout <<"广播地址\t"<< inet_ntoa(((struct sockaddr_in *) (a->broadaddr))->sin_addr) << endl;
                    if (a->dstaddr) cout <<"目的地址\t"<< inet_ntoa(((struct sockaddr_in *) (a->dstaddr))->sin_addr) << endl;
                    if (a->netmask) cout <<"子网掩码\t"<< inet_ntoa(((struct sockaddr_in *) (a->netmask))->sin_addr) << endl;
                    break;
                default:
                    //cout<<"未知协议"<<a->addr->sa_family<<endl;
                    break;
            }

        }
        cout<<endl;
    }
    /* unsigned int a, b;
     struct in_addr addr1;
     struct in_addr addr2;
     pcap_lookupnet(device, &a, &b, err);
     addr1.s_addr = a;
     addr2.s_addr = b;
     cout << device << endl;
     cout << inet_ntoa(addr1);
     cout << inet_ntoa(addr2);*/
    return 0;
}

