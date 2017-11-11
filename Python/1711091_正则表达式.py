import re
content = 'Hello 123 4567 World_This is a Regex Demo'
print(len(content))
result =re.match('^Hello\s\d\d\d\s\d{4}\s\w{10}',content)
print(result)
print(result.group())
print(result.span())

# 我们用^Hello\s\d\d\d\s\d{4}\s\w{10} 用它来匹配这个长字符串。开头的^
# 是匹配字符串的开头，也就是Hello的开头，然后用\s匹配空白字符