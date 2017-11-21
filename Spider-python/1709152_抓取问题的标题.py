import requests

import re

headers={'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'}

#r=requests.get("https://www.zhuhu.com/explore",headers=headers)
r = requests.get("https://www.zhihu.com/explore", headers=headers)
#下面是正则表达式，我在之后学习，这里我看不懂。。

pattern = re.compile('explore-feed.*?question_link.*?>(.*?)</a>', re.S)
titles=re.findall(pattern,r.text)

print(titles)
