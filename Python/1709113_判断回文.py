def is_palindrome(n):
    if n>9:
        num=str(n)
        return num==num[::-1]
output=filter(is_palindrome,range(1,1000))
print(list(output))
