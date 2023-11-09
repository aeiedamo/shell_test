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
                _execvp_(args[0], args);
                printf("./hsh: 1: %s:", args[0]);
                perror(NULL);
                exit(1);
        }
        else
        {
                perror("./shell: 1:");
                printf("./hsh: 1: %s:", args[0]);
                perror(NULL);
                exit(1);
        }
}