#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

/*
 * 所有执行I/O擦做的系统都用以文件描述符，一个非负整数（通常是小整数），来指代打开的文件。
 * 文件描述符用以表示所有类型的已打开文件，包括管道、FIFO、socket、终端、设备和普通文件。针对每个进程，文件描述符都自称一套。
 * 按照惯例，大多数程序都期望使用3种标准的文件描述符。更确切地说，程序继承shell文件描述符的副本
 *
 * 下面介绍执行文件IO操作的4个主要系统调用（编程语言和软件包通常会利用IO函数库对他们进行调用）
 * fd = open(pathname,flags,mode)打开pathname所标识的文件，并返回文件描述符，用以在后续函数中指代打开的文件。
 * 如果文件不存在，open函数可以创建之，这取决于对位掩码的设置
 *
 * numread = read(fd,buffer,count)调用从fd所指代的打开文件中读取至多count字节的数据，并存储到buffer中。read()调用的
 * 返回值为实际写入文件中的字节数，且有可能小于count
 *
 * status = close(fd)在所有输入/输出操作完成之后，调用close(),释放文件描述符fd以及与之相关的内核资源。
 *
 * 该程序实现将源文件内容复制到新文件中
 */
int main(int argc,char *argv[])
{
	int inputFd,outputFd,openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];

	if(argc !=3 || strcmp(argv[1], "--help") == 0)
		printf("%s old-file new-file\n",argv[0]);
//	Open input and output files
	inputFd = open(argv[1],O_RDONLY);
	if(inputFd == -1)
	{
		fprintf(stderr,"file %s error",argv[1]);
		exit(0);
	}

	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

	outputFd = open(argv[2],openFlags,filePerms);
	if(outputFd == -1)
	{
		fprintf(stderr,"file %s error",argv[2]);
		exit(0);
	}

	while((numRead = read(inputFd,buf,BUF_SIZE)) > 0)
	{
		if(write(outputFd,buf,numRead) != numRead){
			fprintf(stderr,"counldn't write whole buffer");
			exit(0);
		}
	}

	if(numRead == -1)
	{
		fprintf(stderr,"read error");
		exit(0);
	}

	if(close(inputFd) == -1)
	{
		fprintf(stderr,"close input error");
		exit(0);
	}

	if(close(outputFd) == -1)
	{
		fprintf(stderr,"close output error");
		exit(0);
	}

	exit(EXIT_SUCCESS);

}
