#include "shell.h"

/**
 * _strlen - return length of  str.
 * @s:  str- length to confirm
 *
 * Return: int length of str
 */
int _strlen(char *s)
{
	int k = 0;

	if (!s)
		return (0);

	while (*s++)
		k++;
	return (k);
}

/**
 * _strcmp -  performing lexicogarphic comparison of 2 strs
 * @s1: 1st str
 * @s2:  2nd str
 *
 * Return: -ve if s1 < s2, +ve if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - confirms whether needle is  starting with haystack
 * @haystack:the  str to search
 * @needle: substring to find
 *
 * Return:  addr of next char of haystack or void
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this concatenates 2 strs
 * @dest:  final buffer
 * @src:  src buffer
 *
 * Return:  ptr to the final buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

