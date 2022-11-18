#ifndef MAIN_H
#define MAIN_H

/* Libraries included */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/**
 * struct builtin_cmd - struct type defining a functiomn pointer to a command
 * @command: command to execute
 * @func: A function pointer to a function that executes
 *         a builtin command.
 */

typedef struct builtin_cmd
{
	char *command;
	int (*func)(char **cmd);
} built_ins;

/* String manipulation functions */

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char *_strtok(char *str, const char *delim);
char *_memset(char *s, char b, unsigned int n);

char *_getenv(char *name);
void path_finder(char **cmd);
int _env(char **cmd);
int exec_builtin(char **command);
int check_cmd(char *command);
int clear(char **cmd);
int __exit(char **cmd);
int _isdigit(char c);
int _atoi(char *s);
char *_itoa(unsigned int n);
void exec(char **cmd, int counter, char **argv);
char **parser(char *buffer);
void printE(int counter, char *cmd, char *argv);
#endif
