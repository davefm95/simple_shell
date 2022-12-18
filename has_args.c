#include "main.h"
/**
 *hasargs - gets number of arguments to program
 *@str: input string of commands and args
 *Return: number of args or -1
 */
int hasargs(char *buff)
{
	int argsno = 0, i = 0;

	while (buff[i] != '\0')
	{
		if (buff[0] == ' ')
			break;
		if (buff[i] == ' ' && buff[i + 1] == '\0')
			break;
		if (buff[i] == ' ')
		{
			argsno++;
		}
		i++;
	}
	return (++argsno);
}
