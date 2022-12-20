#include "main.h"
/**
 *main - pilot function for shell program
 *@ac: number of args in list
 *@av: array of string args
 *@env: environment vars
 *Return: 0
 */
int main(int ac, char **av, char **env)
{
	ssize_t bytesrd, i;
	size_t size = 0;
	char *buff = NULL, **argv = NULL;
	(void)ac;

	do
	{
		write(1, "$ ", 2);
		bytesrd = getline(&buff, &size, stdin);
		if (bytesrd != -1)
		{
			argv = get_args(buff);
			if (argv == NULL)
				continue;
			fork_exec(av, argv, env);
			free_mem(NULL, argv);
			argv = NULL;
			free(buff);
			buff = NULL;
		}
	}while (bytesrd != -1);
	if (bytesrd == -1)
		free(buff);
	return (0);
}
