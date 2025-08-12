#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *str)
{
    char *token;
    char **words = NULL;
    int count = 0;
    char *copy;

    if (!str)
        return NULL;

    copy = strdup(str);
    if (!copy)
        return NULL;

    token = strtok(copy, " \t\n");
    while (token)
    {
        char **tmp = realloc(words, sizeof(char *) * (count + 2));
        if (!tmp)
        {
            free(copy);
            for (int i = 0; i < count; i++)
                free(words[i]);
            free(words);
            return NULL;
        }
        words = tmp;
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, " \t\n");
    }
    free(copy);
    if (words)
        words[count] = NULL;
    return words;
}
