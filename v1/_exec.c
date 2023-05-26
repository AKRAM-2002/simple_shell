#include "shell.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * _exec - execute a command without arguments
 * @tmp_args: array of strings containing
 * the path to the cmd executable.
 * @env: array of args containing the env variables.
 * Return: Nothing
*/

void _exec(char **tmp_args, char **env)
{
	pid_t childPid;
	int status;

	childPid = fork();
	if (childPid == 0)
	{
		execve(tmp_args[0], tmp_args, env);
	}
	else
	{
		wait(&status);
	}
}
