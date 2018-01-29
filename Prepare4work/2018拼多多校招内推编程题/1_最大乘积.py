# // 给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
# // 输入描述:

# // 无序整数数组A[n]
# // 输出描述:

# // 满足条件的最大乘积

# // 输入例子1:

# // 3 4 1 2
# // 输出例子1:

# // 24
import sys
N = int(sys.stdin.readline().strip())
line = sys.stdin.readline().strip().split()
line = [int(i) for i in line]
if N < 3:
    res = 1
    for i in line:
        res *= i
else:
    line.sort()

    left = line[0] * line[1]
    right = line[-3] * line[-2]

    if left > right:
        res = left * line[-1]
    else :
        res = right * line[-1]

print(res)