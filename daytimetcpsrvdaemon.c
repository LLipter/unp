#include	"llipter.h"
#include	<time.h>
#include	<string.h>


int
main(int argc, char **argv)
{
	daemonize("daytimetcpsrv daemonizing");

	int					listenfd, connfd, logfd;
	socklen_t			len;
	struct sockaddr_in	servaddr, cliaddr;
	char				buff[MAXLINE];
	time_t				ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(13);	/* daytime server */

	Bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	int oflag = O_WRONLY | O_APPEND | O_CREAT;
	int mode = 0644;
	logfd = open("daytimelog.txt", oflag, mode);

	for ( ; ; ) {
		len = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *) &cliaddr, &len);
        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		dprintf(logfd ,"%.24s connection from %s, port %d\n", ctime(&ticks),
			   Inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)),
			   ntohs(cliaddr.sin_port));
        Write(connfd, buff, strlen(buff));

		Close(connfd);
	}
}
