#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"
/**
 * _handle_cd - changes directory
 * @env: env vars
 * @tmp_args: array of args
 * @buffer: a buffer
 * Return: Nothing
*/
void _handle_cd(char **env, char **tmp_args, char **buffer)
{
	int res, i;
	char *name;

	for (i = 0; env[i] != NULL; i++)
	{
		buffer[i] = strdup(env[i]);
		name = strtok(buffer[i], "=");
		res = strcmp(name, "HOME");
		if (res == 0)
		{
			name = strtok(NULL, "=");
			if (tmp_args[1] == NULL)
			{
				chdir(name);
			}
			else
			{
			       chdir(tmp_args[1]);
			}
		}
	}
}
