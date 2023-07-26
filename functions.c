#include "main.h"

/* String Functions */
/**
 * _strlen - calculates the string length
 * @s: the string length to be calculated
 * Return: the string length
 */
int _strlen(char *s)
{
	if (!s || *s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}
/**
 * _strcpy - copies a string
 * @source: the source
 * @destination: the destination
 * Return: the dest
 */
char *_strcpy(char *destination, char *source)
{
	int len = _strlen(source);
	int i;

	for (i = 0; i < len; i++)
		destination[i] = source[i];
	destination[i] = '\0';
	return (destination);
}
/**
 * tokenize - makes a line as an array of tokens
 * @ptr: the pointer of the line to be tokenized
 * @tokenized_array: the array to be tokenized
 * Return: the tokenized string
 */
char **tokenize(char *ptr, char **tokenized_array)
{
	int i = 0;
	char *token;

	if (!tokenized_array)
	{
		perror("memory not allocated\n");
		return (NULL);
	}

	token = strtok(ptr, " \t\n\0");
	for (i = 0; token != NULL; i++)
	{
		tokenized_array[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (tokenized_array[i] == NULL)
		{
			release_memory(tokenized_array);
			return (NULL);
		}
		_strcpy(tokenized_array[i], token);

		token = strtok(NULL, " \t\n\0");
	}
	return (tokenized_array);
}
/**
 * calculate_tokens - calculates the number of tokens
 * @s: the string to be caclucated
 * Return: the number of tokens
 */
int calculate_tokens(char *s)
{
	int count = 0;
	char *dup;
	char *tok;

	dup = malloc((_strlen(s) + 1) * sizeof(char));
	_strcpy(dup, s);
	tok = strtok(dup, " \t\n\r");
	while (tok)
	{
		count++;
		tok = strtok(NULL, " \t\n\r");
	}
	return (count);
}
/**
 * release_memory - releases a memory
 * @s: the pointer to be freed
 */
void release_memory(char **s)
{
	int i;

	for (i = 0; s[i] != NULL; i++)
	{
		free(s[i]);
	}
	free(s);
}
