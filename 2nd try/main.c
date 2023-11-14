#include "main.h"

int main(void)
{
        char *line, **tokens;
        /*char *prompt = ">>> ";*/
        while(1)
        {
                line = readLine();
                tokens = parse(line);

                if (tokens[0])
                        execfun(tokens);
                
                free(tokens);
                free(line);
        }
        
        return (0);
}