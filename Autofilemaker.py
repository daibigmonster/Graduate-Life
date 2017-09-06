import os
import time
content={'C1':'C++primer','C2':'Cyber-security',\
'L':'Linux','U':'UNIX','P1':'Python','P2':'Prepare4work','T':'Test'}
source='/home/dai/Graduate-Life/'
today=time.strftime('%Y%m%d')
choice=input('Which content do you want to make file?(like C1,C2)')
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
