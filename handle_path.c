#include "main.h"
/**
 *handle_path - handles the absence of path in commands
 *@comstr: command string
 *Return: modified command string
 */
char *handle_path(char *comstr)
{
	char *bin = "/bin/", *com = NULL;
	DIR *dir;
	struct dirent *ent;

	if (strchr(comstr, '/') == NULL)
	{
		dir = opendir("/usr/bin");
		if (dir == NULL)
		{
			perror("Unable to open and search /bin");
			return (NULL);
		}
		ent = readdir(dir);
		while (ent)
		{
			if (strcmp(ent->d_name, comstr) == 0)
			{
				com = malloc(strlen(ent->d_name) + strlen(bin) + 1);
				strcpy(com, bin);
				strcat(com, bin);
				break;
			}
			ent = readdir(dir);
		}
		return (com);
	}
	closedir(dir);
	return (comstr);
}
