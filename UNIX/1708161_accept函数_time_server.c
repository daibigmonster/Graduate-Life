/*accept函数
accept函数由TCP服务器调用，用于以完成连接队列队头返回下一个已完成连接。如果已完成连接队列为空，那么进程被投入睡眠（假定套接字为默认的阻塞方式）。
#include<sys/socket.h>
int accept(int sockfd,struct sockaddr *cliaddr,socklen_t *addrlen);
参数cliaddr和addrlen用来返回已连接的对端进程的协议地址
如果accept成功，那么其返回值是由内核自动生成的一个全新描述符，代表与所返回客户的TCP连接。在讨论accept函数是，我们称它的第一个参数为监听套接字描述符，称它的返回值为已连接套接字描述符。区分这两个套接字非常重要。一个服务器通常仅仅创建一个监听套接字，它在该服务器的生命期内一直存在。内核为每个由服务器进程接收的客户连接创建一个已连接套接字（也就是说对于它的TCP三路握手过程已经完成）。当服务器完成对某个给定客户的服务时，相应的已连接套接字就被关闭。
本函数对多返回三个值：一个既可能是新套接字描述符也可能是出错指示的整数、客户进程的协议地址（由cliaddr指针所指）以及该地值的大小（由addrlen指针所指）。如果我们对返回客户协议地址不甘心去，那么可以把cliaddr和addrlen均置为空指针。*/
#include"unp.h"
#include<time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
int main(int argc,char **argv)
{
    int listenfd,connfd;
    socklen_t len;
    struct sockaddr_in servaddr,cliaddr;
    char buff[MAXLINE];
    time_t ticks;
    unsigned int value = 0x1;     
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    printf("%d\n",listenfd);

    setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(void *)&value,sizeof(value)); 
   /* bool bDontLinger = false;
    setsockopt(listenfd,SOL_SOCKET,SO_DONTLINGER,(const char*)&bDontLinger,sizeof(BOOL));*/
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(13);
    
    Bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
    Listen(listenfd,LISTENQ);
    for(;;){
        len=sizeof(cliaddr);
        connfd=Accept(listenfd,(SA *)&cliaddr,&len);
        printf("connect from %s,port %d\n",
                Inet_ntop(AF_INET,&cliaddr.sin_addr,buff,sizeof(buff)),ntohs(cliaddr.sin_port));
        ticks=time(NULL);
        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
        Write(connfd,buff,strlen(buff));
        Close(connfd);
    }
}
