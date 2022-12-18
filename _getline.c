#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 *_realloc - reallocates mem for a buff
 *@ptr: ptr to buff
 *@olds: old size of buff
 *@news: new size of buff
 *Return: pointer to newly allocated memory
 */
void *_realloc(void *ptr, size_t olds, size_t news)
{
	void *p;

	if (!ptr)
	{
		ptr = malloc(news);
		return (ptr);
	}
	if (olds == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (olds == news)
		return (ptr);
	p = malloc(news);
	if (!p)
		return (NULL);
	memcpy(p, ptr, olds < news ? olds : news);
	free(ptr);
	return (p);
}

/**
 *_getline - reads a line and writes to specified buffer
 *@fp: pointer to file
 *@size: size of buffer to be read to
 *@buf: poinyer to buffer pointer
 *Return: number of bytes retrieved or -1
 */
ssize_t _getline(char **buf, size_t *size, FILE *fp)
{
	int fd = fileno(fp);
	size_t count = 0;
	ssize_t bytesread = 0;
	char *str = malloc(1), c;

	if (!fp)
		return (-1);
	while (bytesread += read(fd, &c, 1) > 0)
	{
		count++;
		str[count - 1] = c;
		str = _realloc(str, count, count + 1);
		str[count] = '\0';
		if (c == '\n')
			break;
	}
	if (bytesread == -1)
		return (-1);
	if (*buf != NULL)
		free(*buf);
	*buf = str;
	*size = count;
	return (bytesread);
}
