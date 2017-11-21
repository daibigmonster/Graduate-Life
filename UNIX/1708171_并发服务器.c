/*并发服务器
当服务一个客户请求可能花费比较长时间时，我们并不希望整个服务器被单个客户长期占用，而是希望同时服务多个客户。UNIX编写并发服务器程序最简单的办法就是fodk一个子进程来服务每个客户。*/
pid_t pid;
int listenfd,connfd;
listen=Socket(...);
bing(listenfd,...);
Listen(listenfd,LISTENQ);
for(;;){
    connfd==Accept(listenfd,...);
if((pid=fork())==0){
    Colse(listenfd);//child close listening socket
    doit(connfd);//process the requeest
    Close(connfd);//done with this client;
    exit(0);//child terminates
    }
    Close(connfd);//parent close connected socket
}
/*当一个连接建立时，accept返回，服务器接着调用fork，然后由子进程服务客户（通过已连接套接字），父进程则等待另一个连接（通过监听套接字listenfd）.既然新的客户由子进程提供服务，父进程就关闭已连接套接字。
对一个TCP套接字调用close会导致发送一个IN，随后是正常的TCP连接终止序列

Close
#include <unistd.h>
int close(int sockfd);
close一个TCP套接字的默认行为是吧该套接字标记成已关闭，然后立即返回到调用进程。该套接字描述符不能再用调用进程使用，也就是说他不能再作为read或wirte的第一个参数，然而TCP将尝试发送已排队等待发送到对端的任何数据，发送完毕后发生的是正常的TCP连接终止序列。

getsockname和getpeername函数
这两个函数或者返回与某个套接字关联的本地协议地址，或者返回与某个套接字关联的外地协议跌至
#include<sys/socket.h>
int getsockname(int sockfd,struct asockaddr *localaddr,socklen_t* addrlen);
int getpeername(int sockfd,struct sockaddr*peeraddr,socklen_t *addrlen)
