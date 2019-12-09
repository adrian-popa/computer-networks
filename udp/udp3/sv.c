#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>

struct numar{
	int a[10],n;
};

struct sockaddr_in soc, csoc;
int sfd,r;
int main(int argc,char argv[]){
	int clen = sizeof(struct sockaddr_in);
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	
	soc.sin_family = AF_INET;
	soc.sin_port = htons(7777);
	soc.sin_addr.s_addr = inet_addr("0.0.0.0");

	bind(sfd, &soc, sizeof(struct sockaddr_in));
	
	struct numar x;
	int s=0;
	r= recvfrom(sfd,&x, 100,0, &csoc, &clen);
       	int i;
	for (i=0;i<x.n;i++)
		s+=x.a[i];
	//printf("%d\n",max);	
	sendto(sfd, &s, sizeof(int), 0, &csoc, sizeof(struct sockaddr_in));
	return 0;
}
