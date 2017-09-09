import urllib.request
response=urllib.request.urlopen('https://www.github.com')
print(response.status)
print(response.getheaders())
print(response.getheader('Server'))
print(type(response))

