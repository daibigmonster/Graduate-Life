from functools import reduce
def char2num(s):
    return {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9}[s]
def convert(s):
    return reduce(lambda x,y:x*10+y,map(char2num,s))
def str2float(s):
    slist=s.split('.')
    return convert(slist[0])+convert(slist[1])/pow(10,len(slist[1]))
print(str2float('123.456'))
