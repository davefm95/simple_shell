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
	char *argv[] = {"/bin/ls",NULL};
	int hasargs = 0, i = 0;

	while (getline(&buff, &size, stdin) > 0)
	{

		while (buff[i] != '\0')
		{
			if (buff[0] == ' ')
				break;
			if (buff[i] == ' ' && buff[i + 1] == '\0')
				break;
			if (buff[i] == ' ')
			{
				hasargs++;
			}
			i++;
		}
		printf("%s", buff);
		switch (childpid = fork())
		{
		case -1:
			perror("unable to fork");
			break;
		case 0:
			if (execve(buff, argv, environ) == -1)
				write(1, "command not found", 17);
			exit(0);
			break;
		default:
			wait(NULL);
			break;
		}
	}
	return (0);
}
