#ifndef LERROR_H
#define LERROR_H

#include    "../llipter.h"
#include    <stdarg.h>      // va_list va_start() va_arg() va_end()
#include    <stdio.h>       // vsnprintf() printf() fputs()
                            // perror()
#include    <stdlib.h>      // exit()



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