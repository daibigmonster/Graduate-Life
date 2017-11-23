#include "apue.h"
#define BUFFSIZE 4096
int main(void){
	int n;
	char buf[BUFFSIZE];
	while((n=read(STDIN_FILENO,buf,BUFFSIZE))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	if(n<0)err_sys("read error");
	exit(0);
}
/*头文件<unistd.h>及两个常量STDIN_FILENO和STDOUT_FILENO。头文件<unistd.h>包含了很多UNIX系统服务的函数原型
两个常量STDIN_FILENO和STDOUT_FILENO,他们呢执行了标准输入和标准输出的文件面熟符。在POSIX标准中，它们的值分别是0和1
3.9节将详细讨论BUFFSIZE常量，说明它的各种不同值将如何影响程序的效率
read函数返回读取的字节数，此值用作要写的字节数。当到达输入文件尾端时，read返回0,程序停止执行。如果发生一个读错误，read返回-1.出错时大多数系统函数返回-1.
*/
