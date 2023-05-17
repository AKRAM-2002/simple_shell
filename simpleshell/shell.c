#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "shell.h"

int main(int ac, char **av, char **env)
{	
        char *prompt = "-> ";
	char *exitStr = "exit"; 
	char inputcmd[100];
	char *cmd_to_exec[10];
	char *cmd_args[10];
	char *input = NULL;
	ssize_t n;
	size_t size = 100;
	int loop = 1;
	char *name = NULL;
	int res;
	char tmp_path[100];
	struct stat st;
	struct stat sst;
	int i_env = 0;
	pid_t childPid;
	pid_t PID;
	
	while (env[i_env] != NULL)
		i_env++;

	char **buffer = (char **)malloc(sizeof(char *) * (i_env + 1));
	buffer[i_env] = NULL;

        while(1 && loop == 1)
        {
                printf("%s", prompt);
		n = getline(&input, &size, stdin);
		strcpy(inputcmd, input);

		if(inputcmd[n - 1] == '\n')
			inputcmd[n - 1] = '\0';
		if (strcmp(inputcmd, exitStr) == 0)
		{
			// loop = 0;
			break;
		}

		// handeling commands with args :
		// here
		//printf("### %s\n", inputcmd);
		char *tmp_token = NULL;
		char *tmp_args[10];
		int tmp_i = 0;
		char tmp_cmd[100];
		strcpy(tmp_cmd, inputcmd);
		//printf("%s\n", tmp_cmd);
		tmp_token = strtok(tmp_cmd, " ");
		while (tmp_token != NULL)
		{
			//printf("token = %s\n", tmp_token);
			tmp_args[tmp_i++] = strdup(tmp_token);
			//printf("tmp args : %s\n", tmp_args[tmp_i - 1]);
			tmp_token = strtok(NULL, " ");
		}
		tmp_args[tmp_i] = NULL;


		// now do the magic stuf
		//printf("%s, %ld\n", inputcmd, n);

		if (stat(tmp_args[0], &sst) == 0)
		{
			//in this case the executable exists in this directory or the user typed the full path to the executable.
			//now execute the program
			childPid = fork();
			if (childPid == 0)
			{
				execve(tmp_args[0], tmp_args, env);
			}
			else
			{
				int status;
				wait(&status);
			}
		}
		else
		{
		for (int i = 0; env[i] != NULL; i++)
		{
			buffer[i] = strdup(env[i]);
			//strcpy(buffer[i], env[i]); 
			//strcpy(buffer, env[i]);
			//printf("buff : %s\n", buffer);
			name = strtok( buffer[i], "=");
			res = strcmp(name, "PATH");
			if (res == 0)
			{
				name = strtok(NULL, "=");
				name = strtok(name, ":");
				while (name != NULL)
				{
					strcpy(tmp_path, name);
					strcat(tmp_path, "/");
					strcat(tmp_path, tmp_args[0]);
					if (stat(tmp_path, &st) == 0)
					{
						// the executable file is found, next step is to execute it.
					        //printf("file found in path : (%s)\n", tmp_path);
						// execute the file in a child process, because execve overwrites the current program with
						// the executable file program. so the child process will be overwritten and i conserve the parent
						// process.
						childPid = fork();
						if (childPid == 0)
						{
							//child process
							tmp_args[0] = strdup(tmp_path);
							execve( tmp_args[0], tmp_args, env);
						}
						else
						{
							//parent process waiting for the child process to terminate.
							int status;
							wait(&status);
							//printf("parent waiting ...\n");
						}
						break;
					}
					else
					{
						name = strtok(NULL, ":");
					}
				}
			}
		}
		}
        }
	
	free(input);
        return 0;
}
