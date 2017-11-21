/*str_echo函数执行每个客户的服务：从客户读入数据，并把让阿们回射给客户*/
#include "unp.h"
void str_echo(int sockfd)
{
	ssize_t n;
	char buf[MAXLINE];
again:
	while((n=readline(sockfd,buf,MAXLINE))>0)
		Writen(sockfd,buf,n);
	if(n<0&&errno==EINTR)
		goto again;
	else if(n<0)
		err_sys("str_echo:read error");
}
/*read函数从套接字读入数据，writen函数把其中内容回射给客户。如果客户关闭连接，那么接收到客户的FIN将导致服务器子进程的read函数返回0,这又导致str_echo函数返回，从而在服务器主函数中终止子进程。*/
