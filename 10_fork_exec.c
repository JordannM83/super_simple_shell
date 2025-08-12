#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_pid;
    int status;

	for (int i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			char *argv[] = {"/bin/ls", "-l", "/home/jordann/super_simple_shell", NULL};

			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
	}
    return (0);
}
