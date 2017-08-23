#include "unp.h"
#include "1708231_str_echo函数.h"
int main(int argc,char **argv)
{
    int listenfd,connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr,servaddr;
    listenfd=Socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//通配地址由常值INADR_ANY来指定，其值一般为0。它告知内核去选择IP地址。
    servaddr.sin_port=htons(SERV_PORT);
    Bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
    Listen(listenfd,LISTENQ);
    for(;;){
        clilen=sizeof(cliaddr);
        connfd=Accept(listenfd,(SA *)&cliaddr,&clilen); //如果我们对返回客户协议地址不感兴趣，那么可以把cliaddr和addrlen均置为空指针。
        if((childpid=Fork())==0){
            Close(listenfd);
            str_echo(connfd);//process the request
            exit(0);
        }
        Close(connfd);    
    }
}
/*捆绑通配地址是在告知系统：要是系统是多宿主机，我们将接收目的地址为任何本地接口的连接
端口号，在任何时候多个进程可能同时使用TCP、UDP和SCTP这3中传输层协议中的任何一种。这3中协议都使用16为整数的端口号来区分这些进程。
当一个客户想要跟一个服务器联系时，它必须标识想要与之通信的这个服务器TCPUDP和SCTP定义了一组众所周知的端口，用于表示众所周知的服务。举例来说，支持FTP的任何TCP/IP实现都把21这个中所周知的端口分配给FTP服务器。
另一方面，客户通常使用短期存活的临时端口，这些端口号通常由传输层协议自动赋予客户。客户通常不关心临时端口的具体值，而只要确信该端口在所在主机中是唯一的就行。传输协议的代码确保这种唯一性。
端口号被分为3端
1众所周知的端口0-1023
2已登记端口1024-49151IANA等级并提供它们的使用情况清单。可能的话，相同端口号也分配给TCP和UDP的同一给定服务
349152-65535是动态的或私用的端口，IANA不管这些端口，它们就是我们所称的临时端口。
UNIX系统由保留端口的概念，指的是小于1024的任何端口。这些端口只能赋予特权用户进程的套接字

套接字对
一个TCP连接的套接字对是agiel定义该连接的两个端点的四元组：本地IP地址、本地TCP端口号、外地IP地址、外地TCP端口号。套接字对唯一标识一个网络上的每个TCP连接。
标识每个端点的两个值（IP地址和端口号）通常称为一个套接字*/

