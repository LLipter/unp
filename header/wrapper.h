#ifndef WARPPER_H
#define WARPPER_H


#include    "../llipter.h"



int
Socket(int domain, int type, int protocol){
    int socketfd;
    socketfd = socket(domain,type,protocol);
    if(socketfd < 0)
        err_sys("socket error");
    return socketfd;
}

void
Inet_pton(int af, const char * src, void * dst){
    int ret = inet_pton(af, src, dst);
    if(ret <= 0)
        err_sys("inet_pton error for %s", src);
}

const char *
Inet_ntop(int af, const void * src, char * dst, socklen_t size){
    const char * ret = inet_ntop(af, src, dst, size);
    if(ret == NULL)
        err_sys("inet_ntop error");
    return ret;
}


void
Connect(int socket, const struct sockaddr *address,socklen_t address_len){
    int ret = connect(socket,address,address_len);
    if(ret < 0)
        err_sys("connect error");
}

int
Bind(int socket, const struct sockaddr *address, socklen_t address_len){
    int ret;
    ret = bind(socket,address,address_len);
    if(ret < 0)
        err_sys("bind error");
    return ret;
}

void
Listen(int socket, int backlog){
    int ret = listen(socket,backlog);
    if(ret < 0)
        err_sys("linten error");
}

int
Accept(int socket, struct sockaddr * address,socklen_t * address_len){
    int fd = accept(socket,address,address_len);
    if(fd < 0)
        err_sys("accept error");
    return fd;
}

ssize_t
Write(int fildes, const void *buf, size_t nbyte){
    ssize_t ret;
    ret = write(fildes,buf,nbyte);
    if(ret < 0)
        err_sys("write error");
    return ret;
}


ssize_t
Read(int fildes, void *buf, size_t nbyte){
    ssize_t ret = read(fildes, buf, nbyte);
    if(ret < 0)
        err_sys("read error");
    return ret;
}

void
Close(int fildes){
    int ret = close(fildes);
    if(ret < 0)
        err_sys("close error");
}

pid_t
Fork(void){
    pid_t pid = fork();
    if(pid < 0)
        err_sys("fork error");
    return pid;
}

char *
Fgets(char * str, int size, FILE * stream){
    char * ret = fgets(str, size, stream);
    if(ret == NULL && ferror(stream))
        err_sys("fgets error");
    return ret;
}


void
Fputs(const char * s, FILE * stream){
    int ret = fputs(s, stream);
    if(ret == EOF)
        err_sys("fputs error");
}

int
Select(int nfds, fd_set * readfds, fd_set * writefds,fd_set * errorfds, struct timeval * timeout){
    int ret = select(nfds,readfds,writefds,errorfds,timeout);
    if(ret < 0)
        err_sys("select error");
    return ret;
}

int
Poll(struct pollfd fds[], nfds_t nfds, int timeout){
    int ret = poll(fds, nfds, timeout);
    if(ret < 0)
        err_sys("poll error");
    return ret; 
}

void
Shutdown(int socket, int how){
    int ret = shutdown(socket, how);
    if(ret < 0)
        err_sys("shutdown error");
}


ssize_t
Recvfrom(int socket, void * buffer, size_t length, int flags, struct sockaddr * address, socklen_t * address_len){
    ssize_t n = recvfrom(socket,buffer,length,flags,address,address_len);
    if(n < 0)
        err_sys("recvfrom error");
    return n;
}

ssize_t
Sendto(int socket, const void *buffer, size_t length, int flags,const struct sockaddr *dest_addr, socklen_t dest_len){
    ssize_t n = sendto(socket,buffer,length,flags,dest_addr,dest_len);
    if(n < 0)
        err_sys("sendto error");
    return n;
}


void *
Malloc(size_t size){
    void * ret = malloc(size);
    if(ret == NULL)
        err_sys("malloc error");
    return ret;
}

#endif