n = int(input())

def getSum(a,i):
    sum = 0
    while a:
        sum += (a%i)
        a = int(a/i)
    return sum

count = 0
for i in range(1,n+1):
    if getSum(i,2) == getSum(i,10):
        count += 1
print(count)