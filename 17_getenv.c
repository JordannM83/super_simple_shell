#include "main.h"


#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
    size_t len = 0;
    if (!name)
        return NULL;
    len = strlen(name);
    for (char **env = environ; *env != NULL; env++) {
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=') {
            return *env + len + 1;
        }
    }
    return NULL;
}

int main(int ac, char **av, char **env)
{
    // Example usage:
    const char *var = "PATH";
    char *value = _getenv(var);
    if (value)
        printf("%s=%s\n", var, value);
    else
        printf("%s not found\n", var);
    return 0;
}
