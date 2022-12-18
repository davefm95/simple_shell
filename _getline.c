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
	if (news == 0)
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
	int bytesread;
	char *str, c;

	if (!fp)
		return (-1);
	str = malloc(1);
	if (!str)
		return (-1);
	while (bytesread = read(1, &c, 1) > 0)
	{
/*		if (c == '\n' && count == 0)
		{
			free(str);
			str = NULL;
			break;
		}
		if (c == '\n')
		break;*/
		count++;
		str[count - 1] = c;
		str = _realloc(str, count, count + 1);
		str[count] = '\0';
		bytesread = read(1, &c, 1);
	}
	if (bytesread == 0 && count == 0)
	{
		if (*buf)
			free(*buf);
		free(str);
		printf("%d\n", bytesread);
		return (-1);
	}
	if (bytesread == -1)
	{
		free(str);
		printf("%d\n", bytesread);
		return (-1);
	}
	if (*buf != NULL)
		free(*buf);
	*buf = str;
	*size = count;
	return ((ssize_t)(++count));
}
