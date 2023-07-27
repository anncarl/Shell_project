#include "shell.h"

/**
 * is_cmd - detemining if a fille is ann excutable cmd.
 * @info: details structt.
 * @path:the pth to thee fille.
 *
 * Return:  1 if T,else 0.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars -   copies chars.
 * @pathstr:  pth str
 * @start: the beginning indexx
 * @stop: the ending indexx
 *
 * Return: ptr to the new bufer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int y = 0, z = 0;

	for (z = 0, y = start; y < stop; y++)
		if (pathstr[y] != ':')
			buf[z++] = pathstr[y];
	buf[z] = 0;
	return (buf);
}

/**
 * find_path -  searches the cmmd in the PTH str
 * @info: details struct
 * @pathstr: pth str
 * @cmd: command to search for
 *
 * Return:  whole pth of command if fund or void
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int n = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[n] || pathstr[n] == ':')
		{
			path = dup_chars(pathstr, curr_pos, n);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[n])
				break;
			curr_pos = n;
		}
		n++;
	}
	return (NULL);
}

