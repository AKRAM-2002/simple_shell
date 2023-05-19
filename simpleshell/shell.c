#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"
/**
 * main - main function
 * @ac: number of args
 * @av: array of args
 * @env: array of env variables
 * Return: 0 on success&exit
*/
int main(int ac, char **av, char **env)
{
	int i_env = 0;
	char **buffer;

	while (env[i_env] != NULL)
		i_env++;

	buffer = (char **)malloc(sizeof(char *) * (i_env + 1));

	buffer[i_env] = NULL;

	_loop(buffer, env);

	return (0);
}
