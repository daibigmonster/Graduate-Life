#include<stdio.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
#define STRSIZE 1024
#define BUFSIZE 10240
typedef long bpf_int32;
typedef unsigned long bpf_u_int32;
typedef unsigned short  u_short;
typedef unsigned long u_int32;
typedef unsigned short u_int16;
typedef unsigned char u_int8;
struct pcap_pkthdr//该文件为16字节
{
struct timeval ts;  /* time stamp */
bpf_u_int32 caplen; /* length of portion present */
bpf_u_int32 len;    /* length this packet (off wire) */
};
typedef struct IPHeader_t
{ //IP数据报头
u_int8 Ver_HLen;       //版本+报头长度
u_int8 TOS;            //服务类型
u_int16 TotalLen;       //总长度
u_int16 ID; //标识
u_int16 Flag_Segment;   //标志+片偏移
u_int8 TTL;            //生存周期
u_int8 Protocol;       //协议类型
u_int16 Checksum;       //头部校验和
u_int32 SrcIP; //源IP地址
u_int32 DstIP; //目的IP地址
} IPHeader_t;
int main()
{
    FILE* fp;
    int pkt_offset=24,i=0;//pacap头文件结构24个字节
    struct pcap_pkthdr *pkt_header;
    IPHeader_t *ip_header;
    char my_time[STRSIZE];
    char buf[BUFSIZE];
   // file_header = (struct pcap_file_header *)malloc(sizeof(struct pcap_file_header));
    pkt_header  = (struct pcap_pkthdr *)malloc(sizeof(struct pcap_pkthdr));
    ip_header = (IPHeader_t *)malloc(sizeof(IPHeader_t));
    //tcp_header = (TCPHeader_t *)malloc(sizeof(TCPHeader_t));
    memset(buf, 0, sizeof(buf));
    
    if((fp=fopen("1707110.pcap","r"))==NULL)
    {
        printf("错误文件");
        exit(0);
    }
    
    fseek(fp,24,SEEK_SET);
    printf("执行断点！");
    if(fread(pkt_header,16,1,fp)!=1)
    {
        printf("read to the end of pcap file\n");
       // break;
    }
    fseek(fp, 14, SEEK_CUR); 
    if(fread(ip_header, sizeof(IPHeader_t), 1, fp) != 1)
    {
        printf("%d: can not read ip_header\n", i);
        //break;
     }
    printf("时间戳：%ld",pkt_header->ts.tv_sec);
    strftime(my_time,sizeof(my_time),"%Y-%m-%d %T", localtime(&(pkt_header->ts.tv_sec)));
    printf("%d: %s\n", i, my_time);

    fclose(fp);
   // if(fp!=NULL)free(fp);
    return 0;
    
}
