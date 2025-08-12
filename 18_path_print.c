#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *path = getenv("PATH");
    if (!path) {
        fprintf(stderr, "PATH not found\n");
        return 1;
    }
    char *copy = strdup(path);
    if (!copy) {
        perror("strdup");
        return 1;
    }
    char *dir = strtok(copy, ":");
    while (dir) {
        printf("%s\n", dir);
        dir = strtok(NULL, ":");
    }
    free(copy);
    return 0;
}
