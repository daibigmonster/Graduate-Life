from urllib.request import urlopen
from urllib.error import HTTPError
from bs4 import BeautifulSoup


def getContext(url):
    try:
        html = urlopen(url)
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