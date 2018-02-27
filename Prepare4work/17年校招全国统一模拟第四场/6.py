import bisect
import sys
line = sys.stdin
n = int(line.readline().strip())
h = list(map(int,line.readline().strip().split(' ')))
m = int(line.readline().strip())
w = list(map(int,line.readline().strip().split(' ')))
w.sort()
# print(h,w)
count = 0
for i in h:
    index = bisect.bisect_left(w,i)
    if index == len(w) :
        continue
    count += 1
    del w[index]
print(count)