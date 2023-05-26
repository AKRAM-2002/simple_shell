#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "utils.h"

#define INITIAL_BUFFER_SIZE 1024

void simple_shell_0_1(char **environ);

#endif
