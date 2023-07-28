#include "shell.h"

/**
 * bfree - it frees the pointer and sets the address equal to null
 * @ptr: to be freed
 *
 * Return: always success
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
