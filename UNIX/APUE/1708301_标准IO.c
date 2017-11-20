/*标准IO函数为那些不带缓冲的IO函数提供了一个带缓冲的接口。使用标准IO函数无序担心如何选取最佳缓冲区的大小。使用标准IO函数还简化了对输入行的处理。例如，fgets函数读取一个完整的行，而read函数读取指定字节数。在5.4节中我们将了解到，标准IO函数库提供了使我们能够控制该库所使用的缓冲风格的函数。*/
#include "apue.h"
int main(){
	int c;
	while((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("output error");
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
