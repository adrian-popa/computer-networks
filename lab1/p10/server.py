import socket
import pickle

def char_and_count(first,second):
    freq = {}
    if len(first)>len(second):
        aux = first
        first=second
        second = aux
    for i in range(0,len(first)):
        if first[i]==second[i]:
            if first[i] not in freq.keys():
                freq[first[i]]=1
            else :
                freq[first[i]]+=1
    max_char=''
    max_count=0
    for char in freq.keys():
        if freq[char]>max_count:
            max_count = freq[char]
            max_char = char
    return {max_char:max_count}

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

s.bind(("0.0.0.0",5555))
buff,addr = s.recvfrom(50)

info = pickle.loads(buff)

first = info[0]
second = info[1]
s.sendto(pickle.dumps(char_and_count(first,second)),addr)
