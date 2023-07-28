#include "shell.h"


/**
 * _eputchar - prints to the stderr
 * @c: character to be printed
 *
 * Return:this is function, check the code
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 *_eputs - prints a string
 * @str: the string to be printed
 *
 * Return: This returns the return function
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 *_putsfd - prints a char to the given fd
 * @str: string to be printed to the given fd
 * @fd: the fd to be printed to
 *
 * Return: this is the number of strings that will be put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

/**
 * _putfd - writes a character to the given file desfripror
 * @c: this is the character to be printed on the given fd
 * @fd: The fd to be written to
 *
 * Return: On failure it returns the -1
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
