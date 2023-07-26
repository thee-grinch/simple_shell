#include "main.h"
/**
 * printprompt - prints a prompt
 */
void printprompt(void)
{
	_puts("($) ");
}
/**
 * main - acts as a simple shell
 * @argc: the argument counter
 * @argv: the argument vector
 * Return: zero on success
 */
int main(int argc, char *argv[])
{
	char *buffer, *buffercpy, *command;
	size_t n;
	ssize_t chars;
	pid_t child;
	int status;

	while (1)
	{
		printprompt();
		chars = getline(&buffer, &n, stdin);
		if (chars == -1)
		{
			printf("exiting\n");
			return (-1);
		}
		argc = calculate_tokens(buffer);
		buffercpy = allocate(buffercpy, chars);
		_strcpy(buffercpy, buffer);
		argv = malloc(sizeof(char *) * argc);
		if (!argv)
			perror("Memory allocation error\n");
		tokenize(buffercpy, argv);
		command  = _which(argv[0]);
		if (!command)
		{
			perror(argv[0]);
			continue;
		}
		child = fork();
		if (child < 0)
			perror("Fork failed\n");
		else if (child == 0)
			execute(argv, command);
		else
			wait(&status);
	}
	free(buffer);
	free(buffercpy);
	release_memory(argv);
	return (0);
}
