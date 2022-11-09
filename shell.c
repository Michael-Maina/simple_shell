#include "main.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main()
{
	char *buffer, *token;
	size_t buffersize = 1024;
	char *array[1024];
	int i;

	while (1)
	{
		write(1, "$ ", 2);
		buffer = malloc(sizeof(char) * buffersize);
		getline(&buffer, &buffersize, stdin);

		token = strtok(buffer, " \n");
		i = 0;
		while (token)
		{
			array[i++] = strdup(token);
			token = strtok(NULL, " \n");
		}
		if (_strcmp (array[0], "exit") == 0)
			break;
		if (fork() != 0)
		{
			wait(NULL);
		}
		else
		{
			if (_strncmp(array[0], "./", 2) != 0 && _strncmp(array[0], "/", 1) != 0)
				path_finder(&array[0]);

			if (execve(array[0], array, NULL) == -1)
			{
				perror("Error");
				exit(100);
			}
		}
	}
	return (0);
}
