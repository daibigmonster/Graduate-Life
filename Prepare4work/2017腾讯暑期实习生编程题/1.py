# 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
# 输出需要删除的字符个数。

# 输入描述:


# 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  



# 输出描述:


# 对于每组数据，输出一个整数，代表最少需要删除的字符个数。


# 输入例子1:

# abcda
# google
# // 输出例子1:

# // 2
# // 2

Lengths = [1]

def getLength(s):
    if len(s) == 1:
        pass
    elif s == s[::-1]:
        Lengths.append(len(s))
    else:
        for i in range(len(s)):
            s1 = s[:i] + s[i + 1:]
            # print(s1)
            getLength(s1)
    
s = str(input())
getLength(s)
# print(Lengths)
print(len(s) - max(Lengths))


