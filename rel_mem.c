#include "main.h"
/**
 *free_mem - frees memeory
 *@p: pointer;
 *@doublep: double pointer
 */
void free_mem(void *p, char **doublep)
{
	int i = 0;

	free(p);
	while  (doublep[i] != NULL)
	{
		free(doublep[i]);
		i++;
	}
	free(doublep);
}
