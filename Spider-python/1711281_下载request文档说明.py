import os
import re
import time
from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
import sqlite3
from requests.exceptions import RequestException
import random
import pdfkit
import datetime


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
headers = [{'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:57.0) Gecko/20100101 Firefox/57.0'}, \
           {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:57.0) Gecko/20100101 Firefox/57.0'},\
           {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'},\
           {'User-Agent':'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'}
           ]

random.seed(datetime.datetime.now())
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
        self.domain = start_url


    @staticmethod
    def request(url, **kwargs):
        """
        网络请求,返回response对象
        :return:
        """
        try:
            header = headers[random.randint(0,len(headers)-1)]
            response = requests.get(url, headers = header,timeout= 2)
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

    def save_pdf(self, htmls,noveldir):
        """
        将html文件生成pdf文件
        :param htmls: html文件
        :param noveldir: 小说存放路径
        :return:
        """

        raise NotImplementedError

    def run(self):
        start = time.time()
        count = 0
        htmls = []
        datadir = self.store_path + "data"
        noveldir = self.store_path + self.name
        if not os.path.exists(noveldir) :
            os.system('mkdir {}'.format(noveldir))
        if not os.path.exists(datadir) :
            os.system('mkdir {}'.format(datadir))
        recoders = self.parse_menu(self.request(self.start_url))
        for index,recoder in enumerate(recoders):
            # print(index,recoder[1])
            filepath = '{0}/{1}{2}.html'.format(datadir, str(index + 1), recoder[1])
            htmls.append(filepath)
            if os.path.exists(filepath):
                print(index + 1, '{} 已经存在'.format(recoder[1]))
            else:
                print(index + 1, '{} 正在下载'.format(recoder[1]))
                response = self.request(recoder[0])
                if response != None:
                    html = self.parse_body(response)
                    with open(filepath, 'wb') as f:
                        f.write(html)
                    time.sleep(0.5)
                else:
                    print('超时，略过')

        #
        # for recoder in recoders:
        #     count += 1
        #     if count >= 1200:
        #         filepath='{0}/{1}{2}.html'.format(noveldir,str(count),recoder[1])
        #         filename = ''.join([str(count),recoder[1]])
        self.save_pdf(htmls,noveldir)

        total_time = time.time() - start
        print(u"总共耗时：%f 秒" % total_time)

class RequestSpider(Spider):
    """
    Request文档说明下载
    """
    def parse_menu(self, response):
        soup = BeautifulSoup(response.content, "html.parser")
        menu_tag = soup.find(class_ = "section",id = "id3")
        # menu_tag = menu_tag.find_all("li",href=re.compile("^(user/)((?!#).)*$"))
        recoders = []
        for li in menu_tag.find_all("li"):
            url = li.a.get("href")
            if '#' in url:
                continue
            if not url.startswith("http"):
                url = "".join([self.domain, url])
            recoders.append([url,li.a.get_text()])
        return recoders


    def parse_body(self, response):
        soup = BeautifulSoup(response.content, "html.parser")
        content = str(soup.find(id = "content"))
        content = re.sub('<script.*?></script>', '', content)
        html = html_template.format(content = content)
        html = html.encode('utf-8')
        return html

    def save_pdf(self, htmls ,noveldir):
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
        if len(htmls) <= 1000:
            f_name = "{0}/{1}.pdf".format(noveldir,self.name)
            print("开始生成",f_name)
            pdfkit.from_file(htmls,f_name, options=options)
        else:
            for i in range(0,len(htmls),500):
                html = htmls[i : i + 500]
                f_name = "{0}/{1}{2}.pdf".format(noveldir,self.name,str(int(i/500)+1))
                print("开始生成",f_name)
                pdfkit.from_file(html, f_name, options=options)


def main():
    spider_obj = RequestSpider("Request库中文说明文档", \
                 "http://docs.python-requests.org/zh_CN/latest/"\
                 ,"/home/dai/文档/计算机书籍")


    #（scheme = 'http', netloc = 'www.baidu.com', path = 'index.html'paramters = 'user'.query = 'id=5', fragment = 'comment'）
    #res=urlparse('https://www.baidu.com/baidu?wd=query&tn=monline_dg&ie=utf-8')

    reponse = spider_obj.request('http://docs.python-requests.org/zh_CN/latest/index.html#')
    for html in spider_obj.parse_menu(reponse):
        print(html)

    #spider_obj.run()



if __name__ == '__main__':
    main()



