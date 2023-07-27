#include "simple_shell.h"

/**
 * free_all - frees a double array
 * @argv: the argument array
 */
void free_all(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
