import os
import re
import time
from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
import sqlite3
import pdfkit


html_template = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
</head>
<body>
{content}
</body>
</html>
"""


res = requests.get('http://news.sina.com.cn/c/nd/2017-09-09/doc-ifykusey6584342.shtml')
soup = BeautifulSoup(res.content,'html.parser')
article = soup.find(class_= 'article article_16')
article = str(article)
html = html_template.format(content = article)
html = html.encode('utf-8')

with open('news_china.html','wb') as f:
    f.write(html)


options = {
            'page-size': 'Letter',
            'margin-top': '0.75in',
            'margin-right': '0.75in',
            'margin-bottom': '0.75in',
            'margin-left': '0.75in',
            'encoding': "UTF-8",
            'custom-header': [
                ('Accept-Encoding', 'gzip')
            ],
            'cookie': [
                ('cookie-name1', 'cookie-value1'),
                ('cookie-name2', 'cookie-value2'),
            ],
            'outline-depth': 10,
        }


pdfkit.from_file('news_china.html','news.pdf',options=options)
print('succeed')