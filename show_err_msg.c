#include "main.h"
/**
 *err_msg - shows error message
 *@progname: program name
 *@command: command string
 *@count: count of the number of execs
 */
void err_msg(size_t count, char *progname, char *command)
{
	char *errmsg = ": ", *errmsg2 = ": ", *errmsg3 = ": not found\n", c;
	c = count + '0';
	write(1, progname, strlen(progname));
	write(1, errmsg, strlen(errmsg));
	write(1, &c, 1);
	write(1, errmsg2, strlen(errmsg2));
	write(1, command, strlen(command));
	write(1, errmsg3, strlen(errmsg3));
}
