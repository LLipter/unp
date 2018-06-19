#ifndef SIG_H
#define SIG_H

#include    "../llipter.h"

typedef void Sigfunc(int);


void
sig_chld(int signo)
{
	pid_t	pid;
	int		stat;

	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
		printf("child %d terminated\n", pid);
	return;
}


Sigfunc *
lsignal(int signo, Sigfunc *func)
{
	struct sigaction	act, oact;

	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (signo == SIGALRM) {
#ifdef	SA_INTERRUPT
		act.sa_flags |= SA_INTERRUPT;	/* SunOS 4.x */
#endif
	} else {
#ifdef	SA_RESTART
		act.sa_flags |= SA_RESTART;		/* SVR4, 44BSD */
#endif
	}
	if (sigaction(signo, &act, &oact) < 0)
		return(SIG_ERR);
	return(oact.sa_handler);
}
/* end lsignal */

Sigfunc *
Signal(int signo, Sigfunc *func)	/* for our lsignal() function */
{
	Sigfunc	*sigfunc;

	if ( (sigfunc = lsignal(signo, func)) == SIG_ERR)
		err_sys("lsignal error");
	return(sigfunc);
}


#endif