import socket
import pickle

string = "ana are mere "

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("Client sending the string to the server.")

s.sendto(pickle.dumps(string),("0.0.0.0",5555))

msg, addr = s.recvfrom(50)

print("Reversed string received: ")
print(pickle.loads(msg))
