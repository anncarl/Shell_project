#include "shell.h"

/**
 * _myhistory - shows histry list, 1 cmd by line- preceded
 *              with line n0s, beginning from 0.
 * @info: Struct has potential args, used for maintaining
 *        constant funct proto-type.
 *  Return: return 0 always.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set alias- str.
 * @info: the para-meter struct.
 * @str: str alias.
 *
 * Return:returns always 0- success, 1- error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - set alias- str.
 * @info:the p.meter structure.
 * @str: str alias.
 *
 * Return:returns always 0- success, 1- error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -this prints out alias str.
 * @node:  alias nod.
 *
 * Return:returns always 0 - success, 1- error.
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - copies alias builtin man alias.
 * @info: Struct has potential args, used in maintaining
 *          constant funct proto-type.
 *  Return: returns  0.
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

