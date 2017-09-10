import os
import time
import sqlite3
content={'C+':'C++primer','Cy':'Cyber-security',\
'L':'Linux','U':'UNIX','Py':'Python','py':'Python','Pr':'Prepare4work',\
'T':'Test','t':'Test'}
source='/home/dai/Graduate-Life/'
today=time.strftime('%y%m%d')
quit=True
count=1
while quit:
	while True:
		choice=input('Which content do you want to make file?')
		if choice in content:
			break
		else:
			print('Wrong content,input again!')
	filename=input('what filename do U want to take?')
	filetype=input('What kind of file do you want?')

	target_dir=source+content[choice]
	if not os.path.exists(target_dir):
		print('Wrong content!')
    
	conn=sqlite3.connect('/home/dai/Graduate-Life/Backup/countnum.db')
	cur=conn.cursor()
	cur.execute('select * from user where date=?',(today,))
	values=cur.fetchall()
	if values==[]:
		fileallname=today+str(count)+'_'+filename+filetype
		cur.execute('insert into user (date,num,filename) values (?,?,?)',(today,count,fileallname))
		ptint('We have created a rocord which date={0},num={1}'.format(today,count))
	else:
		count=values[0][1]+1
		fileallname=today+str(count)+'_'+filename+filetype
		cur.execute('update user set num=?,filename=? where date=?',(count,fileallname,today))
		print('We have update a rocord which date={0},num={1}'.format(today,count))
	cur.close()
	conn.commit()
	conn.close()

#	with open('/home/dai/Graduate-Life/Backup/countnumers','r') as file_read:
#		flag=False
#		for line in file_read:
#			line=line.strip()
#			if line[:6]==today:
#				flag=True
#				count=int(line[-1])+1
#				file_add=open('/home/dai/Graduate-Life/Backup/countnumers','a')
#				file_add.write(str(count))
#				file_add.close()
#		if not flag:
#			file_add=open('/home/dai/Graduate-Life/Backup/countnumers','a')
#			newline='\n'+today+str(count)
#			file_add.write(newline)
#			file_add.close()



#	fileallname=today+str(count)+'_'+filename+filetype
	target=target_dir+os.sep+fileallname
	file_command='vi {}'.format(target)
	if os.system(file_command)==0:
		print('Successful {0} to {1}'.format(fileallname,target))
	else:
		print('Makefile failed!')
	count=count+1
	flag=input('Do u want to quit or go on?')
	if flag=='q' or flag=='quit':
		quit=False
print('Goodbye,see you again!')
