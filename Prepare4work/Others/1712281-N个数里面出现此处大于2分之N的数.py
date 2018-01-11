l = input().split(' ')
d = {}
for n in l:
    if n in d:
        d[n] += 1
    else:
        d[n] = 1
for i in d:
    if d[i] >= len(l)/2:
        print(i)