#include "main.h"
#include <unistd.h>
/**
 * execute - used to execute commands
 * @s: the array of string pointers
 * Return: 1 on success
 */
int execute(char **s, char *command)
{
	printf("%s", command);
	if (execve(command, s, NULL) == -1)
		printf("Execution Err %s \n", command);
	return (1);
}
/**
 * _which - returns the location of a function
 * @command: the command tobe checked 
 * Return: the location or NULL if not true
 */
char *_which(char *command)
{
	char *path = NULL, *token = NULL, *pathcheck = NULL, *pathcpy = NULL;
	int i;
	struct stat fileStat;

	if (command[0] == '/')
		return (command);
	path = getenv("PATH");
	pathcpy = malloc((_strlen(path) + 1) * sizeof(char));
	_strcpy(pathcpy, path);
	token = strtok(pathcpy, ":");
	for (i = 0; token != NULL; i++)
	{
		pathcheck = malloc((strlen(command) + strlen(token) + 2) * sizeof(char));
		if (!pathcheck)
		{
			perror("Malloc failed");
			return (NULL);
		}
		_strcpy(pathcheck, token);
		_strcat(pathcheck, "/");
		_strcat(pathcheck, command);
		if (stat(pathcheck, &fileStat) != -1)
		{
			return (pathcheck);
		}
		free(pathcheck);
		pathcheck = NULL;
		token = strtok(NULL, ":");
	}
	return (NULL);
}

