import os
import pickle
import time
content={'C+':'C++primer','Cy':'Cyber-security',\
'L':'Linux','U':'UNIX','Py':'Python','py':'Python','Pr':'Prepare4work','T':'Test','t':'Test'}
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
	

	filename='/home/dai/Graduate-Life/Backup/num.data'
	numdict={'1':1}

	with open(filename,'rb') as f:
		numdict=pickle.load(f)
	if today in numdict:
		count=numdict[today]+1
		numdict[today]=count
	else:
		numdict[today]=count
	with open(filename,'wb') as h:
		pickle.dump(numdict,h)
	


	fileallname=today+str(count)+'_'+filename+filetype
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
