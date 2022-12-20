#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
void err_msg(size_t count, char *progname, char *command);
void fork_exec(char * com, char **av, char **argv, char **env, size_t count);
char **get_args(char *buff);
void free_mem(void *p, char **doublep);
char *handle_path(char *comstr);
char *handlepath(char *comstr);

#endif
