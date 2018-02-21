# -*- coding: utf-8 -*-
import re

import pymongo
import scrapy
from bs4 import BeautifulSoup
from scrapy import Request

from NovelDownload.items import NoveldownloadItem


class NovelgetSpider(scrapy.Spider):
    name = 'NovelGet'
    allowed_domains = ['www.xs.la']
    start_urls = ['https://www.xs.la/']

    base_url = 'https://www.xs.la'
    Novle_list_urls = ['https://www.xs.la/1_1212/',
                      'https://www.xs.la/3_3271/',
                      'https://www.xs.la/2_2691/']



    def start_requests(self):
        for Novel_list_url in self.Novle_list_urls:
            yield Request(Novel_list_url,self.parse_menu)

    def parse_menu(self, response):
        chapter_urls = response.css('div#list dl dd a::attr(href)').extract()
        novelname = response.css('div#maininfo div#info h1::text').extract_first()
        chapter_num = 0
        for chapter_url in chapter_urls:
            chapter_num += 1
            yield Request(self.base_url + chapter_url,self.parse_content,
                          meta = {'novelname' : novelname,
                                  'chapterurl' : chapter_url,
                                  'chapternum' : chapter_num})

    def parse_content(self,response):
        item = NoveldownloadItem()
        item['Novel_name'] = response.meta['novelname']
        item['chapter_url'] = response.meta['chapterurl']
        item['chapter_tittle'] = response.css('div.box_con div.bookname h1::text').extract_first()
        item['chapter_num'] = response.meta['chapternum']

        # 用BS4来分析出内容
        soup = BeautifulSoup(response.text, "html.parser")
        body = soup.find(id="content")

        content = str(body)
        content = re.sub('<script.*?></script>', '', content)
        item['chapter_content'] = content
        return item

