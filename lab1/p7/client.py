import socket
import pickle

string = "abaaccsadsad"
startIndex = 0
length = 5
combined = [string,startIndex,length]

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("Client sending the triple (s,start,length) to the server.")

s.sendto(pickle.dumps(combined),("0.0.0.0",5555))

msg, addr = s.recvfrom(50)

print("Substring received: ")
print(pickle.loads(msg))
