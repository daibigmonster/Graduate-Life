/*getsockname getpeername函数
这两个函数或者返回与某个套接字关联的本地协议地址(getsockname),或者返回某个套接字关联的外地协议地址，或者返回某个套接字关联的外地协议地址
#include <sys/socket.h>
int getsockname(int sockfd,struct sockaddr *localaddr,socklen_t *addrlen);
int getpeername(int sockfd,struct sockaddr *peeraddr,socklen_t *addrlen);
注意，这两个函数的最后一个参数都是值-结果参数。也就是说，这两个函数都得装填由localaddr或peeraddr指针所指的套接字地址结构
这两个函数返回与某个网络连接的两端中任何一段相关联的协议地址。
需要这两个函数的理由如下所述
在一个没有调用bind的TCP客户上，connect成功返回后,getsockname用于返回由内核赋予该连接的本地IP地址和本地端口号。
在以端口号0调用bind(告知内核去选择本地端口号)后，getsockname用于返回由内核赋予的本地端口号。
getsockname可用于获取某个套接字的地址族
在一个以通配IP地址调用bind的TCP服务器上，与某个客户的连接一旦建立
