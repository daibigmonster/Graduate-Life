#include<stdio.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
#include<iostream>
#include<pcap.h>
#define BUFSIZE 10240
#define STRSIZE 1024
using namespace std;
/*struct pcap_file_header//文件头是24字节
{
u_int32_t magic;       /* 0xa1b2c3d4 */
/*u_short version_major;   /* magjor Version 2 */
//u_short version_minor;   /* magjor Version 4 */
//u_int32_t thiszone;      /* gmt to local correction */
//u_int32_t sigfigs;     /* accuracy of timestamps */
//u_int32_t snaplen;     /* max length saved portion of each pkt */
//u_int32_t linktype;    /* data link type (LINKTYPE_*) */
//};*/
struct p_pkthdr//该文件为16字节
{
    u_int32_t iTimeSecond;  
    u_int32_t iTimeSS;  /* time stamp */
    u_int32_t caplen; /* length of portion present */
    u_int32_t len;    /* length this packet (off wire) */
};
typedef struct IPHeader_t
{ //IP数据报头
u_int8_t Ver_HLen;       //版本+报头长度
u_int8_t TOS;            //服务类型
u_int16_t TotalLen;       //总长度
u_int16_t ID; //标识
u_int16_t Flag_Segment;   //标志+片偏移
u_int8_t TTL;            //生存周期
u_int8_t Protocol;       //协议类型
u_int16_t Checksum;       //头部校验和
u_int32_t SrcIP; //源IP地址
u_int32_t DstIP; //目的IP地址
} IPHeader_t;
int main()
{
    FILE* fp;
    
    int pkt_offset=24,i=0;//pacap头文件结构24个字节
    struct p_pkthdr *pkt_header;
    IPHeader_t *ip_header;
    char my_time[STRSIZE];
    char buf[BUFSIZE];
    cout<<sizeof(struct p_pkthdr)<<endl;
    cout<<sizeof(struct pcap_file_header)<<endl;
    // file_header = (struct pcap_file_header *)malloc(sizeof(struct pcap_file_header));
    pkt_header  = (struct p_pkthdr *)malloc(sizeof(struct p_pkthdr));
    ip_header = (IPHeader_t *)malloc(sizeof(IPHeader_t));
    //tcp_header = (TCPHeader_t *)malloc(sizeof(TCPHeader_t));
    memset(buf, 0, sizeof(buf));
    memset(my_time, 0, sizeof(my_time));
    fp=fopen("1707110.pcap","r");
    if(fp==NULL)
    {
        cout<<"错误文件"<<endl;
        exit(0);
    } 
    while(fseek(fp,pkt_offset,SEEK_SET)==0)
    {
        i++;
        //printf("%d",i);
        if(fread(pkt_header,sizeof(struct p_pkthdr),1,fp)!=1)
        {
            cout<<"数据包头读取完成"<<endl;
            break;
        }      
        pkt_offset+=16+pkt_header->caplen;//下一个包的偏移值
        cout<<"数据包数："<<i<<endl;
        cout<<"时间戳："<<pkt_header->iTimeSecond<<endl;
        cout<<"包长"<<pkt_header->len<<" "<<pkt_header->caplen<<endl;
       // memset(my_time, 0, sizeof(my_time));
       // strftime(my_time,sizeof(my_time),"%Y-%m-%d %T", localtime(&(pkt_header->iTimeSecond)));
       //cout<<i<<my_time<<endl;;
        
    }
    
    fclose(fp);
    cout<<"程序结束！"<<endl;
    return 0;
}
