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
import logging
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


session = requests.Session()

class Crawler(object):
    """
    爬虫基类，所有爬虫都应该继承此类
    """
    name = None
    start_url = None
    datapath = None

    def __init__(self,name, start_url, store_path,datapath):
        """
        初始化
        :param :解析的url
        :return：html
        """
        self.name = name
        self.start_url = start_url
        if (store_path.endswith('/')):
            self.store_path = store_path
        else:
            self.store_path = ''.join([store_path, '/'])
        self.domain = '{uri.scheme}://{uri.netloc}'.format(uri=urlparse(self.start_url))
        self.datapath = datapath

    @staticmethod
    def request(url, **kwargs):
        """
        网络请求,返回response对象
        :return:
        """
        try:
            headers = {
                'Cookies': 'BAIDUID=9F1E7083263975E4E9FB25DD21CE95A2:FG=1; BIDUPSID=9F1E7083263975E4E9FB25DD21CE95A2; PSTM=1510144024; HMACCOUNT=11D0A7324DF0DFD8; BDUSS=xMZU9LU0N-TnRpaGd3cWFQWEJaMHJ6dllGSjRBTlB4eXBlVnBvRGQydkluU3BhSVFBQUFBJCQAAAAAAAAAAAEAAAAt6RAKZGoxOTg5MDIxOQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMgQA1rIEANaME; BDORZ=B490B5EBF6F3CD402E515D22BCDA1598; cflag=15%3A3; H_PS_PSSID=1453_21106_25177_22075; BDRCVFR[feWj1Vr5u3D]=I67x6TjHwwYf0; PSINO=1',
                'Referer': 'https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/0014317848428125ae6aa24068b4c50a7e71501ab275d52000',
                'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:57.0) Gecko/20100101 Firefox/57.0'}
            response = session.get(url, headers=headers,timeout=2)
            while response.status_code == 503:
                now = datetime.datetime.now()
                print("%s 已经被屏蔽" % now.strftime('%H:%M'))
                time.sleep(600)
                response = session.get(url, headers=headers, timeout=2)
            return response
        except RequestException:
            print("出现异常")
            return None

    def recode_to_sql(self,recoders):
        """
        将教程的目录记录进数据库中
        :return:
        """
        raise NotImplementedError

    def get_from_sql(self):
        """
        将数据库中的目录读出来
        :return:
        """
        raise NotImplementedError

    def parse_menu(self,response):
        """
        从response中解析出所有目录的URL链接
        """
        raise NotImplementedError

    def parse_body(self,response):
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
            filepath = '{0}/{1}{2}.html'.format(datadir, str(index), recoder[0])
            if os.path.exists(filepath):
                #print(index, '{} 已经存在'.format(recoder[1]))
                pass
            else:
                print(index, '{} 正在下载'.format(recoder[0]))
                response = self.request(recoder[1])
                if response is not None:
                    html = self.parse_body(response)
                    with open(filepath, 'wb') as f:
                        f.write(html)

                    time.sleep(5)
                else:
                    print('超时，略过')
                    pass

    def save_pdf(self,htmls,file_name):
        """
        把所有html文件保存到pdf文件
        :param htmls:  html文件列表
        :param file_name: pdf文件名
        :return:
        """
        raise NotImplementedError

    def run(self):
        start = time.time()
        htmls = []
        datadir = self.store_path + "data"
        noveldir = self.store_path + self.name
        #判断书籍存放的地址是否存在
        if not os.path.exists(noveldir):
            os.system('mkdir {}'.format(noveldir))
        if not os.path.exists(datadir):
            os.system('mkdir {}'.format(datadir))

        recoders = self.get_from_sql()
        #进行文档下载
        if len(recoders) <= 500:
            self.multi_process_download(0, recoders, datadir)
        else:
            p = Pool(3)
            for i in range(0, len(recoders), 500):
                recoder = recoders[i: i + 500]
                p.apply_async(self.multi_process_download, args=(i, recoder, datadir))
            print('Waiting for all subprocesses done...')
            p.close()
            p.join()
            print('All subprocesses done.')

        # 转换成pdf
        for index, recoder in enumerate(recoders):
            index += 1
            filepath = '{0}/{1}{2}.html'.format(datadir, str(index), recoder[0])
            htmls.append(filepath)
        self.save_pdf(htmls, noveldir)
        total_time = time.time() - start
        print(u"总共耗时：%f 秒" % total_time)

class LiaoxuefengPythonCrawler(Crawler):
    """
    廖雪峰课程的下载
    """
    def parse_menu(self,response):
        """
        解析目录结构，获取所有的URL目录列表
        :param response: 爬虫返回的对象
        :return: url生成器
        """
        soup = BeautifulSoup(response.content, "html.parser")
        menu_tag = soup.find(id = "x-wiki-index",class_="uk-nav uk-nav-side")
        recoders = []
        for div in menu_tag.find_all("div"):
            url = div.a.get("href")
            if not url.startswith("http"):
                url = "".join([self.domain,url])
            recoders.append([url, div.a.get_text()])
        return recoders

    def recode_to_sql(self,recoders):
        conn = sqlite3.connect(self.datapath)
        cur = conn.cursor()
        cur.execute('create table if not exists {} (name varchar(30),address varchar(50) primary key)'.format(self.name))
        for recoder in recoders:
            cur.execute('select * from {} where address=?'.format(self.name), (recoder[0],))
            values = cur.fetchall()
            if values == []:
                cur.execute('insert into {} (name,address) values (?,?)'.format(self.name), (recoder[1], recoder[0]))  # 需要改成小说名字
        cur.close()
        conn.commit()
        conn.close()

    def get_from_sql(self):
        conn = sqlite3.connect(self.datapath)

        cur = conn.cursor()
        cur.execute('select * from {}'.format(self.name))
        recoders = cur.fetchall()
        cur.close()
        conn.commit()
        conn.close()
        return recoders

    def parse_body(self,response):
        """
        解析url,返回html内容
        :param url:解析的url
        :return：html
        """
        try:
            soup = BeautifulSoup(response.content, "html.parser")
            body = soup.find(class_="x-wiki-content")

            # 加入标题, 居中显示
            title = soup.find('h4').get_text()
            center_tag = soup.new_tag("center")
            title_tag = soup.new_tag('h1')
            title_tag.string = title
            center_tag.insert(1, title_tag)
            body.insert(0, center_tag)

            html = str(body)
            # body中的img标签的src相对路径的改成绝对路径
            pattern = "(<img .*?src=\")(.*?)(\")"

            def func(m):
                if not m.group(2).startswith("http"):
                    rtn = "".join([m.group(1), self.domain, m.group(2), m.group(3)])
                    return rtn
                else:
                    return "".join([m.group(1), m.group(2), m.group(3)])

            html = re.compile(pattern).sub(func, html)
            html = html_template.format(content=html)
            html = html.encode("utf-8")
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

def main():
    # url = "https://foofish.net/python-crawler-html2pdf.html"
    filename = '廖雪峰Python教程'
    url = "https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000"
    storepath = '/home/dai/文档/书籍'
    datapath = '/home/dai/Graduate-Life/Backup/countnum.db'
    spider_obj = LiaoxuefengPythonCrawler(filename,url,storepath,datapath)
    # recoders = spider_obj.parse_menu(spider_obj.request(spider_obj.start_url))
    # spider_obj.recode_to_sql(recoders)
    #recoders = spider_obj.get_from_sql()
    spider_obj.run()


if __name__ == '__main__':
    main()