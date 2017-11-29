import threading
import time
from netaddr import  IPNetwork,IPAddress
import socket
import os
import struct
from ctypes import *



#批量发送udp数据包
def udp_sender(subnet,magic_message):
    time.sleep(5)
    sender = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    for ip in IPNetwork(subnet):
        try:
            sender.sendto(magic_message,("%s" % ip,65212))
            print("%s" % ip,"已经发送")
        except:
            print("%s" % ip,"没有发出")
            pass

def main():
    host = "192.168.1.100"
    subnet = "192.168.1.0/24"
    magic_message = "Congratulatons22!"
    print("开始发送！")
    udp_sender(subnet,magic_message)
    print("数据包发送结束！")

if __name__ == '__main__':
    main()