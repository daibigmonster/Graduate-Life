import re
str = input()
for i in range(len(str)):
    if str[i].isalpha():
        pattern = str[i] + '{1,}'
        if len(re.findall(pattern,str[:i+1],re.M)) == 3 :
            print(str[i])
            break
    
    
