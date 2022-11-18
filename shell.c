#include "main.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	char *buffer;
	size_t buffersize = 1024;
	char **array;
	int status, counter = 0;
	ssize_t get_return;

	(void)argc;

	/*write(1, "\033[1;1H\033[2J", 10);*/ /*clears terminal window */

	while (1)
	{
		counter++;
		buffer = NULL;

		if(isatty(STDIN_FILENO))
			write(1, "$ ", 2);

		buffer = malloc(sizeof(char *) * buffersize);

		if (buffer == NULL)
		{
			continue;
		}

		get_return = getline(&buffer, &buffersize, stdin);

		if (get_return == -1)
		{
			free(buffer);
			exit(0);
		}

		array = parser(buffer);
		if (check_cmd(array[0]) == 0)
		{
			exec_builtin(array);
			free(array);
			free(buffer);
			array = NULL;
			buffer = NULL;
			continue;
		}
		else
		{
			if (fork() != 0)
			{
				wait(&status);
			}
			else
			{
				if (_strncmp(array[0], "./", 2) != 0 &&
				    _strncmp(array[0], "/", 1) != 0)
					path_finder(&array[0]);

				if (execve(array[0], array, environ) == -1)
				{
					printE(counter, array[0], argv[0]);
					free(array);
					free(buffer);
					exit(EXIT_FAILURE);
				}
				return (EXIT_SUCCESS);
			}
		}
	}
	return (EXIT_SUCCESS);
}
char **parser(char *buffer)
{
	char **cmd, *token;
	int i;

	if (buffer == NULL)
		return (NULL);

	token = strtok(buffer, " \n");
	if (token == NULL)
		return (NULL);

	cmd = malloc(sizeof(char *) * 1024);

	i = 0;
	while (token)
	{
		cmd[i++] = _strdup(token);
		token = strtok(NULL, " \n");
	}
	cmd[i] = NULL;
	return (cmd);
}
