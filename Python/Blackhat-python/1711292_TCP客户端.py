import socket
import os

target_host = "192.168.1.100"
target_port = 9999

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

client.connect((target_host,target_port))

client.send(b"AAAAAABBBBB")

reponse = client.recv(4096)

print(reponse)