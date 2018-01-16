# 给定一个有n个正整数的数组A和一个整数sum,求选择数组A中部分数字和为sum的方案数。
# 当两种选取方案有一个数字的下标不一样,我们就认为是不同的组成方案。
# 输入描述:

# 输入为两行:
#  第一行为两个正整数n(1 ≤ n ≤ 1000)，sum(1 ≤ sum ≤ 1000)
#  第二行为n个正整数A[i](32位整数)，以空格隔开。



# 输出描述:

# 输出所求的方案数


# 输入例子1:

# 5 15 
# 5 5 10 2 3


# 输出例子1:

# 4
n,target = map(int,input().split())
A = list(map(int,input().split()))

dp = [[0] * (target + 1)] * (n + 1)
for i in range(1,n):
    dp[i][0] = 1
print(dp) 
for i in range(1,n + 1):
    for j in range(target + 1):
        # print(i,j)
        if A[i - 1] <= j:
            dp[i][j] = dp[i - 1][j - A[i - 1]] + dp[i - 1][j]
        else :
            dp[i][j] = dp[i - 1][j]
        # print(i,j)
        # print(dp)

print(dp)
print(dp[n][target])

