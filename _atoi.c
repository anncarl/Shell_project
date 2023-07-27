#include "shell.h"

/**
 * interactive - return T when shell is in interactive mode
 * @info:contains the struct address.
 *
 * Return: returns 1 when interactive mode, otherwise 0.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - check char if its a delimeter.
 * @c:  char to be checked.
 * @delim: delimeter str.
 * Return: 1-true, 0- false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - check alpha-betic char.
 * @c:char to input.
 * Return: returns 1 if c is alpha-betic,if otherwise 0.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - alters str to int.
 * @s:  str to be converted.
 * Return: returns 0 when no n0 in str, converted n0, otherwise.
 */

int _atoi(char *s)
{
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0; s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
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

