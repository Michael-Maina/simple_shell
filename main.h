#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char **environ;

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);

#endif
