#include "simple_shell.h"

/**
 * _strlen - calculates the length of a string
 * @s: the string to be calculated the length
 * Return: the length of a string
 */
int _strlen(char *s)
{
	if (*s == '\0' || s == NULL)
		return (0);
	return (1 + _strlen(s + 1));
}
