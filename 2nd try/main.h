#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <paths.h>
#include <stdbool.h>
#include <alloca.h>
#include <sys/stat.h>

#define LINEBUF 1024
#define ARGBUF  64
#define DELIMIT " \t\r\n\a"

extern char **environ;
char    *readLine();
char    **parse(char *);
void    execfun(char **);
void    cdfun(char **);
void    exitfun(char **);
char    *_getenv(const char *);
void    _execvp_(char **);
char    *getlocat(char *cmd);


#define BUILTIN_NUM ((sizeof(builtins)) / (sizeof(builtin)))
#endif