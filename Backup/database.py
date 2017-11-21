import sqlite3
import time
def datause():
	count=1
	today=time.strftime('%y%m%d')
	conn=sqlite3.connect('/home/dai/Graduate-Life/Backup/countnum.db')
	cur=conn.cursor()
	cur.execute('select * from user where date=?',(today,))
	values=cur.fetchall()
	if values==[]:
		cur.execute('insert into user (date,num) values (?,?)',(today,count))
		print('We have created a rocord which date={0},num={1}'.format(today,count))
	else:
		count=values[0][1]+1
		cur.execute('update user set num=? where date=?',(count,today))
		print('We have update a rocord which date={0},num={1}'.format(today,count))
	cur.close()
	conn.commit()
	conn.close()
	return count
