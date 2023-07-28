#include "shell.h"


/**
 * _realloc - acts as a realloc function
 * @ptr: pointer to be alocated
 * @old_size: size of previously allocated memory
 * @new_size: size to be allocated
 *
 * Return: the reallocated pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * ffree - frees a double pointer
 * @pp: string to be freed
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
/**
 **_memset - acts as memset function
 *@s: ponter of the memory
 *@b: byte to be filled
 *@n: the number of chars
 *Return: always returns a pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
