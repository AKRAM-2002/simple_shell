#include "shell.h"
#include <string.h>
#include <unistd.h>
/**
 * _update_PWD - updates the PWD variable whith the new current
 * working directory when cd is executed.
 * @env: env vars
 * Return: Nothing
*/
void _update_PWD(char **env)
{
	int i;
	char pathv[256];
	char *tok;
	char *tokstr[1024];
	char new_path[1024] = "PWD=";

	getcwd(pathv, sizeof(pathv));
	for (i = 0; env[i] != NULL; i++)
	{
		tokstr[i] = _strdup(env[i]);
		tok = strtok(tokstr[i], "=");
		if (strcmp(tok, "PWD") == 0)
		{
			_strcat(new_path, pathv);
			tok = strtok(NULL, "=");
			env[i] = _strdup(new_path);
		}
	}
}
