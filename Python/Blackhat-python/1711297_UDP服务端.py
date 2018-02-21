import socket

bind_port = 8081


server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
server.bind(('',bind_port))

print('waiting on port:',bind_port)
while True:
  data,addr = server.recvfrom(1024)
  #接收一个数据报(最大到1024字节)
  print('reciveed:',data,"from",addr)