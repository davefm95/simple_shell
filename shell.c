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
	size_t size = 0, count = 0;
	char *buff = NULL, **argv = NULL, *modarg = NULL;
	(void)ac;

	do
	{
		write(1, "$ ", 2);
		bytesrd = getline(&buff, &size, stdin);
		if (bytesrd != -1)
		{
			count++;
			argv = get_args(buff);
			if (argv == NULL)
				continue;
			modarg = handlepath(argv[0]);
			if (modarg == NULL)
			{
				err_msg(count, *av, argv[0]);
				free_mem(buff, argv);
				buff = NULL;
				argv = NULL;
				continue;
			}
			fork_exec(modarg, av, argv, env, count);
			if (strcmp(modarg, argv[0]) != 0)
				free(modarg);
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
