#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <paths.h>


#define LINEBUF 1024
#define ARGBUF  64
#define DELIMIT " \t\r\n\a"

char    *readLine();
char    **parse(char *);
void    execfun(char **);
void    cdfun(char **);
void    exitfun(char **);
char    *_getenv(const char *);


#define BUILTIN_NUM ((sizeof(builtins)) / (sizeof(builtin)))
#endif