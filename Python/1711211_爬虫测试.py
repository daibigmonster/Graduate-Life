from urllib.request import urlopen
from urllib.error import HTTPError
from bs4 import BeautifulSoup
import codecs


def getTitle(url):
    try:
        html = urlopen(url)
    except HTTPError as e:
        return None
    try:
        bsobj = BeautifulSoup(html.read(),"lxml")
        namelist = bsobj.find("div",{"id":"content"})
    except AttributeError as e:
        return None
    return namelist


namelist = getTitle("http://www.xs.la/1_1212/738017.html")
if namelist == None:
    print("Title could not be found")
else:
    print(namelist)