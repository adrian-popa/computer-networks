#include <netinet/ip.h>

struct numar{
	int a,b;
};

int sfd;
struct sockaddr_in soc;

int main(int argc, char argv[]){
	sfd = socket(AF_INET,SOCK_DGRAM, 0);

	soc.sin_family = AF_INET;
	soc.sin_port = htons(7777);
	soc.sin_addr.s_addr = inet_addr("127.0.0.1");

	struct numar nr;
	nr.a = 10;
	nr.b = 20;
	sendto(sfd, &nr, sizeof(struct numar), 0, &soc, sizeof(struct sockaddr_in));
	int r,max;
	int clen=sizeof(struct sockaddr_in);
	r = recvfrom(sfd, &max, 100, 0, &soc, &clen);
	printf("%d\n", max);
	return 0;
}
