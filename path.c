#include "main.h"

void path_finder(char **cmd)
{
	char *path, *token, *token_cmd, *temp;
	char *array[1024];
	struct stat buff;
	int j, i = 0, k;

	path = _getenv("PATH");

	token = strtok(path, ":");

	while(token)
	{
		array[i++] = _strdup(token);
		token = strtok(NULL, ":");
	}
	k = i;
	i = 0;
	while (i < k)
	{
		temp = NULL;
		token_cmd = NULL;
		temp = _strcat(array[i], "/");
		i++;
		token_cmd = _strcat(temp, *cmd);

		j = stat(token_cmd, &buff);

		if (j == -1)
		{
			continue;
		}
		else
		{
			*cmd = token_cmd;
                        break;

		}
	}
}
