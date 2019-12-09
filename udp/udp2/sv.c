#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>

struct numar{
	int a,b;
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
	
	struct numar n;
	int max;
	r= recvfrom(sfd,&n, 100,0, &csoc, &clen);
       	if(n.a>n.b)
		max = n.a;
	else 
		max = n.b;	
	//printf("%d\n",max);	
	sendto(sfd, &max, sizeof(int), 0, &csoc, sizeof(struct sockaddr_in));
	return 0;
}
