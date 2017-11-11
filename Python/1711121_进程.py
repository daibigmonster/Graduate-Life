import os
print('进程 (%s) 开始...' % os.getpgid())
pid = os.fork()
if pid == 0 :
    print('I am child process (%s) and my parent is %s.' % (os.getpid(),\
    os.getppid()))