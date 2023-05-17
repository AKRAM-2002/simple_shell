#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int ac, char *av[], char *env[]) {
    char **args = NULL;
    char *input = NULL;
    size_t size = 0;
    ssize_t n;
    int count = 0;
    
    printf("Enter a command: ");
    n = getline(&input, &size, stdin);
    
    // Remove newline character
    input[n - 1] = '\0';
    
    char *token = strtok(input, " ");
    while (token != NULL) {
        args = realloc(args, (count + 1) * sizeof(char *));
        args[count] = strdup(token);
        token = strtok(NULL, " ");
        count++;
    }
    
    args = realloc(args, (count + 1) * sizeof(char *));
    args[count] = NULL; // Set the last element to NULL to indicate the end of the array
    
	execve(args[0], args, env);

    // Print the arguments
    printf("Arguments: ");
    for (int i = 0; args[i] != NULL; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
    

    // Free the memory
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
    free(input);
    
    return 0;
}

