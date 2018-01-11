import sys
import re

for i in sys.stdin.readlines():
    i = re.sub('\s','',i)
    if len(i) <= 6:
        print(i)
    elif  len(i) <= 14 and len(i) > 6:
        print(i[:6],i[6:])
    else:
        print(i[:6],i[6:14],i[14:])
    