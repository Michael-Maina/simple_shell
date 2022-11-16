#include "main.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	char *buffer, *token;
	size_t buffersize = 1024;
	char *array[1024];
	int i;
	ssize_t get_return;

	(void)argc;

	write(1, "\033[1;1H\033[2J", 10); /*clears terminal window */

	while (1)
	{
		i = 0;
		while(i < 1024)
			array[i++] = NULL;
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		buffer = malloc(sizeof(char *) * buffersize);

		if (buffer == NULL)
		{
			free(buffer);
			exit(98);
		}

		get_return = getline(&buffer, &buffersize, stdin);

		if (get_return == -1)
		{
			free(buffer);
			exit(98);
		}

		token = strtok(buffer, " \n");
		if (token == NULL)
			continue;

		i = 0;
		while (token)
		{
			array[i++] = _strdup(token);
			token = strtok(NULL, " \n");
		}
		free(buffer);
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

				if (execve(array[0], array, environ) == -1)
				{
					perror(argv[0]);
					exit(100);
				}
			}
		}
	}
	return (0);
}
