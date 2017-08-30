#include "apue.h"
#include <dirent.h>
int main(int argc,char *argv[]){
	DIR *dp;
	struct dirent *dirp;
	if(argc!=2)err_quit("usage: ls directory_name");
	if((dp=opendir(argv[1]))==NULL)
		err_sys("can't open %s",argv[1]);
	while((dirp=readdir(dp))!=NULL)
		printf("%s\n",dirp->d_name);
	closedir(dp);
	exit(0);
}
/*在程序中，由很多细节诶需要考虑。
首先，其中包含了一个头文件apue.h 本书中几乎每个程序都包含此头文件，它包含了某些标准系统头文件，定义了许多常量及函数原型
接下来，我们包含了一个系统头文件dirent.h,以便使用opendir和readdie的函数原型，以及dirent结构的定义。在其他一些系统里，这些定义被分成多个头文件
程序获取命令行的第一个参数argv[1]作为要列出其各个目录项的目录名。第7章将说明main函数如何被调用，程序如何存取命令行参数和环境变量
因为各种不同UNIX系统目录想的实际格式是不一样的，所以是函数opendie、readdir和closedir对目录进行处理
opendir函数返回指向DIR结构的指针，我将将该指针传送给readdir函数。我们并不关心DIR结构中包含了什么。然后，在循环中调用readdir来读每个目录想。它返回一个指向dirent结构的指针，而当目录中已无目录想可读时返回null指针。在dirent结构中取出的只是每个目录项的名字(d_name)。使用该名字，此后就可调用stat函数以获得该文件的所有属性
程序调用了两个自编的函数对错误进行处理：err_sys和err_quit。从上面的输出中可以看到，err_sys函数打印一条消息（"Permission deenied"或""Not a directory"），说明遇到了什么类型的错误
当程序结束是，它以参数0调用函数exit.函数exit终止程序。按管理，参数0的意思是正常结束，参数值1～255则表示出错。*/
