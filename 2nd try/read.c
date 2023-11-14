#include "main.h"

char *readLine()
{
        char *line = NULL;
        size_t buflen = 0;
        ssize_t len;
        errno = 0;

        len = getline(&line, &buflen, stdin);
        if (len == -1)
        {
                if(line)
                free(line);
                if (errno)
                        perror("./shell: getline error");
                exit(0);
        }
        return (line);
}