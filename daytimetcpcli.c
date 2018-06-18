#include	"llipter.h"
#include	<string.h>



int
main(int argc, char **argv)
{
	int					sockfd, n;
	char				recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;
	char				emsg[MAXLINE + 1];

	if (argc != 2)
		err_sys("usage: a.out <IPaddress>");

	sockfd = Socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	Inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			perror("fputs error"),exit(1);
	}
	if (n < 0)
		perror("read error"),exit(1);

	exit(0);
}
