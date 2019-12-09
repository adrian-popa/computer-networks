import socket
import pickle

def intersection(first,second):
    new = []
    for n in first: 
        if n not in second: 
            new+=[n]
    return new

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

info = pickle.loads(buff)

print("Received the two arrays. Computing and sending back A\B.")

first = info[0]
second = info[1]
s.sendto(pickle.dumps(intersection(first,second)),addr)
