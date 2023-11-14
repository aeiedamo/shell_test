#include "main.h"

int main(int argc, char **argv)
{
        char *prompt = "A&M >>> ";
        char *line = NULL, *linecpy = NULL;
        size_t n = 0;
        ssize_t read_chars;
        int tokens = 0;
        char *token;
        int i;
        const char *delimit = " \n\t\r\v";

        (void) argc;

        do
        {
                printf("%s", prompt);
                read_chars = getline(&line, &n, stdin);
                if (read_chars == -1)
                {
                        printf("...Exiting...");
                        return (-1);
                }
                linecpy = malloc(read_chars * sizeof(char));
                if (!linecpy)
                {
                        perror("./shell: memory allocation error");
                        return (-1);
                }

                strcpy(linecpy, line);
                token = strtok(line, delimit);
                while (token)
                {
                        tokens++;
                        token = strtok(NULL, delimit);
                }
                tokens++;
                argv = malloc(tokens * sizeof(char *));
                token = strtok(linecpy, delimit);
                for (i = 0; token; i++)
                {
                        argv[i] = malloc(strlen(token) * sizeof(char));
                        strcpy(argv[i], token);
                        token = strtok(NULL, delimit);
                }
                argv[i] = NULL;
                execcmd(argv);
        } while(1);

        free(line);
        free(linecpy);
        return (0);
        
}