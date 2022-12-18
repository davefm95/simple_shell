#include "main.h"
/**
 *main - pilot function for shell program
 *@ac: number of args in list
 *@ac: array of string args
 *Return: 0
 */
extern char **environ;
int main(int ac, char **av)
{
	ssize_t bytesrd;
	pid_t childpid;
	size_t size = 0;
	char *buff = NULL;
	char *argv[] = {NULL, NULL};
	(void)ac;

	do
	{
		write(1, "$ ", 2);
		if ((bytesrd = getline(&buff, &size, stdin)) != -1)
		{
			if (strcmp(buff, "\n") == 0)
				continue;
			argv[0] = format_command(buff);
			switch (childpid = fork())
			{
			case -1:
				perror("unable to fork");
				break;
			case 0:
				if (execve(argv[0], argv, environ) == -1)
					err_msg(*av, argv[0]);
				exit(0);
				break;
			default:
				wait(NULL);
				break;
			}
			free(argv[0]);
			argv[0] = NULL;
			free(buff);
			buff = NULL;
		}
	}while (bytesrd != -1);
	if (bytesrd == -1)
		free(buff);
	return (0);
}
