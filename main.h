#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/wait.h>
void err_msg(char *progname, char *command);
void fork_exec(char **av, char **argv, char **env);
char **get_args(char *buff);
void free_mem(void *p, char **doublep);

#endif
