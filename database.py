import sqlite3
import time
today=time.strftime('%y%m%d')
conn=sqlite3.connect('/home/dai/Graduate-Life/Backup/countnum.db')
cursor=conn.cursor()
cursor.execute('create table user (data varchar(20) primary key,num int)')
cursor.execute('insert into user (data,num) values ('11',1)')
cursor.close()
conn.commit()
conn.close()
