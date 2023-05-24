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
 * @ac: nbr of args
 * @av: array of args
 * @env: array of env variables
 * Return: 0 on success&exit
*/
/* int ac __attribute__((unused)), char **av __attribute__((unused))*/
int main(int ac, __attribute__((unused))char **av, char **env)
{
	int ttt;
	int i_env = 0;
	char **buffer;

	ttt = ac;

	while (env[i_env] != NULL)
		i_env++;

	buffer = (char **)malloc(sizeof(char *) * (i_env + 1));

	buffer[i_env] = NULL;

	_loop(buffer, env);

	return (0);
}
