#include "main.h"

int __exit(char **cmd)
{
	int i = 0, status;

	if (cmd[1] == NULL)
	{
		exit(EXIT_SUCCESS);
		return (0);
	}

	while(cmd[1][i])
	{
		if(_isdigit(cmd[1][i]) == 0)
		{
			perror("ERROR!!!");
			return (-1);
		}
	i++;
	}
	status = _atoi(cmd[1]);
	exit(status);
	return (0);
}

/**
 * _env - prints the current environment
 *
 * Return: nothing
 */

int _env(char **cmd)
{
	int i = 0;
	(void)cmd;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}


/**
 * _clear - clears the terminal window
 *
 * Return: nothing
 */

int clear(char **cmd)
{
	(void)cmd;

	write(1, "\033[1;1H\033[2J", 10);

	return (0);
}
