//TCP时间获取服务器程序
#include <unp.h>
#include <time.h>
#include <arpa/inet.h>
int main(int argc,char **argv)
{
    int listenfd,connfd;
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    time_t ticks;
    listenfd=Socket(AF_INET,SOCK_STREAM,0);
    /*socket函数是一个可用于根据指定的地址族、数据类型和协议来分配一个套接口的描述字机器所用的资源的函数
    //第一个参数af：一个地址的描述。目前仅支持AF_INET格式，也就是说APRA internet地址格式。
    //第二个参数：新套接口的类型描述，可支持的类型如下：
    SOCK_STREAM提供有序的、可靠的、双向的和基于连接的字节流，使用带外数据传送机制，为internet地址族使用TCP
    SOCK_DGRAM支持无连接的、不可靠的和使用固定大小（通常很小）缓冲区的数据包服务，为internet地址族使用UDP。
    SOCK_STREAM类型的套接口为全双向的字节流。对于流泪套接口，在接收或发送数据必须处于已连接状态。用connect()调用与另一套接口的连接，连接成功后，既可用send()和recv()传送数据。当绘画结束后，调用close().带外数据根据规定用send()和recv()来接收*/
    //TCP套接字的创建与客户程序相同
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(13);
    Bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
    
    //通过填写一个网络套接字地址结构并调用bind函数，服务器的众所周知端口（对时间获取服务是13）被捆绑到所创建的套接字。我们指定IP地址为INADDR_ANY,这样要是服务器由多个网络接口，服务器进程就可以在任意网络接口上接受客户连接。
    Listen(listenfd,LISTENQ);
    //调用listen函数把该套接字转换成一个监听套接字，这样来自客户的外来连接就可在该套接字上由内核接受。socket、bind和listen这三个调用步骤是任何TCP服务器所谓的监听描述符的正常步骤。
    for(;;)
    {
        connfd=Accept(listenfd,(SA*)NULL,NULL);
        ticks=time(NULL);
        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(&ticks));
        Write(connfd,buff,strlen(buff));
        Close(connfd);
    }
}
//通常情况下，服务器进程在accpet调用中被投入睡眠，等待某个客户连接的到达并被内核接受。TCP连接时用三次握手来建立连接。握手完毕时accept返回，其返回值是一个称为已连接描述符的新描述符（本例为connfd)。该描述符用于与新近连接的那个客户通信。accept为每个连接到本服务器的客户返回一个新描述符。
