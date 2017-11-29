import socket
import os
import struct
from ctypes import *

host = "192.168.1.109"

class IP(Structure):
    _fields_ =[{
        ("ipl", c_ubyte,4)
        ("ver", c_ubyte,4)
        ("tos", c_ubyte)
    }]
socket_protocol = socket.IPPROTO_ICMP
sniffer = socket.socket(socket.AF_INET,socket.SOCK_RAW,socket_protocol)
sniffer.bind((host,0))

sniffer.setsockopt(socket.IPPROTO_IP,socket.IP_HDRINCL,1)
#1大概表示1个数据包

print(sniffer.recvfrom(65565))