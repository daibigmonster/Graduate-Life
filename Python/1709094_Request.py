#from urllib import request,parse
from urllib import request,parse
#url='http://httpbin.org/post'
url='http://httpbin.org/post'
#headers={
headers={
#	'User-Agent':'Mozilla/4.0 (compatible;MSIE5.5;Windows Nt)',
	'User-Agent': 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)',
#	'Host':'httpbin.rog'
	'Host':'httpbin.org'
}
#headers={
#    'User-Agent': 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)',
#    'Host': 'httpbin.org'
#}
dict={
	'name':'Germey'
}
#data=bytes(parse.urlencode(dict),encoding='utf8')
data=bytes(parse.urlencode(dict),encoding='utf8')
#req=request.Request(url=url,data=data,headers=headers,method='POST')
req=request.Request(url=url,data=data,headers=headers,method='POST')
response=request.urlopen(req)
#response=request.urlopen(req)
print(response.read().decode('utf-8'))
#print(response.read().decode('utf-8'))


