#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define ADDR "192.168.0.164"
#define PORT 6666

char message[32];
char receive[32];

struct sockaddr_in soc;

int sfd;
int rc;

int main(int argc, char ** argv) {
	sfd = socket(AF_INET, SOCK_STREAM, 0);

	soc.sin_family = AF_INET;
	soc.sin_addr.s_addr = inet_addr(ADDR);
	soc.sin_port = htons(PORT);

	rc = connect(sfd, (struct sockaddr *)&soc, sizeof(soc));

	while (1) {
		printf("Enter message: ");
		fgets(message, sizeof(message), stdin);

		rc = send(sfd, message, strlen(message), 0);
		rc = recv(sfd, receive, 20, 0);

		printf("(%s, %d) : %s\n", ADDR, PORT, receive);
	}

	return 0;
}
