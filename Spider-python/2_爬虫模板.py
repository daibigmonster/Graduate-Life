import os
import re
import time
from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
import sqlite3
import pdflit

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

    def save_pdf(self,htmls, file_name):
        """
        将html文件生成pdf文件
        :param htmls: html文件
        :param file_name: 文件名
        :return:
        """
        raise NotImplementedError

    def run(self):
        """

        :return:
        """
