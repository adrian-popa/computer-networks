import socket
import pickle

string = "abaacc"
char = 'a'
combined = [string,char]

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("Client sending the string and the char to the server.")

s.sendto(pickle.dumps(combined),("0.0.0.0",5555))

msg, addr = s.recvfrom(50)

print("List of indexes received: ")
print(pickle.loads(msg))
