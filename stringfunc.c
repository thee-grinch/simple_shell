#include "shell.h"

/**
 **_strchr - this function is used to return the concatenated string
 *@s: the character array to be checked
 *@c: the needle to be found
 *Return: it returns a pointer pointing to that memory address to be checked
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_strncat - works as strncat but it copies the whole string
 *@dest: the end product
 *@src: the start product
 *@n: the amount of bytes to be allocated
 *Return: the return of the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strncpy - the functionis used to return the concatenated string
 *@dest: the end
 *@src: the start
 *@n: number to be copied
 *Return: string to be concatenated
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
