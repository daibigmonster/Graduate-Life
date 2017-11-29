import socket
port=8081
host='localhost'
c = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
c.sendto(b'hello,this is a test info !',(host,port))