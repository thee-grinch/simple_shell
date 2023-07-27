#include <stdarg.h>
#include "simple_shell.h"
/**
 * free_them - frees all pointers passed to it
 * @first: the first pointer to be passed
 */
void free_them(char *first, ...)
{
	char *next;
	va_list args;

	va_start(args, first);

	while (first != NULL)
	{
		next = va_arg(args, char *);
		free(first);
		first = next;
	}
	va_end(args);
}
