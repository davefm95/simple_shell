#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
void *_realloc(void *ptr, size_t olds, size_t news);
ssize_t _getline(char **buf, size_t *size, FILE *fp);
#endif
