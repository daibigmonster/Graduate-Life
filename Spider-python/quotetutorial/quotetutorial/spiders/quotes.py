# -*- coding: utf-8 -*-
import scrapy
from quotetutorial.items import QuoteItem

class QuotesSpider(scrapy.Spider):
    name = 'quotes'
    allowed_domains = ['quotes.toscrape.com']
    # start_urls = ['http://quotes.toscrape.com/']
    def start_requests(self):
        yield scrapy.Request('http://quotes.toscrape.com/',self.parse)

    def parse(self, response):
        quotes = response.css('.quote')
        for quote in quotes:
            item = QuoteItem()
            text = quote.css('.text::text').extract_first()#scrapy特有的结构，输出里面的文字内容
            author = quote.css('.author::text').extract_first()#scrapy特有的结构，输出里面的文字内容
            tags = quote.css('.tags .tag::text').extract()
            item['text'] = text
            item['author'] = author
            item['tags'] = tags
            yield item

        next = response.css('ul.pager li.next a::attr(href)').extract_first()
        url = response.urljoin(next)
        yield scrapy.Request(url = url,callback = self.parse)