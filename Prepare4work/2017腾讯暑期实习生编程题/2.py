#  小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
# 你能帮帮小Q吗？



# 输入描述:


# 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  



# 输出描述:


# 对于每组数据，输出移位后的字符串。


# 输入例子1:

# AkleBiCeilD


# 输出例子1:

# kleieilABCD
def getString(l):
    length = len(l)
    Biggerwords =[]
    for i in l:
        if 'A' <= i and i <= 'Z':
            Biggerwords.append(i)

    for i in Biggerwords:
        l.remove(i)

    l = "".join(l)
    res = l + "".join(Biggerwords)
    return res

while True:
    try:
        l = list(input().strip())
        print(getString(l))
    except:
        break
# def main():
#     while 
#         ans = getString(l)
#         print(ans)

# if __name__ == '__main__':
#     main()

