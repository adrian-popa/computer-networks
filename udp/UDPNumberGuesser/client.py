import socket 
import pickle

def run():
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    guess = int(input())
    s.sendto(pickle.dumps(guess),("127.0.0.1",7777))
    buff, addr = s.recvfrom(50)
    answ = pickle.loads(buff)
    while answ == "Not yet": 
        guess = int(input())
        s.sendto(pickle.dumps(guess),addr)
        buff,addr = s.recvfrom(50)
        answ = pickle.loads(buff)
    
run()