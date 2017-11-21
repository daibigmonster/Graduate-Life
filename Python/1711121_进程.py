from multiprocessing import Process
from multiprocessing import Pool
import os,time,random

print("Procss (%s) start..." % os.getpid())
pid = os.fork()

if pid == 0:
    print('I am child process (%s) and my parent is %s.' % (os.getpid(), os.getppid()))
else:
    print('I (%s) just created a child process (%s).' % (os.getpid(), pid))


def run_proc(name) :
    print('Run child process %s (%s)...' % (name,os.getpid()))

if __name__ == '__main__':
    print('Parent process %s.' % os.getpid())
    p = Pool(4)
    for i in range(9):
        p.apply_async(long_time_task,args = (i,))
    print('Waiting for all subprocess done...')
    p.close()
    p.join()
    print('All subprocess end.')
#multiprocessing 模块就是跨平台版本的多进程模块
#multiprocessing 模块提供了一个Process类来代表一个进程对象
#
