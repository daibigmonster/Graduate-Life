# 要一次解码具有独一无二字符的数字，具有这样特点的数字有五个分别是zero(z),two(w),four(u),six(x),eight(g),
# 只要数相应独特的字符的个数就能得到多少个相应的数字
# 得到这些数字之后，就会有另外的数字也会能得出，three(t),five(f),
# five有了之后于是就只有seven有v 
# 剩下的one和nine就有了相应的数字
# 接下来就是将得出的数字转换回去

import sys

def NumConvert(s):
    result = [0] * 10
    result[0] = s.count("Z")
    result[2] = s.count("W")
    result[4] = s.count("U")
    result[6] = s.count("X")
    result[8] = s.count("G")
    result[3] = s.count("T") - result[8] - result[2]
    result[5] = s.count("F") - result[4]
    result[7] = s.count("V") - result[5]
    result[1] = s.count("O") - result[0] - result[2] -result[4]
    result[9] = s.count("I") - result[5] - result[6] - result[8]
    res,ans = "",""
    for i in range(len(result)):
        res += result[i] * str(i)
    for i in res:
        ans += str((int(i) + 2) % 10)
    return ''.join(sorted(ans))

for i in sys.stdin.readlines():
    if i[0].isalpha():
        print(NumConvert(i.strip()))
