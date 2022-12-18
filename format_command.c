#include "main.h"
/**
 *format_command - trims the imput syring to acceptable command format
 *@buff: pointer to input string pointer
 *Return: returns formatted string
 */
char *format_command(char *buff)
{
	char *b, *st = buff;

	if (st[strlen(st) - 1] = '\n')
	{
		if (st[strlen(st) - 2] == ' ')
		{
			b = malloc(strlen(st) - 1);
			memcpy(b, st, strlen(st) - 1);
			b[strlen(st) - 2] = '\0';
		}
		else
		{
			b = malloc(strlen(st));
			memcpy(b, st, strlen(st));
			b[strlen(st) - 1] = '\0';
		}
	}
	else if (st[strlen(st) - 1] == ' ')
	{
		b = malloc(strlen(st));
		memcpy(b, st, strlen(st));
		b[strlen(st) - 1] = '\0';
	}
	else
		b = strdup(buff);
	return (b);
}
