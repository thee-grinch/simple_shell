#include "main.h"
/**
 * allocate - allocates a memory
 * @p: pointer to be allocated
 * @len: the length to be allocated
 * Return: the allocated pointer
 */
char *allocate(char *p, int len)
{
	p = malloc(len * sizeof(char));

	if (!p)
	{
		perror("Memory not allocated\n");
		return (NULL);
	}
	return (p);
}
