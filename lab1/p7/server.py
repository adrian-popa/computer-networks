import socket
import pickle

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

info = pickle.loads(buff)

print("Received the tuple (s,start,length)")
string = info[0]
start = info[1]
length = info[2]

s.sendto(pickle.dumps(string[start:start+length]),addr)
