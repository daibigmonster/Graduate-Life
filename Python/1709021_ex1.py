from datetime import datetime
import functools

def logggg(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw),print('call %s()' % func.__name__)
    return wrapper

@logggg
def now():
    print('2015-3-25')
    print(datetime.now())

now()

def logger(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator


@logger('DEBUG')
def today():
    print('2015-3-25')

today()
print(today.__name__)


def log(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args,**kw):
            print('%s %s()' % (text,func.__name__))
            return func(*args,**kw),print('%s %s()' % ('end call',func.__name__))
        return wrapper
    return decorator


@log('')
def now():
    print(datetime.now())
now()