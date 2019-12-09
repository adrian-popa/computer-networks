import socket
import threading

def handleClient(conn, addr):
    ret = "Message received."
    print("Connected to: " + str(addr) + ".")

    while True:
        message = conn.recv(1024).decode("utf-8")
        print("From " + str(addr) + ": " + message, end='')
        conn.send(ret.encode("utf-8"))

        if (message == "close\n"):
            break

    print("Connection to " + str(addr) + " was closed.")
    conn.close();

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

s.bind(("0.0.0.0", 6666))
s.listen(5)

while True:
    conn, addr = s.accept()
    thr = threading.Thread(target=handleClient, args=(conn, addr))
    thr.start()

