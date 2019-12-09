import socket
import pickle

def position_indexes(string,char):
    ind = []
    i = 0
    for c in string: 
        if c==char:
            ind+=[i]
        i+=1
    return ind


s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

info = pickle.loads(buff)

print("Received string " + info[0] +" and char " + info[1])
list_of_indexes = position_indexes(info[0],info[1])

s.sendto(pickle.dumps(list_of_indexes),addr)
