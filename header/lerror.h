#ifndef LERROR_H
#define LERROR_H

#include    "../llipter.h"

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


#endif