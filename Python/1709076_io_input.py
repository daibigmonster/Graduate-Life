def reverse(text):
	return text[::-1]

def is_palindrome(text):
	return text==reverse(text)

something=input("Enter text: ")
if is_palindrome(something):
	print("Yes,it is a palindrome")
else:
	print("No,it's not a palindrome")

teststr=input("Input a test string:")
teststr=reverse(teststr)
testlist=teststr.split(' ')
teststr=''
for substr in testlist:
	teststr+=reverse(substr)
	teststr+=' '
print(teststr)
