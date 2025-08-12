#include "main.h"


/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    unsigned int i;
    struct stat st;

    if (ac < 2)
    {
        printf("Usage: %s path_to_file ...\n", av[0]);
        return (1);
    }
    i = 1;
    while (av[i])
    {
        printf("%s:", av[i]);
        if (stat(av[i], &st) == 0)
        {
            printf(" AH!! Il est là!\n");
        }
        else
        {
            printf(" Oups!! Il est perdu.\n");
        }
        i++;
    }
    return (0);
}
