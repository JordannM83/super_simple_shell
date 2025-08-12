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
		if (nread == -1) {
			break; // EOF or error
		}
		printf("%s", line);
		char **words = split_string(line);
		if (words) {
			for (int i = 0; words[i]; i++) {
				printf("word[%d]: %s\n", i, words[i]);
				free(words[i]);
			}
			free(words);
		}
	}
	free(line);
	return 0;
}
