import requests
import re
import json

def get_one_page(url):
    response = requests.get(url)
    if response.status_code == 200:
        return response.text
    return None

def parse_one_page(html):
    pattern=re.compile('<dd>.*?href="(.*?)">(.*?)</a></dd>',re.S)
    items=re.findall(pattern,html)
    for item in items:
         yield {
            '网址': item[0],
            '章节名': item[1]
        }

def write_to_json(content):
    with open('result.txt', 'ab') as f:
        f.writeline(json.dumps(content, ensure_ascii=False,).encode('utf-8'))

def main():
    url = 'http://www.xs.la/1_1212/'
    html = get_one_page(url)
    for item in parse_one_page(html):
        write_to_json(item)

main()
