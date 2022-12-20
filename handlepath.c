#include "main.h"
/**
 *handlepath -handles the path of commands
 *@comstr: command string
 *Return: modified string ororiginal string
 */
char *handlepath(char *comstr)
{
	char *bin = "/bin/", *com = NULL;
	struct stat st;

	if (strchr(comstr, '/') == NULL)
	{
		com = malloc(strlen(bin) + strlen(comstr) + 1);
		if (!com)
		{
			perror("Error while allocating memory");
			return (NULL);
		}
		strcpy(com, bin);
		strcat(com, comstr);
		if (stat(com, &st) == 0)
			return (com);
		else
		{
			free(com);
			return (NULL);
		}
	}
	return (comstr);
}
