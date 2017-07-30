#include<stdio.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
#include<pcap.h>
#include<vector>
#include<iostream>
#include <algorithm>
#define STRSIZE 1024
#define BUFSIZE 10240
using namespace std;
struct result
{
    u_int32_t ts_s;
    u_int32_t ts_us;
    u_int16_t packet_length;
    u_int32_t src_addr;
    u_int32_t dist_addr;
};
struct p_pkthdr//该文件为16字节
{
    u_int32_t iTimeSecond;  
    u_int32_t iTimeSS;  /* time stamp */
    u_int32_t caplen; /* length of portion present */
    u_int32_t len;    /* length this packet (off wire) */
};
struct ether_header//以太网协议的数据格式
{
    u_int8_t ether_dhost[6];//目的以太网地址
    u_int8_t ether_shost[6];//源以太网地址
    u_int16_t ether_type;//以太网类型   
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
    u_int32_t des_ip;
};
/*int streamnum(vector<struct result> &a)
{
    int distnum,srcnum;
    double streamnum;
    vector<double> a;
    for}*/
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
   FILE *sp;
    if((sp=fopen("DataFecture.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    } 
   int N=data.size(),second,unittime=1,cappacketnum=0,total_len=0;
   double aver_time=0.0,aver_len,firstpackettime=0,lastpackettime=0,packettime;
   double begintime=timeconvert(data,0);
   vector<int> srcadr,disadr,alladr;
   cout.setf(ios_base::fixed,ios_base::floatfield);   
    for(int i=0;i<N;++i)
    {
       
        packettime=timeconvert(data,i);
       // cout<<(int)(packettime-begintime)<<" ";
        second=int(packettime-begintime)+1;
        cout<<"第"<<i+1<<"个数据包：";
        cout<<"第"<<int(packettime-begintime)+1<<"秒 ";
        //cout<<packettime-begintime;
        cout<<" 数据包长"<<data[i].packet_length<<" "<<endl;
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
            for(int j=i-cappacketnum;j<i;++j)
            {
                srcadr.push_back(data[j].src_addr);
                disadr.push_back(data[j].dist_addr);
                alladr.push_back(data[j].src_addr);
                alladr.push_back(data[j].dist_addr);
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
            fprintf(sp,"%d,%d,%.3f,%.3f,%d,%d,%d\n",cappacketnum,total_len,aver_len,aver_time,actualnum(srcadr),actualnum(disadr),actualnum(alladr));           
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
    //cout<<data[1].src_addr<<endl;
}
result* Packetread(struct p_pkthdr *pkth,struct ip_header *iph)
{
    struct result*res;
    res=(struct result *)malloc(sizeof(struct result));
    res->ts_s=pkth->iTimeSecond;
    res->ts_us=pkth->iTimeSS;
    res->packet_length=pkth->caplen;
    res->src_addr=iph->src_ip;
    res->dist_addr=iph->des_ip;
    return res;
}
int main()
{
    FILE* fp;
    vector<struct result> All_data;
    int pkt_offset=24,i=0;
    struct p_pkthdr *pkt_header;
    struct ether_header* eth;
    struct ip_header* iph;
    struct result *res;
    pkt_header=(struct p_pkthdr *)malloc(sizeof(struct p_pkthdr));
    eth=(struct ether_header *)malloc(sizeof(ether_header));
    iph=(struct ip_header *)malloc(sizeof(ip_header));
    res=(struct result *)malloc(sizeof(struct result));
    if((fp=fopen("1707141.pcap","r"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }   
    while(fseek(fp,pkt_offset,SEEK_SET)==0)//遍历文件.跳过文件头
    {
        if(fread(pkt_header,16,1,fp)!=1)break;
        pkt_offset+=16+pkt_header->caplen;//下一个包的偏移值 
        if(fread(eth,14,1,fp)!= 1)break;
        if(eth->ether_type==8)
        {
            if(fread(iph,20,1,fp)!= 1)break;
            {
                 // cout<<"IP源地址："<<inet_ntoa(*((in_addr *)&(iph->src_ip)))<<endl;
                  res=Packetread(pkt_header,iph); 
                  All_data.push_back(*res);
            }
        }
        //else continue;
        
       // fseek(fp,14,SEEK_CUR);//跳过数据帧头
        
          
            
    }
    Datafecture(All_data);
    Lengthdistribution(All_data);
    cout<<inet_ntoa(*((struct in_addr *)&(All_data[0].src_addr)))<<" "<<All_data[0].dist_addr<<endl;
    fclose(fp);
    free(pkt_header);
    free(iph);
    free(res);
    free(eth);
    cout<<"程序结束"<<endl;
    return 0;
}
