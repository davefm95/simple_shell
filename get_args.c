#include "main.h"
/**
 *get_args - gets argumemts from guven string
 *@buff: string
 *Return: NULL or array of string args
 */
char **get_args(char *buff)
{
	char *bc, **agv, *token;
	int count = 0, i = 0;

	bc = strdup(buff);
	token = strtok(bc, " \n");
	if (!token)
		return (NULL);
	while (token)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	free(bc);
	agv = malloc((count + 1) * sizeof(char *));
	token = strtok(buff, " \n");
	while (token)
	{
		agv[i] = strdup(token);
		token = strtok(NULL, " \n");
		i++;
	}
	agv[count] = NULL;
	return (agv);
}
