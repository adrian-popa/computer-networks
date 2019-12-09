import socket
import pickle

def list_of_divisors(number):
    listD = []
    div = 1
    while div*div<number:
        if number%div == 0:
            listD+=[div]
            listD+=[number//div]
        div+=1
    if number%div==0:
        listD+=[div]
    return listD

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

number = pickle.loads(buff)

divisors = list_of_divisors(number)
divisors.sort()
print(divisors)
s.sendto(pickle.dumps(divisors),addr)
