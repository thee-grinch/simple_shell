#include "simple_shell.h"
/**
 * _strcat - concatenates twos trings
 * @src: the source string
 * @dest: the destination string
 */
void _strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0';  j++)
	{
		dest[i++] = src[j];
	}
	dest[i] = '\0';
}
