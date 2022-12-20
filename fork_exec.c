#include "main.h"
/**
 *fork_exec - forks and executes given commands
 *@argv: array of args
 *@env: arraybof environment variables
 */
void fork_exec(char **av, char **argv, char **env)
{
	pid_t childpid;

	switch (childpid = fork())
	{
	case -1:
		perror("unable to fork");
		break;
	case 0:
		if (execve(argv[0], argv, env) == -1)
			err_msg(*av, argv[0]);
		exit(0);
		break;
	default:
		wait(NULL);
	}
}
