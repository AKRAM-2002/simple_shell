#include "shell.h"
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * _find_path - findes the path of a given command
 * @env: env variables.
 * @tmp_args: arrays of command args
 * @buffer: a tmp storage variable
 * Return: Nothing
*/
void _find_path(char **env, char **tmp_args, char **buffer)
{
	int res, i;
	char *name;
	char tmp_path[100];
	struct stat st;

	for (i = 0; env[i] != NULL; i++)
	{
	buffer[i] = strdup(env[i]);
	name = strtok(buffer[i], "=");
	res = strcmp(name, "PATH");
	if (res == 0)
		{
		name = strtok(NULL, "=");
		name = strtok(name, ":");
		while (name != NULL)
			{
			strcpy(tmp_path, name);
			strcat(tmp_path, "/");
			strcat(tmp_path, tmp_args[0]);
			if (stat(tmp_path, &st) == 0)
				{
				_exec_path(tmp_path, tmp_args, env);
				break;
				}
			else
				{
				name = strtok(NULL, ":");
				}
			}
		}
	}
}
