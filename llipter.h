#ifndef LLIPTER_H
#define LLIPTER_H

#define SERV_PORT   7614
#define MAXLINE     1024
#define LISTENQ     1024

#include    <string.h>          // bzero()
#include    <stdarg.h>          // va_list va_start() va_arg() va_end()
#include    <stdio.h>           // vsnprintf() printf() fputs()
                                // perror()
#include    <stdlib.h>          // exit()
#include	<sys/stat.h>		// umask()
#include	<sys/resource.h>	// getrlimit()
#include	<signal.h>			// sigemptyset() sigaction()
#include	<fcntl.h>			// open()
#include	<syslog.h>			// openlog() syslog()
#include    <sys/socket.h>      // socket() connect() bind() listen() accept() shutdown()
#include    <sys/wait.h>        // waitpid()
#include    <sys/select.h>      // select()
#include    <poll.h>            // poll()
#include	<arpa/inet.h>	    // inet_pton() inet_ntop()
#include    <unistd.h>          // write() close() chdir() dup()
                                // setsid() fork()
#include    <errno.h>           // errno
#include    <math.h>

#include    "header/lerror.h"
#include    "header/wrapper.h"
#include    "header/daemon.h"
#include    "header/readwrite.h"
#include    "header/sig.h"



int lmax(int a,int b){
    return a > b ? a : b;
}



#endif