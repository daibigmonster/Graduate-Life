import socket
port=65212
host='192.168.1.105'
c = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
c.sendto(b'hello,this is a test info !',(host,port))