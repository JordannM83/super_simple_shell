#include "main.h"
#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
    printf("Address of envp:    %p\n", (void *)envp);
    printf("Address of environ: %p\n", (void *)environ);
    return 0;
}


