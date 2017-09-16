import requests
import re
import json

def get_one_page(url):
    response = requests.get(url)
    if response.status_code == 200:
        return response.text
    return None

def parse_one_page(html):
    html=re.sub('<br/>.*?<br/>|<script.*?></script>','',html)
    pattern=re.compile('<div.*?id="content">(.*?)</div>',re.S)
    items=re.findall(pattern,html)
    content=items[0]
    content=content.replace('&nbsp;&nbsp;&nbsp;&nbsp;','\n')
#    items=re.sub('<br/>.*?<br/>','',items)
    return content

def write_to_text(content):
    with open('result.txt', 'w') as f:
        f.write(content)

def main():
    url = 'http://www.xs.la/1_1212/738073.html'
    html = get_one_page(url)
    content=parse_one_page(html)
    write_to_text(content)

main()
