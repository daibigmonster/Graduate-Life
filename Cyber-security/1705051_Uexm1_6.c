#include <unp.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
    int sockfd,n;
    char recvline[MAXLINE+1];
    struct sockaddr_in6 servaddr;
    if(argc!=2)
        err_quit("usage:a.out <IPaddress>");
    if((sockfd=socket(AF_INET6,SOCK_STREAM,0))<0)
    //socket函数创建一个网际（AF_INET)字节流（SOCK_STREAM)套接字，它是TCP套接字的花哨名字。该函数返回一个小整数.
        err_sys("socket error");
    //err_sys函数输出我们座位参数提供的出错消息以及所发生的系统错误的描述，然后终止进程，所有err_开头的函数都是自行编写的
    
    
    //我们把服务器的IP地址和端口号填入一个网际套接字地址结构（一个名为servaddr的sockaddr_in的地址变量).
    bzero(&servaddr,sizeof(servaddr));//使用bzero把整个结构清零之后
    servaddr.sin6_family=AF_INET6;//置地址族为AF_NET
    servaddr.sin6_port=htons(13);//端口号为13，网络套接字地址结构中IP地址和端口号这两个成员必须使用特定格式，为此我们调用库函数htons("主机到网络短整数"）去转换二进制端口号
    if(inet_pton(AF_INET6,argv[1],&servaddr.sin6_addr)<=0)//IP地址为第一个命令行参数的值（agrv[1]）。调用库函数inet_pton("呈现形式到数值")去把ASCII命令行参数（例如运行本例字所用的206.168.1112.96)转换为合适的格式。
        err_quit("inet_pton error for %s:",argv[1]);
    
    
    
    if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))<0)//connect函数应用与一个TCP套接字时，将与由它的第二个参数指向的套接字地址结构制定的服务器建立一个TCP连接。该套接字地址结构的长度也必须座位该函数的第三个参数制定，对于网际套接字的地址结构，我们总是使用C语言的sizeof操作符由编译器来计算这个长度。
        err_sys("connect error");
        
        
    while((n=read(sockfd,recvline,MAXLINE))>0)//我们使用read函数读取服务器的应答，并用标准的I/o函数fputs输出结果。使用TCP时必须小心，因为TCP是一个没有记录编辑的字节流协议。
    
    //通常服务器返回包含26个字节的单个字节，但是如果数据量很大，我们就不能确保一次read调用能返回服务器的整个应答。因此从TCP套接字读取数据时，我们总要需要read编写在某个循环中，当read返回0（表明对端关闭连接）或负值（表明发生错误）时终止循环。
    {
        recvline[n]=0;
        if(fputs(recvline,stdout)==EOF)
            err_sys("fputs error");
    }
    if(n<0)
        err_sys("read error");
    exit(0);
}
    //本例中，服务器关闭连接表征记录的结束。sun远程过程调用以及域名系统在使用TCp承载应用数据时，在每个要发送的记录之前放置一个二进制的计数值，给出这个记录的长度。这里的重要概念是TCP本身并不提供记录结束标志：如果应用程序需要确定记录的边界，它就要自己去实现，已有一些常用的方法可以供选择。
    
