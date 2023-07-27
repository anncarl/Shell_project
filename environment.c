#include "shell.h"

/**
 * _myenv - print present environ.
 * @info: Struct has arg for maintaining
 *          constant funct proto-type.
 * Return: returns 0 always.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - acquires val of an env variable.
 * @info: struct has potential args, for  maintaining
 * @name: the environ variable name
 *
 * Return: val
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Init  new env var,
 *             or modify an existing one
 * @info: Struct has potential args, for maintaining
 *        constant funct proto-type.
 *  Return: returning 0 always,
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Removes an env variable
 * @info: Structure contains potential arguments. Used in maintaining
 *        constant function prototype.
 * Return: returns Always 0
 */
int _myunsetenv(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);

	return (0);
}

/**
 * populate_env_list - gets envi linked_list,
 * @info: Struct has ptl args,for maintaining
 *          constant func proto-type.
 * Return: returning 0 always.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

