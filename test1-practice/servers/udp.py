import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("0.0.0.0", 5555))

buff, addr = s.recvfrom(10)

message = buff.decode("utf-8")
print("From " + str(addr) + ": " + message)

consonantsCount = 0
for l in message:
    if l not in ['a', 'e', 'i', 'o', 'u']:
        consonantsCount += 1

s.sendto(consonantsCount.to_bytes(4, 'little'), addr)
