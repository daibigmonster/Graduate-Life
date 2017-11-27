import logging
import os
import re
import time

from urllib.parse import urlparse

import pdfkit
import requests
from bs4 import BeautifulSoup

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

class Crawler(object):
    """
    爬虫基类，所有爬虫都应该继承此类
    """
    name = None
    start_url = None

    def __init__(self,name,start_url):
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

    def run(self):
        start = time.time()
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
        htmls = []
        menus = self.parse_menu(self.request(self.start_url))
        for index,url in enumerate(menus):
            html = self.parse_body(self.request(url))
            f_name = ".".join([str(index),"html"])
            if os.path.exists(f_name):
                print(f_name,'已经存在，略过')
            else:
                print(f_name,'正在下载')
            if html != None:
                with open(f_name, 'wb') as f:
                    f.write(html)
                time.sleep(0.5)
                htmls.append(f_name)
            else:
                print(f_name, '超时，略过')
                continue



        pdfkit.from_file(htmls,self.name + ".pdf", options = options)
        for html in htmls:
            os.remove(html)
        total_time = time.time() - start
        print(u"总共耗时：%f 秒" % total_time)

class LiaoxuefengPythonCrawler(Crawler):
    """
    廖雪峰课程的下载
    """
    def parse_menu(self,response):
        """
        解析目录结构，获取所有的URL目录李彪
        :param response: 爬虫返回的对象
        :return: url生成器
        """
        soup = BeautifulSoup(response.content, "html.parser")
        #menu_tag = soup.find_all(class_ = "uk-nav uk-nav-side")[1]
        menu_tag = soup.find(style = "margin-right:-15px;")
        urls = []
        for div in menu_tag.find_all("div"):
            url = div.a.get("href")
            if not url.startswith("http"):
                url = "".join([self.domain,url])
            urls.append(url)
        return urls

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
            body.insert(1, center_tag)

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
            print(e)



def main():
    # url = "https://foofish.net/python-crawler-html2pdf.html"
    url = "https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000"
    spider_obj = LiaoxuefengPythonCrawler("廖雪峰Python教程", url)
    #menus = spider_obj.parse_menu(spider_obj.request(spider_obj.start_url))
    #for menu in menus:
    #    print(menu)
    spider_obj.run()


if __name__ == '__main__':
    main()