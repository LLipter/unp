#include    <sys/socket.h>  // socket() connect() bind() listen() accept()
#include    <stdarg.h>      // va_list va_start() va_arg() va_end()
#include    <stdio.h>       // vsnprintf() printf() fputs()
                            // perror()
#include    <stdlib.h>      // exit()
#include	<arpa/inet.h>	// inet_pton() 
                            // struct sockaddr_in
#include    <unistd.h>      // write() close()

#define MAXLINE 1024
#define LISTENQ 1024

void
err_sys(const char* msg,...){
    char    msgstr[MAXLINE];
    va_list arg;
    va_start(arg,msg);
    vsnprintf(msgstr,MAXLINE,msg,arg);
    va_end(arg);
    perror(msgstr);
    exit(1);
}

int
Socket(int domain, int type, int protocol){
    int socketfd;
    socketfd = socket(domain,type,protocol);
    if(socketfd < 0)
        err_sys("socket error");
    return socketfd;
}

int
Inet_pton(int af, const char * src, void * dst){
    int ret;
    ret = inet_pton(af, src, dst);
    if(ret <= 0)
        err_sys("inet_pton error for %s", src);
    return ret;
}

int
Connect(int socket, const struct sockaddr *address,socklen_t address_len){
    int ret;
    ret = connect(socket,address,address_len);
    if(ret < 0)
        err_sys("connect error");
    return ret;
}

int
Bind(int socket, const struct sockaddr *address, socklen_t address_len){
    int ret;
    ret = bind(socket,address,address_len);
    if(ret < 0)
        err_sys("bind error");
    return ret;
}

int
Listen(int socket, int backlog){
    int ret;
    ret = listen(socket,backlog);
    if(ret < 0)
        err_sys("linten error");
    return ret;
}

int
Accept(int socket, struct sockaddr * address,socklen_t * address_len){
    int ret;
    ret = accept(socket,address,address_len);
    if(ret < 0)
        err_sys("accept error");
    return ret;
}

ssize_t
Write(int fildes, const void *buf, size_t nbyte){
    int ret;
    ret = write(fildes,buf,nbyte);
    if(ret < 0)
        err_sys("write error");
    return ret;
}

int
Close(int fildes){
    int ret;
    ret = close(fildes);
    if(ret < 0)
        err_sys("close error");
    return ret;
}