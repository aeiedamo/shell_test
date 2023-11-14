#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

char *read_line();
char **split_line(char *line);
int execfun(char **);
int cdfun(char **);
int exitfun(char **);


struct builtin {
        char *name;
        int (*fun)(char **args);
};

int builtins_num();
#endif