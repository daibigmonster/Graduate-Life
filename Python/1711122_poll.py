# 如果要启动大量的紫禁城，可以用进程池的方式批量创建子进程

from multiprocessing import  Pool
import os,time,random

def long_time_task(name) :
    print('Run task %s (%s)...' % (name,os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print('Task %s runs %0.2f seconds.' % (name,(end - start)))

if __name__ == '__main__' :
    print('Parent process %s.' % os.getpid())
    p = Pool(4)
    for i in range(5):
        p.apply_async(long_time_task,args = (i,))
    print('Waiting for subprocesses done...')
    p.close()
    p.join()
    print('All subprocesses done.')
'''
# 子进程
# 很多时候，子进程并不是自身，而是一个外部进程。我们创建了子进程后，还需要
要控制子进程的输入和输出
subprocess可以让我们非常方便地启动一个子进程，然后控制其输入和输出
'''

import  subprocess
print('$ nslookup www.python.org')
r = subprocess.call(['nslookup','www.python.org'])
print('Exit code:',r)

# 如果子进程还需要输入，则可以通过communicate()输入：
p = subprocess.Popen(['nslookup'],stdin = subprocess.PIPE,\
    stdout = subprocess.PIPE,stderr = subprocess.PIPE)