import socket
import pickle

def merge(first,second):
    i=0
    j=0
    result=""
    while i<len(first) and j<len(second):
        if first[i]<second[j]:
            result+=first[i]
            i+=1
        else:
            result+=second[j]
            j+=1
    while i<len(first):
        result+=first[i]
        i+=1
    while j<len(second):
        result+=second[j]
        j+=1
    return result

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

info = pickle.loads(buff)

first = info[0]
second = info[1]
s.sendto(pickle.dumps(merge(first,second)),addr)
