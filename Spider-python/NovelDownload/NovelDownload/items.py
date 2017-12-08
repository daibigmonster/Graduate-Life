# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy
from scrapy import Field


class NoveldownloadItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    Novel_name = Field()
    chapter_url = Field()
    chapter_tittle = Field()
    chapter_num = Field()
    chapter_content = Field()

