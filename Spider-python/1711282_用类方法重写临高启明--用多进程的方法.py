import os
import re
import time
from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
import sqlite3
from requests.exceptions import RequestException
import pdfkit
import click
from multiprocessing import Process
from multiprocessing import Pool
import random
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
            header = headers[random.randint(0, len(headers) - 1)]
            response = requests.get(url, headers=header, timeout=2)
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


    def multi_process_download(self,num,recoders,datadir):
        for index,recoder in enumerate(recoders):
            # print(index,recoder[1])
            index += (num + 1)
            filepath = '{0}/{1}{2}.html'.format(datadir, str(index), recoder[1])
            if os.path.exists(filepath):
                print(index, '{} 已经存在'.format(recoder[1]))
            else:
                print(index, '{} 正在下载'.format(recoder[1]))
                response = self.request(recoder[0])
                if response != None:
                    html = self.parse_body(response)
                    with open(filepath, 'wb') as f:
                        f.write(html)
                    time.sleep(0.5)
                else:
                    print('超时，略过')

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
        htmls = []
        datadir = self.store_path + "data"
        noveldir = self.store_path + self.name
        if not os.path.exists(noveldir) :
            os.system('mkdir {}'.format(noveldir))
        if not os.path.exists(datadir) :
            os.system('mkdir {}'.format(datadir))
        recoders = self.parse_menu(self.request(self.start_url))


        #多进程下载过程
        for i in range(6):
            #因为经常有没有下载成功的情况所以多次下载
            if len(recoders) <= 500:
                self.multi_process_download(0,recoders,datadir)
            else:
                p = Pool(3)
                for i in range(0,len(recoders),500):
                    recoder = recoders[i: i + 500]
                    p.apply_async(self.multi_process_download, args=(i,recoder,datadir))
                print('Waiting for all subprocesses done...')
                p.close()
                p.join()
                print('All subprocesses done.')

        #转换成pdf
        for index, recoder in enumerate(recoders):
            index += 1
            filepath = '{0}/{1}{2}.html'.format(datadir, str(index), recoder[1])
            htmls.append(filepath)
        self.save_pdf(htmls,noveldir)
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
        try:
            soup = BeautifulSoup(response.content, "html.parser")
            body = soup.find(id = "content")

            #加入标题居中显示
            title = str(soup.find(class_ = 'bookname'))
            title = re.findall("<h1>(.*?)</h1>",title)[0]
            center_tag = soup.new_tag("center")
            title_tag = soup.new_tag('h1')
            title_tag.string = title
            center_tag.insert(1, title_tag)
            body.insert(0, center_tag)

            content = str(body)
            content = re.sub('<script.*?></script>', '', content)
            html = html_template.format(content = content)
            html = html.encode('utf-8')
            return html
        except Exception as e:
            logging.error("解析错误", exc_info=True)

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


# @click.command()
# @click.option('--filename', prompt='输入PDF文件的保存名称', help='不需要后缀.pdf，只需要提供名称即可')
# @click.option('--url', prompt='输入要爬取的网页地址', help='需要爬去的网页的目录地址')
# @click.option('--storepath', prompt='输入PDF文件的保存地址', help='保存文件的绝对路径')
# def main(filename,url,storepath):
#     spider_obj = LingaoqimingSpider(filename, url,storepath)
#     spider_obj.run()
# def main():
#     filename = '临高启明'
#     url = 'http://www.xs.la/1_1212/'
#     storepath = '/home/daimonster/文档/小说'
#     spider_obj = LingaoqimingSpider(filename, url,storepath)
#     spider_obj.run()
def main():
    filename = '从零开始'
    url = 'http://www.xs.la/2_2691/'
    storepath = '/home/daimonster/文档/小说'
    spider_obj = LingaoqimingSpider(filename, url,storepath)
    spider_obj.run()


if __name__ == '__main__':
    main()



