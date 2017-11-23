# asyncio的编程模型就是一个消息循环。我们从asyncio模块中直接获取一个EventLoop
# 的引用,然后把需要执行的协程扔到EventLoop中执行，就实现了异步IO
# 用asyncio实现Hello world代码如下
import asyncio
import threading


@asyncio.coroutine
async def hello():
    print("Hello world!(%s)" % threading.currentThread())
    #异步调用asynico.sleep(1)
    r = await asyncio.sleep(4)
    print("Hello world!(%s)" % threading.currentThread())


#获取Eventloop
loop = asyncio.get_event_loop()
tasks = [hello(),hello()]
#执行coroutine
loop.run_until_complete(asyncio.wait(tasks))
loop.close()




