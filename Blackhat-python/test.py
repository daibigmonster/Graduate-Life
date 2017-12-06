import socket
import os


target_host = "192.168.1.100"
target_port = 8081

client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
client.sendto(b"AAAABBBB",(target_host,target_port))

data, addr  = client.recvfrom(4096)

print("Received:",data,"from",addr)
