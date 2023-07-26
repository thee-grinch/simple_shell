#include "main.h"
/**
 * _putchar - prints a character
 * @c: the char to be printed
 * Return: always one
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - puts a string to the standard output
 * @s: the string to be printed
 */
void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
	}
}
