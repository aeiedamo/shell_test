#include "main.h"

struct builtin builtins[] = {
        {"cd", cdfun},
        {"exit", exitfun}
};

int builtins_num()
{
        return (sizeof(builtins) / sizeof (struct builtin));
}

int execfun(char **args)
{
        int i;
        pid_t childpid;
        int status = 0;
        for (i = 0; i < builtins_num(); i++)
        {
                if (strcmp(args[0], builtins[i].name) == 0)
                {
                        builtins[i].fun(args);
                        return (1);
                }
        }
        childpid = fork();
        if (childpid == 0)
        {
                status = execvp(args[0], args);
                perror("Error: ");
                return (1);
        }
        else if (childpid > 0)
        {
                do
                {
                        waitpid(childpid, &status, WUNTRACED);
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
                return (0);
        }
        else
        {
                perror("Error: ");
                return (0);
        }
}