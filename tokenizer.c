#include "simple_shell.h"

/**
 * tokenize - splits a string in to an array of tokens
 * @s: the string to be tokenized
 * @argv: the array they should be put;
 */
void tokenize(char *s, char *argv[])
{
	char *token;
	int i;
	int len;

	token = strtok(s, " \t\n\r");
	for (i = 0; token != NULL; i++)
	{
		len = _strlen(token);
		argv[i] = malloc(sizeof(char) * (len + 1));
		_strcpy(argv[i], token);
		token = strtok(NULL, " \t\r\n");
	}
	argv[i] = NULL;
}
