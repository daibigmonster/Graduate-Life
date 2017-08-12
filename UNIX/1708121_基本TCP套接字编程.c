/*
socket函数
为了执行网络IO，一个进程必须做的第一件事情就是调用socket函数，指定期望的通信协议类型（使用IP4的TCP、使用IP6的UDP、UNIX域字节诶流协议等）
#include<sys/socket.h>
int socket(int family,int tyoe,int protocol) 
其中family参数指明协议族，。该参数也往往被称为协议域，type参数指明套接字类型protocol参数应设为某个协议类型常值，或者设为0,一选择给定family和type组合的系统默认值
family     说明
AF_INET    IP4协议
AF_INET6   IP6协议
AF_LOCAL   unix域协议
AF_ROUTE   路由套接字
AF_KEY     密钥套接字
type       说明
SCOK_STREAM字节流套接字
SCOK_DGRAM 数据包套接字
SOCK_SEQPACKET 有序分组套接字
SCOK_RAW   原始套接字
protocol   说明
IPPROTO_CP TCP传输协议
IPPROTO_UDPUDP传输协议
IPPROTO_SCTP SCTP传输协议
socket函数在成功时返回一个小的非负整数值，它与文件描述符类似，我们把它称为套接字描述符，简称socketfd.为了得到这个套接字描述符，我们只是指定了协议族和套接字类型。
connect函数
TCP客户用connect函数来建立与TCP服务器的连接
#Include <sys/socket.h>
int connect(int sockfd,const struct sockaddr *servaddr,socklen_t addrlen)
bind函数
bind函数把一个本地协议地址赋予一个套接字，对于网际网协议，协议地址是32位的IP4地址或128位IP6地址与16为的TCP或UDP端口号的组合
#include<sys/socket.h>
int bind(int sockfd,const sockaddr *myaddr,socklen_t addrlen);
进程可以把一个特定的IP地址捆绑到它的套接字上，不过这个IP地址必须术语其所在主机的网络接口之一。不过这个IP地址必须属于其所在之际的网络接口之一。对于TCP客户，这久违在该套接字上发送的IP数据包指派了源IP地址。对于TCP服务器，这就限定该套接字值接收那些目的地为这个IP地址的客户连接。TCP客户通常不把IP地址捆绑到它的套接字上。当连接套接字时，内核根据所用外出网络接口来选择源IP地址。而所用外出接口则取决于到达服务器所需的路径。如果TCP服务器没有把IP地址捆绑到它的套接字上，内核就把客户发送的SYN的目的IP地址作为服务器的源IP地址。
正如我们所说，调用bind可以指定IP地址或端口，可以两者都指定，也可以不指定
如果指定端口号为0,那么内核就在bind被调用时选择一个临时端口。然而如果定制IP地址为通配地址，那么内核将等到套接字已连接（TCP）或已在套接字上发出数据包（UDP）是才选择一个本地IP地址
对于IP4来说，通配地址由常值INADDR_ANY来指定，其值一般为0,它告知内核去选择IP地址。我们曾经看到过它的使用;
struct sockaddr_in servaddr;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
如此赋值对IP4是可行的，因为饿其IP地址是一个32位的值，可以用一个简单的数字常值表示，对于IP6我们就不能这么做了，因为128位IP6地址是存放在一个结构中的。
