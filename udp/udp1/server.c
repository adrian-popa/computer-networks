#include <netinet/ip.h>
#include <sys/types.h>
#include <sys/socket.h>
struct nr {
	int a,b,s;
};
struct nr n;
int serverFD, r;
struct sockaddr_in server_socket, client_socket;

int main(int argc, char argv[]){
	int client = sizeof(struct sockaddr_in);
	serverFD = socket(AF_INET, SOCK_DGRAM, 0);
	server_socket.sin_family = AF_INET;
	server_socket.sin_port = htons(7777);
	server_socket.sin_addr.s_addr = inet_addr("0.0.0.0");
	
	bind(serverFD, &server_socket, sizeof(struct sockaddr_in));

	listen(serverFD,5);
	accept(serverFD,(struct sockaddr *) server_socket, (socklen_t*) client_socket);

	r = recvfrom(serverFD, &n, sizeof(struct nr), 0, &client_socket, &client); //number of bytes read
	printf("%d %d\n", n.a, n.b);
	int s=n.a+n.b ;
	//s= n.a+n.b;
	//int asd=htons(s);
	sendto(serverFD, &s, sizeof(int), 0, &client_socket, sizeof(struct sockaddr_in));
	return 0;
}
