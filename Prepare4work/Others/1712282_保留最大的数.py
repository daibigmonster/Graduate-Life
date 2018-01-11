num = list(input())
cnt = int(input())
length,i = len(num),0

while cnt and i < length - 1:
    if num[i] >= num[i + 1]:
        i += 1
    else:
        num.pop(i)
        cnt -= 1
        length -= 1
        i = i - 1 if i > 0 else 0
if cnt > 0:
    num = num [:-cnt]
print(''.join(num))
