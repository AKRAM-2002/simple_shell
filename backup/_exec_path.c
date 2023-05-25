#include "shell.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/**
 * _exec_path - finds the path of a command and executes it.
 * @tmp_path: path to the command
 * @tmp_args: array of cmd and args
 * @env: env variables
 * Return: Nothing
*/

void _exec_path(char *tmp_path, char **tmp_args, char **env)
{
	int status;
	pid_t childPid;

	childPid = fork();
	if (childPid == 0)
	{
		tmp_args[0] = strdup(tmp_path);
		execve(tmp_args[0], tmp_args, env);
	}
	else
	{
	wait(&status);
	}
}
