import socket
import pickle

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

string = pickle.loads(buff)


reverse_string = ''.join(reversed(string))
s.sendto(pickle.dumps(reverse_string),addr)
