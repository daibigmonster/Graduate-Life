/*服务器主机崩溃
我们接着查看当服务器主机崩溃时会发生什么。为了模拟这种情形，我们必须在不同的主机上运行客户和服务器。我们先启动服务器，再启动客户,接着在客户上键入一行文本以确认连接工作正常，然后从网络上断开服务器主机，并在客户上键入另一文本。这样同时也模拟了当客户发送数据时服务器主机不可达的情形
步骤如下所述。
荡妇武器主机崩溃是，已有的网络连接上步伐出任何东西。这里我们假设的是主机崩溃。而不是由操作员执行命令关机
2我们在客户上键入一行文本，它由writen写入内核，再由客户TCP作为一个数据分节送出。客户随后阻塞与readline调用，等待回射的应答
3如果我们用tcpdump观察网络就会发生，客户TCP持续重传数据分节，试图从服务器上接收一个ACK。原子Berkeley的实现重传该数据分节12此，共等待约9分钟才放弃重传。党课互TCP最后终于放弃时，给客户进程返回一个错误。既然客户阻塞在readline调用上，该调用将返回一个错误。假设服务器主机已崩溃，从而对客户的数据分节没有相应，那么返回的错误是ETIMEOUT。然而如果某个中间路由器判断服务器主机已不可达，从而响应一个“destionation unreachable”ICMP消息，那么返回的错误是EHOSTUNREACHhuoENETUTEACH
尽管我们的客户最终还是会发现对端主机已崩溃或不可达，不过有时候我们需要比不得不等待9分钟更快地检测出这种情况。所用的方法就是对readline调用设置一个超时
我们刚刚讨论的情形只有在我们想服务器主机发送数据时才能检测它已经崩溃。如果我们不主动向它发送数据也想检测出服务器主机崩溃，那么需要采用另外一个技术。

服务器主机崩溃后重启
在这种情形中，我们现在客户与服务器之间建立连接，然后假设服务器主机崩溃并重启。前一节中，当我们发送数据时，服务器主机依然处于崩溃状态;本节中，我们将在发送数据前重新启动已经本亏的服务器主机。模拟这种情形的最简单的方法是：先建立连接，再从网络上断开服务器主机，将它关机后重新启动，最后把它重新连接到网络中。
正如前一节所属，如果在服务器主机崩溃时客户不主动给服务器发送数据，那么客户将不知道服务器主机已经崩溃。所发生的步骤如下
1我们重启服务器和客户，并在客户键入一行文本确认连接已建立
2服务器主机崩溃重启
3在客户键入一行文本，它将作为一个TCP数据分节发送到服务器主机
4当服务器主机崩溃后重启时，它的TCP丢失了崩溃前的所以连接信息，因此服务器TCP对于所收到的来自客户的数据分节相应一个RST
5当客户TCP收到该RST，客户正阻塞于readline调用，导致该调用返回ECONNRESET错误
如果对客户而言检测服务器崩溃与否很重要，即使客户不住发送数据也要能检测出来，就需要其他某种技术

服务器主机关机
当我们的服务器进程正在运行时，服务器主机本操作员关机将会发生什么？
Unix系统关机时，init进程通常先给所有进程发送SIGTERM信号（该信号可被捕获），等待一段固定的时间，然后给所有仍在运行的进程发送SIGKILL信号（该信号不能被捕获）。这么做留给所有运行的进程一小段时间来清楚和终止。如果我们不捕获SIGTERM信号并重值，我们的服务器将由SIGKILL信号终止。当服务器子进程终止时，他的所有打开这的描述符都被关闭
