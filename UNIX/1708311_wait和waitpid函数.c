/*在图5-7中，我们调用了wait来处理已经终止的子进程
#include wait<int *static>
pid_t wait(int *statloc)
pid_t waitpid(pid_t pid,int *static,int options);
函数wait和waitpid均返回两个值：已终止子进程的进程ID号，以及通过statloc指针返回的子进程终止状态（一个整数）。我们可以调用三个宏来检查终止状态，并辨别子进程是正常终止、由某个信号杀死，还是仅仅由作业控制停止而已。另有些宏用于接着获取子进程的退出状态、杀死子进程的信号或停止子进程的作业控制信号值。
如果调用wait的进程没有已终止的子进程，不过由一个或多个子进程仍在运行，那么wait将阻塞到现有子进程第一个终止为止。
waitpid函数就等待那个进程以及是否阻塞给了我们更多的控制。首先，pid参数允许我们指定想等待的进程ID，值-1表示等待第一个终止的子进程。其次，options参数允许我们指定附加选项。最常用的选项是WNOHANG，它告知内核在没有已终止子进程时不要阻塞。

行数wait和waitpid的区别
我们现在图示出wait和waitpid在用来清理已终止子进程的区别，为此我们把TCP客户程序修改为如下所示。客户尽力5个与服务器的连接，随后在调用str_cli函数时禁用第一个连接(sockfd[0]).建立多个连接的目地是从并发服务器上派生多个子进程*/
#include"unp.h"
int main(){
	int i,sockfd[5];
	struct sockaddr_in servaddr;
	if(argc!=2)err_quit("usage:tcpcli <IPaddress>");
	for(i=0;i<5;i++){
		sockfd[i]=Socket(AF_INET,SOCK_STREAM,0);
		bzero(&&servaddr,sizeof(servaddr));
		aervaddr.sin_family=AF_INET;
		servaddr.sin_port=htons(SERV_PORT);
		Inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
		Connect(sockfd[i],(SA *)&servaddr,sizeof(servaddr));
	}
	srecli(stdin,sock[0]);
	exit(0);
}
/*建立一个信号处理函数并在其中调用wait并不足以防止出现僵死进程。本问题在于：所有5个信号都是在信号处理函数执行之前产生，而信号处理函数只执行一次，因为Unix信号一般是不排队的。在我们刚刚运行的例子中，客户和服务器在同一个主机上，信号处理函数执行1此，留下4个僵死进程。但是如果我们在不同的主机上运行客户和服务器，那么信号处理函数一般执行2次：一次是第一个产生的信号引起的，由于另外4个信号在处理函数第一次执行时发生，因此该处理函数仅仅再被调用一次，从而留下3个僵死进程。不过由的时候，依赖FIN到达服务器主机的时机，信号处理函数可能会执行3次甚至4次。
正确的解决办法调用waitpid而不死wait，图5-11给出里正确处理SIGCHLD的sig_chld函数。这个版本管用的原因在于：我们在一个循环内调用waitpid，以获取所有已终止子进程的状态。我们必须指定WNOHANG选项，它告知waitpid在由尚未终止的子进程在运行时不要阻塞。我们在图5-7中不能在循环内调用wait，因为没有办法防止wait在正运行的子进程未终止时阻塞。
*/
#include "unp.h"
void sig_chld(int singo){
	pid_t pid;
	int stat;
	while((pid=waitpid(-1,&stat,WNOHANG))>0)
		printf("child %d teminated\n",pid);
	return;
}
