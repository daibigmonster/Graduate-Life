import os
import time
content={'C+':'C++primer','Cy':'Cyber-security',\
'L':'Linux','U':'UNIX','Py':'Python','Pr':'Prepare4work','T':'Test'}
source='/home/dai/Graduate-Life/'
today=time.strftime('%y%m%d')
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
	
fileallname=today+'_'+filename+filetype
target=target_dir+os.sep+fileallname
file_command='vi {}'.format(target)
if os.system(file_command)==0:
	print('Successful {0} to {1}'.format(fileallname,target))
else:
	print('Makefile failed!')
