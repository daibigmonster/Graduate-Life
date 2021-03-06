from urllib.request import urlopen
from urllib.error import HTTPError
from bs4 import BeautifulSoup
import requests
from requests.exceptions import RequestException

def get_one_page(url):
    headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'
}
    try:
        response = requests.get(url,headers=headers,timeout=10)
        if response.status_code == 200:
       	    return response
        return None
    except RequestException:
        return None


def getContext(url):
    try:
        html = get_one_page(url)
    except HTTPError as e:
        return None
    try:
        bsobj = BeautifulSoup(html,"html.parser")
        nameist = bsobj.findAll("p")
    except AttributeError as e:
        return None
    return nameist

testurl = "https://foofish.net/python-crawler-html2pdf.html"
namelist = getContext(testurl)
if namelist == None:
    print("Title could not be found")
else:
    for name in namelist:
        print(name.get_text())