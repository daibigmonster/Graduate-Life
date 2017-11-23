#include<pcap.h>
#include<iostream>
#include<cstring>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<iomanip>
#include<vector>
#include <algorithm>
//#include<map>
struct result
{
    u_int32_t ts_s;
    u_int32_t ts_us;
    u_int16_t packet_length;
    u_int32_t src_ip;
    u_int32_t dis_ip;
    u_int16_t sport;
    u_int16_t dport;
    u_char proto:8;
};
struct ip_header{
    int header_len:4;
    int version:4;
    u_char tos:8;
    int total_len:16;
    int ident:16;
    int flag:16;
    u_char ttl:8;
    u_char proto:8;
    int checksum:16;
    u_int32_t src_ip;
    u_int32_t dis_ip;
};
typedef struct
{
    u_short sport;
    u_short dport;
    u_int32_t sn;
    u_int32_t an;
    u_int16_t other;
    u_int16_t win_size;
    u_int16_t checksum;
    u_int16_t urg_ptr;
    u_int32_t option;
} tcp_header;
typedef struct
{
    u_int16_t sport;
    u_int16_t dport;
    u_int16_t total_len;
    u_int16_t checksum;
} udp_header;
using namespace std;
vector<struct result> all_data;
int actualnum(vector<int> &a)
{
    int num=1;
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]<a[i+1])num++;
        else if(a[i]==a[i+1])continue;
    }
    return num;
}
double timeconvert(vector<struct result> &data,int i)
{
    //data=(struct result *)malloc(sizeof(result));
    double time=data[i].ts_s+(double)data[i].ts_us/1000000;
    return time;
}
int streamcompare(vector<result> &data,int a,int b)
{
    int stream=0,j=0;
    int i=a;
   // cout<<a<<" "<<b<<endl;
    j=i;
   while(i<b)
    {
        cout<<i<<":";
        if((data[i].src_ip==data[i+1].src_ip)&&(data[i].dis_ip==data[i+1].dis_ip)||(data[i].src_ip==data[i+1].dis_ip)&&(data[i].dis_ip==data[i+1].src_ip))
        { 
            cout<<"地址匹配相等"<<endl;
           if((data[i].sport==data[i+1].sport)&&(data[i].dport==data[i+1].dport)||(data[i].sport==data[i+1].dport)&&(data[i].sport==data[i+1].dport))
            {
                cout<<"端口匹配相等"<<endl;
                i++;
                //continue;
            }
            else
            {
                cout<<"端口匹配不相等"<<endl;
                if(i==j)
                {
                    i++;
                    j=i;
                }
                else
                {
                    i++;
                    j=i;
                    stream++;
                 }
                 //cout<<"端口匹配不相等"<<endl;
                 //i++;
             }
       }
       else
       {
            cout<<"地址匹配不相等"<<endl;
            if(i==j)
            {
                i++;
                j=i;
            }
            else
            {
                i++;
                j=i;
                stream++;
            }
          //  
          //  i++;
       }
    }
    return stream;
}
void Lengthdistribution(vector<result> &s)
{
    FILE *sp;
    if((sp=fopen("lengthdistribution.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }   
    int N=s.size();
    int distnum=1,sum=0;
    vector<int> len;
    for(int i=0;i<N;i++)len.push_back(s[i].packet_length);
    sort(len.begin(),len.end());
    //fseek(sp,0,SEEK_SET);
    for(int i=0;i<N;i++)
    {
        if(len[i]<len[i+1])
        {
        sum+=distnum;
        fprintf(sp,"%d,%d\n",len[i],distnum);
        
        distnum=1;
        }
        else if(len[i]==len[i+1])
        {
             distnum++;
             continue;
        }
        else if(len[N-1]==len[i-2])fprintf(sp,"%d,%d\n",len[N-1],distnum+1);
        else if(len[N-1]>len[i-2])fprintf(sp,"%d,%d\n",len[N-1],1);
    }
    fclose(sp);    
}
void Datafecture(vector<struct result> &data)
{
    //cout<<inet_ntoa(*((in_addr *)&(data[0].src_addr)))<<endl;
    FILE *sp;
    if((sp=fopen("DataFecture1.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    } 
   int N=data.size(),second,unittime=1,cappacketnum=0,total_len=0,stream=0;
   double aver_time=0.0,aver_len,firstpackettime=0,lastpackettime=0,packettime;
   double begintime=timeconvert(data,0);
   vector<int> srcadr,disadr,alladr;
   cout.setf(ios_base::fixed,ios_base::floatfield);  
   fprintf(sp,"流数量，单位时间捕获数据包数量，单位时间总包长，单位时间平均包长，单位时间平均数据包间隔，源地址数量，目的地址数量，总地址数量\n");   
    for(int i=0;i<N;++i)
    {
       
        packettime=timeconvert(data,i);
       // cout<<(int)(packettime-begintime)<<" ";
        second=int(packettime-begintime)+1;
        cout<<"第"<<i+1<<"个数据包：";
        cout<<"第"<<int(packettime-begintime)+1<<"秒 ";
        //cout<<packettime-begintime;
        cout<<" 数据包长"<<data[i].packet_length<<" "<<endl;
        cout<<"IP源地址："<<inet_ntoa(*((in_addr *)&(data[i].src_ip)))<<" "
            <<data[i].sport<<endl;
        cout<<"目的地址："<<inet_ntoa(*((in_addr *)&(data[i].dis_ip)))<<" "
            <<data[i].dport<<endl;
         if(second-unittime==0)
        {
            cappacketnum++;
            total_len+=data[i].packet_length;
            continue;
        }
        else  if(second-unittime>0)   
        {
            cout<<"捕获的数据包数量："<<cappacketnum;
            cout<<" 捕获的数据包总长"<<total_len<<endl;
            aver_len=(double)total_len/cappacketnum;
            cout<<"捕获的数据包平均长"<<aver_len<<endl;
            firstpackettime=timeconvert(data,i-cappacketnum);
            lastpackettime=timeconvert(data,i-1);
            stream=streamcompare(all_data,i-cappacketnum,i);
            cout<<"单位时间流的数量"<<stream<<endl;
            
            for(int j=i-cappacketnum;j<i;++j)
            {
                srcadr.push_back(data[j].src_ip);
                disadr.push_back(data[j].dis_ip);
                alladr.push_back(data[j].src_ip);
                alladr.push_back(data[j].dis_ip);
            }

            if(cappacketnum>=2)
            {
                aver_time=(lastpackettime-firstpackettime)/(cappacketnum-1);
                cout<<"单位平均数据包的时间间隔："<<aver_time<<endl;
            }
            else if(cappacketnum==1)
            {
                aver_time=0.0;
                cout<<"单位平均数据包的时间间隔："<<aver_time<<endl;
            }
            fprintf(sp,"%d,%d,%d,%.3f,%.3f,%d,%d,%d\n",stream,cappacketnum,total_len,aver_len,aver_time,actualnum(srcadr),actualnum(disadr),actualnum(alladr));           
            cappacketnum=1;
            total_len=data[i].packet_length;
            unittime=second;
            srcadr.clear();
            disadr.clear();
            alladr.clear();
        }
   }
   fclose(sp);
    //cout<<begintime<<" "<<begintime1<<endl;
    //cout<<data[0].packet_length<<endl;
    //cout<<data[1].src_addr<<endl;cout<<inet_ntoa(*((in_addr *)&(data[0].dist_addr)))<<endl;
}
/*void test(vector<struct result> &data)
{
    int N=data.size();
    for(int i=0;i<N;i++)
    {
        cout<<i<<":"<<endl;
        cout<<"IP源地址："<<inet_ntoa(*((in_addr *)&(data[i].src_ip)))<<" "
            <<data[i].sport<<endl;
        cout<<"目的地址："<<inet_ntoa(*((in_addr *)&(data[i].dis_ip)))<<" "
            <<data[i].dport<<endl;
    }
}*/
void call_back(u_char *user, const struct pcap_pkthdr *h, const u_char *sp)
{   
    struct result*res;
    res=(struct result *)malloc(sizeof(struct result));
    ip_header* iph;
    iph=(struct ip_header *)(sp+14); 
    //cout<<"IP源地址："<<inet_ntoa(*((in_addr *)&(iph->src_ip)))<<" ";
    //cout<<"目的地址："<<inet_ntoa(*((in_addr *)&(iph->des_ip)))<<endl;
    res->ts_s=h->ts.tv_sec;
    res->ts_us=h->ts.tv_usec;
    res->packet_length=h->caplen;
    res->src_ip=iph->src_ip;
    res->dis_ip=iph->dis_ip;
    switch(iph->proto)
    {
        case 6:
        tcp_header* th;
        th=(tcp_header*)(sp+14+20);
        res->sport=ntohs(th->sport);
        res->dport=ntohs(th->dport);
        break;
        case 17:
        udp_header* uh;
        uh=(udp_header*)(sp+14+20);
        uh->sport=ntohs(uh->sport);
        uh->dport=ntohs(uh->dport);
        break;
        default:
        break;
    }
    res->proto=iph->proto;
    all_data.push_back(*res);
    free(res);
}
int main(int argc,char *argv[])
{
    pcap_t *handle;
    char error[100];
    char file[]="1.pcap";
    bpf_u_int32 ip;
    struct bpf_program bpf_filter;
    if((handle=pcap_open_offline(file,error))==NULL)
    {
        printf("%s\n",error);
        return 0;
    }
    char ip_filter[]="ip";
    pcap_compile(handle,&bpf_filter,ip_filter,0,ip);
    pcap_setfilter(handle,&bpf_filter);
    pcap_loop(handle, -1, call_back, NULL);
    pcap_close(handle);
    Datafecture(all_data);
    Lengthdistribution(all_data);
    //test(all_data);
    all_data.clear();
    return 0;
}
