#include "main.h"

#define INITIAL_BUFFER_SIZE 1024

/**
 * read_input - Prompts the user and gets their input
 *
 * Description: This function writes a prompt to the standard output,
 *              allocates memory for the user's input, and reads the
 *              user's input from the standard input. It then removes
 *              the trailing newline character if present.
 *
 * Return: Returns a pointer to the user's input string. In case of an error,
 *         it returns NULL.
 */
char *read_input(void)
{
	ssize_t read_bytes;
	char *command = NULL;
	size_t input_size = 0;

	read_bytes = getline(&command, &input_size, stdin);

	if (read_bytes == -1 || feof(stdin))
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
	if (read_bytes == -1)
	{
		printf("Failed to read user input.\n");
		free(command);
		return (NULL);
	}

	if (read_bytes > 0 && command[read_bytes - 1] == '\n')
	{
		command[read_bytes - 1] = '\0';
	}

	return (command);
}
/**
 * execute_command - Executes the command
 *
 * @environ: The environment variables passed to the new process
 * @command: The command to execute
 * Description: This function forks a new process and executes the
 *              provided command in the child process. It waits
 *              for the child process to finish execution before
 *              returning.
 *
 * Return: This is a void function so it does not return a value.
 *         It directly exits the program in case of an error.
 */
void execute_command(char *command, char **environ)
{
	pid_t pid;
	char *args[2];

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(command);
		return;
	}
	if (pid == 0)
	{
		execve(command, args, environ);
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	free(command);
}

/**
 * simple_shell_0_1 - The main function for the shell
 *
 * @environ: The environment variables passed to the new process
 *
 * Description: This function continually gets user input and executes
 *              the corresponding command until an error occurs or the
 *              user quits the shell. It handles memory allocation errors
 *              and read errors.
 *
 * Return: This is a void function so it does not return a value.
 */
void simple_shell_0_1(char **environ)
{
	bool status = true;
	struct stat st;

	while (status == true)
	{
		char *command = read_input();

		if (command == NULL)
		{
			return;
		}
		if (_is_whitespace(command))
		{
			free(command);
			continue;
		}

		if (stat(command, &st) == -1)
		{
			write(STDOUT_FILENO, "./shell: No such file or directory\n", 36);
			free(command);
			continue;
		}

		execute_command(command, environ);
	}
}
