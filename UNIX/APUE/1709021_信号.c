/*信号用于通知进程发生了某种情况。例如，若某一个进程执行除法操作，其除数为0,则将名为SIGFPE(浮点异常)的信号发给该进程。进程有以下3种处理信号的方式。
1忽略信号。有些信号表示硬件异常，例如，除以0或访问进程地址空间以外的存储单元等，因为这些异常产生的后果不确定，所以不推荐使用这种处理方式。
2按系统默认方式处理。对于除数为0,系统默认方式是终止该进程。
3提供一个函数，信号发生时调用该函数，这被称为捕捉该信号。通过提供自编的函数，我们就能直到什么产生了信号，并按期望的方式处理它。
信号SIGINT的系统默认动作是终止进程。
为了能捕捉到次新号，程序需要调用signal函数，其中指定了当产生SIGINT信号时，要调用函数的名字。函数名为sig_int,当其被调用时，只是打印一条消息,然后打印一个新提示符。
*/
#include "apue.h"
#include <sys/wait.h>
static void sig_int(int);
int main(){
	char buf[MAXLINE];
	pid_t pid;
	int status;
	if(signal(SIGINT,sig_int)==SIG_ERR)
		err_sys("signal error");
	printf("%% ");
	while(fgets(buf,MAXLINE,stdin)!=NULL){
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0;//replace newline with null
		if((pid=fork())<0){
			err_sys("fork error");
		}
		else if(pid==0){
			execlp(buf,buf,(char *)0);
			err_ret("couldn't execute: %s",buf);
			exit(127);
		}
		if((pid=waitpid(pid,&status,0))<0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}
void sig_int(int signo){
	printf("interrupt\n%% ");
}
