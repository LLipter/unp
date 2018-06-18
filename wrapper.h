#ifndef WARPPER_H
#define WARPPER_H


#include    "llipter.h"
#include    <sys/socket.h>  // socket() connect() bind() listen() accept()
#include	<arpa/inet.h>	// inet_pton() inet_ntop()
#include    <unistd.h>      // write() close()


#define LISTENQ 1024



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

const char *
Inet_ntop(int af, const void * src, char * dst, socklen_t size){
    const char * ret;
    ret = inet_ntop(af, src, dst, size);
    if(ret == NULL)
        err_sys("inet_ntop error");
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


#endif