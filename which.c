#include "simple_shell.h"
/**
 * _which - returns the location of a function
 * @command: the path
 * @token: the token to be trancated
 * @pathcheck: the path to be checked whether it exists
 * @pathcpy: the copy of the path;
 * Return: the location or NULL if not true
 */
char *_which(char *command, char *token, char *pathcheck, char *pathcpy)
{
	char *path;
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
			free(path);
			return (pathcheck);
		}
		free(pathcheck);
		pathcheck = NULL;
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
