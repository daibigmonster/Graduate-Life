from __future__ import unicode_literals

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

    def __init__(self,name,start_url):
        """
        初始化
        :param name: 将要被保存为PDF的文件名称
        :param start_url: 爬虫入口URL
        """
        self.name = name;
        self.start_url = start_url;
        self.domain = '{uri.scheme}://{uri.netloc}'.format(uri = urlparse(self.start_url));


    # @staticmethod
    # def request(url,**kwargs):
    #     """
    #     网络请求,返回response对象
    #     :return:
    #     """
    #     response = requests.get(url,**kwargs)
    #     return response


if __name__ == '__main__':
    start_url = "https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000"
    #crawler = LiaoxuefengPythonCrawler("廖雪峰Python", start_url)
    #crawler.run()
main()