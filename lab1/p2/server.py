import socket
import pickle

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

string = pickle.loads(buff)
spaces = 0
for c in string:
    if c == ' ':
        spaces+=1

s.sendto(pickle.dumps(spaces),addr)
