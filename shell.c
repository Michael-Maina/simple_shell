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
	ssize_t get_return;
	char **env = environ;

	write(1, "\033[1;1H\033[2J", 10);

	while (1)
	{
		write(1, "$ ", 2);
		buffer = malloc(sizeof(char) * buffersize);
		get_return = getline(&buffer, &buffersize, stdin);

		if (get_return == -1)
			exit(98);

		if (buffer == NULL)
			continue;

		token = strtok(buffer, " \n");
		i = 0;
		while (token)
		{
			array[i++] = _strdup(token);
			token = strtok(NULL, " \n");
		}
		if (check_cmd(array[0]) == 0)
		{
			exec_builtin(array);
		}
		else
		{
			if (fork() != 0)
			{
				wait(NULL);
			}
			else
			{
				if (_strncmp(array[0], "./", 2) != 0 &&
				    _strncmp(array[0], "/", 1) != 0)
					path_finder(&array[0]);

				if (execve(array[0], array, env) == -1)
				{
					perror("Error");
					exit(100);
				}
			}
		}
	}
	return (0);
}
