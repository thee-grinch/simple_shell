#include "simple_shell.h"
/**
 * execute - used to execute commands
 * @s: the array of string pointers
 * @command: the command to be executed
 * Return: 1 on success
 */
int execute(char **s, char *command)
{
	printf("%s", command);
	if (execve(command, s, NULL) == -1)
		printf("Execution Err %s \n", command);
	return (1);
}
