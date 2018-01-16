# 输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2

import math
n = int(input())
numstr = str(math.factorial(n))
count = 0
 
for i in range(-1,-len(numstr) - 1, -1):
    if numstr[i] == '0':
        count += 1
    else:
        break
 
print(count)
