#include "main.h"
/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */

char *prompt = "My shell $ ";
char *lineptr = NULL;
size_t n = 0;
ssize_t chartyped;
const char *delim = " \n";
char *token;
char *lineptr_copy = NULL;
int num_tokens = 0;
int i;

int main(int ac, char **argv)
{
	(void)ac;
	while (1)
	{
		printf("%s", prompt);

		chartyped = getline(&lineptr, &n, stdin);

		if (chartyped == -1)
		{
		printf("shell is closing...\n");
		return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * chartyped);

		if (lineptr_copy == NULL)
		{
			perror("memory allocation fail");
			return (-1);
		}
		strcpy(lineptr_copy, lineptr);

		token = strtok(lineptr, " \n");
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, " \n");
		}
		num_tokens++;

		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(lineptr_copy, " \n");

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;
	execmd(argv);
	free(lineptr_copy);
	}
	return (0);
}
