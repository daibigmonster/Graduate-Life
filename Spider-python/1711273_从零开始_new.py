import os
import re
import time
from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
import sqlite3
from requests.exceptions import RequestException

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


class Spider(object):
    """
        爬虫基类，所有爬虫都应该继承此类
        """
    name = None
    start_url = None
    store_path = None

    def __init__(self, name, start_url, store_path):
        """
        初始化
        :param :解析的url
        :return：html
        """
        self.name = name
        self.start_url = start_url
        if(store_path.endswith('/')):
            self.store_path = store_path
        else:
            self.store_path = ''.join([store_path,'/'])
        self.domain = '{uri.scheme}://{uri.netloc}'.format(uri=urlparse(self.start_url))


    @staticmethod
    def request(url, **kwargs):
        """
        网络请求,返回response对象
        :return:
        """
        try:
            headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:57.0) Gecko/20100101 Firefox/57.0'}
            response = requests.get(url, headers = headers,timeout= 2)
            return response
        except RequestException:
            print('出现异常')
            return None

    def parse_menu(self, response):
        """
        从response中解析出所有目录的URL链接
        """
        raise NotImplementedError

    def parse_body(self, response):
        """
        解析正文，由子类实现
        :param response:爬虫返回的response对象
        :return: 返回经过处理的html正文文本
        """
        raise NotImplementedError

    def save_pdf(self, htmls):
        """
        将html文件生成pdf文件
        :param htmls: html文件
        :param file_name: 文件名
        :return:
        """

        raise NotImplementedError

    def run(self):
        start = time.time()
        count = 0
        noveldir = self.store_path + self.name
        if not os.path.exists(noveldir):
            os.system('mkdir {}'.format(noveldir))
        recoders = self.parse_menu(self.request(self.start_url))
        htmls = []
        for recoder in recoders:
            count += 1
            filepath='{0}/{1}{2}.html'.format(noveldir,str(count),recoder[1])
            filename = ''.join([str(count),recoder[1]])
            if os.path.exists(filepath):
                print(count, '{} 已经存在'.format(recoder[1]))
            else:
                print(count, '{} 正在下载'.format(recoder[1]))
                response = self.request(recoder[0])
                if response != None:
                    html = self.parse_body(response)
                    with open(filepath, 'wb') as f:
                        f.write(html)
                    time.sleep(0.5)
                    htmls.append(filename)
                else:
                    print('超时，略过')
                    continue

        self.save_pdf(htmls)
        total_time = time.time() - start
        print(u"总共耗时：%f 秒" % total_time)

class LingaoqimingSpider(Spider):
    """
    临高启明下载
    """
    def parse_menu(self, response):
        soup = BeautifulSoup(response.content, "html.parser")
        menu_tag = soup.find(id = "list")
        recoders = []
        for dd in menu_tag.find_all("dd"):
            url = dd.a.get("href")
            if not url.startswith("http"):
                url = "".join([self.domain, url])
            recoders.append([url,dd.get_text()])
        return recoders

    def parse_body(self, response):
        soup = BeautifulSoup(response.content, "html.parser")
        content = str(soup.find(id = "content"))
        #content = re.sub('<br/>.*?<br/>', '\n',content)
        content = re.sub('<script.*?></script>', '', content)
        #content = content.replace('<div id="content">','')
        #content = content.replace('</div>','')
        html = html_template.format(content = content)
        html = html.encode('utf-8')
        return html

    def save_pdf(self, htmls):
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
        pdfkit.from_file(htmls,''.join(self.store_path,self.name,".pdf"), options=options)
        for html in htmls:
            os.remove(html)

def main():
    start_url = 'http://www.xs.la/2_2691/'  # 小说的首页，从首页就可以抓取目录
    # start_url = 'http://www.xs.la/1_1212/4931181.html'  # 小说的首页，从首页就可以抓取目录
    spider_obj = LingaoqimingSpider("从零开始", start_url,'/home/dai/文档/小说')
    #spider_obj = spider_obj.parse_body(spider_obj.request("http://www.xs.la/1_1212/738232.html"),"测试")
    spider_obj.run()

if __name__ == '__main__':
    main()
