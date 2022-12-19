#include "main.h"
/**
 *get_args - gets the arguments in string and places them in array
 *@str: command string
 *@n: the number of args to spli string into
 *Return: array of syring args
 */
char **get_args(char *str, int n)
{
	char **argarr, ;
	int i = 0;

	argarr = malloc(n * sizeof(char *));
	
