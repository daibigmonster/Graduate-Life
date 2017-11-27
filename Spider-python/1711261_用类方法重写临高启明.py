import os
import re
import time
from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
import sqlite3

class Spider(object):
    """
        爬虫基类，所有爬虫都应该继承此类
        """
    name = None
    start_url = None

    def __init__(self, name, start_url):
        """
        初始化
        :param :解析的url
        :return：html
        """
        self.name = name
        self.start_url = start_url
        self.domain = '{uri.scheme}://{uri.netloc}'.format(uri=urlparse(self.start_url))

    @staticmethod
    def request(url, **kwargs):
        """
        网络请求,返回response对象
        :return:
        """
        headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:57.0) Gecko/20100101 Firefox/57.0'}
        response = requests.get(url, headers = headers)
        return response

    def parse_menu(self, response):
        """
        从response中解析出所有目录的URL链接
        """
        raise NotImplementedError

    def parse_body(self, response,text_name):
        """
        解析正文，由子类实现
        :param response:爬虫返回的response对象
        :return: 返回经过处理的html正文文本
        """
        raise NotImplementedError

    def run(self):
        start = time.time()
        count = 0
        noveldir = '/home/daimonster/文档/小说/' + self.name
        if not os.path.exists(noveldir):
            os.system('mkdir {}'.format(noveldir))
        recoders = self.parse_menu(self.request(self.start_url))
        for recoder in recoders:
            count += 1
            bookpath='{0}/{1} {2}.txt'.format(noveldir,str(count),recoder[1])
            if os.path.exists(bookpath):
                print(count, '已经存在，略过')
            else:
                print(count, '正在下载')
                response = self.request(recoder[0])
                if response != None:
                    self.parse_body(response,bookpath)
                    time.sleep(0.5)
                else:
                    print('超时，略过')
                    continue
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

    def parse_body(self, response ,bookpath):
        soup = BeautifulSoup(response.content, "html.parser")
        content = str(soup.find(id = "content"))
        content = re.sub('<br/>.*?<br/>', '\n',content)
        content = re.sub('<script.*?></script>', '', content)
        content = content.replace('<div id="content">','')
        content = content.replace('</div>','')
        with open(bookpath, 'w') as f:
            f.write(content)
        #content = content.get_text()
        # content = content.get_text()
        #content = content.get("br")
        # content = re.sub("&nbsp.*?","\t\n",content)
        # content = re.sub('<br/>.*?<br/>', '\n',str(content))
        #     # content.join([str(child.get_text()),'\n'])
        #     print(child)
        #     child = re.sub('<br/>.*?<br/>', '',str(child))
        # words = []
        # print(content.get_text())

def main():
    start_url = 'http://www.xs.la/1_1212/'  # 小说的首页，从首页就可以抓取目录
    # start_url = 'http://www.xs.la/1_1212/4931181.html'  # 小说的首页，从首页就可以抓取目录
    spider_obj = LingaoqimingSpider("临高启明", start_url)
    #spider_obj = spider_obj.parse_body(spider_obj.request("http://www.xs.la/1_1212/738232.html"),"测试")
    spider_obj.run()

if __name__ == '__main__':
    main()