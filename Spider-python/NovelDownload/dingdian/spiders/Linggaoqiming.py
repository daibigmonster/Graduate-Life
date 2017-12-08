# -*- coding: utf-8 -*-
import scrapy
from scrapy import Request


class LinggaoqimingSpider(scrapy.Spider):
    name = 'Linggaoqiming'
    allowed_domains = ['www.xs.la/1_1212/']
    start_urls = ['http://www.xs.la/1_1212//']

    def start_requests(self):
        yield Request(self.start_urls,self.parse_novellist)

    def parse_novellist(self,reponse):


