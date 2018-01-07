import mysql.connector
conn = mysql.connector.connect(user='root', password='root', database='test')
cur = conn.cursor()
#cur.execute('create table user (id varchar(20) primary key, name varchar(20))')
cur.execute('insert into user (id,name) values (%s,%s)',['1','daijian'])
conn.commit()
cur.close()