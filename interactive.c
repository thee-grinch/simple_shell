#include "shell.h"


/**
 *_atoi - An atoi function checks a character string if it is true or false
 *@s: string to be converted to an oint
 *Return: If no numbers in the string it returns zero or once therwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * is_delim - This function determines wheter a caharacter is a delimeter
 * @c: This is the character to be liseterd
 * @delim: This string inputs a character array of delimeters
 * Return: The function returns 1 or zero if otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * interactive - vbfgv gfbh tyhrgbbrtbtgb  5ht5 tt
 * @info: This is a struct pointer to be checked
 *
 * Return: If in  interactive mode it returns 1, or it returns zero f otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_isalpha - The function checks the character if it is an alphabet
 *@c: this is the chaaracter to be checked
 *Return: The function checks wheter the function is a zero or a one
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
