import socket
import pickle

arrays = [[1,2,3,4,5],[2,3,4]]

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

print("Client sending the two arrays(A,B) to the server.")

s.sendto(pickle.dumps(arrays),("0.0.0.0",5555))

msg, addr = s.recvfrom(50)

print("A\B received: ")
print(pickle.loads(msg))
