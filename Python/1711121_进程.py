from multiprocessing import Process
import os

def run_proc(name) :
    print('Run child process %s (%s)...' % (name,os.getpid()))

if __name__ == '__main__':
    print('Parent process %s.' % os.getpid())
    p = Process(target = run_proc,args = ('test',))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')
#multiprocessing 模块就是跨平台版本的多进程模块
#multiprocessing 模块提供了一个Process类来代表一个进程对象
#
