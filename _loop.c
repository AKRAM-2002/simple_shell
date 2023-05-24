#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
/**
 * _loop - main function
 * @env: array of env variables
 * @buffer: buffer
 * @av: user command
 * Return: 0 on success&exit
*/
void _loop(char **buffer, char **env, char **av)
{
	char *prompt = " ($) ";
	int loop = 1;
	char inputcmd[100];
	char *input = NULL;
	char *tmp_args[10];
	ssize_t n = 0;
	int input_res;
	struct stat sst;

	while (1 && loop == 1)
	{
		if (isatty(STDIN_FILENO) == 0)
			loop = 0;
		if (loop != 0)
			write(STDOUT_FILENO, prompt, strlen(prompt));
		input_res = _get_user_input(n, inputcmd, input);
		if (input_res == 1)
			break;
		_handle_args(tmp_args, inputcmd);
		if (strcmp(tmp_args[0], "cd") == 0)
		{
			_handle_cd(env, tmp_args, buffer);
			_update_PWD(env);
		}
		if (stat(tmp_args[0], &sst) == 0)
		{
			_exec(tmp_args, env);
		}
		else
			_find_path(env, tmp_args, buffer, av);
	}
	free(input);
}
