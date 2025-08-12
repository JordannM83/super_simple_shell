#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
    if (!name || !*name || strchr(name, '='))
        return -1;
    size_t name_len = strlen(name);
    size_t i = 0, j = 0;
    for (; environ[i]; i++) {
        if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=') {
            free(environ[i]);
            continue;
        }
        environ[j++] = environ[i];
    }
    environ[j] = NULL;
    return 0;
}


