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
    u_int16_t packet_num;
    u_int16_t total_len;
    double aver_time;
};
struct p_pkthdr//该文件为16字节
{
    u_int32_t iTimeSecond;  
    u_int32_t iTimeSS;  /* time stamp */
    u_int32_t caplen; /* length of portion present */
    u_int32_t len;    /* length this packet (off wire) */
};
void Datafecture(vector<struct result> &data)
{
    int N=data.size();
    struct result Data[N];}
void Lengthdistribution(vector<int> &s)
{
    FILE *sp;
    if((sp=fopen("lengthdistribution.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }   
    int N=s.size();
    int len[N],distribute[N],temp;
    int distnum=1;
    for(int i=0;i<N;++i)
    {
       len[i]=s[i];
    }
    sort(&len[0],len+N);
    fseek(sp,0,SEEK_SET);
    for(int i=0;i<N;i++)
    {
        if(len[i]<len[i+1])
        {
        fprintf(sp,"%d,%d\n",len[i],distnum);
        distnum=1;
        }
        else if(len[i]==len[i+1])
        {
             distnum++;
             continue;
        }

    }
    fclose(sp);    
}
result* PacketRead(struct p_pkthdr *pkt_header)
{
    static int pnumber=0;
    static double old_timestamp=0,new_timestamp=0,Persecond=0,lasttime;
    static int total_len=0,packet_num=0; 
    double aver_time;
    struct result *res;
    res=(struct result *)malloc(sizeof(struct result));
    cout.setf(ios_base::fixed,ios_base::floatfield);
    if(pnumber==0)
    {
        new_timestamp=pkt_header->iTimeSecond+(double)(pkt_header->iTimeSS)/1000000;
        old_timestamp=new_timestamp;
    }
    else
    {
        old_timestamp=new_timestamp;
        new_timestamp=pkt_header->iTimeSecond+(double)(pkt_header->iTimeSS)/1000000;
    } 
    cout<<"数据包:"<<++pnumber<<endl;
    //cout<<"时间戳："<<pkt_header->iTimeSecond<<endl;
    lasttime=Persecond;
    Persecond+=(new_timestamp-old_timestamp);
    if(Persecond<=1.000000)
    {
        packet_num++;
        total_len+=pkt_header->caplen; 
        //cout<<"单位时间已经捕获的数据包："<<packet_num<<endl;
       // cout<<"单位时间已经捕获的数据包总长"<<total_len<<endl;    
        //cout<<"与单位时间第一个数据包的时间差:"<<Persecond<<endl;
        res->packet_num=0;
        res->total_len=0;
    }
    else
    {
        cout<<"单位时间捕获的数据包数量"<<packet_num<<endl;
        cout<<"单位时间捕获的数据包总长"<<total_len<<endl;
        if(packet_num>=3)
        {
            aver_time=lasttime/(packet_num-1);
            cout<<"单位平均数据包的时间间隔："<<aver_time<<endl;
        }
        else if(packet_num==2)
        {
            aver_time=lasttime;
            cout<<"单位平均数据包的时间间隔："<<aver_time<<endl;
        } 
        else aver_time=0.0;
        res->packet_num=packet_num;
        res->total_len=total_len;
        res->aver_time=aver_time;
       // fprintf(sp,"%d,%d,%f\n",packet_num,total_len,aver_time);
        Persecond=new_timestamp-old_timestamp;
        packet_num=1;
        total_len=pkt_header->len;
        cout<<"新单位时间数据包的时间差:"<<Persecond<<endl;
    } 
    return res;
    //fclose(sp);
}
int main()
{
    FILE* fp;
    FILE* sp;
    vector<int> vec;
    vector<struct result> All_data;
    int pkt_offset=24,i=0;
    cout<<sizeof(double)<<endl;
    struct p_pkthdr *pkt_header;
    struct result *res;
    pkt_header=(struct p_pkthdr *)malloc(sizeof(struct p_pkthdr));
    res=(struct result *)malloc(sizeof(struct result));
    if((fp=fopen("1707110.pcap","r"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }   
    if((sp=fopen("DataFecture.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }
    fseek(sp,0,SEEK_SET);  
    while(fseek(fp,pkt_offset,SEEK_SET)==0)
    {
        if(fread(pkt_header,16,1,fp)!=1)break;
        //fseek(sp,sp_offset,SEEK_SET);
        res=PacketRead(pkt_header); 
        All_data.push_back(*res);  
        vec.push_back(pkt_header->len);
        pkt_offset+=16+pkt_header->caplen;//下一个包的偏移值   
        if(res->packet_num!=0)
        fprintf(sp,"数据:%d,%d,%d,%f\n",++i,res->packet_num,res->total_len,res->aver_time);
       //if(i==1146) cout<<res->packet_num<<endl;  
        else continue;    
        //if(!(pkt_offset= PacketRead(fp,pkt_offset))) break;   
    }
    //cout<<vec.size()<<" "<<vec[vec.size()-1]<<endl;
    Datafecture(All_data);
    Lengthdistribution(vec);
    fclose(fp);
    fclose(sp);
    cout<<"程序结束"<<endl;
    return 0;
}
