poem='''\
Programming is fun
When the work is done
if you wanna make your work also fun:
	use Python
'''

f=open('/home/dai/Test/test1','w')
f.write(poem)
f.close()

f=open('/home/dai/Test/test1')
while True:
	line=f.readline()
	if len(line)==0:
		break
	print(line,end='')
f.close()
