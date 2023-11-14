#include "main.h"

void execfun(char **args)
{
        int status;
        pid_t pid;

        if (strcmp(args[0], "cd") == 0)
                cdfun(args);
        else if (strcmp(args[0], "exit") == 0)
                exitfun(args);

        pid = fork();
        if (pid > 0)
        {
                do
                {
                        waitpid(pid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        else if (pid == 0)
        {
                _execvp_(args);
                fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
                exit(127);
        }
        else
        {
                fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
                exit(127);
        }
}