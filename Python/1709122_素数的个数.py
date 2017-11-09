number=int(input())
def _odd_iter():
    n=1
    while True:
        n=n+2
        yield n
def _not_divisible(n):
	return lambda x:x%n>0
def primes():
    yield 2
    it=_odd_iter()
    while True:
        n=next(it)
        yield n
        it=filter(_not_divisible(n),it)
count=0
for n in primes():
    if n<number:
        count+=1
    else:
        break
print(count)
