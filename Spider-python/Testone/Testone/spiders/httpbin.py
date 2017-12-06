# -*- coding: utf-8 -*-
import scrapy


class HttpbinSpider(scrapy.Spider):
    name = 'httpbin'
    allowed_domains = ['httpbin.org']
    start_urls = ['http://httpbin.org/']

    def make_requests_from_url(self, url):
        return scrapy.Request(url = url,meta={'download_timeout': 10},callback=self.parse)

    def parse(self, response):
        print(response.text)
