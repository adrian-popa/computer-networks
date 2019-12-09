#include <netinet/ip.h>

struct numar{
	int a[10],n;
};

int sfd;
struct sockaddr_in soc;

int main(int argc, char argv[]){
	sfd = socket(AF_INET,SOCK_DGRAM, 0);
	
	soc.sin_family = AF_INET;
	soc.sin_port = htons(7777);
	soc.sin_addr.s_addr = inet_addr("127.0.0.1");

	struct numar nr;
	nr.n = 5 ;
	int i;
	for(int i=0;i<5;i++)
		nr.a[i]=100+i;
	sendto(sfd, &nr, sizeof(struct numar), 0, &soc, sizeof(struct sockaddr_in));
	int r,sum;
	int clen=sizeof(struct sockaddr_in);
	r = recvfrom(sfd, &sum, 100, 0, &soc, &clen);
	printf("%d\n", sum);
	return 0;
}
