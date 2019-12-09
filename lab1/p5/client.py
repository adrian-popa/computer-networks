import socket
import pickle

number = 100

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("Client sending the integer to the server.")

s.sendto(pickle.dumps(number),("0.0.0.0",5555))

msg, addr = s.recvfrom(50)

print("List of divisors received: ")
print(pickle.loads(msg))
