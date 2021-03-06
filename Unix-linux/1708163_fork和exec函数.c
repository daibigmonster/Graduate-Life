/*在阐述如何并写并发服务器程序之前，我们必须首先介绍一些UNIX的fork函数。
该函数（包括有些系统可能提供它的各种变体）是Unix中派生新进程的唯一方法。
#include<unistd.h>
pid_t fork(void)
理解fork最困难指出在于调用它一次，它却返回两次。它在调用进程（成为父进程）中返回一次，返回值是新派生进程（成为子进程）的进程ID号;在子进程又返回一次，返回值为0.因此，返回值本身告知当前进程是子进程还是父进程。
fork在子进程返回0而不是父进程的进程ID在于：任何子进程都只有一个父进程，而子进程总是可以通过调用getppid取得父进程的进程ID。相反，父进程可以有许多子进程，而且无法获取每个子进程的进程ID。如果父进程想要跟踪所有子进程的进程ID，那它必须记录每次调用fork的返回值。
父进程中调用fork之前打开的所有描述父在fork返回之后由子进程分享。我们将看到网络服务器利用了这个特性：父进程调用了accept之后调用fork.所接受的已连接套接字随后就在父进程与子进程之间共享。通常情况下，子进程接着读写这个已连接套接字，父进程则关闭这个已连接套接字。
fork有两个典型用法
1一个进程创建一个自身的副本，这样每个副本都可以在另一个副本执行其他任务的同时处理各自的某个操作。这是网络服务器的典型用法
2一个进程想要执行另一个程序，既然闯进新近成的唯一办法是调用fork,改进成于是首先调用fork创建一个自身的副本，然后其中一个副本（通常为子进程）调用exec(接下去介绍)把自身替换成新的程序。这是诸如shell之类程序的典型用法。
存放在硬盘上可执行文件能够被UNIX执行的唯一方法是：由一个现有进程调用6个exec函数中的某一个。exec把当前进程映像替换成新的程序文件，而且该新程序通常从main函数开始执行。进程ID并不变。我们成调用exec的进程为调用进程。称新执行的程序为新程序*/

