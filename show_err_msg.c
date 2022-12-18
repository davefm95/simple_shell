#include "main.h"
/**
 *err_msg - shows error message
 *@progname: program name
 *@command: command string
 */
void err_msg(char *progname, char *command)
{
	char *errmsg = ": 1: ", *errmsg2 = ": not found\n";
	write(1, progname, strlen(progname));
	write(1, errmsg, strlen(errmsg));
	write(1, command, strlen(command));
	write(1, errmsg2, strlen(errmsg2));
}
