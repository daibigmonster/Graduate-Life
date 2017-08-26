/*signal函数
	建议信号处置的POSIX方法就是调用sigaction函数。不过这有点复杂，因为该函数的参数之一是我们必须分配并填写的结构。简单写的方法就是调用signal函数，其第一个参数是信号名，第二个参数或为指向函数的指针，或者为常值SIG_IGN或SIG_DFL.
*/
#include "unp.h"
Sigfunc * signal(int signo,Sigfunc *func){/*
	函数singal的正常函数原型应层次太多而变得很复杂：
	void(*signal(int signo,void (*func)(int)))(int);
	为了简化起见，我们在头文件unp.h中定义了如下Sigfunc类型：
		typedef void Sigfunc(int);
	它说明信号处理函数是仅有一个整数参数且不返回值值的函数。signal的函数原型于是变为 Sigfunc *signal(int signo,Sigfunc *func);
	该函数的第二个参数和返回值都是指向信号处理函数的指针*/
	struct sigaction act,oact;
	act.sa_handler=func;
 	//设置处理函数
	//sigaction结构的sa_handle成员被设置为func参数
	sigemptyset(&act.sa_mask);
	//设置处理函数的信号掩码
	//POSIX允许我们指定这样一组信号，它们在信号处理函数被调用是阻塞。任何阻塞的信号都不能递交给进程。我们把sa_mask成员设置为空集，移位着在该函数处理函数运行起见，不阻塞额外的信号。POSIX保证被捕获的信号在其信号处理函数运行起见总是阻塞的。
	act.sa_flags=0;
	if(signo==SIGALRM){
#ifdef SA_INTERRUPT
		act.sa_flags|=SA_INTERRUPT;
#endif}
	else{
#ifdef SA_RESTART
		act.sa_flags|=SA_RESTART;
#endif
	}
//设置SA_RESTART标识
//SA_RESTART标志是可选的。如果设置，由显影信号中断的系统调用由内核自动重启。如果被捕获的信号不是SIGALRM且SA_RESTART由定义，我们就设置该标识。对SIGALRM进行特殊处理的原因在于，通常是为I/O操作设置超时，这种情况下我们希望受阻塞的系统调用被该信号中断掉。
	if(sigaction(signo,&act,&oact)<0)return(SIG_ERR);
	return(oact.handler);
	//我们调用sigaction函数，并将相应新号的就行为作为signal函数的返回值。
}
/*
POSIX信号定义
我们包符合POSIX的系统上的信号处理总结为以下几点
一旦安装了信号处理函数它遍一直安装着
在一信号处理函数运行期间，正被递交的信号是阻塞。而且，安装处理函数时在传递给sigaction函数的sa_mask信号基础指定的任何额外信号也被阻塞。在上面函数中，我们将sa_mask置为空集，意味着除了被捕获的信号外，没有额外信号被阻塞
如果一个信号的被阻塞起见产生了一次或多次，那么该信号被解阻塞之后通常只递交一次，也就是说Unix信号默认是不拍对的
利用sigprocmask函数选择性第阻塞或解阻塞一组信号是可能的。这使得我们可以做到在一段临界区代码执行区间，防止捕获某些信号，一次保护这段代码。
*/
