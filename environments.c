#include "shell.h"


/**
 * _getenv - This function gets ytyhe valie of a variable
 * @info: Icludeas all the parameters requires
 * @name: value of env parameter name
 *
 * Return: the value of the variable function
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialises a new variable endwe
 * @info: Continues the the all prototypes
 *  Return: Can return either zero or 1
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


/**
 * populate_env_list - This is used to populate the environment list
 * @info: My required function [parameters
 * Return: Always zero or one
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
/**
 * _myunsetenv - used to remove an enviroment variable
 * @info: This is the function of all envp prototypes
 *  Return: This is my printed environment variables
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}
/**
 * _myenv - This function is used to shew the current environment
 * @info: This is the struct containing all to running of the function
 * Return: it eturns sucess which is zero
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
