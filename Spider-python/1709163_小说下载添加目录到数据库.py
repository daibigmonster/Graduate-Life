import requests
import re
import sqlite3
import time
import os
import socket

def get_one_page(url):
    response = requests.get(url,timeout=10)
    if response.status_code == 200:
        return response.text
    else:
    	print('超时！')

def make_list(html):
	base_url='http://www.xs.la'
	pattern=re.compile('<dd>.*?href="(.*?)">(.*?)</a></dd>',re.S)
	items=re.findall(pattern,html)
	conn=sqlite3.connect('/home/dai/Graduate-Life/Backup/countnum.db')
	cur=conn.cursor()
	cur.execute('create table if not exists booklist (name varchar(30),address varchar(50) primary key)')
	for item in items:
		#print(item)
		url=base_url+item[0]
		cur.execute('select * from booklist where address=?',(url,))
		values=cur.fetchall()
		if values==[]:
			cur.execute('insert into booklist (name,address) values (?,?)',(item[1],url))
		else:
			pass
	cur.execute('select * from booklist')
	values=cur.fetchall()
	cur.close()
	conn.commit()
	conn.close()
	return values

def parse_one_page(bookpath,sourcecode):
#	print(bookpath)
	sourcecode=re.sub('<br/>.*?<br/>|<script.*?></script>','',sourcecode)
	pattern=re.compile('<div.*?id="content">(.*?)</div>',re.S)
	items=re.findall(pattern,sourcecode)
	content=items[0].replace('&nbsp;&nbsp;&nbsp;&nbsp;','\n\t')
#    items=re.sub('<br/>.*?<br/>','',items)	
	with open(bookpath, 'w') as f:
		f.write(content)

def download(noveldir,values):
	count=0
	for item in values:
		count+=1
		bookpath='{0}/{1} {2}.txt'.format(noveldir,str(count),item[0])
		if  os.path.exists(bookpath):
			print(bookpath,'已经存在，略过')
		else:
			print(bookpath,'正在下载')
			sourcecode=get_one_page(item[1])
			parse_one_page(bookpath,sourcecode)
			time.sleep(1)
	
			
def main():
	noveldir=input('Which content do you want to download novel?')
	noveldir='/home/dai/文档/'+noveldir
	if not os.path.exists(noveldir):
		os.system('mkdir {}'.format(noveldir))
	first_url='http://www.xs.la/1_1212/'#小说的首页，从首页就可以抓取目录
	sourcecode=get_one_page(first_url)
	values=make_list(sourcecode)
	download(noveldir,values)
			

main()

