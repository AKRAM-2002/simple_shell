#include <stdio.h>
#include "main.h"
/**
 * main - Entry point
 *
 * @argc: The number of command line arguments
 * @argv: The command line arguments
 * @envp: The environment variables
 *
 * Description: Runs a simple shell script
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;

	simple_shell_0_1(envp);
	return (0);
}
