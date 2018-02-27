import itertools
n,k = list(map(int,input().strip().split()))
 
count = 0
for comb in list(itertools.combinations(range(n),k)) :
    if sum(comb)%n == 0 :
        count += 1
 
print(count)