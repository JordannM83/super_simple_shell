#include "main.h"

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while (1)
    {
        printf("$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
            break;
        char **args = split_string(line);
        if (args && args[0]) {
            pid_t pid = fork();
            if (pid == 0) {
                execvp(args[0], args);
                perror("execvp");
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                wait(NULL);
            } else {
                perror("fork");
            }
            for (int i = 0; args[i]; i++)
                free(args[i]);
            free(args);
        }
    }
    free(line);
    return 0;
}

