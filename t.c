#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
ssize_t _getline(char **buf, size_t *numchars, FILE *stream);
int main(void)
{
	char *buff = NULL;
	size_t linlen = 0;
	ssize_t retlen;

	retlen = _getline(&buff, &linlen, stdin);
	printf("The line length is %ld\n", retlen);
	printf("%s\n", buff);
	free(buff);
	return (0);
}
