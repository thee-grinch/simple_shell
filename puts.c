#include "simple_shell.h"

/**
 * _putchar - prints a char
 * @c: the character to be printed
 * Return: either one or zero
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - prints a string to the std out
 * @s: the string to be printed
 */
void _puts(char *s)
{
	int i;

	if (s)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
	}
}
