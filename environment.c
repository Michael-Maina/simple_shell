#include "main.h"

/**
 * _getenv - gets the value of enviroment variable by name
 * @name: environment variable name
 * Return: the value of the environment variable else NULL.
 */

char *_getenv(char *name)
{
	size_t len, cmd_len = 1024;
	char *env_var, *token;
	int i, x, j;

	len = _strlen(name);

	for (i = 0 ; environ[i]; i++)
	{
		token = strtok(environ[i], "=");
		if (_strcmp(name, token) == 0)
		{
			env_var = malloc(sizeof(char) * cmd_len);
			if (!env_var)
			{
				free(env_var);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = len + 1; environ[i][x]; x++, j++)
			{
				env_var[j] = environ[i][x];
			}
			env_var[j] = '\0';

			return (env_var);
		}
	}

	return (NULL);
}

/**
 * _env - prints the current environment
 *
 * Return: nothing
 */

void _env(char **cmd)
{
	int i = 0;
	(void)cmd;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
}
