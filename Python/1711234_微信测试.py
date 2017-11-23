from wxpy import *

bot = Bot()

GF = bot.friends().search('管小洋',sex = FEMALE)[0]
GF.send('戴涧微信机器人上线测试')
GF.send('让我们开始聊天吧！')

tuling = Tuling(api_key='d68ebf6b345a4b2c9a3ed4e35e045e55')

# 消息接收监听器
@bot.register()
def print_others(msg):
    # 输出监听到的消息
    print(msg)
    # 回复消息
    tuling.do_reply(msg)

embed()