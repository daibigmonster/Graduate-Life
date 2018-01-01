# -*- coding: utf-8 -*-

from functools import reduce
def str2float(s):
    s1,s2=s.split('.')
    def char2num(a):
        return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[a] 
    def num2int(x,y):
        return x*10+y   
    def mul(n):
        a=1
        while n:
           a=a*10
           n=n-1
        return a
    a=reduce(num2int,map(char2num,s1))
    b=reduce(num2int,map(char2num,s2))/mul(len(s2))
    return a+b
print(str2float('123.456'))
