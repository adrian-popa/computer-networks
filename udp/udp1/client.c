#include <netinet/ip.h>

struct nr{
	int a,b,s;
};
int serverFD; 
struct sockaddr_in client_socket, fromServer;
struct nr n,rez;
int main(int argc, char argv[]){
	
	serverFD = socket(AF_INET, SOCK_DGRAM, 0);
	n.a = 10;
	n.b = 20;
	fromServer.sin_family = AF_INET;
	fromServer.sin_port = htons(7777);
	fromServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	sendto(serverFD, &n, sizeof(struct nr), 0, &fromServer, sizeof(struct sockaddr_in)); 
	int r,sum=5;
	r = recvfrom(serverFD, &sum, sizeof(int), 0, &client_socket, sizeof(struct sockaddr_in));
	printf("%d\n", r);
	return 0;
}
