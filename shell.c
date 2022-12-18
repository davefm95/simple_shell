#include <errno.h>
#include "main.h"
/**
 *main - pilot function for shell program
 *Return: 0
 */
extern char **environ;
int main(void)
{
	pid_t childpid;
	size_t size = 0;
	char *buff = NULL;
	char *argv[] = {NULL, NULL};

	while (_getline(&buff, &size, stdin) > 0)
	{
		if (buff !=NULL)
		{
			argv[0] = buff;
			switch (childpid = fork())
			{
			case -1:
				perror("unable to fork");
				break;
			case 0:
				if (execve(argv[0], argv, environ) == -1)
					printf("%s", strerror(errno));
				exit(0);
				break;
			default:
				wait(NULL);
				break;
			}
			size = 0;
		}
	}
	return (0);
}
