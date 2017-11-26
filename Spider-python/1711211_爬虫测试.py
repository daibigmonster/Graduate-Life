from urllib.request import urlopen
from urllib.request import Request
from urllib.error import HTTPError
from bs4 import BeautifulSoup




def getContext(url):
    headers = {
        'Uer-Agent':'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'
    }
    req = Request(url=url, headers=headers,)
    try:
        html = urlopen(req)
    except HTTPError as e:
        return None
    try:
        bsobj = BeautifulSoup(html,"html.parser")
        nameist = bsobj.findAll("p")
        print(nameist)
    except AttributeError as e:
        return None
    return nameist

def main():
    testurl = "https://foofish.net/python-crawler-html2pdf.html"
    namelist = getContext(testurl)
    if namelist == None:
        print("Title could not be found")
    else:
        for name in namelist:
            print(name.get_text())

if __name__ == '__main__':
    main()