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
/*double timeconvert(struct result* data,int i)
{
    data=(struct result *)malloc(sizeof(result));
    return data[i].ts_s+(double)data[i].ts_us/1000000;
}*/
void Datafecture(vector<struct result> &Data)
{
    FILE *sp;
    if((sp=fopen("DataFecture4.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    } 
    //fseek(sp,0,SEEK_SET);
    int N=Data.size();
    int cappacketnum=0;
    int second,unittime=1;
    int total_len=0;
    struct result data[N];
    for(int i=0;i<N;++i)data[i]=Data[i];
    double aver_time=0.0,aver_len,firstpackettime=0,lastpackettime=0;
    double begintime=data[0].ts_s+(double)data[0].ts_us/1000000;
  //  cout<<begintime<<" "<<timeconvet(data,0)<<endl;
    cout.setf(ios_base::fixed,ios_base::floatfield);
   /* for(int i=0;i<N;++i)
    {
        
        double packettime=data[i].ts_s+(double)data[i].ts_us/1000000;
       // cout<<(int)(packettime-begintime)<<" ";
        second=int(packettime-begintime)+1;
        cout<<"第"<<i+1<<"个数据包：";
        cout<<"第"<<int(packettime-begintime)+1<<"秒 ";
        cout<<packettime-begintime;
        cout<<" 数据包长"<<data[i].packet_length<<" "<<endl;
     /*   if(second-unittime==0)
        {
            cappacketnum++;
            total_len+=data[i].packet_length;
            continue;
        }
        else  if(second-unittime>0)   
        {
            cout<<"捕获的数据包数量："<<cappacketnum;
            cout<<" 捕获的数据包总长"<<total_len<<endl;
            //aver_len=(double)total_len/cappacketnum;
            //cout<<"捕获的数据包平均长"<<aver_len<<endl;
            firstpackettime=data[i-cappacketnum].ts_s+(double)data[i-cappacketnum].ts_us/1000000;
            lastpackettime=data[i-1].ts_s+(double)data[i-1].ts_us/1000000;
            if(cappacketnum>=2)
            {
                aver_time=(lastpackettime-firstpackettime)/(cappacketnum-1);
                cout<<"单位平均数据包的时间间隔："<<aver_time<<endl;
            }
            if(cappacketnum==1)
            {
                aver_time=0.0;
                cout<<"单位平均数据包的时间间隔："<<aver_time<<endl;
            }           
           // fprintf(sp,"%d,%d,%.3f,%.3f\n",cappacketnum,total_len,aver_len,aver_time);        
            cappacketnum=1;
            total_len=data[i].packet_length;
            unittime=second;
        }*/
//        
 //   }
    
    
    fclose(sp);
    cout<<begintime<<endl;
    cout<<data[0].packet_length<<endl;
    cout<<data[1].src_addr<<endl;
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
 //   FILE* sp;
    //vector<int> vec;
    vector<struct result> All_data;
    int pkt_offset=24,i=0;
    struct p_pkthdr *pkt_header;
    struct ip_header* iph;
    struct result *res;
    pkt_header=(struct p_pkthdr *)malloc(sizeof(struct p_pkthdr));
    iph=(struct ip_header *)malloc(sizeof(ip_header));
    res=(struct result *)malloc(sizeof(struct result));
    if((fp=fopen("1707110.pcap","r"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }   
 /*   if((sp=fopen("DataFecture1.txt","w"))==0)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    }
    fseek(sp,0,SEEK_SET); */ 
    while(fseek(fp,pkt_offset,SEEK_SET)==0)//遍历文件
    {
        if(fread(pkt_header,16,1,fp)!=1)break;
        fseek(fp,14,SEEK_CUR);//跳过数据帧头
        if(fread(iph,sizeof(ip_header),1,fp)!= 1)break;
        //fseek(sp,sp_offset,SEEK_SET);
        res=Packetread(pkt_header,iph); 
        All_data.push_back(*res);  
       // vec.push_back(pkt_header->len);
        pkt_offset+=16+pkt_header->caplen;//下一个包的偏移值   
       // if(res->packet_num!=0)
       // fprintf(sp,"数据:%d,%d,%d,%f\n",++i,res->packet_num,res->total_len,res->aver_time);
       //if(i==1146) cout<<res->packet_num<<endl;  
        //else continue;    
        //if(!(pkt_offset= PacketRead(fp,pkt_offset))) break;   
    }
    //cout<<vec.size()<<" "<<vec[vec.size()-1]<<endl;
    Datafecture(All_data);
  //  Lengthdistribution(vec);
    fclose(fp);
  //  fclose(sp);
    free(pkt_header);
    free(iph);
    free(res);
    cout<<"程序结束"<<endl;
    return 0;
}
