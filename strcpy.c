#include "simple_shell.h"

/**
 * _strcpy - acts as a string copy function
 * @src: the source strind
 * @dest: the string destination
 * Return: the destination of the string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
