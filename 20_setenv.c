#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
    if (!name || !*name || strchr(name, '='))
        return -1;
    size_t name_len = strlen(name);
    size_t value_len = strlen(value ? value : "");
    char *new_var = malloc(name_len + value_len + 2); // name=value\0
    if (!new_var)
        return -1;
    sprintf(new_var, "%s=%s", name, value ? value : "");
    for (char **env = environ; *env != NULL; env++) {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=') {
            if (overwrite) {
                *env = new_var;
            } else {
                free(new_var);
            }
            return 0;
        }
    }
    // Not found, add new variable
    size_t count = 0;
    while (environ[count]) count++;
    char **new_environ = realloc(environ, sizeof(char *) * (count + 2));
    if (!new_environ) {
        free(new_var);
        return -1;
    }
    environ = new_environ;
    environ[count] = new_var;
    environ[count + 1] = NULL;
    return 0;
}


