/*处理SIGCHLD信号
设置将死状态的目的是维护子进程的信息，以便父进程在以后某个时候获取。这些信息包括子进程的进程ID、终止状态以及资源利用信息。如果一个进程终止，而该进程有子进程处于僵死状态，那么它的所有僵死进程的父进程ID将被重置为1（init进程）。集成这些子进程的init进程将清理他们呢（也就是说init进程将wait它们从而取出它们的僵死状态）。
处理僵死进程
我们显然不愿意留存僵死进程。它们占用内核中的空降，最终可能导致我们耗尽进程资源。无论何时我们fork子进程都得wait它们，以防止它们编程僵死进程。为此我们建立一个俘获SIGCHLD信息号的信号处理函数，在函数体中我们调用wait.
通过listen调用之后增加如下函数调用：
Signal(SIGCHLD,sig_chld);
我们就建立了信号处理函数*/
#include "unp.h"
void sig_chld(int signo){
	pid_t pid;
	int stat;
	pid=wait(&stat);
	printf("chile %d terminated\n",pid);
	return;
}
