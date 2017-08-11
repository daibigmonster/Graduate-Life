/*inet_ntop的一个基本问题是：它要求调用者传递一个指向某个二进制地址的指针，而该地值通常包行在一个套接字地址结构中，这就要求调用这必须直到这个结构的格式和地址族。也就是说，为了使用这个函数，我们必须为IP4编写如下代码：
struct sockaddr_in addr;
inet_ntop(AF_INET，&addr.sin_addr,str,sinof(str));
或为IP6编写如下代码
struct sockaddr_in6 addr6;
inet_ntop(AF_INET6,&addr6.sin6_addr,str,sizeof(str));
这就使得我们的代码与协议相关了
为了解决这个问题，我们将自行编写一个名为sock_ntop的函数,它以指向某个套接字地址结构的指针为参数，查看该结构的内部，然后调用适当的函数返回该地址的表达格式。
#include "unp.h"
char *sock_ntop(const struct sockaddr *sockaddr,socklen_t addrlen);
sockaddr指向一个长度为addrlen的套接字地址结构。本函数用它自己的静态缓冲区来保存结果，而指向该缓冲区的一个指针就是它的返回值。
表达格式就是在一个IP4地址的点分是十进制数串格式之后，或者在一个括以方括号的IP6地址的十六进制数串格式之后，跟一个终止符（我们使用一个分号），再跟一个是禁止的端口号，最后跟一个空字符。因此缓冲区大小对于IP4至少为INET_ADDRSTRLEN加上6个字节（16+22），对于IP6至少为INET_ADDRSTRLEN加上8个字节（46+8=54）*/
char* sock_ntop(const struct sockaddr *sa,socklen_t salen)
{
    char portstr[8];
    static char str[128];
    switch(sa->safamily){
    case AF_INET:{
        struct sockaddr_in *sin=(struct sockaddr_in *)sa;
        if(inet_ntop(AF_INET,&sin->sin_addr,str,sizeof(str))==NULL)
            return (NULL);
        if(ntohs(sin->sin_port)!=0){
            snprintf(port,sizeof(portstr),":%d",noths(sin->sin_port));
            strcat(str,portstr);
        }
        return (str);
    }
}}
