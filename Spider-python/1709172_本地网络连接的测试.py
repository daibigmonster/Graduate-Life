import requests
import re
import sqlite3
import time
import os

def get_one_page(name,address):
    headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'
}
    response = requests.get(address,headers=headers)
    if response.status_code == 200:
        print(name,'connect successfully')

def get_list():
	conn=sqlite3.connect('/home/dai/Graduate-Life/Backup/countnum.db')
	cur=conn.cursor()
	cur.execute('select * from 异常生物见闻录')#需要改成小说名字
	values=cur.fetchall()
	cur.close()
	conn.commit()
	conn.close()
	return values

def main():
	values=get_list()
	for value in values:
		get_one_page(value[0],value[1])

main()
