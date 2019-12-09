#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define ADDR "192.168.43.88"
#define DEF_PORT 4444

#define CONNECT_MSG "Connect"

char message[32];

struct sockaddr_in soc;

int sfd;

int main(int argc, char ** argv) {
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	soc.sin_family = AF_INET;
	soc.sin_addr.s_addr = inet_addr(ADDR);
	soc.sin_port = htons(DEF_PORT);

        int soc_len = sizeof(struct sockaddr_in);

	sendto(sfd, CONNECT_MSG, strlen(CONNECT_MSG), 0, (struct sockaddr*)&soc, soc_len);

	int recvPort = 0;
	recvfrom(sfd, &recvPort, sizeof(int), 0, (struct sockaddr*)&soc, (socklen_t *)&soc_len);

	soc.sin_port = htons(recvPort);

	while (1) {
		printf("Give a word: ");
		fgets(message, sizeof(message), stdin);

		sendto(sfd, message, strlen(message) - 1, 0, (struct sockaddr*)&soc, soc_len);

		int consonantsCount = 0;
		recvfrom(sfd, &consonantsCount, sizeof(int), 0, (struct sockaddr*)&soc, (socklen_t *)&soc_len);
					
		printf("The word contains %d consonants.\n", consonantsCount);
	}

	return 0;
}
