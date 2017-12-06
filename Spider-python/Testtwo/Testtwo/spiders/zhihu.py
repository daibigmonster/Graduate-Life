# -*- coding: utf-8 -*-
from  scrapy import Spider,Request


class ZhihuSpider(Spider):
    name = 'zhihu'
    allowed_domains = ['www.zhihu.com']
    start_urls = ['http://www.zhihu.com/']
    start_user = 'excited-vczh'


    user_url = 'https://www.zhihu.com/api/v4/members/{user}?include={include}'
    user_query = 'allow_message,is_followed,is_following,is_org,is_blocking,employments,answer_count,follower_count,articles_count,gender,badge[?(type=best_answerer)].topics'
    follow_url = 'https://www.zhihu.com/api/v4/members/{user}?include={include}&offset={offset}&limit={limit}'
    follows_query = 'data[*].answer_count,articles_count,gender,follower_count,is_followed,is_following,badge[?(type=best_answerer)].topics'


    def start_requests(self):
        yield Request(self.user_url.format(user = self.start_user,include = self.user_query),\
                      callback = self.parse_user)
        yield Request(self.follow_url.format(user = self.start_user,include = self.follows_query,offset = 0,limit = 20),\
                      callback = self.parse_followers)


    def parse_user(self, response):
        print(response.text)

    def parse_followers(self, response):
        print(response.text)
