num = sorted(list(map(int,input().split())))
# print(num[987:997])

count = 1
ans = []
for i in range(9997):
    if count == 4:
        break
    if i + count != num[i]:
        ans.append(num[i] - 1)
        count += 1
print(int("".join(list(map(str,ans)))) % 7)
