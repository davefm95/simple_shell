#include "main.h"
/**
 *fork_exec - forks and executes given commands
 *@argv: array of args
 *@env: arraybof environment variables
 *@com: command to be passed
 *@count: number of execs and fails
*/
void fork_exec(char *com, char **av, char **argv, char **env, size_t count)
{
	pid_t childpid;

	switch (childpid = fork())
	{
	case -1:
		perror("unable to fork");
		break;
	case 0:
		if (execve(com, argv, env) == -1)
			err_msg(count, *av, argv[0]);
		exit(0);
		break;
	default:
		wait(NULL);
	}
}
