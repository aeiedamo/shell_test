#include "main.h"

char *read_line()
{
        char *line = NULL;
        size_t n = 0;
        errno = 0;
        ssize_t l = getline(&line, &n, stdin);
        if (l < 0)
        {
                if (errno)
                        perror("Error: ");
                exit(1);
        }
        return (line);
}

char **split_line(char *line)
{
        int len = 0, cap = 16;
        char *delimit = " \n\t";
        char *token;
        char **tokens = malloc(cap * sizeof(char *));
        if (!tokens)
        {
                perror("Error: ");
                exit(1);
        }
        token = strtok(line, delimit);
        while(token)
        {
                tokens[len++] = token;
                if (len >= cap)
                {
                        cap *= 2;
                        tokens = realloc(tokens, cap * sizeof(char *));
                        if (!token)
                        {
                                perror("Error: ");
                                exit(1);
                        }
                }
                token = strtok(NULL, delimit);
        }
        tokens[len] = NULL;
        return (tokens);

}