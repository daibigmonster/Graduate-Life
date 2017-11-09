/*listen函数
根据TCP转换图，调用listen导致套接字从CLOSED状态转换到LISTEN状态。
本函数的第二个参数规定了内核应该为相应套接字排队的最大连接个数
#include<sys/socket.h>
int listen(int sockfd,int backlog);
内核为任何一个给定的监听套接字维护两个队列：未完成队列，已完成队列
而过三路握手正常完成，该项就从未完成连接队列移到已完成连接队列的队尾当进程调用accept时,已完成队列的队头项将放回给进程，或者如果该队列为空，那么进程将被投入睡眠，直到TCP在该队列中放入一项才唤醒它。
1listen函数的backlog参数曾被规定为这两个队列综合的最大值
2backlog增设了一个模糊因子：把它乘以1.5得到未处理队列最大长度。举例来说通常指定为5的backlog值实际上允许最多由8项在排队。
3不要把backlog定义为0.
覆写backlog的值
void Listen(int fd,int backlog){
    char *ptr;
    if((ptr=getenv("LISTENQ"))!=NULL)
        backlog=atoi(ptr);
    if(listen(fd,backlog)<0)
    err_sys("listen error")
}

accept函数
accept函数由TCP服务器调用，用于从已完成连接队列队头返回下一个已完成连接。如果已完成连接诶队列为空，那么进程被投入睡眠
#include<sys/socket.h>
int accept(int sockfd,struuct *cliaddr,sockelen_t *addrlen);
参数cliaddr和addrlen用来返回已连接的对端进程（客户）的协议地址。调用前，我们将由*addrlen所引用的整数值置为由cliaddr所指的套接字地址结构的长度，返回时，该整数值即为由内核存放在该套接字地址结构内的确切字符数。

