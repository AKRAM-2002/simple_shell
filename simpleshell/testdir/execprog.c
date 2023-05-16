#include <unistd.h>
#include <stdio.h>

int
main(int argc, char *argv[], char *env[])
{
	char *args[] = {"/bin/ls","-la",NULL};

    if (execve(args[0], args, env) == -1)
      perror("execve");

  printf("My pid is: %d\n", getpid());

  return 0;
}
 

