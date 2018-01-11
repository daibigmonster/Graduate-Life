raw_num = input().split(' ')
num = raw_num[1:]

A1 = A2 = A3 = A5 = 0
A4 = 0.0
A2n = A4n = 0

for l in num:
    l = int(l)
    if l%10 == 0:
        A1 += l
    if l%5 == 1:
        A2 += pow(-1,A2n) * l
        A2n += 1
    if l%5 == 2:
        A3 += 1
    if l%5 == 3:
        A4 += l
        A4n += 1
    if l%5 == 4:
        if l > A5:
            A5 = l
if A4 != 0:
    A4 = A4/A4n
    A4 = round(A4,1)

ans = [A1,A2,A3,A4,A5]
for i in range(5) :
    if ans[i] == 0:
        ans[i] = 'N'
    

print(ans[0],ans[1],ans[2],ans[3],ans[4])




