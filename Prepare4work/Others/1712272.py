import re
ans = re.match('.*?\.(\w+)',input())
if ans != None:
    print(ans.group(1))
else:
    print('null')