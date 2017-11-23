import urllib.parse
import urllib.request

data=bytes(urllib.parse.urlencode({'word':'hello'}),encoding='utf8')
response=urllib.request.urlopen('http://httpbin.org/post',data=data)
print(response.read().decode('utf-8'))


#request=urllib.request.Request('https://python.org')
#reponse=urllib.request.urlopen(request)
#print(reponse.read().decode('utf-8'))
