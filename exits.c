#include "shell.h"

/**
 **_strncpy -dublicates str.
 *@dest:final str to be duplicated to
 *@src:  src str
 *@n:  amt of char to be dublicated
 *Return: returns concatenated str.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int k, p;
	char *s = dest;

	k = 0;
	while (src[k] != '\0' && k < n - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < n)
	{
		p = k;
		while (p < n)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (s);
}

/**
 **_strncat -this concatenates 2 str
 *@dest: 1st str
 *@src: 2nd str
 *@n: amt of bytes to maxim use.
 *Return:returns concatenated str
 */
char *_strncat(char *dest, char *src, int n)
{
	int k, p;
	char *s = dest;

	k = 0;
	p = 0;
	while (dest[k] != '\0')
		k++;
	while (src[p] != '\0' && p < n)
	{
		dest[k] = src[p];
		k++;
		p++;
	}
	if (p < n)
		dest[k] = '\0';
	return (s);
}

/**
 **_strchr -identifies a char in a str
 *@s:  str to parse
 *@c:  char to look
 *Return: returns (s) a ptr to the mem area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

