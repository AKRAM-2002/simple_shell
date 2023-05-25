#ifndef _SHELL_H_
#define _SHELL_H_
#include <sys/types.h>

void _exec(char **tmp_args, char **env);
void _find_path(char **env, char **tmp_args, char **buffer, char **av);
void _exec_path(char *tmp_path, char **tmp_args, char **env);
void _update_PWD(char **env);
void _handle_cd(char **env, char **tmp_args, char **buffer);
int _get_user_input(ssize_t n, char inputcmd[100], char *input);
void _loop(char **buffer, char **env, char **av);
void _handle_args(char **tmp_args, char inputcmd[100]);

#endif
