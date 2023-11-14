#include "main.h"

int cdfun(char **args)
{
        if (args[1] == NULL)
        {
                fprintf(stderr, "Error: cd: missing arguments\n");
                return (1);
        }
        else
        {
                if (chdir(args[1]) != 0)
                {
                        perror("Error: cd:");
                        return (1);
                }
        }
}

int exitfun(char **argv)
{
        if (argv[1])
                exit(atoi(argv[1]));
        exit(0);
        return (0);
}