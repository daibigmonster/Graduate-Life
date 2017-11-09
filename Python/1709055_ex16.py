def print_max(a,b):
	if a>b:
		print(a,"is maximum")
	elif a==b:
		print(a,'is equal to',b)
	else:
		print(b,'is maximum')
print_max(3,5)
print_max(input('a='),input('b='))
