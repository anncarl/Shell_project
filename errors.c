#include "shell.h"

/**
 * _eputs - printing input str.
 * @str: str printed.
 *
 * Return: Null
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 * _eputchar - wrt char c to stderr
 * @c: char to prnt
 *
 * Return: returns 1 0n success.
 * On error, -1- rtn, errno set to appropriately.
 */
int _eputchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putfd - wrt char c to fd
 * @c: char printed
 * @fd: filedescriptor to wrt
 *
 * Return: returns On success 1.
 * On error, -1-returned, errno set appropriately.
 */
int _putfd(char c, int fd)
{
	static int k;

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putsfd - printing input str,
 * @str: str printed
 * @fd:filedescriptor to wrt to
 *
 * Return: n0 of char put
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}

