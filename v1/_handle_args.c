#include "shell.h"
#include <string.h>
/**
 * _handle_args - cut the input string and stores each arg into
 * an array of strings.
 * @tmp_args: array of args
 * @inputcmd: array of the users input
 * Return: Nothing
*/

void _handle_args(char **tmp_args, char inputcmd[100])
{
	char *tmp_token = NULL;
	int tmp_i = 0;
	char tmp_cmd[100];

	_strcpy(tmp_cmd, inputcmd);
	tmp_token = strtok(tmp_cmd, " ");
	while (tmp_token != NULL)
	{
		tmp_args[tmp_i++] = _strdup(tmp_token);
		tmp_token = strtok(NULL, " ");
	}
	tmp_args[tmp_i] = NULL;
}
