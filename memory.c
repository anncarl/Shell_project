#include "shell.h"

/**
 * bfree - freees a ptr and voids the addr.
 * @ptr: addr of the ptr to freee.
 *
 * Return: if freed,1, 0 else.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

