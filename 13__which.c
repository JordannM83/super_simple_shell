#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return 1;
    }
    char *path = getenv("PATH");
    if (!path) {
        fprintf(stderr, "PATH not set\n");
        return 1;
    }
    char *path_copy = strdup(path);
    if (!path_copy) {
        perror("strdup");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        char *filename = argv[i];
        char *dir = strtok(path_copy, ":");
        int found = 0;
        while (dir) {
            char fullpath[4096];
            snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, filename);
            if (access(fullpath, X_OK) == 0) {
                printf("%s\n", fullpath);
                found = 1;
                break;
            }
            dir = strtok(NULL, ":");
        }
        if (!found)
            printf("%s not found in PATH\n", filename);
        strcpy(path_copy, path); // reset for next filename
    }
    free(path_copy);
    return 0;
}


