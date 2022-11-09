#include "main.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main()
{
	char *buffer;
	size_t buffersize = 1024;
	char *array[1024];
	int i;

	while (1)
	{
		buffer = malloc(sizeof(char) * buffersize);
		getline(&buffer, &buffersize, stdin);

		char *token = strtok(buffer, " \n");
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
			wait();
		}
		else
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Error:");
			}
		}
	}
	return (0);
}
