#include "main.h"

/**
 * check_cmd - checks if command is a builtin command
 *
 * @command: command to check
 * Return: 0 if true, else -1
 */

int check_cmd(char *command)
{
	int i = 0;
	char *array_cmd[] = {"exit"};

	while (array_cmd[i])
	{
		if (_strcmp(array_cmd[i], command) == 0)
			return (0);

		i++;
	}
	return (-1);
}

/**
 * exec_builtin - executes builtin commands
 * @command - command to execute
 */

void (*exec_builtin(char **command))
{
	int i = 0;
	built_ins selector[] =
	{
		{"exit", __exit},
		{"env", _env},
		{NULL, NULL}
	};

	while (selector[i].command != NULL && selector[i].command != command[0])
		i++;

	return (selector[i].func);
}
