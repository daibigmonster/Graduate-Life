/*getsockname getpeername函数
这两个函数或者返回与某个套接字关联的本地协议地址(getsockname),或者返回某个套接字关联的外地协议地址，或者返回某个套接字关联的外地协议地址
#include <sys/socket.h>
int getsockname(int sockfd,struct sockaddr *localaddr,socklen_t *addrlen);
int getpeername(int sockfd,struct sockaddr *peeraddr,socklen_t *addrlen);
注意，这两个函数的最后一个参数都是值-结果参数。也就是说，这两个函数都得装填由localaddr或peeraddr指针所指的套接字地址结构
这两个函数返回与某个网络连接的两端中任何一段相关联的协议地址。
需要这两个函数的理由如下所述
在一个没有调用bind的TCP客户上，connect成功返回后,getsockname用于返回由内核赋予该连接的本地IP地址和本地端口号。
在以端口号0调用bind(告知内核去选择本地端口号)后，getsockname用于返回由内核赋予的本地端口号。
getsockname可用于获取某个套接字的地址族
在一个以通配IP地址调用bind的TCP服务器上，与某个客户的连接一旦建立(accept成功返回)，getsocketname就可以用于返回由内核赋予该连接的本地IP地址。在这样的调用总共，套接字描述符参数必须是已连接套接字的描述符。而不是监听套接字的描述符。
当一个服务是由调用过accept的某个进程通过调用exec执行程序时，它能够获取客户身份的唯一途径便是调用getpeername.inetd fork并exec某个TCP服务器程序就是这个情形。inetd调用accept返回两个值：已连接套接字描述符connfd，这是函数的返回值;客户的IP地址及端口号。inetd随后调用fork,派生出inetd的一个子进程。既然子进程起始于父进程的内存映像的一个副本，父进程的安格套接字地址结构在子进程中也可用，那个已连接套接字描述符也是如此。然而当子进程调用exec执行真正的服务器程序时（譬如说Telnet服务器程序时），子进程的内存映像被替换成新的Telnet服务器的程序文件（也就是说包含对端地址的那个套接字地址结构就此丢失），不过那个已连接套接字描述符跨exec继续保持开放，Telnet服务器首先调用的函数之一便是getpeername,用于获取客户的IP地址和端口号
显然，最后一个例子中的Telnet服务器必须在启动之后获取connfd的值。获取该值有两个常用方法。第一种方法是，调用exec的进程可以把这个描述符号格式化成一个字符串，再把它作为一个命令行参数传递给新程序。第二种方法是，约定在exec之前，总是把某个特定描述符置为所接受的已连接套接字的描述符置为所接受的已连接套接字的描述符*/
//获取套接字的协议族
#include "unp.h"
int sockfd_to_family(int sockfd)
{
    struct sockaddr_stirage ss;
    socklen_t len;
    len=sizeof(ss);
    if(getsockname(sockfd,(SA *)&ss,&len)<0)
        return(-1);
    return (ss.ss_family);
}
