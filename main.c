#include "main.h"

int main(void)
{
        char *line, **tokens;
        int status;
        while (1)
        {
                line = read_line();
                tokens = split_line(line);

                if (tokens)
                {
                        exit(execfun(tokens));
                        free(tokens);
                }
                free(line);
        }
}