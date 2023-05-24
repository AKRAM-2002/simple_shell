#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _get_user_input - takes the user input and stores it.
 * @n: var
 * @inputcmd: string
 * @input: string
 * Return: 1 if input is exit cmd else 0
*/

int _get_user_input(ssize_t n, char inputcmd[100], char *input)
{
	size_t size = 100;
	char *exitStr = "exit";

	n = getline(&input, &size, stdin);
	strcpy(inputcmd, input);
	if (inputcmd[n - 1] == '\n')
		inputcmd[n - 1] = '\0';
	if (strcmp(inputcmd, exitStr) == 0)
	{
		return (1);
	}
	free(input);
	return (0);
}
