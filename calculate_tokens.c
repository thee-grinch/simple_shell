#include "simple_shell.h"

/**
 * calculate_tokens - cac=lculatesx tokens in a string
 * @s: the string to be calculated
 * Return: the count of tokens
 */
int calculate_tokens(char *s)
{
	char *token;
	int count = 0;
	char *seperator = " \t\n\r";

	token = strtok(s, seperator);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, seperator);
	}
	return (count);
}
