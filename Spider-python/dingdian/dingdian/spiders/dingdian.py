import re
import scrapy
from bs4 import BeautifulSoup
from scrapy.http import Request
from dingdian.items import DingdianItem
# 玄幻奇幻　http://www.xs.la/newclass/1/1.html
#
# 武侠修真：http://www.xs.la/newclass/2/1.html
#
# 都市言情：http://www.xs.la/newclass/3/1.html
#
# 历史军事：http://www.xs.la/newclass/4/1.html
#
# 科幻灵异：http://www.xs.la/newclass/5/1.html
#
# 网游竞技：http://www.xs.la/newclass/6/1.html
#
# 女频频道：http://www.xs.la/newclass/7/1.html
#
# 完本小说:http://www.xs.la/quanben/


class Myspider(scrapy.Spider):
    name = 'dingdian'
    allowed_domains = ['xs.la']
    bash_url = 'http://www.xs.la/newclass/'
    bashurl = '.html'

    def start_requests(self):
        for i in range(1,8):
            url = self.bash_url + str(i) + '/1' + self.bashurl
            yield Request(url,callback = self.get_name)
        yield Request('http://www.xs.la/quanben/',callback=self.get_name)


    def get_name(self,response):
        tds1 = BeautifulSoup(response.content, "html.parser").find_all('div',class_='ll')
        tds2 = BeautifulSoup(response.content, "html.parser").find_all('div',class_='l')
        tds3 = BeautifulSoup(response.content, "html.parser").find_all('div',class_='r')
        for td in tds1:
            novelname = 