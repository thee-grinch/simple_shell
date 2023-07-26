#include "main.h"
/**
 * _strcat - The function is used to concatenate 2 strings
 * @source: the source string
 * @destination: the destination string
 * Return: the destination string;
 */
char *_strcat(char *destination, char *source)
{
	int a, b;

	while (destination && source)
	{
		for (a = 0; destination[a] != '\0'; a++)
			;
		for (b = 0; source[b] != '\0'; b++)
		{
			destination[a++] = source[b];
		}
		destination[a] = '\0';
		return (destination);
	}
	return (NULL);
}
