#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define ADDR "192.168.0.164"
#define PORT 5555

#define MESSAGE "qwertyabc"

struct sockaddr_in soc;

int sfd;

int main(int argc, char ** argv) {
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	soc.sin_family = AF_INET;
	soc.sin_addr.s_addr = inet_addr(ADDR);
	soc.sin_port = htons(PORT);
	
	int soc_len = sizeof(struct sockaddr_in);
	
	sendto(sfd, MESSAGE, strlen(MESSAGE), 0, (struct sockaddr*)&soc, soc_len);
	
	int consonantsCount = 0;
	recvfrom(sfd, &consonantsCount, sizeof(int), 0, (struct sockaddr*)&soc, &soc_len);
	
	printf("The word contains %d consonants.\n", consonantsCount);
	
	return 0;
}