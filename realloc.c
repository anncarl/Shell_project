#include "shell.h"

/**
 * _memset - fils mem wit a constant bte
 * @s:  ptr to the mem location
 * @b:  bte to fil *s wit
 * @n:  amt of byte to be filed
 * Return: (s) a ptr to the mem location s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
		s[k] = b;
	return (s);
}

/**
 * ffree - free a str of strs
 * @pp: str of strs
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - re-allocates  blk of mem
 * @ptr:  ptr to last malloc ated blk
 * @old_size:the bytte siize of last blk
 * @new_size:the bytte sizze of new blk
 *
 * Return:  ptr to the old blk
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

