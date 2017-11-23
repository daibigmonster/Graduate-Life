try:
	text=input("Enter somthing-->")
except EOFError:
	print("What did you do an EOF on me?")
except KeyboardInterrupt:
	print("You cancelled the operation.")
else:
	print('You entered  {}'.format(text))
	
