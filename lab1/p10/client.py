import socket
import pickle

strings = ["aaabccc!!!!","aaabccc!!!!"]

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("Client sending the two strings to the server.")

s.sendto(pickle.dumps(strings),("0.0.0.0",5555))

msg, addr = s.recvfrom(50)

print("Char+count received: ")
print(pickle.loads(msg))
