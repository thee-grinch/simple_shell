#include "simple_shell.h"

/**
 * main - is the simple shell main function
 * @argc: the argument count
 * @argv: the argument vector
 * Return: 0 in success
 */
int main(int argc, char *argv[])
{
	char *buff, *buffcpy;
	size_t n = 0;
	int readchars, count, i;
	char *token = NULL, *pathcpy = NULL, *pathcheck = NULL, *command = NULL;
	(void)argc;
	while (1)
	{
		readchars = getline(&buff, &n, stdin);
		buffcpy = malloc(sizeof(char) * readchars + 1);
		if (!buffcpy)
		{
			perror("Memory allocation error");
			free(buff);
			return (-1);
		}
		_strcpy(buffcpy, buff);
		if (readchars == -1)
			break;
		count = calculate_tokens(buffcpy);
		argv = malloc(sizeof(char *) * (count + 1));
		if (!argv)
		{
			perror("memory allocation error\n");
			return (-1);
		}
		tokenize(buff, argv);
		for (i = 0; argv[i] != NULL; i++)
		{
			puts(argv[i]);
		}
		command = _which(argv[0], token, pathcheck, pathcpy);
		execute(argv, command);
		free_them(buff, buffcpy, token, pathcpy, pathcheck, command);
		if (argv)
			free_all(argv);
	}
	return (0);
}
