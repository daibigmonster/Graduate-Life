/*图5-12给出了我们服务器程序的最终版本。它正确处理accept返回EINTER，并建立一个给所有已终止子进程调用waitpid的信号处理函数。
本节的目的是示范我们在网络编程时可能遇到的三种情况：
1当fork子进程时，必须捕获SIGHLD信号;
2当捕获信号时，必须处理被中断的系统调用;
3SIGCHLD的信号处理函数必须正确编写，应使用waitpid函数以免留下僵死进程*/
#include "unp.h"
#include "1708231_str_echo函数.h"
void sig_chld(int singo){
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))>0)
		printf("child %d terminated\n",pid);
	return;
}
int main(int argc,char **argv)
{
	int listenfd,connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;
	void sig_chld(int);
	listenfd=Socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(SERV_PORT);
	Bind(listenfd,(SA *)&servaddr,sizeof(servaddr));
	Listen(listenfd,LISTENQ);
	Signal(SIGCHLD,sig_chld);
	for(;;){
		clilen=sizeof(cliaddr);
		if((connfd=accept(listenfd,(SA *)&cliaddr,&clilen))<0){
			if(errno==EINTR)continue;
			else err_sys("accept error");
		}
		if((childpid=Fork())==0){
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		Close(connfd);
	}
}
