import os
import time
source=['/home/dai/Graduate-Life']
target_dir='/home/dai/文档/backup'
if not os.path.exists(target_dir):
	os.mkdir(target_dir)
today=target_dir+os.sep+time.strftime('%Y%m%d')
now=time.strftime('%H%M%S')
comment=input('Enter a comment -->')
#检查是不是由评论输入
if len(comment)==0:
	target=today+op.sep+now+'.zip'
else:
	target=today+os. sep+now+'_'+comment.replace(' ','_')+'.zip'
#replace用下划线替换掉了注释中的空格
#如果子目录不存在则输入一个
if not os.path.exists(today):
	os.mkdir(today)
	print('Successfully created directory',today)

zip_command='zip -r {0} {1}'.format(target,' '.join(source))
print('Zip command is:')
print(zip_command)
print('Running:')
if os.system(zip_command)==0:
	print('Successful backup to',target)
else:
	print('Backup failed')
