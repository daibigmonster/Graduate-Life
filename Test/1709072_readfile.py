import os,sys,time
#today=time.strftime('%y%m%d')
today='170909'
with open('/home/dai/文档/backup/countnumers','r') as file_read:
	flag=False
	for line in file_read:
		line=line.strip('\n')
		if line[:6]==today:
			flag=True
			print(line[-1])
			count=int(line[-1])+1
			file_add=open('/home/dai/文档/backup/countnumers','a')
			file_add.write(str(count))
			file_add.close()
	if not flag:
		file_add=open('/home/dai/文档/backup/countnumers','a')
		newline='\n'+today+'1'
		file_add.write(newline)
		file_add.close()
