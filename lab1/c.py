import socket

UDP_IP = "192.168.43.82"
UDP_PORT = 9999

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

s.sendto(b"Heiii!", (UDP_IP, UDP_PORT))
